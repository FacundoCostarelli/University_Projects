/*******************************************************************************************************************************/ /**
                                                                                                                                   *
                                                                                                                                   * @file		I2C.cpp
                                                                                                                                   * @brief		Descripcion del modulo
                                                                                                                                   * @date		26 ene. 2023
                                                                                                                                   * @author		Luca Rimondini
                                                                                                                                   *
                                                                                                                                   **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "I2C.h"



/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/
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

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
I2C *g_I2CVector[4] = {nullptr, nullptr, nullptr, nullptr};

bool m_FlagWrite;
bool m_FlagRead;
I2C_Type* m_I2C;

bool m_Error;
bool m_NACK;
uint8_t m_Bytes;
uint8_t m_SlaveAddress;

uint8_t* m_BufferRead;
uint32_t m_IndexReadIn;
uint32_t m_IndexReadOut;
uint32_t m_MaxRead;

uint8_t* m_BufferWrite;
uint32_t m_IndexWriteIn;
uint32_t m_IndexWriteOut;
uint32_t m_MaxWrite;


mode_t m_Mode;

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/

/**
 * @brief Constructor de la clase I2C.
 *        Configura los pines, buffers y el modo de operación del periférico I2C.
 * @param portSCL Puerto para la línea SCL.
 * @param pinSCL  Pin para la línea SCL.
 * @param portSDA Puerto para la línea SDA.
 * @param pinSDA  Pin para la línea SDA.
 * @param i2c     Puntero al periférico I2C.
 * @param mode    Modo de operación (maestro o esclavo).
 * @param slaveAddress Dirección del esclavo en caso de modo esclavo.
 */
I2C::I2C(uint8_t portSCL, uint8_t pinSCL, uint8_t portSDA, uint8_t pinSDA, I2C_Type *i2c,
         mode_t mode, uint8_t slaveAddress) {
    m_MaxRead = 64;
    m_MaxWrite = 64;
    m_BufferRead = new uint8_t[m_MaxRead];
    m_BufferWrite = new uint8_t[m_MaxWrite];
    m_IndexReadIn = m_IndexReadOut = m_IndexWriteIn = m_IndexWriteOut = 0;

    m_NoAnsweredRequests = 0;
    m_MaxNoAnsweredRequests = 4;

    // Check if already assigned to not overwrite.
    m_Error = !(
        (i2c == I2C0 && g_I2CVector[0] == nullptr) || (i2c == I2C1 && g_I2CVector[1] == nullptr) ||
        (i2c == I2C2 && g_I2CVector[2] == nullptr) || (i2c == I2C3 && g_I2CVector[3] == nullptr));

    if (!m_Error) {
        m_FlagWrite = false;
        m_FlagRead = false;
        m_NACK = false;
        m_Bytes = 0;
        m_I2C = i2c;
        m_Mode = mode;
        m_PortSCL = (m_I2C != I2C0) ? portSCL : 0;
        m_PinSCL = (m_I2C != I2C0) ? pinSCL : 10;
        m_PortSDA = (m_I2C != I2C0) ? portSDA : 0;
        m_PinSDA = (m_I2C != I2C0) ? pinSDA : 11;
        m_SlaveAddress = slaveAddress;

        if (m_I2C == I2C0)
            g_I2CVector[0] = this;
        else if (m_I2C == I2C1)
            g_I2CVector[1] = this;
        else if (m_I2C == I2C2)
            g_I2CVector[2] = this;
        else if (m_I2C == I2C3)
            g_I2CVector[3] = this;

        if (m_I2C == I2C0) {
            ConfiguracionI2C0();  // configuracion particular
        } else {
            ClearPresets();
            EnableClocks();
            AssignPins();

            // Set mode.
            if (m_Mode == master)
                SetUpMaster();
            else if (m_Mode == slave)
                SetUpSlave();
        }

        // Enable interrupts.
        EnableNvicInterrupt();
    }
}

/**
 * @brief Configura los pines del periférico I2C para el puerto 0 (I2C0).
 *        Configura el clock, pines y resets necesarios.
 */
