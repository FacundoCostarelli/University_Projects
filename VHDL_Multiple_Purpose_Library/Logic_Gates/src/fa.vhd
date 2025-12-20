----------------------------------------------------------------------------------
-- Company:  UTN BA
-- Engineer:  Facundo Costarelli
-- 
-- Create Date: 12.05.2025 21:44:33
-- Design Name: xor_operation_&_carry_out_operation 
-- Module Name: fa - Behavioral
-- Project Name: Exercise 2
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

entity fa is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           ci : in STD_LOGIC;
           co : out STD_LOGIC;
           s : out STD_LOGIC);
end fa;

architecture Behavioral of fa is

begin

s <= a xor b xor ci;
co <= (a and b) or (b and ci) or (a and ci);

end Behavioral;
