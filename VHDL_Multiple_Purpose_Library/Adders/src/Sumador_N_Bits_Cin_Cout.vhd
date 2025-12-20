----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03.06.2025 17:03:51
-- Design Name: 
-- Module Name: Sumador_N_Bits_Cin_Cout - Behavioral
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

entity Sumador_N_Bits_Cin_Cout is
    generic (
        N : integer := 4;
        ES_SIGNED : boolean := true
    );
    port (
        a    : in  std_logic_vector(N-1 downto 0);
        b    : in  std_logic_vector(N-1 downto 0);
        cin  : in  std_logic;
        cout : out std_logic;
        res  : out std_logic_vector(N-1 downto 0)
    );
end entity;

architecture Behavioral of Sumador_N_Bits_Cin_Cout is
    signal a_S, b_S : std_logic_vector(N+1 downto 0);
    signal res_S    : std_logic_vector(N+1 downto 0);
begin

    a_S <= '0' & a & cin;
    b_S <= '0' & b & cin;

    unsigned_sum: if not ES_SIGNED generate
        signal a_U, b_U : unsigned(N+1 downto 0);
    begin
        a_U <= unsigned(a_S);
        b_U <= unsigned(b_S);
        res_S <= std_logic_vector(a_U + b_U);
    end generate;

    signed_sum: if ES_SIGNED generate
        signal a_SI, b_SI : signed(N+1 downto 0);
    begin
        a_SI <= signed(a_S);
        b_SI <= signed(b_S);
        res_S <= std_logic_vector(a_SI + b_SI);
    end generate;

    res  <= res_S(N downto 1);
    cout <= res_S(N+1);

end architecture;

