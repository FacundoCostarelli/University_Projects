/*
 * I2C.cpp
 *
 *  Created on: January 2023
 *      Author: Luca Rimondini.
 */


#include "I2C.h"

/* ESP
 * @brief Matriz de índices IOCON para los pines de los puertos PIO0 y PIO1.
 *        Esta matriz permite mapear los pines físicos a sus respectivos registros IOCON.
 */

/* ENG
 * @brief IOCON index matrix for PIO0 and PIO1 pins.
 *        This matrix maps physical pins to their respective IOCON registers.
 */

uint8_t IOCON_INDEX[2][32] = {
    {IOCON_INDEX_PIO0_0,  IOCON_INDEX_PIO0_1,  IOCON_INDEX_PIO0_2,  IOCON_INDEX_PIO0_3,
     IOCON_INDEX_PIO0_4,  IOCON_INDEX_PIO0_5,  IOCON_INDEX_PIO0_6,  IOCON_INDEX_PIO0_7,
     IOCON_INDEX_PIO0_8,  IOCON_INDEX_PIO0_9,  IOCON_INDEX_PIO0_10, IOCON_INDEX_PIO0_11,
     IOCON_INDEX_PIO0_12, IOCON_INDEX_PIO0_13, IOCON_INDEX_PIO0_14, IOCON_INDEX_PIO0_15,
     IOCON_INDEX_PIO0_16, IOCON_INDEX_PIO0_17, IOCON_INDEX_PIO0_18, IOCON_INDEX_PIO0_19,
     IOCON_INDEX_PIO0_20, IOCON_INDEX_PIO0_21, IOCON_INDEX_PIO0_22, IOCON_INDEX_PIO0_23,
     IOCON_INDEX_PIO0_24, IOCON_INDEX_PIO0_25, IOCON_INDEX_PIO0_26, IOCON_INDEX_PIO0_27,
     IOCON_INDEX_PIO0_28, IOCON_INDEX_PIO0_29, IOCON_INDEX_PIO0_30, IOCON_INDEX_PIO0_31},
    {IOCON_INDEX_PIO1_0,  IOCON_INDEX_PIO1_1,  IOCON_INDEX_PIO1_2,  IOCON_INDEX_PIO1_3,
     IOCON_INDEX_PIO1_4,  IOCON_INDEX_PIO1_5,  IOCON_INDEX_PIO1_6,  IOCON_INDEX_PIO1_7,
     IOCON_INDEX_PIO1_8,  IOCON_INDEX_PIO1_9,  IOCON_INDEX_PIO1_10, IOCON_INDEX_PIO1_11,
     IOCON_INDEX_PIO1_12, IOCON_INDEX_PIO1_13, IOCON_INDEX_PIO1_14, IOCON_INDEX_PIO1_15,
     IOCON_INDEX_PIO1_16, IOCON_INDEX_PIO1_17, IOCON_INDEX_PIO1_18, IOCON_INDEX_PIO1_19,
     IOCON_INDEX_PIO1_20, IOCON_INDEX_PIO1_21}};




/* ESP
 * @brief Vector global que almacena punteros a instancias de I2C para cada periférico I2C disponible.
 *        Permite manejar múltiples instancias de I2C.
 */

/* ENG
 * @brief Global vector storing pointers to I2C instances for each available I2C peripheral.
 *        Allows handling multiple I2C instances.
 */

I2C *g_I2CVector[4] = {nullptr, nullptr, nullptr, nullptr};

// ESP: Variables globales para el manejo de I2C
// ENG: Global variables to manage I2C


// ESP: Indica si hay una operación de escritura en curso.
// ENG: Indicates if a write operation is in progress
bool m_FlagWrite;

// ESP: Indica si hay una operación de lectura en curso.
// ENG: Indicates if a read operation is in progress.
bool m_FlagRead;

// ESP: Puntero al periférico I2C.
// ENG: Pointer to the I2C peripheral.
I2C_Type* m_I2C;

// ESP: Indica si hubo un error en la configuración.
// ENG: Indicates if there was an error in the configuration.
bool m_Error;

// ESP: Indica si se recibió un NACK en la comunicación.
// ENG: Indicates if a NACK was received in the communication.
bool m_NACK;

// ESP: Número de bytes a leer o escribir.
// ENG: Number of bytes to read or write.
uint8_t m_Bytes;

// ESP: Dirección del esclavo I2C.
// ENG: I2C slave address.
uint8_t m_SlaveAddress;

// ESP: Buffer circular para almacenar datos leídos.
// ENG: Circular buffer to store read data.
uint8_t* m_BufferRead;

// ESP: Índice de entrada para el buffer de lectura.
// ENG: Input index for the read buffer.
uint32_t m_IndexReadIn;

// ESP: Índice de salida para el buffer de lectura.
// ENG: Output index for the read buffer.
uint32_t m_IndexReadOut;

// ESP: Tamaño máximo del buffer de lectura.
// ENG: Maximum size of the read buffer.
uint32_t m_MaxRead;

