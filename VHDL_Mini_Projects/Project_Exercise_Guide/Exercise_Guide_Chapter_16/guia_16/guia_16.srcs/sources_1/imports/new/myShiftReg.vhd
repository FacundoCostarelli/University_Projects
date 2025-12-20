----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 15.07.2025 18:38:33
-- Design Name: 
-- Module Name: myShiftReg - Behavioral
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

entity myShiftReg is
    Generic (N: integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic; -- rst sincronico
           ena : in std_logic;
           si : in std_logic;
           so : out std_logic;
           po : out std_logic_vector (N - 1 downto 0);-- dato q
           pi : in std_logic_vector (N - 1 downto 0); -- dato d
           pl : in std_logic);
end myShiftReg;

architecture Behavioral of myShiftReg is
signal Out_S:std_logic_vector (N - 1 downto 0);

begin
    
process (clk)   
begin
    if (rising_edge (clk)) then
        if (rst = '1') then -- rst tiene prioridad frente a ena siempre
            Out_S <= (others => '0');
        else
            if (ena = '1') then
                if (pl = '0') then
                    Out_S <= Out_S (N - 2 downto 0) & si; --> Salida serie
                else
                    Out_S <= pi; --> Salida carga paralelo
                end if;
            end if;
        end if;
    end if;
end process;
    
    so <= Out_S(N-1); 
    po <= Out_S;
    
end Behavioral;