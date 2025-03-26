function [t, vl, il]= f_resRL(R, L, tspan, x)
%f_resRL() resuelve un circuito RL serie, con salida en el inductor.
% Variables de entrada:
% R % Valor de la resistencia
% L % Valor del inductor
% tspan % Vector temporal
% x % Funcion desde la cual se obtiene la tension de entrada
%
% Variables de salida:
% t % Vector temporal correspondiente tanto a vl como a il
% vl % Vector tension en el inductor
% il % Vector corriente en el inductor
%
% Ejemplo:
% R=5; L=.1;
% tspan = 0 : .01 : 5;
% x = @(t) esc(t) - esc(t-1);
% [t, vl, il] = f_resRL_bis(R, L, tspan, x);
% vi = x(t);
% subplot(311); plot(t, vi); grid; axis tight; title('v_{i(t)}'); xlabel('t');
% subplot(312); plot(t, il); grid; axis tight; title('i_{L(t)}'); xlabel('t');
% subplot(313); plot(t, vl); grid; axis tight; title('v_{L(t)}'); xlabel('t');

    il_prima = @(t,il) x(t) * (1/L) - il * R/L; % Defino una función anónima asociada a la señal il_prima de la EDO de un circuito RL serie
    condiciones_iniciales = 0; % Planteo condiciones nulas para evaluar EDO 
    [tsal,ilsal] = ode23(il_prima, tspan, condiciones_iniciales); % Calculo el t de salida y la señal il de salida
    t = tsal; % Retorno la variable tsal
    il = ilsal;% Retorno la variable ilsal
    vl = x(tsal) - (ilsal * R); % Calculo la vl de salida por Kirchoff
end

