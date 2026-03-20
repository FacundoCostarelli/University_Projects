# Original Text - v0.2_Final_R1101_info1_2022-12-16.pdf

Universidad Tecnológica Nacional       16 de Diciembre de 2022 Final  
Facultad Regional Buenos Aires  
Departamento de Ingeniería Electrónica  
Informática I  
 
 
Apellido y Nombres  Legajo  # de Hojas  
   
 
Aprueba si suma 60% y al menos tiene: 30% práctica y 20% teoría simultáneamente  
T1(20%)  T2(20%)  P1 (20%)  P2 (20%)  P3(20%)  TOTAL  
      
 
Normas Generales   
Numere las hojas entregadas. Lea detenidamente cada pregunta, la interpretación del enunciado forma parte de la evaluación.  
Complete en la primera hoja la cantidad total de hojas entregadas. Realice este parcial con tinta color azul o negro. No utilice rojo ni 
verde por favor . Cada e jercicio debe realizarse en hojas separadas y numeradas. Debe identificarse cada hoja con: Nombre, 
Apellido, Legajo. Por favor entregar esta hoja y las restantes del tema junto al examen.  
 
 
Sección teórica TIEMPO 15m [Correcto +1, Incorrecto -1, Incorrecto Justificado 0]  
 
1. Sobre Thread tilde las correctas:  
● pthread_join() bloquea el hilo en el cual se invoca a la espera de que el que se pone en el argumento 
finalize.  
● pthread_join() NO bloquea el hilo en el cual se invoca  a la espera de que el que se pone en el 
argumento finalize.  
● Un thread , comparte con los otros thread del mismo proceso heap y stack.  
● Un thread , NO comparte con los otros thread del mismo proceso heap y stack.  
2. Sobre socket tilde las correctas:  
● Los únicos socket que existen son los tcp/ipv4.  
● Los socket tcp/ipv4 determinan una conexión utilizando 2 IP, y 2 puertos.  
● Los socket tcp/ipv4 determinan una conexión utilizando 1 IP, y 1 puertos.  
● Los socket tcp/ipv4 determinan una conexión utilizando 2 IP,  y 4 puertos.  
● accept() es una función bloqueante , hasta que un cliente no se conecta , no se desbloquea.  
● connect() es la función que llama el código del cliente para conectarse a un servidor.  
● Una conexión tcp está completamente cerrada , si de cada lado s e hace un close() sobre la conexión 
establecida.  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
Sección Práctica  
Universidad Tecnológica Nacional       16 de Diciembre de 2022 Final  
Facultad Regional Buenos Aires  
Departamento de Ingeniería Electrónica  
Informática I  
 
 
Apellido y Nombres  Legajo  # de Hojas  
   
 
Aprueba si suma 60% y al menos tiene: 30% práctica y 20% teoría simultáneamente  
T1(20%)  T2(20%)  P1 (20%)  P2 (20%)  P3(20%)  TOTAL  
      
 
Normas Generales   
Numere las hojas entregadas. Lea detenidamente cada pregunta, la interpretación del enunciado forma parte de la 
evaluación.  
Complete en la primera hoja la cantidad total de hojas entregadas. Realice este parcial con tinta color azul o negro. No utilice rojo ni 
verde por favor . Cada e jercicio debe realizarse en hojas separadas y numeradas. Debe identificarse cada hoja con: Nombre, 
Apellido, Legajo. Por favor entregar esta hoja y las restantes del tema junto al examen.  
Un switch  es un dispositivo de comunicaciones en redes de datos de paquetes.El mismo cuenta con 
conectores físicos de interconexión (puertos), donde se inserta un cable con un conector en su 
extremo(el otro extremo puede ir conectado a una computadora). Cada dispos itivo que envía 
mensajes en la red tiene una etiqueta identificadora llamada dirección mac , que es un número de 6 
bytes.  
  Analizando el paquete recibido, un switch debe ser capaz de identificar en qué puerto ingresó un 
paquete, y luego de un procesamient o saber porque puerto tiene que salir.  
En este examen se pide realizar solo algunas  partes del funcionamiento de un switch, con el fin de 
lograr una simulación de su funcionamiento.  
 
Como parte de un software de simulación de redes se pide:  
 Construir un m ain que llame a las funciones de los puntos  (1,2,3), y agregue cualquier 
función que considere necesaria:  
 
1. Realizar una función que rellene dinámicamente un array estático, de punteros a struct 
paquete    de 10 posiciones. La estructura interna de struct p aquete  se detalla debajo, 
notar que cada struct paquete, contiene 2 struct port que se utilizan como campo de 
bits.(el array debe ser creado en el main). Con esta función simulamos la existencia de 
10 paquetes.  
2. Realizar una función que rellene aleatoriamen te los array de char llamados MACori  y 
MACdes  que forman parte de la estructura, y rellene  los struct port entrada y salida. 
(En estos últimos sólo 1bit de cada struct port entrada y struct por salida  puede valer 
‘1’). Con este ítem se busca lograr tener una dirección mac  de origen  y una dirección 
mac de destino  aleatoria, junto con un  puerto de origen aleatorio (por donde el 
paquete simulado entro), y un puerto de salida  aleatorio(por donde el paquete 
simulado debería salir)  
3. Realizar una función que imprima en la terminal según el siguiente título.  
a) MAC_Destino MAC_Origen Puerto_Salida Puerto_Entrada.  
 
 
 
 
 
 
 
 
Universidad Tecnológica Nacional       16 de Diciembre de 2022 Final  
Facultad Regional Buenos Aires  
Departamento de Ingeniería Electrónica  
Informática I  
 
 
Apellido y Nombres  Legajo  # de Hojas  
   
 
Aprueba si suma 60% y al menos tiene: 30% práctica y 20% teoría simultáneamente  
T1(20%)  T2(20%)  P1 (20%)  P2 (20%)  P3(20%)  TOTAL  
      
 
Normas Generales   
Numere las hojas entregadas. Lea detenidamente cada pregunta, la interpretación del enunciado forma parte de la 
evaluación.  
Complete en la primera hoja la cantidad total de hojas entregadas. Realice este parcial con tinta color azul o negro. No utilice rojo ni 
verde por favor . Cada e jercicio debe realizarse en hojas separadas y numeradas. Debe identificarse cada hoja con: Nombre, 
Apellido, Legajo. Por favor entregar esta hoja y las restantes del tema junto al examen.  
 
    struct port  
    { 
unsigned char p0:1;  
unsigned char p1:1;  
unsigned char p2:1;  
unsigned char p3:1;  
unsigned char p4:1;  
unsigned char p5:1;  
unsigned char p6:1;  
unsigned char p7:1;  
    }; struct paquete  
{ 
 unsigned char MACori[6];  
 unsigned char MACdes[6];  
struct port entrada;  
struct port salida;  
}; 
 
 
 
 
