----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 08:38:39
-- Design Name: 
-- Module Name: myLatchD_Clr - Behavioral
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


-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myLatchD_Clr is
    Port ( ena : in std_logic;
           clr : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myLatchD_Clr;

architecture Behavioral of myLatchD_Clr is

begin

    process (ena, d)
    begin
        if (clr = '1') then -- Clear Asinc --> va justo encima del if que evalua "ena"
            q <= '0';
        elsif (ena = '1') then
            q <= d;
        end if;
    end process;

end Behavioral;
