/*
 * MAX30102.c
 *
 *  Created on: October 2024
 *      Author: Facundo Costarelli & Ezequiel Lagatche
 */

#include "MAX30102.h"

/* ESP
 * @brief Variables estáticas para almacenar los datos procesados del sensor:
 *        `an_x` almacena los valores IR y `an_y` los valores rojos.
 *        También se define una estructura `Record` para manejar datos en buffers circulares.
 */

/* ENG
 * @brief Static variables to store processed sensor data:
 *        `an_x` stores IR values and `an_y` stores red values.
 *        A `Record` structure is also defined to manage data in circular buffers.
 */

static  int32_t an_x[ BUFFER_SIZE]; // IR data
static  int32_t an_y[ BUFFER_SIZE]; // Red data

struct Record
{
  uint32_t red[SAMPLES_SIZE]; 	// ESP: Buffer para datos de LED Rojo. ENG: Buffer for Red LED readings
  uint32_t IR[SAMPLES_SIZE]; 	// ESP: Buffer para datos de LED Infrarrojo. ENG: Buffer for IR LED readings
  uint8_t head; 				// ESP: Indice para insertar valores de entrada. ENG: Index for inserting new values
  uint8_t tail; 				// ESP: Indice para leer valores de salida. ENG: Index for reading values (not used currently)
} sense;




/* ESP
 * @brief Constructor de la clase MAX30102.
 *        Configura la instancia del sensor y llama a la función de configuración inicial.
 *
 * @param m_i2c Puntero al módulo I2C utilizado.
 * @param mode Modo de operación del I2C.
 * @param slaveAddress Dirección I2C del sensor MAX30102.
 */

/* ENG
 * @brief Constructor for the MAX30102 class.
 *        Configures the sensor instance and calls the initial setup function.
 *
 * @param m_i2c Pointer to the I2C module used.
 * @param mode I2C operation mode.
 * @param slaveAddress I2C address of the MAX30102 sensor.
 */

MAX30102::MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress)
	:i2c(0, 0, 0, 0, m_i2c, mode, slaveAddress)
{
	ConfiguracionSensorMAX30102(i2c); // ESP: Configura el sensor. ENG: Configures the sensor.
}




/* ESP
 * @brief Configura los registros del sensor MAX30102 para inicializarlo correctamente.
 *        Realiza un reinicio y configura los modos de operación, registros de SPO2, y amplitudes de los LEDs.
 *
 * @param i2c Instancia del I2C utilizada para la comunicación.
 */

/* ENG
 * @brief Configures the registers of the MAX30102 sensor for proper initialization.
 *        Resets and configures operation modes, SPO2 registers, and LED amplitudes.
 *
 * @param i2c I2C instance used for communication.
 */

