----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.07.2025 23:03:49
-- Design Name: 
-- Module Name: decompanding_A - Behavioral
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


entity decompanding_A is
    Port ( clk : in std_logic; -- Reloj principal del sistema
           rst : in std_logic; -- Reset Sinc
           sck : in std_logic; -- Reloj de datos (1MHz)
        salida : out STD_LOGIC_VECTOR (12 downto 0); -- Salida de 13 bits (descomprimida)
       entrada : in STD_LOGIC_VECTOR (7 downto 0)); -- Entrada de 8 bits (comprimida)
end decompanding_A;

architecture Behavioral of decompanding_A is

    signal sck_rise_edge  : std_logic;
    signal sck_fall_edge : std_logic;
    --signal q_S: std_logic_vector (N-1 downto 0);
    signal RegIn_d, RegIn_q   : std_logic_vector(8-1 downto 0);
    signal RegOut_d, RegOut_q : std_logic_vector(13-1 downto 0);
    
      
    signal s_bit       : std_logic;
    signal chord_val   : std_logic_vector(2 downto 0);
    signal abcd_bits   : std_logic_vector(3 downto 0);
    
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
      generic map (N => 8)
      port map (
        clk => clk,
        d   => RegIn_d,
        q   => RegIn_q
      );
    
    -- Flip-Flop para previous
    Out_Data_Register: myFFD_RisingEdge_N_Bits
      generic map (N => 13)
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
  
  
-- Tabla de descompresión: mapea S + ABCD según CHORD a posiciones en 13 bits
 
    s_bit     <= RegIn_q(7);
    chord_val <= RegIn_q(6 downto 4);
    abcd_bits <= RegIn_q(3 downto 0);
    --En mi caso, el valor de "raya -" vale 0 por definicion mia
    RegOut_d <= 
        s_bit & "00000000" & abcd_bits       when chord_val = "000" else
        s_bit & "0000001"  & abcd_bits & '0'  when chord_val = "001" else
        s_bit & "000001"   & abcd_bits & "00"  when chord_val = "010" else
        s_bit & "00001"    & abcd_bits & "000"  when chord_val = "011" else
        s_bit & "0001"     & abcd_bits & "0000"  when chord_val = "100" else
        s_bit & "001"      & abcd_bits & "00000"  when chord_val = "101" else
        s_bit & "01"       & abcd_bits & "000000"  when chord_val = "110" else
        s_bit & '1'        & abcd_bits & "0000000"  when chord_val = "111" else
        (others => '0'); -- error o indefinido

end Behavioral;