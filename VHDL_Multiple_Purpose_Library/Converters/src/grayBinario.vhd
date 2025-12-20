----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.05.2025 10:54:56
-- Design Name: 
-- Module Name: grayBinario - Behavioral
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

entity grayBinario is
    Generic (N: integer := 4);
    Port ( gray : in std_logic_vector (N-1 downto 0);
        binario : out std_logic_vector (N-1 downto 0));
end grayBinario;

architecture Behavioral of grayBinario is
    signal binario_S : std_logic_vector(N-1 downto 0);  -- Internal signal

begin
    -- ===================================================
    -- Gray-to-Binary Conversion Logic
    -- MSB would be N-1 = i: binario(N-1) = gray(N-1)
    -- Other bits would be N-2 <= i <= 0: binario(i) = binario(i+1) XOR gray(i)
    -- ===================================================
    binario <= binario_S;
    binario_S(N-1) <= gray(N-1);
    Gray_To_Binary: for i in N-2 downto 0 generate
    begin        
         binario_S(i) <= binario_S(i+1) xor gray(i);  -- XOR with next higher bit        
    end generate Gray_To_Binary;
end Behavioral;
