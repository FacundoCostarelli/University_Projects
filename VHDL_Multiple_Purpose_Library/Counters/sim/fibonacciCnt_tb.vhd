----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05.12.2024 08:36:57
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
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fibonacciCnt_tb is
    Generic (N : integer := 5);
end fibonacciCnt_tb;

architecture Behavioral of fibonacciCnt_tb is
    component fibonacciCnt is
        Generic (N : integer := 5);
        Port ( clk       : in std_logic;
               rst       : in std_logic;
               ena       : in std_logic;
               cnt: out std_logic_vector (N - 1 downto 0));
    end component;
    
    signal rst       : std_logic;
    signal ena       : std_logic;
    signal cnt : std_logic_vector (N - 1 downto 0);
    
        -- Clk --
        signal clk : std_logic := '0';
        constant clk_period : time := 10 ns;
    begin
    
    -- Instantiate the Unit Under Test (UUT) --
    uut: fibonacciCnt
        Generic map (N => N)
        Port map ( clk => clk,
                   rst => rst,
                   ena => ena,
                   cnt  => cnt);
    
    -- Clock process --
    clk_process :process
    begin
        clk <= '0';     wait for clk_period/2;
        clk <= '1';     wait for clk_period/2;
    end process;
    
    -- Reset process --
    resetProc :process
    begin      
        rst <= '1';     wait for 50 ns;
        rst <= '0';     wait;
    end process;
    
    -- Stimulus process --
    stimProc :process
    begin      
        ena <= '0';
        wait until falling_edge (rst); 
        ena <= '1';
        wait;    
    end process;
    
    
    end Behavioral;