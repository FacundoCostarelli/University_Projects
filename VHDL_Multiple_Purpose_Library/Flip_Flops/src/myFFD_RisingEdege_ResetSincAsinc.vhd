----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 08:30:26
-- Design Name: 
-- Module Name: myFFD_RisingEdege_ResetSincAsinc - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myFFD_RisingEdege_ResetSincAsinc is
    Port ( clk : in std_logic;
           rst : in std_logic;
      rstAsync : in std_logic;
             d : in std_logic;
             q : out std_logic);
end myFFD_RisingEdege_ResetSincAsinc;

architecture Behavioral of myFFD_RisingEdege_ResetSincAsinc is

begin

    process (clk, rstAsync)
    begin
        if (rstAsync = '1') then
            q <= '0';
        elsif (rising_edge (clk)) then
            if (rst = '1') then
                q <= '0';
            else
                q <= d;
            end if;
        end if;
    end process;

end Behavioral;
