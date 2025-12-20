----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.07.2025 16:14:09
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

entity FFT is
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             t : in std_logic;
             q : out std_logic);
end FFT;

architecture Behavioral of FFT is
    signal q_s: std_logic;

begin
   
    process (clk)
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                q_s <= '0';
            elsif ( ena = '1') then
                if (t = '1') then
                    q_s <= not q_s;
                end if;
            end if;
        end if;
    end process;
    
     q <= q_s;
    
end Behavioral;