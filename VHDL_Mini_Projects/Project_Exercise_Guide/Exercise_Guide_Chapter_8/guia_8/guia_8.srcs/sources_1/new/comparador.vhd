----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2025 18:56:48
-- Design Name: 
-- Module Name: comparador - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity comparador is
    Generic (N: integer := 4);
    Port ( a : in std_logic_vector (N-1 downto 0);
           b : in std_logic_vector (N-1 downto 0);
           magCa2 : in std_logic;
           aMayorQueB : out std_logic;
           aMenorQueB : out std_logic;
           aIgualB : out std_logic);
end comparador;

architecture Behavioral of comparador is
    signal comparadorMag_out : std_logic_vector(2 downto 0);
    signal comparadorCa2_out : std_logic_vector(2 downto 0);
  
component comparadorMag
        Generic (N: integer := 4);
        Port ( a_Mag : in std_logic_vector (N-1 downto 0);
               b_Mag : in std_logic_vector (N-1 downto 0);
               aMayorQueB_Mag : out std_logic;
               aMenorQueB_Mag : out std_logic;
               aIgualB_Mag : out std_logic);
    end component;

component comparadorCa2
    Generic (N: integer := 4);
    Port ( a_Ca2 : in std_logic_vector (N-1 downto 0);
           b_Ca2 : in std_logic_vector (N-1 downto 0);
           aMayorQueB_Ca2 : out std_logic;
           aMenorQueB_Ca2 : out std_logic;
           aIgualB_Ca2 : out std_logic);
    end component;

    

begin

    Inst_comparadorCa2: comparadorCa2
        Generic Map (N => N)
        Port Map (a_Ca2 => a, b_Ca2 => b, aMayorQueB_Ca2 => comparadorCa2_out(0), aMenorQueB_Ca2 => comparadorCa2_out(1), aIgualB_Ca2 => comparadorCa2_out(2));
        

    Inst_comparadorMag: comparadorMag
        Generic Map (N => N)
        Port Map (a_Mag => a, b_Mag => b, aMayorQueB_Mag => comparadorMag_out(0), aMenorQueB_Mag => comparadorMag_out(1), aIgualB_Mag => comparadorMag_out(2));
    
     aMayorQueB <= comparadorMag_out(0) when(magCa2 ='0') else comparadorCa2_out(0);
     aMenorQueB <= comparadorMag_out(1) when(magCa2 ='0') else comparadorCa2_out(1);
     aIgualB    <= comparadorMag_out(2) when(magCa2 ='0') else  comparadorCa2_out(2);
    


end Behavioral;
