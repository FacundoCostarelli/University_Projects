%% Script_b1

% Author: Facundo Costarelli

%[ESP] Limpieza de la ventana de comandos.
%[ENG] Clearing the command window.
clc; % Limpia Command Window

%[ESP] Limpieza de todas las variables del espacio de trabajo.
%[ENG] Clearing all variables from the workspace.
clear; % Limpia Workspace al liberar memoria (variables)

%[ESP] Cierre de todas las ventanas de figuras abiertas.
%[ENG] Closing all open figure windows.
close all; % Cierra todas las figura 

%% 
% Realice un script donde se visualicen las siguientes señales, utilizando 
% el array temporal: t = 0 : 1/fs : 1 siendo fs = 44kHz(frecuencia de muestreo)
% Calcule, además, los puntos máximos y mínimo(junto con los índices de 
% dichos puntos) para cada una de las señales dadas por enunciado: 

%[ESP] Definición de la frecuencia de muestreo.
%[ENG] Defining the sampling frequency.
% Creo una vairable que almacena la frecuencia de muestreo
fs = 44000;

%[ESP] Creación del vector de tiempo.
%[ENG] Creating the time vector.
% Creo un array temporal
t = 0 : 1/fs : 1;

%[ESP] Generación de las 6 señales (y1 a y6) basadas en las funciones.
%[ENG] Generating the 6 signals (y1 to y6) based on the functions.
% Creo vectores horizontales que son equivalentes a funciones y(t), esto
% siguiendo las expresiones propuestas por enunciado para cada una
y1 = esc(t-0.1) + 10 * ramp(t-0.2) - 30 * ramp(t-0.5) + 20 * ramp(t-0.8)...
     - esc(t-0.8);
y2 = 2 * (ramp(t) - 2 * ramp(t-0.4) + ramp(t-0.8));
y3 = y2 .* sin(100 * pi * t);
y4 = 0.2 * cos(1000 * pi * t);
y5 = y2 .* sin(2000 * pi * t);
y6 = 0.5 * (y5 + y4);

%[ESP] Agrupación de todas las señales en una matriz.
%[ENG] Grouping all signals into one matrix.
% Creo una matriz de n = 6 filas y m = 44000 columnas que almacena cada una
% de las funciones y(t)
y = [y1 ; y2 ; y3 ; y4 ; y5 ; y6];

%[ESP] Cálculo de los valores máximos e índices.
%[ENG] Calculating the maximum values and indices.
% Creo vectores horizontales que almacenan los máximos y mínimos asi como
% los indices de posición
[max , ind_max] = max(y')

%[ESP] Cálculo de los valores mínimos e índices.
%[ENG] Calculating the minimum values and indices.
[min , ind_min] = min(y')

%% Reprodución de audio de las funciones y4(t), y5(t) e y6(t)
%[ESP] Creación del objeto reproductor para y4.
%[ENG] Creating the player object for y4.
%Inicializo el audioplayer para la salida "y4"
player = audioplayer(y4, fs); 
%[ESP] Reproducción del audio (bloqueante).
%[ENG] Playing the audio (blocking).
%Reproduzco el tono
playblocking(player) 

%[ESP] Creación del objeto reproductor para y5.
%[ENG] Creating the player object for y5.
%Inicializo el audioplayer para la salida "y5"
player = audioplayer(y5, fs); 
%[ESP] Reproducción del audio (bloqueante).
%[ENG] Playing the audio (blocking).
%Reproduzco el tono
playblocking(player) 

%[ESP] Creación del objeto reproductor para y6.
%[ENG] Creating the player object for y6.
%Inicializo el audioplayer para la salida "y6"
player = audioplayer(y6, fs); 
%[ESP] Reproducción del audio (bloqueante).
%[ENG] Playing the audio (blocking).
%Reproduzco el tono
playblocking(player) 
     
%% Grafico de las funciones que conforman la matrix "y". 

%[ESP] Obtención del número de señales (filas) a graficar.
%[ENG] Getting the number of signals (rows) to plot.
%Calculo la cantidad de signals que tiene mi matrix. Para ello, calculo la "cantidad de filas"
% de la matrix "y". 
cantidad_senales = size(y, 1);

%[ESP] Inicio del bucle para graficar cada señal.
%[ENG] Starting the loop to plot each signal.
% Itero signal a signal y grafico en cada cuadro una funcion la cual es una
% fila de la matrix "y"
for i = 1 : cantidad_senales
    %[ESP] Selección de la sub-figura (mosaico).
    %[ENG] Selecting the subplot (tiling).
    subplot(ceil(cantidad_senales/2), ceil(cantidad_senales/2), i);
    %[ESP] Graficación de la señal i-ésima vs tiempo.
    %[ENG] Plotting the i-th signal vs time.
    plot(t, y(i,:));
    %[ESP] Asignación de títulos y etiquetas.
    %[ENG] Assigning titles and labels.
    title(sprintf('Función y%d', i));
	ylabel(sprintf('y%d', i));
    xlabel('t [seg]');
end