void I2C::ConfiguracionI2C0() {
    // Configuracion de I2C. El orden de pasos de configuracion del periferico I2C0 es importante

    // 1. Habilitar y seleccionar los pines para SDA y SCL
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);  // Limpio bit 7
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);   // Habilito clock de la Switch Matrix

    SWM0->PINENABLE0 &= ~(1 << 12) & ~(1 << 13);  // Habilito pines P0.10 y P0.11 para SDA y SCL

    IOCON->PIO[IOCON_INDEX_PIO0_10] &=
        ~(11 << 8);  // Configuro PIO0_10 como Standard Mode I2C. I2C0_SCL
    IOCON->PIO[IOCON_INDEX_PIO0_11] &=
        ~(11 << 8);  // Configuro PIO0_11 como Standard Mode I2C. I2C0_SDA

    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);  // Apago el clock de la Switch Matrix

    // 2. Elegir el clock rate del pin SCL del modulo I2C0
    SYSCON->FCLKSEL[5] =
        1;  // Elijo el clock principal a usar de referencia en los calculos de baudrate del I2C0.
            // Selecciono main_clk = clock del sistema. Debería ser 30MHz

    // Habilito el clk del periferico de i2c
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 5);  // Limpio el Bit 5
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 5);   // Seteo en 1 el Bit 5

    // 3. Realizar un reset del modulo I2C o periferico
    SYSCON->PRESETCTRL0 &= ~(1 << 5);  // Limpio bit 5 del registro PRESETCTRL0
    SYSCON->PRESETCTRL0 |= (1 << 5);   // Realizo un reset del periferico. Reset con 1 en bit 5

    // NVIC->ISER[0] |= 1<<8;
    // I2C0->INTENSET |=1; //master pending
    // I2C0->MSTCTL|=1<<1; //master start bit for I2C

    // 4.
    I2C0->CLKDIV = 0x0F;  // 14 Elijo un divisor de Clock para manejar el bit rate del I2C.
                          // //determina el incremento usado en Msttime

    I2C0->MSTTIME &= ~(0x07);       // Limpio bits 0 a 2
    I2C0->MSTTIME |= 0x07;          // Cargo 1 en MSTSCLLOW //9 clocks
    I2C0->MSTTIME &= ~(0x07 << 4);  // Limpio bits 4 a 6
    I2C0->MSTTIME |= (0x07 << 4);   // Cargo 0 en MSTSCLHIGH //9 clocks
    // En este punto hay un baudrate de 400khz de I2C en SCL.

    //*****VERFICAR si debe ir 100kHZ = Standar Mode o 400KHz = Fast Mode. Para ello ver la hoja de
    // datos del sensor. Mas baudrate implica resistencias de pull up mas altas

    I2C0->CFG |= I2C_CFG_MSTEN(1);  // == 1 // Establezco I2C0 en modo maestro. ******VERFICAR: Si
                                    // tenemos synchronous y single-master mode

}

I2C::~I2C() {}

/**
 * @brief Asigna los pines al periférico I2C.
 *        Configura los pines SDA y SCL para el funcionamiento del periférico.
 */
void I2C::AssignPins() {
    // Power on the switch matrix clock.
    SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);

    // Assign pins.
    // I2C0 is fixed on PIO0_10 for SCL and PIO0_11 for SDA.
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

    // Set open-drain if not using I2C0.
    if (m_I2C != I2C0) {
        IOCON->PIO[IOCON_INDEX[m_PortSCL][m_PinSCL]] |= IOCON_PIO_OD(1);
        IOCON->PIO[IOCON_INDEX[m_PortSDA][m_PinSDA]] |= IOCON_PIO_OD(1);
    }

    // Power off the switch matrix clock.
    SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);
}

/**
 * @brief Limpia los presets del periférico I2C.
 *        Realiza un reset del periférico antes de configurarlo.
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

/**
 * @brief Habilita los clocks para el periférico I2C.
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

    // Set clock divider.
    m_I2C->CLKDIV = 11;  // Clock divided by 12.
}

/**
 * @brief Habilita las interrupciones NVIC para el periférico I2C.
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

/**
 * @brief Configura el periférico I2C en modo maestro.
 */
void I2C::SetUpMaster() {
    // Set SCL to be high and low for 4 clock cycles each.
    m_I2C->MSTTIME = I2C_MSTTIME_MSTSCLLOW(3) | I2C_MSTTIME_MSTSCLHIGH(3);

    // Set master mode.
    m_I2C->CFG = I2C_CFG_MSTEN(1);
}

/**
 * @brief Configura el periférico I2C en modo esclavo.
 */
void I2C::SetUpSlave() {
    // Set slave mode.
    m_I2C->CFG = I2C_CFG_SLVEN(1);

    // Set slave address.
    m_I2C->SLVADR[0] = I2C_SLVADR_SLVADR(m_SlaveAddress);
    m_I2C->SLVADR[1] = I2C_SLVADR_SADISABLE(1);
    m_I2C->SLVADR[2] = I2C_SLVADR_SADISABLE(1);
    m_I2C->SLVADR[3] = I2C_SLVADR_SADISABLE(1);

    // Enable slave interrupts.
    m_I2C->INTENSET |= I2C_INTENSET_SLVPENDINGEN(1);
}

