%% Script_b3

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

%% Ejemplo de aplicación de la función f_get_even_odd(n,x):
%[ESP] Creación del vector de índices simétrico.
%[ENG] Creating the symmetric index vector.
n = -10 : 10;

%[ESP] Creación de la señal original a descomponer.
%[ENG] Creating the original signal to decompose.
x = n + 1; %Donde n es la parte impar, y 1 es la par

%[ESP] Llamada a la función para obtener las componentes par e impar.
%[ENG] Calling the function to get the even and odd components.
[x_par, x_impar] = f_get_even_odd(n,x);

%[ESP] Reconstrucción de la señal sumando las componentes.
%[ENG] Reconstructing the signal by adding the components.
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