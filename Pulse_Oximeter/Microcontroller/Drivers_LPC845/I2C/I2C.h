/*******************************************************************************************************************************/ /**
                                                                                                                                   *
                                                                                                                                   * @file		I2C.h
                                                                                                                                   * @brief		Breve descripción del objetivo del Módulo
                                                                                                                                   * @date		26 ene. 2023
                                                                                                                                   * @author		Luca Rimondini
                                                                                                                                   *
                                                                                                                                   **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef I2C_H_
#define I2C_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "../LPC845.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
#if defined(__cplusplus)
extern "C" {
void I2C0_IRQHandler();
}
#endif

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
enum mode_t { master, slave };
/***********************************************************************************************************************************
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
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

    // configuracion particular
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

    //helper methods
    uint8_t read(void);
    void writeI2CAndWait(void *data_to_write, uint32_t size);
    void readI2CAndWait(uint8_t size);
};

#endif /* I2C_H_ */
