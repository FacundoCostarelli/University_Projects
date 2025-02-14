/*
 * ESP8266.cpp
 *
 *  Created on: 5 dic. 2024
 *      Author: Facundo Costarelli y Ezequiel Lagache
 *      ESP --> Descripción: Implementación de los métodos para manejar el módulo WiFi ESP8266.
 *		ESN --> Description: Implementation of the methods to manage the ESP8266 WiFi module.
 */
#include <esp8266/ESP8266.h>

// ESP: Puntero global al objeto ESP8266
// ENG: Global pointer to ESP8266 object
ESP8266 *esp8266 = nullptr;




/* ESP
 * @brief Constructor de la clase ESP8266.
 *        Inicializa el módulo WiFi ESP8266 y sus componentes.
 *
 * @param comPC Puntero al objeto de comunicación serial.
 */
/* ENG
 * @brief Constructor of the ESP8266 class.
 *        Initializes the ESP8266 WiFi module and its components.
 *
 * @param comPC Pointer to the serial communication object.
 */

ESP8266::ESP8266(serialCom * comPC )
{
	// ESP: Configuro el puntero global al objeto actual.
	// ENG: Set the global pointer to the current object.
	esp8266 = this;

	// ESP: Asigno el puntero de comunicación serial.
	// ENG: Assign the serial communication pointer.
	ptr_comPC = comPC;

	// ESP: Inicializo el estado del módulo como desconectado.
	// ENG: Initialize the module state as disconnected.
	state_mde = esp_states_mde::WIFI_DISCONNECTED;

	// ESP: Creo un nuevo temporizador para manejar el envío de tareas.
	// ENG: Create a new timer to handle task sending.
	timer_send = new Timer(500, ESP8266::timer_handler, false);

	// ESP: Inicializa los flags de estado y configuración.
	// ENG: Initializes state and configuration flags.
	flag_Ok = false;
	flag_ok_aux =false;
	is_configured = false;
}




/* ESP
 * @brief Handler del temporizador.
 *        Llama a la función process_next() para procesar la siguiente tarea en la cola.
 */
/* ENG
 * @brief Timer handler.
 *        Calls the process_next() function to process the next task in the queue.
 */

void ESP8266::timer_handler()
{
	// ESP: Verifico si el objeto ESP8266 existe.
	// ENG: Check if the ESP8266 object exists.
    if(esp8266)
    	esp8266->process_next();
}




/* ESP
 * @brief Procesa la siguiente tarea en la cola de envíos.
 *        Si la cola no está vacía, desencola la tarea y ejecuta la función asociada.
 */
/* ENG
 * @brief Processes the next task in the send queue.
 *        If the queue is not empty, dequeues the task and executes the associated function.
 */

void ESP8266::process_next()
{
	// ESP: Verifico si la cola de envíos no está vacía.
	// ENG: Check if the send queue is not empty
	if(!send_queue.is_empty())
	{
		Task tarea;

		// ESP: Desencolo la tarea de la cola.
		// ENG: Dequeue the task from the queue.
		if(send_queue.dequeue(tarea))
		{
			// ESP: Desencola la tarea y ejecuta la función asociada.
			// ENG: Dequeues the task and executes the associated function.
			tarea.function(tarea.data);

			// ESP: Detiene y reinicia el temporizador para la próxima tarea.
			// ENG: Stops and restarts the timer for the next task.
			timer_send->stop();
			timer_send->start();
		}
	}
	else
	{
		// ESP: Detiene el temporizador si no hay tareas en la cola.
		// ENG: Stops the timer if there are no tasks in the queue.
		timer_send->stop();
	}
}




/* ESP
 * @brief Comprueba si se recibió "OK\r\n" desde el módulo.
 *        Implementa una máquina de estados para detectar la secuencia "OK\r\n".
 *
 * @return true si se recibió "OK\r\n", false en caso contrario.
 */
/* ENG
 * @brief Checks if "OK\r\n" was received from the module.
 *        Implements a state machine to detect the "OK\r\n" sequence.
 *
 * @return true if "OK\r\n" was received, false otherwise.
 */

