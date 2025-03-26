%% Script_a1
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura
%% Ejercicio
% Realice un script que obtenga m�dulo y fase, parte real e imaginaria
% y el conjugado de los siguientes n�meros complejos:

% Creo variables de n�meros complejos con las operatorias de enunciado
z_1 = -1 + 2i;
z_2 = 2 * exp(-i*pi/4);
z_3 = z_1 + z_2;
z_4 = z_1 - z_2;
z_5 = z_1 * z_2;
z_6 = z_1 / z_2;
z_7 = z_1 ^ 3;

% Creo un vector "z" de n�meros complejos y le calculo la traspuesta para
% mejor visualizaci�n
z = [z_1 z_2 z_3 z_4 z_5 z_6 z_7]'

% Creo vectores que contienen los resultados de m�dulo, fase, parte real
% parte imaginaria y conjugado. Esto por cada n�mero complejo del vector "z"

% Utilizo todas funciones incorporadas en MatLab
modulo = abs(z)
fase = angle(z)
parte_real = real(z)
parte_imaginaria = imag(z)
conjugado = conj(z)

% Grafico de los n�meros complejos ubicados en el vector "z"
figure
zplane(z); 
grid on;
hold on;
compass(z);
hold off;