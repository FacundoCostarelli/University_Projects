----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor UartRx System with I/O
-- Module Name: uartRx - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Receptor UART. Implementa la norma RS-232 para recibir datos de 8 bits. 
-- Utiliza un detector de flancos para el bit de inicio y sincroniza el muestreo 
-- a la mitad del bit (Baud Rate 9600 bps por defecto).
-- ENG: UART Receiver. Implements RS-232 standard to receive 8-bit data. 
-- It uses an edge detector for the start bit and synchronizes sampling 
-- at the center of the bit (Default 9600 bps Baud Rate).
----------------------------------------------------------------------------------

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
               dataRd : out std_logic; -- ESP: Pulso de dato recibido / ENG: Data received pulse
               dataRx : out std_logic_vector (dataSize - 1 downto 0); -- ESP: Dato paralelo / ENG: Parallel data
                   rx : in std_logic); -- ESP: Entrada serie física / ENG: Physical serial input
end uartRx;

architecture Behavioral of uartRx is

-- ESP: Estados de la FSM de recepción
-- ENG: Reception FSM states
type state_type is (stIdle, stReceiveBits, stEofRx);
signal state, next_state : state_type;
    
-- ESP: Componentes de conteo y detección de flancos
-- ENG: Counting and edge detection components   
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

 -- ESP: Cantidad de pulsos respecto de sysClk, que dura un bit de Rx. Si dividimos /2 esa cantidad, podremos samplear a la mitad de la duracion del pulso del dato
 -- ENG: Number of pulses relative to sysClk, which lasts for one bit of Rx. If we divide that number by 2, we can sample at half the duration of the data pulse.
constant divisor_sampling : integer := (sysClk/baudRate)-1;
 
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

constant N_RX_BITS_COUNTER : integer := integer(ceil(log2(real(dataSize+1))));
signal divisor_rx_bits : integer := dataSize+1;-- 1 Start bit + 8 data bits + 1 Stop Bit
signal P_VAL_RX_BITS : std_logic_vector(N_RX_BITS_COUNTER-1 downto 0) := std_logic_vector(to_unsigned(divisor_rx_bits, N_RX_BITS_COUNTER));

signal ena_RxBits_cnt_ctl: std_logic := '0';
signal tc_rx_bits_flag: std_logic := '0';

-- ESP: Registro de desplazamiento con dirección configurable (MSB/LSB first)
-- ENG: Shift register with configurable direction (MSB/LSB first)   
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

-- ESP: Señales internas de control y sincronización
-- ENG: Internal control and synchronization signals        
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

-- ESP: Contador de muestreo: salidaM_2 permite samplear a mitad del bit
-- ENG: Sampling counter: salidaM_2 allows sampling at the center of the bit            
SamplingCounter_RxData: myCnt
    generic map ( M => divisor_sampling )
    port map (  clk => clk,
                rst => rst,
                ena => ena_sampling_cnt_ctl,
          salidaM_2 => flag_sampling_cnt_M2,
            salidaM => flag_sampling_cnt_M
    );
    
-- ESP: Contador de bits de la trama (Start + Data + Stop)
-- ENG: Frame bit counter (Start + Data + Stop)    
RxBitsCounter: mySingleModuleCnt 
     generic map( N => N_RX_BITS_COUNTER )
     port map ( clk => clk,
                rst => rst,
                ena => ena_RxBits_cnt_ctl,
                  p => P_VAL_RX_BITS,              
    counting_status => tc_rx_bits_flag
    ); 

-- ESP: Registro de desplazamiento para reconstrucción paralelo del dato
-- ENG: Shift register for parallel data reconstruction
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
-- ESP: Detector de flanco de bajada para identificar el Bit de Inicio (Start bit)
-- ENG: Falling edge detector to identify the Start Bit          
sckEdgeDetector: SckRisingAndFallingEdgeDetector
port map (
  clk        => clk,
  rst        => rst,
  d          => rx,
  ena        => '1',
  risingEdge => sck_rising_edge_flag,
  fallingEdge=> sck_falling_edge_flag
);          

-- ESP: Registro que almacena el valor del flag de dataRd_flag
-- ENG: Register that saves the dataRd_flag value of the flag
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

-- ESP: Regitro que almacena la data Rx recibida por un registro de desplazamiento en su salida.
-- ENG: Register that saves the Rx data received by a shift register output.
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

-- ESP: Proceso secuencial para actualización de estado y banderas
-- ENG: Sequential process for state and flag updates
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

-- ESP: Lógica combinacional de salidas de control (MDE Moore)
-- ENG: Combinational control output logic (Moore FSM)
logicaSalida: process (state, sck_falling_edge_flag, flag_sampling_cnt_M2, tc_rx_bits_flag)
begin
-- Default values
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
             -- ESP: Habilita el desplazamiento solo a mitad del bit para mayor estabilidad
             -- ENG: Enables shifting only at bit center for better stability
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

-- ESP: Lógica de transición de estados basada en eventos de tiempo y bits
-- ENG: State transition logic based on timing and bit events
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
