----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.07.2025 23:31:41
-- Design Name: 
-- Module Name: ejemploMealy - Behavioral
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

entity ejemploMealy is
    Port ( clk : in std_logic;
           rst : in std_logic;
       entrada : in std_logic;
        salida : out std_logic;
       salidaR : out std_logic);
end ejemploMealy;

architecture Behavioral of ejemploMealy is
    type state_type is (stA, stB, stC , stD);
    signal state, next_state : state_type;
    signal salida_s : std_logic;

begin

----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state <= stA;
            salidaR <= '0';
        else
            state <= next_state;
            salidaR <= salida_s;
        end if;
    end if;
end process;

salida <= salida_s;


----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
logicaSalida: process (state, entrada)
begin
    case (state) is
        when stA =>
            if entrada = '0' then
                salida_s <= '0';
            else
                salida_s <= '1';
            end if;
        when stB =>
            salida_s <= '1';
        when stC =>
            salida_s <= '1';
        when stD =>
            salida_s <= '0';
        when others =>
            salida_s <= '0';
        end case;
end process;


----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, entrada)
begin
    next_state <= state;
    case (state) is
        when stA =>
            if entrada = '1' then
                next_state <= stB;
            end if;
        when stB =>
            next_state <= stC;
        when stC =>
            next_state <= stD;
        when stD =>
            next_state <= stA;
        when others =>
            next_state <= stA;
        end case;
end process;


end Behavioral;
