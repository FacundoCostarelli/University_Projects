----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.07.2025 20:04:49
-- Design Name: 
-- Module Name: myCnt2 - Behavioral
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

entity myCnt2 is
    Generic (N : integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             p : in std_logic_vector (N - 1 downto 0);
        salida : out std_logic);
end myCnt2;

architecture Behavioral of myCnt2 is

    component myCntBinarioSimple is
        Generic( N : integer := 4);
        Port(clk : in std_logic;
             rst : in std_logic;
             ena : in std_logic;
               q : out std_logic_vector (N - 1 downto 0));
    end component;

    signal rst_cnt_BinarioSimple: std_logic;
    signal cnt_S: std_logic_vector (N - 1 downto 0);

begin

U_CNT: myCntBinarioSimple
    Generic map (N => N)
    Port map(clk => clk,
             rst => rst_cnt_BinarioSimple,
             ena => ena,
             q   => cnt_S);
             
    process (clk)
    begin
        if(rising_edge (clk)) then
            if rst = '1' then
                rst_cnt_BinarioSimple <= '1';
                salida <= '0';
            elsif ena = '1' then
                rst_cnt_BinarioSimple <= '0';
                if(cnt_S = p) then
                    rst_cnt_BinarioSimple <= '1';
                    salida <= '1';
                else
                    salida <= '0';
                end if;
            end if;
        end if;    
    end process;
             

end Behavioral;
