----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor myCnt System with I/O
-- Module Name: myCnt - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Generador de pulsos de temporización. Produce una señal al final del ciclo (M)
-- y otra a la mitad (M/2), fundamental para el muestreo de la UART.
-- ENG: Timing pulse generator. Produces a signal at the end of the cycle (M)
-- and another at the half (M/2), essential for UART sampling.
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.math_real.all;

entity myCnt is
    Generic (M : integer := 100); -- ESP: Valor del divisor / ENG: Divisor value
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
     salidaM_2 : out std_logic;  -- ESP: Pulso a mitad de ciclo / ENG: Half-cycle pulse
       salidaM : out std_logic); -- ESP: Pulso a fin de ciclo / ENG: End-of-cycle pulse
end myCnt;

architecture Behavioral of myCnt is

-- ESP: Cálculo automático de bits necesarios para el contador
-- ENG: Automatic calculation of required bits for the counter
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
                -- ESP: Generación de pulsos según el estado del contador
                -- ENG: Pulse generation based on counter state     
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