// ESP: Buffer circular para almacenar datos a escribir.
// ENG: Circular buffer to store data to write.
uint8_t* m_BufferWrite;

// ESP: Índice de entrada para el buffer de escritura.
// ENG: Input index for the write buffer.
uint32_t m_IndexWriteIn;

// ESP: Índice de salida para el buffer de escritura.
// ENG: Output index for the write buffer.
uint32_t m_IndexWriteOut;

// ESP: Tamaño máximo del buffer de escritura.
// ENG: Maximum size of the write buffer.
uint32_t m_MaxWrite;

// ESP: Modo de operación (maestro o esclavo).
// ENG: Operation mode (master or slave).
mode_t m_Mode;




/* ESP
 * @brief Constructor de la clase I2C.
 *        Configura los pines, buffers y el modo de operación del periférico I2C.
 *
 * @param portSCL Puerto para la línea SCL.
 * @param pinSCL  Pin para la línea SCL.
 * @param portSDA Puerto para la línea SDA.
 * @param pinSDA  Pin para la línea SDA.
 * @param i2c     Puntero al periférico I2C.
 * @param mode    Modo de operación (maestro o esclavo).
 * @param slaveAddress Dirección del esclavo en caso de modo esclavo.
 */

/* ENG
 * @brief Constructor of the I2C class.
 *        Configures pins, buffers, and the operation mode of the I2C peripheral.
 *
 * @param portSCL Port for the SCL line.
 * @param pinSCL  Pin for the SCL line.
 * @param portSDA Port for the SDA line.
 * @param pinSDA  Pin for the SDA line.
 * @param i2c     Pointer to the I2C peripheral.
 * @param mode    Operation mode (master or slave).
 * @param slaveAddress Slave address in case of slave mode.
 */

I2C::I2C(uint8_t portSCL, uint8_t pinSCL, uint8_t portSDA, uint8_t pinSDA, I2C_Type *i2c,
         mode_t mode, uint8_t slaveAddress) {
	// ESP: Tamaño máximo del buffer de lectura y escritura.
	// ENG: Maximum size of the read and write buffers.
    m_MaxRead = 64;
    m_MaxWrite = 64;

    // ESP: Crea los buffers de lectura y escritura.
    // ENG: Creates the read and write buffers.
    m_BufferRead = new uint8_t[m_MaxRead];
    m_BufferWrite = new uint8_t[m_MaxWrite];

    // ESP: Inicializa los índices de los buffers.
    // ENG: Initializes the buffer indices.
    m_IndexReadIn = m_IndexReadOut = m_IndexWriteIn = m_IndexWriteOut = 0;

    // ESP: Inicializa el contador de solicitudes no respondidas.
    // ENG: Initializes the counter for unanswered requests.
    m_NoAnsweredRequests = 0;
    m_MaxNoAnsweredRequests = 4;

    // ESP: Verifica si el periférico ya está asignado para no sobrescribirlo.
    // ENG: Checks if the peripheral is already assigned to avoid overwriting.
    m_Error = !(
        (i2c == I2C0 && g_I2CVector[0] == nullptr) || (i2c == I2C1 && g_I2CVector[1] == nullptr) ||
        (i2c == I2C2 && g_I2CVector[2] == nullptr) || (i2c == I2C3 && g_I2CVector[3] == nullptr));

    if (!m_Error) {
    	// ESP: Inicializa las banderas y variables de estado.
    	// ENG: Initializes flags and state variables.
        m_FlagWrite = false;
        m_FlagRead = false;
        m_NACK = false;
        m_Bytes = 0;
        m_I2C = i2c;
        m_Mode = mode;

        // ESP: Configura los pines SCL y SDA según el periférico I2C.
        // ENG: Configures SCL and SDA pins based on the I2C peripheral.
        m_PortSCL = (m_I2C != I2C0) ? portSCL : 0;
        m_PinSCL = (m_I2C != I2C0) ? pinSCL : 10;
        m_PortSDA = (m_I2C != I2C0) ? portSDA : 0;
        m_PinSDA = (m_I2C != I2C0) ? pinSDA : 11;
        m_SlaveAddress = slaveAddress;


        // ESP: Asigna la instancia actual al vector global correspondiente.
        // ENG: Assigns the current instance to the corresponding global vector.
        if (m_I2C == I2C0)
            g_I2CVector[0] = this;
        else if (m_I2C == I2C1)
            g_I2CVector[1] = this;
        else if (m_I2C == I2C2)
            g_I2CVector[2] = this;
        else if (m_I2C == I2C3)
            g_I2CVector[3] = this;


        // ESP: Configuración específica para I2C0.
        // ENG: Specific configuration for I2C0.
        if (m_I2C == I2C0) {
            ConfiguracionI2C0();
        } else {
        	// ESP: Limpia los presets, habilita los clocks y asigna los pines.
        	// ENG: Clears presets, enables clocks, and assigns pins.
            ClearPresets();
            EnableClocks();
            AssignPins();

            // ESP: Configura el modo de operación (maestro o esclavo).
            // ENG: Configures the operation mode (master or slave).
            if (m_Mode == master)
                SetUpMaster();
            else if (m_Mode == slave)
                SetUpSlave();
        }

        // ESP: Habilita las interrupciones NVIC.
        // ENG: Enables NVIC interrupts.
        EnableNvicInterrupt();
    }
}




