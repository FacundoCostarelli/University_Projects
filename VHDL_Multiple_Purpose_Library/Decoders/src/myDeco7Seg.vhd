----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 21:09:35
-- Design Name: Deco7Seg
-- Module Name: Decodificador 7 segmentos Cátodo Común - Behavioral
-- Project Name: Exercise 8
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

entity myDeco7Seg is
    Port ( entrada : in STD_LOGIC_VECTOR (3 downto 0);
           a : out STD_LOGIC;
           b : out STD_LOGIC;
           c : out STD_LOGIC;
           d : out STD_LOGIC;
           e : out STD_LOGIC;
           f : out STD_LOGIC;
           g : out STD_LOGIC );
           
end myDeco7Seg;

architecture Behavioral of myDeco7Seg is
    signal OutSeg_S: std_logic_vector (6 downto 0);
begin

-- Assign individual bits of OutSeg_S to output ports
  a <= OutSeg_S(6);
  b <= OutSeg_S(5);
  c <= OutSeg_S(4);
  d <= OutSeg_S(3);
  e <= OutSeg_S(2);
  f <= OutSeg_S(1);
  g <= OutSeg_S(0);

with entrada select
    OutSeg_S <= "1111110" when "0000", -- 0
                "0110000" when "0001", -- 1
                "1101101" when "0010", -- 2
                "1111001" when "0011", -- 3
                "0110011" when "0100", -- 4
                "1011011" when "0101", -- 5
                "1011111" when "0110", -- 6
                "1110000" when "0111", -- 7
                "1111111" when "1000", -- 8
                "1111011" when "1001", -- 9
                "1110111" when "1010", -- 10
                "0011111" when "1011", -- 11
                "1111000" when "1100", -- 12
                "0111101" when "1101", -- 13
                "1001111" when "1110", -- 14
                "1000111" when "1111", -- 15
                "0000000" when others; -- Shutdown
                
end Behavioral;
