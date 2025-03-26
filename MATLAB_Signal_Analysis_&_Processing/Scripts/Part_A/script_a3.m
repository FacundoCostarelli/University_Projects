%% Script_a3
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura
%%
% Realice un script que obtenga los n resultados de una radicación
% para un número z perteneciente a los complejos. Utilice la función
% nativa roots() y entregue los resultados en forma de vector columna.
% Luego grafíquelos en un único plano complejo

% Creo variables que contienen el grado del polinomio y el numero de
% coeficientes de ese polinomio
grado_polinomio = 2
numero_coefs = grado_polinomio + 1
% Creo un vector que contiene los n+1 coeficientes de un polinomio "p" de
% grado n
% Utilizo la función randn que devuelve arreglos de números
% de punto flotante reales que se extraen de una distribución normal 
% estándar.
p = randn(1,numero_coefs)

% Creación de un vector de "raices" y uso de la función nativa roots()
raices = roots(p)

% Grafico de las raices
% Grafico de los números complejos ubicados en el vector "raices"
figure
zplane(raices); 
grid on;
hold on;
compass(raices);
hold off;
