%% Script_a5

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

%[ESP] Definición del número de elementos para la aproximación.
%[ENG] Defining the number of elements for the approximation.
% Creo una variable que almacena el número de elementos de la serie
n_elementos = 5

%[ESP] Creación del vector de índices para el factorial (de N-1 a 0).
%[ENG] Creating the index vector for the factorial (from N-1 down to 0).
% Creo un vector fila que almacena los factores a factorizar de cada
% elemento de la seire, esto es n!, (n-1)!, (n-2)! ..., asi hasta llegar al
% valor de 0!. 
factores = n_elementos - 1 : -1 : 0

%[ESP] Cálculo de los factoriales de los índices (n!).
%[ENG] Calculating the factorials of the indices (n!).
% Creo un vector fila que contiene los factoriales de cada factor
factoriales = factorial(factores)

%[ESP] Cálculo de los términos de la serie (1/n!).
%[ENG] Calculating the terms of the series (1/n!).
% Creo un vector fila que contiene los factoriales invertidos 
A = 1./factoriales

%[ESP] Suma de los términos para obtener la aproximación de 'e'.
%[ENG] Summing the terms to get the approximation of 'e'.
% Creo una variable que almacena la suma de los elementos de la serie
% ubicados en A
numero_euler_aprox = sum(A)