----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:08:30
-- Design Name: 
-- Module Name: myShiftReg_Generic_N_bits - Behavioral
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

entity myShiftReg_Generic_N_bits is
    generic (N : integer := 3);
    Port ( clk : in std_logic;
           clr : in std_logic;
            si : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end myShiftReg_Generic_N_bits;

architecture Behavioral of myShiftReg_Generic_N_bits is
    signal q_S :std_logic_vector (N - 1 downto 0);

begin
    
    process (clk, clr)
        begin
            if (clr = '1') then
                q_S <= (others => '0');
            elsif (rising_edge (clk)) then
                q_S <= q_S (N - 2 downto 0) & si;
            end if;
    end process;
            q <= q_S;
            
end Behavioral;