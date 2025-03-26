function [n_y, y] = f_stem_conv(n_x, x, n_h, h)
%f_plot_conv(n_x, x, n_h, h) calcula la salida de un sistema con respuesta
%al impulso h, cuando ingresa una señal x. Luego, grafica las 3 señales.
%
% Variables de entrada:
% n_x %Vector de indices de la señal de entrada
% x %Señal de entrada al sistema (excitacion)
% n_h %Vector de indices de la respuesta al impulso
% h %Respuesta al impulso
%
% Variables de salida:
% n_y %Vector de indices de la señal de salida
% y %Señal de salida
%
% Ejemplo:
% n_x = -5 : 50;
% n_h = -2 : 20;
% x = esc(n_x) - esc(n_x-30);
% h = 5*esc(n_h).*exp(-0.5*n_h);
%
% f_stem_conv(n_x, x, n_h, h);
% f_stem_conv(n_h, h, n_x, x); %Por propiedad, deberian resultar iguales



% Creo un nuevo vector de muestras de salida, este comienza en la suma de
% los inicios y finaliza en la suma de los finales. 
% Su largo es: (length(n_h)+length(n_x)-1)
n_y = (n_x(1) + n_h(1)) : (n_x(end) + n_h(end));

% Creo un vector asociado a la señal de salida, la cual resulta por
% convolución
y = conv(x, h);

% Creo variables que almacenan los máximos y mínimos. Esto para la señal de entrada, respuesta
% impulsional y la señal de salida. Así puedo modificar genericamente los
% limites superiores e inferiores del eje horizontal en axis para graficar
% mejor

max_x = max(x);
min_x = min(x);

max_h = max(h);
min_h = min(h);

max_y = max(y);
min_y = min(y);

% Grafico de la señal de entrada
subplot(3,1,1); stem(n_x,x); axis([n_x(1) n_x(end) min_x-1 max_x+1]);
title('Señal de entrada'); ylabel('x(t)'); xlabel('n[muestras]');
% Grafico de la respuesta impulsional 
subplot(3,1,2); stem(n_h,h); axis([n_h(1) n_h(end) min_h-1 max_h+1]);
title('Respuesta al Impulso'); ylabel('h(t)'); xlabel('n[muestras]');
% Grafico de la señal de salida
subplot(3,1,3); stem(n_y,y); axis([(n_x(1) + n_h(1)) (n_x(end) + n_h(end)) min_y-1 max_y+1]);
title('Salida: convolución de la entrada con la respuesta al impulso'); ylabel('y(t)'); xlabel('n[muestras]'); 


