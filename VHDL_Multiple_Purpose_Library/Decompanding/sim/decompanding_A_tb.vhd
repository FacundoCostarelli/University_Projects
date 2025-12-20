----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.07.2025 13:24:07
-- Design Name: 
-- Module Name: decompanding_A_tb - Behavioral
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

entity decompanding_A_tb is
end decompanding_A_tb;

architecture Behavioral of decompanding_A_tb is

    -- Componente a probar
    component decompanding_A
        Port (
            clk     : in  std_logic;
            rst     : in  std_logic;
            sck     : in  std_logic;
            salida  : out std_logic_vector(12 downto 0);
            entrada : in  std_logic_vector(7 downto 0)
        );
    end component;

    -- Señales internas del testbench con sufijo _tb
    signal clk_tb     : std_logic := '0';
    signal rst_tb     : std_logic := '1';
    signal sck_tb     : std_logic := '0';
    signal entrada_tb : std_logic_vector(7 downto 0) := (others => '0');
    signal salida_tb  : std_logic_vector(12 downto 0);

    -- Parámetros de reloj
    constant clk_period_tb : time := 10 ns;
    constant sck_period_tb : time := 1000 ns;

begin

    -- Instancia del DUT (Device Under Test)
    uut: decompanding_A
        port map (
            clk     => clk_tb,
            rst     => rst_tb,
            sck     => sck_tb,
            entrada => entrada_tb,
            salida  => salida_tb
        );

    -- Generador de reloj clk_tb (100 MHz)
    clk_process_tb : process
    begin
        while true loop
            clk_tb <= '0';
            wait for clk_period_tb / 2;
            clk_tb <= '1';
            wait for clk_period_tb / 2;
        end loop;
    end process;

    -- Generador de sck_tb (1 MHz)
    sck_process_tb : process
    begin
        wait for 200 ns; -- Delay inicial
        while true loop
            sck_tb <= '0';
            wait for sck_period_tb / 2;
            sck_tb <= '1';
            wait for sck_period_tb / 2;
        end loop;
    end process;

    -- Estímulos
    stim_proc_tb : process
    begin
        wait for 100 ns;
        rst_tb <= '0';

        -- Enviar patrones
        wait for sck_period_tb;
        entrada_tb <= "00011011"; -- CHORD = 000, ABCD = 1011, S = 0

        wait for sck_period_tb;
        entrada_tb <= "11101100"; -- CHORD = 110, ABCD = 1100, S = 1

        wait for sck_period_tb;
        entrada_tb <= "10000001"; -- CHORD = 000, ABCD = 0001, S = 1

        wait for sck_period_tb;
        entrada_tb <= "01111111"; -- CHORD = 111, ABCD = 1111, S = 0

        -- Espera para ver el resultado
        wait for 10 * sck_period_tb;

        -- Fin de simulación
        assert false report "Simulación finalizada correctamente." severity failure;
    end process;

end Behavioral;
