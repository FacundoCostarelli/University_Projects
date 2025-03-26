%% Script_c2
clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura 

%% Desarrollo del programa para resolución de la EDO 1er orden

dt = 0.01; % Creo diferencial de tiempo
ti = 0; tf = 5; % Creo variables de tiempo inicial y final
tspan = ti : dt : tf; % Creo un vector temporal  

x1 = @(t) esc(t) - esc(t-1); % Defino funcion anónima para señal x1 con t como parametro de entrada
x2 = @(t) 2 * esc(t) - 2 * esc(t-2); % Defino funcion anónima para señal x2 con t como parametro de entrada

R = 5;  % Resistencia en ohmios
L = 0.1;  % Inductancia en henrios

[t1, vl1, il1] = f_resRL(R, L, tspan, x1); % Calculo de t1, vl1 e il1 a traves de la función f_resRL
[t2, vl2, il2] = f_resRL(R, L, tspan, x2); % Calculo de t2, vl2 e il2 a traves de la función f_resRL

vi1 = x1(t1); % Asocio la función anónima x1(t1) a una variable 
vi2 = x2(t2); % Asocio la función anónima x2(t2) a una variable 

figure;
subplot(311); plot(t1, vi1); grid; axis tight; title('v_{i(t)}'); xlabel('t'); % Gráfico de vi para x1(t)
subplot(312); plot(t1, il1); grid; axis tight; title('i_{L(t)}'); xlabel('t'); % Gráfico de il para x1(t)
subplot(313); plot(t1, vl1); grid; axis tight; title('v_{L(t)}'); xlabel('t'); % Gráfico de vl para x1(t)

figure;
subplot(311); plot(t2, vi2); grid; axis tight; title('v_{i(t)}'); xlabel('t'); % Gráfico de vi para x2(t)
subplot(312); plot(t2, il2); grid; axis tight; title('i_{L(t)}'); xlabel('t'); % Gráfico de il para x2(t)
subplot(313); plot(t2, vl2); grid; axis tight; title('v_{L(t)}'); xlabel('t'); % Gráfico de vl para x2(t)

