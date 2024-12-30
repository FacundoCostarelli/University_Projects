/*
 * ESP8266.cpp
 *
 *  Created on: 5 dic. 2024
 *      Author: Facundo Costarelli y Ezequiel Lagache
 *      Descripción: Implementación de los métodos para manejar el módulo WiFi ESP8266.
 */
#include <esp8266/ESP8266.h>

// Puntero global al objeto ESP8266
ESP8266 *esp8266 = nullptr;

// Constructor: Inicializa el módulo y sus componentes
ESP8266::ESP8266(serialCom * comPC )
{
	esp8266 = this;
	ptr_comPC = comPC;
	state_mde = esp_states_mde::WIFI_DISCONNECTED;
	timer_send = new Timer(500, ESP8266::timer_handler, false);

	//Inicializacion flags
	flag_Ok = false;
	flag_ok_aux =false;
	is_configured = false;
}

// Handler del temporizador: Llama a process_next()
void ESP8266::timer_handler()
{
    if(esp8266)
    	esp8266->process_next();
}

// Procesa la siguiente tarea en la cola de envíos
void ESP8266::process_next()
{
	if(!send_queue.is_empty())
	{
		Task tarea;
		if(send_queue.dequeue(tarea))
		{  	//Desencola la tarea y el dato asociado
			tarea.function(tarea.data);            	//Ejecuta la función encolada
			timer_send->stop();
			timer_send->start();            		//Inicia el temporizador para la próxima tarea
		}
	}
	else
		timer_send->stop();              			 // Detiene el temporizador si no hay tareas
}



// Comprueba si se recibió "OK\r\n" desde el módulo
bool ESP8266::check_response_ok(void)
{
	static uint8_t estado = BUSCANDO_O;

	int16_t dato = ptr_comPC->Recibir();
	bool retorno = false;

	if(dato != bufferCirc::NO_DATA )
	{
		switch(estado)
		{
		case BUSCANDO_O:
			if(dato == 'O')
				estado = BUSCANDO_K;
			break;
		case BUSCANDO_K:
			if(dato == 'K')
				estado = BUSCANDO_R;
			break;
		case BUSCANDO_R:
			if(dato == '\r')
				estado = BUSCANDO_N;
			break;
		case BUSCANDO_N:
			if(dato == '\n')
			{
				retorno = true; 			// "OK\r\n" recibido
				if(is_configured)
					flag_ok_aux = true;
				estado = BUSCANDO_O;
			}
			break;
		default:
			estado = BUSCANDO_O;
			break;
		}
	}
	return retorno;
}

//Metodo callback que se llama dentro del systick cada 1 msg. Se asocia con un periferico temporizado
void ESP8266::callback(void)
{
	flag_Ok = check_response_ok();
}

// Inicializa y configura el módulo WiFi
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
		if(flag_primer_iteracion)
		{
			ptr_comPC->Transmitir(comando_at, Cadenas::longitudCadena(comando_at));
			flag_primer_iteracion = false;
		}

		if(flag_Ok)
		{
			flag_primer_iteracion = true;
			flag_Ok = false;

			ptr_comPC->Transmitir(comando_mode, Cadenas::longitudCadena(comando_mode));

			state_mde= esp_states_mde::WIFI_SET_MODE;
		}
		break;

	case WIFI_SET_MODE:
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
		if(flag_Ok)
		{
			 state_mde= esp_states_mde::WIFI_CONNECTED;
			 flag_Ok = false;
			 is_configured = true;
		}
		break;

	case WIFI_CONNECTED:	//no hago nada si ya se coneccto

		break;

	case WIFI_RESET:
		if(flag_primer_iteracion_rst)
		{
			ptr_comPC->Transmitir(commando_reset,Cadenas::longitudCadena(commando_reset));
			flag_primer_iteracion_rst = false;
		}

		if(flag_Ok)
		{
			state_mde= esp_states_mde::WIFI_SET_MODE;
			flag_primer_iteracion_rst = true;
			flag_Ok = false;
		}
		break;

	default:
		state_mde=esp_states_mde::WIFI_DISCONNECTED;
		break;
	}
}

//Verifica si el modulo esta conectado a la red
bool ESP8266::check_wifi_connected(void)
{
	return state_mde == WIFI_CONNECTED;
}


//Metodo para enviar la informacion
void ESP8266::send(uint32_t value)
{
	bool estaba_vacia = send_queue.is_empty();  		//Verifica si la cola estaba vacía

	send_queue.enqueue(send_length_func, value);  		//Encola longitud
	send_queue.enqueue(send_data_func, value);    		//Encola dato

	if(estaba_vacia)
	{
		timer_send->stop();                 			//Detiene el temporizador si estaba corriendo
		timer_send->start();                			//Lo reinicia para iniciar el procesamiento
	}
}

//Función para enviar la longitud del dato
void send_length_func(uint32_t value)
{
    uint8_t length = esp8266->size_of_digits(value);  //Usa el dato actual
	esp8266->send_length(length);
	esp8266->flag_ok_aux = false;
}

//Función para enviar la longitud del dato
void ESP8266::send_length(uint8_t length_data)
{
	uint8_t lengthStr[10];
	uint8_t sendCommand[300] = "AT+CIPSEND=";

    Cadenas::enteroACadena(length_data, lengthStr);  			//convierte length_data en un string
    Cadenas::concatenarCadena(sendCommand, lengthStr);
    Cadenas::concatenarCadena(sendCommand, (const uint8_t *)"\r\n");

    ptr_comPC->Transmitir(sendCommand, Cadenas::longitudCadena(sendCommand));
}

//Funcion para enviar el contenido del dato
void send_data_func(uint32_t value)
{
	if(esp8266->flag_ok_aux)
	{
		esp8266->ptr_comPC->Transmitir_decimal(value);
		esp8266->flag_ok_aux = false;
	}
}

uint8_t ESP8266::size_of_digits(int32_t number)
{
	uint8_t size_of_digits = 0;
    if (number == 0)
        size_of_digits = 1;
    else
    {
        int32_t num_aux = number;
        while (num_aux > 0)
        {
        	num_aux /= 10;
            size_of_digits++;
        }
    }
    return size_of_digits;
}
