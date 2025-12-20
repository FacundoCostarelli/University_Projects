----------------------------------------------------------------------------------
-- myShiftReg_dir.vhd
-- Registro de desplazamiento con carga paralela y dirección seleccionable.
--  - PL = '1'  -> carga paralela PI en 1 ciclo de clk
--  - PL = '0'  -> desplaza 1 bit cuando ENA = '1'
--  - msb_first = '1' -> MSB sale primero (shift izquierda, SO = Out_S(N-1))
--  - msb_first = '0' -> LSB sale primero (shift derecha,  SO = Out_S(0))  [UART típico]
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity myShiftReg_dir is
  generic (N : integer := 10);                                  -- ancho del registro
  port (
    clk       : in  std_logic;
    rst       : in  std_logic;
    ena       : in  std_logic;                         -- habilita el shift (un tick)
    si        : in  std_logic;                         -- bit que ingresa por el extremo opuesto
    so        : out std_logic;                         -- salida serie (bit extremo)
    po        : out std_logic_vector (N - 1 downto 0);
    pi        : in std_logic_vector (N - 1 downto 0);  -- carga paralela
    pl        : in  std_logic;                         -- '1' => carga paralela PI    
    msb_first : in  std_logic);                        -- '1' MSB-first, '0' LSB-first
 
end entity;

architecture Behavioral of myShiftReg_dir is
  signal Out_S : std_logic_vector(N-1 downto 0);
begin

 

  process(clk)
  begin
    if rising_edge(clk) then
      if (rst = '1') then
            Out_S <= (others => '0');    
      elsif(ena = '1') then
            if(pl = '0') then
                -- Desplazamiento de 1 bit en la dirección seleccionada
                if (msb_first = '1') then
                    -- MSB-first: corre a izquierda, SI entra por LSB
                    Out_S <= Out_S(N-2 downto 0) & si;
                else
                    -- LSB-first: corre a derecha, SI entra por MSB
                    Out_S <= si & Out_S(N-1 downto 1);
                end if;
            else
                -- Carga paralela sin desplazamiento
                Out_S <= pi;
            end if;
      end if;
    end if;
  end process;

 -- Bit que sale depende de la dirección elegida
  so <= Out_S(N-1) when (msb_first = '1') else Out_S(0);
 -- Salida paralelo 
  po  <= Out_S;

end Behavioral;
