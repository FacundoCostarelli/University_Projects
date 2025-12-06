%% Script_a1

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

%% Ejercicio
% Realice un script que obtenga módulo y fase, parte real e imaginaria
% y el conjugado de los siguientes números complejos:

%[ESP] Definición de los números complejos iniciales y sus operaciones.
%[ENG] Definition of the initial complex numbers and their operations.
% Creo variables de números complejos con las operatorias de enunciado
z_1 = -1 + 2i;
z_2 = 2 * exp(-i*pi/4);
z_3 = z_1 + z_2;
z_4 = z_1 - z_2;
z_5 = z_1 * z_2;
z_6 = z_1 / z_2;
z_7 = z_1 ^ 3;

%[ESP] Creación de un vector columna con todos los números complejos.
%[ENG] Creating a column vector with all the complex numbers.
% Creo un vector "z" de números complejos y le calculo la traspuesta para
% mejor visualización
z = [z_1 z_2 z_3 z_4 z_5 z_6 z_7]'

%[ESP] Cálculo de las propiedades de los números complejos.
%[ENG] Calculating the properties of the complex numbers.
% Creo vectores que contienen los resultados de módulo, fase, parte real
% parte imaginaria y conjugado. Esto por cada número complejo del vector "z"

% Utilizo todas funciones incorporadas en MatLab
%[ESP] Cálculo de los módulos.
%[ENG] Calculating the magnitudes (modulus).
modulo = abs(z)

%[ESP] Cálculo de las fases (ángulos).
%[ENG] Calculating the phases (angles).
fase = angle(z)

%[ESP] Extracción de las partes reales.
%[ENG] Extracting the real parts.
parte_real = real(z)

%[ESP] Extracción de las partes imaginarias.
%[ENG] Extracting the imaginary parts.
parte_imaginaria = imag(z)

%[ESP] Cálculo de los conjugados.
%[ENG] Calculating the conjugates.
conjugado = conj(z)

%[ESP] Creación de una nueva figura para graficar.
%[ENG] Creating a new figure for plotting.
% Grafico de los números complejos ubicados en el vector "z"
figure

%[ESP] Graficación de los números complejos en el plano Z.
%[ENG] Plotting the complex numbers on the Z-plane.
zplane(z); 
grid on;
hold on;

%[ESP] Superposición de un gráfico de brújula (vectores desde el origen).
%[ENG] Overlaying a compass plot (vectors from the origin).
compass(z);
hold off;