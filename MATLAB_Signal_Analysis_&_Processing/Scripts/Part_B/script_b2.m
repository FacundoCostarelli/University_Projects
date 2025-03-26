%% Script_b2
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 
%% 
% Para la obtenci�n de la parte par e impar utilizo las expresiones
% propuestas en el cap�tulo 1 pagina 27 del libro de Asys. Esto es:
% x_par = 0.5 * (x[n] + x[-n])
% x_impar = 0.5 * (x[n] - x[-n])

% Vector sim�trico de muestras o �ndices. Este posee los valores de la 
% entrada  "n" de la se�al discreta
n = -10 : 10;
% Se�al original a descomponer (discreta)
x = n + 1; 
% Se�al par obtenida
x_par = 0.5 * (x + fliplr(x));
% Se�al impar obtenida
x_impar = 0.5 * (x - fliplr(x));
% Se�al reconstruida, a partir de sumar las partes par e impar.
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

