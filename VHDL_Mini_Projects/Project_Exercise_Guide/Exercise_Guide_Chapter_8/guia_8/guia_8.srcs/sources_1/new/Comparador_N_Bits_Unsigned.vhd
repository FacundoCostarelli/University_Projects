----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.05.2025 22:49:36
-- Design Name: 
-- Module Name: Comparador_N_Bits_Unsigned - Behavioral
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

entity Comparador_N_Bits_Unsigned is
    generic (N : integer := 4);
    port (a : in std_logic_vector(N-1 downto 0);
    b : in std_logic_vector(N-1 downto 0);
    aMayB : out std_logic;
    bMayA : out std_logic;
    AigualB : out std_logic);
    
end Comparador_N_Bits_Unsigned;

architecture Behavioral of Comparador_N_Bits_Unsigned is
    signal cmp : std_logic_vector(2 downto 0);
    signal a_s : unsigned(N-1 downto 0);
    signal b_s : unsigned(N-1 downto 0);

begin

    a_s <= unsigned(a);
    b_s <= unsigned(b);
    
    cmp <= "010" when (a_s = b_s) else
           "100" when (a_s > b_s) else
           "001";
           
    aMayB<= cmp(0);
    AigualB <= cmp(1);
    bMayA <= cmp(2);

end Behavioral;
