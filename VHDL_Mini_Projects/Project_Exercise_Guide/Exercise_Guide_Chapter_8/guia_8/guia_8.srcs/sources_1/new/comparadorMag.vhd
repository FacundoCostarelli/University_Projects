----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2025 18:27:54
-- Design Name: 
-- Module Name: comparadorMag - Behavioral
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

entity comparadorMag is
    Generic (N: integer := 4);
    Port ( a : in std_logic_vector (N-1 downto 0);
           b : in std_logic_vector (N-1 downto 0);
           aMayorQueB : out std_logic;
           aMenorQueB : out std_logic;
           aIgualB : out std_logic);
end comparadorMag;

architecture Behavioral of comparadorMag is
    signal cmp : std_logic_vector(2 downto 0);
    signal a_s : unsigned(N-1 downto 0);
    signal b_s : unsigned(N-1 downto 0);
begin

    a_s <= unsigned(a);
    b_s <= unsigned(b);
    
    cmp <= "010" when (a_s = b_s) else
    "100" when (a_s > b_s) else
    "001";
    
    aMayorQueB<= cmp(0);
    aIgualB <= cmp(1);
    aMenorQueB <= cmp(2);

end Behavioral;
