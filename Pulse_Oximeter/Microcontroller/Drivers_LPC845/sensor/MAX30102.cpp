/*
 * MAX30102.c
 *
 *  Created on: 6 oct 2024
 *      Author: Costarelli
 */

#include "MAX30102.h"

static  int32_t an_x[ BUFFER_SIZE]; //ir
static  int32_t an_y[ BUFFER_SIZE]; //red

//buffer circular para guardar los valores del sensor
struct Record
{
  uint32_t red[SAMPLES_SIZE];
  uint32_t IR[SAMPLES_SIZE];
  uint8_t head; // para insertarlos // actua como indice para guardar al siguiente valor
  uint8_t tail; // para leer valores //en realidad no lo uso para nada esto
} sense;

/*
 * @brief Constructor de la clase MAX30102
 * 		  Inicia la configuracion de pines del sensor max30102
 * */
MAX30102::MAX30102(I2C_Type* m_i2c, mode_t mode, uint8_t slaveAddress)
	:i2c(0, 0, 0, 0, m_i2c, mode, slaveAddress){


	ConfiguracionSensorMAX30102(i2c);
}


/*
 * @brief Configura los pines del sensor max30102
 * */
void MAX30102::ConfiguracionSensorMAX30102(I2C i2c){
	 	 uint8_t datos[2];  // Array to hold the register address and data
	    uint8_t readData;  // Array to store the data read back for verification

	    // Step 1: Reset the FIFO Write, Read pointers, and Overflow Counter
	    datos[0] = FIFO_WR_PTR;  // FIFO_WR_PTR register
	    datos[1] = 0x00;         // Reset write pointer
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(FIFO_WR_PTR, &readData);

	    datos[0] = OV_COUNTER;  // OVF_COUNTER register
	    datos[1] = 0x00;        // Reset overflow counter
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(OV_COUNTER, &readData);

	    datos[0] = FIFO_RD_PTR;  // FIFO_RD_PTR register
	    datos[1] = 0x00;         // Reset read pointer
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(FIFO_RD_PTR, &readData);


	    datos[0] = 0x08;  // FIFO_CONFIG register
		datos[1] = 0x50;         // 010 4 sample avergage on
		i2c.writeI2CAndWait(datos, 2);
		readRegisterMAX30102(0x08, &readData);


	    // Step 2: Configure the MODE register
	    datos[0] = MODE_CONFIG;  // MODE_CONFIG register
	    datos[1] = 1 << 6;       // Reset mode
	    i2c.writeI2CAndWait(datos, 2);
	     readRegisterMAX30102(MODE_CONFIG, &readData);

	    //CAMBIAR MODO para que sea multimodo
	    datos[0] = MODE_CONFIG;  // MODE_CONFIG register
	    datos[1] = 0x07;         // MULTILED MODE
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(MODE_CONFIG, &readData);


	    datos[0] = MULTILEDCONFIG1;  // MULTILED MODE CONTROL register
		datos[1] = 0x21; //  SLOT 1 RED SLOT 2 IR
		i2c.writeI2CAndWait(datos, 2);
		readRegisterMAX30102(MULTILEDCONFIG1, &readData);


	    // Step 3: Configure the SPO2 settings
	    datos[0] = SPO2_CONFIG;  // SPO2_CONFIG register
	    //datos[1] = 0x6F;         // Configure for 400 samples/sec, 411us pulse width
	    //datos[1] = 0x04;			// Configure for 100 samples/sec, 69us pulse width
	    //datos[1] = 0x67; // Configure for 100 samples/sec, 411us pulse width
	    datos[1] = 0x27; // Configure for 100 samples/sec, 411 pulse width & 15.63pA LSB SIZE Y  4096 nA FULL SCALE
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(SPO2_CONFIG, &readData);

	    // Step 4: Set the LED1 (Red) current
	    datos[0] = LED1_PA;  // LED1_PA register (LED RED pulse amplitude)
	    datos[1] = 0x3c;     // Set to maximum current
	    i2c.writeI2CAndWait(datos, 2);
	     readRegisterMAX30102(LED1_PA, &readData);

	    // Step 5: Set the LED2 (IR) current
	    datos[0] = LED2_PA;  // LED2_PA register (LED IR pulse amplitude)
	    datos[1] = 0x3c;     // Set to maximum current
	    i2c.writeI2CAndWait(datos, 2);
	    readRegisterMAX30102(LED2_PA, &readData);
}