void MAX30102::ConfiguracionSensorMAX30102(I2C i2c)
{
	 	uint8_t datos[2];  // ESP: Array para datos de escritura. ENG: Array for writing data.
	    uint8_t readData;   // ESP: Variable para lectura de verificación. ENG: Variable for verification read.

	    // ESP: Paso 1 --> Reset de punteros FIFO Write, Read y Overflow Counter. ENG: Step 1 --> Reset FIFO Write, Read pointers, and Overflow Counter
	    datos[0] = FIFO_WR_PTR;  // ESP: Dirección del puntero de escritura. ENG: Address of the write pointer.
	    datos[1] = 0x00;         // ESP: Reinicia el puntero. ENG: Resets the pointer.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(FIFO_WR_PTR, &readData);

	    datos[0] = OV_COUNTER;  // ESP: Dirección del contador de desbordamiento. ENG: Address of the overflow counter.
	    datos[1] = 0x00;        // ESP: Reinicia el contador. ENG: Resets the counter.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(OV_COUNTER, &readData);

	    datos[0] = FIFO_RD_PTR;  // ESP: Dirección del puntero de lectura. ENG: Address of the read pointer.
	    datos[1] = 0x00;         // ESP: Reinicia el puntero. ENG: Resets the pointer.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(FIFO_RD_PTR, &readData);


	    datos[0] = 0x08;  // ESP: Dirección del registro FIFO_CONFIG. ENG: Address of the FIFO_CONFIG register.
		datos[1] = 0x50;  // ESP: Configura promedio de 4 muestras. ENG: Configures 4-sample averaging.
		i2c.writeI2CAndWait(datos, 2);
		readRegisterMAX30102(0x08, &readData);

		// ESP: Paso 2 --> Configurar el registro de MODE.
	    // ENG: Step 2 --> Configure the MODE register.
	    datos[0] = MODE_CONFIG;  // ESP: Dirección del registro MODE_CONFIG. ENG: Address of the MODE_CONFIG register.
	    datos[1] = 1 << 6;       // ESP: Aplico un Reset primero al registro. ENG: Apply Reset first to the register.
	    i2c.writeI2CAndWait(datos, 2);
	     readRegisterMAX30102(MODE_CONFIG, &readData);

	    //CAMBIAR MODO para que sea multimodo
	    datos[0] = MODE_CONFIG;  // ESP: Dirección del registro MODE_CONFIG. ENG: Address of the MODE_CONFIG register.
	    datos[1] = 0x07;         // ESP: Modo multiled. ENG: Multi-LED mode.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(MODE_CONFIG, &readData);


	    datos[0] = MULTILEDCONFIG1;  // ESP: Registro de control de modo multiled. ENG: Multi-LED mode control register.
		datos[1] = 0x21; // ESP: SLOT 1 -> RED, SLOT 2 -> IR. ENG: SLOT 1 -> RED, SLOT 2 -> IR.
		i2c.writeI2CAndWait(datos, 2);
		readRegisterMAX30102(MULTILEDCONFIG1, &readData);

		// ESP: Paso 3 --> Configurar el registro de SPO2.
	    // ENG: Step 3 --> Configure the SPO2 register.
	    datos[0] = SPO2_CONFIG;  // ESP: Registro de configuración de SPO2. ENG: SPO2 configuration register.
	    //datos[1] = 0x6F;  	 // Alternative --> Configure for 400 samples/sec, 411us pulse width
	    //datos[1] = 0x04;		 // Alternative --> Configure for 100 samples/sec, 69us pulse width
	    //datos[1] = 0x67; 		 // Alternative   --> for 100 samples/sec, 411us pulse width
	    datos[1] = 0x27; 		 // ESP: Configura a 100 muestras/s con amplitud de LED máxima. ENG: Configures 100 samples/s with maximum LED amplitude.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(SPO2_CONFIG, &readData);

	    // ESP: Paso 4 --> Establecer la corriente del LED1 (Rojo).
	    // ENG: Step 4 --> Set the LED1 (Red) current.
	    datos[0] = LED1_PA;  // ESP: Registro de amplitud de LED1. ENG: LED1 pulse amplitude register.
	    datos[1] = 0x3c;     // ESP: Máxima corriente. ENG: Maximum current.
	    i2c.writeI2CAndWait(datos, 2);
	     readRegisterMAX30102(LED1_PA, &readData);

	    // ESP: Paso 5 --> Establecer la corriente del LED2 (Infrarrojo).
	    // ENG: Step 5 --> Set the LED2 (IR) current.
	    datos[0] = LED2_PA;  // ESP: Registro de amplitud de LED2. ENG: LED2 pulse amplitude register.
	    datos[1] = 0x3c;     // ESP: Máxima corriente. ENG: Maximum current.
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(LED2_PA, &readData);
}




/* ESP
 * @brief Lee un byte de un registro específico del sensor MAX30102.
 *
 * @param regName Dirección del registro a leer.
 * @param regValue_read Puntero para almacenar el valor leído.
 */

/* ENG
 * @brief Reads one byte from a specific register of the MAX30102 sensor.
 *
 * @param regName Address of the register to read.
 * @param regValue_read Pointer to store the read value.
 */

void MAX30102::readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read)
{
	 	uint8_t datos[1]; 				// ESP: Array para enviar la dirección del registro. ENG: Array to send the register address.
	    datos[0] = regName;				// ESP: Asigna la dirección al array. ENG: Assigns the address to the array.
	    i2c.writeI2CAndWait(datos, 1);  // ESP: Escribe la dirección en el bus I2C. ENG: Writes the address on the I2C bus.

	    //perform reading
	    i2c.readI2CAndWait(1);			// ESP: Realiza la lectura en el bus I2C. ENG: Performs the read operation on the I2C bus.

		i2c.Read(regValue_read, 1); 	// ESP: Almacena el valor leído en el puntero proporcionado. ENG: Stores the read value in the provided pointer.
}




/* ESP
 * @brief Lee múltiples bytes de un registro específico del sensor MAX30102.
 *
 * @param regName Dirección del registro a leer.
 * @param size Cantidad de bytes a leer.
 */

/* ENG
 * @brief Reads multiple bytes from a specific register of the MAX30102 sensor.
 *
 * @param regName Address of the register to read.
 * @param size Number of bytes to read.
 */

void MAX30102::readRegisterMAX30102NBytes(uint8_t regName, uint8_t size)
{
	 	uint8_t datos[1];					// ESP: Array para enviar la dirección del registro. ENG: Array to send the register address.
	    datos[0] = regName;					// ESP: Asigna la dirección al array. ENG: Assigns the address to the array.
	    i2c.writeI2CAndWait(datos, 1);		// ESP: Escribe la dirección en el bus I2C. ENG: Writes the address on the I2C bus.
	    i2c.readI2CAndWait(size);			// ESP: Realiza la lectura de múltiples bytes en el bus I2C. ENG: Reads multiple bytes from the I2C bus.
}




/* ESP
 * @brief Escribe un valor en un registro específico del sensor MAX30102.
 *
 * @param regName Dirección del registro donde escribir.
 * @param regValue Valor a escribir.
 */

