----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.08.2025 19:38:17
-- Design Name: 
-- Module Name: uartTx - Behavioral
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
use ieee.math_real.all;

entity uartTx is
Generic (baudRate : integer := 9600;
         sysClk : integer := 100000000;
         dataSize : integer := 8);
Port (  clk : in std_logic;
        rst : in std_logic;
        dataWr : in std_logic;
        dataTx : in std_logic_vector (dataSize - 1 downto 0);
        ready : out std_logic;
        tx : out std_logic);
end uartTx;


architecture Behavioral of uartTx is

---------------Signals MDE------------
type state_type is (stIdle, stTransmitingBits, stEofTx);
-- NOTA: stIdle = Estado de Idle
-- NOTA: stReceiveBits = Estado de recibiendo bits
-- NOTA: stEofRx = Estado de fin de recepción de bits
signal state, next_state : state_type;
    
--------------Component y Signals de cnt de pulsos de transmiting---------------    
component myCnt is
    Generic (M : integer := 100);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
     salidaM_2 : out std_logic;
       salidaM : out std_logic);
end component;

signal flag_transmiting_cnt_M  : std_logic;
signal flag_transmiting_cnt_M2 : std_Logic;
signal ena_transmiting_cnt_ctl : std_logic;



 -- Cantidad de pulsos respecto de sysClk, que dura un bit de Tx. Si dividimos /2 esa cantidad, podremos samplear a la mitad de la duracion del pulso del dato
constant divisor_transmiting : integer := (sysClk/baudRate)-1;

--------------Component y Signals de SingleModuleCnt para contar bits recibidos,(0..dataSize-1)--------------- 
--------------Abarca bits de start, data, stop---------------------------------------------------------------- 
component mySingleModuleCnt is
Generic (N : integer := 4);
     Port ( clk : in std_logic;
            rst : in std_logic;
            ena : in std_logic;
              p : in std_logic_vector (N - 1 downto 0);
counting_status : out std_logic); 
end component;

constant N_TX_BITS_COUNTER : integer := integer(ceil(log2(real(dataSize+1))));
signal divisor_tx_bits : integer := dataSize+1;-- 1 Start bit + 8 data bits + 1 Stop Bit
signal P_VAL_TX_BITS : std_logic_vector(N_TX_BITS_COUNTER-1 downto 0) := std_logic_vector(to_unsigned(divisor_tx_bits, N_TX_BITS_COUNTER));

signal ena_TxBits_cnt_ctl: std_logic := '0';
signal tc_tx_bits_flag: std_logic := '0';

--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
---------------------------myShiftReg_Dir solo para probar---------------------------------------------------
component myShiftReg_dir is
  generic (
    N : integer := 10                                  -- ancho del registro
  );
  port (
    clk       : in  std_logic;
    rst       : in  std_logic;
    ena       : in  std_logic;                         -- habilita el shift (un tick)
    si        : in  std_logic;                         -- bit que ingresa por el extremo opuesto
    so        : out std_logic;                         -- salida serie (bit extremo)
    po        : out std_logic_vector (N - 1 downto 0);
    pl        : in  std_logic;                         -- '1' => carga paralela PI
    pi        : in std_logic_vector (N - 1 downto 0);  -- carga paralela
    msb_first : in  std_logic);                        -- '1' MSB-first, '0' LSB-first 
  
end component;

--------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------

--------------Component y Signals de registro de desplazamiento para guardar dato de Rx---------------    
--component myShiftReg is
--    Generic (N: integer := 4);
--    Port ( clk : in std_logic;
--           rst : in std_logic; 
--           ena : in std_logic;
--           si : in std_logic;
--           so : out std_logic;
--           po : out std_logic_vector (N - 1 downto 0);
--           pi : in std_logic_vector (N - 1 downto 0); 
--           pl : in std_logic);
--end component;    
        
signal ena_shift_register : std_logic;  
 
signal bitStart: std_logic := '0';
signal bitStop: std_logic := '1'; 
  
signal dataRd_flag_q: std_logic;
signal dataRd_flag_d: std_logic;

--signal dataTx_s: std_logic;	

signal dataTx_Pi_s: std_logic_vector(dataSize+2 - 1 downto 0);
	
component SckRisingAndFallingEdgeDetector is
    Port (  clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;
            ena : in  std_logic;
            --  q : out std_logic;
     risingEdge : out std_logic;
    fallingEdge : out std_logic);
end component;

signal sck_rising_edge_flag    : std_logic := '0';
signal sck_falling_edge_flag   : std_logic := '0';

	
begin

