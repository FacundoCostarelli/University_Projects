function [n_y, y] = f_stem_conv(n_x, x, n_h, h)
%[ESP] Declaración de la función, recibe señales discretas y sus índices.
%[ENG] Function declaration, receives discrete signals and their indices.

% Author: Facundo Costarelli

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
%[ESP] Creación del vector de índices para la señal de salida.
%[ENG] Creating the index vector for the output signal.
n_y = (n_x(1) + n_h(1)) : (n_x(end) + n_h(end));

% Creo un vector asociado a la señal de salida, la cual resulta por
% convolución
%[ESP] Cálculo de la convolución discreta de las señales.
%[ENG] Calculating the discrete convolution of the signals.
% 
y = conv(x, h);

% Creo variables que almacenan los máximos y mínimos. Esto para la señal de entrada, respuesta
% impulsional y la señal de salida. Así puedo modificar genericamente los
% limites superiores e inferiores del eje horizontal en axis para graficar
% mejor

%[ESP] Obtención de los límites de la señal 'x' para el gráfico.
%[ENG] Getting the limits of the 'x' signal for the plot.
max_x = max(x);
min_x = min(x);

%[ESP] Obtención de los límites de la señal 'h' para el gráfico.
%[ENG] Getting the limits of the 'h' signal for the plot.
max_h = max(h);
min_h = min(h);

%[ESP] Obtención de los límites de la señal 'y' para el gráfico.
%[ENG] Getting the limits of the 'y' signal for the plot.
max_y = max(y);
min_y = min(y);

% Grafico de la señal de entrada
%[ESP] Graficación (stem) de la señal de entrada 'x'.
%[ENG] Plotting (stem) the input signal 'x'.
subplot(3,1,1); stem(n_x,x); axis([n_x(1) n_x(end) min_x-1 max_x+1]);
title('Señal de entrada'); ylabel('x(t)'); xlabel('n[muestras]');
% Grafico de la respuesta impulsional 
%[ESP] Graficación (stem) de la respuesta al impulso 'h'.
%[ENG] Plotting (stem) the impulse response 'h'.
subplot(3,1,2); stem(n_h,h); axis([n_h(1) n_h(end) min_h-1 max_h+1]);
title('Respuesta al Impulso'); ylabel('h(t)'); xlabel('n[muestras]');
% Grafico de la señal de salida
%[ESP] Graficación (stem) de la señal de salida 'y' (convolución).
%[ENG] Plotting (stem) the output signal 'y' (convolution).
subplot(3,1,3); stem(n_y,y); axis([(n_x(1) + n_h(1)) (n_x(end) + n_h(end)) min_y-1 max_y+1]);
title('Salida: convolución de la entrada con la respuesta al impulso'); ylabel('y(t)'); xlabel('n[muestras]'); 

end
%[ESP] Fin de la función.
%[ENG] End of the function.
