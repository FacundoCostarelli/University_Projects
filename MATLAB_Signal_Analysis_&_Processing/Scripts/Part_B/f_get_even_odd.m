function [x_par, x_impar] = f_get_even_odd(n, x)
%f_get_even_odd(n, x) descompone la señal x en su parte par e impar.
%
% Variables de entrada:
% n %Vector de indices de la señal de entrada, debe ser simetrico
% x %Señal a descomponer (discreta)
%
% Variables de salida:
% x_par %Parte par de x(n)
% x_impar %Parte impar de x(n)
%
% Ejemplo:
% n = -10 : 10;
% x = n + 1; %Donde n es la parte impar, y 1 es la par
% [x_par, x_impar] = f_get_even_odd(n, x);
% x_new = x_par + x_impar;
%
% figure;
% subplot(411); stem(n, x); ylabel('x');
% subplot(412); stem(n, x_par); ylabel('x\_par');
% subplot(413); stem(n, x_impar); ylabel('x\_impar');
% subplot(414); stem(n, x_new); ylabel('x\_new');

% Para la obtención de la parte par e impar utilizo las expresiones
% propuestas en el capítulo 1 pagina 27 del libro de Asys. Esto es:
% x_par = 0.5 * (x[n] + x[-n])
% x_impar = 0.5 * (x[n] - x[-n])

% Señal par obtenida
x_par = 0.5 * (x + fliplr(x));
% Señal impar obtenida
x_impar = 0.5 * (x - fliplr(x));

