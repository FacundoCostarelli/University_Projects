----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.07.2025 13:20:32
-- Design Name: 
-- Module Name: parpadeo1S_tb - Behavioral
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

entity parpadeo1S_tb is
end parpadeo1S_tb;

architecture Behavioral of parpadeo1S_tb is
    -- Parámetros del diseño
    --constant N : integer := 8;
    constant clk_period : time := 10 ns;
    -- 10 = ciclos de clk, 
    -- 1 ciclo que lleva colocar el flag en alto despues del conteo
    -- 1 ciclo que lleva colocar en en alto o bajo la salida
    -- 2 = ciclos extras mencionados arriba
    constant SYS_CLK_tb : integer := 10 - 2; 
    -- Señales de prueba
    signal clk_tb    : std_logic := '0';
    signal rst_tb    : std_logic := '0';
    signal salida_tb : std_logic;
   
    component parpadeo1S is
        Generic (SYS_CLK: integer := 100000000);
        Port ( 
                    clk : in std_logic;
                    rst : in std_logic;
                    salida : out std_logic
        );
    end component;
    
begin
    -- Instanciar el diseño
    DUT: parpadeo1S
        generic map (
             SYS_CLK => SYS_CLK_tb  -- contar solo 10 ciclos
        )
        port map (
            clk      => clk_tb,
            rst      => rst_tb,
            salida   => salida_tb
        );

    -- Generador de reloj con clk_period
    clk_process : process
    begin
        while true loop
            clk_tb <= '0';
            wait for clk_period / 2;
            clk_tb <= '1';
            wait for clk_period / 2;
        end loop;
    end process;
    
    -- Estímulo de señales
    stim_proc : process
    begin
        -- Reset activo
        rst_tb <= '1';
        wait for 2 * clk_period;
        rst_tb <= '0';
        
        -- Esperar 1000 ns para observar cambios
        wait for 1000 ns;

        wait;
    end process;
    
    monitor_proc : process(clk_tb)
    begin
        if rising_edge(clk_tb) then
            report "Tiempo: " & time'image(now) & 
                   " - salida_tb: " & std_logic'image(salida_tb);
        end if;
    end process;
    
end Behavioral;