/**
 * @brief Maneja una escritura maestro.
 *        Envía datos desde el buffer de escritura.
 */
void I2C::MasterWrite() {
    if (m_FlagWrite) {
        uint8_t data;
        if (PopWrite(&data)) {
            m_I2C->MSTDAT = data & 0xFF;                  // Write 8 bits of data.
            m_I2C->MSTCTL = I2C_MSTCTL_MSTCONTINUE_MASK;  // Continue with the transmission.
        } else {
            DisableMasterPendingInterrupt();
            m_I2C->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;  // Stop the transmission.
            m_FlagWrite = false;
        }
    }
}

/**
 * @brief Maneja una lectura maestro.
 *        Recibe datos y los almacena en el buffer de lectura.
 * @param last Indica si este es el último byte de la transmisión.
 */
void I2C::MasterRead(bool last) {
    uint8_t data = (m_I2C->MSTDAT & I2C_MSTDAT_DATA_MASK) >> I2C_MSTDAT_DATA_SHIFT;
    PushRead(data);
    m_Bytes--;

    if (!last && m_Bytes)
        m_I2C->MSTCTL = I2C_MSTCTL_MSTCONTINUE_MASK;  // Continue with the transmission.
    else {
        DisableMasterPendingInterrupt();
        m_I2C->MSTCTL = I2C_MSTCTL_MSTSTOP_MASK;  // Stop the transmission.
        m_FlagRead = false;
        m_Bytes = 0;
    }
}

/**
 * @brief Maneja una lectura esclavo.
 *        Recibe datos desde el bus I2C y los almacena en el buffer de lectura.
 */
void I2C::SlaveRead() {
    uint8_t data = (m_I2C->SLVDAT & I2C_SLVDAT_DATA_MASK) >> I2C_SLVDAT_DATA_SHIFT;
    m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;
    PushRead(data);
}

/**
 * @brief Maneja una escritura esclavo.
 *        Envía datos desde el buffer de escritura al bus I2C.
 */
void I2C::SlaveWrite() {
    uint8_t data;
    if (PopWrite(&data)) {
        m_I2C->SLVDAT = data & 0xFF;                  // Write 8 bits of data.
        m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;  // Continue with the transmission.
        m_NoAnsweredRequests = 0;
    } else {
        if (++m_NoAnsweredRequests > m_MaxNoAnsweredRequests) {
            m_I2C->SLVDAT = 0 & 0xFF;                     // Write a 0 to answer the read request.
            m_I2C->SLVCTL = I2C_SLVCTL_SLVCONTINUE_MASK;  // Continue with the transmission.
            m_NoAnsweredRequests = 0;
        }
    }
}


/**
 * @brief Inicia una operación de lectura maestro.
 */
void I2C::StartMasterRead() {
    m_FlagRead = true;
    m_NACK = false;
    m_I2C->MSTDAT =
        ((m_SlaveAddress & 0x7F) << 1) | (1 << 0);  // Write address and set RW bit to 1.
    m_I2C->MSTCTL = I2C_MSTCTL_MSTSTART_MASK;       // Start the transmission.
}

/**
 * @brief Inicia una operación de escritura maestro.
 */
void I2C::StartMasterWrite() {
    m_FlagWrite = true;
    m_NACK = false;
    m_I2C->MSTDAT =
        ((m_SlaveAddress & 0x7F) << 1) | (0 << 0);  // Write address and set RW bit to 0.
    m_I2C->MSTCTL = I2C_MSTCTL_MSTSTART_MASK;       // Start the transmission.
}

/*
 * @brief deshabilita las interrupciones pendientes
 * */
void I2C::DisableMasterPendingInterrupt() { m_I2C->INTENCLR |= I2C_INTENCLR_MSTPENDINGCLR(1); }

/*
 * @brief habilita las interrupciones pendientes
 * */
void I2C::EnableMasterPendingInterrupt() { m_I2C->INTENSET |= I2C_INTENSET_MSTPENDINGEN(1); }

/*
 * @brief ingresa dato en el buffer de lectura
 * @param data dato a guardar en el buffer
 * */
void I2C::PushRead(uint8_t data) {
    m_BufferRead[m_IndexReadIn] = data;
    m_IndexReadIn++;
    m_IndexReadIn %= m_MaxRead;
}
/*
 * @brief extraer dato del buffer de lectura
 * @param data puntero donde se guarda lo extraido del buffer
 * */
bool I2C::PopRead(uint8_t *data) {
    if (m_IndexReadIn != m_IndexReadOut) {
        *data = m_BufferRead[m_IndexReadOut];
        m_IndexReadOut++;
        m_IndexReadOut %= m_MaxRead;
        return true;
    }

    return false;
}