/*
 * @brief lee 1 byte del registro regName de MAZ30102 y lo guarda en *regValue_read
 * @param regName direccion del registro a leer del sensor max30102
 * @param regValue_read puntero donde guardar lo leido del sensor
 */
void MAX30102::readRegisterMAX30102(uint8_t regName, uint8_t *regValue_read){
	 uint8_t datos[1];
	    datos[0] = regName;
	    i2c.writeI2CAndWait(datos, 1);

	    //perform reading
	    i2c.readI2CAndWait(1);

		i2c.Read(regValue_read, 1);//read 1 byte
}


/*
 * @brief lee size byte del registro regName del sensor MAX30102
 * @param regName direccion del registro a leer del sensor max30102
 * @param size cantidad de datos a leer en bytes
 */
void MAX30102::readRegisterMAX30102NBytes(uint8_t regName, uint8_t size){
	 uint8_t datos[1];
	    datos[0] = regName;
	    i2c.writeI2CAndWait(datos, 1);

	    //perform reading
	    i2c.readI2CAndWait(size);
}

/*
 * @brief escribe el regValue en el registro regName del sensor MAX30102
 * @param regName direccion del registro a escribir del sensor max30102
 * @param regValue dato a escribir
 */
void MAX30102::writeRegisterMAX30102(uint8_t regName, uint8_t regValue){
	 uint8_t datos[2];
	// reset fifo write register
	  datos[0] = regName;
	  datos[1] = regValue;
	  i2c.writeI2CAndWait(datos, 2);
}

uint32_t cant_samples = 0;//cantidad de muestras

/*
 * @brief lee los datos del sensor MAX30102
 * @param bytesLeftToRead cantidad de datos a leer en bytes
 */
void MAX30102::readFifoData(int32_t *bytesLeftToRead){
	while (*bytesLeftToRead > 0 ){
		  int32_t toGet = *bytesLeftToRead;
		  if (toGet > BUFFER_LENGTH) {
			  // If toGet is 32 this is bad because we read 6 bytes (Red+IR * 3 = 6) at a time
			  // 32 % 6 = 2 left over. We don't want to request 32 bytes, we want to request 30.
			  // 32 % 9 (Red+IR+GREEN) = 5 left over. We want to request 27.

			  toGet = BUFFER_LENGTH - (BUFFER_LENGTH % 6);  // Trim toGet to be a multiple of the samples we need to read
		  }

		  *bytesLeftToRead -= toGet;

		  //performe reading
		  readRegisterMAX30102NBytes(FIFO_DATA, toGet);

		  while (toGet > 0){
			 sense.head++;                // Advance the head of the storage struct
			 sense.head %= SAMPLES_SIZE;

			 cant_samples ++;

			 uint8_t temp[sizeof(uint32_t)];  // Array of 4 bytes that we will convert into long

			 uint32_t tempLong;

			 // Burst read three bytes - RED
			 temp[3] = 0;
			 temp[2] = i2c.read();
			 temp[1] = i2c.read();
			 temp[0] = i2c.read();

			 memcpy(&tempLong, temp, sizeof(tempLong));

			tempLong &= 0x3FFFF;  // Zero out all but 18 bits

			sense.red[sense.head] = tempLong;  // Store this reading into the sense array

			// Burst read three more bytes - IR
			temp[3] = 0;
			temp[2] = i2c.read();
			temp[1] = i2c.read();
			temp[0] = i2c.read();

			// Convert array to long
			memcpy(&tempLong, temp, sizeof(tempLong));

			tempLong &= 0x3FFFF;  // Zero out all but 18 bits

			sense.IR[sense.head] = tempLong;

			toGet -= 6;
		  }
	  }
}

/* @brief verifica si aun faltan muestras por leer
 *
 */
bool MAX30102::continue_reading(){
	return cant_samples < SAMPLES_SIZE;
}

/* @brief resetea el contador de muestras
 *
 */
void MAX30102::reset_samples_counter(){
	cant_samples = 0;
}


