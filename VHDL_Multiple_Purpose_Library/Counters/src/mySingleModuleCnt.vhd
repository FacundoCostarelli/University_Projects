----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.08.2025 23:06:47
-- Design Name: 
-- Module Name: mySingleModuleCnt - Behavioral
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

entity mySingleModuleCnt is
Generic (N : integer := 4);
     Port ( clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
              p : in std_logic_vector (N - 1 downto 0);             
counting_status : out std_logic); 
end mySingleModuleCnt;

architecture Behavioral of mySingleModuleCnt is

signal cnt_S_U: unsigned(N - 1 downto 0);
signal P_VAL_U: unsigned(N - 1 downto 0) := unsigned(P);

signal cnt_S: std_logic_vector(N - 1 downto 0);

begin     

P_VAL_U <= unsigned(P);  -- concurrente, se actualiza siempre

    process (clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                counting_status <= '0';
                cnt_S_U <= (others => '0');
            elsif(ena = '1') then
                counting_status <= '0';  -- pulso limpio           
                if(cnt_S_U = unsigned(P)) then
                  cnt_S_U <= (others => '0');  -- auto-reset en el MISMO ciclo
                  counting_status <= '1';
                else
                  cnt_S_U <= cnt_S_U + 1;
                end if;
            else
                counting_status <= '0';     
            end if;
        end if;
 end process;
 
 cnt_S <= std_logic_vector(cnt_S_U);
 
end Behavioral;
                 
