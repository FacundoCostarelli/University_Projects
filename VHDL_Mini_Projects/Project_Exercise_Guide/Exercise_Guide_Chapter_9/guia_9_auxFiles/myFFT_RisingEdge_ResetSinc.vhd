----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.06.2025 20:10:08
-- Design Name: 
-- Module Name: myFFT_RisingEdge_ResetSinc - Behavioral
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

entity myFFT_RisingEdge_ResetSinc is
    Port ( clk : in std_logic;
           rst : in std_logic;
             t : in std_logic;
             q : out std_logic);
end myFFT_RisingEdge_ResetSinc;

architecture Behavioral of myFFT_RisingEdge_ResetSinc is
    signal q_s: std_logic;

begin
    q <= q_s;
    process (clk)
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                q_s <= '0';
            else
                if (t = '1') then
                    q_s <= not q_s;
                end if;
            end if;
        end if;
    end process;
    
end Behavioral;
