/*
 * ESP8266.h
 *
 *  Created on: 5 dic. 2024
 *      Author: Facundo Costarelli y Ezequiel Lagache
 *		ESP --> Descripción: Declaraciones para manejar el módulo WiFi ESP8266 de forma no bloqueante.
 *      ENG --> Description: Declarations to handle the ESP8266 WiFi module in a non-blocking way.
 *
 */

/* ESP
 * @brief Este archivo contiene las declaraciones necesarias para manejar el módulo WiFi ESP8266 de manera no bloqueante.
 *        Incluye la configuración de conexión WiFi, estados del módulo, y métodos para enviar y recibir datos.
 *
 *      **Variables Globales**
 *
 *      WIFI_SSID:          Define el SSID de la red WiFi a la que se conectará el módulo.
 *      WIFI_PASSWORD:      Define la contraseña de la red WiFi.
 *      TCP_HOST:           Define la dirección IP del servidor TCP al que se conectará el módulo.
 *      TCP_PORT:           Define el puerto del servidor TCP.
 *
 *      BUSCANDO_O, BUSCANDO_K, BUSCANDO_R, BUSCANDO_N:
 *                          Estados del parser para detectar la respuesta "OK\r\n" del módulo ESP8266.
 *
 *      **Enumeración**
 *
 *      esp_states_mde:     Enumeración que define los posibles estados del módulo WiFi:
 *                          - WIFI_CONNECTED:      Módulo conectado a la red WiFi.
 *                          - WIFI_DISCONNECTED:   Módulo desconectado de la red WiFi.
 *                          - WIFI_TCP_CONNECT:    Módulo conectándose al servidor TCP.
 *                          - WIFI_SET_MODE:       Módulo configurando el modo WiFi.
 *                          - WIFI_CONNECT:        Módulo conectándose a la red WiFi.
 *                          - WIFI_RESET:          Módulo en proceso de reinicio.
 *
 *      **Funciones Auxiliares**
 *
 *      send_length_func(uint32_t value):
 *                          Función auxiliar para enviar la longitud de los datos.
 *      send_data_func(uint32_t value):
 *                          Función auxiliar para enviar los datos.
 *
 *      **Clase ESP8266**
 *
 *      **Variables Privadas**
 *
 *      ptr_comPC:          Puntero a un objeto de comunicación serie para interactuar con el módulo ESP8266.
 *      flag_Ok:            Bandera que indica si se recibió la respuesta "OK" del módulo.
 *      flag_ok_aux:        Bandera auxiliar para manejar el estado "OK".
 *      is_configured:      Bandera que indica si el módulo ha sido configurado correctamente.
 *      state_mde:          Estado actual del módulo WiFi (ver enumeración `esp_states_mde`).
 *      send_queue:         Cola para manejar las tareas de envío de datos.
 *      timer_send:         Temporizador para gestionar los envíos de datos.
 *
 *      **Métodos Privados**
 *
 *      timer_handler(void):
 *                          Función estática para procesar las tareas de la cola de envío.
 *      send_length(uint8_t length_data):
 *                          Método para enviar la longitud de los datos.
 *      size_of_digits(int32_t number):
 *                          Método para calcular la cantidad de dígitos de un número.
 *
 *      **Métodos Públicos**
 *
 *      ESP8266(serialCom * comPC):
 *                          Constructor de la clase. Inicializa el módulo ESP8266 con un puntero a la comunicación serie.
 *      callback(void):     Método que se ejecuta cuando ocurre un evento en el módulo.
 *      init_module(void):  Método para inicializar el módulo WiFi.
 *      check_response_ok(void):
 *                          Método para verificar si se recibió la respuesta "OK" del módulo.
 *      check_wifi_connected(void):
 *                          Método para verificar si el módulo está conectado a la red WiFi.
 *      send(uint32_t value):
 *                          Método para enviar datos a través del módulo WiFi.
 *      process_next(void): Método para procesar la siguiente tarea en la cola de envío.
 *
 *      **Funciones Amigas**
 *
 *      send_length_func(uint32_t value):
 *                          Función amiga para enviar la longitud de los datos.
 *      send_data_func(uint32_t value):
 *                          Función amiga para enviar los datos.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file contains the necessary declarations to manage the ESP8266 WiFi module in a non-blocking manner.
 *        It includes WiFi connection configuration, module states, and methods for sending and receiving data.
 *
 *      **Global Variables**
 *
 *      WIFI_SSID:          Defines the SSID of the WiFi network the module will connect to.
 *      WIFI_PASSWORD:      Defines the password of the WiFi network.
 *      TCP_HOST:           Defines the IP address of the TCP server the module will connect to.
 *      TCP_PORT:           Defines the port of the TCP server.
 *
 *      BUSCANDO_O, BUSCANDO_K, BUSCANDO_R, BUSCANDO_N:
 *                          Parser states to detect the "OK\r\n" response from the ESP8266 module.
 *
 *      **Enumeration**
 *
 *      esp_states_mde:     Enumeration that defines the possible states of the WiFi module:
 *                          - WIFI_CONNECTED:      Module connected to the WiFi network.
 *                          - WIFI_DISCONNECTED:   Module disconnected from the WiFi network.
 *                          - WIFI_TCP_CONNECT:    Module connecting to the TCP server.
 *                          - WIFI_SET_MODE:       Module configuring WiFi mode.
 *                          - WIFI_CONNECT:        Module connecting to the WiFi network.
 *                          - WIFI_RESET:          Module in reset process.
 *
 *      **Auxiliary Functions**
 *
 *      send_length_func(uint32_t value):
 *                          Auxiliary function to send the length of the data.
 *      send_data_func(uint32_t value):
 *                          Auxiliary function to send the data.
 *
 *      **Class ESP8266**
 *
 *      **Private Variables**
 *
 *      ptr_comPC:          Pointer to a serial communication object for interacting with the ESP8266 module.
 *      flag_Ok:            Flag indicating whether the "OK" response was received from the module.
 *      flag_ok_aux:        Auxiliary flag for handling the "OK" state.
 *      is_configured:      Flag indicating whether the module has been configured correctly.
 *      state_mde:          Current state of the WiFi module (see `esp_states_mde` enumeration).
 *      send_queue:         Queue to manage data sending tasks.
 *      timer_send:         Timer to manage data sending.
 *
 *      **Private Methods**
 *
 *      timer_handler(void):
 *                          Static function to process tasks in the send queue.
 *      send_length(uint8_t length_data):
 *                          Method to send the length of the data.
 *      size_of_digits(int32_t number):
 *                          Method to calculate the number of digits in a number.
 *
 *      **Public Methods**
 *
 *      ESP8266(serialCom * comPC):
 *                          Class constructor. Initializes the ESP8266 module with a pointer to serial communication.
 *      callback(void):     Method executed when an event occurs in the module.
 *      init_module(void):  Method to initialize the WiFi module.
 *      check_response_ok(void):
 *                          Method to check if the "OK" response was received from the module.
 *      check_wifi_connected(void):
 *                          Method to check if the module is connected to the WiFi network.
 *      send(uint32_t value):
 *                          Method to send data through the WiFi module.
 *      process_next(void): Method to process the next task in the send queue.
 *
 *      **Friend Functions**
 *
 *      send_length_func(uint32_t value):
 *                          Friend function to send the length of the data.
 *      send_data_func(uint32_t value):
 *                          Friend function to send the data.
 *
 * @param None
 */

