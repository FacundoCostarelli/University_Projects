----------------------------------------------------------------------------------
-- Company: National Technological University of Buenos Aires (UTN BA)
-- Engineer: Facundo Costarelli
-- 
-- Create Date: 2025
-- Design Name: Microprocessor Control Unit System with I/O
-- Module Name: uc - Behavioral
-- Project Name: Microprocessor Design
-- Description: 
-- ESP: Unidad de Control (UC). Implementa la FSM para decodificar instrucciones,
-- gestionar saltos condicionales y controlar los buses de la ALU, RAM y UART.
-- ENG: Control Unit (UC). Implements the FSM to decode instructions, manage
-- conditional jumps, and control ALU, RAM, and UART buses.
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity uc is
    generic (   DATA_BITS: integer := 16;
                UART_DATA_BITS: integer := 8);
     Port ( clk : in std_logic;
            rst : in std_logic;
            portRd : in std_logic_vector (DATA_BITS - 1 downto 0);
            portWr : out std_logic_vector (DATA_BITS - 1 downto 0);
            portWrEna : out std_logic;
            uartDataWr   : out  std_logic;
            uartDataTx   : out std_logic_vector (UART_DATA_BITS - 1 downto 0);
            uartDataRx   : in std_logic_vector (UART_DATA_BITS - 1 downto 0);
            aluEna : out std_logic;
            aluCode: out std_logic_vector (3 downto 0);
            aluOp : out std_logic_vector (DATA_BITS - 1 downto 0);
            aluAcc : in std_logic_vector (DATA_BITS - 1 downto 0);
            aluZero : in std_logic;
            aluOverflow : in std_logic;
            aluCarryBorrow : in std_logic;
            aluNegative : in std_logic;
            pcEna : out std_logic;
            pcPl : out std_logic;
            pcPlAddr : out std_logic_vector (DATA_BITS - 1 downto 0);
            pcData: in std_logic_vector (31 downto 0));
end uc;

architecture Behavioral of uc is

-- ESP: Componente de Memoria RAM interna para almacenamiento de datos
-- ENG: Internal RAM Memory component for data storage
    component ramMem is
        Port ( clka : in std_logic;
               wea : in std_logic_vector (0 downto 0);
               addra : in std_logic_vector (9 downto 0);
               dina : in std_logic_vector (DATA_BITS - 1 downto 0);
               douta : out std_logic_vector (DATA_BITS - 1 downto 0));
    end component;
    signal ramAddr: std_logic_vector (9 downto 0);
    signal ramDataWr: std_logic_vector (DATA_BITS - 1 downto 0);
    signal ramDataRd: std_logic_vector (DATA_BITS - 1 downto 0);
    signal ramWea: std_logic_vector (0 downto 0);
    signal uartRx: std_logic_vector (DATA_BITS - 1 downto 0);
    
-- ESP: Definición de estados de la FSM (Unidad de Control)
-- ENG: FSM state definitions (Control Unit)     
    type state_type is (stIdle, stStart, stPCUpdate, stPCUpdateFinish, stNOP, stALU, stMOVwp,stMOVr, stMOVwu, stJMP, stJMPCondZ, stJMPCondOv, stJMPCondCB, stJMPCondN, stJMPStop);
    signal state, next_state : state_type;
begin
    
-- ESP: Proceso secuencial para la actualización del estado
-- ENG: Sequential process for state update
    estadoProc: process (clk)
    begin
        if rising_edge(clk) then
            if rst = '1' then
                state <= stStart;
            else
                state <= next_state;
            end if;
        end if;
    end process;

-- ESP: Lógica de salida combinacional (Control de señales de habilitación)
-- ENG: Combinational output logic (Control of enable signals)
    logicaSalida: process (state, aluZero, aluOverflow, aluCarryBorrow, aluNegative)
    begin
    -- Default values
        pcEna <= '0';
        pcPl <= '0';
        aluEna <= '0';
        ramWea <= (others => '0');
        portWrEna <= '0';
        uartDataWr <= '0';
        case state is
            when stStart =>
                pcPl <= '1';
            when stIdle =>
                null;
            when stALU =>
                aluEna <= '1';
            when stMOVwu =>
                uartDataWr <= '1';
            when stMOVr =>
                ramWea <= "1";
            when stMOVwp =>
                portWrEna <= '1';
            when stJMP =>
                pcPl <= '1';
            when stJMPCondZ =>
                if(aluZero = '1') then
                    pcPl <= '1';
                end if;
            when stJMPCondOv =>
                if(aluOverflow = '1') then
                    pcPl <= '1';
                end if;
            when stJMPCondCB =>
                if(aluCarryBorrow = '1') then
                    pcPl <= '1';
                end if;
            when stJMPCondN =>
                if(aluNegative = '1') then
                    pcPl <= '1';
                end if;
            when stJMPStop =>
                pcPl <= '0';
            when stNOP =>
                null; 
            when stPCUpdate =>
                pcEna <= '1';
            when stPCUpdateFinish =>
                pcEna <= '0';
            when others =>
                null;
        end case;
    end process;
    
