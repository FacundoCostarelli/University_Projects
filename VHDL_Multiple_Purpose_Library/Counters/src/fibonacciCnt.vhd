----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.11.2025 20:03:02
-- Design Name: 
-- Module Name: fibonacciCnt - Behavioral
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

entity fibonacciCnt is
    Generic (N: integer := 5);
    Port ( clk: in std_logic;
           rst: in std_logic;
           ena: in std_logic;
           cnt: out std_logic_vector (N - 1 downto 0));
end fibonacciCnt;

architecture Behavioral of fibonacciCnt is

signal cnt_actual_S: unsigned(N-1 downto 0);
signal cnt_anterior1_S: unsigned(N-1 downto 0);
signal cnt_anterior2_S: unsigned(N-1 downto 0);

signal max_numero_representable_Nbits: unsigned(N-1 downto 0) := (others => '1');

begin



process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            cnt_actual_S    <= (others => '0');
            cnt_anterior1_S  <= (others => '0');
            cnt_anterior2_S <= (others => '0');
        else
            if(ena = '1') then
                if(cnt_anterior1_S = 0 and cnt_anterior2_S = 0 ) then
                    cnt_actual_S <= to_unsigned(1,N);
                    cnt_anterior1_S <= to_unsigned(1,N);
                elsif(cnt_anterior1_S = 1 and cnt_anterior2_S = 0) then
                    cnt_actual_S <= to_unsigned(1,N);
                    cnt_anterior2_S <= to_unsigned(1,N);
                else                            
                    
                    if( cnt_anterior1_S < max_numero_representable_Nbits - cnt_anterior2_S ) then                    
                        cnt_actual_S <= cnt_anterior1_S + cnt_anterior2_S;
                        cnt_anterior2_S <= cnt_anterior1_S;
                        cnt_anterior1_S <= cnt_anterior1_S + cnt_anterior2_S; 
                    else
                       cnt_actual_S    <= (others => '0');
                       cnt_anterior1_S  <= (others => '0');
                       cnt_anterior2_S <= (others => '0'); 
                    end if;
                end if;
            end if;
        end if;
    end if;
end process;

cnt <= std_logic_vector(cnt_actual_S);


end Behavioral;
