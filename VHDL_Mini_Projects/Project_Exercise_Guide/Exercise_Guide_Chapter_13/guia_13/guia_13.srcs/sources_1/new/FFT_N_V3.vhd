----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 24.07.2025 15:27:17
-- Design Name: 
-- Module Name: FFT_N_V3 - Behavioral
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

entity FFT_N_V3 is
    Generic (N : integer := 4);
    Port ( 
        clk : in std_logic;
        rst : in std_logic;
        ena : in std_logic;
        t   : in std_logic_vector (N - 1 downto 0);
        q   : out std_logic_vector (N - 1 downto 0)
    );
end FFT_N_V3;

architecture Behavioral of FFT_N_V3 is
    signal q_s: STD_LOGIC_VECTOR (N - 1 downto 0);
begin
    q <= q_s;
    
    process (clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                q_s <= (others => '0');
            elsif ena = '1' then
                q_s <= q_s xor t;  
            end if;
        end if;
    end process;

end Behavioral;