/* ENG
 * @brief Writes a value to a specific register of the MAX30102 sensor.
 *
 * @param regName Address of the register to write to.
 * @param regValue Value to write.
 */

void MAX30102::writeRegisterMAX30102(uint8_t regName, uint8_t regValue)
{
	  uint8_t datos[2];					// ESP: Array para enviar dirección y valor. ENG: Array to send the address and value.
	  datos[0] = regName;				// ESP: Dirección del registro. ENG: Register address.
	  datos[1] = regValue;				// ESP: Valor a escribir. ENG: Value to write.
	  i2c.writeI2CAndWait(datos, 2);	// ESP: Realiza la escritura en el bus I2C. ENG: Performs the write operation on the I2C bus.
}


// ESP: Declaro e inicializo una variable que almacena la cantidad de muestras.
// ENG: Declare and initialization of a variable that stores the samples quantity.
uint32_t cant_samples = 0;


/* ESP
 * @brief Lee datos del FIFO del sensor MAX30102.
 *
 * @param bytesLeftToRead Puntero a la cantidad de bytes que faltan leer.
 */

/* ENG
 * @brief Reads data from the FIFO of the MAX30102 sensor.
 *
 * @param bytesLeftToRead Pointer to the number of bytes left to read.
 */

void MAX30102::readFifoData(int32_t *bytesLeftToRead)
{
	while (*bytesLeftToRead > 0 )
	{
		  int32_t toGet = *bytesLeftToRead;
		  if (toGet > BUFFER_LENGTH)
		  {
			  // ESP: Ajusta `toGet` para evitar lectura parcial de muestras.
			  // ENG: Adjust `toGet` to avoid partial reading of samples.
			  // Additional comment:
			  // If toGet is 32 this is bad because we read 6 bytes (Red+IR * 3 = 6) at a time
			  // 32 % 6 = 2 left over. We don't want to request 32 bytes, we want to request 30.
			  // 32 % 9 (Red+IR+GREEN) = 5 left over. We want to request 27.
			  // Trim toGet to be a multiple of the samples we need to read
			  toGet = BUFFER_LENGTH - (BUFFER_LENGTH % 6);
		  }

		  *bytesLeftToRead -= toGet; // ESP: Actualiza los bytes restantes. ENG: Updates the remaining bytes.

		  // ESP: Lee los datos del FIFO.
		  // ENG: Reads the FIFO data.
		  readRegisterMAX30102NBytes(FIFO_DATA, toGet);

		  while (toGet > 0)
		  {
			 sense.head++;   					// ESP: Avanza el índice del buffer circular. ENG: Advances the circular buffer index.
			 sense.head %= SAMPLES_SIZE;		// ESP: Condición de envoltura. ENG: Wrap-around condition.

			 cant_samples ++;					// ESP: Incrementa el contador de muestras. ENG: Increment the sample counter.

			 uint8_t temp[sizeof(uint32_t)];  // ESP: Array de 4 bytes que buscamos convertir a int long. ENG: Array of 4 bytes that we will convert into long
			 uint32_t tempLong;

			 // ESP: Lee 3 bytes del LED Rojo.
			 // ENG: Reads 3 bytes from the Red LED.
			 temp[3] = 0;
			 temp[2] = i2c.read();
			 temp[1] = i2c.read();
			 temp[0] = i2c.read();

			 memcpy(&tempLong, temp, sizeof(tempLong));		// ESP: Convertir array a int long. ENG: Convert array to int long.
			 tempLong &= 0x3FFFF;  							// ESP: Máscara para 18 bits. ENG: Mask for 18 bits.
			 sense.red[sense.head] = tempLong;  			// ESP: Almacena en el buffer rojo. ENG: Stores in the red buffer.

			 // ESP: Lee 3 bytes del LED IR.
			 // ENG: Reads 3 bytes from the IR LED.
			 temp[3] = 0;
			 temp[2] = i2c.read();
			 temp[1] = i2c.read();
			 temp[0] = i2c.read();

			 memcpy(&tempLong, temp, sizeof(tempLong));		// ESP: Convertir array a int long. ENG: Convert array to int long.
			 tempLong &= 0x3FFFF;							// ESP: Máscara para 18 bits. ENG: Mask for 18 bits.
			 sense.IR[sense.head] = tempLong;				// ESP: Almacena en el buffer infrarrojo. ENG: Stores in the infrared buffer.

			 toGet -= 6;									// ESP: Decrementa el contador de bytes por muestra. ENG: Decrease byte counter per sample.
		  }
	  }
}




/* ESP
 * @brief Verifica si quedan muestras por leer del sensor.
 *
 * @return true si aún faltan muestras por leer, false de lo contrario.
 */

/* ENG
 * @brief Checks if there are remaining samples to read from the sensor.
 *
 * @return true if samples are still to be read, false otherwise.
 */

