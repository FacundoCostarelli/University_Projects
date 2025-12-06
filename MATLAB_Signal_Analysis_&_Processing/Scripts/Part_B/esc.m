function u = esc(x)
%[ESP] Declaración de la función, recibe el vector de entrada.
%[ENG] Function declaration, receives the input vector.

% Author: Facundo Costarelli

% Genera la funcion escalon unitario u(x)={1 si x>=0; 0 si x<0}
% 
% 	Variables de entrada:
% 	x %Vector temporal (t) o discreto (n)
% 
% 	Variables de salida:
% 	u %Valor del escalon para cada valor del vector de entrada
% 
% 	Ejemplo:
% 	t = -1 : 0.01 : 3;
% 	y = esc(t) - esc(t-1);
% 	plot(t, y);

    %[ESP] Creación del escalón mediante una comparación lógica.
    %[ENG] Creating the step function using a logical comparison.
    % 

[Image of a unit step function graph]

	u = double(x >= 0);
end
%[ESP] Fin de la función.
%[ENG] End of the function.