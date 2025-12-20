----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01.06.2025 19:28:36
-- Design Name: 
-- Module Name: sat16a8 - Behavioral
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

entity sat16a8 is
    Port ( entrada : in std_logic_vector (15 downto 0);
           salida : out std_logic_vector (7 downto 0));
end sat16a8;

architecture Behavioral of sat16a8 is
    signal entrada_S: std_logic_vector (15 downto 0);
    signal salida_S : std_logic_vector(7 downto 0);
   

begin

    entrada_S <= std_logic_vector(signed(entrada));
    
    -- Asignación condicional concurrente:
    salida_S <= X"7F" when signed(entrada_S) > 127 else  -- Saturación positiva
                X"80" when signed(entrada_S) < -128 else -- Saturación negativa
                entrada_S(7 downto 0);                   -- Valor dentro del rango
                
    salida <= salida_S;
                 
end Behavioral;