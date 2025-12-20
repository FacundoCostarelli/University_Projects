----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.08.2025 21:41:49
-- Design Name: 
-- Module Name: uartRx - Behavioral
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


-- RECEPTOR DE LA UART (Universal Asynchronous Receiver/ Transmitter). RECIBE DATA DE 8 BITS, 
-- 1 BIT DE START, 1 BIT STOP, SIN BIT DE PARIDAD. USA UN UNICO RELOJ. BAUD RATE = 9600 BPS DEFAULT.
-- La norma utilizada es RS-232
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.math_real.all;

entity uartRx is
    Generic (baudRate : integer := 9600;
               sysClk : integer := 100000000;
             dataSize : integer := 8);
    Port (        clk : in std_logic;
                  rst : in std_logic;
               dataRd : out std_logic;
               dataRx : out std_logic_vector (dataSize - 1 downto 0);
                   rx : in std_logic);
end uartRx;

architecture Behavioral of uartRx is

---------------Signals MDE------------
type state_type is (stIdle, stReceiveBits, stEofRx);
-- NOTA: stIdle = Estado de Idle
-- NOTA: stReceiveBits = Estado de recibiendo bits
-- NOTA: stEofRx = Estado de fin de recepción de bits
signal state, next_state : state_type;
    
--------------Component y Signals de cnt de pulsos de sampling---------------    
component myCnt is
    Generic (M : integer := 100);
    Port ( clk : in std_logic;
           rst : in std_logic;
           ena : in std_logic;
     salidaM_2 : out std_logic;
       salidaM : out std_logic);
end component;

signal flag_sampling_cnt_M  : std_logic;
signal flag_sampling_cnt_M2 : std_Logic;
signal ena_sampling_cnt_ctl : std_logic;

 -- Cantidad de pulsos respecto de sysClk, que dura un bit de Rx. Si dividimos /2 esa cantidad, podremos samplear a la mitad de la duracion del pulso del dato
constant divisor_sampling : integer := (sysClk/baudRate)-1;
 
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

constant N_RX_BITS_COUNTER : integer := integer(ceil(log2(real(dataSize+1))));
signal divisor_rx_bits : integer := dataSize+1;-- 1 Start bit + 8 data bits + 1 Stop Bit
signal P_VAL_RX_BITS : std_logic_vector(N_RX_BITS_COUNTER-1 downto 0) := std_logic_vector(to_unsigned(divisor_rx_bits, N_RX_BITS_COUNTER));

signal ena_RxBits_cnt_ctl: std_logic := '0';
signal tc_rx_bits_flag: std_logic := '0';
  
--------------Component y Signals de registro de desplazamiento para guardar dato de Rx---------------    
component myShiftReg is
    Generic (N: integer := 4);
    Port ( clk : in std_logic;
           rst : in std_logic; 
           ena : in std_logic;
           si : in std_logic;
           so : out std_logic;
           po : out std_logic_vector (N - 1 downto 0);
           pi : in std_logic_vector (N - 1 downto 0); 
           pl : in std_logic);
end component;    
        
signal ena_shift_register : std_logic;  
signal registroRx         : std_logic_vector(dataSize+2 - 1 downto 0);

  
signal dataRd_flag_q: std_logic;
signal dataRd_flag_d: std_logic;
signal dataRx_s: std_logic_vector(dataSize - 1 downto 0);

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
            
SamplingCounter_RxData: myCnt
    generic map ( M => divisor_sampling )
    port map (  clk => clk,
                rst => rst,
                ena => ena_sampling_cnt_ctl,
          salidaM_2 => flag_sampling_cnt_M2,
            salidaM => flag_sampling_cnt_M
    );
    
RxBitsCounter: mySingleModuleCnt 
     generic map( N => N_RX_BITS_COUNTER )
     port map ( clk => clk,
                rst => rst,
                ena => ena_RxBits_cnt_ctl,
                  p => P_VAL_RX_BITS,              
    counting_status => tc_rx_bits_flag
    ); 

