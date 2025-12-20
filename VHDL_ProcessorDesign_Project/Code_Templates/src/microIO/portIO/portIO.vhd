----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor portIO System with I/O
-- Module Name: portIO - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Controlador de puertos de Entrada/Salida (I/O). Gestiona el registro 
-- de los puertos de lectura y escritura sincronizados con el reloj.
-- ENG: Input/Output (I/O) port controller. Manages the register for 
-- read and write ports synchronized with the system clock.
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity portIO is
    Generic ( DATA_BITS : integer := 16);    
    Port ( clk : in std_logic;
    rst : in std_logic;
    portRd : in std_logic_vector (DATA_BITS-1 downto 0);     -- ESP: Pines de entrada físicos / ENG: Physical input pins
    portRdReg : out std_logic_vector (DATA_BITS-1 downto 0); -- ESP: Entrada registrada para la UC / ENG: Registered input for UC
    portWrEna : in std_logic;                                -- ESP: Habilitación de escritura / ENG: Write enable signal
    portWr : out std_logic_vector (DATA_BITS-1 downto 0);    -- ESP: Pines de salida físicos / ENG: Physical output pins
    portWrReg : in std_logic_vector (DATA_BITS-1 downto 0)); -- ESP: Dato a escribir desde la UC / ENG: Data to write from UC
end portIO;

architecture Behavioral of portIO is

begin

    -- ESP: Proceso secuencial para la sincronización de puertos
    -- ENG: Sequential process for port synchronization
    estadoProc: process (clk)
    begin
        if rising_edge(clk) then
            if(rst = '1') then
                -- ESP: Limpieza de registros al resetear
                -- ENG: Clear registers on reset
                portRdReg <= (others => '0');
                portWr <= (others => '0');
            else
                -- ESP: Actualización de salida solo si está habilitado por la UC
                -- ENG: Output update only if enabled by the UC
                if(portWrEna = '1') then
                    portWr <= portWrReg;
                end if;
                -- ESP: Registro de la entrada para evitar metaestabilidad
                -- ENG: Registering input to prevent metastability
                portRdReg <= portRd;
            end if;
        end if;
    end process;

end Behavioral;
