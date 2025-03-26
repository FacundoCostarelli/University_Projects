%% Script_b4
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%%

% Creo un vector temporal para la señal de entrada
dt1 = 0.01;
t1 = -1 : dt1 : 10;
% Creo un vector asociado a la señal de entrada
x = esc(t1) - esc(t1-8);

% Creo un vector temporal para la respuesta impulsional
dt2 = 0.01;
t2 = -2: dt2 : 5;
% Creo un vector asociado a la respuesta impulsional
a = 2;
b = 5;
h = (b * exp(-a * t2)) .* esc(t2); 
 
% Creo un vector temporal para la señal de salida
dt_y = 0.01;
t_y =  (t1(1) + t2(1)): dt_y : (t1(end) + t2(end));
% Creo un vector asociado a la señal de salida
y = conv(x,h) * dt_y;

% Grafico de la señal de entrada
subplot(3,1,1); plot(t1,x); axis([-1 10 -1 2]);
title('Señal de enttrada'); ylabel('x(t)'); xlabel('t[seg]');
% Grafico de la respuesta impulsional 
subplot(3,1,2); plot(t2,h); axis([-2 5 -1 6]);
title('Respuesta al Impulso'); ylabel('h(t)'); xlabel('t[seg]');
% Grafico de la señal de salida
subplot(3,1,3); plot(t_y,y); axis([(t1(1) + t2(1)) (t1(end) + t2(end)) -1 3]);
title('Salida: convolución de la entrada con la respuesta al impulso'); ylabel('y(t)'); xlabel('t[seg]'); 
