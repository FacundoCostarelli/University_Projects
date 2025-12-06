function [e_aprox] = f_calc_e(num_elements)
%[ESP] Declaración de la función, recibe el número de elementos.
%[ENG] Function declaration, receives the number of elements.

% Author: Facundo Costarelli

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

    %[ESP] Creación de un vector con los números para el factorial (de N-1 a 0).
    %[ENG] Creating a vector for the factorial numbers (from N-1 down to 0).
    factores = num_elements - 1 : -1 : 0; % Creo un vector fila que almacena los factores a factorizar de cada elemento de la serie

    %[ESP] Cálculo de los factoriales de cada elemento del vector.
    %[ENG] Calculating the factorials of each element in the vector.
    factoriales = factorial(factores); % Creo un vector fila que contiene los factoriales de cada factor

    %[ESP] Cálculo del inverso de cada factorial (1/n!).
    %[ENG] Calculating the inverse of each factorial (1/n!).
    A = 1./factoriales; % Creo un vector fila que contiene los factoriales invertidos 

    %[ESP] Suma de todos los términos de la serie para aproximar 'e'.
    %[ENG] Summing all terms of the series to approximate 'e'.
    e_aprox = sum(A); % Creo una variable que almacena la suma de los elementos de la serie ubicados en A. Esta contiene el valor de "e" aproximado

end
%[ESP] Fin de la función.
%[ENG] End of the function.