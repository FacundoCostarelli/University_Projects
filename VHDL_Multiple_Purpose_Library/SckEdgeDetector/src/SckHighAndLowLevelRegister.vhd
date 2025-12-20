----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12.09.2025 23:12:25
-- Design Name: 
-- Module Name: SckHighAndLowLevelRegister - Behavioral
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

entity SckHighAndLowLevelRegister is
Port (      clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;
            ena : in  std_logic;
              --q : out std_logic;
     HighLevel : out std_logic;
      LowLevel : out std_logic);
end SckHighAndLowLevelRegister;

architecture Behavioral of SckHighAndLowLevelRegister is

signal sck_level_register: std_logic_vector(2 - 1 downto 0);

begin

process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            sck_level_register <= "00";
        elsif(ena = '1') then
            sck_level_register(0) <= d;
            sck_level_register(1) <= sck_level_register(0);
        end if;               
    end if;   
end process;

--q <= sck_level_register(0);   

HighLevel <= '1' when (sck_level_register = "11") else '0';
LowLevel  <= '1' when (sck_level_register = "00") else '0';

end Behavioral;