bool ESP8266::check_response_ok(void)
{
	static uint8_t estado = BUSCANDO_O;

	int16_t dato = ptr_comPC->Recibir();
	bool retorno = false;

	// ESP: Verifico si se recibió un dato válido.
	// ENG: Check if valid data was received.
	if(dato != bufferCirc::NO_DATA )
	{
		switch(estado)
		{
		case BUSCANDO_O:
			// ESP: Busco el carácter 'O'.
			// ENG: Look for the character 'O
			if(dato == 'O')
				estado = BUSCANDO_K;
			break;

		case BUSCANDO_K:
			// ESP: Busco el carácter 'K'.
			// ENG: Look for the character 'K'
			if(dato == 'K')
				estado = BUSCANDO_R;
			break;

		case BUSCANDO_R:
			// ESP: Busco el carácter '\r'.
			// ENG: Look for the character '\r'
			if(dato == '\r')
				estado = BUSCANDO_N;
			break;

		case BUSCANDO_N:
			// ESP: Busco el carácter '\n'.
			// ENG: Look for the character '\n'
			if(dato == '\n')
			{
				// ESP: "OK\r\n" recibido.
				// ENG: "OK\r\n" received.
				retorno = true;
				if(is_configured)
					flag_ok_aux = true;
				estado = BUSCANDO_O;
			}
			break;
		default:
			// ESP: Reinicio la máquina de estados.
			// ENG: Reset the state machine.
			estado = BUSCANDO_O;
			break;
		}
	}
	return retorno;
}




/* ESP
 * @brief Método callback que se llama dentro del Systick cada 1 ms.
 *        Verifica si se recibió "OK\r\n" desde el módulo.
 */
/* ENG
 * @brief Callback method called within the Systick every 1 ms.
 *        Checks if "OK\r\n" was received from the module.
 */

void ESP8266::callback(void)
{
	// ESP: Verifico si se recibió "OK\r\n".
	// ENG: Check if "OK\r\n" was received.
	flag_Ok = check_response_ok();
}




/* ESP
 * @brief Inicializa y configura el módulo WiFi.
 *        Implementa una máquina de estados para configurar el módulo paso a paso.
 */
/* ENG
 * @brief Initializes and configures the WiFi module.
 *        Implements a state machine to configure the module step by step.
 */

