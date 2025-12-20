----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.05.2025 22:25:16
-- Design Name: 
-- Module Name: Sumador_N_Bits_Signed - Behavioral
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

entity Sumador_N_Bits_Signed is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         res : out std_logic_vector(N-1 downto 0));
end Sumador_N_Bits_Signed;

architecture Behavioral of Sumador_N_Bits_Signed is

begin

    res <= std_logic_vector(signed(b) + signed(a));

end Behavioral;
