----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 14:46:14
-- Design Name: 
-- Module Name: myCntBinarioSimple - Behavioral
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

entity myCntBinarioSimple is
      Generic( N : integer := 4);
      Port(clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end myCntBinarioSimple;

architecture Behavioral of myCntBinarioSimple is
    signal cnt_S : unsigned (N - 1 downto 0);   
    
begin

process (clk)
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                cnt_S <= (others => '0');
            elsif (ena = '1') then
                cnt_S <= cnt_S + 1;
            end if;
        end if;
    end process;
        q <= std_logic_vector (cnt_s);

end Behavioral;
