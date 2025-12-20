----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 24.07.2025 15:02:27
-- Design Name: 
-- Module Name: FFT_N_V2 - Behavioral
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


entity FFT_N_V2 is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             t : in std_logic_vector (N - 1 downto 0);
             q : out std_logic_vector (N - 1 downto 0));
end FFT_N_V2;

architecture Behavioral of FFT_N_V2 is

    component FFT is
        Port ( clk : in std_logic;
               rst : in std_logic;
               ena : in std_logic;
                 t : in std_logic;
                 q : out std_logic);
    end component;

    signal q_S: std_logic_vector (N - 1 downto 0);
    
begin

    gen_FFT: for i in 0 to N-1 generate
      INST_FFT: FFT
           port map (
               clk => clk,
               rst => rst,
               ena => ena,
                 t => t(i),
                 q => q_S(i)
                 );
    end generate;           
    
    q <= q_S;

end Behavioral;
