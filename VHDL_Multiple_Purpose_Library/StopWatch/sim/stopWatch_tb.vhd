----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.08.2024 19:41:28
-- Design Name: 
-- Module Name: stopWatch_tb - Behavioral
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

entity stopWatch_tb is
end stopWatch_tb;

architecture Behavioral of stopWatch_tb is

    constant N : integer := 4;

    component stopWatch is
        Generic (N: integer := 4);
        Port (
            clk    : in std_logic;
            rst    : in std_logic;
            start  : in std_logic;
            stop   : in std_logic;
            salida : out std_logic_vector(N-1 downto 0)
        );
    end component;

    signal clk     : std_logic := '0';
    signal rst     : std_logic := '0';
    signal start   : std_logic := '0';
    signal stop    : std_logic := '0';
    signal salida  : std_logic_vector(N-1 downto 0);

    constant clk_period : time := 10 ns;

begin

    -- Instancia del DUT
    uut: stopWatch
        generic map (N => N)
        port map (
            clk    => clk,
            rst    => rst,
            start  => start,
            stop   => stop,
            salida => salida
        );

    -- Proceso de reloj
    clk_process : process
    begin
        while true loop
            clk <= '0'; wait for clk_period / 2;
            clk <= '1'; wait for clk_period / 2;
        end loop;
    end process;

    -- Proceso de estímulos
    stim_proc : process
    begin
        -- Reset inicial
        rst <= '1';
        wait for 40 ns;
        rst <= '0';

        -- Activar START (por un ciclo)
        wait for 20 ns;
        start <= '1'; 
        wait for clk_period;
        start <= '0';

        -- Contar un poco
        wait for 200 ns;

        -- Activar STOP (por un ciclo)
        stop <= '1'; 
        wait for clk_period;
        stop <= '0';

        wait;
    end process;

end Behavioral;

