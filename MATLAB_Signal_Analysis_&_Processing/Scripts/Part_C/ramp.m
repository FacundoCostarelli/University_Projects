function r = ramp(x)
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

	r = x.*(x > 0);
end
