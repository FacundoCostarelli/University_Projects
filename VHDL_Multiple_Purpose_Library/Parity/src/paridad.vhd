----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 26.05.2025 15:07:20
-- Design Name: Simple Parity Generator 
-- Design Name: Simple Parity Generator 
-- Module Name: paridad - Behavioral
-- Project Name: guia_7
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

-- Entity: paridad
-- Implements an N-bit parity generator using cascaded XOR operations
-- Generic parameter:
--   N: Number of input bits (default = 4)
-- Output p = 1 when odd number of '1's in input (odd parity)
entity paridad is
    generic (
        N : integer := 4  -- Input vector size
    );
    port (
        a : in  std_logic_vector(N-1 downto 0);  -- Input vector
        p : out std_logic                         -- Parity bit
    );
end paridad;

architecture Behavioral of paridad is
    signal a_s : std_logic_vector(N-1 downto 0);  -- XOR operation progression

begin
    -- ==============================================
    -- Cascaded XOR Implementation (N-bit parity)
    -- ==============================================
    -- First stage: Initialize with first input bit
    a_s(0) <= a(0);
    
    -- Generate statement for N-bit XOR operation
    etiqueta : for i in 1 to N-1 generate
    begin
        -- Cascade XOR operation: each stage XORs previous result with next input
        a_s(i) <= a(i) xor a_s(i-1);
    end generate;
    
    -- Final parity result from last cascade stage
    p <= a_s(N-1);

end Behavioral;
