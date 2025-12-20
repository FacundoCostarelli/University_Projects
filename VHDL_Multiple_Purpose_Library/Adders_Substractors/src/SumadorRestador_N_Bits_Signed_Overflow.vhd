----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.05.2025 22:31:26
-- Design Name: 
-- Module Name: SumadorRestador_N_Bits_Signed_Overflow - Behavioral
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

entity SumadorRestador_N_Bits_Signed_Overflow is
    generic(N : integer :=4);
    port(a : in std_logic_vector(N-1 downto 0);
         b : in std_logic_vector(N-1 downto 0);
         sel : in std_logic;
         ov  : out std_logic;
         res : out std_logic_vector(N-1 downto 0));
end SumadorRestador_N_Bits_Signed_Overflow;

architecture Behavioral of SumadorRestador_N_Bits_Signed_Overflow is
    signal s : std_logic_vector(N-1 downto 0);
    signal r : std_logic_vector(N-1 downto 0);
    signal rOv_s : std_logic;
    signal sOv_s : std_logic;

begin

    s <= std_logic_vector(signed(b) + signed(a));
    r <= std_logic_vector(signed(b) - signed(a));

    res <= s when(sel = '1') else r;

    rOv_s <= (not(s(N-1)) and a(N-1) and b(N-1)) or 
             (s(N-1) and not(a(N-1)) and not(b(N-1)));
    
    sOv_s <= (not(r(N-1)) and not(a(N-1)) and b(N-1)) or
              (r(N-1) and a(N-1) and not(b(N-1)));

    ov <= sOv_s when(sel = '1') else rOv_s;
    ov <= sOv_s when(sel = '1') else rOv_s;
            
end Behavioral;
