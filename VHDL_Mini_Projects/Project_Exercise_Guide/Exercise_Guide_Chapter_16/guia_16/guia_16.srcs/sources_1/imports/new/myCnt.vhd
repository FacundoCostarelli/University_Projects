----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.07.2025 21:45:21
-- Design Name: 
-- Module Name: myCnt - Behavioral
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
use ieee.math_real.all;

entity myCnt is
    Generic (M : integer := 100);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
     salidaM_2 : out std_logic;
       salidaM : out std_logic);
end myCnt;

architecture Behavioral of myCnt is

-- Conversion de cantidad decimal M pulsos a cantidad N bits necesaria para contar los pulsos. Vale para M y M/2
constant N : integer := integer(ceil(log2(real (M))));
constant M_U  : unsigned(N - 1 downto 0) := to_unsigned(M - 1, N); --Modulo de comparacion 
constant M_2 : unsigned (N-1 downto 0) := to_unsigned(M-1, N) / 2; --Modulo de comparacion

signal cnt_S_U: unsigned(N - 1 downto 0);

begin
    process (clk)
    begin
        if(rising_edge (clk)) then
            if(rst = '1') then
                salidaM_2 <= '0';
                salidaM   <= '0';
                cnt_S_U   <= (others => '0');              
            elsif(ena = '1') then      
                cnt_S_U <= cnt_S_U + 1;     
                if(cnt_S_U = M_U) then
                      cnt_S_U <= (others => '0');                    
                      salidaM <= '1';
                elsif(cnt_S_U = M_2) then                   
                    salidaM_2 <= '1';                                   
                else                   
                    salidaM <= '0';
                    salidaM_2 <= '0';
                end if;
            else
                cnt_S_U <= (others => '0'); 
                
            end if;
        end if;    
    end process;
    
end Behavioral;