#ifndef ESP8266_H_
#define ESP8266_H_

#include <LPC845.h>
#include <serialCom.h>
#include <bufferCirc.h>
#include <PerifericoTemporizado.h>
#include <strings.h>
#include <Utils/queue/Queue.h>
#include <Timer.h>

#define WIFI_SSID "MIRED"
#define WIFI_PASSWORD "123456789"
#define TCP_HOST "192.168.116.150"
#define TCP_PORT "5000"

#define BUSCANDO_O	0
#define BUSCANDO_K	1
#define BUSCANDO_R	2
#define BUSCANDO_N	3

typedef enum{
	WIFI_CONNECTED,
	WIFI_DISCONNECTED,
	WIFI_TCP_CONNECT,
	WIFI_SET_MODE,
	WIFI_CONNECT,
	WIFI_RESET
}esp_states_mde;


void send_length_func(uint32_t value);
void send_data_func(uint32_t value);

class ESP8266 : public PerifericoTemporizado
{
private:
	serialCom * ptr_comPC;
	bool flag_Ok;
	bool flag_ok_aux;
	bool is_configured;
	esp_states_mde state_mde;

	Queue send_queue;
	Timer *timer_send;

	static void timer_handler(void);
	void send_length(uint8_t length_data);
	uint8_t size_of_digits(int32_t number);

public:

	ESP8266(serialCom * comPC);

	void callback(void);
	void init_module(void);
	bool check_response_ok(void);
	bool check_wifi_connected(void);

	void send(uint32_t value);
	void process_next(void);

	friend void send_length_func(uint32_t value);
	friend void send_data_func(uint32_t value);
};


#endif /* ESP8266_H_ */
