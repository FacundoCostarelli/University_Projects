----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.05.2025 22:01:49
-- Design Name: 
-- Module Name: SumadorRestador_N_Bits_Unsigned_Cin_Cout - Behavioral
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

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Sumador_N_Bits_Unsigned_Cin_Cout is
    generic(N : integer :=4);
    port(   a : in std_logic_vector(N-1 downto 0);
            b : in std_logic_vector(N-1 downto 0);
            cin : in std_logic; -- cin >>> carry in
            cout : out std_logic; -- cout >>> carry out
            res : out std_logic_vector(N-1 downto 0));
            
end Sumador_N_Bits_Unsigned_Cin_Cout;

architecture Behavioral of Sumador_N_Bits_Unsigned_Cin_Cout is
    signal res_S : std_logic_vector(N+1 downto 0);
    signal a_s : unsigned(N+1 downto 0);
    signal b_s : unsigned(N+1 downto 0);
begin

    a_s <= unsigned('0' & a & cin);
    b_s <= unsigned('0' & b & cin);

    res_s <= std_logic_vector(a_s + b_s); -- >> va el casteo obligatorio, osea std_logic_vector 
    
    res <= res_s(N downto 1);
    cout <= res_s(N + 1);
    
end Behavioral;
