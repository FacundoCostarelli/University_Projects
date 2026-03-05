----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.11.2025 20:41:28
-- Design Name: 
-- Module Name: rle - Behavioral
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



--library IEEE;
--use IEEE.STD_LOGIC_1164.ALL;
--use IEEE.NUMERIC_STD.ALL;

--entity rle is
--    Port ( clk: in std_logic;
--           rst: in std_logic;
--           sck: in std_logic;
--       entrada: in std_logic_vector(7 downto 0);
--    salidaCaracter: out std_logic_vector(7 downto 0);
--    salidaContador: out std_logic_vector(7 downto 0));
--end rle ;

--architecture Behavioral of rle is
--    signal q_ed: std_logic_vector(2-1 downto 0);
--    signal ascendente: std_logic;
--    signal flag_cambio_char: std_logic;
--    signal reg_char,salidaCaracter_q: std_logic_vector(8-1 downto 0);
--    signal q_counter: unsigned(8-1 downto 0);
--begin

--edge_detector: process(clk)
--    begin
--        if rising_edge(clk) then
--            if rst='1' then
--                q_ed<="00";
--            else
--                q_ed<=q_ed(0)&sck;
--            end if;
--        end if;
--    end process;
    
--    ascendente <= '1' when q_ed="01" else 
--                  '0'; 

--    control_char: process(clk)
--    begin
--        if rising_edge(clk) then
--            if rst='1' then
--                reg_char<=entrada;
--                flag_cambio_char<='0';
--                salidaCaracter_q<=(others=>'0');
--            else
--                if(ascendente='1') then
--                    if (reg_char /= entrada) then
--                        reg_char<=entrada;
--                        flag_cambio_char<='1';
--                        salidaCaracter_q<=reg_char;
--                    else
--                        reg_char<=reg_char;
--                        flag_cambio_char<='0';                    
--                        salidaCaracter_q<=(others=>'0');
--                    end if;
--                else
--                    reg_char<=reg_char;
--                    flag_cambio_char<='0';                                    
--                end if;
--            end if;
--        end if;
--    end process;
    
--    salidaCaracter<=salidaCaracter_q;
    
--    counter_proc: process(clk)
--    begin
--        if rising_edge(clk) then
--            if rst='1' then
--                q_counter<=to_unsigned(0,8);
--                salidaContador<=(others=>'0');
--            else

--                if (reg_char /= entrada) then
--                    q_counter<=to_unsigned(0,8);
--                    salidaContador<=std_logic_vector(q_counter);
--                else                
--                    q_counter<=q_counter;                
--                    if(ascendente='1') then
--                        salidaContador<=(others=>'0');
--                        q_counter<=q_counter+1;
--                    else
--                        q_counter<=q_counter;
--                    end if; 
--                end if;
                    

----                if(flag_cambio_char ='1') then
----                    q_counter<=to_unsigned(0,8);
----                    salidaContador<=std_logic_vector(q_counter);
----                else
----                    q_counter<=q_counter;                
----                    if(ascendente='1') then
----                        salidaContador<=(others=>'0');
----                        q_counter<=q_counter+1;
----                    else
----                        q_counter<=q_counter;
----                    end if; 
----                end if;    
--            end if;
--        end if;
--    end process;


--end Behavioral;


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity rle is
    Port ( clk: in std_logic;
    rst: in std_logic;
    sck: in std_logic;
    entrada: in std_logic_vector(7 downto 0);
    salidaCaracter: out std_logic_vector(7 downto 0);
    salidaContador: out std_logic_vector(7 downto 0));
end rle ;

architecture Behavioral of rle is

signal q0: std_logic_vector(7 downto 0); 
signal q1: std_logic_vector(7 downto 0); 

--signal salidaCaracter_S: std_logic_vector(7 downto 0);
--signal salidaContador_S: std_logic_vector(7 downto 0);
--signal entrada_S: std_logic_vector(7 downto 0);

signal flag_change: std_logic := '0';
signal cnt_S: unsigned(7 downto 0); 

signal salidaTotal: std_logic_vector(15 downto 0); 

component SckRisingAndFallingEdgeDetector
    Port (  clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;
            ena : in  std_logic;
              --q : out std_logic;
     risingEdge : out std_logic;
    fallingEdge : out std_logic);
end component;

signal sck_rising_edge_flag:  std_logic := '0';
signal sck_falling_edge_flag: std_logic := '0';

begin

SckEdgeDetector: SckRisingAndFallingEdgeDetector 
    Port map(  
        clk => clk,
        rst => rst,
        d   => sck,      
        ena => '1', 
       --q : out std_logic;
     risingEdge =>  sck_rising_edge_flag,
    fallingEdge => sck_falling_edge_flag
    );



--entrada_S <= entrada;
--salidaCaracter <= salidaCaracter_S;
--salidaContador <= salidaContador_S;

CharRegisterDetector: process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            q0 <= (others => '0');
            q1 <= (others => '0');
            
            salidaTotal(7 downto 0) <= (others => '0');
            --salidaCaracter <= (others => '0');
            
            --salidaCaracter_S <= (others => '0');
        else
            if(sck_rising_edge_flag = '1') then
                --q0 <= entrada_S;
                q0 <= entrada;
                q1 <= q0;
                if(q0 /= q1) then
                    flag_change <= '1';
                    --salidaCaracter_S <= q1;
                    
                    salidaTotal(7 downto 0) <= q1;
                    --salidaCaracter <= q1;               
                else
                    flag_change <= '0';
                   -- salidaCaracter_S <= (others => '0');
                   
                   
                   salidaTotal(7 downto 0) <= (others => '0');
                   --salidaCaracter <= (others => '0');
                end if;
            else
                flag_change <= '0';
                q0 <= q0;
                q1 <= q1;
               --salidaCaracter_S <= salidaCaracter_S;
              -- salidaCaracter <= salidaCaracter;
              --salidaTotal(7 downto 0) <= salidaTotal(7 downto 0);   
            end if;
        end if;
    end if;
end process;

CharCounterDetector: process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            cnt_S <= (others => '0');
            --salidaContador_S <= (others => '0');
            
            salidaTotal(15 downto 8) <= (others => '0');
            --salidaContador <= (others => '0');
        else          
            if(flag_change = '1') then
                --salidaContador_S <= std_logic_vector(cnt_S);                                     
                salidaTotal(15 downto 8) <= std_logic_vector(cnt_S);                   
                --salidaContador <= std_logic_vector(cnt_S);            
                cnt_S <= (others => '0');                                          
            else
                cnt_S <= cnt_S;
                if(sck_rising_edge_flag = '1') then
                    salidaTotal(15 downto 8) <= (others => '0');
                    --salidaContador_S <= (others => '0');
                    --salidaContador <= (others => '0');
                    cnt_S <= cnt_S + 1;
                else
                    cnt_S <= cnt_S;
                end if;
            end if;               
        end if;
    end if;
end process;        

salidaContador <= salidaTotal(15 downto 8);
salidaCaracter <= salidaTotal(7 downto 0);

end Behavioral;
