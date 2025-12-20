----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2025 18:40:28
-- Design Name: 
-- Module Name: comparadorCa2 - Behavioral
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

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity comparadorCa2 is
    Generic (N: integer := 4);
    Port ( a : in std_logic_vector (N-1 downto 0);
           b : in std_logic_vector (N-1 downto 0);
           aMayorQueB : out std_logic;
           aMenorQueB : out std_logic;
           aIgualB : out std_logic);
end comparadorCa2;

architecture Behavioral of comparadorCa2 is
    signal cmp : std_logic_vector(2 downto 0);
    signal a_s : signed(N-1 downto 0);
    signal b_s : signed(N-1 downto 0);
    
begin

    a_s <= signed(a);
    b_s <= signed(b);
    
    cmp <= "010" when (a_s = b_s) else
    "100" when (a_s > b_s) else
    "001";
    
    aMayorQueB<= cmp(0);
    aIgualB <= cmp(1);
    aMenorQueB <= cmp(2);

end Behavioral;