-- Dato rx entra de LSB a MSB tal que al ir desplazandose queda el LSB en el registro mas a la derecha
-- mientras que el MSB queda en el registro mas a la izquierda
RxDataRegister: myShiftReg 
    generic map (N => dataSize+2)
    port map ( clk => clk,
               rst => rst,
               ena => ena_shift_register,
                si => rx,
                so => open,
                po => registroRx,
                pi => (others => '0'),
                pl => '0'
           );
          
sckEdgeDetector: SckRisingAndFallingEdgeDetector
port map (
  clk        => clk,
  rst        => rst,
  d          => rx,
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

DataRxRegisterOutput: process(clk)
begin
    if(rising_edge(clk)) then
        if(rst = '1') then
            dataRx_s <= (others => '0');    
        elsif(dataRd_flag_q = '1') then
            dataRx_s <= registroRx(dataSize downto 1);
        end if;
    end if;
end process;

--------------------------------------RX MDE, TIPO MOORE, la salida NO depende de la entrada------------------------------------------------------ 
----------------------------------PARTE SECUENCIAL------------------------------------------------
estadoProc: process (clk)
begin
    if (rising_edge (clk)) then
        if (rst = '1') then
            state  <= stIdle;
            dataRx <= (others=>'0');
            dataRd <= '0';
        else
            state  <= next_state;
            dataRx <= dataRx_s;
            dataRd <= dataRd_flag_q;
        end if;
    end if;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO ACTUAL Y SALIDA------------------------------------------------
logicaSalida: process (state, sck_falling_edge_flag, flag_sampling_cnt_M2, tc_rx_bits_flag)
begin

ena_sampling_cnt_ctl <= '0';
ena_RxBits_cnt_ctl <= '0';
ena_shift_register <= '0';
dataRd_flag_d <= '0';

    case (state) is   
        when stIdle =>                                 
            ena_shift_register <= '0';
            dataRd_flag_d <= '0';     
            if(sck_falling_edge_flag = '1') then               
                ena_sampling_cnt_ctl <= '1';
                ena_RxBits_cnt_ctl <= '0';
            end if;                    
        when stReceiveBits =>  
             ena_sampling_cnt_ctl <= '1';
             if(flag_sampling_cnt_M2 = '1' and tc_rx_bits_flag = '0') then
                ena_shift_register <= '1';               
                ena_RxBits_cnt_ctl <= '1';               
             elsif(tc_rx_bits_flag = '1') then
                ena_shift_register <= '0';
                ena_RxBits_cnt_ctl <= '0';
             end if;            
             dataRd_flag_d <= '0';                    
        when stEofRx =>        
               ena_RxBits_cnt_ctl <= '0';            
               ena_shift_register <= '0'; 
               ena_sampling_cnt_ctl <= '0';              
               dataRd_flag_d <= '1';                            
        when others =>
            ena_sampling_cnt_ctl <= '0';
            ena_RxBits_cnt_ctl <= '0';
            ena_shift_register <= '0';
            dataRd_flag_d <= '0';           
        end case;
end process;

----------------------------------PARTE COMBINACIONAL ESTADO FUTURO------------------------------------------------
logicaEstadoFuturo: process (state, sck_falling_edge_flag, tc_rx_bits_flag)
begin
    next_state <= state;
    case (state) is
        when stIdle =>
            if(sck_falling_edge_flag = '1') then
                next_state <= stReceiveBits;
            else
                next_state <= stIdle;
            end if;
        when stReceiveBits =>
            if(tc_rx_bits_flag = '1') then               
                next_state <= stEofRx;
            else
                next_state <= stReceiveBits;
            end if;           
        when stEofRx =>
                next_state <= stIdle;
        when others =>
            next_state <= stIdle;
        end case;    
end process;            

end Behavioral;
