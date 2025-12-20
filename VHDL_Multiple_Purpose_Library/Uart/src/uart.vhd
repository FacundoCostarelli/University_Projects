----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.09.2025 02:17:24
-- Design Name: 
-- Module Name: uart - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
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
               dataWr : in std_logic;
               dataTx : in std_logic_vector (dataSize - 1 downto 0);
                ready : out std_logic;
                   tx : out std_logic;
               dataRd : out std_logic;
               dataRx : out std_logic_vector (dataSize - 1 downto 0);
                   rx : in std_logic);
end uart;

architecture Behavioral of uart is

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
