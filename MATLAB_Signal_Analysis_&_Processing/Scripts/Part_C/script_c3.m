%% Script_c3

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

%% Modelización de Circuito RLC en serie

% Nota sobre la obtención de la EDO 2do orden. 
% El circuito es en serio -> vIn = vR + vL + vC donde i = iR = iL = iC
% A partir de re-escribir la ecuación de vIn en función de vC(salida)
% considerando lo mencionado -> vIn = vC + C*R * vC' + L*C * vC''
% Vemos que a = L*C, b = C*R, c = 1
% Despejando vC'' y planteando las igualdes siguientes: vC'' = Z', vC' = Z
% donde Z es una variable intermedia, nos queda el sistema: 
% (1) Z' = vIn * 1/(L*C) - vC * 1/(L*C) - Z * R/L
% (2) Z = vC'
% Este sistema se resuelve genéricamente como:
% [vC' ; Z'] = [0 1 ; -1/a -b/a] * [vC ; Z] + [0 ; 1/a] * vIn
% Con esta idea principal, se basa la resolución del enunciado

%% Desarrollo del programa para resolución de la EDO 2do orden

%[ESP] Definición del paso de tiempo y el intervalo temporal.
%[ENG] Defining the time step and the time interval.
% Defino un vector temporal
dt = 0.01;
ti = -1; tf=15;
t = ti: dt : tf;

%[ESP] Establecimiento de las condiciones iniciales (nulas) para la EDO.
%[ENG] Setting the initial conditions (zero) for the ODE.
% Defino condiciones iniciales para la EDO de 2do orden 
condiciones_iniciales = [0; 0]; 

%[ESP] Definición de la tensión de entrada 'vi' como función anónima.
%[ENG] Defining the input voltage 'vi' as an anonymous function.
% Defino un identificador de función anónima el cual será "vi" para señal de
% entrada. Luego uso la función anónima como vi(t) donde t es el parametro 
% de entrada
vi = @(t) esc(t); 

%[ESP] Declaración de variables globales para los parámetros del circuito.
%[ENG] Declaring global variables for the circuit parameters.
% Defino las constantes del circuito RLC serie.
global C R L;

% Planteo un caso cualquiera para probar el código.
% Caso 1: Amortiguamiento Crítico
% R = 4;  L = 2;  C = 0.5;  
% Caso 2: Sobreamortiguado
% R = 6;  L = 2;  C = 0.5;   
% Caso 3: Subamortiguado
%[ESP] Asignación de valores a los parámetros del circuito (caso subamortiguado).
%[ENG] Assigning values to the circuit parameters (underdamped case).
R = 2;  L = 2;  C = 0.5;
 
%[ESP] Definición de las matrices de estado (A y B) para la EDO.
%[ENG] Defining the state-space matrices (A and B) for the ODE.
% Planteo una ecuación diferencial en formato matricial para poder así
% obtener una variable que se asocia con la derivada primera, para así 
% pasar dicha variable a ode23 
A=[0 1 ; -1/(L*C) -R/L];
B=[0 1/(L*C)]';

%[ESP] Definición de la Ecuación Diferencial (EDO) como función anónima.
%[ENG] Defining the Differential Equation (ODE) as an anonymous function.
vc_prima = @(t,vc) A * vc + B * vi(t); 

%[ESP] Resolución de la EDO usando el solver numérico (ode23).
%[ENG] Solving the ODE using the numerical solver (ode23).
% Resuelvo EDO de 2do orden de t=ti a t=tf con condiciones iniciales nulas
% Para esto invoco ode23
[tsalida,vc]=ode23(vc_prima,t,condiciones_iniciales);

%% Gráfico de la señal vC de salida

% Creo variables que almacenan los máximos y mínimos. Esto para la tensión
% de capacitor. Así se modifica automaticamente los limites superiores 
% e inferiores del eje horizontal en axis un mejor gráfico

%[ESP] Cálculo de los límites (min/max) para el gráfico de 'vc'.
%[ENG] Calculating the limits (min/max) for the 'vc' plot.
max_vc = max(vc(:,1));
min_vc = min(vc(:,1));

% Abro una figura y ploteo agregando las etiquetas y ajustes de ejes
% necesarios
%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
figure;

%[ESP] Graficación de la tensión del capacitor (salida).
%[ENG] Plotting the capacitor voltage (output).
plot(tsalida, vc(:,1));

%[ESP] Activación de la cuadrícula en el gráfico.
%[ENG] Activating the grid on the plot.
grid on;

%[ESP] Ajuste de los límites de los ejes.
%[ENG] Adjusting the axis limits.
axis([tsalida(1) tsalida(end) min_vc - 1 max_vc + 1]);

%[ESP] Asignación de etiquetas y título al gráfico.
%[ENG] Assigning labels and title to the plot.
title('Tensión de capacitor');
ylabel('vc(t)');
xlabel('tsalida[seg]');
