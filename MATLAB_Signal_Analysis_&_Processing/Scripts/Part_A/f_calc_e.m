function [e_aprox] = f_calc_e(num_elements)
%f_calc_e(num_elements) aproxima el número e mediante su descomposición en 
% serie
% Variables de entrada:
% num_elements %Cantidad de elementos de la serie a tener en cuenta
%
% Variables de salida:
% e_aprox %Valor aproximado del numero e
%
% Ejemplo:
% num_elements = 18;
% e_aprox = f_calc_e(num_elements);
% fprintf('e_aprox: %.16f\ne_matlab: %.16f\n', e_aprox, exp(1)) %Comparacion
 
    factores = num_elements - 1 : -1 : 0; % Creo un vector fila que almacena los factores a factorizar de cada elemento de la serie
    factoriales = factorial(factores); % Creo un vector fila que contiene los factoriales de cada factor
    A = 1./factoriales; % Creo un vector fila que contiene los factoriales invertidos 
    e_aprox = sum(A); % Creo una variable que almacena la suma de los elementos de la serie ubicados en A. Esta contiene el valor de "e" aproximado

end