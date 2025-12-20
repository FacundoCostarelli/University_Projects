----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 14:54:24
-- Design Name: 
-- Module Name: myEdgeCnt_V2_tb - Behavioral
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


entity myEdgeCnt_V2_tb is
    Generic (N : integer := 8);
end myEdgeCnt_V2_tb;

architecture Behavioral of myEdgeCnt_V2_tb is

    signal rst : std_logic;
    signal d : std_logic;
    signal q : std_logic_vector (N-1 downto 0);
    
    -- Clock signal --
    signal clk : std_logic := '0';
    constant clk_period : time := 10 ns;

component myEdgeCnt_V2 is
        Generic (N : integer := 8);
        Port ( clk : in std_logic;
               rst : in std_logic;
               d : in std_logic;
               q : out std_logic_vector (N-1 downto 0));
    end component;

    
begin

    -- Instantiate the Unit Under Test (UUT) --
    uut: myEdgeCnt_V2
        Port map ( clk => clk,
                   rst => rst,
                   d => d,
                   q => q);

    -- Clock process --
    clk_process : process
    begin
        clk <= '0';
        wait for clk_period/2;
        clk <= '1';
        wait for clk_period/2;
    end process;

    -- Reset process --
    resetProc : process
    begin      
        rst <= '1';
        wait for 50 ns;
        rst <= '0';
        wait;
    end process;

    -- Stimulus process --
    stimProc : process
    begin      
        d <= '0';
        wait until falling_edge(rst);
        d <= '0';     wait for 100 ns;
        d <= '1';     wait for 100 ns;
        d <= '0';     wait for 100 ns;
        d <= '1';     wait for 100 ns;
        d <= '0';     wait for 100 ns;
        d <= '1';     wait for 100 ns;
        wait;
    end process;

end Behavioral;
