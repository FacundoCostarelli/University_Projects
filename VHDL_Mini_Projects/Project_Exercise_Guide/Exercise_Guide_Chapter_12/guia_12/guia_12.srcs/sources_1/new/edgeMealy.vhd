----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.07.2025 00:51:28
-- Design Name: 
-- Module Name: edgeMealy - Behavioral
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

entity edgeMealy is
    Port ( clk : in std_logic;
           rst : in std_logic;
             d : in std_logic;
             y : out std_logic);
end edgeMealy;

architecture Behavioral of edgeMealy is
    type state_type is (stA, stB);
    signal state, next_state : state_type;
    signal salida_s : std_logic;

begin

----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state <= stA;
            y <= '0';
        else
            state <= next_state;
            y <= salida_s;
        end if;
    end if;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
logicaSalida: process (state, d)
begin
    case (state) is
        when stA =>
            if d = '1' then
                salida_s <= '1';
            else
                salida_s <= '0';
            end if;
        when stB =>
            if d = '0' then
                salida_s <= '0';
            else
                salida_S <= '0';
            end if;
        when others =>
            salida_s <= '0';
        end case;
end process;


----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, d)
begin
    next_state <= state;
    case (state) is
        when stA =>
            if d = '1' then
                next_state <= stB;
            else 
                next_state <= stA;
            end if;
        when stB =>
            if d = '0' then
                next_state <= stA;
            else
                next_state <= stB;
            end if;
        when others =>
                next_state <= stA;
        end case;
end process;

end Behavioral;
