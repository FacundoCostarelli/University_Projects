----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 24.07.2025 15:09:15
-- Design Name: 
-- Module Name: FFT_N_V2_tb - Behavioral
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


entity FFT_N_V2_tb is
end FFT_N_V2_tb;

architecture Behavioral of FFT_N_V2_tb is

  constant N : integer := 4;

  signal clk : std_logic := '0';
  signal rst, ena : std_logic := '0';
  signal t : std_logic_vector(N-1 downto 0) := (others => '0');
  signal q : std_logic_vector(N-1 downto 0);

  -- Clock period definition
  constant clk_period : time := 10 ns;

begin

    -- DUT instantiation
    DUT: entity work.FFT_N_V2
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
  -- Stimuli
    stim_proc: process
    begin
        -- Reset inicial
        rst <= '1'; ena <= '0'; t <= (others => '0');
        wait for clk_period;

        -- Fin del reset
        rst <= '0'; wait for clk_period;

        -- Activar enable y aplicar estímulos
        ena <= '1';
        t <= "1010"; wait for clk_period;
        t <= "0101"; wait for clk_period;
        t <= "1111"; wait for clk_period;
        t <= "0000"; wait for clk_period;

        -- Reset durante operación
        rst <= '1'; wait for clk_period;
        rst <= '0'; wait for clk_period;

        -- Otro patrón
        t <= "1100"; wait for clk_period;
        t <= "0011"; wait for clk_period;

        -- Final
        wait for 2*clk_period;
        assert false report "Fin de la simulación" severity failure;
        wait;
    end process;

end Behavioral;
