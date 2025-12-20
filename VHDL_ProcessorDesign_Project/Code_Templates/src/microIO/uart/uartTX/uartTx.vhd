----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor UartTx System with I/O
-- Module Name: uartTx - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Transmisor UART. Convierte datos paralelos en una trama serie (Start, Data, Stop)
-- utilizando una FSM y un registro de desplazamiento con dirección seleccionable.
-- ENG: UART Transmitter. Converts parallel data into a serial frame (Start, Data, Stop)
-- using an FSM and a shift register with selectable direction.
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
        dataWr : in std_logic; -- ESP: Inicia la transmisión / ENG: Starts transmission
        dataTx : in std_logic_vector (dataSize - 1 downto 0); -- ESP: Dato paralelo / ENG: Parallel data
        ready : out std_logic; -- ESP: Listo para nuevo dato / ENG: Ready for new data
        tx : out std_logic);   -- ESP: Salida serie / ENG: Serial output
end uartTx;


architecture Behavioral of uartTx is

---------------Signals MDE------------
-- ESP: Estados de la FSM de transmisión
-- ENG: Transmission FSM states
type state_type is (stIdle, stTransmitingBits, stEofTx);
signal state, next_state : state_type;
    
-- ESP: Componentes para el conteo de tiempo (Baud Rate) y bits
-- ENG: Components for timing (Baud Rate) and bit counting
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



-- ESP: Cantidad de pulsos respecto de sysClk, que dura un bit de Tx. En rx si dividimos /2 esa cantidad, podremos samplear a la mitad de la duracion del pulso del dato
-- ENG: Number of pulses relative to sysClk, which lasts for one bit of Rx. If we divide that number by 2, we can sample at half the duration of the data pulse.
constant divisor_transmiting : integer := (sysClk/baudRate)-1;

-- ESP: Componente y Signals de SingleModuleCnt para contar bits enviados,(0..dataSize-1). Abarca bits de start, data, stop
-- ENG: Component and signals of SingleModuleCnt to count sent bits,(0..dataSize-1). It considers bits of start, data and stop.
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

-- ESP: Registro de desplazamiento con dirección configurable (MSB/LSB first)
-- ENG: Shift register with configurable direction (MSB/LSB first)
component myShiftReg_dir is
  generic (
    N : integer := 10                                  
  );
  port (
    clk       : in  std_logic;
    rst       : in  std_logic;
    ena       : in  std_logic;                         
    si        : in  std_logic;                         
    so        : out std_logic;                         
    po        : out std_logic_vector (N - 1 downto 0);
    pl        : in  std_logic;                         
    pi        : in std_logic_vector (N - 1 downto 0);  
    msb_first : in  std_logic);                        
end component;

-- ESP: Señales internas de control y sincronización
-- ENG: Internal control and synchronization signals
signal so_internal : std_logic;         
signal ena_shift_register : std_logic;  
 
signal bitStart: std_logic := '0';
signal bitStop: std_logic := '1'; 
  
signal dataRd_flag_q: std_logic;
signal dataRd_flag_d: std_logic;
	
signal dataTx_Pi_s: std_logic_vector(dataSize+2 - 1 downto 0); -- Trama: Start + Data + Stop
	
component SckRisingAndFallingEdgeDetector is
    Port (  clk : in  std_logic;
            rst : in  std_logic;
              d : in  std_logic;
            ena : in  std_logic;
            --  q : out std_logic;
     risingEdge : out std_logic;
    fallingEdge : out std_logic);
end component;

-- ESP: Señales internas de control y sincronización
-- ENG: Internal control and synchronization signals
signal sck_rising_edge_flag    : std_logic := '0';
signal sck_falling_edge_flag   : std_logic := '0';
	
begin

-- ESP: Instancia del contador para generar el tiempo de bit (Baud Rate)
-- ENG: Counter instance to generate bit timing (Baud Rate)
TransmitingCounter_TxData: myCnt
    generic map ( M => divisor_transmiting )
    port map (  clk => clk,
                rst => rst,
                ena => ena_transmiting_cnt_ctl,
          salidaM_2 => open,
            salidaM => flag_transmiting_cnt_M
    );

-- ESP: Instancia del contador de bits enviados
-- ENG: Sent bits counter instance
TxBitsCounter: mySingleModuleCnt 
     generic map( N => N_TX_BITS_COUNTER )
     port map ( clk => clk,
                rst => rst,
                ena => ena_TxBits_cnt_ctl,
                  p => P_VAL_TX_BITS,              
    counting_status => tc_tx_bits_flag
    ); 
    
-- ESP: Registro de desplazamiento para la salida serial
-- ENG: Shift register for serial output           
TxDataRegister: myShiftReg_dir 
  generic map ( N => dataSize+2)                
  port map(   clk => clk,
              rst => rst,
              ena => ena_shift_register,                                       
              si  => '1',                       
              so  => so_internal,                                                 
              po => open,
              pi => dataTx_Pi_s,
              pl => dataWr,
              msb_first => '1'                  -- '1' MSB-first, '0' LSB-first           
  );

-- ESP: Si el estado es idle, tx es '1'. Si no, toma el valor de la salida del registro.
-- ENG: If stIdle, tx is '1'. If not, it takes the register output value. 
tx <= '1' when state = stIdle else so_internal;       
           
-- ESP: Construcción de la trama (Bit inicio '0' y Bit parada '1')
-- ENG: Frame construction (Start bit '0' and Stop bit '1') 
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

-- ESP: Proceso secuencial de la FSM. Moore type.
-- ENG: FSM sequential process. Moore type.
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

-- ESP: Lógica combinacional de estados y salidas
-- ENG: Combinational state and output logic
logicaSalida: process (state, sck_falling_edge_flag, flag_transmiting_cnt_M, tc_tx_bits_flag)
begin
-- Default values
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

-- ESP: Lógica de estado futuro
-- ENG: Next state logic
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
