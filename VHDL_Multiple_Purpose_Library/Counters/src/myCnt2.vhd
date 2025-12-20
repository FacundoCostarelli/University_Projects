----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 17:17:24
-- Design Name: 
-- Module Name: myCnt2 - Behavioral
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

entity myCnt2 is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             p : in std_logic_vector (N - 1 downto 0);
        salida : out std_logic);
end myCnt2;

architecture Behavioral of myCnt2 is
 
 component myCntBinarioSimple is
        Generic( N : integer := 4);
        Port(clk : in std_logic;
             rst : in std_logic;
             ena : in std_logic;
               q : out std_logic_vector (N - 1 downto 0));
    end component;

    signal cnt_S: std_logic_vector (N - 1 downto 0);

begin

U_CNT: myCntBinarioSimple
    Generic map (N => N)
    Port map(clk => clk,
             rst => rst,
             ena => ena,
             q   => cnt_S);
             
process (clk)
begin
    if(rising_edge (clk)) then
        if rst = '1' then
            salida <= '0';
        elsif ena = '1' then
            if(cnt_S = p) then
                salida <= '1';
            else
                salida <= '0';
            end if;
        end if;
    end if;    
end process;


end Behavioral;
