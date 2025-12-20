----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Sck Detector System with I/O
-- Module Name: SckRisingAndFallingEdgeDetector - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Detector de flancos de subida y bajada. Utiliza un registro de 2 bits 
-- para comparar el estado anterior y actual de una señal. [cite: 488, 489, 490]
-- ENG: Rising and falling edge detector. Uses a 2-bit register to 
-- compare the previous and current state of a signal. [cite: 488, 489, 490]
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SckRisingAndFallingEdgeDetector is
    Port (  clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;  -- ESP: Señal a monitorear / ENG: Signal to monitor
            ena : in  std_logic;
              --q : out std_logic;
     risingEdge : out std_logic;  -- ESP: Pulso en flanco de subida / ENG: Rising edge pulse
    fallingEdge : out std_logic); -- ESP: Pulso en flanco de bajada / ENG: Falling edge pulse
end SckRisingAndFallingEdgeDetector;

architecture Behavioral of SckRisingAndFallingEdgeDetector is

signal sck_edge_register: std_logic_vector(2-1 downto 0);

begin

process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            sck_edge_register <= "00";
        elsif(ena = '1') then
            -- ESP: Desplaza historial e ingresa nuevo estado / ENG: Shift history and enter new state
            sck_edge_register <= sck_edge_register(0)&d;
        end if;
    end if;
end process;
 
-- ESP: Lógica de detección / ENG: Detection logic
risingEdge  <= '1' when (sck_edge_register = "01") else '0';
fallingEdge <= '1' when (sck_edge_register = "10") else '0';

end Behavioral;

