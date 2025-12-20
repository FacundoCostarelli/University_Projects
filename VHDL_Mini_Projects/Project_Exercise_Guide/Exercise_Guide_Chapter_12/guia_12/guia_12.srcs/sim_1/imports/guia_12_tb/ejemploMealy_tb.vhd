library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ejemploMealy_tb is

end ejemploMealy_tb;

architecture Behavioral of ejemploMealy_tb is
component ejemploMealy is
    Port ( clk : in std_logic;
           rst : in std_logic;
           entrada : in std_logic;
           salida : out std_logic;
           salidaR : out std_logic
           );    
end component;

    signal rst : std_logic;
    signal entrada : std_logic;
    signal salida : std_logic;
    signal salidaR : std_logic;

    -- Clk --
    signal clk : std_logic := '0';
    constant clk_period : time := 10 ns;
    
begin

uut: ejemploMealy 
    Port map( clk => clk,
              rst => rst,
              entrada => entrada,
              salida => salida,
              salidaR => salidaR);    

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
    entrada <= '0';
    wait until falling_edge (rst); 
    wait until rising_edge (clk);
    wait until falling_edge (clk);
    entrada <= '1';
    wait until rising_edge (clk);
    entrada <= '0';
    wait;    
end process;


end Behavioral;
