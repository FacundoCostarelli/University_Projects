----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.05.2025 11:52:47
-- Design Name: 
-- Module: Binary-to-Gray Code Converter
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: Converts N-bit binary to Gray code using XOR operations.
--              Gray code MSB matches binary MSB. Lower bits are XOR of adjacent binary bits.
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

entity binarioGray is
    Generic (N: integer := 4);                              -- Default: 4-bit converter
    Port ( binario : in std_logic_vector (N-1 downto 0);    -- Binary input
              gray : out std_logic_vector (N-1 downto 0));  -- Gray code output
end binarioGray;
    
architecture Behavioral of binarioGray is
    signal gray_S : std_logic_vector(N-1 downto 0);  -- Internal signal for Gray code
begin
    -- ===================================================
    -- Binary-to-Gray Conversion Logic
    -- ===================================================
    -- MSB of Gray code matches binary MSB
    
    -- Assign internal signal to output port
    gray <= gray_S;
    gray_S(N-1) <= binario(N-1);
    
    -- Generate loop for lower bits (N-2 downto 0)
    Binary_To_Gray: for i in N-2 downto 0 generate
    begin        
        -- Gray(i) = Binary(i+1) XOR Binary(i)
         gray_S(i) <= binario(i+1) xor binario(i);  -- XOR with next higher bit        
    end generate Binary_To_Gray;
end Behavioral;


