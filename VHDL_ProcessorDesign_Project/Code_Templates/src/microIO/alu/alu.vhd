----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor ALU Unit System with I/O
-- Module Name: alu - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Unidad Aritmético-Lógica (ALU) de 16 bits. Realiza operaciones lógicas,
-- aritméticas con saturación opcional, rotación y gestión de registros de estado.
-- ENG: 16-bit Arithmetic Logic Unit (ALU). Performs logical and arithmetic 
-- operations with optional saturation, rotation, and status flag management.
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity alu is
    generic (DATA_BITS: integer := 16);
    port (  clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
            code: in std_logic_vector (3 downto 0); -- Operation Code
            op : in std_logic_vector (DATA_BITS-1 downto 0); -- Input operand
            acc : out std_logic_vector (DATA_BITS-1 downto 0); -- Output accumulator
            zero : out std_logic;
            overflow : out std_logic;
            carryBorrow : out std_logic;
            negative : out std_logic);
end alu;

architecture Behavioral of alu is

    -- ESP: Señales para registros internos de acumulador y banderas
    -- ENG: Signals for internal accumulator and flags registers
    signal acc_q : std_logic_vector(DATA_BITS - 1 downto 0);
    signal acc_d : std_logic_vector(DATA_BITS - 1 downto 0);
    signal carryBorrow_q : std_logic;
    signal carryBorrow_d : std_logic;
    signal overflow_q : std_logic;
    signal overflow_d : std_logic;
    signal negative_q : std_logic;
    signal negative_d : std_logic;
    signal zero_q : std_logic;
    signal zero_d : std_logic;
    signal sat_q : std_logic;
    signal sat_d : std_logic;
    
    -- ESP: Señales auxiliares para cálculos aritméticos y rotación
    -- ENG: Auxiliary signals for arithmetic calculations and rotation
    signal temp_res : std_logic_vector(DATA_BITS downto 0); 
    signal min_val: std_logic_vector(DATA_BITS-1 downto 0);
    signal max_val: std_logic_vector(DATA_BITS-1 downto 0);
    signal sum : std_logic_vector (DATA_BITS downto 0);
    signal res : std_logic_vector (DATA_BITS downto 0);
    constant cero : std_logic_vector(DATA_BITS-1 downto 0) := (others => '0');
    signal rot_entrada : std_logic_vector(16 downto 0); 
    signal rot_salida : std_logic_vector(16 downto 0);

    -- ESP: Signal caso especial
    -- ENG: Special Signal case 
    signal operando_uno: std_logic_vector (DATA_BITS-1 downto 0):= std_logic_vector(to_signed(1,DATA_BITS));

