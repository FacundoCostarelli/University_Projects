----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12.09.2025 23:32:46
-- Design Name: 
-- Module Name: SckRisingAndFallingEdgeDetector - Behavioral
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

entity SckRisingAndFallingEdgeDetector is
    Port (  clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;
            ena : in  std_logic;
              --q : out std_logic;
     risingEdge : out std_logic;
    fallingEdge : out std_logic);
end SckRisingAndFallingEdgeDetector;

architecture Behavioral of SckRisingAndFallingEdgeDetector is
-- Registro que guarda bit individual de una sck. 
 -- Por cada flanco ascendente de "clk", guarda el bit de "sck" y lo expone en la salida "q" 
 -- mientras que en la entrada sck está el nuevo bit a ingresar al registro.
 
signal sck_edge_register: std_logic_vector(2-1 downto 0);
-- IMPORTANTE FORMULA REGISTER: 
-- sck_edge_register(N-2 downto 0) con N = 2, por lo que vale sck_edge_register(0) en este caso
-- donde N = 2. Registro de 1 bit de salida y 1 bit de entrada-.

begin

process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            sck_edge_register <= "00";
        elsif(ena = '1') then
            sck_edge_register <= sck_edge_register(0)&d;
        end if;
    end if;
end process;

--q <= sck_edge_register(0);   
 
risingEdge  <= '1' when (sck_edge_register = "01") else '0';
fallingEdge <= '1' when (sck_edge_register = "10") else '0';

end Behavioral;

