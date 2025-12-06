%% Script_b2

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
%% 
% Para la obtención de la parte par e impar utilizo las expresiones
% propuestas en el capítulo 1 pagina 27 del libro de Asys. Esto es:
% x_par = 0.5 * (x[n] + x[-n])
% x_impar = 0.5 * (x[n] - x[-n])
% 

%[ESP] Creación del vector de índices simétrico.
%[ENG] Creating the symmetric index vector.
% Vector simétrico de muestras o índices. Este posee los valores de la 
% entrada  "n" de la señal discreta
n = -10 : 10;

%[ESP] Creación de la señal original a descomponer.
%[ENG] Creating the original signal to decompose.
% Señal original a descomponer (discreta)
x = n + 1; 

%[ESP] Cálculo de la componente par de la señal.
%[ENG] Calculating the even component of the signal.
% Señal par obtenida
x_par = 0.5 * (x + fliplr(x));

%[ESP] Cálculo de la componente impar de la señal.
%[ENG] Calculating the odd component of the signal.
% Señal impar obtenida
x_impar = 0.5 * (x - fliplr(x));

%[ESP] Reconstrucción de la señal sumando las componentes.
%[ENG] Reconstructing the signal by adding the components.
% Señal reconstruida, a partir de sumar las partes par e impar.
x_new = x_par + x_impar;


%% Gráfico de las 4 señales: Original, par, impar y reconstruida

%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
% Abro una figura
figure;
% Creo un cuadro subdividido en 4 partes y grafico cada uno de estos
% Agrego para cada uno de ellos una etiqueta en eje y e x asi como título

%[ESP] Graficación de la señal original (x).
%[ENG] Plotting the original signal (x).
subplot(411); stem(n, x); title('Función Original'); ylabel('x'); xlabel('n [muestras]');

%[ESP] Graficación de la componente par (x_par).
%[ENG] Plotting the even component (x_par).
subplot(412); stem(n, x_par); title('Función Par'); ylabel('x\_par'); xlabel('n [muestras]');

%[ESP] Graficación de la componente impar (x_impar).
%[ENG] Plotting the odd component (x_impar).
subplot(413); stem(n, x_impar); title('Función Impar'); ylabel('x\_impar'); xlabel('n [muestras]');

%[ESP] Graficación de la señal reconstruida (x_new).
%[ENG] Plotting the reconstructed signal (x_new).
subplot(414); stem(n, x_new); title('Función Reconstruida'); ylabel('x\_new'); xlabel('n [muestras]');
