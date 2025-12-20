----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.05.2025 22:11:28
-- Design Name: 
-- Module Name: Restador_N_Bits_Unsigned_Cin_Cout - Behavioral
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

entity Restador_N_Bits_Unsigned_bin_bout is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         bin : in std_logic; -- bin >>> borrow in
         bout : out std_logic; -- bout >> borrow out
         res : out std_logic_vector(N-1 downto 0));
end Restador_N_Bits_Unsigned_bin_bout;

architecture Behavioral of Restador_N_Bits_Unsigned_bin_bout is
    signal res_S : std_logic_vector(N+1 downto 0);
    signal a_s : unsigned(N+1 downto 0);
    signal b_s : unsigned(N+1 downto 0);
    
begin

    a_s <= unsigned('0' & a & '0');
    b_s <= unsigned('0' & b & bin); 

    res_s <= std_logic_vector(a_s - b_s);  -- >> va el casteo obligatorio, osea std_logic_vector 
    
    res <= res_s(N downto 1);
    bout <= res_s(N + 1);

end Behavioral;
