----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.08.2024 20:36:03
-- Design Name: 
-- Module Name: blockRamTest0_tb - Behavioral
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


entity blockRamTest0_tb is
--  Port ( );
end blockRamTest0_tb;

architecture Behavioral of blockRamTest0_tb is

    -- Declaración de señales en el testbench
    signal wea   : std_logic_vector(0 downto 0);
    signal addra : std_logic_vector(9 downto 0); -- depende del tamaño de tu BRAM
    signal dina  : std_logic_vector(15 downto 0); -- depende del ancho de datos
    signal douta : std_logic_vector(15 downto 0);

    -- Clk --
    signal clka : std_logic := '0';
    constant clk_period : time := 10 ns;


    component blockRamTest0
    port (
    clka : in std_logic;
    wea : in std_logic_vector(0 DOWNTO 0); --> IMPORTANTISIMO , vector 0 downto 0, se debe respetar para usar std_logic_vector
    addra : in std_logic_vector(9 DOWNTO 0);
    dina : in std_logic_vector(15 DOWNTO 0);
    douta : out std_logic_vector(15 DOWNTO 0)
    );
    end component;


begin

-- Instantiate the Unit Under Test (UUT) --
uut: blockRamTest0 port map (
        clka => clka,
        wea => wea,
        addra => addra,
        dina => dina,
        douta => douta
    );

-- Clock process --
clk_process :process
begin
    clka <= '0';     wait for clk_period/2;
    clka <= '1';     wait for clk_period/2;
end process;

StimProcess : process
begin
    -- Lecturas iniciales (antes de escribir)
    wea <= "0";
    dina <= (others => '0');

    addra <= "00" & X"00";
    wait until rising_edge(clka);
    
    addra <= "00" & X"01";
    wait until rising_edge(clka);
    
    addra <= "00" & X"02";
    wait until rising_edge(clka);

    addra <= "00" & X"03";
    wait until rising_edge(clka);

    addra <= "00" & X"04";
    wait until rising_edge(clka);

    -- Escritura en 0x004
    wea   <= "1";
    addra <= "00" & X"04";
    dina  <= X"5555";
    wait until rising_edge(clka);

    -- Desactiva escritura y lee 0x005
    wea   <= "0";
    addra <= "00" & X"05";
    dina  <= (others => '0');
    wait until rising_edge(clka);

    -- Escritura en 0x05
    wea   <= "1";
    addra <= "00" & X"05";
    dina  <= X"5555";
    wait until rising_edge(clka);

    -- Lectura en 0x04
    wea   <= "0";
    addra <= "00" & X"04";
    dina  <= (others => '0');
    wait until rising_edge(clka);

    -- Listo, detenemos el proceso
    wait;
end process;


end Behavioral;
