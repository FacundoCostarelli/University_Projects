%% Script_a6

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

%% Ejemplo de aplicación de la función f_calc_e(num_elements):

%[ESP] Definición del número de elementos para la aproximación de 'e'.
%[ENG] Defining the number of elements for the 'e' approximation.
num_elements = 18; % Creo una variable con el número de términos de la serie de euler

%[ESP] Llamada a la función personalizada para calcular 'e' aproximado.
%[ENG] Calling the custom function to calculate the approximated 'e'.
e_aprox = f_calc_e(num_elements); % Calculo el número de euler a traves de la función

%[ESP] Impresión y comparación del valor aproximado con el valor de MATLAB.
%[ENG] Printing and comparing the approximated value with MATLAB's value.
fprintf('e_aprox: %.16f\ne_matlab: %.16f\n', e_aprox, exp(1)) % Comparacion del valor calculado de euler y el real dado por matlab