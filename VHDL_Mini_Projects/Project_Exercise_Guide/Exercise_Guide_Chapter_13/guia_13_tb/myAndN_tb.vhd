----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.07.2025 15:36:17
-- Design Name: 
-- Module Name: myAndN_tb - Behavioral
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

entity myAndN_tb is
-- no  Port ( );
end myAndN_tb;

architecture Behavioral of myAndN_tb is
    
    component myAndN is
        Generic (N : integer := 4); 
        Port (   a : in std_logic_vector (N - 1 downto 0);
                 y : out std_logic);
    end component;
    
  constant N : integer := 4;
  signal a_S : std_logic_vector(N-1 downto 0) := (others => '0');
  signal y_S : std_logic;

begin
  
  UUT_myAndN: entity work.myAndN
    generic map (N => N)
    port map (
      a => a_S,
      y => y_s
    );

  stim: process
  begin
    a_S <= "0000"; wait for 50 ns;
    a_S <= "0111"; wait for 50 ns;
    a_S <= "1111"; wait for 50 ns;  -- aquí y='1'
    a_S <= "1011"; wait for 50 ns;
    a_S <= "1110"; wait for 50 ns;
    a_S <= "1111"; wait for 50 ns;  -- y='1' de nuevo
    wait;  -- fin de simulación
  end process;


end Behavioral;
