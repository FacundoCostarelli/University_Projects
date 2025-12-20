----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2025 15:43:14
-- Design Name: 
-- Module Name: myDiv8 - Behavioral
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

entity myDiv8 is
    Port ( entrada : in std_logic_vector (7 downto 0);
    div : in std_logic_vector (1 downto 0);
    salida : out std_logic_vector (7 downto 0));
end myDiv8;

architecture Behavioral of myDiv8 is
    signal entrada_S: std_logic_vector (7 downto 0);
    signal salida_S : std_logic_vector(7 downto 0);

begin

    entrada_S <= std_logic_vector(signed(entrada));
    -- Asignación concurrente usando desplazamientos
    salida_S <= entrada_S                                       when div = "00" else  -- División por 1 (sin cambio)
              entrada_S(7) &                                    entrada_S(7 downto 1)    when div = "01" else  -- División por 2 (shift 1 bit)
              entrada_S(7) & entrada_S(7) &                     entrada_S(7 downto 2)   when div = "10" else  -- División por 4 (shift 2 bits)
              entrada_S(7) & entrada_S(7) & entrada_S(7) &      entrada_S(7 downto 3);                       -- División por 8 (shift 3 bits)
    
     salida <= salida_S;

end Behavioral;
