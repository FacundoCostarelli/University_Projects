----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03.06.2025 17:05:37
-- Design Name: 
-- Module Name: Restador_N_Bits_Bin_Bout - Behavioral
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

entity Restador_N_Bits_Bin_Bout is
    generic (
        N : integer := 4;
        ES_SIGNED : boolean := true
    );
    port (
        a    : in  std_logic_vector(N-1 downto 0);
        b    : in  std_logic_vector(N-1 downto 0);
        bin  : in  std_logic;
        bout : out std_logic;
        res  : out std_logic_vector(N-1 downto 0)
    );
end entity;

architecture Behavioral of Restador_N_Bits_Bin_Bout is
    signal a_S, b_S : std_logic_vector(N+1 downto 0);
    signal res_S    : std_logic_vector(N+1 downto 0);
begin

    -- Según presentación ppt original --> Extensión de los operandos con bin como LSB
   a_S <= '0' & a & '0';
   b_S <= '0' & b & bin; -- Siempre vale bin = -1
   
   -- Solucion IA (no anda)
   --b_S <= '0' & a & '0';
   --a_S <= '0' & b & bin;

    unsigned_sub: if not ES_SIGNED generate
        signal a_U, b_U : unsigned(N+1 downto 0);
    begin
        a_U <= unsigned(a_S);
        b_U <= unsigned(b_S);
        res_S <= std_logic_vector(a_U - b_U);
    end generate;

    signed_sub: if ES_SIGNED generate
        signal a_SI, b_SI : signed(N+1 downto 0);
    begin
        a_SI <= signed(a_S);
        b_SI <= signed(b_S);
        res_S <= std_logic_vector(a_SI - b_SI);
    end generate;

    res  <= res_S(N downto 1);
    bout <= res_S(N+1);

end architecture;