bool MAX30102::continue_reading()
{
	return cant_samples < SAMPLES_SIZE;	// ESP: Retorna true si no se alcanzó el tamaño del buffer. ENG: Returns true if buffer size is not reached.
}




/* ESP
 * @brief Reinicia el contador de muestras leídas del sensor.
 */

/* ENG
 * @brief Resets the counter for samples read from the sensor.
 */

void MAX30102::reset_samples_counter()
{
	cant_samples = 0; // ESP: Reinicia el contador a cero. ENG: Resets the counter to zero.
}




/* ESP
 * @brief Ordena índices en orden descendente basado en los valores asociados.
 *
 * @param pn_x Array con los valores a ordenar.
 * @param pn_indx Array de índices a ordenar.
 * @param n_size Tamaño del array.
 */

/* ENG
 * @brief Sorts indices in descending order based on the associated values.
 *
 * @param pn_x Array of values to sort.
 * @param pn_indx Array of indices to sort.
 * @param n_size Size of the array.
 */

void MAX30102::maxim_sort_indices_descend(  int32_t  *pn_x, int32_t *pn_indx, int32_t n_size)
{
  int32_t i, j, n_temp;
  for (i = 1; i < n_size; i++)
  {
    n_temp = pn_indx[i];

    for (j = i; j > 0 && pn_x[n_temp] > pn_x[pn_indx[j-1]]; j--)
      pn_indx[j] = pn_indx[j-1]; 	// ESP: Desplaza índices hacia adelante. ENG: Shifts indices forward.

    pn_indx[j] = n_temp; 			// ESP: Inserta el índice en la posición correcta. ENG: Inserts the index in the correct position.
  }
}




/* ESP
 * @brief Ordena un array en orden ascendente.
 *
 * @param pn_x Array a ordenar.
 * @param n_size Tamaño del array.
 */

/* ENG
 * @brief Sorts an array in ascending order.
 *
 * @param pn_x Array to sort.
 * @param n_size Size of the array.
 */

void MAX30102::maxim_sort_ascend(int32_t  *pn_x, int32_t n_size)
{
  int32_t i, j, n_temp;

  for (i = 1; i < n_size; i++)
  {
    n_temp = pn_x[i];

    for (j = i; j > 0 && n_temp < pn_x[j-1]; j--)
        pn_x[j] = pn_x[j-1];		// ESP: Desplaza valores hacia adelante. ENG: Shifts values forward.

    pn_x[j] = n_temp;				// ESP: Inserta el valor en la posición correcta. ENG: Inserts the value in the correct position.
  }
}




/* ESP
 * @brief Elimina picos que están demasiado cerca unos de otros.
 *
 * @param pn_locs Array de ubicaciones de los picos.
 * @param pn_npks Cantidad de picos encontrados.
 * @param pn_x Array de valores asociados a los picos.
 * @param n_min_distance Distancia mínima entre picos.
 */

/* ENG
 * @brief Removes peaks that are too close to each other.
 *
 * @param pn_locs Array of peak locations.
 * @param pn_npks Number of peaks found.
 * @param pn_x Array of values associated with peaks.
 * @param n_min_distance Minimum distance between peaks.
 */

void MAX30102::maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance)
{
  int32_t i, j, n_old_npks, n_dist;

  // ESP: Ordena los picos por magnitud. Ordena picos del mas grande al mas chico. ENG: Sort peaks by magnitude. Order peaks from large to small.
  maxim_sort_indices_descend( pn_x, pn_locs, *pn_npks );

  for ( i = -1; i < *pn_npks; i++ ){
    n_old_npks = *pn_npks;
    *pn_npks = i+1;
    for ( j = i+1; j < n_old_npks; j++ ){
      n_dist =  pn_locs[j] - ( i == -1 ? -1 : pn_locs[i] );
      if ( n_dist > n_min_distance || n_dist < -n_min_distance )
        pn_locs[(*pn_npks)++] = pn_locs[j]; // ESP: Mantiene los picos suficientemente separados. ENG: Keeps peaks sufficiently separated.
    }
  }

  maxim_sort_ascend( pn_locs, *pn_npks ); // ESP: Reordena los picos en orden ascendente. ENG: Reorders peaks in ascending order.
}




/* ESP
 * @brief Detecta picos que superan una altura mínima.
 *
 * @param pn_locs Array donde almacenar las ubicaciones de los picos.
 * @param n_npks Cantidad de picos detectados.
 * @param pn_x Array de valores donde buscar picos.
 * @param n_size Tamaño del array.
 * @param n_min_height Altura mínima para considerar un pico.
 */

/* ENG
 * @brief Detects peaks that exceed a minimum height.
 *
 * @param pn_locs Array to store the locations of peaks.
 * @param n_npks Number of peaks detected.
 * @param pn_x Array of values to search for peaks.
 * @param n_size Size of the array.
 * @param n_min_height Minimum height to consider as a peak.
 */

