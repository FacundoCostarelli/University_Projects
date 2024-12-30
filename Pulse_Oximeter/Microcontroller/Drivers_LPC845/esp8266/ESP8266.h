/*
 * ESP8266.h
 *
 *  Created on: 5 dic. 2024
 *      Author: Facundo Costarelli y Ezequiel Lagache
 *      Descripción: Declaraciones para manejar el módulo WiFi ESP8266 de forma no bloqueante.
 */

#ifndef ESP8266_H_
#define ESP8266_H_

// Includes necesarios para el manejo del módulo y comunicación
#include <LPC845.h>
#include <serialCom.h>
#include <bufferCirc.h>
#include <PerifericoTemporizado.h>
#include <strings.h>
#include <Utils/queue/Queue.h>
#include <Timer.h>

// Configuración de conexión WiFi y servidor TCP
#define WIFI_SSID "MIRED" 	  	// SSID de la red WiFi
#define WIFI_PASSWORD "123456789" 	// Contraseña de la red WiFi
#define TCP_HOST "192.168.248.150"  // IP del servidor TCP
#define TCP_PORT "5000"				// Puerto del servidor TCP

// Estados del parser para detectar la respuesta "OK\r\n"
#define BUSCANDO_O	0
#define BUSCANDO_K	1
#define BUSCANDO_R	2
#define BUSCANDO_N	3

// Enumeración de los estados del módulo WiFi
typedef enum{
	WIFI_CONNECTED,		 // Conectado
	WIFI_DISCONNECTED,   // Desconectado
	WIFI_TCP_CONNECT,    // Conectando a servidor TCP
	WIFI_SET_MODE,       // Configurando modo WiFi
	WIFI_CONNECT,        // Conectando a red WiFi
	WIFI_RESET           // Reiniciando el módulo
}esp_states_mde;

// Declaración de funciones auxiliares para el envío de datos
void send_length_func(uint32_t value);
void send_data_func(uint32_t value);

// Clase principal para controlar el módulo ESP8266
class ESP8266 : public PerifericoTemporizado
{
private:
	serialCom * ptr_comPC;  	// Comunicación serie con el módulo
	bool flag_Ok; 				// Indica si se recibió "OK"
	bool flag_ok_aux;			// Auxiliar para el estado "OK"
	bool is_configured; 		// Indica si el módulo está configurado
	esp_states_mde state_mde;	// Estado actual del módulo

	Queue send_queue;    		//Cola para manejar tareas de envío
	Timer *timer_send;        	//Temporizador para manejar los envíos

	//Función para procesar tareas de la cola
	static void timer_handler(void);

	//Metodo para enviar el lenght
	void send_length(uint8_t length_data);

	//calcula la cantidad de digitos del numero
	uint8_t size_of_digits(int32_t number);

public:
	//Constructor
	ESP8266(serialCom * comPC);

	//Metodos para inicializar el modulo y controlar el módulo
	void callback(void);
	void init_module(void);
	bool check_response_ok(void);
	bool check_wifi_connected(void);

	//Metodos para el envio de la informacion
	void send(uint32_t value);

	//Metodo para procesar la siguiente tarea de la cola
	void process_next(void);

	// Declarar funciones auxiliares como "amigas" de la clase
	friend void send_length_func(uint32_t value);
	friend void send_data_func(uint32_t value);
};


#endif /* ESP8266_H_ */
