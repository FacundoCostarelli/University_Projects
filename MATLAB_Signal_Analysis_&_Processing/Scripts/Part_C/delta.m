function d = delta(x)
%[ESP] Declaración de la función, recibe el vector de entrada.
%[ENG] Function declaration, receives the input vector.

% Author: Facundo Costarelli

% Genera la funcion impulso/delta de dirac d(x)={1/dx si x=0; 0 si x!=0}
% 
% 	Variables de entrada:
% 	x %Vector temporal (t) o discreto (n)
% 
% 	Variables de salida:
% 	d %Valor del delta de dirac para cada valor del vector de entrada
% 
% 	Ejemplo:
% 	t = 0 : 20;
% 	y = delta(t) - delta(t-5) + delta(t-10);
% 	plot(t, y);

    %[ESP] Cálculo del intervalo (paso) del vector de entrada.
    %[ENG] Calculating the interval (step) of the input vector.
	dx = abs(x(2) - x(1));
    
    %[ESP] Generación del impulso (valor 1/dx) en la muestra x=0.
    %[ENG] Generating the impulse (value 1/dx) at the x=0 sample.
    % 
	d = (1/dx) .* (x<dx) .* (x>-dx);
end
%[ESP] Fin de la función.
%[ENG] End of the function.