void MAX30102::maxim_peaks_above_min_height( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height )
{
  int32_t i = 1, n_width;
  *n_npks = 0; // ESP: Inicializa el contador de picos. ENG: Initializes the peak counter.

  while (i < n_size-1){
    if (pn_x[i] > n_min_height && pn_x[i] > pn_x[i-1])
    {
      n_width = 1; // ESP: Busca borde izquierdo de picos potenciales. ENG: Find left edge of potential peaks

      while (i+n_width < n_size && pn_x[i] == pn_x[i+n_width])  // ESP: Busca picos planos. ENG: find flat peaks.
        n_width++; // ESP: Maneja picos planos. ENG: Handles flat peaks.

      if (pn_x[i] > pn_x[i+n_width] && (*n_npks) < 15 )
      {
        pn_locs[(*n_npks)++] = i; // ESP: Busca borde derecho de picos potenciales. ENG: Find right edge of peaks.

        i += n_width+1; // ESP: Para picos planos, la ubicación del pico es en borde izquierdo. ENG: For flat peaks, peak location is left edge
      }
      else
        i += n_width;
    }
    else
      i++;
  }
}

/* ESP
 * @brief Encuentra picos que cumplen con condiciones específicas de altura mínima, distancia mínima y cantidad máxima.
 *
 * @param pn_locs Array donde almacenar las ubicaciones de los picos.
 * @param n_npks Cantidad de picos encontrados.
 * @param pn_x Array de valores donde buscar picos.
 * @param n_size Tamaño del array.
 * @param n_min_height Altura mínima para considerar un pico.
 * @param n_min_distance Distancia mínima entre picos.
 * @param n_max_num Cantidad máxima de picos permitidos.
 */

/* ENG
 * @brief Finds peaks that meet specific conditions of minimum height, minimum distance, and maximum number.
 *
 * @param pn_locs Array to store the locations of peaks.
 * @param n_npks Number of peaks found.
 * @param pn_x Array of values to search for peaks.
 * @param n_size Size of the array.
 * @param n_min_height Minimum height to consider as a peak.
 * @param n_min_distance Minimum distance between peaks.
 * @param n_max_num Maximum number of allowed peaks.
 */

void MAX30102::maxim_find_peaks( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num )
{
  maxim_peaks_above_min_height( pn_locs, n_npks, pn_x, n_size, n_min_height );		// ESP: Encuentra picos por altura mínima. ENG: Finds peaks by minimum height.
  maxim_remove_close_peaks( pn_locs, n_npks, pn_x, n_min_distance );				// ESP: Elimina picos demasiado cercanos. ENG: Removes peaks that are too close.
  *n_npks = min( *n_npks, n_max_num );												// ESP: Limita la cantidad de picos al máximo permitido. ENG: Limits the number of peaks to the maximum allowed.
}




/* ESP
 * @brief Calcula la frecuencia cardíaca y la saturación de oxígeno (SpO2) a partir de los datos IR y rojos del sensor.
 *
 * @param pun_ir_buffer Buffer con los datos IR.
 * @param n_ir_buffer_length Longitud del buffer IR.
 * @param pun_red_buffer Buffer con los datos rojos.
 * @param pn_spo2 Puntero donde almacenar el valor calculado de SpO2.
 * @param pch_spo2_valid Bandera que indica si el valor de SpO2 es válido.
 * @param pn_heart_rate Puntero donde almacenar el valor calculado de la frecuencia cardíaca.
 * @param pch_hr_valid Bandera que indica si el valor de la frecuencia cardíaca es válido.
 */

/* ENG
 * @brief Calculates heart rate and oxygen saturation (SpO2) from the sensor's IR and red data.
 *
 * @param pun_ir_buffer Buffer with IR data.
 * @param n_ir_buffer_length Length of the IR buffer.
 * @param pun_red_buffer Buffer with red data.
 * @param pn_spo2 Pointer to store the calculated SpO2 value.
 * @param pch_spo2_valid Flag indicating if the SpO2 value is valid.
 * @param pn_heart_rate Pointer to store the calculated heart rate value.
 * @param pch_hr_valid Flag indicating if the heart rate value is valid.
 */

