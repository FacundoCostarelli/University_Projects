----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 19:30:59
-- Design Name: 
-- Module Name: myFFD_RisingEdge_SetAsinc - Behavioral
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

entity myFFD_RisingEdge_SetAsinc is
    Port ( clk : in std_logic;
        preset : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myFFD_RisingEdge_SetAsinc;

architecture Behavioral of myFFD_RisingEdge_SetAsinc is

begin

    process (clk, preset)
    begin
        if (preset = '1') then
            q <= '1';
        elsif (rising_edge (clk)) then
            q <= d;
        end if;
    end process;

end Behavioral;
