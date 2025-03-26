%% Script_a2
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura
%%
% Realice un script que obtenga los resultados de 
% las operaciones matriciales dadas por enunciado

% Creación de las matrices A y B
A = [1 2 5 ; 5 6 8 ; 8 6 3]
B = [5 2 0 ; 7 5 3 ; 9 5 1]
C = [1 3 9]

% Creación de matrizes a partir de las Operaciones matriciales de enunciado
M1 = A * B
M2 = det(A) / det(B)
M3 = B * C'
M4 = A + B
M5 = B * C' + C'
M6 = A ^ -1
M7 = A .^ -1
M8 = A.*(ones(3,3) - eye(3,3))
M9 = [B(:, 1:2) C']
M10 = A > 4
