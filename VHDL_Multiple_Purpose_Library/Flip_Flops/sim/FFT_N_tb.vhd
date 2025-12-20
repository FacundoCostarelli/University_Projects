----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 23.07.2025 09:19:46
-- Design Name: 
-- Module Name: FFT_N_tb - Behavioral
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

entity FFT_N_tb is
end FFT_N_tb;

architecture Behavioral of FFT_N_tb is

  constant N : integer := 4;

  signal clk : std_logic := '0';
  signal rst, ena : std_logic := '0';
  signal t : std_logic_vector(N-1 downto 0) := (others => '0');
  signal q : std_logic_vector(N-1 downto 0);

  -- Clock period definition
  constant clk_period : time := 10 ns;

begin

  -- DUT instantiation
  DUT: entity work.FFT_N
    generic map (N => N)
    port map (
      clk => clk,
      rst => rst,
      ena => ena,
      t   => t,
      q   => q
    );

  -- Clock generation
  clk_proc: process
  begin
    while true loop
      clk <= '0'; wait for clk_period / 2;
      clk <= '1'; wait for clk_period / 2;
    end loop;
  end process;

  

  -- Main stimuli process
  stim_proc: process
  
  -- Estímulos: procedimiento para aplicar un vector T
  procedure aplicar_t_vector (
    constant vec : in std_logic_vector(N-1 downto 0);
    constant dur : in time := clk_period
  ) is
  begin
    t <= vec;
    wait for dur;
  end procedure;
  
  begin

    -- Inicialización
    rst <= '1';
    ena <= '0';
    t <= (others => '0');
    wait for clk_period;
    
    -- Fin del reset
    rst <= '0';
    wait for clk_period;

    -- Activar enable y probar toggles con vectores distintos
    ena <= '1';

    aplicar_t_vector("1010");  -- toggle en bits 3 y 1
    aplicar_t_vector("0101");  -- toggle en bits 2 y 0
    aplicar_t_vector("0000");  -- nada cambia
    aplicar_t_vector("1111");  -- toggle todos los bits
    aplicar_t_vector("0001");  -- toggle solo LSB
    aplicar_t_vector("1101");  -- toggle bits 3, 2, 0

    -- Reset en medio de funcionamiento
    rst <= '1';
    wait for clk_period;
    rst <= '0';

    aplicar_t_vector("1111");  -- toggle todos de nuevo tras reset

    -- Fin de simulación
    wait for 2*clk_period;
    assert false report "Fin de la simulación - FFT_N_tb" severity failure;

  end process;

end Behavioral;

