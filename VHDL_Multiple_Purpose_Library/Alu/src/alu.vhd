----------------------------------------------------------------------------------
-- ALU con acumulador y registro de banderas (compatible VHDL-93)
-- Tabla de operaciones:
-- 0: ACC = ACC and op
-- 1: ACC = ACC or  op
-- 2: ACC = ACC xor op
-- 3: (carry,ACC) = ACC + op + carry
-- 4: (borrow,ACC)= ACC - op + borrow   (borrow usa carryBorrow)
-- 5: (Carry,ACC) = rotación por carry (op >= 0 izq, op < 0 der)  [DATA_BITS=16]
-- 6: ACC = op
-- 7: carrySet = op(0)
-- 8: satSet   = op(0)
-----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_MISC.ALL;  -- or_reduce

entity alu is
    generic (DATA_BITS : integer := 16);
    port (
        clk         : in  std_logic;
        rst         : in  std_logic;
        ena         : in  std_logic;
        code        : in  std_logic_vector(3 downto 0);
        op          : in  std_logic_vector(DATA_BITS-1 downto 0);

        acc         : out std_logic_vector(DATA_BITS-1 downto 0);
        zero        : out std_logic;
        overflow    : out std_logic;
        carryBorrow : out std_logic;
        negative    : out std_logic
    );
end alu;

architecture Behavioral of alu is
    --------------------------------------------------------------------------
    -- Componentes
    --------------------------------------------------------------------------
    component myFFDREN is
        generic (N : integer := 4);
        port (
            clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
            d   : in std_logic_vector(N-1 downto 0);
            q   : out std_logic_vector(N-1 downto 0)
        );
    end component;

    component myFFDRE is
        port (
            clk : in  std_logic;
            rst : in  std_logic;
            ena : in  std_logic;
            d   : in  std_logic;
            q   : out std_logic
        );
    end component;

    -- Rotación por carry: {carry,acc}=17, op=16
    component rot is
        port(
            entrada        : in  std_logic_vector(16 downto 0);
            desplazamiento : in  std_logic_vector(15 downto 0);
            salida         : out std_logic_vector(16 downto 0)
        );
    end component;

    component miniAlu is
        generic (DATA_BITS: integer := 16);
        port (
            a        : in  std_logic_vector (DATA_BITS-1 downto 0);
            b        : in  std_logic_vector (DATA_BITS-1 downto 0);
            carryIn  : in  std_logic;
            carryOut : out std_logic;
            res      : out std_logic_vector (DATA_BITS-1 downto 0);
            sat      : in  std_logic;
            code     : in  std_logic_vector (3 downto 0);
            zero     : out std_logic;
            overflow : out std_logic;
            negative : out std_logic
        );
    end component;

    -- Registros
    signal acc_q         : std_logic_vector(DATA_BITS-1 downto 0);
    signal carry_q       : std_logic;
    signal ovf_q         : std_logic;
    signal zero_q        : std_logic;
    signal neg_q         : std_logic;
    signal sat_q         : std_logic;

    -- Próximos
    signal acc_d         : std_logic_vector(DATA_BITS-1 downto 0);
    signal carry_d       : std_logic;
    signal ovf_d         : std_logic;
    signal zero_d        : std_logic;
    signal neg_d         : std_logic;
    signal sat_d         : std_logic;

    -- Auxiliares
    signal rot_in        : std_logic_vector(16 downto 0);
    signal rot_out       : std_logic_vector(16 downto 0);

    signal mini_res      : std_logic_vector(DATA_BITS-1 downto 0);
    signal mini_carry    : std_logic;
    signal mini_zero     : std_logic;
    signal mini_ovf      : std_logic;
    signal mini_neg      : std_logic;
    signal code_mini     : std_logic_vector(3 downto 0);

