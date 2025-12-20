----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.07.2025 20:23:24
-- Design Name: 
-- Module Name: myLatch_D - Behavioral
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



entity myLatch_D is
    Port ( ena : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myLatch_D;

architecture Behavioral of myLatch_D is

begin

process (ena, d)
begin
    if (ena = '1') then
        q <= d;
    end if;
end process;

end Behavioral;