begin

    -- ESP: Instancia del módulo rotador
    -- ENG: Rotator module instance
    U1: entity work.rot 
        port map (  entrada => rot_entrada, 
                    desplazamiento => op, 
                    salida => rot_salida);

    rot_entrada <= carryBorrow_q & acc_q;

    -- ESP: Proceso secuencial para actualizar registros de la ALU
    -- ENG: Sequential process to update ALU registers
    process (clk, rst)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                acc_q <= (others => '0');
                carryBorrow_q <= '0';
                overflow_q <= '0';
                negative_q <= '0';
                zero_q <= '0';
                sat_q <= '0';
            elsif ena = '1' then
                acc_q <= acc_d;
                carryBorrow_q <= carryBorrow_d;
                overflow_q <= overflow_d;
                negative_q <= negative_d;
                zero_q <= zero_d;
                sat_q <= sat_d;
            end if;
        end if;
    end process;

    
    min_val <= x"8000";
    max_val <= x"7FFF";
    
    -- ESP: Cálculos aritméticos base (Suma y Resta con Carry)
    -- ENG: Base arithmetic calculations (Addition and Subtraction with Carry)
    sum <= std_logic_vector(signed(('0' & acc_q)) + signed(('0' & operando_uno)) + signed((cero & carryBorrow_q))) when(code = "1001") else
           std_logic_vector(signed(('0' & acc_q)) + signed(('0' & op)) + signed((cero & carryBorrow_q)));
   
    res <= std_logic_vector(signed(('0' & acc_q)) - signed(('0' & op)) - signed((cero & carryBorrow_q)));
    
    -- ESP: Lógica combinacional para el cálculo del próximo valor del acumulador
    -- ENG: Combinational logic for calculating the next accumulator value
    acc_d <=    (acc_q and op) when(code = "0000") else -- AND
                (acc_q or op)  when(code = "0001") else -- OR
                (acc_q xor op) when(code = "0010") else -- XOR
                
                -- ESP: Suma con detección de saturación
                -- ENG: Addition with saturation detection
                (max_val) when((code = "0011" or code = "1001") and (signed(sum(DATA_BITS-1 downto 0)) < 0 and signed(acc_q) > 0 and signed(op) > 0) and sat_q = '1') else   
                (min_val) when((code = "0011" or code = "1001") and (signed(sum(DATA_BITS-1 downto 0)) > 0 and signed(acc_q) < 0 and signed(op) < 0) and sat_q = '1') else   
                (sum(DATA_BITS-1 downto 0)) when(code = "0011" or code = "1001") else 
                
                -- ESP: Resta con detección de saturación
                -- ENG: Subtraction with saturation detection
                (max_val) when(code = "0100" and (signed(res(DATA_BITS-1 downto 0)) < 0 and signed(acc_q) > 0 and signed(op) < 0) and sat_q = '1') else   --4 resta con saturacion positiva
                (min_val) when(code = "0100" and (signed(res(DATA_BITS-1 downto 0)) > 0 and signed(acc_q) < 0 and signed(op) > 0) and sat_q = '1') else   --4 resta con saturacion negativa
                (res(DATA_BITS-1 downto 0)) when(code = "0100") else --4 resta
                
                -- ESP: Rotador y asignaciones de acumulador
                -- ENG: Rotator and accumulator assigment
                (rot_salida(DATA_BITS-1 downto 0)) when(code = "0101") else 
                (op)  when(code = "0110") else          -- ACC = OP
                (acc_q) when(code = "0111") else        -- CARRY= OP
                (acc_q) when(code = "1000") else        -- SAT = OP
                (others => '0');                        
    
    -- ESP: Actualización de banderas de estado
    -- ENG: Status flags update            
    carryBorrow_d <=    sum(DATA_BITS) when(code = "0011" or code = "1001") else 
                        res(DATA_BITS) when(code = "0100") else 
                        rot_salida(DATA_BITS) when(code = "0101") else 
                        op(0) when(code = "0111") else
                        carryBorrow_q;                 


    overflow_d <=   ('1') when((code = "0011" or code = "1001") and ((signed(sum(DATA_BITS-1 downto 0)) < 0 and signed(acc_q) >= 0 and signed(op) >= 0) or (signed(sum(DATA_BITS-1 downto 0)) >= 0 and signed(acc_q) < 0 and signed(op) < 0))) else 
                    ('1') when(code = "0100" and ((signed(res(DATA_BITS-1 downto 0)) < 0 and signed(acc_q) >= 0 and signed(op) < 0) or (signed(res(DATA_BITS-1 downto 0)) >= 0 and signed(acc_q) < 0 and signed(op) >= 0))) else 
                    ('0') when(code = "0011" or code = "0100") else 
                    overflow_q; 

                
    negative_d <=       ('1') when(signed(acc_d) < 0) else 
                        '0';
                
    zero_d <=           ('1') when(signed(acc_d) = 0) else 
                        '0';
  
    sat_d <=            op(0) when(code = "1000") else
                        sat_q;                                             


    -- ESP: Salidas finales
    -- ENG: Final outputs
    acc <= acc_q;
    carryBorrow <= carryBorrow_q;
    overflow <= overflow_q;
    zero <= zero_q;
    negative <= negative_q;

end Behavioral;