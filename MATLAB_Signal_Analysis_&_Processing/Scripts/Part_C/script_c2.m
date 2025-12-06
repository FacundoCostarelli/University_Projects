%% Script_c2

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

%% Desarrollo del programa para resolución de la EDO 1er orden

%[ESP] Definición del incremento (paso) de tiempo.
%[ENG] Defining the time increment (step).
dt = 0.01; % Creo diferencial de tiempo

%[ESP] Creación del vector de tiempo (intervalo) de simulación.
%[ENG] Creating the time vector (interval) for the simulation.
ti = 0; tf = 5; % Creo variables de tiempo inicial y final
tspan = ti : dt : tf; % Creo un vector temporal  

%[ESP] Definición de la primera señal de entrada (x1) como función anónima.
%[ENG] Defining the first input signal (x1) as an anonymous function.
x1 = @(t) esc(t) - esc(t-1); % Defino funcion anónima para señal x1 con t como parametro de entrada

%[ESP] Definición de la segunda señal de entrada (x2) como función anónima.
%[ENG] Defining the second input signal (x2) as an anonymous function.
x2 = @(t) 2 * esc(t) - 2 * esc(t-2); % Defino funcion anónima para señal x2 con t como parametro de entrada

%[ESP] Definición de los parámetros (constantes) del circuito RL.
%[ENG] Defining the RL circuit parameters (constants).
R = 5;  % Resistencia en ohmios
L = 0.1;  % Inductancia en henrios

%[ESP] Resolución del circuito para la entrada x1 usando la función.
%[ENG] Solving the circuit for the x1 input using the function.
[t1, vl1, il1] = f_resRL(R, L, tspan, x1); % Calculo de t1, vl1 e il1 a traves de la función f_resRL

%[ESP] Resolución del circuito para la entrada x2 usando la función.
%[ENG] Solving the circuit for the x2 input using the function.
[t2, vl2, il2] = f_resRL(R, L, tspan, x2); % Calculo de t2, vl2 e il2 a traves de la función f_resRL

%[ESP] Generación del vector de la primera tensión de entrada (vi1).
%[ENG] Generating the vector for the first input voltage (vi1).
vi1 = x1(t1); % Asocio la función anónima x1(t1) a una variable 

%[ESP] Generación del vector de la segunda tensión de entrada (vi2).
%[ENG] Generating the vector for the second input voltage (vi2).
vi2 = x2(t2); % Asocio la función anónima x2(t2) a una variable 

%[ESP] Creación de la primera ventana de figura (para x1).
%[ENG] Creating the first figure window (for x1).
figure;

%[ESP] Graficación de la tensión de entrada (vi1).
%[ENG] Plotting the input voltage (vi1).
subplot(311); plot(t1, vi1); grid; axis tight; title('v_{i(t)}'); xlabel('t'); % Gráfico de vi para x1(t)

%[ESP] Graficación de la corriente del inductor (il1).
%[ENG] Plotting the inductor current (il1).
subplot(312); plot(t1, il1); grid; axis tight; title('i_{L(t)}'); xlabel('t'); % Gráfico de il para x1(t)

%[ESP] Graficación de la tensión del inductor (vl1).
%[ENG] Plotting the inductor voltage (vl1).
subplot(313); plot(t1, vl1); grid; axis tight; title('v_{L(t)}'); xlabel('t'); % Gráfico de vl para x1(t)

%[ESP] Creación de la segunda ventana de figura (para x2).
%[ENG] Creating the second figure window (for x2).
figure;

%[ESP] Graficación de la tensión de entrada (vi2).
%[ENG] Plotting the input voltage (vi2).
subplot(311); plot(t2, vi2); grid; axis tight; title('v_{i(t)}'); xlabel('t'); % Gráfico de vi para x2(t)

%[ESP] Graficación de la corriente del inductor (il2).
%[ENG] Plotting the inductor current (il2).
subplot(312); plot(t2, il2); grid; axis tight; title('i_{L(t)}'); xlabel('t'); % Gráfico de il para x2(t)

%[ESP] Graficación de la tensión del inductor (vl2).
%[ENG] Plotting the inductor voltage (vl2).
subplot(313); plot(t2, vl2); grid; axis tight; title('v_{L(t)}'); xlabel('t'); % Gráfico de vl para x2(t)
