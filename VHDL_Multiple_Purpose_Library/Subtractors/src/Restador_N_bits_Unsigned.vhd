----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2025 13:30:04
-- Design Name: 
-- Module Name: Restador_N_bits - Behavioral
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

entity Restador_N_bits_Unsigned is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         res : out std_logic_vector(N-1 downto 0));
end Restador_N_bits_Unsigned;

architecture Behavioral of Restador_N_bits_Unsigned is

begin

    res <= std_logic_vector(unsigned(b) - unsigned(a));

end Behavioral;
