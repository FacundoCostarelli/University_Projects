----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 14:44:39
-- Design Name: 
-- Module Name: myEdgeCnt_V2 - Behavioral
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

entity myEdgeCnt_V2 is
    Generic (N: integer := 8);
    Port ( clk: in std_logic;
    rst: in std_logic;
    d: in std_logic;
    q : out std_logic_vector (N-1 downto 0));        
end myEdgeCnt_V2;

architecture Behavioral of myEdgeCnt_V2 is
    signal d_reg : std_logic;
    signal cnt_S : unsigned (N - 1 downto 0);

begin

process (clk,rst)
begin
    if rising_edge(clk) then
            if rst = '1' then
                d_reg <= '0';
                cnt_S <= to_unsigned(0, cnt_S'length);
            else
                if d = '1' and d_reg = '0' then
                    cnt_S <= cnt_S + 1;
                end if;
                d_reg <= d;
            end if;
        end if;
end process;
     q <= std_logic_vector(cnt_S);    
     
end Behavioral;
