----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 22:41:03
-- Design Name: Deco_3_to_8_with_enable_pin
-- Module Name: deco3a8eEna - Behavioral
-- Project Name: Exercise 5
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity deco3a8eEna is
    Port ( w : in STD_LOGIC_VECTOR (2 downto 0);
           e : in STD_LOGIC;
           y : out STD_LOGIC_VECTOR (7 downto 0));
end deco3a8eEna;

architecture Behavioral of deco3a8eEna is

begin

process(w, e)
begin
    
    if (e = '1') then 
        case w is
                when "000" => y <= "00000001";
                when "001" => y <= "00000010";
                when "010" => y <= "00000100";
                when "011" => y <= "00001000";
                when "100" => y <= "00010000";
                when "101" => y <= "00100000";
                when "110" => y <= "01000000";
                when others => y <= "10000000";
        end case;
    else
        y <= "00000000";
    end if;
end process;
end Behavioral;