/*
 * @brief ingresa dato en el buffer de escitura
 * @param data dato a guardar en el buffer
 * */
void I2C::PushWrite(uint8_t data) {
    m_BufferWrite[m_IndexWriteIn] = data;
    m_IndexWriteIn++;
    m_IndexWriteIn %= m_MaxWrite;
}

/*
 * @brief extraer dato del buffer de escritura
 * @param data puntero donde se guarda lo extraido del buffer
 * */
bool I2C::PopWrite(uint8_t *data) {
    if (m_IndexWriteIn != m_IndexWriteOut) {
        *data = m_BufferWrite[m_IndexWriteOut];
        m_IndexWriteOut++;
        m_IndexWriteOut %= m_MaxWrite;
        return true;
    }

    return false;
}

/*
 * @brief Guarda el mensaje a enviar en el buffer de escritura
 * 		  e inicia la interrupcion para realizar la operacion de escritura
 * @param message datos a enviar
 * @param size cantidad de caracteres a enviar del message
 * */
void I2C::Write(void *message, uint32_t size) {
    if (!m_Error) {
        for (uint32_t i = 0; i < size; i++) {
            PushWrite(((uint8_t *)message)[i]);

            if (!m_FlagWrite) {
                StartMasterWrite();
                EnableMasterPendingInterrupt();
            }
        }
    }
}


/*
 * @brief Returns true if reading was successfully triggered.
 * 		  Returns false if a previous reading is still active.
 * */
bool I2C::TriggerReading(uint8_t bytes) {
    if (MasterIsIdle()) {
        m_Bytes = bytes;
        StartMasterRead();
        EnableMasterPendingInterrupt();
        return true;
    }

    return false;
}

/*
 * @brief Lee size bytes de la ultima lectura y lo guarda en message
 * @param message viariable donde guarda lo leido
 * @param size tamaño del dato a leer en bytes
 * */
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
		return (void *)buffer; //retorna los bytes leidos si no hubo error
    }

    return nullptr; // returna nullptr si hubo un error
}

/*
 * @brief Lee 1 byte de la ultima lectura y lo guarda en *message
 * @param message viariable donde guarda lo leido
 * */
bool I2C::ReadNextByte(uint8_t *message) {
    if (!m_Error) {
        uint8_t data;

        if (PopRead(&data)) {          // Si se pudo leer algo del buffer circular
        	*message = data;          // Almacena el byte leído en el buffer
            return true;                  // Retorna true para indicar que se leyó 1 byte
        }
    }
    return false;                          // Retorna false si no se leyó nada
}

/*
 * @brief lee de a un byte y lo devuelve
 * */
uint8_t I2C::read(void){
	uint8_t data = 0;
	ReadNextByte(&data);//read 1 byte
  return data ;
}

/*
 * @brief escribe size bytes de data_to_write a través de i2c y espera a que termine
 * @param data_to_write variable con el dato a escribir
 * @param tamaño del contenido a escribir en bytes
 */
void I2C::writeI2CAndWait(void *data_to_write, uint32_t size) {
    Write(data_to_write, size);

    while (MasterIsWriting());
}

/*
 * @brief Envia la operación de lectura a i2c de size bytes y espera a que termine
 * @param size tamaño en bytes a leer
 */
void I2C::readI2CAndWait(uint8_t size) {
    TriggerReading(size);

    while (MasterIsReading());
}

/**
 * @brief Maneja la interrupción del periférico I2C.
 *        Dependiendo del estado, realiza acciones de lectura o escritura.
 */
void I2C::IRQHandler() {
    if (!m_Error) {
        if (m_Mode == master) {
            uint8_t stat = (m_I2C->STAT & I2C_STAT_MSTSTATE_MASK) >> I2C_STAT_MSTSTATE_SHIFT;

            if (stat == 0x1 && m_FlagRead)  // Receive ready.
                MasterRead();

            else if (stat == 0x2 /*&& m_FlagWrite*/)  // Transmit ready.
                MasterWrite();

            else if (stat == 0x0 || stat == 0x3 || stat == 0x4)  // NACK address or NACK data.
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



void I2C0_IRQHandler() { g_I2CVector[0]->IRQHandler(); }


//getters

bool I2C::MasterIsReading() { return m_FlagRead; }
bool I2C::MasterIsWriting() { return m_FlagWrite; }
bool I2C::MasterIsIdle() { return (!m_FlagRead && !m_FlagWrite); }
bool I2C::HadNACK() { return m_NACK; }
