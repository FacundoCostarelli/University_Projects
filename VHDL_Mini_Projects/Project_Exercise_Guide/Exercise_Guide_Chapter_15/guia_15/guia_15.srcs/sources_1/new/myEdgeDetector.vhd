----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 12:41:03
-- Design Name: 
-- Module Name: myEdgeDetector - Behavioral
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

entity myEdgeDetector is
    Port (  clk : in std_logic;
            rst : in std_logic;
              d : in std_logic;
    ascendente : out std_logic;
    descendente : out std_logic);
end myEdgeDetector;

architecture Behavioral of myEdgeDetector is
    signal d_anterior: std_logic;
    

begin

process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            d_anterior  <= '0';
            ascendente  <= '0';
            descendente <= '0';
        else            
            if(d = '1' and d_anterior = '0') then 
                ascendente  <= '1';
                descendente <= '0';
            elsif(d = '0' and d_anterior = '1') then
                ascendente  <= '0';
                descendente <= '1';
            else
                ascendente  <= '0';
                descendente <= '0';               
            end if;
            
            d_anterior <= d;  -- Actualiza al final del proceso
            
        end if;
    end if;

end process;

end Behavioral;