-- ESP: Lógica de estado siguiente (Decodificación de instrucciones)
-- ENG: Next state logic (Instruction decoding)
    logicaEstadoFuturo: process (state, pcData, aluZero, aluOverflow, aluCarryBorrow, aluNegative) -- Cambio metido el 14/10/2025 a las 21:40, agregue aluZero a la lista de sensibilidad
    begin
        case state is
            when stStart =>
                next_state <= stIdle;
            when stIdle =>
                if pcData(22 downto 21) = "01" then -- Alu op
                    next_state <= stALU;
                elsif pcData(22 downto 21) = "10" then -- Control Flow
                    if pcData(20 downto 17) = "0000" then
                        next_state <= stJMPCondZ;
                    elsif pcData(20 downto 17) = "0001" then
                        next_state <= stJMPCondOv;
                    elsif pcData(20 downto 17) = "0010" then
                        next_state <= stJMPCondCB;
                    elsif pcData(20 downto 17) = "0011" then
                        next_state <= stJMPCondN;
                    elsif pcData(20 downto 17) = "0100" then
                        next_state <= stJMP;
                    else
                        next_state <= stJMP;
                    end if;
                elsif pcData(22 downto 21) = "11" then -- Memory I/O
                    if pcData(20 downto 17) = "0000" or pcData(20 downto 17) = "0001" or pcData(20 downto 17) = "0010" or pcData(20 downto 17) = "0011" then
                        next_state <= stMOVr;
                    elsif pcData(20 downto 17) = "0100" then
                        next_state <= stMOVwp; -- Port
                    else
                        next_state <= stMOVwu; -- Uart
                    end if;
                elsif pcData(22 downto 21) = "00" then
                    next_state <= stNOP;
                else
                    next_state <= stIdle;
                end if;
            when stALU =>
                next_state <= stPCUpdate;
            when stMOVr =>
                next_state <= stPCUpdate;
            when stMOVwp =>
                next_state <= stPCUpdate;
            when stMOVwu =>
                next_state <= stPCUpdate;
            when stJMP =>
                next_state <= stJMPStop;
            when stJMPCondZ => 
                if(aluZero = '1') then
                    next_state <= stJMPStop; 
                else
                    next_state <= stPCUpdate; 
                end if;
            when stJMPCondOv =>
                if(aluOverflow = '1') then
                    next_state <= stJMPStop;
                else
                    next_state <= stPCUpdate;
                end if;
            when stJMPCondCB =>
                if(aluCarryBorrow = '1') then
                    next_state <= stJMPStop;
                else
                    next_state <= stPCUpdate;
                end if;
            when stJMPCondN =>
                if(aluNegative = '1') then
                    next_state <= stJMPStop;
                else
                    next_state <= stPCUpdate;
                end if;
                next_state <= stJMPStop;
            when stJMPStop =>
                next_state <= stIdle;
               -- next_state <= stPCUpdate; 
            when stNOP =>
                next_state <= stPCUpdate;
           when stPCUpdate =>
                next_state <= stPCUpdateFinish;
            when stPCUpdateFinish =>
                next_state <= stIdle;
            when others =>
                next_state <= stStart;
        end case;
    end process;

    ramMem_inst : ramMem
    port map (
        clka => clk,       
        wea => ramWea,         
        addra => ramAddr,      
        dina => ramDataWr,        
        douta => ramDataRd       
    );
    
    -- ESP: Asignaciones de Uart
    -- ENG: Uart assignments
    uartRx(DATA_BITS - 1 downto UART_DATA_BITS) <= (others => '0');
    uartRx(UART_DATA_BITS - 1 downto 0) <= uartDataRx;
    
    -- ESP: Asignaciones de buses y selección de operandos
    -- ENG: Bus assignments and operand selection
    aluCode <= pcData(20 downto 17);
    ramAddr <= pcData(9 downto 0); 
    aluOp <= ramDataRd when pcData(16) = '0' else pcData(15 downto 0); 
    portWr <= ramDataRd when pcData(16) = '0' else pcData(15 downto 0); 
    
    -- ESP: Selección de fuente de datos para escritura en RAM
    -- ENG: Data source selection for RAM write
    ramDataWr <=    portRd when pcData(18 downto 17) = "00" else 
                    uartRx when pcData(18 downto 17) = "01" else
                    aluAcc when pcData(18 downto 17) = "10" else
                    (others => '0');
    
                     
    pcPlAddr <= ramDataRd when pcData(16) = '0' else pcData(15 downto 0); 
    uartDataTx <= ramDataRd(UART_DATA_BITS - 1 downto 0) when pcData(16) = '0' else pcData(UART_DATA_BITS - 1 downto 0); 
end Behavioral;