/* ESP
 * @brief Configura los pines del periférico I2C para el puerto 0 (I2C0).
 *        Configura el clock, pines y resets necesarios.
 */

/* ENG
 * @brief Configures the I2C peripheral pins for port 0 (I2C0).
 *        Configures the clock, pins, and necessary resets.
 */

void I2C::ConfiguracionI2C0() {

	// ESP: Configuracion de I2C. El orden de pasos de configuracion del periferico I2C0 es importante.
    // ENG: Configuration of I2C: The steps order during the configuration of the I2C0 register, is very important.


	// ESP: 1. Habilita y selecciona los pines para SDA y SCL.
	// ENG: 1. Enables and selects pins for SDA and SCL.
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);  // ESP: Limpio bit 7. ENG: Clean the 7th bit.
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);   // ESP: Habilito clock de la Switch Matrix. ENG: Enable clock of the Switch Matrix.

    SWM0->PINENABLE0 &= ~(1 << 12) & ~(1 << 13);  // ESP: Habilito pines P0.10 y P0.11 para SDA y SCL. ENG: Enable pins P0.10 and P0.11 related to SDA and SCL.

    IOCON->PIO[IOCON_INDEX_PIO0_10] &=
        ~(11 << 8);  // ESP: Configuro PIO0_10 como Standard Mode I2C. I2C0_SCL. ENG: Configure PIO0_10 as Standard Mode I2C for the I2C0_SCL.
    IOCON->PIO[IOCON_INDEX_PIO0_11] &=
        ~(11 << 8);  // ESP: Configuro PIO0_11 como Standard Mode I2C. I2C0_SDA. ENG: Configure PIO0_11 as Standard Mode I2C for the I2C0_SDA.

    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);  // ESP: Apago el clock de la Switch Matrix. ENG: Turn off the Switch Matrix clock.

    // ESP: 2. Selecciona el clock rate del pin SCL del módulo I2C0.
    // ENG: 2. Selects the clock rate for the SCL pin of the I2C0 module.
    SYSCON->FCLKSEL[5] =
    		1;  // ESP: Elijo el clock principal a usar de referencia en los calculos de baudrate del I2C0. ENG: Choose the main clock to use as a reference in the I2C0 baudrate calculations.
    			// ESP: Selecciono main_clk = clock del sistema. Debería ser 30MHz. ENG: Select main_clk = system clock. It should be 30MHz.

    // ESP: Habilita el clk del periférico de I2C.
    // ENG: Enables the clock for the I2C peripheral.
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 5);  // ESP: Limpio el Bit 5. ENG: Clean 5th bit.
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 5);   // ESP: Seteo en 1 el Bit 5. ENG: Set 1 the 5th bit.

    // ESP: 3. Realiza un reset del módulo I2C o periférico.
    // ENG: 3. Resets the I2C module or peripheral.
    SYSCON->PRESETCTRL0 &= ~(1 << 5);  // ESP: Limpio bit 5 del registro PRESETCTRL0. ENG: Clean the 5th bit of the PRESETCTRL0 register.
    SYSCON->PRESETCTRL0 |= (1 << 5);   // ESP: Realizo un reset del periferico. Reset con 1 en bit 5. ENG: Reset the peripheral. Reset with 1 the 5th bit.

    // NVIC->ISER[0] |= 1<<8;
    // I2C0->INTENSET |=1; //master pending
    // I2C0->MSTCTL|=1<<1; //master start bit for I2C

    // ESP: 4. Configura el divisor de clock para el bit rate del I2C.
    // ENG: 4. Configures the clock divider for the I2C bit rate.
    I2C0->CLKDIV = 0x0F;  // ESP: Elijo un divisor de Clock(14) para manejar el bit rate del I2C. ENG: Choose a Clock divisor(14) to manage bit rate of I2C.
                          // ESP: Determina el incremento usado en Msttime. ENG: Determines the Msttime increment.

    I2C0->MSTTIME &= ~(0x07);       // ESP: Limpio bits 0 a 2. ENG: Clean bits 0 to 2.
    I2C0->MSTTIME |= 0x07;          // ESP: Cargo 1 en MSTSCLLOW --> 9 clocks. ENG: Set 1 in MSTSCLLOW --> 9clocks.
    I2C0->MSTTIME &= ~(0x07 << 4);  // ESP: Limpio bits 4 a 6. ENG: Clean bis 4 to 6.
    I2C0->MSTTIME |= (0x07 << 4);   // ESP: Cargo 0 en MSTSCLHIGH --> 9 clocks. ENG: Set 0 in MSTSCLHIGH --> 9 clocks.
    // ESP: En este punto hay un baudrate de 400khz de I2C en SCL. ENG: At this point there should be 400kHz as I2C baudrate for the SCL pin.

    //*************************************************************************************************************************************//
    // ESP: 100kHZ = Standar Mode o 400KHz = Fast Mode. Ver hoja dedatos del sensor. Mas baudrate implica resistencias de pull up mas altas.
    // ENG: 100kHz = Standard Mode, 400kHz = Fast Mode. See the datasheet of the sensor. More baudrate implicates higher pull up resistors.
    //*************************************************************************************************************************************//


    I2C0->CFG |= I2C_CFG_MSTEN(1);  // ESP: Con 1 establezco I2C0 en modo maestro. ENG: With 1 I2C master mode is established.

}




