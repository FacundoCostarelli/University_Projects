library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity myEdgeCnt_tb is
end myEdgeCnt_tb;

architecture Behavioral of myEdgeCnt_tb is

    -- Parámetros del diseño
    constant N : integer := 8;
    constant clk_period : time := 10 ns;
    -- Señales de prueba
    signal clk_tb : std_logic := '0';
    signal rst_tb : std_logic := '0';
    signal d_tb   : std_logic := '0';
    signal q_tb   : std_logic_vector(N-1 downto 0);

    -- Declaracion del component
    component myEdgeCnt
        generic (N : integer := 8);
        port (
            clk : in std_logic;
            rst : in std_logic;
            d   : in std_logic;
            q   : out std_logic_vector (N-1 downto 0)
        );
    end component;

begin

    -- Instanciar el diseño
    DUT: myEdgeCnt
        generic map (N => N)
        port map (
            clk => clk_tb,
            rst => rst_tb,
            d   => d_tb,
            q   => q_tb
        );

    -- Generador de reloj con clk_period
    clk_process : process
       -- variable clk_period : time := 10 ns;
    begin
        while true loop
            clk_tb <= '0';
            wait for clk_period / 2;
            clk_tb <= '1';
            wait for clk_period / 2;
        end loop;
    end process;

    -- Estímulo de señales
    stim_proc : process
       -- variable clk_period : time := 10 ns;
    begin
        -- Reset activo
        rst_tb <= '1';
        wait for 2 * clk_period;
        rst_tb <= '0';

        -- Flanco ascendente en d (de 0 a 1): cuenta
        d_tb <= '0'; wait for clk_period;
        d_tb <= '1'; wait for clk_period; -- ↑ flanco 1
        d_tb <= '1'; wait for clk_period; -- sin flanco
        d_tb <= '0'; wait for clk_period; -- ↓
        d_tb <= '0'; wait for clk_period; -- sin flanco
        d_tb <= '1'; wait for clk_period; -- ↑ flanco 2
        d_tb <= '0'; wait for clk_period; -- ↓
        d_tb <= '1'; wait for clk_period; -- ↑ flanco 3
        d_tb <= '0'; wait for clk_period; -- ↓
        d_tb <= '1'; wait for clk_period; -- ↑ flanco 4

        wait for 2 * clk_period; -- Esperar y terminar
        wait;
    end process;

end Behavioral;
