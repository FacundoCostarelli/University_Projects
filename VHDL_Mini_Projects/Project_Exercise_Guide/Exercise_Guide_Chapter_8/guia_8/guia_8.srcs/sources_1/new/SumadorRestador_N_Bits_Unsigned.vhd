----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2025 13:33:12
-- Design Name: 
-- Module Name: SumadorRestador_N_Bits - Behavioral
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

entity SumadorRestador_N_Bits_Unsigned is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         sel : in std_logic;
         res : out std_logic_vector(N-1 downto 0));
end SumadorRestador_N_Bits_Unsigned;

architecture Behavioral of SumadorRestador_N_Bits_Unsigned is
    signal s : std_logic_vector(N-1 downto 0);
    signal r : std_logic_vector(N-1 downto 0);
begin

    s <= std_logic_vector(unsigned(b) + unsigned(a));
    r <= std_logic_vector(unsigned(b) - unsigned(a));

    res <= s when(sel = '1') else r;

end Behavioral;
