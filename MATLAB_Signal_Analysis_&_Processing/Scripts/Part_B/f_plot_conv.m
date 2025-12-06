function [t_y, y] = f_plot_conv(t_x, x, t_h, h)
%[ESP] Declaración de la función, recibe dos señales y sus vectores de tiempo.
%[ENG] Function declaration, receives two signals and their time vectors.

% Author: Facundo Costarelli

%f_plot_conv(t_x, x, t_h, h) calcula la salida de un sistema con respuesta
% al impulso h, cuando ingresa una señal x. Luego, grafica las 3 señales.
%
% Variables de entrada:
% t_x %Vector temporal de la señal de entrada
% x %Señal de entrada al sistema (excitacion)
% t_h %Vector temporal de la respuesta al impulso
% h %Respuesta al impulso
%
% Variables de salida:
% t_y %Vector temporal de la señal de salida
% y %Señal de salida
%
% Ejemplo:
% dt = 0.01; %Incremento diferencial
% t_x = -1 : dt : 10;
% t_h = -2 : dt : 5;
% x = esc(t_x) - esc(t_x-8);
% h = 5*esc(t_h).*exp(-2*t_h);
%
% f_plot_conv(t_x, x, t_h, h);
% f_plot_conv(t_h, h, t_x, x); %Por propiedad, deberian resultar iguales

    %[ESP] Cálculo del incremento diferencial (paso de tiempo).
    %[ENG] Calculating the differential increment (time step).
    dt_y = t_x(2) - t_x(1); % Calculo el Incremento diferencial entre un punto y otro. Esto es la diferencia entre 2 elementos temporales consecutivos. Vale tambien dt_y = t_h(2) - t_h(1);
    
    %[ESP] Cálculo de la longitud del vector de salida.
    %[ENG] Calculating the length of the output vector.
    n = (length(t_h)+length(t_x)-1); % Calculo el numero de elementos de t_y
    
    %[ESP] Creación del vector de tiempo para la señal de salida.
    %[ENG] Creating the time vector for the output signal.
    t_y = linspace(t_x(1) + t_h(1), t_x(end) + t_h(end), n); % Creo un vector temporal para la señal de salida. Temporalmente comienza en la suma de los inicios y termina en la suma de los finales de las señales x e h
    
    %[ESP] Cálculo de la convolución y escalado por el paso de tiempo.
    %[ENG] Calculating the convolution and scaling by the time step.
    % 
    y = conv(x,h) * dt_y; % Creo un vector asociado a la señal de salida la cual resulta por convolución

    %[ESP] Obtención de los límites de la señal 'x' para el gráfico.
    %[ENG] Getting the limits of the 'x' signal for the plot.
    max_x = max(x); % Calculo los máximos y mínimos de señal x, h e y. Así puedo modificar genericamente los limites superiores e inferiores del eje horizontal para graficar mejor
    min_x = min(x);

    %[ESP] Obtención de los límites de la señal 'h' para el gráfico.
    %[ENG] Getting the limits of the 'h' signal for the plot.
    max_h = max(h);
    min_h = min(h);

    %[ESP] Obtención de los límites de la señal 'y' para el gráfico.
    %[ENG] Getting the limits of the 'y' signal for the plot.
    max_y = max(y);
    min_y = min(y);


    %[ESP] Graficación de la señal de entrada 'x'.
    %[ENG] Plotting the input signal 'x'.
    subplot(3,1,1); plot(t_x,x); axis([t_x(1) t_x(end) min_x-1 max_x+1]); % Grafico de la señal de entrada
    title('Señal de entrada'); ylabel('x(t)'); xlabel('t[seg]');
    
    %[ESP] Graficación de la respuesta al impulso 'h'.
    %[ENG] Plotting the impulse response 'h'.
    subplot(3,1,2); plot(t_h,h); axis([t_h(1) t_h(end) min_h-1 max_h+1]); % Grafico de la respuesta impulsional 
    title('Respuesta al Impulso'); ylabel('h(t)'); xlabel('t[seg]');
    
    %[ESP] Graficación de la señal de salida 'y' (convolución).
    %[ENG] Plotting the output signal 'y' (convolution).
    subplot(3,1,3); plot(t_y,y); axis([(t_x(1) + t_h(1)) (t_x(end) + t_h(end)) min_y-1 max_y+1]); % Grafico de la señal de salida
    title('Salida: convolución de la entrada con la respuesta al impulso'); ylabel('y(t)'); xlabel('t[seg]'); 

end
%[ESP] Fin de la función.
%[ENG] End of the function.
