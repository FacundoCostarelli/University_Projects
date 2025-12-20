----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.08.2024 20:09:31
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FFT_N_V3_tb is
    Generic (N : integer := 4);
end FFT_N_V3_tb;

architecture Behavioral of FFT_N_V3_tb is

component FFT_N is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
    rst : in std_logic;
    ena : in std_logic;
    t : in std_logic_vector (N - 1 downto 0);
    q : out std_logic_vector (N - 1 downto 0)
);
end component;

signal rst : std_logic;
signal ena : std_logic;
signal t : std_logic_vector (N - 1 downto 0);
signal q : std_logic_vector (N - 1 downto 0);

-- Clk --
signal clk : std_logic := '0';
constant clk_period : time := 10 ns;

begin

-- Instantiate the Unit Under Test (UUT) --
uut: FFT_N port map (
        clk => clk,
        rst => rst,
        t => t,
        q => q,
        ena => ena
    );

-- Clock process --
clk_process :process
begin
    clk <= '0';     wait for clk_period/2;
    clk <= '1';     wait for clk_period/2;
end process;

-- Reset process --
resetProc :process
begin      
    rst <= '1'; ena <= '0';    wait for 50 ns;
    rst <= '0'; ena <= '1';     wait;
end process;

-- Stimulus process --
stimProc :process
begin      
    t <= (others => '0');
    wait until falling_edge (rst); 
    t <= (others => '0');     wait for 500 ns;
    t <= (others => '1');     wait for 500 ns;
end process;


end Behavioral;
