----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.05.2025 00:49:43
-- Design Name: 
-- Module Name: calcOverflow - Behavioral
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

entity calcOverflow is
    Port ( a : in STD_LOGIC;  -- operando a (Sign bit)
           b : in STD_LOGIC;  -- operando b (Sign bit)
           r : in STD_LOGIC;  -- resultado de operacion (Sign bit)
           op : in STD_LOGIC; -- Si vale 0 es suma, si vale 1 es resta
           ov : out STD_LOGIC); -- Flag de overflow
end calcOverflow;

architecture Behavioral of calcOverflow is
    signal in_S: std_logic_vector (3 downto 0);
begin

in_S <= op & r & b & a; -- Bit positions: [3][2][1][0]

with in_S select
    ov <= '1' when "0011" | "0100" | "1010" | "1101", -- La barra | siginifica or 
          '0' when others;


end Behavioral;
