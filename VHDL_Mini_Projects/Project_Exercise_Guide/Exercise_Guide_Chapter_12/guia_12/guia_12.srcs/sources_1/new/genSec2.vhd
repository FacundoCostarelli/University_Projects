----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.07.2025 15:37:18
-- Design Name: 
-- Module Name: genSec2 - Behavioral
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

---------Generador de secuencia con MDE MOORE----------
entity genSec2 is
    Port ( clk : in std_logic;
           rst : in std_logic;
      entradas : in std_logic_vector(1 downto 0);
             y : out std_logic_vector (2 downto 0));
end genSec2;

architecture Behavioral of genSec2 is
    type state_type is (stA, stB, stC , stD);
    signal state, next_state : state_type;
    signal salida_s : std_logic_vector (2 downto 0);

begin

----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state <= stA;
            y <= "000";
        else
            state <= next_state;
            y <= salida_s;
        end if;
    end if;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
logicaSalida: process (state)
begin
    case (state) is
        when stA =>
            salida_s <= "000";
        when stB =>
            salida_s <= "000";
        when stC =>
            salida_s <= "101";
        when stD =>
            salida_s <= "111";
        when others =>
            salida_s <= "000";
        end case;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, entradas)
begin
    next_state <= state;
        case (state) is
            when stA =>
                if entradas = "01" then
                    next_state <= stB;
                elsif entradas = "11" then
                    next_state <= stC;
                else
                    next_state <= stA;
                end if;
            when stB =>
                if entradas = "00" then
                    next_state <= stA;
                elsif entradas = "01" then
                    next_state <= stB;
                elsif entradas = "11" then
                    next_state <= stC;
                else -- si llega 10
                    next_state <= stB;
                end if;
            when stC =>
                next_state <= stD;
            when stD =>
                next_state <= stA;
            when others =>
                next_state <= stA;
            end case;
end process;


end Behavioral;
