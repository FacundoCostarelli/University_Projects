%% Script_b6
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Ejemplo de aplicación de la función f_stem_conv

% Creo un vector de muestras o índices para la señal de entrada
n_x = -5 : 50;
% Creo un vector de muestras o índices para la respuesta impulsiona
n_h = -2 : 20;

% Creo un vector asociado a la señal de entrada
x = esc(n_x) - esc(n_x-30);
% Creo un vector asociado a la respuesta impulsional
h = 5*esc(n_h).*exp(-0.5*n_h);

% Realizo la convolución entre x e h a partir de invocar a la función.
% Ejecuta la operatoria enviando los parametros de una u otra forma
f_stem_conv(n_x, x, n_h, h);
figure;
%Por propiedad, deberian resultar iguales los resultados de las
%invocaciones
f_stem_conv(n_h, h, n_x, x); 

