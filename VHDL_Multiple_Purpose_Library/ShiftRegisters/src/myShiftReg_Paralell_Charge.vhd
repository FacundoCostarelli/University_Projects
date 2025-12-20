----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:26:12
-- Design Name: 
-- Module Name: myShiftReg_Paralell_Charge - Behavioral
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

entity myShiftReg_Paralell_Charge is
    generic (N : integer := 3);
    Port ( clk : in std_logic;
            pl : in std_logic;
            si : in std_logic;
             d : in std_logic_vector (N - 1 downto 0);
             q : out std_logic_vector (N - 1 downto 0));
end myShiftReg_Paralell_Charge;

architecture Behavioral of myShiftReg_Paralell_Charge is
    signal q_S :std_logic_vector (N - 1 downto 0);
begin

    process (clk)
        begin
            if (rising_edge (clk)) then
                if (pl = '1') then
                    q_S <= q_S (N - 2 downto 0) & si;
                else
                    q_S <= d;
                end if;
            end if;
        end process;
    q <= q_S;
    
end Behavioral;
