----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 16.07.2025 20:38:56
-- Design Name: 
-- Module Name: generadorSecuencia - Behavioral
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

entity generadorSecuencia is
    Port ( clk : in std_logic;
           rst : in std_logic;
           gen : in std_logic;
        salida : out std_logic);
end generadorSecuencia;

architecture Behavioral of generadorSecuencia is

 -- COMPONENTES
    component myEdgeDetector is
        Port ( clk : in std_logic;
               rst : in std_logic;
               d   : in std_logic;
               ascendente : out std_logic;
               descendente : out std_logic);
    end component;

    component myShiftReg is
        Generic (N : integer := 4);
        Port ( clk  : in std_logic;
               rst  : in std_logic;
               ena  : in std_logic;
               si   : in std_logic;
               so   : out std_logic;
               po   : out std_logic_vector (N-1 downto 0);
               pi   : in std_logic_vector (N-1 downto 0);
               pl   : in std_logic);
    end component;

    -- SEÑALES INTERNAS
    signal flanco_gen : std_logic;
    signal dummy_desc : std_logic;
    signal enable_sr  : std_logic := '0';
    signal carga      : std_logic := '0';
    signal datos      : std_logic_vector(3 downto 0) := "1010";

begin

    -- Detector de flanco ascendente
    U1: myEdgeDetector
        port map (
            clk => clk,
            rst => rst,
            d   => gen,
            ascendente => flanco_gen,
            descendente => dummy_desc
        );
        
    -- Registro de corrimiento
    U2: myShiftReg
        generic map (N => 4)
        port map (
            clk => clk,
            rst => rst,
            ena => enable_sr,
            si  => '0',               -- no usamos entrada serie
            so  => salida,           -- salida serial
            po  => open,             -- salida paralelo no se usa
            pi  => datos,            -- "1010"
            pl  => carga             -- carga paralelo si flanco_gen
        );

-- Control de carga y habilitación del registro
    process(clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                enable_sr <= '0';
                carga <= '0';
            else
                if flanco_gen = '1' then
                    carga <= '1';        -- pulso único para carga
                    enable_sr <= '1';    -- activa desplazamiento
                else
                    carga <= '0';        -- sólo dura 1 ciclo
                end if;
            end if;
        end if;
    end process;


end Behavioral;
