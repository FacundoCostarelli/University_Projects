%% Script_b3
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Ejemplo de aplicaci�n de la funci�n f_get_even_odd(n,x):
n = -10 : 10;
x = n + 1; %Donde n es la parte impar, y 1 es la par
[x_par, x_impar] = f_get_even_odd(n,x);
x_new = x_par + x_impar;

%% Gr�fico de las 4 se�ales: Original, par, impar y reconstruida

% Abro una figura
figure;
% Creo un cuadro subdividido en 4 partes y grafico cada uno de estos
% Agrego para cada uno de ellos una etiqueta en eje y e x asi como t�tulo
subplot(411); stem(n, x); title('Funci�n Original'); ylabel('x'); xlabel('n [muestras]');
subplot(412); stem(n, x_par); title('Funci�n Par'); ylabel('x\_par'); xlabel('n [muestras]');
subplot(413); stem(n, x_impar); title('Funci�n Impar'); ylabel('x\_impar'); xlabel('n [muestras]');
subplot(414); stem(n, x_new); title('Funci�n Reconstruida'); ylabel('x\_new'); xlabel('n [muestras]');
