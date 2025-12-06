%% Script_c1

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

%% Modelización de Circuito RL en serie

% El circuito es en serie -> vIn = vR + vL donde i = iR = iL
% A partir de re-escribir la ecuación de vIn en función de iL(salida)
% considerando lo mencionado -> vIn = iR * R + L * iL'
% Vemos que a = L, b = R
% Despejando iL' obtengo que: iL' = vIn * 1/L - iR * R/L
% Nos queda un sistema de una únic ecuación.
% Este sistema se resuelve genericamente como: 
% [iL'] = [-b/a] * [iL] + [1/a] * vIn
% Con esta idea principal, se basa la resolución del enunciado


%% Desarrollo del programa para resolución de la EDO 1er orden

%[ESP] Definición del paso de tiempo (dt) y el intervalo temporal.
%[ENG] Defining the time step (dt) and the time interval.
% Defino un vector temporal
dt = 0.001;
ti = -2; tf = 5;
t = ti: dt : tf;

%[ESP] Establecimiento de las condiciones iniciales (nulas) para la EDO.
%[ENG] Setting the initial conditions (zero) for the ODE.
% Defino condiciones iniciales para la EDO de 1er orden
condiciones_iniciales = 0; 

%[ESP] Definición de la tensión de entrada 'vi' como función anónima.
%[ENG] Defining the input voltage 'vi' as an anonymous function.
% Defino un identificador de función anónima el cual será "vi"
% Luego uso la función anónima como vi(t) donde t es el parametro de entrada
vi = @(t) (esc(t) - esc(t - 1)); % También vi = i * z

%[ESP] Definición de las constantes (parámetros) del circuito.
%[ENG] Defining the circuit constants (parameters).
% Defino las constantes del circuito
R = 1;  % Resistencia en ohmios
L = 1;  % Inductancia en henrios

%[ESP] Definición de la Ecuación Diferencial Ordinaria (EDO) como función anónima.
%[ENG] Defining the Ordinary Differential Equation (ODE) as an anonymous function.
% Defino un identificador de función anónima el cual será iL_prima
% Luego uso la función anónima como iL_prima(t,iL). Esta refiere a la EDO
iL_prima = @(t,iL) (1/L) * (vi(t) - iL * R);

%[ESP] Resolución de la EDO usando el solver numérico (ode23).
%[ENG] Solving the ODE using the numerical solver (ode23).
% Resuelvo EDO de 1der orden de t=ti a t=tf con condiciones iniciales nulas
% Para esto invoco ode23
[t,iL] = ode23(iL_prima, t, condiciones_iniciales);

%[ESP] Cálculo de la tensión en el inductor 'vL' (la salida).
%[ENG] Calculating the inductor voltage 'vL' (the output).
% Calculo la vL, es decir, la salida. Defino un identificador de función
% anónima el cual será vL
% Para obtener la derivada de iL utilizo:
% Df = gradient(iL,t) ya que devuelve el gradiente numérico unidimensional 
% del vector iL en este caso. Basicamente calcula la derivada de un vector 
% o matrix. 
vL = @(t) L * gradient(iL,t);

%% Gráficos de las señales: vi, iL, vL

% Creo variables que almacenan los máximos y mínimos. Esto para la tensión de
% entrada, la corriente del inductor y la tensión del inductor. Así puedo modificar genericamente los
% limites superiores e inferiores del eje horizontal en axis para graficar
% mejor

%[ESP] Cálculo de límites (min/max) para el gráfico de 'vi'.
%[ENG] Calculating limits (min/max) for the 'vi' plot.
max_vi = max(vi(t));
min_vi = min(vi(t));

%[ESP] Cálculo de límites (min/max) para el gráfico de 'iL'.
%[ENG] Calculating limits (min/max) for the 'iL' plot.
max_iL = max(iL);
min_iL = min(iL);

%[ESP] Cálculo de límites (min/max) para el gráfico de 'vL'.
%[ENG] Calculating limits (min/max) for the 'vL' plot.
max_vL = max(vL(t));
min_vL = min(vL(t));

%[ESP] Creación de una nueva ventana de figura.
%[ENG] Creating a new figure window.
figure; 

%[ESP] Graficación de la tensión de entrada 'vi'.
%[ENG] Plotting the input voltage 'vi'.
subplot(311); plot(t, vi(t)); grid on; axis([t(1) t(end) min_vi-1 max_vi+1]); 
title('Tensión de entrada'); ylabel('vi(t)'); xlabel('t[seg]');

%[ESP] Graficación de la corriente en el inductor 'iL'.
%[ENG] Plotting the inductor current 'iL'.
subplot(312); plot(t, iL); grid on; axis([t(1) t(end) min_iL-1 max_iL+1]); 
title('Corriente del inductor'); ylabel('iL(t)'); xlabel('t[seg]'); 

%[ESP] Graficación de la tensión en el inductor 'vL'.
%[ENG] Plotting the inductor voltage 'vL'.
subplot(313); plot(t, vL(t)); grid on; axis([t(1) t(end) min_vL-1 max_vL+1]); 
title('Tensión del inductor'); ylabel('vL(t)'); xlabel('t[seg]');