void MAX30102::maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, int32_t *pn_spo2, int8_t *pch_spo2_valid,
                int32_t *pn_heart_rate, int8_t *pch_hr_valid)
{
	  // ESP: Calcula la media de los valores IR.
	  // ENG: Calculates the mean of the IR values.
	  uint32_t un_ir_mean ;
	  int32_t k, n_i_ratio_count;
	  int32_t i, n_exact_ir_valley_locs_count, n_middle_idx;
	  int32_t n_th1, n_npks;
	  int32_t an_ir_valley_locs[15] ;
	  int32_t n_peak_interval_sum;

	  int32_t n_y_ac, n_x_ac;
	  int32_t n_spo2_calc;
	  int32_t n_y_dc_max, n_x_dc_max;
	  int32_t n_y_dc_max_idx, n_x_dc_max_idx;
	  int32_t an_ratio[5], n_ratio_average;
	  int32_t n_nume, n_denom ;

	  // ESP: Calculo del Heart Rate. ENG: Calculus of the Heart Rate.

	  // ESP: Calcula la media de CC y resta la CC de infrarojo. 		ENG: Calculates DC mean and subtract DC from infrared.
	  un_ir_mean =0;
	  for (k=0 ; k<n_ir_buffer_length ; k++ ) un_ir_mean += pun_ir_buffer[k] ;
	  un_ir_mean =un_ir_mean/n_ir_buffer_length ;

	  // ESP: Eliminea CC e invierte la señal para que podamos usar el detector de picos como detector de valles.
	  // ENG: Removes DC and inverts signal so that we can use peak detector as valley detector.
	  for (k=0 ; k<n_ir_buffer_length ; k++ )
		an_x[k] = -1*(pun_ir_buffer[k] - un_ir_mean) ;// ESP: Invierte la señal para calcular los picos facilmente. ENG: Invert the signal to easily calculate peaks.

	  // ESP: Media móvil de 4 puntos --> elimino el ruido y dejo pasar las variaciones mas lentas.
	  // ENG: Moving average of 4 points --> I eliminate the noise and let the slower variations pass through.
	  for(k=0; k< BUFFER_SIZE-MA4_SIZE; k++)
	  {
		an_x[k]=( an_x[k]+an_x[k+1]+ an_x[k+2]+ an_x[k+3])/(int)4;
	  }

	  // ESP: Calcula el umbral para detectar picos.
	  // ENG: Calculates threshold for detect peaks.
	  n_th1=0;
	  for ( k=0 ; k<BUFFER_SIZE ;k++)
	  {
		n_th1 +=  an_x[k];
	  }
	  n_th1=  n_th1/ ( BUFFER_SIZE);
	  if( n_th1<30) n_th1=30; // ESP: Minimo permitido. ENG: Min allowed.
	  if( n_th1>60) n_th1=60; // ESP: Máximo permitido. ENG: Max allowed.

	  for ( k=0 ; k<15;k++) an_ir_valley_locs[k]=0;

	  // ESP: Desde que invertimos la señal, usamos el detector de picos como detector de valles.
	  // ENG: Since we flipped signal, we use peak detector as valley detector.
	  maxim_find_peaks( an_ir_valley_locs, &n_npks, an_x, BUFFER_SIZE, n_th1, 4, 15 ); // ESP: altura_pico, distancia_pico, número_max_picos. ENG: peak_height, peak_distance, max_num_peaks
	  n_peak_interval_sum =0;
	  if (n_npks>=2)
	  {
		// ESP: Si hay 2 o más picos detectados, entonces se saca un promedio del intervalo de los picos.
		// ENG: If there are 2 or more peaks detected, then it is taken an average of the peak interval.
		for (k=1; k<n_npks; k++) n_peak_interval_sum += (an_ir_valley_locs[k] -an_ir_valley_locs[k -1] ) ;
		n_peak_interval_sum =n_peak_interval_sum/(n_npks-1);
		// ENG: Apply formula to calculate heart rate.
		// ESP: Aplica formula para calcular el heart rate.
		*pn_heart_rate =(int32_t)( (FS*60)/ n_peak_interval_sum );
		*pch_hr_valid  = 1;
	  }
	  else
	  {
		// ENG: Case where it is unable to calculate because # of peaks are too small.
		// ESP: Caso en que no se puede calcular porque el número de picos es demasiado pequeño.
		*pn_heart_rate = -999;
		*pch_hr_valid  = 0;
	  }

	  // ESP: Calculo de SPO2.
	  // ENG: Calculus of SPO2.


	  // ESP: Cargar nuevamente el valor crudo para el cálculo de SPO2: RED(=y) e IR(=X).
	  // ENG: Load raw value again for SPO2 calculation : RED(=y) and IR(=X).
	  for (k=0 ; k<n_ir_buffer_length ; k++ )
	  {
		  an_x[k] =  pun_ir_buffer[k] ;
		  an_y[k] =  pun_red_buffer[k] ;
	  }

	  // ESP: Encuentra el mínimo preciso cerca de an_ir_valley_locs.
	  // ENG: Find precise min near an_ir_valley_locs.
	  n_exact_ir_valley_locs_count =n_npks;

	  // ESP: Usando exact_ir_valley_locs, se encuentran ir-red DC y ir-red AC para calibración de SPO2 an_ratio.
	  // Queremos el máximo de CA/CC de la señal cruda.
	  // ENG: Using exact_ir_valley_locs , it is found ir-red DC andir-red AC for SPO2 calibration an_ratio
	  // We want to find AC/DC maximum of raw
	  n_ratio_average =0;
	  n_i_ratio_count = 0;

	  for(k=0; k< 5; k++) an_ratio[k]=0;

	  for (k=0; k< n_exact_ir_valley_locs_count; k++)
	  {
		// ESP: Verificamos que la posición de cada valle no este fuera de rango.
		// ENG: We check that the position of each valley is not out of range.
		if (an_ir_valley_locs[k] > BUFFER_SIZE )
		{
		   // ESP: No se usa SPO2 en caso de que la localización del valle esté fuera de rango.
		   // ENG: It is not used SPO2 in case of valley loc is out of range.
		  *pn_spo2 =  -999 ;
		  *pch_spo2_valid  = 0;
		  return;
		}
	  }

	  // ESP: Se busca el máximo entre dos ubicaciones de valle y se utiliza una relación entre el componente de CA de Ir y Rojo
	  // y el componente de CC de Ir y Rojo para SPO2.
	  // ENG: It is found the max between two valley locations and it is use an_ratio betwen AC compoent of Ir & Red
	  // and DC compoent of Ir & Red for SPO2
	  for (k=0; k< n_exact_ir_valley_locs_count-1; k++){
		n_y_dc_max= -16777216 ;
		n_x_dc_max= -16777216;

		if (an_ir_valley_locs[k+1]-an_ir_valley_locs[k] >3){
			for (i=an_ir_valley_locs[k]; i< an_ir_valley_locs[k+1]; i++){
			  if (an_x[i]> n_x_dc_max) {n_x_dc_max =an_x[i]; n_x_dc_max_idx=i;}
			  if (an_y[i]> n_y_dc_max) {n_y_dc_max =an_y[i]; n_y_dc_max_idx=i;}
		  }
		  n_y_ac= (an_y[an_ir_valley_locs[k+1]] - an_y[an_ir_valley_locs[k]] )*(n_y_dc_max_idx -an_ir_valley_locs[k]); // ESP: Rojo. ENG: Red.
		  n_y_ac=  an_y[an_ir_valley_locs[k]] + n_y_ac/ (an_ir_valley_locs[k+1] - an_ir_valley_locs[k])  ;
		  n_y_ac=  an_y[n_y_dc_max_idx] - n_y_ac; // ESP: Se restan las componentes CC lineales de la señal cruda. ENG: It is Subracted linear DC compoenents from raw

		  n_x_ac= (an_x[an_ir_valley_locs[k+1]] - an_x[an_ir_valley_locs[k] ] )*(n_x_dc_max_idx -an_ir_valley_locs[k]); // ESP: Infrarojo. ENG: Infrared.
		  n_x_ac=  an_x[an_ir_valley_locs[k]] + n_x_ac/ (an_ir_valley_locs[k+1] - an_ir_valley_locs[k]);
		  n_x_ac=  an_x[n_y_dc_max_idx] - n_x_ac; // ESP: Se restan las componentes CC lineales de la señal cruda. ENG: It is Subracted linear DC compoenents from raw

		  n_nume=( n_y_ac *n_x_dc_max)>>7 ; // ESP: Preparar X100 para preservar el valor flotante. ENG: Prepare X100 to preserve floating value
		  n_denom= ( n_x_ac *n_y_dc_max)>>7;

		  if (n_denom>0  && n_i_ratio_count <5 &&  n_nume != 0)
		  {
			an_ratio[n_i_ratio_count]= (n_nume*100)/n_denom ; // ESP: La fórmula es (n_y_ac *n_x_dc_max) / (n_x_ac *n_y_dc_max). ENG: The formula is ( n_y_ac *n_x_dc_max) / ( n_x_ac *n_y_dc_max) ;
			n_i_ratio_count++;
		  }
		}
	  }
	  // ESP: Se elige el valor medio ya que la señal PPG puede variar de un latido a otro.
	  // ENG: It is chosen median value since PPG signal may varies from beat to beat.
	  maxim_sort_ascend(an_ratio, n_i_ratio_count);
	  n_middle_idx= n_i_ratio_count/2;

	  if (n_middle_idx >1)
		n_ratio_average =( an_ratio[n_middle_idx-1] +an_ratio[n_middle_idx])/2;
	  else
		n_ratio_average = an_ratio[n_middle_idx ];


	  if( n_ratio_average>2 && n_ratio_average <184){
		n_spo2_calc= uch_spo2_table[n_ratio_average] ;
		*pn_spo2 = n_spo2_calc ;
		*pch_spo2_valid  = 1;//  float_SPO2 =  -45.060*n_ratio_average* n_ratio_average/10000 + 30.354 *n_ratio_average/100 + 94.845 ;  // for comparison with table
	  }
	  else{
		// ESP: No se usa SPO2 en caso de que la tasa media esté fuera de rango.
		// ENG: It is not used SPO2 in case of signal an_ratio is out of range
		*pn_spo2 =  -999 ;
		*pch_spo2_valid  = 0;
	  }
	}