/* ESP
 * @brief Destructor de la clase I2C.
 */

/* ENG
 * @brief Destructor of the I2C class.
 */

I2C::~I2C() {}



/* ESP
 * @brief Asigna los pines al periférico I2C.
 *        Configura los pines SDA y SCL para el funcionamiento del periférico.
 */

/* ENG
 * @brief Assigns pins to the I2C peripheral.
 *        Configures SDA and SCL pins for the peripheral operation.
 */

void I2C::AssignPins() {
	// ESP: Habilita el clock de la Switch Matrix.
	// ENG: Enables the Switch Matrix clock.
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);

    // ESP: Asigna los pines. I2C0 está fijado a PIO0_10 para SCL y PIO0_11 para SDA.
    // ENG: Assigns the pins. I2C0 is fixed on PIO0_10 for SCL and PIO0_11 for SDA.
    if (m_I2C == I2C0)
        SWM0->PINENABLE0 &= ~(1 << 12) & ~(1 << 13);
    else if (m_I2C == I2C1)
        SWM0->PINASSIGN.PINASSIGN9 = (SWM0->PINASSIGN.PINASSIGN9 & 0x0000FFFF) |
                                     ((m_PinSDA + m_PortSDA * 0x20) << 16) |
                                     ((m_PinSCL + m_PortSCL * 0x20) << 24);
    else if (m_I2C == I2C2)
        SWM0->PINASSIGN.PINASSIGN10 = (SWM0->PINASSIGN.PINASSIGN9 & 0xFFFF0000) |
                                      ((m_PinSDA + m_PortSDA * 0x20) << 0) |
                                      ((m_PinSCL + m_PortSCL * 0x20) << 8);
    else if (m_I2C == I2C3)
        SWM0->PINASSIGN.PINASSIGN10 = (SWM0->PINASSIGN.PINASSIGN9 & 0x0000FFFF) |
                                      ((m_PinSDA + m_PortSDA * 0x20) << 16) |
                                      ((m_PinSCL + m_PortSCL * 0x20) << 24);

    // ESP: Configura los pines en modo open-drain si no es I2C0.
    // ENG: Configures pins in open-drain mode if not I2C0.
    if (m_I2C != I2C0) {
        IOCON->PIO[IOCON_INDEX[m_PortSCL][m_PinSCL]] |= IOCON_PIO_OD(1);
        IOCON->PIO[IOCON_INDEX[m_PortSDA][m_PinSDA]] |= IOCON_PIO_OD(1);
    }

    // ESP: Apaga el clock de la Switch Matrix.
    // ENG: Disables the Switch Matrix clock.
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);
}




/* ESP
 * @brief Limpia los presets del periférico I2C.
 *        Realiza un reset del periférico antes de configurarlo.
 */

/* ENG
 * @brief Clears the I2C peripheral presets.
 *        Resets the peripheral before configuration.
 */

void I2C::ClearPresets() {
    if (m_I2C == I2C0) {
        SYSCON->PRESETCTRL0 &= ~(1 << 5);
        SYSCON->PRESETCTRL0 |= (1 << 5);
    } else if (m_I2C == I2C1) {
        SYSCON->PRESETCTRL0 &= ~(1 << 21);
        SYSCON->PRESETCTRL0 |= (1 << 21);
    } else if (m_I2C == I2C2) {
        SYSCON->PRESETCTRL0 &= ~(1 << 22);
        SYSCON->PRESETCTRL0 |= (1 << 22);
    } else if (m_I2C == I2C3) {
        SYSCON->PRESETCTRL0 &= ~(1 << 23);
        SYSCON->PRESETCTRL0 |= (1 << 23);
    }
}




/* ESP
 * @brief Habilita los clocks para el periférico I2C.
 */

/* ENG
 * @brief Enables clocks for the I2C peripheral.
 */

