----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 26.05.2025 14:35:57
-- Design Name: ejemplo01
-- Module Name: Cascade_And_N_Inputs_Cascade_Or_N_Inputs - Behavioral
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

-- Entity: ejemplo01
-- Implements a cascaded AND circuit (N inputs) and cascaded OR circuit (M inputs)
-- Generic parameters:
--   N: Number of inputs for AND operation (default = 4)
--   M: Number of inputs for OR operation (default = 8)
entity ejemplo01 is
    generic (
        N : integer := 4;  -- AND circuit input size
        M : integer := 8   -- OR circuit input size
    );
    port (
        a    : in  std_logic_vector(N-1 downto 0);  -- AND circuit inputs
        b    : in  std_logic_vector(M-1 downto 0);  -- OR circuit inputs
        yOr  : out std_logic;                       -- OR circuit output
        yAnd : out std_logic                        -- AND circuit output
    );
end ejemplo01;

architecture Behavioral of ejemplo01 is
    -- Internal signals for cascaded operations
    signal a_S : std_logic_vector(N-1 downto 0);  -- AND operation progression
    signal b_S : std_logic_vector(M-1 downto 0);  -- OR operation progression

begin
    -- ==============================================
    -- Cascaded AND Implementation (N-input AND gate)
    -- ==============================================
    -- First stage: Initialize with first input
    a_S(0) <= a(0);
    
    -- Generate statement for N-input AND operation
    andInst : for i in 1 to N-1 generate
    begin
        -- Cascade AND operation: each stage ANDs previous result with next input
        a_S(i) <= a_S(i-1) and a(i);
    end generate;
    
    -- Final AND result from last cascade stage
    yAnd <= a_S(N-1);

    -- =============================================
    -- Cascaded OR Implementation (M-input OR gate)
    -- =============================================
    -- First stage: Initialize with first input
    b_S(0) <= b(0);
    
    -- Generate statement for M-input OR operation
    orInst : for i in 1 to M-1 generate
    begin
        -- Cascade OR operation: each stage ORs previous result with next input
        b_S(i) <= b_S(i-1) or b(i);  -- Fixed from original (changed AND to OR)
    end generate;
    
    -- Final OR result from last cascade stage
    yOr <= b_S(M-1);  -- Fixed from original (changed N to M)

end Behavioral;