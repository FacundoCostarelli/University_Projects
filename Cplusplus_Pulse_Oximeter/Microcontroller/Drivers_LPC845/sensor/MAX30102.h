/*
 * MAX30102.h
 *
 *  Created on: October 2024
 *      Author: Facundo Costarelli
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la clase `MAX30102`, la cual implementa la comunicación y configuración del sensor MAX30102
 *        para la medición de frecuencia cardíaca (heart rate) y saturación de oxígeno (SpO2).
 *
 *      **Variables**
 *
 *      i2c:         Objeto de la clase `I2C` utilizado para realizar la comunicación I2C con el sensor MAX30102.
 *
 *      **Constantes**
 *
 *      FS:          Frecuencia de muestreo (sampling frequency), configurada por defecto a 25 Hz.
 *      BUFFER_SIZE: Tamaño del buffer, definido como `FS * 4` (4 segundos de muestra).
 *      MA4_SIZE:    Tamaño de la ventana de promediado móvil.
 *      SLAVE_ADDR_MAX30102:
 *                   Dirección I2C del sensor MAX30102 (0x57).
 *      Varias macros adicionales para registros del sensor (e.g., `FIFO_WR_PTR`, `MODE_CONFIG`, etc.) y configuraciones.
 *
 *      **Métodos Privados**
 *
 *      void ConfiguracionSensorMAX30102(I2C i2c):
 *                   Método que configura el sensor MAX30102 utilizando la interfaz I2C.
 *
 *      Métodos auxiliares de procesamiento de señales (e.g., detección de picos):
 *      - void maxim_sort_indices_descend(int32_t *pn_x, int32_t *pn_indx, int32_t n_size)
 *      - void maxim_sort_ascend(int32_t *pn_x, int32_t n_size)
 *      - void maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance)
 *      - void maxim_peaks_above_min_height(int32_t *pn_locs, int32_t *n_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height)
 *      - void maxim_find_peaks(int32_t *pn_locs, int32_t *n_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num)
 *                   Métodos para procesar las señales de IR y LED rojo del sensor, incluyendo la detección de picos y la eliminación de ruido.
 *
 *      Métodos de lectura/escritura de registros:
 *      - void readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read)
 *      - void readRegisterMAX30102NBytes(uint8_t regName, uint8_t size)
 *      - void writeRegisterMAX30102(uint8_t regName, uint8_t regValue)
 *                   Métodos para leer y escribir registros del sensor a través de I2C.
 *
 *      Métodos auxiliares:
 *      - int16_t available(void): Verifica si hay datos disponibles para leer del FIFO del sensor.
 *      - void nextSample(void): Avanza al siguiente dato en el FIFO del sensor.
 *
 *      **Métodos Públicos**
 *
 *      MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress):
 *                   Constructor de la clase. Inicializa el sensor con el módulo I2C, el modo de operación y la dirección del esclavo I2C.
 *
 *      void maxim_heart_rate_and_oxygen_saturation(...):
 *                   Método principal que calcula la frecuencia cardíaca y la saturación de oxígeno a partir de los datos del sensor.
 *
 *      Métodos relacionados con la lectura de datos FIFO:
 *      - void readFifoData(int32_t *bytesLeftToRead): Lee los datos del FIFO del sensor.
 *      - uint32_t getFIFORed(void): Devuelve el valor del LED rojo almacenado en el FIFO.
 *      - uint32_t getFIFOIR(void): Devuelve el valor del LED IR almacenado en el FIFO.
 *      - void resetFifoWrite(void): Reinicia el puntero de escritura del FIFO.
 *      - void getFifoReadAndWrite(uint8_t *write, uint8_t *read): Obtiene los punteros de lectura y escritura del FIFO.
 *
 *      Métodos auxiliares para gestión de datos:
 *      - uint32_t* getArrayIRValues(): Devuelve un puntero al array de valores de LED IR.
 *      - uint32_t* getArrayRValues(): Devuelve un puntero al array de valores de LED rojo.
 *      - bool continue_reading(): Indica si se debe continuar leyendo datos del sensor.
 *      - void reset_samples_counter(): Reinicia el contador de muestras.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the `MAX30102` class, which implements communication and configuration
 *        of the MAX30102 sensor for heart rate (HR) and oxygen saturation (SpO2) measurement.
 *
 *      **Variables**
 *
 *      i2c:         Instance of the `I2C` class used to perform I2C communication with the MAX30102 sensor.
 *
 *      **Constants**
 *
 *      FS:          Sampling frequency, set to 25 Hz by default.
 *      BUFFER_SIZE: Buffer size, defined as `FS * 4` (4 seconds of samples).
 *      MA4_SIZE:    Moving average window size.
 *      SLAVE_ADDR_MAX30102:
 *                   I2C address of the MAX30102 sensor (0x57).
 *      Various macros for sensor registers (e.g., `FIFO_WR_PTR`, `MODE_CONFIG`, etc.) and settings.
 *
 *      **Private Methods**
 *
 *      void ConfiguracionSensorMAX30102(I2C i2c):
 *                   Method that configures the MAX30102 sensor using the I2C interface.
 *
 *      Signal processing helper methods (e.g., peak detection):
 *      - void maxim_sort_indices_descend(int32_t *pn_x, int32_t *pn_indx, int32_t n_size)
 *      - void maxim_sort_ascend(int32_t *pn_x, int32_t n_size)
 *      - void maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance)
 *      - void maxim_peaks_above_min_height(int32_t *pn_locs, int32_t *n_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height)
 *      - void maxim_find_peaks(int32_t *pn_locs, int32_t *n_npks, int32_t *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num)
 *                   Methods for processing IR and red LED signals from the sensor, including peak detection and noise removal.
 *
 *      Register read/write methods:
 *      - void readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read)
 *      - void readRegisterMAX30102NBytes(uint8_t regName, uint8_t size)
 *      - void writeRegisterMAX30102(uint8_t regName, uint8_t regValue)
 *                   Methods to read and write sensor registers via I2C.
 *
 *      Auxiliary methods:
 *      - int16_t available(void): Checks if data is available to read from the sensor's FIFO.
 *      - void nextSample(void): Advances to the next sample in the sensor's FIFO.
 *
 *      **Public Methods**
 *
 *      MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress):
 *                   Class constructor. Initializes the sensor with the I2C module, operating mode, and I2C slave address.
 *
 *      void maxim_heart_rate_and_oxygen_saturation(...):
 *                   Main method that calculates heart rate and oxygen saturation from sensor data.
 *
 *      Methods related to FIFO data reading:
 *      - void readFifoData(int32_t *bytesLeftToRead): Reads data from the sensor's FIFO.
 *      - uint32_t getFIFORed(void): Returns the red LED value stored in the FIFO.
 *      - uint32_t getFIFOIR(void): Returns the IR LED value stored in the FIFO.
 *      - void resetFifoWrite(void): Resets the FIFO write pointer.
 *      - void getFifoReadAndWrite(uint8_t *write, uint8_t *read): Retrieves the FIFO read and write pointers.
 *
 *      Auxiliary methods for data management:
 *      - uint32_t* getArrayIRValues(): Returns a pointer to the array of IR LED values.
 *      - uint32_t* getArrayRValues(): Returns a pointer to the array of red LED values.
 *      - bool continue_reading(): Indicates whether to continue reading data from the sensor.
 *      - void reset_samples_counter(): Resets the sample counter.
 *
 * @param None
 */

