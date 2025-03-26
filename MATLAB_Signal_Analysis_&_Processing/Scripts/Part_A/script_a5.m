%% Script_a5
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura
%% 
% Calcular el número "e" (aproximadamente 2,7182818284590455), en forma
% aproximada, medante su descomposición en serie. Para ello, tome en cuenta
% los primeros 5 elementos (los más significativos) de la serie. Evite
% utilzar un "for" o un "while" explícito; utilice operaciones con vectores
% mediante funciones provistas por MATLAB en cambio. No utilice variables
% simbólicas. Ejemplo: el resultado para 5 elementos debería ser
% 2,708333333333333

% La serie de Euler tiene una fórmula dada como: e = Sumatoria(1/n!) desde 
% n = 0 hasta n->infinito. Esta serie proviene de la exponencial la cual es
%  e^x = Sumatoria(x^n/n!) desde n = 0 hasta n->infinito

% Creo una variable que almacena el número de elementos de la serie
n_elementos = 5
% Creo un vector fila que almacena los factores a factorizar de cada
% elemento de la seire, esto es n!, (n-1)!, (n-2)! ..., asi hasta llegar al
% valor de 0!. 
factores = n_elementos - 1 : -1 : 0
% Creo un vector fila que contiene los factoriales de cada factor
factoriales = factorial(factores)
% Creo un vector fila que contiene los factoriales invertidos 
A = 1./factoriales
% Creo una variable que almacena la suma de los elementos de la serie
% ubicados en A
numero_euler_aprox = sum(A)
