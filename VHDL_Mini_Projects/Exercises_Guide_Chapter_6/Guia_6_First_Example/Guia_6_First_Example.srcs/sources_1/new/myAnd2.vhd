----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 19:45:25
-- Design Name: myAnd2
-- Module Name: myAnd2 - Behavioral
-- Project Name: Exercises_Guide_Chapter_6
-- Target Devices: 
-- Tool Versions: VHDL
-- Description: Just an iplementation and simulation of an "and" logic door that has 2 inputs and 1 output
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


entity myAnd2 is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           y : out STD_LOGIC);
end myAnd2;

architecture Behavioral of myAnd2 is

begin

y <= a and b;

end Behavioral;
