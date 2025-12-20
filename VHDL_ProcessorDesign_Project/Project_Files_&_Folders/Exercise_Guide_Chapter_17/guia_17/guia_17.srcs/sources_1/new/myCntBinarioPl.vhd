----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Binary Counter With Paralell Load input
-- Module Name: myCntBinarioPl - Behavioral
-- Project Name: Microprocessor Unit Control Design - Digital Techniques I
-- Description: 
-- ESP: Contador binario de 10 bits con carga paralela sincrónica. 
-- Implementa el registro de dirección para la memoria de programa.
-- ENG: 10-bit binary counter with synchronous parallel load. 
-- Implements the address register for the program memory.
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity myCntBinarioPl is
    Generic (N: integer := 16);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic; -- Enable that increments programm counter as PC+1
            dl : in std_logic; -- Paralell Data Load flag
             d : in std_logic_vector (9 downto 0); -- Input data
             q : out std_logic_vector (9 downto 0)); -- Output data
end myCntBinarioPl;


architecture Behavioral of myCntBinarioPl is

-- ESP: Señal interna de tipo unsigned para operaciones aritméticas
-- ENG: Internal unsigned signal for arithmetic operations
signal cnt_S : unsigned (9 downto 0);

begin

-- ESP: Proceso secuencial que gestiona el flujo del contador
-- ENG: Sequential process managing the counter flow
process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            -- ESP: Reset pone el contador en la dirección inicial (0)
            -- ENG: Reset sets the counter to the starting address (0)
            cnt_S <= (others => '0');
            
        elsif (dl = '1') then
            -- ESP: Carga paralela con prioridad sobre el incremento (Salto/Jump)
            -- ENG: Parallel load with priority over increment (Jump)
            cnt_S <= unsigned(d);
            
        elsif (ena = '1') then
            -- ESP: Incremento secuencial de la dirección
            -- ENG: Sequential address increment
            cnt_S <= cnt_S + 1;
        end if;
    end if;
end process;

-- ESP: Conversión de la señal interna al bus de salida
-- ENG: Conversion from internal signal to output bus
q <= std_logic_vector (cnt_s);
end Behavioral;