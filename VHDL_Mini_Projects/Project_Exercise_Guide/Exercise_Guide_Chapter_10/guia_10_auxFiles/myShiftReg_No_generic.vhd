----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:05:34
-- Design Name: 
-- Module Name: myShiftReg_No_generic - Behavioral
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

entity myShiftReg_No_generic is
    generic (N : integer := 3);
    Port ( clk : in std_logic;
           clr : in std_logic;
            si : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end myShiftReg_No_generic;

architecture Behavioral of myShiftReg_No_generic is
    signal q_S :std_logic_vector (N - 1 downto 0);

begin
    process (clk, clr)
        begin
            if (clr = '1') then
                q_S <= (others => '0');
            elsif (rising_edge (clk)) then
                q_S(0) <= si;
                q_S(1) <= q_S(0);
                q_S(2) <= q_S(1); -- No es generico
            end if;
    end process;
            q <= q_S;
            
end Behavioral;