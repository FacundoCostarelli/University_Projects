----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 19:18:39
-- Design Name: 
-- Module Name: myFFD_RisingEdge_N_Bits - Behavioral
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

entity myFFD_RisingEdge_N_Bits is
    Generic (N : integer := 8);
    Port ( clk : in std_logic;
             d : in std_logic_vector(N-1 downto 0);
             q : out std_logic_vector(N-1 downto 0));
end myFFD_RisingEdge_N_Bits;

architecture Behavioral of myFFD_RisingEdge_N_Bits is

begin

    process (clk)
    begin
    if (rising_edge (clk)) then
        q <= d;
    end if;

end process;

end Behavioral;
