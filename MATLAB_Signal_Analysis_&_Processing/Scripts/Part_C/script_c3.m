%% Script_c3
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
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

% Defino un vector temporal
dt = 0.01;
ti = -1; tf=15;
t = ti: dt : tf;

% Defino condiciones iniciales para la EDO de 2do orden 
condiciones_iniciales = [0; 0]; 

% Defino un identificador de función anónima el cual será "vi" para señal de
% entrada. Luego uso la función anónima como vi(t) donde t es el parametro 
% de entrada
vi = @(t) esc(t); 

% Defino las constantes del circuito RLC serie.
global C R L;

% Planteo un caso cualquiera para probar el código.
% Caso 1: Amortiguamiento Crítico
% R = 4;  L = 2;  C = 0.5;  
% Caso 2: Sobreamortiguado
% R = 6;  L = 2;  C = 0.5;   
% Caso 3: Subamortiguado
R = 2;  L = 2;  C = 0.5;
 
% Planteo una ecuación diferencial en formato matricial para poder así
% obtener una variable que se asocia con la derivada primera, para así 
% pasar dicha variable a ode23 
A=[0 1 ; -1/(L*C) -R/L];
B=[0 1/(L*C)]';
vc_prima = @(t,vc) A * vc + B * vi(t); 

% Resuelvo EDO de 2do orden de t=ti a t=tf con condiciones iniciales nulas
% Para esto invoco ode23
[tsalida,vc]=ode23(vc_prima,t,condiciones_iniciales);

%% Gráfico de la señal vC de salida

% Creo variables que almacenan los máximos y mínimos. Esto para la tensión
% de capacitor. Así se modifica automaticamente los limites superiores 
% e inferiores del eje horizontal en axis un mejor gráfico

max_vc = max(vc(:,1));
min_vc = min(vc(:,1));

% Abro una figura y ploteo agregando las etiquetas y ajustes de ejes
% necesarios
figure;
plot(tsalida, vc(:,1));
grid on;
axis([tsalida(1) tsalida(end) min_vc - 1 max_vc + 1]);
title('Tensión de capacitor');
ylabel('vc(t)');
xlabel('tsalida[seg]');
