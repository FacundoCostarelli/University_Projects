----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.06.2025 18:38:57
-- Design Name: 
-- Module Name: myLatch - Behavioral
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

entity myLatch is --Latch D
    Port (ena : in std_logic;
            d : in std_logic;
            q : out std_logic);
end myLatch;

architecture Behavioral of myLatch is

begin
    process (ena, d)
    begin
        if (ena = '1') then
        q <= d;
    end if;

end process;

end Behavioral;
