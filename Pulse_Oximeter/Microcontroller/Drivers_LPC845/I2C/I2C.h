/*
 * I2C.h
 *
 *  Created on: January 2023
 *      Author: Luca Rimondini.
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la clase `I2C`, que maneja la comunicación I2C tanto en modo maestro como en modo esclavo.
 *        La clase proporciona métodos para configurar y gestionar la comunicación I2C, incluyendo la lectura y escritura de datos, así como la gestión de interrupciones.
 *
 *      **Variables**
 *
 *      m_NoAnsweredRequests:      Variable de tipo `uint8_t` que almacena el número de solicitudes no respondidas.
 *      m_MaxNoAnsweredRequests:   Variable de tipo `uint8_t` que almacena el número máximo de solicitudes no respondidas permitidas.
 *      m_PortSCL:                 Variable de tipo `uint8_t` que almacena el puerto del pin SCL (Serial Clock Line).
 *      m_PinSCL:                  Variable de tipo `uint8_t` que almacena el número del pin SCL.
 *      m_PortSDA:                 Variable de tipo `uint8_t` que almacena el puerto del pin SDA (Serial Data Line).
 *      m_PinSDA:                  Variable de tipo `uint8_t` que almacena el número del pin SDA.
 *
 *      **Métodos Privados**
 *
 *      AssignPins():              Método que asigna los pines SCL y SDA para la comunicación I2C.
 *      ClearPresets():            Método que limpia las configuraciones previas del I2C.
 *      EnableClocks():            Método que habilita los relojes necesarios para el funcionamiento del I2C.
 *      EnableNvicInterrupt():     Método que habilita las interrupciones NVIC para el I2C.
 *      SetUpMaster():             Método que configura el I2C en modo maestro.
 *      SetUpSlave():              Método que configura el I2C en modo esclavo.
 *      MasterRead(bool last):     Método que realiza una lectura en modo maestro.
 *      MasterWrite():             Método que realiza una escritura en modo maestro.
 *      SlaveRead():               Método que realiza una lectura en modo esclavo.
 *      SlaveWrite():              Método que realiza una escritura en modo esclavo.
 *      DisableMasterPendingInterrupt(): Método que deshabilita las interrupciones pendientes en modo maestro.
 *      EnableMasterPendingInterrupt():  Método que habilita las interrupciones pendientes en modo maestro.
 *      PopRead(uint8_t* data):    Método que extrae un byte del buffer de lectura.
 *      PushRead(uint8_t data):    Método que introduce un byte en el buffer de lectura.
 *      PopWrite(uint8_t* data):   Método que extrae un byte del buffer de escritura.
 *      PushWrite(uint8_t data):   Método que introduce un byte en el buffer de escritura.
 *      StartMasterRead():         Método que inicia una lectura en modo maestro.
 *      StartMasterWrite():        Método que inicia una escritura en modo maestro.
 *      ConfiguracionI2C0():       Método que realiza la configuración específica para el I2C0.
 *
 *      **Métodos Públicos**
 *
 *      I2C(uint8_t portSCL, uint8_t pinSCL, uint8_t portSDA, uint8_t pinSDA, I2C_Type* i2c, mode_t mode, uint8_t slaveAddress):
 *                                 Constructor de la clase. Inicializa el I2C con los pines y modo especificados.
 *      ~I2C():                    Destructor de la clase. Libera los recursos utilizados por el objeto.
 *      IRQHandler():              Método que maneja las interrupciones del I2C.
 *      Write(void* message, uint32_t size): Método que escribe un mensaje en el bus I2C.
 *      TriggerReading(uint8_t bytes): Método que inicia una lectura de un número específico de bytes.
 *      MasterIsReading():         Método que verifica si el maestro está en modo lectura.
 *      MasterIsWriting():         Método que verifica si el maestro está en modo escritura.
 *      MasterIsIdle():            Método que verifica si el maestro está en modo inactivo.
 *      HadNACK():                 Método que verifica si se ha recibido un NACK.
 *      Read(void* message, uint32_t size): Método que lee un mensaje del bus I2C.
 *      ReadNextByte(uint8_t *message): Método que lee el siguiente byte del buffer de lectura.
 *      read():                    Método auxiliar que realiza una lectura de un byte.
 *      writeI2CAndWait(void *data_to_write, uint32_t size): Método que escribe datos en el I2C y espera a que se complete la operación.
 *      readI2CAndWait(uint8_t size): Método que lee datos del I2C y espera a que se complete la operación.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the `I2C` class, which handles I2C communication in both master and slave modes.
 *        The class provides methods to configure and manage I2C communication, including data reading and writing, as well as interrupt handling.
 *
 *      **Variables**
 *
 *      m_NoAnsweredRequests:      `uint8_t` variable that stores the number of unanswered requests.
 *      m_MaxNoAnsweredRequests:   `uint8_t` variable that stores the maximum number of unanswered requests allowed.
 *      m_PortSCL:                 `uint8_t` variable that stores the port of the SCL (Serial Clock Line) pin.
 *      m_PinSCL:                  `uint8_t` variable that stores the SCL pin number.
 *      m_PortSDA:                 `uint8_t` variable that stores the port of the SDA (Serial Data Line) pin.
 *      m_PinSDA:                  `uint8_t` variable that stores the SDA pin number.
 *
 *      **Private Methods**
 *
 *      AssignPins():              Method that assigns the SCL and SDA pins for I2C communication.
 *      ClearPresets():            Method that clears previous I2C configurations.
 *      EnableClocks():            Method that enables the necessary clocks for I2C operation.
 *      EnableNvicInterrupt():     Method that enables NVIC interrupts for I2C.
 *      SetUpMaster():             Method that configures I2C in master mode.
 *      SetUpSlave():              Method that configures I2C in slave mode.
 *      MasterRead(bool last):     Method that performs a read in master mode.
 *      MasterWrite():             Method that performs a write in master mode.
 *      SlaveRead():               Method that performs a read in slave mode.
 *      SlaveWrite():              Method that performs a write in slave mode.
 *      DisableMasterPendingInterrupt(): Method that disables pending interrupts in master mode.
 *      EnableMasterPendingInterrupt():  Method that enables pending interrupts in master mode.
 *      PopRead(uint8_t* data):    Method that pops a byte from the read buffer.
 *      PushRead(uint8_t data):    Method that pushes a byte into the read buffer.
 *      PopWrite(uint8_t* data):   Method that pops a byte from the write buffer.
 *      PushWrite(uint8_t data):   Method that pushes a byte into the write buffer.
 *      StartMasterRead():         Method that initiates a read in master mode.
 *      StartMasterWrite():        Method that initiates a write in master mode.
 *      ConfiguracionI2C0():       Method that performs specific configuration for I2C0.
 *
 *      **Public Methods**
 *
 *      I2C(uint8_t portSCL, uint8_t pinSCL, uint8_t portSDA, uint8_t pinSDA, I2C_Type* i2c, mode_t mode, uint8_t slaveAddress):
 *                                 Class constructor. Initializes I2C with the specified pins and mode.
 *      ~I2C():                    Class destructor. Releases the resources used by the object.
 *      IRQHandler():              Method that handles I2C interrupts.
 *      Write(void* message, uint32_t size): Method that writes a message to the I2C bus.
 *      TriggerReading(uint8_t bytes): Method that initiates a read of a specific number of bytes.
 *      MasterIsReading():         Method that checks if the master is in read mode.
 *      MasterIsWriting():         Method that checks if the master is in write mode.
 *      MasterIsIdle():            Method that checks if the master is idle.
 *      HadNACK():                 Method that checks if a NACK has been received.
 *      Read(void* message, uint32_t size): Method that reads a message from the I2C bus.
 *      ReadNextByte(uint8_t *message): Method that reads the next byte from the read buffer.
 *      read():                    Helper method that performs a single-byte read.
 *      writeI2CAndWait(void *data_to_write, uint32_t size): Method that writes data to I2C and waits for the operation to complete.
 *      readI2CAndWait(uint8_t size): Method that reads data from I2C and waits for the operation to complete.
 *
 * @param None
 */