/* ESP
 * @brief Verifica la cantidad de muestras disponibles en el buffer circular.
 *        Calcula la diferencia entre el índice de escritura (head) y el de lectura (tail).
 *
 * @return Número de muestras disponibles.
 */

/* ENG
 * @brief Checks the number of samples available in the circular buffer.
 *        Calculates the difference between the write index (head) and the read index (tail).
 *
 * @return Number of available samples.
 */

int16_t MAX30102::available(void)
{
  int16_t numberOfSamples = sense.head - sense.tail; 		// ESP: Calcula la diferencia entre índices. ENG: Calculates the difference between indices.

  if (numberOfSamples < 0) numberOfSamples += SAMPLES_SIZE; // ESP: Ajusta en caso de envoltura del buffer. ENG: Adjusts for buffer wrap-around.

  return (numberOfSamples); 								// ESP: Retorna el número de muestras disponibles. ENG: Returns the number of available samples.
}




/* ESP
 * @brief Avanza el índice de lectura (tail) del buffer circular si hay nuevas muestras disponibles.
 */

/* ENG
 * @brief Advances the read index (tail) of the circular buffer if new samples are available.
 */
void MAX30102::nextSample(void)
{
  if(available()) // ESP: Verifica si hay datos disponibles antes de avanzar. ENG: Checks if data is available before advancing.
  {
    sense.tail++; 				// ESP: Incrementa el índice de lectura. ENG: Increments the read index.
    sense.tail %= SAMPLES_SIZE; // ESP: Ajusta en caso de envoltura del buffer. ENG: Adjusts for buffer wrap-around.
  }
}




