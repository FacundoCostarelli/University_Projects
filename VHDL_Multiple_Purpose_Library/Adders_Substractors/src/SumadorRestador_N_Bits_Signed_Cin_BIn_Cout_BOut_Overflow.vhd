----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2025 21:54:53
-- Design Name: 
-- Module Name: SumadorRestador_N_Bits_Signed_Cin_BIn_Cout_BOut_Overflow - Behavioral
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

-- CA2 format
entity SumadorRestador_N_Bits_Signed_Cin_BIn_Cout_BOut_Overflow is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         cin  : in std_logic;  -- cin >>> carry in/borrow in
         cout : out std_logic; -- cout >>> carry out/borrow out
         sel : in std_logic;
         ov  : out std_logic;
         res : out std_logic_vector(N-1 downto 0));
end SumadorRestador_N_Bits_Signed_Cin_BIn_Cout_BOut_Overflow;

architecture Behavioral of SumadorRestador_N_Bits_Signed_Cin_BIn_Cout_BOut_Overflow is
    signal a_suma_S  : signed(N+1 downto 0);
    signal b_suma_S  : signed(N+1 downto 0);
    signal a_resta_S : signed(N+1 downto 0);
    signal b_resta_S : signed(N+1 downto 0);
    signal res_S : std_logic_vector(N+1 downto 0);
    signal suma_S : std_logic_vector(N-1 downto 0);
    signal resta_S : std_logic_vector(N-1 downto 0);
    
    signal rOv_s : std_logic;
    signal sOv_s : std_logic;

begin
    -- SUMA
    --a_s <= unsigned('0' & a & cin);
    --b_s <= unsigned('0' & b & cin);
    
    -- RESTA
    -- a_s <= unsigned('0' & a & '0');
    -- b_s <= unsigned('0' & b & bin); 

    --res_s <= std_logic_vector(a_s + b_s); -- >> va el casteo obligatorio, osea std_logic_vector 
    
    --res <= res_s(N downto 1);
    --cout <= res_s(N + 1);

    --SUMA
    a_suma_S <= signed('0' & a & cin);
    b_suma_S <= signed('0' & b & cin);
    
    --RESTA
    a_resta_S <= signed('0' & a & '0');
    b_resta_S <= signed('0' & b & cin); 
    
    suma_S  <=  std_logic_vector(a_suma_S + b_suma_S);
    resta_S <=  std_logic_vector(a_resta_S - b_resta_S);

    res_S <= suma_S when(sel = '1') else resta_S;

    rOv_S <= (not(suma_S(N-1)) and a_resta_S(N-1) and b_resta_S(N-1)) or 
             (suma_S(N-1) and not(a_resta_S(N-1)) and not(b_resta_S(N-1)));
    
    sOv_S <= (not(resta_S(N-1)) and not(a_suma_S(N-1)) and b_suma_S(N-1)) or
              (resta_S(N-1) and a_suma_S(N-1) and not(b_suma_S(N-1)));

    ov <= sOv_S when(sel = '1') else rOv_S;
     
    res <= res_s(N downto 1); 
    cout <= res_s(N + 1);
            
            
end Behavioral;


