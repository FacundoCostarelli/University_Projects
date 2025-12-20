----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.07.2025 21:44:59
-- Design Name: 
-- Module Name: fibonacciCnt - Behavioral
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
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity fibonacciCnt is
    Generic (N: integer := 5);
    Port ( clk: in std_logic;
           rst: in std_logic;
           ena: in std_logic;
           cnt: out std_logic_vector (N - 1 downto 0));
end fibonacciCnt;

architecture Behavioral of fibonacciCnt is
    signal cnt_S                 : std_logic_vector (N - 1 downto 0);
    signal current_d, previous_d : std_logic_vector(N-1 downto 0);
    signal current_q, previous_q : std_logic_vector(N-1 downto 0);

    -- suma extendida (N+1 bits) para detectar overflow real
    signal sum_ext : unsigned(N downto 0);

    -- bandera para reset diferido (un ciclo después de ver 21)
    signal wrap_q, wrap_d : std_logic := '0';

    component myFFD_RisingEdge_N_Bits
        Generic (N : integer := 8);
        Port ( clk : in std_logic;
               d   : in std_logic_vector(N-1 downto 0);
               q   : out std_logic_vector(N-1 downto 0) );
    end component;
begin
    -- Flip-Flop para current
    Current_Data_Register: myFFD_RisingEdge_N_Bits
      generic map (N => N)
      port map ( clk => clk, d => current_d, q => current_q );

    -- Flip-Flop para previous
    Previous_Data_Register: myFFD_RisingEdge_N_Bits
      generic map (N => N)
      port map ( clk => clk, d => previous_d, q => previous_q );

    -- Suma extendida = current_q + previous_q (con 1 bit extra)
    sum_ext <= ('0' & unsigned(current_q)) + ('0' & unsigned(previous_q));

    -- Lógica secuencial
    process(clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                -- estado inicial: 0,1,...
                previous_d <= (others => '0');
                current_d  <= std_logic_vector(to_unsigned(1, N));
                cnt_S      <= (others => '0');
                wrap_q     <= '0';

            elsif ena = '1' then
                -- registrar la bandera
                wrap_q <= wrap_d;
                if wrap_q = '1' then
                    -- ciclo posterior al 21: ahora sí reseteo la pareja (0,1) y muestro 0
                    previous_d <= (others => '0');
                    current_d  <= std_logic_vector(to_unsigned(1, N));
                    cnt_S      <= (others => '0');
                    wrap_d     <= '0';

                else
                    -- avance normal
                    previous_d <= current_q;
                    current_d  <= std_logic_vector(sum_ext(N-1 downto 0));                                     
                    if sum_ext(N) = '1' then
                        -- overflow: mostrar 21 este ciclo y programar reset para el próximo
                        --scnt_S  <= std_logic_vector(sum_ext(N-1 downto 0)); -- 21
                        cnt_S      <= (others => '0');
                        wrap_d <= '1';
                    else
                        cnt_S  <= std_logic_vector(sum_ext(N-1 downto 0)); -- 21
                        wrap_d <= '0';
                    end if;
                end if;
            end if;            
        end if;
    end process;

    cnt <= cnt_S;
end Behavioral;

