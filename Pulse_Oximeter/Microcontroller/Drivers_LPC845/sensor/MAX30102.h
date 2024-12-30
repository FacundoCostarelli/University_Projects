/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef MAX30102_H_
#define MAX30102_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
																															   #include "../Drivers_LPC845/I2C/I2C.h"
#include <I2C/I2C.h>
#include <cstring> // for memcpy

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
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
/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
#define min(x,y) ((x) < (y) ? (x) : (y));

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/


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



/***********************************************************************************************************************************
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
class MAX30102 {


   private:
		I2C i2c;

      void ConfiguracionSensorMAX30102(I2C i2c);//hecha por mi
      //Funciones de arduino hechas por SparkFun
      void maxim_sort_indices_descend(  int32_t  *pn_x, int32_t *pn_indx, int32_t n_size);
      void maxim_sort_ascend(int32_t  *pn_x, int32_t n_size);
      void maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance);
      void maxim_peaks_above_min_height( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height );
      void maxim_find_peaks( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num );

      void readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read);//hechas por mi
	  void readRegisterMAX30102NBytes(uint8_t regName, uint8_t size);//hechas por mi
	  void writeRegisterMAX30102(uint8_t regName, uint8_t regValue);//hechas por mi
	  //Funciones de arduino hechas por SparkFun
	  int16_t available(void);
	  void nextSample(void);
   public:

      MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress);//hecha por mi

      //Funcion de arduino hecha por SparkFun
      void maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, int32_t *pn_spo2, int8_t *pch_spo2_valid,
                           int32_t *pn_heart_rate, int8_t *pch_hr_valid);

      //Funciones hechas por mi con base en arduino de Sparkfun
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
