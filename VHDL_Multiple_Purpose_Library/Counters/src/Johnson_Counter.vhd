----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:33:28
-- Design Name: 
-- Module Name: Johnson_Counter - Behavioral
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

entity Johnson_Counter is
    generic (N : integer := 3);
    Port ( clk : in std_logic;
           clr : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end Johnson_Counter;

architecture Behavioral of Johnson_Counter is
    signal q_S :std_logic_vector (N - 1 downto 0);
begin

    process (clk,clr)
        begin
            if (clr = '1') then
                q_S <= (others => '0');
            elsif (rising_edge (clk)) then
                q_S <= q_S (N - 2 downto 0) & not (q_S(N - 1));
            end if;
    end process;

    q <= q_S;

end Behavioral;
