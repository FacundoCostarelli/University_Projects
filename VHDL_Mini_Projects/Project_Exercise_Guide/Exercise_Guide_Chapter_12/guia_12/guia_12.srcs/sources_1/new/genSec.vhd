----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.07.2025 11:06:38
-- Design Name: 
-- Module Name: genSec - Behavioral
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
entity genSec is
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             y : out std_logic_vector (3 downto 0));
end genSec;

architecture Behavioral of genSec is
    type state_type is (stA, stB, stC , stD);
    signal state, next_state : state_type;
    signal salida_s : std_logic_vector (3 downto 0);
begin

----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state <= stA;
            y <= "0000";
        elsif ena = '1' then
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
            salida_s <= "0000";
        when stB =>
            salida_s <= "0001";
        when stC =>
            salida_s <= "1100";
        when stD =>
            salida_s <= "0111";
        when others =>
            salida_s <= "0000";
        end case;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, ena)
begin
    next_state <= state;
        case (state) is
            when stA =>
                if ena = '1' then
                    next_state <= stB;
                else
                    next_state <= stA;
                end if;
            when stB =>
                if ena = '1' then
                    next_state <= stC;
                else
                    next_state <= stB;
                end if;
            when stC =>
                if ena = '1' then
                    next_state <= stD;
                else
                    next_state <= stC;
                end if;
            when stD =>
                if ena = '1' then
                    next_state <= stA;
                else
                    next_state <= stD;
                end if;
            when others =>
                next_state <= stA;
            end case;
end process;

end Behavioral;
