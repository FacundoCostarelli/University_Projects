%% Script_b5

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

%% Ejemplo de aplicación de la función f_plot_conv

%[ESP] Definición del incremento (paso) de tiempo.
%[ENG] Defining the time increment (step).
dt = 0.01; % Incremento diferencial

%[ESP] Creación del vector de tiempo para la señal 'x'.
%[ENG] Creating the time vector for signal 'x'.
t_x = -1 : dt : 10; % Creo un vector temporal para la señal de entrada

%[ESP] Creación del vector de tiempo para la señal 'h'.
%[ENG] Creating the time vector for signal 'h'.
t_h = -2 : dt : 5; % Creo un vector temporal para la respuesta impulsional

%[ESP] Creación de la señal de entrada 'x' (pulso).
%[ENG] Creating the input signal 'x' (pulse).
x = esc(t_x) - esc(t_x-8); % Creo un vector asociado a la señal de entrada

%[ESP] Creación de la respuesta al impulso 'h' (exponencial).
%[ENG] Creating the impulse response 'h' (exponential).
h = 5*esc(t_h).*exp(-2*t_h); % Creo un vector asociado a la respuesta impulsional

%[ESP] Llamada a la función para convolucionar x*h y graficar.
%[ENG] Calling the function to convolve x*h and plot.
f_plot_conv(t_x, x, t_h, h); % Realizo la convolución entre x e h a partir de invocar a la función. 

%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
figure;

%[ESP] Llamada a la función para convolucionar h*x (propiedad conmutativa).
%[ENG] Calling the function to convolve h*x (commutative property).
f_plot_conv(t_h, h, t_x, x); % Realizo la convolución entre x e h a partir de invocar a la función. Por propiedad, deberian resultar iguales