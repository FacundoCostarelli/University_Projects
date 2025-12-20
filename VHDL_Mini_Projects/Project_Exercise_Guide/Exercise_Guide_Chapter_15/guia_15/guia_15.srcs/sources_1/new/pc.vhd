----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.07.2025 14:33:08
-- Design Name: 
-- Module Name: pc - Behavioral
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

entity pc is
    Generic ( DATA_BITS : integer := 16);
    Port    (       clk : in std_logic;
                    rst : in std_logic;
                    ena : in std_logic;
                    pl  : in std_logic;
                 plAddr : in std_logic_vector (DATA_BITS - 1 downto 0);
                    data: out std_logic_vector (31 downto 0));
end pc;

architecture Behavioral of pc is

    signal cnt_q      : std_logic_vector(DATA_BITS-1 downto 0); 
    signal data_S     : std_logic_vector(31 downto 0);
    signal addr_S     : std_logic_vector(9 downto 0);
    signal data_mem   : std_logic_vector(31 DOWNTO 0);
    
    
    component myCntBinarioPl
        Generic( N : integer := 4);
        Port ( clk : in std_logic;
               rst : in std_logic;
               ena : in std_logic;
                dl : in std_logic;
                 d : in std_logic_vector (N - 1 downto 0);
                 q : out std_logic_vector (N - 1 downto 0));
    
    end component;
    
    component pcMem is
        Port (
            clka : in STD_LOGIC;
            addra : in STD_LOGIC_VECTOR(9 DOWNTO 0);
            douta : out STD_LOGIC_VECTOR(31 DOWNTO 0)
        );
    end component;

begin

    U1_Contador: myCntBinarioPl 
        generic map( N => DATA_BITS)
        port map ( clk => clk,
               rst => rst,
               ena => ena,
                dl => pl,
                 d => plAddr,
                 q => cnt_q           
        );

    addr_S <= cnt_q(9 downto 0);
    
    U2_pcMem_BlockRam: pcMem
        Port map (
            clka => clk,          
            addra => addr_S,         
            douta => data_mem     
        );

    data <= data_mem;

end Behavioral;
