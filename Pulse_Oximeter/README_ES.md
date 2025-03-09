# Pulsioxímetro - Proyecto Integrado

**Descripción breve:**  
Desarrollo de un dispositivo prototipo de pulsioxímetro que combina software y hardware básico. 
Este proyecto mide saturación de oxígeno en sangre (SPO2) y frecuencia cardíaca (Heart Rate) 
utilizando el sensor MAX30102, el microcontrolador LPC845 y el módulo ESP8266 para transmisión WiFi hacia una PC. 
Incluye una interfaz gráfica Qt para visualización de datos.
[Youtube presentación PulseOximeter pt1](https://youtu.be/6Oj863C7EKM)
[Youtube presentación PulseOximeter pt2](https://www.youtube.com/watch?v=Ok4IE8EWSyQ)

---

## Tabla de Contenidos

1. [Instalación](#instalación)
2. [Uso](#uso)
3. [Problemas Comunes](#problemas-comunes)
4. [Documentación](#documentación)
5. [Fuentes De Consulta](#fuentes-de-consulta)
6. [Contribución](#contribución)
7. [Licencia](#licencia)
8. [Autores](#autores)
9. [Reconocimientos Y Colaboraciones](#reconocimientos-y-colaboraciones)

---

## Instalación
Se presenta una guía escrita de como realizar la instalación del software y la puesta en marcha del kit del Pulsioxímetro.
Se deja también un link a una lista de reproducción de un canal de youtube con los videos explicativos de cada uno de los pasos de instalación.
[Youtube tutorial PulseOximeter](https://www.youtube.com/playlist?list=PLJ6_LB1a1MI06xPoo7MHM6bcKQjcWh7LC)

**Requisitos previos:**
- Microcontrolador LPC845 y sensor MAX30102.
- Módulo de hardware de acople de sensores diseñado en kicad.
- Módulo ESP8266 configurado con comandos AT.
- Fuente de alimentación de 3.3V.
- Software necesario:
  - [Qt Creator](https://www.qt.io/) 
  - Qt --> Version 6.4.2 o mayor.
  - [MCUXpresso IDE](https://www.nxp.com/design/software/development-software/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)
  - MCUXPRESSO IDE --> Version MCUXpresso IDE v11.10.0 [Build 3148] [2024-07-03] o mayor.

**Pasos de instalación:**
1. Clonar el repositorio:
	git clone https://github.com/FacundoCostarelli/University_Proyects/tree/master/Pulse_Oximeter
2. Configurar paquete de software del LPC845 y MCUXpresso IDE pre-ejecución del programa:

	**Instalación MCUXPRESSO IDE:**
	- Entrar a la página de NXP official y en descargar el MCUXpresso IDE en la versión mas reciente con link 
	[MCUXpresso IDE](https://nxp.flexnetoperations.com/control/frse/product?entitlementId=715761407&lineNum=1&authContactId=185187057&authPartyId=208677767)
	- Seguir los pasos de instalación dados por el propio instalador del IDE

   **Configurar proyecto opción 1:** --> [Video Configuración proyecto opción 1](https://www.youtube.com/watch?v=mEhIXuK23LE) 
   - Generar un archivo .zip a partir de la carpeta Microcontroller con el mismo nombre que la carpeta y guardarla en el escritorio u otro lado que puedas.
	- Abrir el MCUXPRESSO IDE, seleccionar el workspace deseado. Tipicamente viene por default con la ruta dada como
	C:\Users\nombre_usuario_de_tu_pc\Documents\MCUXpressoIDE_11.10.0_3148\workspace
	- Buscar la ventana que dice "Create or import a project". Tipicamente está en la esquina inferior izquierda.
	- Seleccionar "Import project(s) from file system".
	- Elegir "Project archive (zip)" y dar click en Browse.
	- Buscar en Browse, el archivo .zip generado en el 1er paso.
	- Dar click en next y en la siguiente ventana debe aparecer un cuadro blanco con el nombre del proyecto como SPO2_HR
	y justo al lado una caja con un tick de okey.
	- Dar click en finish y luego en el próximo cartel de modificar las configuraciones dar en "Yes to all".
	- El proyecto está ahora abierto con todas las configuraciones y las carpetas con archivos .cpp y .h  .
	- Compilar con el simbolo de "Martillo" ubicado en la barra superior, verificar que no hay errores e ignorar Warnings.

	**Configurar proyecto opción 2:** --> [Video Configuración proyecto opción 2](https://www.youtube.com/watch?v=ol-p68hnu50)
	- Abrir el MCUXPRESSO IDE, seleccionar el workspace deseado. Tipicamente viene por default con la ruta dada como
	C:\Users\nombre_usuario_de_tu_pc\Documents\MCUXpressoIDE_11.10.0_3148\workspace
	- Crear un nuevo proyecto desde "File"-->"New"-->"Create a C/C++ project" y elegir en "Target" el "LPC84x"-->"LPC845".
	- Dar click en "next >" y en la ventana de "Wizard selection page" elegir "C++ project".
	- En "Project name" dar un nombre, por ejemplo "SPO2_HR" y dejar con el tick la casilla de "Use default location". Ya que necesitamos que se cree el proyecto en el worksapace cuya ruta es dada por default por el MCUXPRESSO IDE durante la instalación del IDE.
		- En "Wizar properties page" desactivamos la casilla de "Enable use of RomDivie library by compiled code" y damos en "Next >".
		- En "Micro Trace Buffer Enable" desactivamos la casilla de "Enable definition of buffer array for MTB".
		- En "Code Read Protection (CRP)" desactivamos la casilla de "Enable linker support for CRP".
	- Estos últimos 3 pasos es necesario desactivar estos casilleros ya que no se usan en el proyecto y en caso de querer usarlo, añaden consumo de memoria y recursos del microcontrolador y este consumo no es deseado.
	- El resto de opciones deben quedar en la configuración por default.
	- Dar click en "Finish" y esperar a que el IDE configure lo necesario.
	- Luego debe aparecer a la izquierda en la ventana de "Projects" nuestro proyecto generado con su nombre y sub carpetas.
	- Ahora debemos borrar la carpeta "src" generada por default.
	- Descargar las carpetas "src", "Drivers_LPC845" y "Utils" del repositorio. Podemos descargar todo el repositorio o solo las carpetas individuales. Solo usamos estas carpetas mencionadas ahora.
	- Copiar y pegar dando click derecho en el nombre del proyecto, las carpetas "src", "Drivers_LPC845" y "Utils" ubicadas en la carpeta Microcontroller en el repositorio de "Universiy_Projects".
	- Dar click derecho en la carpeta del proyecto y elegir "Properties", luego seleccionar "C/C++ Build"-->"settings" y de "MCU C++ Compiler"-->"Includes".
	- En "Includes" elegir "Include paths" y luego "add"(tiene un simbolo de una hoja con un +". Se abre la ventana "Add directoty path" y elegir workspace.
	- Luego vemos que aparece la ventana "Folder selection". Buscar la carpeta general del proyecto de nombre "SPO2_HR". Dar click y elegir cada carpeta y sub carpeta, una por vez. Estas son: "src", "Drivers_LPC845","dr_init", "esp8266", "gpio", "I2C", "perifericoTemporizado", "pinInt", "sensor", "SerialCom", "systick", "timer", "Utils", "queue", "strings".
	- Se deben añadir todas las carpetas y subcarpetas mencionadas una a la vez y luego dar "Apply and close. Para cada carpeta se repite el proceso.
	- Compilar con el simbolo de "Martillo" ubicado en la barra superior y verificar que no hay errores e ignorar Warnings.
3. Configurar la interfaz Qt y el QT IDE pre-ejecución del programa:

	**Instalacion de QT:**
	- Entrar en la página oficial del QT y descargar la versión mas reciente siendo "open source" de acuerdo con este link
	[QT IDE](https://www.qt.io/download-open-source)
	- Bajar en la página y elegir “Download the Qt Online Installer”.
	- Seleccionamos la última versión cuidando la selección del compilador GCC o en caso de Windows MinGW
	- Para la descarga e instalación debe considerar SOLAMENTE los siguientes paquetes de software:
	![QT Software Packages 1](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/QT_GraphicUserInterface/Software%20Packages%20ScreenShots/Picture1.jpeg)
	![QT Software Packages 2](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/QT_GraphicUserInterface/Software%20Packages%20ScreenShots/Picture2.jpeg)

4. Configurar SSID y dirección IP de WIFI del ESP8266
	- Recordar que este proyecto utiliza una red wifi donde el celular trabaja como servidor en modo hotspot con roaming data donde el ESP8266 y el PC tipo notebook son clientes. 
	- Configurar telefono movil o celular en modo hotspot y asegurarsede tener data roaming.
	- Conectar PC tipo notebook o cualquier PC con red de wifi al telefono.
	- En MCUXpresso IDE, buscamos el proyecto SPO2_HR y luego "Drivers_LPC845"-->"esp8266"-->"ESP8266.h" buscamos la sección comentada como "Configuración de conexión y servidor TCP". Allí, buscamos la linea 22 y modificamos el "#define WIFI_SSID "MIRED" por el nombre de nuestra red de wifi del celular en modo hotspot. No puede contener espacios ni caracteres especiales, o simplemente dejamos este nombre y configuramos nuestro telefono en modo hotspot colocando el nombre de "MIRED".
	- Buscamos la linea 24 y modificamos el "#define TCP_HOST "192.168.116.150", en particular la dirección IP debe ser modificada segun la que aparece asociada al PC conectado en el celular. Esto se ve dentro del modo hotspot desde el celular o desde la laptop en "propiedades" de la red wifi y luego en IPV4. 

5. Ensamblar hardware y ejecutar paquete de software del LPC845 y la aplicación de interfaz de QT
	- Calibrar el móduo regulador DC-DC mini360 de color verde debajo de donde va el LPC845. Para esto girar el pequeño tornillo gris con un destornillador paleta o cruz de punta pequeña. Se deben alcanzar 3,3V a la salida del regulador. Para verificarlo, conectar una fuente de tensión directa a la entrada y medir con un voltimetro la tensión de salida en los bornes del regulador mientras se gira el tornillo en simultaneo.
	- Colocar modulos wifi, sensor MAX30102 y microcontrolador en la placa previamente construida. Se deben colocar en las tiras de pines correspondientes como indica el plano esquemático de Kicad. 
	- El plano se y el modelado 3D se puede ver en archivo PDF de nombre "oximeter_max30102_LPC845" o en el siguiente link [PulseOximeter Hardware](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/Hardware/oximeter_max30102_LPC845.pdf)
	
---

## Uso
Una vez realizados todos los pasos de instalación y configuración, se deben realizar los siguientes pasos:

**Pasos de uso:**
- Conectar el microcontrolador con cable usb a la PC pero no conectar en la bornera ninguna fuente aún.
- En MCUXpresso IDE compilar codigo con el simbolo del martillo y ejecutar el código con el botón de "Play =" y luego dar click en el botón cuadrado rojo de "terminate".
- Abrir una terminal en el MCUXpresso IDE. Desde "Window"-->"show view"-->"other"-->"terminal"-->"open".
- En QT IDE abrir proyecto de Interfaz_QT y ejecutar la aplicación en QT con el botón de "Play". Luego dar click en "Mediciones".
- Con las ventanas de la GUI del QT y de la terminal del MCUXpresso IDE, ahora conectar una fuente de tensión continua en la bornera azul. Debe tener uno de los siguientes valores: 5V o 9V o 12V. 
  También puede tener una valor de tensión continua entre 5V y 20V. Se recomienda una fuente de laboratorio de 5V o una pila de 9V.
- Aplicar un reset al LPC. Debe pulsar 2 segundos y soltar al botón de reset(en color negro) de la placa del LPC845.
- Si todo va bien ,y con cierta demora, en la consola del MCUXpresso IDE se debe ver en consola una serie de comandos AT y respuestas del tipo "OK" desde el módulo.
- Si la información se está enviando correctamene pues se deben ver mensajes como:
	...
	...
	...	
	...	
 	...
- Si hay problemas en la transmisión de datos, entonces hacer otro reset tantas veces como sea necesario.
- Visualizar los datos en la GUI en el QT. Observar en tiempo real los valores de SPO2 y frecuencia cardíaca procesados en la interfaz Qt.
- Tener en cuenta que:
	- Los primeros datos de SPO2 y HR deben descartarse de la observación. La estabilización del proceso de medición requiere de algunos segundos de demora.
	- El refresco de datos es cada medio segundo. Esto puede ser modificado.
	- Cuando un dato es repetido multiples veces en la medición, pues se muestra el valor del dato pero sin refrescar hasta que aparezca un nuevo cambio en la medición, para evitar repeticiones inecesarias de los datos.
	- Guardar mediciones, se debe dar click en "Guardar" en la interfaz para almacenar los datos localmente en un archivo. 
	- Se obtiene un archivo que almacena los datos de cada paciente que puede ser modificado desde un block de notas txt o desde la interfaz en el botón de "editar".

---

## Problemas comunes
  1. Problemas con dispositivos durante la investigación:
	  - Descripción: Dificultad para encontrar dispositivos económicos, fáciles de programar y con soporte técnico adecuado.
	  - Solución: Colaboración con el laboratorio GBIO, que proporcionó el sensor MAX30102 y el módulo WiFi ESP8266, ambos previamente utilizados con éxito por otros estudiantes.
  2. Ruido y falso contacto en el prototipo de hardware:
	  - Descripción: Problemas de ruido en la comunicación debido a cables largos en el protoboard y falso contacto entre módulos.
	  - Solución: Diseño de una PCB que fijó los módulos y utilizó pistas cortas. Se empleó una batería en lugar de una fuente de laboratorio.
  3. Sobrecarga en la alimentación de los módulos:
	  - Descripción: Altas demandas de corriente del módulo WiFi causaron sobrecalentamiento y daños en el microcontrolador y el módulo WiFi.
	  - Solución: Separar las alimentaciones: el regulador alimenta al sensor MAX30102 y al ESP8266, mientras que el microcontrolador usa una conexión USB.
  4. Configuración del módulo WiFi con adaptadores TTL:
	  - Descripción: El adaptador FTDI232 no funcionó correctamente, dificultando la visualización de comandos AT.
	  - Solución: Uso de la consola UART del IDE MCUXpresso para configurar el ESP8266.
  5. Sobrecorriente en el módulo WiFi:
	  - Descripción: Picos de corriente del ESP8266 superaban los 200 mA, causando inestabilidad.
	  - Solución: Uso de un regulador adecuado y un capacitor de 100 µF para amortiguar los picos.
  6. Problemas de comunicación I2C:
	  - Descripción: Dificultades para sincronizar el envío de direcciones y datos al sensor MAX30102.
	  - Solución: Introducir retrasos entre comandos, utilizar un analizador lógico para depuración, y consultar foros y bibliotecas de NXP.
  7. Configuración compleja del sensor MAX30102:
	  - Descripción: Documentación poco clara sobre el uso de punteros FIFO y el orden de configuración.
	  - Solución: Realización de pruebas exhaustivas y consulta de proyectos previos para identificar el orden correcto.
  8. Problemas de programación del módulo WiFi:
	  - Descripción: Dificultades con el patrón de comunicación, comandos AT, y uso de funciones bloqueantes.
	  - Solución: Implementación de una máquina de estados para manejar respuestas "OK\r\n" y un sistema de encolamiento para transmitir mensajes.

---

## Documentación
Para mayor información y detalles se sugiere consultar los siguientes enlaces. También puede consultar la carpeta "DocumentsAndDatasheets" dentro de la carpeta "Pulse_Oximeter" en el repositorio de "University_Proyects"

- [Informe Técnico en ESP](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Informe_T%C3%A9cnico_PulseOximeter.pdf)
- [Informe Idea Fuerza en ESP](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Informe_Idea_Fuerza_PulseOximeter.pdf)

Para más detalles técnicos, consulta las hojas de datos de los componentes:

- [Datasheet Module MAX30102](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Module_MAX30102_Datasheet.pdf)
- [Recommended Configurations Module MAX3010x](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Module_MAX3010x_ev_kits_recommended_configurations_and_operating_profiles.pdf)
- [Datasheet Module ESP8266](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Module_ESP8266_Datasheet.pdf)
- [Instruction Set ESP8266](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Module_esp8266_at_instruction_set_en.pdf)
- [Command Examples ES8266](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Module_esp8266_at_command_examples_en.pdf)
- [Datasheet Module LPC845](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/LPC84X_User_Manual.pdf)
- [Datasheet Breakout Board LPC845](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/LPC845_Breakout_board_User_Manual.pdf)
- [Schematic Breakout Board LPC845](https://github.com/FacundoCostarelli/University_Proyects/blob/master/Pulse_Oximeter/DocumentsAndDatasheets/Schematic_LPC845_BRK_RevA.PDF)

---

## Fuentes De Consulta
- [Foros de NXP en LPC845](https://community.nxp.com/t5/forums/searchpage/tab/message?advanced=false&allow_punctuation=true&q=LPC845)
- [Foros de StackOverflow](https://stackoverflow.com/)
- [Chat GPT PLUS](https://chatgpt.com/)

Aclaración: Utilizamos principalmente los foros y algo de ayuda de la IA de ChatGPT. Es necesario mencionar que el chat gpt no funciona en general bien para la programación de microcontroladores.
Es necesario enviar al chat algunos archivos, ideas y codigo desarrollado por el programador sin ayuda de la IA al menos en forma de prototipo para recibir ayuda clara de la IA. 
Es recomendable enviar incluso bloques de código que funcionen y pedir ayuda concreta en secciones específicas y a partir de allí tomar la ayuda.
No es recomendable copiar y pegar ya que seguramente no funcione el código brindado en C y C++ por ser aplicado en el microcontrolador específico.
Si es recomendable tomar como referencia la estructura de código brindada, líneas de código y funciones específicas aunque con modificaciones necesarias según el datasheet del microcontrolador.

---

## Contribución

Toda colaboración es bienvenida. Sigue estos pasos para contribuir:

  1. Realiza un fork del repositorio.

  2. Crea una nueva rama para tu funcionalidad o corrección:
     - git checkout -b feature/nueva-caracteristica
  3. Realiza tus cambios y haz commit:
     - git commit -m "Descripción de los cambios realizados"
  4. Haz push a tu rama:
     - git push origin feature/nueva-caracteristica
  5. Crea un Pull Request describiendo tus cambios.

---

## Licencia
Este proyecto está licenciado bajo la Licencia Pública General GNU v3.0. 
Puedes usar, modificar y distribuir este proyecto respetando los términos de la licencia.

---

## Autores
- Facundo Costarelli

---

## Reconocimientos Y Colaboraciones
- Laboratorio de Bio Ingeniería UTN BA [Sitio web UTN BA-GBIO](https://www.frba.utn.edu.ar/gibio/)
- Prof Doctor Ing Leandro Cymberknop(Electrónica en UTN BA)
- Prof Ing Mariana Prieto(Electrónica en UTN BA)
- Prof Ing Jorge Escola(Electrónica en UTN BA)
- Estudiante de Ing Juan(Electrónica en UTN BA)
- Estudiante de Ing Nahuel(Electrónica en UTN BA)
- Estudiante de Ing Maximiliano(Electrónica en UTN BA)
- Estudiante de Ing Matias(Electrónica en UTN BA)
- Estudiante de Ing Franco Callero(Informática y Sistemas en UTN BA)
- Estudiante de Ing Ezequiel Lagatche(Electrónica en UTN BA)
- Estudiante de Ing Guido Rodriguez(Electrónica en UBA)

**Abreviaciones:**
UTN BA-->Universidad Tecnológica Nacional de Buenos Aires

UBA   -->Universidad de Buenos Aires


