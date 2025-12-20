----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 19:53:05
-- Design Name: 
-- Module Name: myFFD_RisingEdge_Enable - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myFFD_RisingEdge_Enable is
    Port ( clk : in std_logic;
           ena : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myFFD_RisingEdge_Enable;

architecture Behavioral of myFFD_RisingEdge_Enable is

begin

    process (clk)
    begin
        if (rising_edge (clk)) then
            if (ena = '1') then
                q <= d;
            end if;
        end if;
    end process;

end Behavioral;
