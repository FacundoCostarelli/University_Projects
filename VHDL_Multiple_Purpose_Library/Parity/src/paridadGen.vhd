----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 27.05.2025 10:14:15
-- Design Name: Generic Parity Detector
-- Module Name: paridadGen - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity paridadGen is
    Generic (N: integer := 4);                       -- Default 4-bit input
    Port ( a : in std_logic_vector (N - 1 downto 0); -- Input data
         sel : in std_logic;                         -- 0=Even parity, 1=Odd parity
           p : out std_logic);                       -- Parity bit output
end paridadGen;

architecture Behavioral of paridadGen is
    signal a_s : std_logic_vector(N-1 downto 0);  -- XOR operation progression

begin
    -- ==============================================
    -- Cascaded XOR Implementation (N-bit parity)
    -- ==============================================
    -- First stage: Initialize with first input bit
    a_s(0) <= a(0);
    
    -- Generate statement for N-bit XOR operation
    Xor_Casacade : for i in 1 to N-1 generate
    begin
        -- Cascade XOR operation: each stage XORs previous result with next input
        a_s(i) <= a(i) xor a_s(i-1);
    end generate;
    
    -- Final parity result from last cascade stage
    p <= a_s(N-1) xor sel;
    
    -- a_s(N-1) = a(0) xor a(1) xor a(2) xor a(3)

end Behavioral;

-- Example:
-- Input: a = "1101" (three 1's → odd count).
-- Even Parity Sel: p = 1 (make total 1's even).
-- Odd Parity Sel: p = 0 (keep total 1's odd).
-- Behavior:

-- vhdl
-- a_s(0) = '1' 
-- a_s(1) = '1' xor '1' = '0'
-- a_s(2) = '0' xor '0' = '0'
-- a_s(3) = '1' xor '0' = '1'  -- Final XOR = 1 (even parity)
-- p = '1' xor sel              -- sel=0 → 1, sel=1 → 0