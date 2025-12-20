----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 12:33:43
-- Design Name: 
-- Module Name: FFT - Behavioral
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

-- flip-flop T con reset sincronico

entity FFT is
    Port ( clk : in std_logic;
           rst : in std_logic;
             t : in std_logic;
             q : out std_logic);
end FFT;

architecture Behavioral of FFT is
    signal q_s: std_logic;

begin

    q <= q_s;
    process(clk)
    begin
        if(rising_edge (clk)) then
            if(rst = '1') then
                q_s <= '0';
            elsif(t = '1') then -- t en 1 implica "negar" el dato "q" y mandarlo ese dato al cable de "q"
                q_s <= not q_s; -- solo con una signal puedo negar un dato de un cable y que en ese mismo cable se asigne el dato negado
            end if;
        end if;
    end process;

end Behavioral;