void I2C::EnableClocks() {
    if (m_I2C == I2C0) {
        SYSCON->FCLKSEL[5] = 0;
        SYSCON->SYSAHBCLKCTRL0 |= (1 << 5);
    } else if (m_I2C == I2C1) {
        SYSCON->FCLKSEL[6] = 0;
        SYSCON->SYSAHBCLKCTRL0 |= (1 << 21);
    } else if (m_I2C == I2C2) {
        SYSCON->FCLKSEL[7] = 0;
        SYSCON->SYSAHBCLKCTRL0 |= (1 << 22);
    } else if (m_I2C == I2C3) {
        SYSCON->FCLKSEL[8] = 0;
        SYSCON->SYSAHBCLKCTRL0 |= (1 << 23);
    }

    // ESP: Configura el divisor de clock.
    // ENG: Configures the clock divider.
    m_I2C->CLKDIV = 11;  // ESP: Clock dividido por 12 . ENG: Clock divided by 12.
}




/* ESP
 * @brief Habilita las interrupciones NVIC para el periférico I2C.
 */

/* ENG
 * @brief Enables NVIC interrupts for the I2C peripheral.
 */

void I2C::EnableNvicInterrupt() {
    if (m_I2C == I2C0)
        NVIC->ISER[0] |= (1 << 8);
    else if (m_I2C == I2C1)
        NVIC->ISER[0] |= (1 << 7);
    else if (m_I2C == I2C2)
        NVIC->ISER[0] |= (1 << 21);
    else if (m_I2C == I2C3)
        NVIC->ISER[0] |= (1 << 22);
}




/* ESP
 * @brief Configura el periférico I2C en modo maestro.
 */

/* ENG
 * @brief Configures the I2C peripheral in master mode.
 */

void I2C::SetUpMaster() {
	// ESP: Configura el tiempo de SCL alto y bajo.
	// ENG: Configures SCL high and low time.
    m_I2C->MSTTIME = I2C_MSTTIME_MSTSCLLOW(3) | I2C_MSTTIME_MSTSCLHIGH(3);

    // ESP: Establece el modo maestro.
    // ENG: Sets master mode.
    m_I2C->CFG = I2C_CFG_MSTEN(1);
}




/* ESP
 * @brief Configura el periférico I2C en modo esclavo.
 */

/* ENG
 * @brief Configures the I2C peripheral in slave mode.
 */

void I2C::SetUpSlave() {
	// ESP: Establece el modo esclavo.
	// ENG: Sets slave mode.
    m_I2C->CFG = I2C_CFG_SLVEN(1);

    // ESP: Configura la dirección del esclavo.
    // ENG: Configures the slave address.
    m_I2C->SLVADR[0] = I2C_SLVADR_SLVADR(m_SlaveAddress);
    m_I2C->SLVADR[1] = I2C_SLVADR_SADISABLE(1);
    m_I2C->SLVADR[2] = I2C_SLVADR_SADISABLE(1);
    m_I2C->SLVADR[3] = I2C_SLVADR_SADISABLE(1);

    // ESP: Habilita las interrupciones del esclavo.
    // ENG: Enables slave interrupts.
    m_I2C->INTENSET |= I2C_INTENSET_SLVPENDINGEN(1);
}




/* ESP
 * @brief Maneja una escritura maestro.
 *        Envía datos desde el buffer de escritura.
 */

/* ENG
 * @brief Handles a master write.
 *        Sends data from the write buffer.
 */

void I2C::MasterWrite() {
    if (m_FlagWrite) {
        uint8_t data;
        if (PopWrite(&data)) {
        	// ESP: Escribe 8 bits de datos en el registro de datos maestro.
        	// ENG: Writes 8 bits of data to the master data register.
            m_I2C->MSTDAT = data & 0xFF;

            // ESP: Continúa con la transmisión.
            // ENG: Continues the transmission.
            m_I2C->MSTCTL = I2C_MSTCTL_MSTCONTINUE_MASK;
        } else {
        	// ESP: Deshabilita la interrupción pendiente y detiene la transmisión.
			// ENG: Disables the pending interrupt and stops the transmission.
            DisableMasterPendingInterrupt();
            m_I2C->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;
            m_FlagWrite = false;
        }
    }
}




/* ESP
 * @brief Maneja una lectura maestro.
 *        Recibe datos y los almacena en el buffer de lectura.
 * @param last Indica si este es el último byte de la transmisión.
 */

/* ENG
 * @brief Handles a master read.
 *        Receives data and stores it in the read buffer.
 * @param last Indicates if this is the last byte of the transmission.
 */

void I2C::MasterRead(bool last) {
	// ESP: Lee 8 bits de datos del registro de datos maestro.
	// ENG: Reads 8 bits of data from the master data register.
    uint8_t data = (m_I2C->MSTDAT & I2C_MSTDAT_DATA_MASK) >> I2C_MSTDAT_DATA_SHIFT;

    // ESP: Almacena el dato en el buffer de lectura.
    // ENG: Stores the data in the read buffer.
    PushRead(data);
    m_Bytes--;

    if (!last && m_Bytes)
    	// ESP: Continúa con la transmisión si no es el último byte.
    	// ENG: Continues the transmission if it's not the last byte.
        m_I2C->MSTCTL = I2C_MSTCTL_MSTCONTINUE_MASK;
    else {
    	// ESP: Deshabilita la interrupción pendiente y detiene la transmisión.
    	// ENG: Disables the pending interrupt and stops the transmission.
        DisableMasterPendingInterrupt();
        m_I2C->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;
        m_FlagRead = false;
        m_Bytes = 0;
    }
}




