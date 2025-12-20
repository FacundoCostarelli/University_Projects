----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.07.2025 15:57:13
-- Design Name: 
-- Module Name: myAndN - Behavioral
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
use IEEE.STD_LOGIC_MISC.ALL;
-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myAndN is
    Generic (N : integer := 4); 
    Port (   a : in std_logic_vector (N - 1 downto 0);
             y : out std_logic);
end myAndN;

architecture Behavioral of myAndN is

begin
   y <= and_reduce(a);
   --y <= a(0) and a(1) and a(2) and a(3);
end Behavioral;