void ESP8266::init_module(void)
{
	uint8_t comando_wifi_connect[35] = "AT+CWJAP=\"";
	uint8_t commando_tcp[43]= "AT+CIPSTART=\"TCP\",\"";
	uint8_t commando_reset[] = "AT+RST\r\n";				//reset
	uint8_t comando_mode[] = "AT+CWMODE=3\r\n";				//set mode
	uint8_t comando_at[] = "AT\r\n";						//check connection

	static bool flag_primer_iteracion = true;
	static bool flag_primer_iteracion_rst = true;

	switch(state_mde)
	{
	case WIFI_DISCONNECTED:
		// ESP: Envío el comando AT para verificar la conexión.
		// ENG: Send the AT command to check the connection.
		if(flag_primer_iteracion)
		{
			ptr_comPC->Transmitir(comando_at, Cadenas::longitudCadena(comando_at));
			flag_primer_iteracion = false;
		}

		// ESP: Si se recibió "OK\r\n", cambio al estado WIFI_SET_MODE.
		// ENG: If "OK\r\n" was received, switch to the WIFI_SET_MODE state.
		if(flag_Ok)
		{
			flag_primer_iteracion = true;
			flag_Ok = false;

			ptr_comPC->Transmitir(comando_mode, Cadenas::longitudCadena(comando_mode));

			state_mde= esp_states_mde::WIFI_SET_MODE;
		}
		break;

	case WIFI_SET_MODE:
		// ESP: Si se recibió "OK\r\n", configuro la conexión WiFi.
		// ENG: If "OK\r\n" was received, configure the WiFi connection.
		if(flag_Ok)
		{
			flag_Ok = false;

			Cadenas::concatenarCadena(comando_wifi_connect, (const uint8_t*)WIFI_SSID);
			Cadenas::concatenarCadena(comando_wifi_connect, (const uint8_t*)"\",\"");
			Cadenas::concatenarCadena(comando_wifi_connect, (const uint8_t*)WIFI_PASSWORD);
			Cadenas::concatenarCadena(comando_wifi_connect, (const uint8_t*)"\"\r\n");
			ptr_comPC->Transmitir(comando_wifi_connect, Cadenas::longitudCadena(comando_wifi_connect));

			state_mde= esp_states_mde::WIFI_CONNECT;
		}
		break;

	case WIFI_CONNECT:
		// ESP: Si se recibió "OK\r\n", configuro la conexión TCP.
		 // ENG: If "OK\r\n" was received, configure the TCP connection.
		 if(flag_Ok)
		 {
			 Cadenas::concatenarCadena(commando_tcp, (const uint8_t*)TCP_HOST);
			 Cadenas::concatenarCadena(commando_tcp, (const uint8_t*)"\",");
			 Cadenas::concatenarCadena(commando_tcp, (const uint8_t*)TCP_PORT);
			 Cadenas::concatenarCadena(commando_tcp, (const uint8_t*)"\r\n");
			 ptr_comPC->Transmitir(commando_tcp, Cadenas::longitudCadena(commando_tcp));

			 state_mde= esp_states_mde::WIFI_TCP_CONNECT;
			 flag_Ok = false;
		 }
		break;

	case WIFI_TCP_CONNECT:
		// ESP: Si se recibió "OK\r\n", el módulo está conectado.
		// ENG: If "OK\r\n" was received, the module is connected.
		if(flag_Ok)
		{
			 state_mde= esp_states_mde::WIFI_CONNECTED;
			 flag_Ok = false;
			 is_configured = true;
		}
		break;

	case WIFI_CONNECTED: // ESP: No hace nada si ya está conectado. ENG: Does nothing if already connected.
		// ESP: No hace nada si ya está conectado.
		// ENG: Does nothing if already connected.
		break;

	case WIFI_RESET:
		// ESP: Envío el comando de reinicio.
		// ENG: Send the reset command.
		if(flag_primer_iteracion_rst)
		{
			ptr_comPC->Transmitir(commando_reset,Cadenas::longitudCadena(commando_reset));
			flag_primer_iteracion_rst = false;
		}

		// ESP: Si se recibió "OK\r\n", cambio al estado WIFI_SET_MODE.
		// ENG: If "OK\r\n" was received, switch to the WIFI_SET_MODE state.
		if(flag_Ok)
		{
			state_mde= esp_states_mde::WIFI_SET_MODE;
			flag_primer_iteracion_rst = true;
			flag_Ok = false;
		}
		break;

	default:
		// ESP: Reinicio al estado WIFI_DISCONNECTED si ocurre un error.
		// ENG: Reset to the WIFI_DISCONNECTED state if an error occurs.
		state_mde=esp_states_mde::WIFI_DISCONNECTED;
		break;
	}
}




/* ESP
 * @brief Verifica si el módulo está conectado a la red WiFi.
 *
 * @return true si está conectado, false en caso contrario.
 */
/* ENG
 * @brief Checks if the module is connected to the WiFi network.
 *
 * @return true if connected, false otherwise.
 */

bool ESP8266::check_wifi_connected(void)
{
	// ESP: Verifico si el estado actual es WIFI_CONNECTED.
	// ENG: Check if the current state is WIFI_CONNECTED.
	return state_mde == WIFI_CONNECTED;
}




/* ESP
 * @brief Envía información al módulo.
 *        Encola la longitud y los datos para su envío.
 *
 * @param value Valor a enviar.
 */
/* ENG
 * @brief Sends information to the module.
 *        Enqueues the length and data for sending.
 *
 * @param value Value to send.
 */