void MAX30102::maxim_sort_indices_descend(  int32_t  *pn_x, int32_t *pn_indx, int32_t n_size)
/**
* \brief        Sort indices
* \par          Details
*               Sort indices according to descending order (insertion sort algorithm)
*
* \retval       None
*/
{
  int32_t i, j, n_temp;
  for (i = 1; i < n_size; i++) {
    n_temp = pn_indx[i];
    for (j = i; j > 0 && pn_x[n_temp] > pn_x[pn_indx[j-1]]; j--)
      pn_indx[j] = pn_indx[j-1];
    pn_indx[j] = n_temp;
  }
}
void MAX30102::maxim_sort_ascend(int32_t  *pn_x, int32_t n_size)
/**
* \brief        Sort array
* \par          Details
*               Sort array in ascending order (insertion sort algorithm)
*
* \retval       None
*/
{
  int32_t i, j, n_temp;
  for (i = 1; i < n_size; i++) {
    n_temp = pn_x[i];
    for (j = i; j > 0 && n_temp < pn_x[j-1]; j--)
        pn_x[j] = pn_x[j-1];
    pn_x[j] = n_temp;
  }
}

void MAX30102::maxim_remove_close_peaks(int32_t *pn_locs, int32_t *pn_npks, int32_t *pn_x, int32_t n_min_distance)
/**
* \brief        Remove peaks
* \par          Details
*               Remove peaks separated by less than MIN_DISTANCE
*
* \retval       None
*/
{

  int32_t i, j, n_old_npks, n_dist;

  /* Order peaks from large to small */
  maxim_sort_indices_descend( pn_x, pn_locs, *pn_npks );

  for ( i = -1; i < *pn_npks; i++ ){
    n_old_npks = *pn_npks;
    *pn_npks = i+1;
    for ( j = i+1; j < n_old_npks; j++ ){
      n_dist =  pn_locs[j] - ( i == -1 ? -1 : pn_locs[i] ); // lag-zero peak of autocorr is at index -1
      if ( n_dist > n_min_distance || n_dist < -n_min_distance )
        pn_locs[(*pn_npks)++] = pn_locs[j];
    }
  }

  // Resort indices int32_to ascending order
  maxim_sort_ascend( pn_locs, *pn_npks );
}

void MAX30102::maxim_peaks_above_min_height( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height )
/**
* \brief        Find peaks above n_min_height
* \par          Details
*               Find all peaks above MIN_HEIGHT
*
* \retval       None
*/
{
  int32_t i = 1, n_width;
  *n_npks = 0;

  while (i < n_size-1){
    if (pn_x[i] > n_min_height && pn_x[i] > pn_x[i-1]){      // find left edge of potential peaks
      n_width = 1;
      while (i+n_width < n_size && pn_x[i] == pn_x[i+n_width])  // find flat peaks
        n_width++;
      if (pn_x[i] > pn_x[i+n_width] && (*n_npks) < 15 ){      // find right edge of peaks
        pn_locs[(*n_npks)++] = i;
        // for flat peaks, peak location is left edge
        i += n_width+1;
      }
      else
        i += n_width;
    }
    else
      i++;
  }
}

void MAX30102::maxim_find_peaks( int32_t *pn_locs, int32_t *n_npks,  int32_t  *pn_x, int32_t n_size, int32_t n_min_height, int32_t n_min_distance, int32_t n_max_num )
/**
* \brief        Find peaks
* \par          Details
*               Find at most MAX_NUM peaks above MIN_HEIGHT separated by at least MIN_DISTANCE
*
* \retval       None
*/
{
  maxim_peaks_above_min_height( pn_locs, n_npks, pn_x, n_size, n_min_height );
  maxim_remove_close_peaks( pn_locs, n_npks, pn_x, n_min_distance );
  *n_npks = min( *n_npks, n_max_num );
}


void MAX30102::maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, int32_t *pn_spo2, int8_t *pch_spo2_valid,
                int32_t *pn_heart_rate, int8_t *pch_hr_valid)
