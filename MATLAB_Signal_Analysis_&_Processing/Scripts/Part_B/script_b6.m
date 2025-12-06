%% Script_b6

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

%% Ejemplo de aplicación de la función f_stem_conv

%[ESP] Creación del vector de índices para la señal de entrada.
%[ENG] Creating the index vector for the input signal.
% Creo un vector de muestras o índices para la señal de entrada
n_x = -5 : 50;

%[ESP] Creación del vector de índices para la respuesta al impulso.
%[ENG] Creating the index vector for the impulse response.
% Creo un vector de muestras o índices para la respuesta impulsiona
n_h = -2 : 20;

%[ESP] Creación de la señal de entrada 'x' (pulso).
%[ENG] Creating the input signal 'x' (pulse).
% Creo un vector asociado a la señal de entrada
x = esc(n_x) - esc(n_x-30);

%[ESP] Creación de la respuesta al impulso 'h' (exponencial).
%[ENG] Creating the impulse response 'h' (exponential).
% Creo un vector asociado a la respuesta impulsional
h = 5*esc(n_h).*exp(-0.5*n_h);

% Realizo la convolución entre x e h a partir de invocar a la función.
% Ejecuta la operatoria enviando los parametros de una u otra forma
%[ESP] Llamada a la función para convolucionar x*h y graficar.
%[ENG] Calling the function to convolve x*h and plot.
f_stem_conv(n_x, x, n_h, h);

%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
figure;
%Por propiedad, deberian resultar iguales los resultados de las
%invocaciones
%[ESP] Llamada a la función para convolucionar h*x (propiedad conmutativa).
%[ENG] Calling the function to convolve h*x (commutative property).
f_stem_conv(n_h, h, n_x, x);
