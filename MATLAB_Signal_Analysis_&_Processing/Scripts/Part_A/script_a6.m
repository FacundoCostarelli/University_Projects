%% Script_a6
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Ejemplo de aplicaci�n de la funci�n f_calc_e(num_elements):

num_elements = 18; % Creo una variable con el n�mero de t�rminos de la serie de euler
e_aprox = f_calc_e(num_elements); % Calculo el n�mero de euler a traves de la funci�n
fprintf('e_aprox: %.16f\ne_matlab: %.16f\n', e_aprox, exp(1)) % Comparacion del valor calculado de euler y el real dado por matlab