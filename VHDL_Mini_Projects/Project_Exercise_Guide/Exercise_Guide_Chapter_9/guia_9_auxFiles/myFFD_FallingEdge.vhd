----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 18:42:51
-- Design Name: 
-- Module Name: myFFD_FallingEdge - Behavioral
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

entity myFFD_FallingEdge is
    Port ( clk : in std_logic;
             d : in std_logic;
              q : out std_logic);
end myFFD_FallingEdge;

architecture Behavioral of myFFD_FallingEdge is

begin

    process (clk)
    begin
        if (falling_edge (clk)) then
        q <= d;
        end if;
    end process;

end Behavioral;
