/*
 *- main.cpp
 *-
 *- Created on: August 2024
 *-     Author: Facundo Costarelli
 */

#include "MdeMAX30102.h"


/* ESP
 * @brief Función principal del programa. Es la que instancia y configura los objetos necesarios para
 * 		  hacer funcionar los módulos de hardware LPC845, MAX30102 y ESP8266. También se ejecuta la apliación
 * 		  del sistema a traves de un while(1) utilizando máquina de estados. No hay loops bloqueantes.
 *
 * @param Ninguno
 *
 */

/* ENG
 * @brief Main function of the programm. It is instanced and configured the necessary objects to make work
 * 		  the hardware modules such as LPC845, MAX30102 and ESP8266. Also it is executed the system application
 * 		  through a while(1) loop using states machine. There are no blocking loops.
 *
 * @param None
 *
 */

int main(void) {
	//ESP: Inicialización del hardware del sistema. Esto es la placa del LPC845.
    //ENG: Initialization of the system hardware. That is the LPC845 board.
    InicializarPLL();

    //ESP: Instancia y configuración de objetos para la comunicación inalámbrica.
    //ENG: Instance and configuration of objects to have inalambric communications.
    serialCom serial(115200,24, 25);
    ESP8266 wifi(&serial);


    //ESP: Ciclo while de configuración del modulo wifi.
    //ENG: While loop to configure wifi module.
    while(!wifi.check_wifi_connected()){

    	wifi.init_module();
    }

    //ESP: Instancia y configuración de objeto asociado al sensor MAX30102.
    //ENG: Instance and configuration of the object related to the MAX30102 sensor.
    Max30102StateMachine sm(&wifi);


    //ESP: Bucle repetitivo de while(1) para ejecutar la aplicación del sistema utilizando máquina de estados.
    //ENG: Repetitive loop of while(1) to execute the system application using states machine.
    while(1)
    {
    	sm.Mde_MAX30102();
    }


    return 0;
}








