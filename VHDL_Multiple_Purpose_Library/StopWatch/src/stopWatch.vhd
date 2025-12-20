----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.07.2025 15:08:46
-- Design Name: 
-- Module Name: stopWatch - Behavioral
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


entity stopWatch is
    Generic (N: integer := 4);
    Port (
        clk : in std_logic;
        rst : in std_logic;
        start : in std_logic;
        stop : in std_logic;
        salida: out std_logic_vector (N - 1 downto 0)
    );
end stopWatch;

architecture Behavioral of stopWatch is

    type state_type is (stA, stB, stC);
    signal state, next_state : state_type;
    signal salida_S: std_logic_vector (N-1 downto 0);
    signal    cnt_dir: std_logic :=  '0';
    signal    cnt_ena: std_logic :=  '0'; 
    signal    cnt_rst: std_logic :=  '0';

    component myCntBiDir is
        Generic ( N: integer := 4);
        Port ( 
                clk: in std_logic;
                rst: in std_logic;
                ena: in std_logic;
                dir: in std_logic;
                q : out std_logic_vector (N-1 downto 0)
        );
    end component;

begin

U1: myCntBiDir
    Generic map(N => N)
    Port map(
           clk    => clk,
           rst    => cnt_rst,
           ena    => cnt_ena,
           dir    => cnt_dir,
           q      => salida_S
    );



----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state      <= stA;
        else
            state    <= next_state;
        end if;
    end if;
end process;

salida   <= salida_S;

----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
-----------No pregunto con sentencias "if" acá, solo escribo en ciertos pines de entradas y salidas de ser necesario--------
logicaSalida: process (state, start, stop)
begin
    case (state) is
        when stA =>
                cnt_rst <= '1';
                cnt_ena  <= '0';                
        when stB =>
                cnt_rst <= '0';
                cnt_ena    <= '1';         
        when stC =>           
              cnt_rst <= '0';
              cnt_ena <= '0';
        when others =>
                cnt_rst <= '0';
                cnt_ena <= '0';
        end case;
end process;


----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, start, stop)
begin
    next_state <= state;
    case (state) is
        when stA =>
            if (start = '1' and stop = '0') then
                next_state <= stB;
            else
                next_state <= stA;
            end if;
        when stB =>
            if (stop = '1') then
                next_state <= stC;
            else
                next_state <= stB;
            end if;
        when stC =>
            if (start = '1' and stop = '0') then
                next_state <= stB;
            elsif start = '0' and stop = '1' then
                next_state <= stA;
            else
                next_state <= stC;
            end if;
        when others =>
            next_state <= stA;
        end case;
end process;


end Behavioral;
