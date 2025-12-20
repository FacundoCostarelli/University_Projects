----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.09.2025 10:36:14
-- Design Name: 
-- Module Name: uartRx_tb - Behavioral
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
use ieee.math_real.all;



entity uartRx_tb is
end uartRx_tb;

architecture Behavioral of uartRx_tb is

component uartRx is
    Generic (baudRate : integer := 9600;
               sysClk : integer := 100000000;
             dataSize : integer := 8);
    Port (        clk : in std_logic;
                  rst : in std_logic;
               dataRd : out std_logic;
               dataRx : out std_logic_vector (dataSize - 1 downto 0);
                   rx : in std_logic);
end component;

constant baudRate: integer := 9600;
constant sysClk : integer := 100000000;
constant dataSize : integer := 8;
signal    clk : std_logic;
signal    rst : std_logic;
signal dataRd : std_logic;
signal dataRx : std_logic_vector (dataSize - 1 downto 0);
signal     rx : std_logic;

constant clk_period : time := 10 ns; -- 1/sysClk

begin

uut: uartRx
    generic map ( 
                baudRate => baudRate,
                  sysClk => sysClk,  
                dataSize => dataSize
                ) 
    port map (       clk => clk,
                     rst => rst,
                  dataRd => dataRd,
                  dataRx => dataRx,
                      rx => rx
             );            

-- Clock process definitions
clk_process :process
begin
    clk <= '1';
    wait for clk_period/2;
    clk <= '0';
    wait for clk_period/2;
end process;

-- Reset Process
rst_process: process
begin
    rst<='1';
    wait for clk_period*5;
    rst<='0';
    wait;
end process;

 -- Stimulus process
stim_proc: process
begin		
   
    rx <= '1';         -- idle
    wait for 104 us;  -- para calcular el tiempo de un bit: (1/9600) = 104,1666667 us aprox = 104 us

    rx <= '0';         -- start
    wait for 104 us;

    rx <= '1';         -- bit(0) de la H = "01001000", envío los bits de derecha a izquierda
    wait for 104 us;    
    rx <= '0';         -- bit(1)
    wait for 104 us;
    rx <= '0';         -- bit(2)
    wait for 104 us;
    rx <= '0';         -- bit(3)
    wait for 104 us;    
    rx <= '0';         -- bit(4)
    wait for 104 us;        
    rx <= '0';         -- bit(5)
    wait for 104 us;
    rx <= '0';         -- bit(6)
    wait for 104 us;
    rx <= '1';         -- bit(7)
    wait for 104 us; 

    rx <= '1';         -- stop
    wait for 104 us;   

    rx <= '1';         -- idle
    wait for 500 us; 

--Otro dato 
    rx <= '0';         -- start
    wait for 104 us;

    rx <= '1';         -- bit(0) de la o = "01101111"  
    wait for 104 us;    
    rx <= '1';         -- bit(1)
    wait for 104 us;
    rx <= '1';         -- bit(2)
    wait for 104 us;
    rx <= '1';         -- bit(3)
    wait for 104 us;    
    rx <= '0';         -- bit(4)
    wait for 104 us;        
    rx <= '1';         -- bit(5)
    wait for 104 us;
    rx <= '1';         -- bit(6)
    wait for 104 us;
    rx <= '0';         -- bit(7)
    wait for 104 us;   

    rx <= '1';         -- stop
    wait for 104 us;   

    rx <= '1';         -- idle
    wait for 500 us;
    
-- Otro dato


    rx <= '0';         -- falso start
    wait for 30 us;
    
    rx <= '1';         -- idle
    wait for 70 ns;
  
    rx <= '0';         -- start
    wait for 104 us;

    rx <= '0';         -- bit(0) de la l = "01101100" 
    wait for 104 us;    
    rx <= '0';         -- bit(1)
    wait for 104 us;
    rx <= '1';         -- bit(2)
    wait for 104 us;
    rx <= '1';         -- bit(3)
    wait for 104 us;      
    rx <= '0';         -- bit(4)
    wait for 104 us;        
    rx <= '1';         -- bit(5)
    wait for 104 us;
    rx <= '1';         -- bit(6)
    wait for 104 us;
    rx <= '0';         -- bit(7)
    wait for 104 us;    

    rx <= '1';         -- stop
    wait for 104 us; 

    rx <= '1';         -- idle
    wait for 1000 us;



    wait;

end process;
end Behavioral;
