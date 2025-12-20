----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.06.2025 12:12:25
-- Design Name: 
-- Module Name: myShiftReg_Ena - Behavioral
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
    
entity myShiftReg_Ena is
    generic (N : integer := 3);
    Port ( clk : in std_logic;
           ena : in std_logic;
            si : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end myShiftReg_Ena;

architecture Behavioral of myShiftReg_Ena is
    signal q_S :std_logic_vector (N - 1 downto 0);
begin

    process (clk)
        begin
            if (rising_edge (clk)) then
                if (ena = '1') then
                    q_S <= q_S (N - 2 downto 0) & si;
                end if;
            end if;
    end process;
    
    q <= q_S;

end Behavioral;