/* ESP
 * @brief Maneja una lectura esclavo.
 *        Recibe datos desde el bus I2C y los almacena en el buffer de lectura.
 */

/* ENG
 * @brief Handles a slave read.
 *        Receives data from the I2C bus and stores it in the read buffer.
 */

void I2C::SlaveRead() {
	// ESP: Lee 8 bits de datos del registro de datos esclavo.
	// ENG: Reads 8 bits of data from the slave data register.
    uint8_t data = (m_I2C->SLVDAT & I2C_SLVDAT_DATA_MASK) >> I2C_SLVDAT_DATA_SHIFT;

    // ESP: Continúa con la transmisión.
    // ENG: Continues the transmission.
    m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;

    // ESP: Almacena el dato en el buffer de lectura.
    // ENG: Stores the data in the read buffer.
    PushRead(data);
}




/* ESP
 * @brief Maneja una escritura esclavo.
 *        Envía datos desde el buffer de escritura al bus I2C.
 */

/* ENG
 * @brief Handles a slave write.
 *        Sends data from the write buffer to the I2C bus.
 */

void I2C::SlaveWrite() {
    uint8_t data;
    if (PopWrite(&data)) {
    	// ESP: Escribe 8 bits de datos en el registro de datos esclavo.
		// ENG: Writes 8 bits of data to the slave data register.
        m_I2C->SLVDAT = data & 0xFF;
        m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK; // ESP: Continuar con la transmision. ENG: Continue with the transmission.
        m_NoAnsweredRequests = 0;
    } else {
        if (++m_NoAnsweredRequests > m_MaxNoAnsweredRequests) {

        	// ESP: Responde con un 0 si no hay datos para enviar.
			// ENG: Responds with a 0 if there is no data to send.
            m_I2C->SLVDAT = 0 & 0xFF;                     // ESP: Escribe 0 para responder la solicitud de lectura. ENG: Write a 0 to answer the read request.
            m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;  // ESP: Continuar con la transmision. ENG: Continue with the transmission.
            m_NoAnsweredRequests = 0;
        }
    }
}




/* ESP
 * @brief Inicia una operación de lectura maestro.
 */

/* ENG
 * @brief Starts a master read operation.
 */

void I2C::StartMasterRead() {
    m_FlagRead = true;
    m_NACK = false;

    // ESP: Escribe la dirección del esclavo y setea el bit RW en 1 en el registro de datos maestro.
    // ENG: Writes the slave address and sets 1 in the RW bit into the master data register.
    m_I2C->MSTDAT = ((m_SlaveAddress & 0x7F) << 1) | (1 << 0);

    // ESP: Comienza la transmisión.
    // ENG: Start the transmission.
    m_I2C->MSTCTL = I2C_MSTCTL_MSTSTART_MASK;
}




/* ESP
 * @brief Inicia una operación de escritura maestro.
 */

/* ENG
 * @brief Starts a master write operation.
 */

void I2C::StartMasterWrite() {
    m_FlagWrite = true;
    m_NACK = false;

    // ESP: Escribe la dirección del esclavo y setea el bit RW en 0 en el registro de datos maestro.
    // ENG: Writes the slave address and sets 0 in the RW bit into the master data register.
    m_I2C->MSTDAT = ((m_SlaveAddress & 0x7F) << 1) | (0 << 0);

    // ESP: Inicia la transmisión.
    // ENG: Starts the transmission.
    m_I2C->MSTCTL = I2C_MSTCTL_MSTSTART_MASK;
}




/* ESP
 * @brief Deshabilita las interrupciones pendientes.
 */

/* ENG
 * @brief Disables pending interrupts.
 */

void I2C::DisableMasterPendingInterrupt() { m_I2C->INTENCLR |= I2C_INTENCLR_MSTPENDINGCLR(1); }




/* ESP
 * @brief Habilita las interrupciones pendientes.
 */

/* ENG
 * @brief Enables pending interrupts.
 */

void I2C::EnableMasterPendingInterrupt() { m_I2C->INTENSET |= I2C_INTENSET_MSTPENDINGEN(1); }




/* ESP
 * @brief Ingresa un dato en el buffer de lectura.
 * @param data Dato a guardar en el buffer.
 */

/* ENG
 * @brief Pushes data into the read buffer.
 * @param data Data to store in the buffer.
 */

void I2C::PushRead(uint8_t data) {
    m_BufferRead[m_IndexReadIn] = data;
    m_IndexReadIn++;
    m_IndexReadIn %= m_MaxRead;
}




