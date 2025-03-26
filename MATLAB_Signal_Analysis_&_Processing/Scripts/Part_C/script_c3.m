%% Script_c3
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura

%% Modelizaci�n de Circuito RLC en serie

% Nota sobre la obtenci�n de la EDO 2do orden. 
% El circuito es en serio -> vIn = vR + vL + vC donde i = iR = iL = iC
% A partir de re-escribir la ecuaci�n de vIn en funci�n de vC(salida)
% considerando lo mencionado -> vIn = vC + C*R * vC' + L*C * vC''
% Vemos que a = L*C, b = C*R, c = 1
% Despejando vC'' y planteando las igualdes siguientes: vC'' = Z', vC' = Z
% donde Z es una variable intermedia, nos queda el sistema: 
% (1) Z' = vIn * 1/(L*C) - vC * 1/(L*C) - Z * R/L
% (2) Z = vC'
% Este sistema se resuelve gen�ricamente como:
% [vC' ; Z'] = [0 1 ; -1/a -b/a] * [vC ; Z] + [0 ; 1/a] * vIn
% Con esta idea principal, se basa la resoluci�n del enunciado

%% Desarrollo del programa para resoluci�n de la EDO 2do orden

% Defino un vector temporal
dt = 0.01;
ti = -1; tf=15;
t = ti: dt : tf;

% Defino condiciones iniciales para la EDO de 2do orden 
condiciones_iniciales = [0; 0]; 

% Defino un identificador de funci�n an�nima el cual ser� "vi" para se�al de
% entrada. Luego uso la funci�n an�nima como vi(t) donde t es el parametro 
% de entrada
vi = @(t) esc(t); 

% Defino las constantes del circuito RLC serie.
global C R L;

% Planteo un caso cualquiera para probar el c�digo.
% Caso 1: Amortiguamiento Cr�tico
% R = 4;  L = 2;  C = 0.5;  
% Caso 2: Sobreamortiguado
% R = 6;  L = 2;  C = 0.5;   
% Caso 3: Subamortiguado
R = 2;  L = 2;  C = 0.5;
 
% Planteo una ecuaci�n diferencial en formato matricial para poder as�
% obtener una variable que se asocia con la derivada primera, para as� 
% pasar dicha variable a ode23 
A=[0 1 ; -1/(L*C) -R/L];
B=[0 1/(L*C)]';
vc_prima = @(t,vc) A * vc + B * vi(t); 

% Resuelvo EDO de 2do orden de t=ti a t=tf con condiciones iniciales nulas
% Para esto invoco ode23
[tsalida,vc]=ode23(vc_prima,t,condiciones_iniciales);

%% Gr�fico de la se�al vC de salida

% Creo variables que almacenan los m�ximos y m�nimos. Esto para la tensi�n
% de capacitor. As� se modifica automaticamente los limites superiores 
% e inferiores del eje horizontal en axis un mejor gr�fico

max_vc = max(vc(:,1));
min_vc = min(vc(:,1));

% Abro una figura y ploteo agregando las etiquetas y ajustes de ejes
% necesarios
figure;
plot(tsalida, vc(:,1));
grid on;
axis([tsalida(1) tsalida(end) min_vc - 1 max_vc + 1]);
title('Tensi�n de capacitor');
ylabel('vc(t)');
xlabel('tsalida[seg]');
