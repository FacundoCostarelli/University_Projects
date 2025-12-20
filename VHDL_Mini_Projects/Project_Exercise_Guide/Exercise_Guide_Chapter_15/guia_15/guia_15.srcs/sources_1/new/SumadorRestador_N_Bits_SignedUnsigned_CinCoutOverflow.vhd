----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03.06.2025 17:09:18
-- Design Name: 
-- Module Name: SumadorRestador_N_Bits_SignedUnsigned_CinCoutOverflow - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

entity SumadorRestador_N_Bits_SignedUnsigned_CinCoutOverflow is
    generic (
        N : integer := 4;
        ES_SIGNED : boolean := true
    );
    port (
        a    : in  std_logic_vector(N-1 downto 0);
        b    : in  std_logic_vector(N-1 downto 0);
        cin  : in  std_logic;
        sel  : in  std_logic; -- '1' para suma, '0' para resta
        cout : out std_logic;
        ov   : out std_logic;
        res  : out std_logic_vector(N-1 downto 0)
    );
end entity;

architecture Structural of SumadorRestador_N_Bits_SignedUnsigned_CinCoutOverflow is

    -- Declaración de componentes
    component Sumador_N_Bits_Cin_Cout
        generic (N : integer := 4; ES_SIGNED : boolean := true);
        port (a, b : in std_logic_vector(N-1 downto 0);
              cin : in std_logic;
              cout : out std_logic;
              res : out std_logic_vector(N-1 downto 0));
    end component;

    component Restador_N_Bits_Bin_Bout
        generic (N : integer := 4; ES_SIGNED : boolean := true);
        port (a, b : in std_logic_vector(N-1 downto 0);
              bin : in std_logic;
              bout : out std_logic;
              res : out std_logic_vector(N-1 downto 0));
    end component;

    -- Señales internas
    signal suma_S, resta_S : std_logic_vector(N-1 downto 0);
    signal cout_s, bout_s  : std_logic;
    signal ov_s, ov_r : std_logic;
    
begin

    -- Instancia del sumador
    Inst_Sumador: Sumador_N_Bits_Cin_Cout
        generic map (N => N, ES_SIGNED => ES_SIGNED)
        port map (
            a => a,
            b => b,
            cin => cin,
            cout => cout_s,
            res => suma_S
        );

    -- Instancia del restador
    Inst_Restador: Restador_N_Bits_Bin_Bout
        generic map (N => N, ES_SIGNED => ES_SIGNED)
        port map (
            a => a,
            b => b,
            bin => cin,
            bout => bout_s,
            res => resta_S
        );

    -- Selección del resultado y cout
    res  <= suma_S when sel = '1' else resta_S;
    cout <= cout_s when sel = '1' else bout_s;

   
    -- Solo si ES_SIGNED = true
    overflow_logic: if ES_SIGNED generate
    begin
        ov_s <= (not (suma_S(N-1)) and a(N-1) and b(N-1)) or
                (suma_S(N-1) and not (a(N-1)) and not (b(N-1)));

        
        ov_r <= (a(N-1) and not b(N-1) and not resta_S(N-1)) or
                (not a(N-1) and b(N-1) and resta_S(N-1));


        --ov_r <= (not (resta_S(N-1)) and not (a(N-1)) and b(N-1)) or
         --       (resta_S(N-1) and a(N-1) and not (b(N-1))); --> revisar

        ov <= ov_s when sel = '1' else ov_r;
    end generate;

    -- Si ES_SIGNED = false, overflow es siempre 0
    no_overflow: if not ES_SIGNED generate
        ov <= '0';
    end generate;

end architecture;

