----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 21:09:35
-- Design Name: Coder 8 to 3 eg
-- Module Name: coder8a3 con Enable, gs y prioridad - Behavioral
-- Project Name: Exercise 7
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

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity coder8a3eg is
    Port ( w : in STD_LOGIC_VECTOR (7 downto 0);
           e : in STD_LOGIC;
           gs : out STD_LOGIC;
           y : out STD_LOGIC_VECTOR (2 downto 0));
end coder8a3eg;

architecture Behavioral of coder8a3eg is
signal y_S: std_logic_vector (2 downto 0);
begin
y <= y_S when (e = '1') else "000";
y_S <= "111" when (w(7) = '1') else
       "110" when (w(6) = '1') else
       "101" when (w(5) = '1') else
       "100" when (w(4) = '1') else
       "011" when (w(3) = '1') else
       "010" when (w(2) = '1') else
       "001" when (w(1) = '1') else
       "000" when (w(0) = '1') else
       "000";
gs <= '0' when ( e = '0' or (e = '1' and w = "00000000")) else '1';
-- gs = group signal, indica 0 cuando todas las salidas van a 0 
--      e indica 1 cuando una o más las salidas van a algo distinto de 0


end Behavioral;
