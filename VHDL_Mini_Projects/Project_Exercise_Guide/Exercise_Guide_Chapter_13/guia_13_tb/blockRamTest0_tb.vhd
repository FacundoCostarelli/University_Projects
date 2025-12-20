----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.08.2024 20:36:03
-- Design Name: 
-- Module Name: blockRamTest0_tb - Behavioral
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

entity blockRamTest0_tb is
--  Port ( );
end blockRamTest0_tb;

architecture Behavioral of blockRamTest0_tb is
component blockRamTest0
port (
clka : in std_logic;
wea : in std_logic_vector(0 DOWNTO 0);
addra : in std_logic_vector(9 DOWNTO 0);
dina : in std_logic_vector(15 DOWNTO 0);
douta : out std_logic_vector(15 DOWNTO 0)
);
end component;

-- Clk --
signal clka : std_logic := '0';
constant clk_period : time := 10 ns;

begin

-- Instantiate the Unit Under Test (UUT) --
uut: blockRamTest0 port map (
        clka => clka,
        wea => wea,
        addra => addra,
        dina => dina,
        douta => douta
    );

-- Clock process --
clk_process :process
begin
    clka <= '0';     wait for clk_period/2;
    clka <= '1';     wait for clk_period/2;
end process;

end Behavioral;
