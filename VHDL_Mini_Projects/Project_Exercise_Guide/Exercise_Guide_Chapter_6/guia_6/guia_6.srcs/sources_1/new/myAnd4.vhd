----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 21:09:35
-- Design Name: And Logical Combination
-- Module Name: myAnd4 - Behavioral
-- Project Name: Exercise 1
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


entity myAnd4 is
    Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
           y : out STD_LOGIC);
end myAnd4;

architecture Behavioral of myAnd4 is

begin

y <= a(0) and a(1) and a(2) and a(3);

end Behavioral;