/* ESP
 * @brief Extrae un dato del buffer de lectura.
 * @param data Puntero donde se guarda el dato extraído.
 * @return true si se extrajo un dato, false si el buffer está vacío.
 */

/* ENG
 * @brief Pops data from the read buffer.
 * @param data Pointer to store the extracted data.
 * @return true if data was popped, false if the buffer is empty.
 */

bool I2C::PopRead(uint8_t *data) {
    if (m_IndexReadIn != m_IndexReadOut) {
        *data = m_BufferRead[m_IndexReadOut];
        m_IndexReadOut++;
        m_IndexReadOut %= m_MaxRead;
        return true;
    }

    return false;
}




/* ESP
 * @brief Ingresa un dato en el buffer de escritura.
 * @param data Dato a guardar en el buffer.
 */

/* ENG
 * @brief Pushes data into the write buffer.
 * @param data Data to store in the buffer.
 */

void I2C::PushWrite(uint8_t data) {
    m_BufferWrite[m_IndexWriteIn] = data;
    m_IndexWriteIn++;
    m_IndexWriteIn %= m_MaxWrite;
}




/* ESP
 * @brief Extrae un dato del buffer de escritura.
 * @param data Puntero donde se guarda el dato extraído.
 * @return true si se extrajo un dato, false si el buffer está vacío.
 */

/* ENG
 * @brief Pops data from the write buffer.
 * @param data Pointer to store the extracted data.
 * @return true if data was popped, false if the buffer is empty.
 */

bool I2C::PopWrite(uint8_t *data) {
    if (m_IndexWriteIn != m_IndexWriteOut) {
        *data = m_BufferWrite[m_IndexWriteOut];
        m_IndexWriteOut++;
        m_IndexWriteOut %= m_MaxWrite;
        return true;
    }

    return false;
}




/* ESP
 * @brief Guarda el mensaje a enviar en el buffer de escritura
 *        e inicia la interrupción para realizar la operación de escritura.
 * @param message Datos a enviar.
 * @param size Cantidad de caracteres a enviar del mensaje.
 */

/* ENG
 * @brief Stores the message to send in the write buffer
 *        and starts the interrupt to perform the write operation.
 * @param message Data to send.
 * @param size Number of characters to send from the message.
 */

void I2C::Write(void *message, uint32_t size) {
    if (!m_Error) {
        for (uint32_t i = 0; i < size; i++) {
        	// ESP: Almacena cada byte del mensaje en el buffer de escritura.
            // ENG: Stores each byte of the message in the write buffer.
            PushWrite(((uint8_t *)message)[i]);

            if (!m_FlagWrite) {
            	// ESP: Inicia la operación de escritura si no hay una en curso.
            	// ENG: Starts the write operation if none is in progress.
                StartMasterWrite();
                EnableMasterPendingInterrupt();
            }
        }
    }
}




/* ESP
 * @brief Devuelve true si se inició correctamente una lectura.
 *        Devuelve false si ya hay una lectura en curso.
 */

/* ENG
 * @brief Returns true if reading was successfully triggered.
 *        Returns false if a previous reading is still active.
 */

bool I2C::TriggerReading(uint8_t bytes) {
    if (MasterIsIdle()) {
        m_Bytes = bytes;
        StartMasterRead();
        EnableMasterPendingInterrupt();
        return true;
    }

    return false;
}




/* ESP
 * @brief Lee size bytes de la última lectura y los guarda en message.
 * @param message Variable donde se guarda lo leído.
 * @param size Tamaño del dato a leer en bytes.
 */

/* ENG
 * @brief Reads size bytes from the last read and stores them in message.
 * @param message Variable to store the read data.
 * @param size Size of the data to read in bytes.
 */

void *I2C::Read(void *message, uint32_t size) {
    if (!m_Error) {
        uint8_t data;
        uint32_t index = 0;
        char *buffer = (char *)message;

        while(index < size){
			if (PopRead(&data)) {
				buffer[index] = data;
				index++;
			}
        }
		return (void *)buffer; // ESP: Retorna los bytes leidos si no hubo error. ENG: Returns the read bytes if there are no errors.
    }

    return nullptr; // ESP: Retorna nullptr si hubo un error. ENG: Return nullptr if there is any error.
}




/* ESP
 * @brief Lee 1 byte de la última lectura y lo guarda en *message.
 * @param message Variable donde se guarda lo leído.
 */

/* ENG
 * @brief Reads 1 byte from the last read and stores it in *message.
 * @param message Variable to store the read data.
 */

bool I2C::ReadNextByte(uint8_t *message) {
    if (!m_Error) {
        uint8_t data;

        if (PopRead(&data))
        {
        	// ESP: Si se pudo leer algo del buffer circular --> se almacena el byte leído en el message buffer.
        	// ENG: If it was possible to read something from the circular buffer --> The read byte is saved into the message buffer.
        	*message = data;
        	// ESP: Retorna true para indicar que se leyó 1 byte.
        	// ENG: Returns true to indicate that 1 byte was correctly read.
            return true;
        }
    }
    // ESP: Retorna false si no se leyó nada.
    // ENG: Returns false if nothing was read.
    return false;
}




