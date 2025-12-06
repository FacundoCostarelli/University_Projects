%% Script_b4

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

%[ESP] Definición del paso de tiempo para la entrada.
%[ENG] Defining the time step for the input.
% Creo un vector temporal para la señal de entrada
dt1 = 0.01;

%[ESP] Creación del vector de tiempo de la entrada 't1'.
%[ENG] Creating the input time vector 't1'.
t1 = -1 : dt1 : 10;

%[ESP] Creación de la señal de entrada 'x' (pulso).
%[ENG] Creating the input signal 'x' (pulse).
% Creo un vector asociado a la señal de entrada
x = esc(t1) - esc(t1-8);

%[ESP] Definición del paso de tiempo para la respuesta al impulso.
%[ENG] Defining the time step for the impulse response.
% Creo un vector temporal para la respuesta impulsional
dt2 = 0.01;

%[ESP] Creación del vector de tiempo 't2'.
%[ENG] Creating the time vector 't2'.
t2 = -2: dt2 : 5;

%[ESP] Creación de la respuesta al impulso 'h'.
%[ENG] Creating the impulse response 'h'.
% Creo un vector asociado a la respuesta impulsional
a = 2;
b = 5;
h = (b * exp(-a * t2)) .* esc(t2); 
 
%[ESP] Definición del paso de tiempo para la salida.
%[ENG] Defining the time step for the output.
% Creo un vector temporal para la señal de salida
dt_y = 0.01;

%[ESP] Creación del vector de tiempo de salida 't_y'.
%[ENG] Creating the output time vector 't_y'.
t_y =  (t1(1) + t2(1)): dt_y : (t1(end) + t2(end));

%[ESP] Cálculo de la convolución y escalado por el paso de tiempo.
%[ENG] Calculating the convolution and scaling by the time step.
% 
% Creo un vector asociado a la señal de salida
y = conv(x,h) * dt_y;

%[ESP] Graficación de la señal de entrada 'x'.
%[ENG] Plotting the input signal 'x'.
% Grafico de la señal de entrada
subplot(3,1,1); plot(t1,x); axis([-1 10 -1 2]);
title('Señal de enttrada'); ylabel('x(t)'); xlabel('t[seg]');

%[ESP] Graficación de la respuesta al impulso 'h'.
%[ENG] Plotting the impulse response 'h'.
% Grafico de la respuesta impulsional 
subplot(3,1,2); plot(t2,h); axis([-2 5 -1 6]);
title('Respuesta al Impulso'); ylabel('h(t)'); xlabel('t[seg]');

%[ESP] Graficación de la señal de salida 'y'.
%[ENG] Plotting the output signal 'y'.
% Grafico de la señal de salida
subplot(3,1,3); plot(t_y,y); axis([(t1(1) + t2(1)) (t1(end) + t2(end)) -1 3]);
title('Salida: convolución de la entrada con la respuesta al impulso'); ylabel('y(t)'); xlabel('t[seg]');