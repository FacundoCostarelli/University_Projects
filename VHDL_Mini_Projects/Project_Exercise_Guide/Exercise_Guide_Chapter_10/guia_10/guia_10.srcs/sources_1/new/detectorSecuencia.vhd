----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 16.07.2025 19:50:17
-- Design Name: 
-- Module Name: detectorSecuencia - Behavioral
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

entity detectorSecuencia is
    Port ( clk : in std_logic;
           rst : in std_logic;
             d : in std_logic;
        salida : out std_logic);
end detectorSecuencia;

architecture Behavioral of detectorSecuencia is

component myShiftReg
        Generic (N : integer := 4);
        Port (
            clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
            si  : in std_logic;
            so  : out std_logic;
            po  : out std_logic_vector(N - 1 downto 0);
            pi  : in std_logic_vector(N - 1 downto 0);
            pl  : in std_logic
        );
    end component;

    signal q, q_sync : std_logic_vector(3 downto 0);

begin

-- Instancia del registro de desplazamiento
    shift_inst : myShiftReg
        generic map ( N => 4 )
        port map (
            clk => clk,
            rst => rst,
            ena => '1',              -- Habilito por defecto
            si  => d,
            so  => open,             -- Salida serial abierta, no interesa solamente Q(3)
            po  => q,                -- Salida de todos los Qn
            pi  => (others => '0'),  -- Cargo todos 0 en pi, no uso carga paralela
            pl  => '0'               -- Desplazamiento serial sin carga paralela
        );

-- Comparación de secuencia
    process(clk)
    begin
        if rising_edge(clk) then
            q_sync <= q; -- copio el vaor ya actualizado para meter un delay de 1 ciclo de clk
            if (q_sync = "1010") then
                salida <= '1';
            else
                salida <= '0';
            end if;
        end if;
    end process;

end Behavioral;
