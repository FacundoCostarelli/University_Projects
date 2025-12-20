----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor System with I/O
-- Module Name: myShiftReg_dir - Behavioral
-- Project Name: Microprocessor Unit Control Design - Digital Techniques I
-- Description: 
-- ESP: Registro de desplazamiento con carga paralela y dirección seleccionable.
-- Permite elegir si el dato sale LSB-first (típico en UART) o MSB-first. 
-- ENG: Shift register with parallel load and selectable direction.
-- Allows choosing between LSB-first (typical in UART) or MSB-first output. 
---------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity myShiftReg_dir is
  generic (N : integer := 10);                         -- ESP: Ancho del registro / ENG: Register width
  port (
    clk       : in  std_logic;
    rst       : in  std_logic;
    ena       : in  std_logic;                         -- ESP: Habilita el desplazamiento / ENG: Enable shift
    si        : in  std_logic;                         -- ESP: Bit de entrada serial / ENG: Serial input bit
    so        : out std_logic;                         -- ESP: Salida serie / ENG: Serial output
    po        : out std_logic_vector (N - 1 downto 0); -- ESP: Salida paralelo / ENG: Parallel output
    pi        : in std_logic_vector (N - 1 downto 0);  -- ESP: Carga paralela / ENG: Parallel load
    pl        : in  std_logic;                         -- ESP: '1' carga PI, '0' desplaza / ENG: '1' loads PI, '0' shifts    
    msb_first : in  std_logic);                        -- ESP: '1' MSB primero, '0' LSB primero / ENG: '1' MSB-first, '0' LSB-first
 
end entity;

architecture Behavioral of myShiftReg_dir is
  signal Out_S : std_logic_vector(N-1+1 downto 0); -- ESP: Registro con bit extra para acarreo
begin

 

  process(clk)
  begin
    if rising_edge(clk) then
      if (rst = '1') then
            Out_S <= (others => '0');    
      elsif(ena = '1') then
            if(pl = '0') then
                -- ESP: Desplazamiento según dirección / ENG: Shift according to direction
                if (msb_first = '1') then
                    -- ESP: MSB primero, shifteo a izquierda. SI viene
                    -- ENG: MSB-first, left shifting and SI comes through LSB
                    Out_S <= Out_S(N-2+1 downto 0) & si;
                else
                    -- ESP: LSB-first: corre a derecha, SI entra por MSB
                    -- ENG: MSB-first: rigth shifting, SI comes through MSB
                    Out_S <= si & Out_S(N-1+1 downto 1);
                end if;
            else
                -- ESP: Carga paralela sin desplazamiento
                -- ENG: Parallel load without shifting
                Out_S <= '0' & pi;
            end if;
      end if;
    end if;
  end process;

  -- ESP: Selección de salida según dirección / ENG: Output selection based on direction
  so <= Out_S(N-1+1) when (msb_first = '1') else Out_S(0);
  po  <= Out_S(N-1 downto 0);

end Behavioral;