begin
    --------------------------------------------------------------------------
    -- Registros
    --------------------------------------------------------------------------
    reg_acc : myFFDREN
        generic map (N => DATA_BITS)
        port map (clk => clk, rst => rst, ena => ena, d => acc_d, q => acc_q);

    reg_carry : myFFDRE  port map (clk => clk, rst => rst, ena => ena, d => carry_d, q => carry_q);
    reg_ovf   : myFFDRE  port map (clk => clk, rst => rst, ena => ena, d => ovf_d,   q => ovf_q);
    reg_zero  : myFFDRE  port map (clk => clk, rst => rst, ena => ena, d => zero_d,  q => zero_q);
    reg_neg   : myFFDRE  port map (clk => clk, rst => rst, ena => ena, d => neg_d,   q => neg_q);
    reg_sat   : myFFDRE  port map (clk => clk, rst => rst, ena => ena, d => sat_d,   q => sat_q);

    --------------------------------------------------------------------------
    -- Submódulos
    --------------------------------------------------------------------------
    rot_in <= carry_q & acc_q;

    Rotator : rot
        port map (
            entrada        => rot_in,
            desplazamiento => op,  -- asume DATA_BITS=16
            salida         => rot_out
        );

    -- miniAlu sólo para códigos 0..4
    code_mini <= code when (unsigned(code) <= to_unsigned(4, code'length)) else "0000";

    Mini : miniAlu
        generic map (DATA_BITS => DATA_BITS)
        port map (
            a        => acc_q,
            b        => op,
            carryIn  => carry_q,
            carryOut => mini_carry,
            res      => mini_res,
            sat      => sat_q,
            code     => code_mini,
            zero     => mini_zero,
            overflow => mini_ovf,
            negative => mini_neg
        );

    --------------------------------------------------------------------------
    -- Próximos estados (secuencial dentro del process)
    --------------------------------------------------------------------------
    process(acc_q, carry_q, ovf_q, zero_q, neg_q, sat_q,
            code, op, mini_res, mini_carry, mini_zero, mini_ovf, mini_neg, rot_out)
    begin
        -- mantener por defecto
        acc_d   <= acc_q;
        carry_d <= carry_q;
        ovf_d   <= ovf_q;
        zero_d  <= zero_q;
        neg_d   <= neg_q;
        sat_d   <= sat_q;

        case code is
            ------------------------------------------------------------------
            -- 0/1/2: AND / OR / XOR   (Z,N actualizan; C/OVF sin cambio)
            ------------------------------------------------------------------
            when "0000" | "0001" | "0010" =>
                acc_d <= mini_res;
                -- if secuencial en lugar de when/else
                if or_reduce(mini_res) = '0' then
                    zero_d <= '1';
                else
                    zero_d <= '0';
                end if;
                neg_d <= mini_neg;

            ------------------------------------------------------------------
            -- 3: ADD
            ------------------------------------------------------------------
            when "0011" =>
                acc_d   <= mini_res;
                carry_d <= mini_carry;
                ovf_d   <= mini_ovf;
                if or_reduce(mini_res) = '0' then
                    zero_d <= '1';
                else
                    zero_d <= '0';
                end if;
                neg_d   <= mini_neg;

            ------------------------------------------------------------------
            -- 4: SUB
            ------------------------------------------------------------------
            when "0100" =>
                acc_d   <= mini_res;
                carry_d <= mini_carry;  -- aquí "carry" es borrow
                ovf_d   <= mini_ovf;
                if or_reduce(mini_res) = '0' then
                    zero_d <= '1';
                else
                    zero_d <= '0';
                end if;
                neg_d   <= mini_neg;

            ------------------------------------------------------------------
            -- 5: ROT por carry  (Z/N/OVF sin cambio)
            ------------------------------------------------------------------
            when "0101" =>
                acc_d   <= rot_out(15 downto 0);
                carry_d <= rot_out(16);

            ------------------------------------------------------------------
            -- 6: LOAD ACC = op
            ------------------------------------------------------------------
            when "0110" =>
                acc_d <= op;
                if or_reduce(op) = '0' then
                    zero_d <= '1';
                else
                    zero_d <= '0';
                end if;
                neg_d <= op(DATA_BITS-1);

            ------------------------------------------------------------------
            -- 7: carrySet
            ------------------------------------------------------------------
            when "0111" =>
                carry_d <= op(0);

            ------------------------------------------------------------------
            -- 8: satSet
            ------------------------------------------------------------------
            when "1000" =>
                sat_d <= op(0);

            ------------------------------------------------------------------
            -- 9..15: sin acción
            ------------------------------------------------------------------
            when others =>
                null;
        end case;
    end process;

    --------------------------------------------------------------------------
    -- Salidas registradas
    --------------------------------------------------------------------------
    acc         <= acc_q;
    carryBorrow <= carry_q;
    overflow    <= ovf_q;
    zero        <= zero_q;
    negative    <= neg_q;

end Behavioral;
