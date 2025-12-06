function [t, vl, il]= f_resRL(R, L, tspan, x)
%[ESP] Declaración de la función, recibe parámetros del circuito y entrada.
%[ENG] Function declaration, receives circuit parameters and input.

% Author: Facundo Costarelli

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

    %[ESP] Definición de la Ecuación Diferencial Ordinaria (EDO) del circuito.
    %[ENG] Defining the Ordinary Differential Equation (ODE) of the circuit.
    
    il_prima = @(t,il) x(t) * (1/L) - il * R/L; % Defino una función anónima asociada a la señal il_prima de la EDO de un circuito RL serie
    
    %[ESP] Establecimiento de las condiciones iniciales (nulas).
    %[ENG] Setting the initial conditions (zero).
    condiciones_iniciales = 0; % Planteo condiciones nulas para evaluar EDO 
    
    %[ESP] Resolución de la EDO usando el solver numérico (ode23).
    %[ENG] Solving the ODE using the numerical solver (ode23).
    [tsal,ilsal] = ode23(il_prima, tspan, condiciones_iniciales); % Calculo el t de salida y la señal il de salida
    
    %[ESP] Asignación del vector de tiempo de salida.
    %[ENG] Assigning the output time vector.
    t = tsal; % Retorno la variable tsal
    
    %[ESP] Asignación del vector de corriente del inductor (salida).
    %[ENG] Assigning the inductor current vector (output).
    il = ilsal;% Retorno la variable ilsal
    
    %[ESP] Cálculo de la tensión en el inductor (Vl = Vi - Vr).
    %[ENG] Calculating the inductor voltage (Vl = Vi - Vr).
    vl = x(tsal) - (ilsal * R); % Calculo la vl de salida por Kirchoff
end
%[ESP] Fin de la función.
%[ENG] End of the function.

