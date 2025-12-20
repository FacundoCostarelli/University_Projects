----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.07.2025 13:07:39
-- Design Name: 
-- Module Name: lfsr_g_cell - Behavioral
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

entity lfsr_g_cell is
    Port ( clk  : in  std_logic;
           rst  : in  std_logic;
           init : in  std_logic;
           f    : in  std_logic; -- feedback signal (q(0))
           tap  : in  std_logic; -- tap(i)
           d    : in  std_logic; -- data input (from right neighbor)
           q    : out std_logic);
end lfsr_g_cell;

architecture Behavioral of lfsr_g_cell is

    -- Combinational logic (outside clocked process)
    signal q_S: std_logic;
    signal and_out: std_logic;
    signal xor_out: std_logic;
    
begin

-- Combinational logic
and_out <= f and tap;
xor_out <= and_out xor d;

process(clk,rst)
begin
    if (rst = '1') then -- rst tiene prioridad frente a ena siempre
        q_S <= init;
    elsif rising_edge(clk) then
        q_S <= xor_out;    
    end if;
end process;

    q <= q_S;
end Behavioral;
