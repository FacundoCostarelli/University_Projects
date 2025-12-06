function r = ramp(x)
%[ESP] Declaración de la función, recibe el vector de entrada.
%[ENG] Function declaration, receives the input vector.

% Author: Facundo Costarelli

% Genera la funcion rampa p(x)={x si x>=0; 0 si x<0}
% 
% 	Variables de entrada:
% 	x %Vector temporal (t) o discreto (n)
% 
% 	Variables de salida:
% 	r %Valor de la rampa para cada valor del vector de entrada
% 
% 	Ejemplo:
% 	t = 0 : 20;
% 	y = ramp(t) - ramp(t-5) + ramp(t-10);
% 	plot(t, y);

    %[ESP] Cálculo de la rampa usando multiplicación lógica.
    %[ENG] Calculating the ramp using logical multiplication.
    % 

[Image of a ramp function graph]

	r = x.*(x > 0);
end
%[ESP] Fin de la función.
%[ENG] End of the function.