----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:31:05
-- Design Name: 
-- Module Name: Contador_Anillo - Behavioral
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


entity Ring_Counter is
    generic (N : integer := 3);
     Port (clk : in std_logic;
           clr : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end Ring_Counter;
    
architecture Behavioral of Ring_Counter is
    signal q_S :std_logic_vector (N - 1 downto 0);
begin

    process (clk,clr)
        begin
            if (clr = '1') then
                q_S <= ('1',others => '0');
            elsif (rising_edge (clk)) then
                q_S <= q_S (N - 2 downto 0) & q_S(N - 1);
            end if;
    end process;
    
    q <= q_S;

end Behavioral;
