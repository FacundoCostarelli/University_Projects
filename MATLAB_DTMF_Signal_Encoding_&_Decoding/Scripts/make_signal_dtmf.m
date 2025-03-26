function [x, t] = make_signal_dtmf(n, fs, d)
%make_signal_dtmf() codifica, es decir, genera una señal de audio DTMF
%
% Variables de entrada:
% n % Número (tecla de marcación), debe estar comprendido entre 0 y 9
% fs % Frecuencia de muestreo, en Hertz
% d % Duración de la señal de audio resultante, en segundos
%
% Variables de salida:
% x % Señal de audio DTMF generada
% t % Vector temporal de x

    % Replico la tabla de frecuencias establecidas por la norma, segun fila y columna
    % del teclado de marcacion. Creo una vector fila y columna para guardar
    % cada dato
    fila = 2*pi*[697, 770, 852, 941];
    columna = 2*pi*[1209, 1336, 1477, 1633];
    
    % Creo un vector temporal de 0 a "d" segundos equiespaciado 1/fs
    t = 0:1/fs:d;
    
    % Creo una matriz con todos los digitos posibles del teclado
    matrix = [1, 2, 3 ; 4, 5, 6 ; 7, 8, 9; 42, 0, 35];
    
    % Busco en la matriz los indices del digito ingresado "n"
    [i,j,v] = find(matrix == n);
    
    % Pregunto si se encuentra el valor de n en la matrix. Si no es así,
    % entonces devuelve x = 0, sino genera el tono para el digito n
    if v == 0
        x = 0;
    else
        % Genero la funcion temporal con cosenos, es decir, el tono para cada valor de "n"
        x = 0.5.*( cos(fila(i)*t) + cos(columna(j)*t) ); 
    end

end
    



