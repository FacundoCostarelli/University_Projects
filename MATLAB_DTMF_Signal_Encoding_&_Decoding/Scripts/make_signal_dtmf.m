function [x, t] = make_signal_dtmf(n, fs, d)

% Author: Facundo Costarelli

%[ESP] Definición de la función, recibe el dígito, fs y duración.
%[ENG] Function definition, receives the digit, fs, and duration.

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

    %[ESP] Definición de las frecuencias angulares para filas y columnas.
    %[ENG] Defining angular frequencies for rows and columns.
    % Replico la tabla de frecuencias establecidas por la norma, segun fila y columna
    % del teclado de marcacion. Creo una vector fila y columna para guardar
    % cada dato
    fila = 2*pi*[697, 770, 852, 941];
    columna = 2*pi*[1209, 1336, 1477, 1633];
    
    %[ESP] Creación del vector de tiempo basado en fs y duración.
    %[ENG] Creating the time vector based on fs and duration.
    % Creo un vector temporal de 0 a "d" segundos equiespaciado 1/fs
    t = 0:1/fs:d;
    
    %[ESP] Definición de la matriz de referencia del teclado.
    %[ENG] Defining the keypad reference matrix.
    % Creo una matriz con todos los digitos posibles del teclado
    matrix = [1, 2, 3 ; 4, 5, 6 ; 7, 8, 9; 42, 0, 35];
    
    %[ESP] Búsqueda de la posición (índices) del dígito en la matriz.
    %[ENG] Searching for the digit's position (indices) in the matrix.
    % Busco en la matriz los indices del digito ingresado "n"
    [i,j,v] = find(matrix == n);
    
    %[ESP] Comprobación de si el dígito es válido.
    %[ENG] Checking if the digit is valid.
    % Pregunto si se encuentra el valor de n en la matrix. Si no es así,
    % entonces devuelve x = 0, sino genera el tono para el digito n
    if v == 0
        %[ESP] Asignación de salida nula si el dígito no existe.
        %[ENG] Assigning null output if the digit doesn't exist.
        x = 0;
    else
        %[ESP] Generación de la señal DTMF sumando los dos tonos.
        %[ENG] Generating the DTMF signal by adding the two tones.
        % Genero la funcion temporal con cosenos, es decir, el tono para cada valor de "n"
        x = 0.5.*( cos(fila(i)*t) + cos(columna(j)*t) ); 
    end

end
    



