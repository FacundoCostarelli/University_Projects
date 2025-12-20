----------------------------------------------------------------------------------
-- Company: UTN BA
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 12.05.2025 21:58:05
-- Design Name: Mux_4_inputs_&_2_enables 
-- Module Name: myMux4 - Behavioral
-- Project Name: Exercise 3 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myMux4 is
    Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
           c : in STD_LOGIC_VECTOR (1 downto 0);
           y : out STD_LOGIC);
end myMux4;

architecture Behavioral of myMux4 is

begin

    with c select
        y <= a(0) when "00",
             a(1) when "01",
             a(2) when "10",
             a(3) when "11",
             a(3) when others;


-- Otra forma
-- Con A = a(0), B = a(1), C = a(2), D = a(3)
-- Con S0 = c(0), S1 = c(1)
-- process (A,B,C,D,S0,S1) is
-- begin
--  if (S0 ='0' and S1 = '0') then
--      Z <= A;
--  elsif (S0 ='1' and S1 = '0') then
--      Z <= B;
--  elsif (S0 ='0' and S1 = '1') then
--      Z <= C;
--  else
--      Z <= D;
--  end if;
--end process;

end Behavioral;
