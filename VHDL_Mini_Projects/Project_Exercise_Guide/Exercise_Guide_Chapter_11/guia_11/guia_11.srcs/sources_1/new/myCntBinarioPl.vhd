----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.07.2025 20:37:37
-- Design Name: 
-- Module Name: myCntBinarioPl - Behavioral
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

entity myCntBinarioPl is
    Generic (N: integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
            dl : in std_logic;
             d : in std_logic_vector (N - 1 downto 0);
             q : out std_logic_vector (N - 1 downto 0));
end myCntBinarioPl;

architecture Behavioral of myCntBinarioPl is
    signal q_S : unsigned (N - 1 downto 0);

begin

process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            q_S <= (others => '0');
        elsif (ena = '1') then
            if (dl = '1') then
                q_S <= unsigned(d);  -- carga paralela
            else
                q_S <= q_S + 1;  -- contar
            
            end if;
        end if;
    end if;
end process;

q <= std_logic_vector (q_S);

end Behavioral;
