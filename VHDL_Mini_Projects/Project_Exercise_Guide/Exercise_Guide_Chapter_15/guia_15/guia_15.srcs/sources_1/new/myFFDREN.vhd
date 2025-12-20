----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.07.2025 22:51:11
-- Design Name: 
-- Module Name: myFFDREN - Behavioral
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

entity myFFDREN is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             d : in std_logic_vector (N-1 downto 0);
             q : out std_logic_vector (N-1 downto 0));
end myFFDREN;

architecture Behavioral of myFFDREN is

begin

process (clk)
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                q <= (others => '0');
            elsif (ena = '1') then
                q <= d;
            end if;
        end if;
    end process;    

end Behavioral;
