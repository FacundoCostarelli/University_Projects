----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.07.2025 21:45:21
-- Design Name: 
-- Module Name: myCnt - Behavioral
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

entity myCnt is
    Generic (M : integer := 100);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
     salidaM_2 : out std_logic;
       salidaM : out std_logic);
end myCnt;

architecture Behavioral of myCnt is

component myCntBinarioSimple is
    Generic( N : integer := 4);
      Port(clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             q : out std_logic_vector (N - 1 downto 0));
end component;

-- Enunciado
constant N : integer := integer(ceil(log2(real (M))));
constant M_2 : unsigned (N-1 downto 0) := to_unsigned(M-1, N) / 2;

-- Propop
constant M_U  : unsigned(N - 1 downto 0) := to_unsigned(M - 1, N); -- para comparación

signal cnt_S: std_logic_vector (N - 1 downto 0);

signal cnt_S_U: unsigned(N - 1 downto 0);

signal rst_cnt_BinarioSimple: std_logic;

begin

U_CNT: myCntBinarioSimple
    Generic map (N => N)
    Port map(clk => clk,
             rst => rst_cnt_BinarioSimple,
             ena => ena,
             q   => cnt_S);

 -- casteo afuera para no repetir en el process
 cnt_S_U <= unsigned(cnt_S);

    process (clk)
    begin
        if(rising_edge (clk)) then
            if rst = '1' then
                salidaM_2 <= '0';
                salidaM   <= '0';
                rst_cnt_BinarioSimple    <= '1';
            elsif ena = '1' then
                rst_cnt_BinarioSimple    <= '0';
                if(cnt_S_U = M_2) then                    
                    salidaM_2 <= '1';
                elsif(cnt_S_U = M_U) then
                    rst_cnt_BinarioSimple     <= '1';
                    salidaM    <= '1';                                   
                else
                    salidaM <= '0';
                    salidaM_2 <= '0';
                end if;
                
            end if;
        end if;    
    end process;
   
end Behavioral;



-------------CODIGO ORIGNAL - FUNCIONAL PERO CON PROBLEMAS DE SYNCRONIZACION DE CLK ENTRE CONTADORES-----
--library IEEE;
--use IEEE.STD_LOGIC_1164.ALL;
--use IEEE.NUMERIC_STD.ALL;
--use ieee.math_real.all;

--entity myCnt is
--    Generic (M : integer := 100);
--    Port ( clk : in std_logic;
--           rst : in std_logic;
--           ena : in std_logic;
--     salidaM_2 : out std_logic;
--       salidaM : out std_logic);
--end myCnt;

--architecture Behavioral of myCnt is

--component myCntBinarioSimple is
--    Generic( N : integer := 4);
--      Port(clk : in std_logic;
--           rst : in std_logic;
--           ena : in std_logic;
--             q : out std_logic_vector (N - 1 downto 0));
--end component;

---- Enunciado
--constant N : integer := integer(ceil(log2(real (M))));
--constant M_2 : unsigned (N-1 downto 0) := to_unsigned(M-1, N) / 2;

---- Propop
--constant M_U  : unsigned(N - 1 downto 0) := to_unsigned(M - 1, N); -- para comparación

--signal cnt_S_1: std_logic_vector (N - 1 downto 0);
--signal cnt_S_2: std_logic_vector (N - 1 downto 0);

--signal cnt_S_U_M2: unsigned(N - 1 downto 0);
--signal cnt_S_U_MU: unsigned(N - 1 downto 0);

--signal rst_MU: std_logic := '0';
--signal rst_M2: std_logic := '0';

--begin

--U_CNT_M2: myCntBinarioSimple
--    Generic map (N => N)
--    Port map(clk => clk,
--             rst => rst_M2,
--             ena => ena,
--             q   => cnt_S_2);

--U_CNT_MU: myCntBinarioSimple
--    Generic map (N => N)
--    Port map(clk => clk,
--             rst => rst_MU,
--             ena => ena,
--             q   => cnt_S_1);
                           
-- -- casteo afuera para no repetir en el process
-- cnt_S_U_M2 <= unsigned(cnt_S_2);
-- cnt_S_U_MU <= unsigned(cnt_S_1); 

--    process (clk)
--    begin
--        if(rising_edge (clk)) then
--            if rst = '1' then
--                salidaM_2 <= '0';
--                salidaM   <= '0';
--                rst_MU    <= '1';
--                rst_M2    <= '1';
--            elsif ena = '1' then
--                rst_MU    <= '0';
--                rst_M2    <= '0';
--                if(cnt_S_U_M2 = M_2) then
--                    rst_M2        <= '1';
--                    salidaM_2     <= '1';
--                else
--                    salidaM_2 <= '0';
--                end if;
                
--                if(cnt_S_U_MU = M_U) then
--                    rst_MU     <= '1';
--                    salidaM    <= '1';
--                else
--                    salidaM <= '0';
--                end if;
                
--            end if;
--        end if;    
--    end process;
   
--end Behavioral;
