----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 08:56:59
-- Design Name: 
-- Module Name: myFFDREna - Behavioral
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

-- Flip-Flop D con reset sincrónico y enable
entity myFFDREna is
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myFFDREna;

architecture Behavioral of myFFDREna is

begin

    process(clk)
        begin
            if(rising_edge(clk)) then
                if(ena = '1') then -- Enable, para FFD Sinc --> va justo debajo del if que evalua el "clk"
                    if (rst = '1') then -- Reset Sinc --> va justo debajo del if que evalua "clk"
                        q <= '0';
                    else
                        q <= d;
                    end if;
                end if;
            end if;
        end process;
end Behavioral;
