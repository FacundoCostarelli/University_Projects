----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.07.2025 22:59:23
-- Design Name: 
-- Module Name: fibonacciCnt_tb - Behavioral
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
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity fibonacciCnt_tb is end fibonacciCnt_tb;

architecture Behavioral of fibonacciCnt_tb is
  constant N : integer := 5;
  signal clk_tb  : std_logic := '0';
  signal rst_tb  : std_logic := '0';
  signal ena_tb  : std_logic := '0';
  signal cnt_tb  : std_logic_vector(N-1 downto 0);
  constant clk_period : time := 10 ns;
begin
  uut: entity work.fibonacciCnt
    generic map (N => N)
    port map (clk => clk_tb, rst => rst_tb, ena => ena_tb, cnt => cnt_tb);

  clk_proc: process
  begin
    clk_tb <= '0'; wait for clk_period/2;
    clk_tb <= '1'; wait for clk_period/2;
  end process;

  stim: process
  begin
    rst_tb <= '1'; ena_tb <= '0';
    wait for 2*clk_period;       -- reset 2 ciclos
    wait until rising_edge(clk_tb);
    rst_tb <= '0'; ena_tb <= '1';-- habilitar
    wait for 80*clk_period;      -- correr
    wait;
  end process;
end Behavioral;