function [res_xy, res_abs, res_angle] = f_get_roots(n, z)

% Author: Facundo Costarelli

%[ESP] Declaración de la función, recibe 'n' y 'z', retorna 3 vectores.
%[ENG] Function declaration, receives 'n' and 'z', returns 3 vectors.

% f_get_roots(n, z) calcula los n resultados de la raiz n-esima de z
%
% Variables de entrada:
% n %Exponente de la raiz (numero natural)
% z %Argumento de la raiz (numero complejo)
%
% Variables de salida:
% res_xy %Vector columna con las n raices (formato cartesiano)
% res_abs %Vector columna con el modulo de las n raices (formato polar)
% res_angle %Vector columna con la fase en rad de las n raices (formato polar)
%
% Ejemplo:
% z = -1; %Argumento de la raiz
% n = 2; %Exponente de la raiz
% [res_xy, res_abs, res_angle] = f_get_roots(n, z)
% figure; zplane(res_xy);

    %[ESP] Creación del polinomio (z^n - z) para encontrar las raíces.
    %[ENG] Creating the polynomial (z^n - z) to find the roots.
    polinomio = [1, zeros(1,(n-1)), -z]; % Creación de polinomio con 1er coeficiente igual a 1 que multiplica Z^n, con coeficientes n-1 ceros intermedios y con el ultimo coeficiente igual al numero complejo de entrada
    
    %[ESP] Cálculo de las raíces del polinomio (salida cartesiana).
    %[ENG] Calculating the roots of the polynomial (Cartesian output).
    res_xy = roots(polinomio); % Calculo de las n raices del argumento z del radical
    
    %[ESP] Cálculo del módulo (magnitud) de las raíces.
    %[ENG] Calculating the modulus (magnitude) of the roots.
    res_abs = abs(res_xy); % Calculo el modulo de las n raices
    
    %[ESP] Cálculo del ángulo (fase) de las raíces.
    %[ENG] Calculating the angle (phase) of the roots.
    res_angle = angle(res_xy); % Calculo la fase de las n raices

end
%[ESP] Fin de la función.
%[ENG] End of the function.