#ifndef MAX30102_H_
#define MAX30102_H_


#include "../Drivers_LPC845/I2C/I2C.h"
#include <I2C/I2C.h>
#include <cstring>

#define FS 25    //sampling frequency
#define BUFFER_SIZE (FS * 4) // 4 son los segundos de muestra
#define MA4_SIZE 4 // DONOT CHANGE



#define SLAVE_ADDR_MAX30102 0x57

#define INTR_ENABLE_1 0x02
#define FIFO_WR_PTR 0x04
#define OV_COUNTER 0x05
#define FIFO_RD_PTR 0x06
#define FIFO_DATA 0x07

#define MODE_CONFIG 0x09
#define SPO2_CONFIG 0x0A
#define LED1_PA 0x0C
#define LED2_PA 0x0D

#define MULTILEDCONFIG1 0x11

#define BUFFER_LENGTH 32
#define SAMPLES_SIZE 100

#define min(x,y) ((x) < (y) ? (x) : (y));

//uch_spo2_table is approximated as  -45.060*ratioAverage* ratioAverage + 30.354 *ratioAverage + 94.845 ;
const uint8_t uch_spo2_table[184]={ 95, 95, 95, 96, 96, 96, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 99, 99, 99, 99,
              99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
              100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 99, 99, 98, 98, 98, 98, 98, 98, 97, 97,
              97, 97, 96, 96, 96, 96, 95, 95, 95, 94, 94, 94, 93, 93, 93, 92, 92, 92, 91, 91,
              90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85, 85, 84, 84, 83, 82, 82, 81, 81,
              80, 80, 79, 78, 78, 77, 76, 76, 75, 74, 74, 73, 72, 72, 71, 70, 69, 69, 68, 67,
              66, 66, 65, 64, 63, 62, 62, 61, 60, 59, 58, 57, 56, 56, 55, 54, 53, 52, 51, 50,
              49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 31, 30, 29,
              28, 27, 26, 25, 23, 22, 21, 20, 19, 17, 16, 15, 14, 12, 11, 10, 9, 7, 6, 5,
              3, 2, 1 } ;


class MAX30102
{
   private:
		I2C i2c;

      void ConfiguracionSensorMAX30102(I2C i2c);

      void maxim_sort_indices_descend(  int32_t  *pn_x, int32_t *pn_indx, int32_t n_size);
      void maxim_sort_ascend(int32_t  *pn_x, int32_t n_size);
      void maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance);
      void maxim_peaks_above_min_height( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height );
      void maxim_find_peaks( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num );

      void readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read);
	  void readRegisterMAX30102NBytes(uint8_t regName, uint8_t size);
	  void writeRegisterMAX30102(uint8_t regName, uint8_t regValue);

	  int16_t available(void);
	  void nextSample(void);

   public:
      MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress);

      void maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, int32_t *pn_spo2, int8_t *pch_spo2_valid,
                           int32_t *pn_heart_rate, int8_t *pch_hr_valid);

      void readFifoData(int32_t *bytesLeftToRead);
      uint32_t getFIFORed(void);
      uint32_t getFIFOIR(void);
      void resetFifoWrite();
      void getFifoReadAndWrite(uint8_t *write, uint8_t *read);

      uint32_t* getArrayIRValues();
      uint32_t* getArrayRValues();

      bool continue_reading();
      void reset_samples_counter();
};

#endif /* MAX30102_H_ */
