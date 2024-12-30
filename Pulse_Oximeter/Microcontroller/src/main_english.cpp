/*
 *- main.cpp INFO2 R2001
 *-
 *- Created on: 8 ago 2024
 *-     Author: Facundo Costarelli & Ezequiel Lagatche
 */

#include "MdeMAX30102.h"



int main(void) {
    // Inicialización del hardware del sistema
	InitializePLL();
	//InitializeHW();


    serialCom serial(115200,24, 25);
    ESP8266 wifi(&serial);


    //configuro al modulo wifi
    while(!wifi.check_wifi_connected()){

    	wifi.init_module();
    }
    //luego el sensor MAX30102
    Max30102StateMachine sm(&wifi);


    while(1)
    {
    	sm.Mde_MAX30102();
    }


    return 0;
}

