----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.07.2025 23:19:27
-- Design Name: 
-- Module Name: myFFDRE - Behavioral
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

entity myFFDRE is
    Port ( clk : in  std_logic;
           rst : in  std_logic;
           ena : in  std_logic;
             d : in  std_logic;
             q : out std_logic);
end myFFDRE;

architecture Behavioral of myFFDRE is

begin

process (clk)
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                q <= '0';
            elsif (ena = '1') then
                q <= d;
            end if;
        end if;
    end process;


end Behavioral;