TransmitingCounter_TxData: myCnt
    generic map ( M => divisor_transmiting )
    port map (  clk => clk,
                rst => rst,
                ena => ena_transmiting_cnt_ctl,
          salidaM_2 => open,
            salidaM => flag_transmiting_cnt_M
    );

TxBitsCounter: mySingleModuleCnt 
     generic map( N => N_TX_BITS_COUNTER )
     port map ( clk => clk,
                rst => rst,
                ena => ena_TxBits_cnt_ctl,
                  p => P_VAL_TX_BITS,              
    counting_status => tc_tx_bits_flag
    ); 
    
    
-- Dato rx entra de carga paralela tal que al ir desplazandose queda el LSB en el registro mas a la derecha
-- mientras que el MSB queda en el registro mas a la izquierda
--TxDataRegister: myShiftReg 
--    generic map (N => dataSize+2)
--    port map ( clk => clk,
--               rst => rst,
--               ena => ena_shift_register,
--                si => '1',
--                so => tx,
--                po => open,
--                pi => dataTx_Pi_s,
--                pl => dataWr
--           );
           
TxDataRegister: myShiftReg_dir 
  generic map ( N => dataSize+2)               -- ancho del registro 
  port map(   clk => clk,
              rst => rst,
              ena => ena_shift_register,        -- habilita el shift (un tick)                               -- '1' => carga paralela PI
              si  => '1',                       -- bit que ingresa por el extremo opuesto
              so  => tx,                        -- salida serie (bit extremo)
              po => open,
              pi => dataTx_Pi_s,
              pl => dataWr,
              msb_first => '0'                  -- '1' MSB-first, '0' LSB-first           
  );

          
           
           
 
dataTx_Pi_s <= bitStart & dataTx & bitStop; 
          
sckEdgeDetector: SckRisingAndFallingEdgeDetector
port map (
  clk        => clk,
  rst        => rst,
  d          => dataWr,
  ena        => '1',
  risingEdge => sck_rising_edge_flag,
  fallingEdge=> sck_falling_edge_flag
);          


ReadyFlagRegister: process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            dataRd_flag_q <= '0';
        else
            dataRd_flag_q <= dataRd_flag_d;
        end if;
    end if;
end process; 

--------------------------------------TX MDE, TIPO MOORE, la salida NO depende de la entrada------------------------------------------------------ 
----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state <= stIdle;
            ready <= '0';
        else
            state  <= next_state;
            ready  <= dataRd_flag_q;
        end if;
    end if;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
logicaSalida: process (state, sck_falling_edge_flag, flag_transmiting_cnt_M, tc_tx_bits_flag)
begin

ena_transmiting_cnt_ctl <= '0';
ena_TxBits_cnt_ctl <= '0';
ena_shift_register <= '0';
dataRd_flag_d <= '0';

    case state is
        when stIdle =>
            ena_shift_register <= '1';
            dataRd_flag_d <= '0';
            
            if(sck_falling_edge_flag = '1') then
                ena_transmiting_cnt_ctl <= '1';
                ena_TxBits_cnt_ctl <= '0';
                ena_shift_register <= '0';           
            end if;
        when stTransmitingBits =>					
            ena_transmiting_cnt_ctl <= '1';    
            if(flag_transmiting_cnt_M = '1' and tc_tx_bits_flag = '0') then       
               ena_shift_register <= '1';
               ena_TxBits_cnt_ctl <= '1'; 
            elsif(tc_tx_bits_flag = '1') then
               ena_shift_register <= '0';
               ena_TxBits_cnt_ctl <= '0';          
            end if;
            --ena_shift_register, poner dentro del else si no funciona
            dataRd_flag_d <= '0';
        when stEofTx =>
            ena_transmiting_cnt_ctl <= '0';
            ena_TxBits_cnt_ctl <= '0';
            ena_shift_register <= '0';
            dataRd_flag_d <= '1';               
        when others =>
           ena_transmiting_cnt_ctl <= '0';
           ena_TxBits_cnt_ctl <= '0';
           ena_shift_register <= '0';
           dataRd_flag_d <= '0';
    end case;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, sck_falling_edge_flag, tc_tx_bits_flag)
begin
    next_state <= state;
    case state is
        when stIdle =>
            if(sck_falling_edge_flag = '1') then
                next_state <= stTransmitingBits;
            else
                next_state <= stIdle;
            end if;
        when stTransmitingBits =>
            if(tc_tx_bits_flag = '1') then               
                next_state <= stEofTx;
            else
                next_state <= stTransmitingBits;
            end if;           
        when stEofTx =>
            next_state <= stIdle;
        when others =>
            next_state <= stIdle;               
    end case;
end process;

end Behavioral;
