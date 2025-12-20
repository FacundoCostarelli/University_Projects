library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;

entity calcOverflow_tb is
--  Port ( );
end calcOverflow_tb;

architecture Behavioral of calcOverflow_tb is

    component calcOverflow is
    Port ( a : in std_logic;
           b : in std_logic;
           r : in std_logic;
           op: in std_logic;
           ov: out std_logic);
    end component;

    signal a : std_logic;
    signal b : std_logic;
    signal r : std_logic;
    signal op: std_logic;
    signal ov: std_logic;

    signal entrada : unsigned (3 downto 0) := "0000";

begin

uut: calcOverflow PORT MAP (
        a => a,          
        b => b,
        r => r,
        op => op,
        ov => ov
        );

stim_proc: process    
    
begin

    entrada <= entrada + 1;  
    a <= entrada(0);
    b <= entrada(1);
    r <= entrada(2);
    op <= entrada(3);
    wait for 100 ns;       
    
end process; 


end Behavioral;

