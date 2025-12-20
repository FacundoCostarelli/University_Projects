----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 16:01:52
-- Design Name: 
-- Module Name: parpadeo1S - Behavioral
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
use IEEE.MATH_REAL.ALL;

entity parpadeo1S is
    Generic (SYS_CLK: integer := 100000000);
    Port ( clk : in std_logic;
    rst : in std_logic;
    salida : out std_logic);
end parpadeo1S;

architecture Behavioral of parpadeo1S is

--constant N : integer := integer(ceil(log2(real(SYS_CLK))));
constant N : integer := 32;
constant CS : std_logic_vector(N - 1 downto 0) := std_logic_vector(to_unsigned(SYS_CLK, N));

signal salida_S : std_logic;
signal flag_out_Cnt_S: std_logic;
signal rst_cnt_S : std_logic := '0';  -- señal interna de reset

component myCnt2 is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             p : in std_logic_vector (N - 1 downto 0);
        salida : out std_logic);
end component;
    
    
begin

U1: myCnt2
    Generic map (N => N)-- ? Que pongo acá? Debo contar 100.000.000 de ciclos y debe ser representable con cierta cantidad de N bits
    Port map(
           clk    => clk,
           rst    => rst_cnt_S,
           ena    => '1',
           p      => CS,
           salida => flag_out_Cnt_S);

process(clk)
begin
    if(rising_edge (clk)) then
        if rst = '1' then
            salida_S <= '0';
            rst_cnt_S  <= '1';  -- reset inicial del contador
        elsif(flag_out_Cnt_S = '1') then
            salida_S <= not salida_S;
            rst_cnt_S  <= '1';  -- reset al contador tras cada pulso
        else
            rst_cnt_S  <= '0';
        end if;
    end if;    
end process;

salida <= salida_S;

end Behavioral;
