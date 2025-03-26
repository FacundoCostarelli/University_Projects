%% Script_c1
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Modelizaci�n de Circuito RL en serie

% El circuito es en serie -> vIn = vR + vL donde i = iR = iL
% A partir de re-escribir la ecuaci�n de vIn en funci�n de iL(salida)
% considerando lo mencionado -> vIn = iR * R + L * iL'
% Vemos que a = L, b = R
% Despejando iL' obtengo que: iL' = vIn * 1/L - iR * R/L
% Nos queda un sistema de una �nic ecuaci�n.
% Este sistema se resuelve genericamente como: 
% [iL'] = [-b/a] * [iL] + [1/a] * vIn
% Con esta idea principal, se basa la resoluci�n del enunciado

%% Desarrollo del programa para resoluci�n de la EDO 1er orden

% Defino un vector temporal
dt = 0.001;
ti = -2; tf = 5;
t = ti: dt : tf;

% Defino condiciones iniciales para la EDO de 1er orden
condiciones_iniciales = 0; 

% Defino un identificador de funci�n an�nima el cual ser� "vi"
% Luego uso la funci�n an�nima como vi(t) donde t es el parametro de entrada
vi = @(t) (esc(t) - esc(t - 1)); % Tambi�n vi = i * z

% Defino las constantes del circuito
R = 1;  % Resistencia en ohmios
L = 1;  % Inductancia en henrios

% Defino un identificador de funci�n an�nima el cual ser� iL_prima
% Luego uso la funci�n an�nima como iL_prima(t,iL). Esta refiere a la EDO
iL_prima = @(t,iL) (1/L) * (vi(t) - iL * R);

% Resuelvo EDO de 1der orden de t=ti a t=tf con condiciones iniciales nulas
% Para esto invoco ode23
[t,iL] = ode23(iL_prima, t, condiciones_iniciales);

% Calculo la vL, es decir, la salida. Defino un identificador de funci�n
% an�nima el cual ser� vL
% Para obtener la derivada de iL utilizo:
% Df = gradient(iL,t) ya que devuelve el gradiente num�rico unidimensional 
% del vector iL en este caso. Basicamente calcula la derivada de un vector 
% o matrix. 
vL = @(t) L * gradient(iL,t);

%% Gr�ficos de las se�ales: vi, iL, vL

% Creo variables que almacenan los m�ximos y m�nimos. Esto para la tensi�n de
% entrada, la corriente del inductor y la tensi�n del inductor. As� puedo modificar genericamente los
% limites superiores e inferiores del eje horizontal en axis para graficar
% mejor

max_vi = max(vi(t));
min_vi = min(vi(t));

max_iL = max(iL);
min_iL = min(iL);

max_vL = max(vL(t));
min_vL = min(vL(t));

figure; 
subplot(311); plot(t, vi(t)); grid on; axis([t(1) t(end) min_vi-1 max_vi+1]); 
title('Tensi�n de entrada'); ylabel('vi(t)'); xlabel('t[seg]');

subplot(312); plot(t, iL); grid on; axis([t(1) t(end) min_iL-1 max_iL+1]); 
title('Corriente del inductor'); ylabel('iL(t)'); xlabel('t[seg]'); 

subplot(313); plot(t, vL(t)); grid on; axis([t(1) t(end) min_vL-1 max_vL+1]); 
title('Tensi�n del inductor'); ylabel('vL(t)'); xlabel('t[seg]'); 