#ifndef I2C_H_
#define I2C_H_


#include "../LPC845.h"

#if defined(__cplusplus)
extern "C" {
void I2C0_IRQHandler();
}
#endif

enum mode_t { master, slave };

class I2C {

   private:

    uint8_t m_NoAnsweredRequests, m_MaxNoAnsweredRequests;
    uint8_t m_PortSCL, m_PinSCL, m_PortSDA, m_PinSDA;


    // Configuration.
    void AssignPins();
    void ClearPresets();
    void EnableClocks();
    void EnableNvicInterrupt();
    void SetUpMaster();
    void SetUpSlave();

    // Helpers.
    void MasterRead(bool last = false);
    void MasterWrite();
    void SlaveRead();
    void SlaveWrite();
    void DisableMasterPendingInterrupt();
    void EnableMasterPendingInterrupt();

    // Buffer management.
    bool PopRead(uint8_t* data);
    void PushRead(uint8_t data);
    bool PopWrite(uint8_t* data);
    void PushWrite(uint8_t data);

    // Signals sending.
    void StartMasterRead();
    void StartMasterWrite();

    // Particular configuration
    void ConfiguracionI2C0();

   public:
    I2C(uint8_t portSCL, uint8_t pinSCL, uint8_t portSDA, uint8_t pinSDA, I2C_Type* i2c,
        mode_t mode, uint8_t slaveAddress);
    virtual ~I2C();

    void IRQHandler();
    void Write(void* message, uint32_t size);
    bool TriggerReading(uint8_t bytes);
	bool MasterIsReading();
	bool MasterIsWriting();
	bool MasterIsIdle();
	bool HadNACK();
    void* Read(void* message, uint32_t size);
    bool ReadNextByte(uint8_t *message);

    //Helper methods
    uint8_t read(void);
    void writeI2CAndWait(void *data_to_write, uint32_t size);
    void readI2CAndWait(uint8_t size);
};

#endif /* I2C_H_ */
