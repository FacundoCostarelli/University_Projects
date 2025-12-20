----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Uart System with I/O
-- Module Name: uart - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Módulo integrador de la UART. Encapsula los bloques de Transmisión (TX) 
-- y Recepción (RX) para permitir comunicación full-duplex.
-- ENG: UART integration module. Encapsulates Transmission (TX) and 
-- Reception (RX) blocks to allow full-duplex communication.
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.math_real.all;


entity uart is
    Generic (baudRate : integer := 9600;
               sysClk : integer := 100000000;
             dataSize : integer := 8);
    Port         (clk : in std_logic;
                  rst : in std_logic;
               dataWr : in std_logic; -- ESP: Pulso de escritura para iniciar TX / ENG: Write pulse to start TX
               dataTx : in std_logic_vector (dataSize - 1 downto 0); -- ESP: Dato a transmitir / ENG: Data to transmit
                ready : out std_logic; -- ESP: Indica que el transmisor está libre / ENG: Indicates transmitter is free
                   tx : out std_logic; -- ESP: Pin físico de salida serie / ENG: Physical serial output pin
               dataRd : out std_logic; -- ESP: Pulso que indica dato recibido / ENG: Pulse indicating data received
               dataRx : out std_logic_vector (dataSize - 1 downto 0); -- ESP: Dato recibido / ENG: Received data
                   rx : in std_logic); -- ESP: Pin físico de entrada serie / ENG: Physical serial input pin
end uart;

architecture Behavioral of uart is

-- ESP: Transmisor UART (Convierte paralelo a serie)
-- ENG: UART Transmitter (Converts parallel to serial)
component uartTx is
Generic (baudRate : integer := 9600;
         sysClk : integer := 100000000;
         dataSize : integer := 8);
Port (  clk : in std_logic;
        rst : in std_logic;
        dataWr : in std_logic;
        dataTx : in std_logic_vector (dataSize - 1 downto 0);
        ready : out std_logic;
        tx : out std_logic);
end component;

-- ESP: Receptor UART (Convierte serie a paralelo)
-- ENG: UART Receiver (Converts serial to parallel)
component uartRx is
    Generic (baudRate : integer := 9600;
               sysClk : integer := 100000000;
             dataSize : integer := 8);
    Port (        clk : in std_logic;
                  rst : in std_logic;
               dataRd : out std_logic;
               dataRx : out std_logic_vector (dataSize - 1 downto 0);
                   rx : in std_logic);
end component;

begin

-- ESP: Instancia del transmisor
-- ENG: Transmitter instance
Uart_Tx: uartTx
        Generic map (
            baudRate => baudRate,
            sysClk => sysClk,
            dataSize => dataSize
        )
        Port map (
            clk => clk,
            rst => rst,
            dataWr => dataWr,
            dataTx => dataTx,
            ready => ready,
            tx => tx
        );

-- ESP: Instancia del receptor
-- ENG: Receiver instance
Uart_Rx: uartRx
    Generic map (
        baudRate => baudRate,
        sysClk => sysClk,
        dataSize => dataSize
    )
    Port map (
        clk => clk,
        rst => rst,
        dataRd => dataRd,
        dataRx => dataRx,
        rx => rx
    );

end Behavioral;