/* ESP
 * @brief Obtiene el último valor del LED Rojo almacenado en el buffer circular.
 *
 * @return Último valor del LED Rojo.
 */

/* ENG
 * @brief Retrieves the last Red LED value stored in the circular buffer.
 *
 * @return Last Red LED value.
 */

uint32_t MAX30102::getFIFORed(void)
{
  return (sense.red[sense.tail]); // ESP: Retorna el valor almacenado en la posición actual del tail. ENG: Returns the value stored at the current tail position.
}




/* ESP
 * @brief Obtiene el último valor del LED IR almacenado en el buffer circular.
 *
 * @return Último valor del LED IR.
 */

/* ENG
 * @brief Retrieves the last IR LED value stored in the circular buffer.
 *
 * @return Last IR LED value.
 */

uint32_t MAX30102::getFIFOIR(void)
{
  return (sense.IR[sense.tail]); // ESP: Retorna el valor almacenado en la posición actual del tail. ENG: Returns the value stored at the current tail position.
}




/* ESP
 * @brief Obtiene un puntero al array completo de valores IR almacenados en el buffer.
 *
 * @return Puntero al array de valores IR.
 */

/* ENG
 * @brief Retrieves a pointer to the full array of IR values stored in the buffer.
 *
 * @return Pointer to the IR values array.
 */

uint32_t* MAX30102::getArrayIRValues()
{
	return sense.IR; // ESP: Retorna el puntero al array IR. ENG: Returns the pointer to the IR array.
}




/* ESP
 * @brief Obtiene un puntero al array completo de valores Rojos almacenados en el buffer.
 *
 * @return Puntero al array de valores Rojos.
 */

/* ENG
 * @brief Retrieves a pointer to the full array of Red values stored in the buffer.
 *
 * @return Pointer to the Red values array.
 */

uint32_t* MAX30102::getArrayRValues()
{
	return sense.red; // ESP: Retorna el puntero al array de valores Rojos. ENG: Returns the pointer to the Red values array.
}




/* ESP
 * @brief Resetea el puntero de escritura del registro FIFO del sensor MAX30102.
 */

/* ENG
 * @brief Resets the write pointer of the MAX30102 sensor's FIFO register.
 */

void MAX30102::resetFifoWrite()
{
	writeRegisterMAX30102(FIFO_WR_PTR, 0x00); // ESP: Escribe 0 en el registro FIFO_WR_PTR para reiniciar el puntero. ENG: Writes 0 to the FIFO_WR_PTR register to reset the pointer.
}




/* ESP
 * @brief Lee los punteros de lectura y escritura del registro FIFO del sensor MAX30102.
 *
 * @param write Puntero para almacenar el valor del registro FIFO_WR_PTR.
 * @param read Puntero para almacenar el valor del registro FIFO_RD_PTR.
 */

/* ENG
 * @brief Reads the read and write pointers of the MAX30102 sensor's FIFO register.
 *
 * @param write Pointer to store the value of the FIFO_WR_PTR register.
 * @param read Pointer to store the value of the FIFO_RD_PTR register.
 */
void MAX30102::getFifoReadAndWrite(uint8_t *write, uint8_t *read)
{
	readRegisterMAX30102(FIFO_WR_PTR, write);  // ESP: Lee el registro FIFO_WR_PTR. ENG: Reads the FIFO_WR_PTR register.
	readRegisterMAX30102(FIFO_RD_PTR, read);   // ESP: Lee el registro FIFO_RD_PTR. ENG: Reads the FIFO_RD_PTR register.
}