/**
* \brief        Calculate the heart rate and SpO2 level
* \par          Details
*               By detecting  peaks of PPG cycle and corresponding AC/DC of red/infra-red signal, the an_ratio for the SPO2 is computed.
*               Since this algorithm is aiming for Arm M0/M3. formaula for SPO2 did not achieve the accuracy due to register overflow.
*               Thus, accurate SPO2 is precalculated and save longo uch_spo2_table[] per each an_ratio.
*
* \param[in]    *pun_ir_buffer           - IR sensor data buffer
* \param[in]    n_ir_buffer_length      - IR sensor data buffer length
* \param[in]    *pun_red_buffer          - Red sensor data buffer
* \param[out]    *pn_spo2                - Calculated SpO2 value
* \param[out]    *pch_spo2_valid         - 1 if the calculated SpO2 value is valid
* \param[out]    *pn_heart_rate          - Calculated heart rate value
* \param[out]    *pch_hr_valid           - 1 if the calculated heart rate value is valid
*
* \retval       None
*/
{
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

  // CALCULO HEART BEAT

  // calculates DC mean and subtract DC from ir
  un_ir_mean =0;
  for (k=0 ; k<n_ir_buffer_length ; k++ ) un_ir_mean += pun_ir_buffer[k] ;
  un_ir_mean =un_ir_mean/n_ir_buffer_length ;

  // remove DC and invert signal so that we can use peak detector as valley detector
  for (k=0 ; k<n_ir_buffer_length ; k++ )
    an_x[k] = -1*(pun_ir_buffer[k] - un_ir_mean) ;//invierte la señal para calcular los picos facilmente

  // 4 pt Moving Average // elimino el ruido y dejo pasar las variaciones mas lentas
  for(k=0; k< BUFFER_SIZE-MA4_SIZE; k++){
    an_x[k]=( an_x[k]+an_x[k+1]+ an_x[k+2]+ an_x[k+3])/(int)4;
  }

  // calculate threshold for detect peaks
  n_th1=0;
  for ( k=0 ; k<BUFFER_SIZE ;k++){
    n_th1 +=  an_x[k];
  }
  n_th1=  n_th1/ ( BUFFER_SIZE);
  if( n_th1<30) n_th1=30; // min allowed
  if( n_th1>60) n_th1=60; // max allowed

  for ( k=0 ; k<15;k++) an_ir_valley_locs[k]=0;

  // since we flipped signal, we use peak detector as valley detector
  maxim_find_peaks( an_ir_valley_locs, &n_npks, an_x, BUFFER_SIZE, n_th1, 4, 15 );//peak_height, peak_distance, max_num_peaks
  n_peak_interval_sum =0;
  if (n_npks>=2){// si hay 2 o más picos detectados
	  //saca un promedio del intervalo de los picos
    for (k=1; k<n_npks; k++) n_peak_interval_sum += (an_ir_valley_locs[k] -an_ir_valley_locs[k -1] ) ;
    n_peak_interval_sum =n_peak_interval_sum/(n_npks-1);
    //aplica formula para calcular el heart rate
    *pn_heart_rate =(int32_t)( (FS*60)/ n_peak_interval_sum );
    *pch_hr_valid  = 1;
  }
  else  {
    *pn_heart_rate = -999; // unable to calculate because # of peaks are too small
    *pch_hr_valid  = 0;
  }

  // CALCULO SPO2

  //  load raw value again for SPO2 calculation : RED(=y) and IR(=X)
  for (k=0 ; k<n_ir_buffer_length ; k++ )  {
      an_x[k] =  pun_ir_buffer[k] ;
      an_y[k] =  pun_red_buffer[k] ;
  }

  // find precise min near an_ir_valley_locs
  n_exact_ir_valley_locs_count =n_npks;

  //using exact_ir_valley_locs , find ir-red DC andir-red AC for SPO2 calibration an_ratio
  //finding AC/DC maximum of raw

  n_ratio_average =0;
  n_i_ratio_count = 0;

  for(k=0; k< 5; k++) an_ratio[k]=0;

  for (k=0; k< n_exact_ir_valley_locs_count; k++){//verifica que la posición de cada valle no este fuera de rango
    if (an_ir_valley_locs[k] > BUFFER_SIZE ){
      *pn_spo2 =  -999 ; // do not use SPO2 since valley loc is out of range
      *pch_spo2_valid  = 0;
      return;
    }
  }

  // find max between two valley locations
  // and use an_ratio betwen AC compoent of Ir & Red and DC compoent of Ir & Red for SPO2
  for (k=0; k< n_exact_ir_valley_locs_count-1; k++){
    n_y_dc_max= -16777216 ;
    n_x_dc_max= -16777216;

    if (an_ir_valley_locs[k+1]-an_ir_valley_locs[k] >3){
        for (i=an_ir_valley_locs[k]; i< an_ir_valley_locs[k+1]; i++){
          if (an_x[i]> n_x_dc_max) {n_x_dc_max =an_x[i]; n_x_dc_max_idx=i;}
          if (an_y[i]> n_y_dc_max) {n_y_dc_max =an_y[i]; n_y_dc_max_idx=i;}
      }
      n_y_ac= (an_y[an_ir_valley_locs[k+1]] - an_y[an_ir_valley_locs[k]] )*(n_y_dc_max_idx -an_ir_valley_locs[k]); //red
      n_y_ac=  an_y[an_ir_valley_locs[k]] + n_y_ac/ (an_ir_valley_locs[k+1] - an_ir_valley_locs[k])  ;
      n_y_ac=  an_y[n_y_dc_max_idx] - n_y_ac;    // subracting linear DC compoenents from raw

      n_x_ac= (an_x[an_ir_valley_locs[k+1]] - an_x[an_ir_valley_locs[k] ] )*(n_x_dc_max_idx -an_ir_valley_locs[k]); // ir
      n_x_ac=  an_x[an_ir_valley_locs[k]] + n_x_ac/ (an_ir_valley_locs[k+1] - an_ir_valley_locs[k]);
      n_x_ac=  an_x[n_y_dc_max_idx] - n_x_ac;      // subracting linear DC compoenents from raw

      n_nume=( n_y_ac *n_x_dc_max)>>7 ; //prepare X100 to preserve floating value
      n_denom= ( n_x_ac *n_y_dc_max)>>7;

      if (n_denom>0  && n_i_ratio_count <5 &&  n_nume != 0)
      {
        an_ratio[n_i_ratio_count]= (n_nume*100)/n_denom ; //formular is ( n_y_ac *n_x_dc_max) / ( n_x_ac *n_y_dc_max) ;
        n_i_ratio_count++;
      }
    }
  }
  // choose median value since PPG signal may varies from beat to beat
  maxim_sort_ascend(an_ratio, n_i_ratio_count);
  n_middle_idx= n_i_ratio_count/2;

  if (n_middle_idx >1)
    n_ratio_average =( an_ratio[n_middle_idx-1] +an_ratio[n_middle_idx])/2; // use median
  else
    n_ratio_average = an_ratio[n_middle_idx ];


  if( n_ratio_average>2 && n_ratio_average <184){
    n_spo2_calc= uch_spo2_table[n_ratio_average] ;
    *pn_spo2 = n_spo2_calc ;
    *pch_spo2_valid  = 1;//  float_SPO2 =  -45.060*n_ratio_average* n_ratio_average/10000 + 30.354 *n_ratio_average/100 + 94.845 ;  // for comparison with table
  }
  else{
    *pn_spo2 =  -999 ; // do not use SPO2 since signal an_ratio is out of range
    *pch_spo2_valid  = 0;
  }
}


