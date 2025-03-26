function u = esc(x)
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

	u = double(x >= 0);
end
