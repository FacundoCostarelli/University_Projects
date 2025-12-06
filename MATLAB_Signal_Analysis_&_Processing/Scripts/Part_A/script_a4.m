%% Script_a4

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

%% Ejemplo de aplicación de la función f_get_roots(n, z):
%[ESP] Definición del argumento (número complejo) para la raíz.
%[ENG] Defining the argument (complex number) for the root.
z = -1; % Argumento de la raiz

%[ESP] Definición del exponente (índice) de la raíz.
%[ENG] Defining the exponent (index) of the root.
n = 2; % Exponente de la raiz

%[ESP] Llamada a la función personalizada para calcular las raíces.
%[ENG] Calling the custom function to calculate the roots.
[res_xy, res_abs, res_angle] = f_get_roots(n, z);

%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
figure; 

%[ESP] Graficación de las raíces (res_xy) en el plano Z.
%[ENG] Plotting the roots (res_xy) on the Z-plane.

zplane(res_xy);

%[ESP] Activación de la cuadrícula en el gráfico.
%[ENG] Activating the grid on the plot.
grid on;

%[ESP] Mantenimiento del gráfico actual para superponer otro.
%[ENG] Holding the current plot to overlay another one.
hold on;

%[ESP] Superposición de un gráfico de brújula (vectores).
%[ENG] Overlaying a compass (vector) plot.
compass(res_xy);

%[ESP] Liberación del gráfico.
%[ENG] Releasing the plot.
hold off;