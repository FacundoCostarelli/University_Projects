----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 19:35:06
-- Design Name: 
-- Module Name: myFFD_RisingEdge_ResetAsinc - Behavioral
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
use IEEE.STD_LOGIC_MISC.all;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myFFD_RisingEdge_ResetAsinc is
    Port ( clk : in std_logic;
         clear : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myFFD_RisingEdge_ResetAsinc;

architecture Behavioral of myFFD_RisingEdge_ResetAsinc is

begin

    process (clk, clear)
    begin
        if (clear = '1') then
            q <= '0';
        elsif (rising_edge (clk)) then
            q <= d;
        end if;
    end process;

end Behavioral;
