%% Script_b2
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 
%% 
% Para la obtención de la parte par e impar utilizo las expresiones
% propuestas en el capítulo 1 pagina 27 del libro de Asys. Esto es:
% x_par = 0.5 * (x[n] + x[-n])
% x_impar = 0.5 * (x[n] - x[-n])

% Vector simétrico de muestras o índices. Este posee los valores de la 
% entrada  "n" de la señal discreta
n = -10 : 10;
% Señal original a descomponer (discreta)
x = n + 1; 
% Señal par obtenida
x_par = 0.5 * (x + fliplr(x));
% Señal impar obtenida
x_impar = 0.5 * (x - fliplr(x));
% Señal reconstruida, a partir de sumar las partes par e impar.
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

