----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Shift Register System with I/O
-- Module Name: myShiftReg - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Registro de desplazamiento básico con carga paralela.
-- ENG: Basic shift register with parallel load capability.
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity myShiftReg is
    Generic (N: integer := 4); -- ESP: Tamaño del registro / ENG: Register size
    Port ( clk : in std_logic;
           rst : in std_logic; 
           ena : in std_logic;
           si : in std_logic;  -- ESP: Entrada serie / ENG: Serial input
           so : out std_logic; -- ESP: Salida serie / ENG: Serial output
           po : out std_logic_vector (N - 1 downto 0); -- ESP: Salida paralelo
           pi : in std_logic_vector (N - 1 downto 0); -- ESP: Entrada paralelo
           pl : in std_logic); -- ESP: Selector Carga/Desplazamiento
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
                    -- ESP: Desplazamiento hacia la izquierda / ENG: Shift to the left
                    Out_S <= Out_S (N - 2 downto 0) & si;
                else
                    Out_S <= pi; -- Parallel load output
                end if;
            end if;
        end if;
    end if;
end process;
    
    so <= Out_S(N-1); 
    po <= Out_S;
    
end Behavioral;