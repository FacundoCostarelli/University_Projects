----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.07.2025 14:30:56
-- Design Name: 
-- Module Name: companding_A_tb - Behavioral
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

entity companding_A_tb is
end companding_A_tb;

architecture Behavioral of companding_A_tb is

    component companding_A
        Port (
            clk     : in  std_logic;
            rst     : in  std_logic;
            sck     : in  std_logic;
            entrada : in  std_logic_vector(12 downto 0);
            salida  : out std_logic_vector(7 downto 0)
        );
    end component;

    signal clk_tb     : std_logic := '0';
    signal rst_tb     : std_logic := '1';
    signal sck_tb     : std_logic := '0';
    signal entrada_tb : std_logic_vector(12 downto 0) := (others => '0');
    signal salida_tb  : std_logic_vector(7 downto 0);

    constant clk_period_tb : time := 10 ns;
    constant sck_period_tb : time := 1000 ns;

begin

    -- Instancia del DUT
    uut: companding_A
        port map (
            clk     => clk_tb,
            rst     => rst_tb,
            sck     => sck_tb,
            entrada => entrada_tb,
            salida  => salida_tb
        );

    -- Reloj principal (100 MHz)
    clk_process : process
    begin
        while true loop
            clk_tb <= '0';
            wait for clk_period_tb / 2;
            clk_tb <= '1';
            wait for clk_period_tb / 2;
        end loop;
    end process;

    -- Reloj de datos (1 MHz)
    sck_process : process
    begin
        while true loop
            sck_tb <= '0';
            wait for sck_period_tb / 2;
            sck_tb <= '1';
            wait for sck_period_tb / 2;
        end loop;
    end process;

    -- Estímulos
    stim_proc : process
    begin
        wait for 50 ns;
        rst_tb <= '0';

        wait for sck_period_tb;

        -- Entrada: CHORD = "000", ABCD = "1011", S = '0'
        entrada_tb <= "010000001011";  -- salida esperada: 00001011
        wait for sck_period_tb;

        -- Entrada: CHORD = "111", ABCD = "1100", S = '1'
        entrada_tb <= "1111001100000"; -- salida esperada: 11111100
        wait for sck_period_tb;

        -- Entrada: CHORD = "011", ABCD = "1111", S = '0'
        entrada_tb <= "0011110000000"; -- salida esperada: 00111111
        wait for sck_period_tb;

        -- Entrada: CHORD = "001", ABCD = "0110", S = '1'
        entrada_tb <= "1000011000000"; -- salida esperada: 100010110
        wait for sck_period_tb;

        -- Esperar y finalizar
        wait for 10 * sck_period_tb;
        assert false report "Simulation ended." severity failure;
    end process;

end Behavioral;

