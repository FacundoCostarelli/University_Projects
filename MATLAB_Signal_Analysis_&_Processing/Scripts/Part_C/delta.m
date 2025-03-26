function d = delta(x)
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

	dx = abs(x(2) - x(1));
	d = (1/dx) .* (x<dx) .* (x>-dx);
end


