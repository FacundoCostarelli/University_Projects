%% Script_b5
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Ejemplo de aplicaci�n de la funci�n f_plot_conv

dt = 0.01; % Incremento diferencial
t_x = -1 : dt : 10; % Creo un vector temporal para la se�al de entrada
t_h = -2 : dt : 5; % Creo un vector temporal para la respuesta impulsional
x = esc(t_x) - esc(t_x-8); % Creo un vector asociado a la se�al de entrada
h = 5*esc(t_h).*exp(-2*t_h); % Creo un vector asociado a la respuesta impulsional
f_plot_conv(t_x, x, t_h, h); % Realizo la convoluci�n entre x e h a partir de invocar a la funci�n. 
figure;
f_plot_conv(t_h, h, t_x, x); % Realizo la convoluci�n entre x e h a partir de invocar a la funci�n. Por propiedad, deberian resultar iguales