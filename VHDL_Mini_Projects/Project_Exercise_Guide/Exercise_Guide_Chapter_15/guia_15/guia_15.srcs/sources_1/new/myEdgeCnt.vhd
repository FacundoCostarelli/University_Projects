----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.07.2025 12:39:19
-- Design Name: 
-- Module Name: myEdgeCnt - Behavioral
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

entity myEdgeCnt is
    Generic (N: integer := 8);
    Port (
        clk : in std_logic;
        rst : in std_logic;
        d   : in std_logic;
        q   : out std_logic_vector (N-1 downto 0)
    );
end myEdgeCnt;

architecture Behavioral of myEdgeCnt is
    signal asc_S  : std_logic;
    signal desc_S : std_logic;
    signal q_S: std_logic_vector (N-1 downto 0);
    
    component myEdgeDetector
        Port (
            clk         : in std_logic;
            rst         : in std_logic;
            d           : in std_logic;
            ascendente  : out std_logic;
            descendente : out std_logic
        );
    end component;
   
   component myCntBinarioSimple
        Generic( N : integer := 4);
        Port(clk : in std_logic;
             rst : in std_logic;
             ena : in std_logic;
               q : out std_logic_vector (N - 1 downto 0)
        );
   end component;
   
begin

    U1: myEdgeDetector
        Port map (
        clk         => clk,
        rst         => rst,
        d           => d,
        ascendente  => asc_S,
        descendente => desc_S
    );
    
    U2: myCntBinarioSimple
        Generic map( N => N)
        Port map(
        clk         => clk,
        rst         => rst,
        ena         => asc_S , 
        q           => q_S
        );

    q <= q_S;
    
end Behavioral;
