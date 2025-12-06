%% Script_a3

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
% Realice un script que obtenga los n resultados de una radicación
% para un número z perteneciente a los complejos. Utilice la función
% nativa roots() y entregue los resultados en forma de vector columna.
% Luego grafíquelos en un único plano complejo

%[ESP] Definición del grado del polinomio.
%[ENG] Defining the degree of the polynomial.
% Creo variables que contienen el grado del polinomio y el numero de
% coeficientes de ese polinomio
grado_polinomio = 2

%[ESP] Cálculo del número de coeficientes necesarios.
%[ENG] Calculating the necessary number of coefficients.
numero_coefs = grado_polinomio + 1

%[ESP] Creación de un vector de coeficientes aleatorios para el polinomio.
%[ENG] Creating a random coefficient vector for the polynomial.
% Creo un vector que contiene los n+1 coeficientes de un polinomio "p" de
% grado n
% Utilizo la función randn que devuelve arreglos de números
% de punto flotante reales que se extraen de una distribución normal 
% estándar.
p = randn(1,numero_coefs)

%[ESP] Cálculo de las raíces del polinomio 'p'.
%[ENG] Calculating the roots of the polynomial 'p'.
% Creación de un vector de "raices" y uso de la función nativa roots()
raices = roots(p)

% Grafico de las raices
%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
% Grafico de los números complejos ubicados en el vector "raices"
figure

%[ESP] Graficación de las raíces en el plano complejo (plano Z).
%[ENG] Plotting the roots on the complex plane (Z-plane).
zplane(raices); 
grid on;
hold on;

%[ESP] Superposición de un gráfico de brújula (vectores).
%[ENG] Overlaying a compass (vector) plot.
compass(raices);
hold off;