/* ESP
 * @brief Lee de a un byte y lo devuelve.
 */

/* ENG
 * @brief Reads one byte and returns it.
 */

uint8_t I2C::read(void){
	uint8_t data = 0;
	ReadNextByte(&data); // ESP: Lee 1 byte. ENG: Reads 1 byte.
  return data ;
}

/* ESP
 * @brief Escribe size bytes de data_to_write a través de I2C y espera a que termine.
 * @param data_to_write Variable con el dato a escribir.
 * @param size Tamaño del contenido a escribir en bytes.
 */

/* ENG
 * @brief Writes size bytes of data_to_write through I2C and waits for it to finish.
 * @param data_to_write Variable with the data to write.
 * @param size Size of the content to write in bytes.
 */

void I2C::writeI2CAndWait(void *data_to_write, uint32_t size) {
    Write(data_to_write, size);

    // ESP: Espera a que termine la escritura. ENG. It waits to finish the writing process.
    while (MasterIsWriting());

}




/* ESP
 * @brief Envía la operación de lectura a I2C de size bytes y espera a que termine.
 * @param size Tamaño en bytes a leer.
 */

/* ENG
 * @brief Sends the read operation to I2C for size bytes and waits for it to finish.
 * @param size Size in bytes to read.
 */

void I2C::readI2CAndWait(uint8_t size) {
    TriggerReading(size);

    // ESP: Espera a que termine la lectura. ENG. It waits to finish the reading process.
    while (MasterIsReading());
}




/* ESP
 * @brief Maneja la interrupción del periférico I2C.
 *        Dependiendo del estado, realiza acciones de lectura o escritura.
 */

/* ENG
 * @brief Handles the I2C peripheral interrupt.
 *        Depending on the state, performs read or write actions.
 */

void I2C::IRQHandler() {
    if (!m_Error) {
        if (m_Mode == master) {
            uint8_t stat = (m_I2C->STAT & I2C_STAT_MSTSTATE_MASK) >> I2C_STAT_MSTSTATE_SHIFT;

            // ESP: Si el flag de stat marca listo para recibir entonces el maestro lee.
            // ENG: If the stat flag marks ready to receive, then the master reads.
            if (stat == 0x1 && m_FlagRead)
                MasterRead();

            // ESP: Si el flag de stat marca listo para escribir, entonces el maestro transmite.
            // ENG: If the flag stat marks ready to write, then the master writes.
            else if (stat == 0x2 /*&& m_FlagWrite*/)
                MasterWrite();

            // ESP: Si el flag de stat marca NACK address or NARCK data, entonces sE pregunta por la lectura de un último byte, se frena la transmisión y se resetea el buffer de escritura.
            // ENG: If the stat flag marks NACK address or NARCK data, then it is asked for the reading of a last byte, the transmission is stopped and the write buffer is reset.
            else if (stat == 0x0 || stat == 0x3 || stat == 0x4)
            {
                if (m_FlagRead)
                    MasterRead(true);  // Last byte to read.
                else {
                    DisableMasterPendingInterrupt();
                    m_I2C->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;  // Stop the transmission.
                    m_NACK = true;
                    m_IndexWriteIn = m_IndexWriteOut = 0;  // Reset write buffer.
                    m_FlagWrite = false;
                }
            }
        } else if (m_Mode == slave) {
            uint8_t stat = (m_I2C->STAT & I2C_STAT_MSTSTATE_MASK) >> I2C_STAT_MSTSTATE_SHIFT;

            if (stat == 0x0)  // Received address and RW.
                m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;

            else if (stat == 0x1)  // Receive ready.
                SlaveRead();

            else if (stat == 0x2)  // Transmit ready.
                SlaveWrite();
        }
    }
}




/* ESP
 * @brief Manejador de interrupción para I2C0.
 */

/* ENG
 * @brief Interrupt handler for I2C0.
 */

void I2C0_IRQHandler() { g_I2CVector[0]->IRQHandler(); }




/* ESP
 * @brief Devuelve true si el maestro está leyendo.
 */

/* ENG
 * @brief Returns true if the master is reading.
 */

bool I2C::MasterIsReading() { return m_FlagRead; }




/* ESP
 * @brief Devuelve true si el maestro está escribiendo.
 */

/* ENG
 * @brief Returns true if the master is writing.
 */

bool I2C::MasterIsWriting() { return m_FlagWrite; }




/* ESP
 * @brief Devuelve true si el maestro está inactivo.
 */

/* ENG
 * @brief Returns true if the master is idle.
 */

bool I2C::MasterIsIdle() { return (!m_FlagRead && !m_FlagWrite); }




/* ESP
 * @brief Devuelve true si se recibió un NACK.
 */

/* ENG
 * @brief Returns true if a NACK was received.
 */

bool I2C::HadNACK() { return m_NACK; }