void ESP8266::send(uint32_t value)
{
	bool estaba_vacia = send_queue.is_empty();  		// ESP: Verifica si la cola estaba vacía. ENG: Checks if the queue was empty.
	send_queue.enqueue(send_length_func, value);  		// ESP: Encola la longitud. ENG: Enqueues the length.
	send_queue.enqueue(send_data_func, value);    		// ESP: Encola el dato. ENG: Enqueues the data.

	// ESP: Si la cola estaba vacía, reinicio el temporizador.
	// ENG: If the queue was empty, restart the timer.
	if(estaba_vacia)
	{
		// ESP: Detiene y reinicia el temporizador para iniciar el procesamiento.
		// ENG: Stops and restarts the timer to start processing.
		timer_send->stop();
		timer_send->start();
	}
}




/* ESP
 * @brief Función para enviar la longitud del dato.
 *
 * @param value Valor del cual se calcula la longitud.
 */
/* ENG
 * @brief Function to send the length of the data.
 *
 * @param value Value from which the length is calculated.
 */

void send_length_func(uint32_t value)
{
	// ESP: Calculo la longitud del dato.
	// ENG: Calculate the length of the data.
    uint8_t length = esp8266->size_of_digits(value);

    // ESP: Envío la longitud al módulo.
	// ENG: Send the length to the module
    esp8266->send_length(length);

    // ESP: Reinicio el flag auxiliar.
	// ENG: Reset the auxiliary flag.
	esp8266->flag_ok_aux = false;
}




/* ESP
 * @brief Envía la longitud del dato al módulo.
 *
 * @param length_data Longitud del dato a enviar.
 */
/* ENG
 * @brief Sends the length of the data to the module.
 *
 * @param length_data Length of the data to send.
 */

void ESP8266::send_length(uint8_t length_data)
{
	uint8_t lengthStr[10];
	uint8_t sendCommand[300] = "AT+CIPSEND=";

	// ESP: Convierto la longitud a cadena.
	// ENG: Convert the length to a string.
    Cadenas::enteroACadena(length_data, lengthStr);  // ESP: Convierte length_data en un string. ENG: Converts length_data to a string.

    // ESP: Concateno la longitud al comando de envío.
	// ENG: Concatenate the length to the send command.
    Cadenas::concatenarCadena(sendCommand, lengthStr);
    Cadenas::concatenarCadena(sendCommand, (const uint8_t *)"\r\n");

    // ESP: Envío el comando al módulo.
	// ENG: Send the command to the module.
    ptr_comPC->Transmitir(sendCommand, Cadenas::longitudCadena(sendCommand));
}




/* ESP
 * @brief Función para enviar el contenido del dato.
 *
 * @param value Valor a enviar.
 */
/* ENG
 * @brief Function to send the content of the data.
 *
 * @param value Value to send.
 */

void send_data_func(uint32_t value)
{
	// ESP: Verifico si el flag auxiliar está activo.
	// ENG: Check if the auxiliary flag is active.
	if(esp8266->flag_ok_aux)
	{
		// ESP: Envío el valor decimal al módulo.
		// ENG: Send the decimal value to the module
		esp8266->ptr_comPC->Transmitir_decimal(value);

		// ESP: Reinicio el flag auxiliar.
		// ENG: Reset the auxiliary flag.
		esp8266->flag_ok_aux = false;
	}
}




/* ESP
 * @brief Calcula el número de dígitos de un número.
 *
 * @param number Número del cual se calcula la cantidad de dígitos.
 * @return Número de dígitos.
 */
/* ENG
 * @brief Calculates the number of digits in a number.
 *
 * @param number Number from which the digit count is calculated.
 * @return Number of digits.
 */

uint8_t ESP8266::size_of_digits(int32_t number)
{
	uint8_t size_of_digits = 0;

	// ESP: Si el número es cero, tiene un dígito.
	// ENG: If the number is zero, it has one digit.
	if (number == 0)
        size_of_digits = 1;
    else
    {
        int32_t num_aux = number;

        // ESP: Cuento los dígitos del número.
        // ENG: Count the digits of the number
        while (num_aux > 0)
        {
        	num_aux /= 10;
            size_of_digits++;
        }
    }
    return size_of_digits;
}
