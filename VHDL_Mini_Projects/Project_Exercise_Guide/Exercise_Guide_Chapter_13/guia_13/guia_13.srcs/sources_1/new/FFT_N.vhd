----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.07.2025 16:00:32
-- Design Name: 
-- Module Name: FFT_N - Behavioral
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

entity FFT_N is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             t : in std_logic_vector (N - 1 downto 0);
             q : out std_logic_vector (N - 1 downto 0));
end FFT_N;

architecture Behavioral of FFT_N is

    component FFT is
        Port ( clk : in std_logic;
               rst : in std_logic;
               ena : in std_logic;
                 t : in std_logic;
                 q : out std_logic);
    end component;

    signal q_S: std_logic_vector (N - 1 downto 0);
    signal t_S : std_logic_vector(N - 1 downto 0); 
    signal q_next : std_logic_vector(N-1 downto 0);
    
    
begin

     -- Conexión del primer flip-flop al t(0) externo
    t_S <= t;

    -- Conexión en cascada: t_s(i) se alimenta con q_s(i-1)
    --gen_t: for i in 1 to N - 1 generate
    --    t_S(i) <= q_S(i - 1);
    --end generate;


    --gen_FFT: for i in 0 to N-1 generate
    --  INST_FFT: FFT
    --       port map (
    --           clk => clk,
    --           rst => rst,
    --           ena => ena,
    --             t => t_S(i),
    --             q => q_S(i)
    --             );
    --end generate;           
 
    
    process (clk)
        variable q_next : std_logic_vector(N-1 downto 0);    
    begin
        if (rising_edge (clk)) then
            if (rst = '1') then
                q_S <= (others => '0');
            elsif (ena = '1') then  
                q_next := q_S;
                for i in 0 to N - 1 loop
                    if(t_S(i) = '1') then
                        q_next(i) := not q_S(i);
                    end if;
                end loop;
                    q_S <= q_next (N - 2 downto 0) & t_S(0);            
            end if;
        end if;
    end process;
    
    q <= q_S;
    
end Behavioral;

