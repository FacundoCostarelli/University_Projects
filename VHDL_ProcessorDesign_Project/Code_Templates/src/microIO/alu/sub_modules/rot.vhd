----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07.11.2024 22:06:34
-- Design Name: 
-- Module Name: rot - Behavioral
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


entity rot is
    Port(entrada : in std_logic_vector(17-1 downto 0);
         desplazamiento: in std_logic_vector(16-1 downto 0);
         salida: out std_logic_vector(17-1 downto 0));        
end rot;

architecture Behavioral of rot is

begin
    salida <=   entrada(16-1 downto 0)&entrada(17-1) when desplazamiento=x"0001" else
                entrada(15-1 downto 0)&entrada(17-1 downto 16-1)  when desplazamiento=x"0002" else
                entrada(14-1 downto 0)&entrada(17-1 downto 15-1)  when desplazamiento=x"0003" else
                entrada(13-1 downto 0)&entrada(17-1 downto 14-1)  when desplazamiento=x"0004" else
                entrada(12-1 downto 0)&entrada(17-1 downto 13-1)  when desplazamiento=x"0005" else
                entrada(11-1 downto 0)&entrada(17-1 downto 12-1)  when desplazamiento=x"0006" else
                entrada(10-1 downto 0)&entrada(17-1 downto 11-1)  when desplazamiento=x"0007" else
                entrada(9-1  downto 0)&entrada(17-1 downto 10-1)  when desplazamiento=x"0008" else
                entrada(8-1  downto 0)&entrada(17-1 downto 9-1)   when desplazamiento=x"0009" else
                entrada(7-1  downto 0)&entrada(17-1 downto 8-1)   when desplazamiento=x"000A" else
                entrada(6-1  downto 0)&entrada(17-1 downto 7-1)   when desplazamiento=x"000B" else
                entrada(5-1  downto 0)&entrada(17-1 downto 6-1)   when desplazamiento=x"000C" else
                entrada(4-1  downto 0)&entrada(17-1 downto 5-1)   when desplazamiento=x"000D" else
                entrada(3-1  downto 0)&entrada(17-1 downto 4-1)   when desplazamiento=x"000E" else
                entrada(2-1  downto 0)&entrada(17-1 downto 3-1)   when desplazamiento=x"000F" else
                entrada(0)&entrada(17-1 downto 2-1)               when desplazamiento=x"0010" else

                entrada(0)&entrada(17-1 downto 2-1) when desplazamiento=x"FFFF" else             -- -1
                entrada(2-1 downto  0)&entrada(17-1 downto 3-1) when desplazamiento=x"FFFE" else   -- -2
                entrada(3-1 downto  0)&entrada(17-1 downto 4-1) when desplazamiento=x"FFFD" else   -- -3
                entrada(4-1 downto  0)&entrada(17-1 downto 5-1) when desplazamiento=x"FFFC" else   -- -4
                entrada(5-1 downto  0)&entrada(17-1 downto 6-1) when desplazamiento=x"FFFB" else   -- -5
                entrada(6-1 downto  0)&entrada(17-1 downto 7-1) when desplazamiento=x"FFFA" else   -- -6
                entrada(7-1 downto  0)&entrada(17-1 downto 8-1) when desplazamiento=x"FFF9" else   -- -7
                entrada(8-1 downto  0)&entrada(17-1 downto 9-1) when desplazamiento=x"FFF8" else   -- -8
                entrada(9-1 downto  0)&entrada(17-1 downto 10-1)when desplazamiento=x"FFF7" else  -- -9
                entrada(10-1 downto 0)&entrada(17-1 downto 11-1)when desplazamiento=x"FFF6" else -- -10
                entrada(11-1 downto 0)&entrada(17-1 downto 12-1)when desplazamiento=x"FFF5" else -- -11
                entrada(12-1 downto 0)&entrada(17-1 downto 13-1)when desplazamiento=x"FFF4" else -- -12 
                entrada(13-1 downto 0)&entrada(17-1 downto 14-1)when desplazamiento=x"FFF3" else -- -13
                entrada(14-1 downto 0)&entrada(17-1 downto 15-1)when desplazamiento=x"FFF2" else -- -14
                entrada(15-1 downto 0)&entrada(17-1 downto 16-1)when desplazamiento=x"FFF1" else -- -15
                entrada(16-1 downto 0)&entrada(16)              when desplazamiento=x"FFF0" else               -- -16
                entrada;    

end Behavioral;
