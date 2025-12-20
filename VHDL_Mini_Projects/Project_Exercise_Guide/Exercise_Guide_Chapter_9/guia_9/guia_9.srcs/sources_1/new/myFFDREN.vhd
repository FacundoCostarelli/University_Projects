----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 18.06.2025 12:10:30
-- Design Name: 
-- Module Name: myFFDREN - Behavioral
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

--  N BITS flip-flop D con reset sincrónico y enable.
entity myFFDREN is
    Generic (N: integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
             d : in std_logic_vector (N-1 downto 0);
             q : out std_logic_vector (N-1 downto 0));
end myFFDREN;

architecture Behavioral of myFFDREN is
  
  signal my_N_ZeroesVector: std_logic_vector (N-1 downto 0);
  
  -- DUDA CON ESTO
  -- Defino un array type con N elements, cada uno de tipo std_logic
  --type My_N_ZeroesArrayType is array (N-1 downto 0) of std_logic;

  -- Declaro una signal según el array type definido
  --signal my_N_ZeroesArray : My_N_ZeroesArrayType;

begin

    
    my_N_ZeroesVector <= (others => '0');

    -- DUDA CON ESTO
    -- Process para inicializar array con zeroes
    --process
    --   begin
        -- Initializo el array con all zeros
    --    my_N_ZeroesArray <= (others => '0');
    --    wait; --Necesario para simular pero no para synthesis
    -- end process;
        
    process(clk)
        begin
            if(rising_edge(clk)) then
                if(ena = '1') then -- Enable, para FFD Sinc --> va justo debajo del if que evalua el "clk"
                    if (rst = '1') then -- Reset Sinc --> va justo debajo del if que evalua "clk"
                        q <= my_N_ZeroesVector;
                    else
                        q <= d;
                    end if;
                end if;
            end if;
        end process;

end Behavioral;
