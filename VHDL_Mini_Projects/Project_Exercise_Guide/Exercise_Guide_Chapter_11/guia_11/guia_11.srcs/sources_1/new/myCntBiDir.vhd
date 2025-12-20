----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.07.2025 21:31:13
-- Design Name: 
-- Module Name: myCntBiDir - Behavioral
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

entity myCntBiDir is
    Generic (N: integer := 4);
    Port ( clk: in std_logic;
           rst: in std_logic;
           ena: in std_logic;
           dir: in std_logic;
            q : out std_logic_vector (N-1 downto 0));
end myCntBiDir;

architecture Behavioral of myCntBiDir is
    signal q_S : unsigned (N - 1 downto 0);

begin

process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            q_S <= (others => '0');
        elsif (ena = '1') then
            if (dir = '0') then
                q_S <= q_S + 1;
            else
                q_S <= q_S - 1;
            end if;
        end if;
    end if;
end process;

q <= std_logic_vector (q_S);


end Behavioral;
