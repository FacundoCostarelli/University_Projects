function [t, vc] = f_resRLC(R, L, C, tspan, x)
%f_resRLC() resuelve un circuito RLC serie, con salida en el capacitor.
% Variables de entrada:
% R % Valor de la resistencia
% L % Valor del inductor
% C % Valor del capacitor
% tspan %Vector temporal
% x % Funcion desde la cual se obtiene la tension de entrada
%
% Variables de salida:
% t % Vector temporal correspondiente a vc
% vc % Tension del capacitor
%
% Ejemplo:
% R=1; L=1; C=1;
% tspan = -1 : .01 : 25;
% x = @(t) esc(t);
% [t, vc] = f_resRLC_bis(R, L, C, tspan, x);
% plot(t, x(t), t, vc); xlabel('t'); legend('x_{(t)}', 'v_c');

    condiciones_iniciales = [0; 0]; % Defino condiciones iniciales nulas para las EDO por enunciado 
    A=[0 1 ; -1/(L*C) -R/L]; % Obtengo la matriz A para EDO diferencial matricial
    B=[0 1/(L*C)]'; % Obtengo la matriz B para EDO diferencial matricial
    vc_prima = @(t,vc) A * vc + B * x(t); % Defino funcion anónima para señal vc_prima con t y vc como parametros de entrada
    [t,vc]=ode23(vc_prima,tspan,condiciones_iniciales); % Resuelvo la EDO de 2do orden y calculo la t y vc de salida a traves de ode23
    vc = vc(:,1);
end
