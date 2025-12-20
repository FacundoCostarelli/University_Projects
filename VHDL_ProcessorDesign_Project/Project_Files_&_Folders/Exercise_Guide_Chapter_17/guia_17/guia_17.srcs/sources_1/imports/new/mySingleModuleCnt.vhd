----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor mySingleModuleCnt System with I/O
-- Module Name: mySingleModuleCnt - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Contador de eventos con límite configurable. Utilizado para contar
-- la cantidad de bits transmitidos o recibidos en la UART.
-- ENG: Event counter with configurable limit. Used to count the number 
-- of bits transmitted or received in the UART.
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity mySingleModuleCnt is
Generic (N : integer := 4);
     Port ( clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
              p : in std_logic_vector (N - 1 downto 0); -- ESP: Límite de cuenta / ENG: Count limit             
counting_status : out std_logic); -- ESP: Indica fin de cuenta / ENG: End of count flag
end mySingleModuleCnt;

architecture Behavioral of mySingleModuleCnt is

signal cnt_S_U: unsigned(N - 1 downto 0);
signal P_VAL_U: unsigned(N - 1 downto 0) := unsigned(P);

signal cnt_S: std_logic_vector(N - 1 downto 0);

begin     

P_VAL_U <= unsigned(P); 

    process (clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                counting_status <= '0';
                cnt_S_U <= (others => '0');
            elsif(ena = '1') then
                counting_status <= '0';
                 
                -- ESP: Reinicio automático al alcanzar el valor P
                -- ENG: Auto-reset upon reaching value P           
                if(cnt_S_U = unsigned(P)) then
                  cnt_S_U <= (others => '0');  
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
                 
