----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 15.07.2025 21:33:44
-- Design Name: 
-- Module Name: myCntJohnson - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity myCntJohnson is
    Generic (N: integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
           q : out std_logic_vector (N - 1 downto 0));
end myCntJohnson;

architecture Behavioral of myCntJohnson is
    signal q_S :std_logic_vector (N - 1 downto 0) := (others => '0');

begin

process (clk)
begin    
    if (rising_edge (clk)) then
       if (rst = '1') then
            q_S <= (others => '0');
       else
            if (ena = '1') then
                q_S <= q_S (N - 2 downto 0) & not (q_S(N - 1));
            end if;    
       end if;
    end if;
end process;

q <= q_S;

end Behavioral;