/*
 * @brief verifica si hay muestras leidas con el struct sense
 * */
int16_t MAX30102::available(void){
  int16_t numberOfSamples = sense.head - sense.tail;
  if (numberOfSamples < 0) numberOfSamples += SAMPLES_SIZE;

  return (numberOfSamples);
}

/*
 * @brief si se leyo mas muestras, avanza el tail del struct sense
 * */
void MAX30102::nextSample(void)
{
  if(available()) //Only advance the tail if new data is available
  {
    sense.tail++;
    sense.tail %= SAMPLES_SIZE; //Wrap condition
  }
}
//getters

uint32_t MAX30102::getFIFORed(void)
{
  return (sense.red[sense.tail]);
}

uint32_t MAX30102::getFIFOIR(void)
{
  return (sense.IR[sense.tail]);
}


uint32_t* MAX30102::getArrayIRValues(){
	return sense.IR;
}

uint32_t* MAX30102::getArrayRValues(){
	return sense.red;
}

/*
 * @brief resetea el registro puntero de fifo write del sensor
 * */
void MAX30102::resetFifoWrite(){
	writeRegisterMAX30102(FIFO_WR_PTR, 0x00);
}

/*
 * @brief getter del registro puntero de fifo write y fifo read del sensor
 * @param write puntero donde almacenar lo leido de fifo write
 * @param read puntero donde almacenar lo leido de fifo read
 * */
void MAX30102::getFifoReadAndWrite(uint8_t *write, uint8_t *read){
	readRegisterMAX30102(FIFO_WR_PTR, write);  // leo registro fifo write

	readRegisterMAX30102(FIFO_RD_PTR, read);  // leo registro fifo read

}
