----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Program Counter System with I/O
-- Module Name: pc - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Contador de Programa (PC). Gestiona la dirección de lectura de la memoria
-- de instrucciones, permitiendo incrementos secuenciales o saltos mediante PL.
-- ENG: Program Counter (PC). Manages the instruction memory read address,
-- allowing for sequential increments or jumps through Parallel Load (PL).
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;


entity pc is
    Generic ( DATA_BITS : integer := 16);
    Port ( clk : in std_logic; 
    rst : in std_logic; 
    ena : in std_logic; 
    pl : in std_logic; 
    plAddr : in std_logic_vector (DATA_BITS - 1 downto 0); 
    data: out std_logic_vector (31 downto 0) 
    );
end pc;

architecture Behavioral of pc is

    -- ESP: Contador binario interno con capacidad de carga paralela
    -- ENG: Internal binary counter with parallel load capability
    component myCntBinarioPl is
      Generic (N: integer := 16);
      Port ( clk : in std_logic;
             rst : in std_logic;
             ena : in std_logic;
             dl : in std_logic;
             d : in std_logic_vector (9 downto 0);
             q : out std_logic_vector (9 downto 0));
    end component;
  
    signal cnt_q : std_logic_vector(9 downto 0); 

    -- ESP: Memoria ROM de instrucciones (generada mediante IP Core de Vivado)
    -- ENG: Instruction ROM Memory (generated via Vivado IP Core)
    component pcMem is
        Port (
            clka : in STD_LOGIC;
            addra : in STD_LOGIC_VECTOR(9 DOWNTO 0);
            douta : out STD_LOGIC_VECTOR(31 DOWNTO 0)
        );
    end component;

  begin
  
    -- ESP: Instancia del contador que genera las direcciones (PC)
    -- ENG: Instance of the counter that generates addresses (PC)
    cnt_inst : myCntBinarioPl
      generic map (N => 16)  
      port map (
        clk => clk,
        rst => rst,
        ena => ena,
        dl => pl,
        d => plAddr(9 downto 0),  
        q => cnt_q    
      );
      
    -- ESP: Lectura de la instrucción correspondiente a la dirección actual
    -- ENG: Fetching the instruction corresponding to the current address
    pcMem_inst: pcMem
        Port map (
            clka => clk,          
            addra => cnt_q,         
            douta => data     
        );

  end Behavioral;

