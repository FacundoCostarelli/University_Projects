----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.07.2025 19:30:56
-- Design Name: 
-- Module Name: lfsr_F - Behavioral
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
use ieee.std_logic_misc.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lfsr_F is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
         inits : in std_logic_vector(N - 1 downto 0);
          taps : in std_logic_vector(N - 1 downto 0);
        salida : out std_logic_vector(N - 1 downto 0));
end lfsr_F;

architecture Behavioral of lfsr_F is
    signal q_S:std_logic_vector (N - 1 downto 0);
begin


process (clk)   
begin
    if (rising_edge (clk)) then
        if (rst = '1') then -- rst tiene prioridad frente a ena siempre
            q_S <= inits;
        else
            -- Desplazamiento: nuevo bit entra por MSB
            q_S <= q_S (N - 2 downto 0) & xor_reduce((q_S and taps)); --> Salida serie       
        end if;
    end if;
end process;
    
    salida <= q_S;
end Behavioral;
