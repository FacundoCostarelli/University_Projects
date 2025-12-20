----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.07.2025 22:02:04
-- Design Name: 
-- Module Name: companding_A - Behavioral
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

-- "companding refiere a compresor", es decir, lograr que el dato de entrada se pueda representar con menor cantidad de bits
entity companding_A is
    Port ( clk : in std_logic; -- Reloj principal del sistema
           rst : in std_logic; -- Reset Sinc
           sck : in std_logic; -- Reloj de datos (1MHz)
       entrada : in STD_LOGIC_VECTOR (12 downto 0); -- Entrada de 13 bits (descomprimida)
        salida : out STD_LOGIC_VECTOR (7 downto 0)); -- Salida de 8 bits (comprimida)
end companding_A;

architecture Behavioral of companding_A is
    signal sck_rise_edge  : std_logic;
    signal sck_fall_edge : std_logic;
    --signal q_S: std_logic_vector (N-1 downto 0);
    signal RegIn_d, RegIn_q   : std_logic_vector(13-1 downto 0);
    signal RegOut_d, RegOut_q : std_logic_vector(8-1 downto 0);
    
      
    signal s_bit       : std_logic;
  --  signal chord_val   : std_logic_vector(7 downto 0);
  --  signal abcd_bits   : std_logic_vector(3 downto 0);
    
    component myFFD_RisingEdge_N_Bits
    Generic (N : integer := 8);
    Port ( clk : in std_logic;
             d : in std_logic_vector(N-1 downto 0);
             q : out std_logic_vector(N-1 downto 0)
    );
    end component;
    
    component myEdgeDetector
        Port (
            clk         : in std_logic;
            rst         : in std_logic;
            d           : in std_logic;
            ascendente  : out std_logic;
            descendente : out std_logic
        );
    end component;

begin

-- Flip-Flop para current
    In_Data_Register: myFFD_RisingEdge_N_Bits
      generic map (N => 13)
      port map (
        clk => clk,
        d   => RegIn_d,
        q   => RegIn_q
      );
    
    -- Flip-Flop para previous
    Out_Data_Register: myFFD_RisingEdge_N_Bits
      generic map (N => 8)
      port map (
        clk => clk,
        d   => RegOut_d,
        q   => RegOut_q
      );

    U1: myEdgeDetector
        Port map (
        clk         => clk,
        rst         => rst,
        d           => sck,
        ascendente  => sck_rise_edge,
        descendente => sck_fall_edge
    );


process(clk)
begin
    if rising_edge(clk) then
        if rst = '1' then
            RegIn_d <= (others => '0');
        elsif sck_rise_edge = '1' then
            RegIn_d <= entrada;
        end if;
    end if;
end process;

process(clk)
begin
    if rising_edge(clk) then
        if rst = '1' then
            salida <= (others => '0');
        elsif sck_fall_edge = '1' then
            salida <= RegOut_q;
        end if;
    end if;
end process;

    s_bit     <= RegIn_q(12);
    RegOut_d <= 
        s_bit & "000" & RegIn_q(3 downto  0 ) when RegIn_q(4)   = '0' else
        s_bit & "001" & RegIn_q(4 downto  1 ) when RegIn_q(5)   = '1' else
        s_bit & "010" & RegIn_q(5 downto  2 ) when RegIn_q(6)   = '1' else
        s_bit & "011" & RegIn_q(6 downto  3 ) when RegIn_q(7)   = '1' else
        s_bit & "100" & RegIn_q(7 downto  4 ) when RegIn_q(8)   = '1' else
        s_bit & "101" & RegIn_q(8 downto  5 ) when RegIn_q(9)   = '1' else
        s_bit & "110" & RegIn_q(9 downto  6 ) when RegIn_q(10)  = '1' else
        s_bit & "111" & RegIn_q(10 downto 7 ) when RegIn_q(11)  = '1' else
       (others => '0'); -- error o indefinido

end Behavioral;
