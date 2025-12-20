----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.10.2024 19:04:58
-- Design Name: 
-- Module Name: uart_tb - Behavioral
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

entity uart_tb is
end uart_tb;

architecture Behavioral of uart_tb is
    constant clk_period : time := 10 ns;  
    constant baudRate : integer := 9600;
    constant sysClk : integer := 100000000;
    constant DATA_SIZE : integer := 8;
    constant bit_period : time := 1 sec / baudRate;

    signal clk : std_logic := '0';
    signal rst : std_logic := '0';
    signal dataWr : std_logic := '0';
    signal dataTx : std_logic_vector(DATA_SIZE - 1 downto 0) := (others => '0');
    signal ready : std_logic;
    signal tx : std_logic;
    signal dataRd : std_logic;
    signal dataRx : std_logic_vector(DATA_SIZE - 1 downto 0) := (others => '0');
    signal rx : std_logic;

    component uart is
        Generic (baudRate : integer;
                 sysClk : integer;
                 dataSize : integer);
        Port (  clk : in std_logic;
                rst : in std_logic;
                dataWr : in std_logic;
                dataTx : in std_logic_vector(dataSize - 1 downto 0);
                ready : out std_logic;
                tx : out std_logic;
                dataRd : out std_logic;
                dataRx : out std_logic_vector(dataSize - 1 downto 0);
                rx : in std_logic);
    end component;

begin

    UUT: uart
        Generic map (
            baudRate => baudRate,
            sysClk => sysClk,
            dataSize => DATA_SIZE
        )
        Port map (
            clk => clk,
            rst => rst,
            dataWr => dataWr,
            dataTx => dataTx,
            ready => ready,
            tx => tx,
            dataRd => dataRd,
            dataRx => dataRx,
            rx => rx
        );

    clk_process :process
    begin
        while true loop
            clk <= '0';
            wait for clk_period / 2;
            clk <= '1';
            wait for clk_period / 2;
        end loop;
    end process;

    stimulus_process: process
    begin

        rst <= '1';
        wait for 20 ns;
        rst <= '0';
        rx <= '1';
        dataTx <= "01010101";
        dataWr <= '1';
        wait for clk_period;
        dataWr <= '0';

        wait until ready = '1';

        wait for 100 us;
        wait for clk_period;  

        -- Enviar un byte (10100101)
        rx <= '0';  -- Bit de inicio
        wait for bit_period;
        rx <= '1';  
        wait for bit_period;
        rx <= '0';  
        wait for bit_period;
        rx <= '1';  
        wait for bit_period;
        rx <= '0';  
        wait for bit_period;
        rx <= '0';  
        wait for bit_period;
        rx <= '1';  
        wait for bit_period;
        rx <= '0';  
        wait for bit_period;
        rx <= '1';  
        wait for bit_period;
        rx <= '1';  -- Bit de parada
        wait for bit_period;
        wait for 100 us;

        wait;
    end process;
end Behavioral;

