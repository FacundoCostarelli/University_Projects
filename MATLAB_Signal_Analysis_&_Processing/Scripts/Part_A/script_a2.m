%% Script_a2

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
% Realice un script que obtenga los resultados de 
% las operaciones matriciales dadas por enunciado

%[ESP] Definición de las matrices A, B y el vector C.
%[ENG] Defining matrices A, B, and vector C.
% Creación de las matrices A y B
A = [1 2 5 ; 5 6 8 ; 8 6 3]
B = [5 2 0 ; 7 5 3 ; 9 5 1]
C = [1 3 9]

% Creación de matrizes a partir de las Operaciones matriciales de enunciado
%[ESP] Cálculo de la multiplicación de matrices.
%[ENG] Calculating the matrix multiplication.
M1 = A * B

%[ESP] Cálculo de la división de determinantes.
%[ENG] Calculating the division of determinants.
M2 = det(A) / det(B)

%[ESP] Cálculo de la multiplicación de matriz por vector transpuesto.
%[ENG] Calculating matrix multiplication by a transposed vector.
M3 = B * C'

%[ESP] Cálculo de la suma de matrices.
%[ENG] Calculating the matrix sum.
M4 = A + B

%[ESP] Cálculo de una operación matricial combinada.
%[ENG] Calculating a combined matrix operation.
M5 = B * C' + C'

%[ESP] Cálculo de la matriz inversa (álgebra lineal).
%[ENG] Calculating the inverse matrix (linear algebra).
M6 = A ^ -1

%[ESP] Cálculo del inverso elemento a elemento.
%[ENG] Calculating the element-wise inverse.
M7 = A .^ -1

%[ESP] Cálculo de una operación elemento a elemento.
%[ENG] Calculating an element-wise operation.
M8 = A.*(ones(3,3) - eye(3,3))

%[ESP] Creación de una nueva matriz mediante concatenación.
%[ENG] Creating a new matrix by concatenation.
M9 = [B(:, 1:2) C']

%[ESP] Cálculo de una matriz lógica (comparación).
%[ENG] Calculating a logical matrix (comparison).
M10 = A > 4
