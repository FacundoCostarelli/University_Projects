%% Script_a4
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura

%% Ejemplo de aplicación de la función f_get_roots(n, z):
z = -1; % Argumento de la raiz
n = 2; % Exponente de la raiz
[res_xy, res_abs, res_angle] = f_get_roots(n, z);
figure; 
zplane(res_xy);
grid on;
hold on;
compass(res_xy);
hold off;