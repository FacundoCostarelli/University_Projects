%% Script_b3
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Ejemplo de aplicación de la función f_get_even_odd(n,x):
n = -10 : 10;
x = n + 1; %Donde n es la parte impar, y 1 es la par
[x_par, x_impar] = f_get_even_odd(n,x);
x_new = x_par + x_impar;

%% Gráfico de las 4 señales: Original, par, impar y reconstruida

% Abro una figura
figure;
% Creo un cuadro subdividido en 4 partes y grafico cada uno de estos
% Agrego para cada uno de ellos una etiqueta en eje y e x asi como título
subplot(411); stem(n, x); title('Función Original'); ylabel('x'); xlabel('n [muestras]');
subplot(412); stem(n, x_par); title('Función Par'); ylabel('x\_par'); xlabel('n [muestras]');
subplot(413); stem(n, x_impar); title('Función Impar'); ylabel('x\_impar'); xlabel('n [muestras]');
subplot(414); stem(n, x_new); title('Función Reconstruida'); ylabel('x\_new'); xlabel('n [muestras]');
