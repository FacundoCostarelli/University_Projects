%% Script_b1
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% 
% Realice un script donde se visualicen las siguientes señales, utilizando 
% el array temporal: t = 0 : 1/fs : 1 siendo fs = 44kHz(frecuencia de muestreo)
% Calcule, además, los puntos máximos y mínimo(junto con los índices de 
% dichos puntos) para cada una de las señales dadas por enunciado: 

% Creo una vairable que almacena la frecuencia de muestreo
fs = 44000;
% Creo un array temporal
t = 0 : 1/fs : 1;
% Creo vectores horizontales que son equivalentes a funciones y(t), esto
% siguiendo las expresiones propuestas por enunciado para cada una
y1 = esc(t-0.1) + 10 * ramp(t-0.2) - 30 * ramp(t-0.5) + 20 * ramp(t-0.8)...
    - esc(t-0.8);
y2 = 2 * (ramp(t) - 2 * ramp(t-0.4) + ramp(t-0.8));
y3 = y2 .* sin(100 * pi * t);
y4 = 0.2 * cos(1000 * pi * t);
y5 = y2 .* sin(2000 * pi * t);
y6 = 0.5 * (y5 + y4);

% Creo una matriz de n = 6 filas y m = 44000 columnas que almacena cada una
% de las funciones y(t)
y = [y1 ; y2 ; y3 ; y4 ; y5 ; y6];

% Creo vectores horizontales que almacenan los máximos y mínimos asi como
% los indices de posición
[max , ind_max] = max(y')
[min , ind_min] = min(y')

%% Reprodución de audio de las funciones y4(t), y5(t) e y6(t)
%Inicializo el audioplayer para la salida "y4"
player = audioplayer(y4, fs); 
%Reproduzco el tono
playblocking(player) 

%Inicializo el audioplayer para la salida "y5"
player = audioplayer(y5, fs); 
%Reproduzco el tono
playblocking(player) 

%Inicializo el audioplayer para la salida "y6"
player = audioplayer(y6, fs); 
%Reproduzco el tono
playblocking(player) 
    
%% Grafico de las funciones que conforman la matrix "y". 

%Calculo la cantidad de signals que tiene mi matrix. Para ello, calculo la "cantidad de filas"
% de la matrix "y". 
cantidad_senales = size(y, 1);

% Itero signal a signal y grafico en cada cuadro una funcion la cual es una
% fila de la matrix "y"
for i = 1 : cantidad_senales
    subplot(ceil(cantidad_senales/2), ceil(cantidad_senales/2), i);
    plot(t, y(i,:));
    title(sprintf('Función y%d', i));
	ylabel(sprintf('y%d', i));
    xlabel('t [seg]');
end
