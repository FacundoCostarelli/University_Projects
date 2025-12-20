----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 12:44:42
-- Design Name: 
-- Module Name: myLatchD - Behavioral
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

-- Implementación de un Latch D
entity myLatchD is
    Port ( ena : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myLatchD;

architecture Behavioral of myLatchD is

begin

    process (ena, d)
        begin
            if (ena = '1') then
                q <= d;
            end if;
        end process;

end Behavioral;
