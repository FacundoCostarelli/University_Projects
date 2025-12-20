----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 27.05.2025 17:48:23
-- Design Name: 
-- Module Name: conversorBinarioGray - Behavioral
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

entity conversorBinarioGray is
    Generic (N: integer := 8);
    Port ( entrada: in std_logic_vector (N-1 downto 0);
           salida : out std_logic_vector (N-1 downto 0);
              sel : in std_logic);
end conversorBinarioGray;

architecture Behavioral of conversorBinarioGray is
    signal bin_to_gray_out : std_logic_vector(N-1 downto 0);
    signal gray_to_bin_out : std_logic_vector(N-1 downto 0);
    signal salida_S        : std_logic_vector(N-1 downto 0);

    component binarioGray
        Generic (N: integer := 8);
        Port ( binario : in  std_logic_vector(N-1 downto 0);
               gray    : out std_logic_vector(N-1 downto 0));
    end component;

    component grayBinario
        Generic (N: integer := 8);
        Port ( gray    : in  std_logic_vector(N-1 downto 0);
               binario : out std_logic_vector(N-1 downto 0));
    end component;

begin
    -- Instantiate both converters
    Inst_B_to_G_Converter: binarioGray
        Generic Map (N => N)
        Port Map (binario => entrada, gray => bin_to_gray_out);

    Inst_G_to_B_Converter: grayBinario
        Generic Map (N => N)
        Port Map (gray => entrada, binario => gray_to_bin_out);

    -- Select output using 'sel'
    salida_S <= bin_to_gray_out when (sel = '0') else gray_to_bin_out;
    salida <= salida_S;

end Behavioral;

