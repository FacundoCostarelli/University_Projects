----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 31.07.2025 22:59:56
-- Design Name: 
-- Module Name: alu_tb - Behavioral
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

entity alu_tb is
end alu_tb;

architecture Behavioral of alu_tb is

component alu
    generic (DATA_BITS: integer := 16);
    port ( clk : in std_logic; -- Clock del sistema
           rst : in std_logic; -- Reset sincr nico del sistema
           ena : in std_logic; -- Habilita la realizaci n de la operaci n
           code: in std_logic_vector (4-1 downto 0); -- C digo de la operaci n a realizar
            op : in std_logic_vector (DATA_BITS-1 downto 0); -- Operando
           acc : out std_logic_vector (DATA_BITS-1 downto 0); -- Acumulador
          zero : out std_logic; -- Acumulador en cero
      overflow : out std_logic; -- Overflow
   carryBorrow : out std_logic; -- Carry/Borrow
      negative : out std_logic -- Acumulador negativo
      );
end component;

    signal clk_tb: std_logic:='0';
    signal rst_tb: std_logic:='0';
    signal ena_tb: std_logic:='0';
    signal code_tb: std_logic_vector(4-1 downto 0):=(others=>'0');
    signal op_tb: std_logic_vector(16-1 downto 0):=(others=>'0');
    signal acc_tb: std_logic_vector(16-1 downto 0):=(others=>'0');
    signal zero_tb: std_logic:='0';
    signal overflow_tb: std_logic:='0';
    signal carryBorrow_tb: std_logic:='0';
    signal negative_tb: std_logic:='0';
    constant clk_period : time := 10 ns;
    type TState is (reset,prueba_acc_enable,prueba_and,
    prueba_or,prueba_xor,prueba_suma,prueba_sat_positiva,
    prendo_bit_sat,prueba_suma_negativos,genero_carry,
    suma_con_carry,prueba_resta,resta_sat_positiva,
    limpio_overflow,saturacion_negativa,resta_negativa_saturada,
    borrow,resta_con_borrow,rotacion);
    signal StateProob: Tstate := reset;

begin
    uut: ALU
    Generic map(DATA_BITS=> 16)
    PORT MAP (
           clk =>clk_tb,
           rst =>rst_tb,
           ena =>ena_tb,
           code=>code_tb,
            op =>op_tb,
           acc =>acc_tb,
          zero =>zero_tb,
      overflow =>overflow_tb,
   carryBorrow =>carryBorrow_tb,
      negative =>negative_tb
        );
    

    -- Clock process --
    clk_process :process
    begin
    clk_tb <= '0';     wait for clk_period/2;
    clk_tb <= '1';     wait for clk_period/2;
    end process;
    
    stim_proc:process
    begin
        --hold reset
        rst_tb<='1';        
        wait for clk_period*2;
        rst_tb<='0';        
        wait for clk_period;
        
        --cargo algo en acc y pruebo el enable
        StateProob<=prueba_acc_enable;
        code_tb<="0110";
        op_tb<=x"5555";
        wait for clk_period;
        ena_tb<='1';
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        --prueba comando and
        StateProob<=prueba_and;
        code_tb<="0000";
        op_tb<=x"AAAA";
        ena_tb<='1';
        wait for clk_period*2;
        ena_tb<='0';
        wait for clk_period;

        --prueba comando or
        StateProob<=prueba_or;
        code_tb<="0001";
        op_tb<=x"BBBB";
        ena_tb<='1';
        wait for clk_period*2;
        ena_tb<='0';
        wait for clk_period;

        --prueba comando xor
        StateProob<=prueba_xor;
        code_tb<="0010";
        op_tb<=x"BBBB";
        ena_tb<='1';
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period*2;

        --prueba comando suma
        --limpio el acc
        StateProob<=prueba_suma;
        code_tb<="0001";
        op_tb<=x"0000";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"0003";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0002";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
                
        --pruebo saturacion positiva
        StateProob<=prueba_sat_positiva;
        ena_tb<='1';
        code_tb<="0110";
        op_tb<=x"7FFE";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0002";        
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period*2;
        
        --pruebo hacer la misma operacion con bit sat =1
        StateProob<=prendo_bit_sat;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"7FFE";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0002";        
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period*2;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0000";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period*2;
        
        --pruebo una suma de negativos
        StateProob<=prueba_suma_negativos;
        code_tb<="0110";
        op_tb<=x"8004";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"FFFF";
        wait for clk_period;
        --saturo por negativos
        op_tb<=x"FFF0";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;

        --repito con bit sat = 1
        StateProob<=prendo_bit_sat;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"8004";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"FFFF";
        wait for clk_period;
        --saturo por negativos
        op_tb<=x"FFF0";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        --prueba de carry
        --limpio el carry
        StateProob<=genero_carry;
        ena_tb<='1';
        code_tb<="0111";
        op_tb<=x"0000";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"FFFF";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0001";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
 
        --sumo 1+1+carry
        StateProob<=suma_con_carry;
        ena_tb<='1';
        code_tb<="0110";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0001";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
    
        --prueba comando resta        
        --limpio el acc
        StateProob<=prueba_resta;
        code_tb<="0110";
        op_tb<=x"0000";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"0003";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"0002";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;

        --saturacion positiva
        StateProob<=resta_sat_positiva;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0000";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"7FFE";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"FFF0";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        
        --(+)con saturacion de palabra
        StateProob<=prendo_bit_sat;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"7FFE";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"FFF0";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;

        --limpio overflow
        StateProob<=limpio_overflow;
        ena_tb<='1';
        code_tb<="0110";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0011";
        op_tb<=x"0001";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        --saturacion negativa
        StateProob<=saturacion_negativa;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0000";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"8001";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"0004";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
                
        --(-)con saturacion de palabra
        StateProob<=resta_negativa_saturada;
        ena_tb<='1';
        code_tb<="1000";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0110";
        op_tb<=x"8001";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"0004";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        --borrow
        StateProob<=borrow;
        code_tb<="0110";
        op_tb<=x"0000";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"0002";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
    
        --borrow 1-2+1
        StateProob<=resta_con_borrow;
        code_tb<="0110";
        op_tb<=x"0007";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0111";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0100";
        op_tb<=x"0002";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
        --prueba de rotacion
        StateProob<=rotacion;
        code_tb<="0110";
        op_tb<=x"0107";
        ena_tb<='1';
        wait for clk_period;
        code_tb<="0111";
        op_tb<=x"0001";
        wait for clk_period;
        code_tb<="0101";
        op_tb<=x"0001";
        wait for clk_period;

        wait for clk_period;

        --prueba de rotacion
        StateProob<=rotacion;
        ena_tb<='1';
        code_tb<="0101";
        op_tb<=x"0001";
        wait for clk_period;
        ena_tb<='0';
        wait for clk_period;
        
    wait;
    end process;

end Behavioral;
