----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.06.2025 15:49:14
-- Design Name: 
-- Module Name: miniAlu - Behavioral
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
use IEEE.STD_LOGIC_MISC.all;

entity miniAlu is
    generic (DATA_BITS: integer := 16);
    port ( a: in std_logic_vector (DATA_BITS-1 downto 0);    -- Operando a
           b: in std_logic_vector (DATA_BITS-1 downto 0);    -- Operando b
           carryIn : in std_logic;                           -- carry/borrow de entrada
           carryOut : out std_logic;                         -- carry/borrow de salida
           res: out std_logic_vector (DATA_BITS-1 downto 0); -- resultado de las operaciones.
           sat: in std_logic;                                -- si vale uno el resultado de la operación se satura.
           code: in std_logic_vector (3 downto 0);           -- indica qué operación debe realizar
           zero : out std_logic;                             -- se coloca en uno cuando la res vale cero
           overflow : out std_logic;                         -- salida que indica si hubo overfl ow en la operación.
           negative : out std_logic);                        -- indica si el resultado es negativo.
end miniAlu;

architecture Behavioral of miniAlu is
      signal carryOut_S : std_logic; 
      signal res_S : std_logic_vector(DATA_BITS-1 downto 0);
      signal sat_S : std_logic;
      signal overflow_S : std_logic;
      signal negative_S : std_logic;
      
      signal res_final_S : std_logic_vector(DATA_BITS-1 downto 0);
      
      signal res_FullAdderExtended : std_logic_vector(DATA_BITS-1 downto 0);
      signal res_Aux : std_logic_vector(DATA_BITS-1 downto 0);
       
      signal res_And : std_logic_vector(DATA_BITS-1 downto 0); 
      signal res_Or : std_logic_vector(DATA_BITS-1 downto 0);
      signal res_Xor : std_logic_vector(DATA_BITS-1 downto 0);
      
      signal sel_S : std_logic;
      
      signal aux_evaluation : std_logic_vector(2 downto 0);
      
      constant ES_SIGNED_LOCAL : boolean := true; 
        
      component SumadorRestador_N_Bits_SignedUnsigned_CinCoutOverflow
           generic(
                    N : integer := 4; 
                    ES_SIGNED : boolean := true
                   );
           port(   
                    a    : in  std_logic_vector(DATA_BITS-1 downto 0);
                    b    : in  std_logic_vector(DATA_BITS-1 downto 0);
                    cin  : in  std_logic;
                    sel  : in  std_logic; -- '1' para suma, '0' para resta
                    cout : out std_logic;
                    ov   : out std_logic;
                    res  : out std_logic_vector(DATA_BITS-1 downto 0)
                );
      end component; 
       
begin

    
       
    res_And <= a and b;
    res_Or  <= a or b;
    res_Xor <= a xor b;
       
    
    sel_S <= '1' when(code = "0011") else '0';
        
    -- Instancia del sumador
    Inst_FullAdderExtended_N_Bits_SI_UN_CinCoutOv: SumadorRestador_N_Bits_SignedUnsigned_CinCoutOverflow
        generic map (N => DATA_BITS,  ES_SIGNED => ES_SIGNED_LOCAL)
        port map (
            a => a,
            b => b,
            cin => carryIn,
            sel => sel_S,
            -- sel => code(2) para operacion resta per code(1) y code(0) para operacion suma
            cout => carryOut_S,
            ov => overflow_S,
            res => res_FullAdderExtended
        );
        
        overflow <= overflow_S;
        sat_S <= sat;
        
        aux_evaluation <= res_FullAdderExtended(DATA_BITS-1) & overflow_S & sat_S; 
        
        --with aux_evaluation select
        --res_aux <=  X"1000"    when "011", --> sepuede generalizar
        --            X"0111"    when "111", --> sepuede generalizar
        --            res_FullAdderExtended when others;
        
        -- Cargo todo con ceros y unos , debo indicar la cantidad de bits
        with aux_evaluation select
        res_aux(DATA_BITS-2 downto 0) <= (others => '0') when "011",
                                         (others => '1') when "111",
                                         res_FullAdderExtended(DATA_BITS-2 downto 0) when others;

        -- Ajusto el bit más significativo cargando cero o uno correspondientemente
        res_aux(DATA_BITS-1) <= '1' when aux_evaluation = "011" else
                                '0' when aux_evaluation = "111" else
                                res_FullAdderExtended(DATA_BITS-1);

        
        res_final_S <= res_aux        when (code = "0100" or code = "0011") else
                       res_And        when (code = "0000") else
                       res_Or         when (code = "0001") else
                       res_Xor        when (code = "0010") else 
                       (others=>'0');
                        -->Cada digito hexadecimal equivale a 4 bits en total
        
        -- Logica de cable de "zero", importante  or_reduce es para generalizar
        zero <= not(or_reduce(res_final_S));  
        
        negative_S <= '1' when (res_final_S(DATA_BITS-1) = '1') else '0';
        negative <= negative_S;
        
        carryOut <= carryOut_s;-- No importa para la saturacion

        res <= res_final_S;
end Behavioral;
