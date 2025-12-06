%% Script_c4

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

%% Desarrollo del programa para resolución de la EDO 2do orden

%[ESP] Definición del incremento (paso) de tiempo.
%[ENG] Defining the time increment (step).
dt = 0.01; % Creo diferencial de tiempo

%[ESP] Definición del tiempo inicial y final.
%[ENG] Defining the start and end time.
ti = -1; tf=15; % Creo variables de tiempo inicial y final

%[ESP] Creación del vector de tiempo de simulación.
%[ENG] Creating the simulation time vector.
t = ti: dt : tf; % Creo un vector temporal  

%[ESP] Definición de la señal de entrada 'x' (escalón) como función anónima.
%[ENG] Defining the input signal 'x' (step) as an anonymous function.
x = @(t) esc(t); % Defino funcion anónima para señal x con t como parametro de entrada 

% Caso 1: Amortiguamiento Crítico
%[ESP] Definición de parámetros para el Caso 1 (Crítico).
%[ENG] Defining parameters for Case 1 (Critical).
R = 4;  L = 2;  C = 0.5; % Defino las constantes del circuito RLC serie 
% 

%[ESP] Resolución del circuito para el Caso 1 usando la función.
%[ENG] Solving the circuit for Case 1 using the function.
[t_caso1, vc_caso1] = f_resRLC(R, L, C, t, x); % Calculo de t y vc a traves de la función f_resRLC

%[ESP] Cálculo de límites (min/max) para el gráfico del Caso 1.
%[ENG] Calculating limits (min/max) for the Case 1 plot.
max_vc_caso1 = max(vc_caso1); % Creo variables que almacenan los máximos y mínimos. Así puedo modificar genericamente los limites del eje horizontal para graficar mejor
min_vc_caso1 = min(vc_caso1);

%[ESP] Creación de una nueva figura para el Caso 1.
%[ENG] Creating a new figure for Case 1.
figure;
%[ESP] Graficación de la entrada (x) y la salida (vc) del Caso 1.
%[ENG] Plotting the input (x) and output (vc) for Case 1.
plot(t, x(t), t_caso1, vc_caso1); grid on; axis([t(1) t(end) min_vc_caso1-1 max_vc_caso1+1]); % Gráfico Caso 1 de la señal vc(t) e x(t)
%[ESP] Asignación de título, etiquetas y leyenda.
%[ENG] Assigning title, labels, and legend.
title('Tensión de capacitor y señal de entrada'); 
xlabel('t[seg]'); legend('x_{(t)}', 'v_c');


% Caso 2: Sobreamortiguado
%[ESP] Definición de parámetros para el Caso 2 (Sobreamortiguado).
%[ENG] Defining parameters for Case 2 (Overdamped).
R = 6;  L = 2;  C = 0.5; % Defino las constantes del circuito RLC serie 
% 

%[ESP] Resolución del circuito para el Caso 2 usando la función.
%[ENG] Solving the circuit for Case 2 using the function.
[t_caso2, vc_caso2] = f_resRLC(R, L, C, t, x); % Calculo de t y vc a traves de la función f_resRLC

%[ESP] Cálculo de límites (min/max) para el gráfico del Caso 2.
%[ENG] Calculating limits (min/max) for the Case 2 plot.
max_vc_caso2 = max(vc_caso2); % Creo variables que almacenan los máximos y mínimos. Así puedo modificar genericamente los limites del eje horizontal para graficar mejor
min_vc_caso2 = min(vc_caso2);

%[ESP] Creación de una nueva figura para el Caso 2.
%[ENG] Creating a new figure for Case 2.
figure;
%[ESP] Graficación de la entrada (x) y la salida (vc) del Caso 2.
%[ENG] Plotting the input (x) and output (vc) for Case 2.
plot(t, x(t), t_caso2, vc_caso2); grid on; axis([t(1) t(end) min_vc_caso2-1 max_vc_caso2+1]); % Gráfico Caso 2 de la señal vc(t) e x(t)
%[ESP] Asignación de título, etiquetas y leyenda.
%[ENG] Assigning title, labels, and legend.
title('Tensión de capacitor y señal de entrada'); 
xlabel('t[seg]'); legend('x_{(t)}', 'v_c');

% Caso 3: Subamortiguado
%[ESP] Definición de parámetros para el Caso 3 (Subamortiguado).
%[ENG] Defining parameters for Case 3 (Underdamped).
R = 2;  L = 2;  C = 0.5; % Defino las constantes del circuito RLC serie  
% 

%[ESP] Resolución del circuito para el Caso 3 usando la función.
%[ENG] Solving the circuit for Case 3 using the function.
[t_caso3, vc_caso3] = f_resRLC(R, L, C, t, x); % Calculo de t y vc a traves de la función f_resRLC

%[ESP] Cálculo de límites (min/max) para el gráfico del Caso 3.
%[ENG] Calculating limits (min/max) for the Case 3 plot.
max_vc_caso3 = max(vc_caso3); % Creo variables que almacenan los máximos y mínimos. Así puedo modificar genericamente los limites del eje horizontal para graficar mejor
min_vc_caso3 = min(vc_caso3);

%[ESP] Creación de una nueva figura para el Caso 3.
%[ENG] Creating a new figure for Case 3.
figure;
%[ESP] Graficación de la entrada (x) y la salida (vc) del Caso 3.
%[ENG] Plotting the input (x) and output (vc) for Case 3.
plot(t, x(t), t_caso3, vc_caso3); grid on; axis([t(1) t(end) min_vc_caso3-1 max_vc_caso3+1]); % Gráfico Caso 3 de la señal vc(t) e x(t)  
%[ESP] Asignación de título, etiquetas y leyenda.
%[ENG] Assigning title, labels, and legend.
title('Tensión de capacitor y señal de entrada'); 
xlabel('t[seg]'); legend('x_{(t)}', 'v_c');

