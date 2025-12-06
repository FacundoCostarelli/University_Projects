function [n] = get_number_from_dtmf(x, fs)

% Author: Facundo Costarelli

%[ESP] Definición de la función, recibe la señal y la frecuencia.
%[ENG] Function definition, receives the signal and the frequency.

%get_number_from_dtmf() decodifica una señal de audio DTMF
%
% Variables de entrada:
% x % Señal de audio DTMF a decodificar
% fs % Frecuencia de muestreo, en Hertz
%
% Variables de salida:
% n % Número (tecla de marcación) correspondiente a la señal de entrada

    %[ESP] Creación de un vector que agrupa todos los filtros.
    %[ENG] Creating a vector that groups all the filters.
    % Genero un vector con cada uno de los filtros para iterar sobre ellos
    h = [row1(fs) row2(fs) row3(fs) row4(fs) colA(fs) colB(fs) colC(fs)];
    
    %[ESP] Definición de la matriz de referencia del teclado.
    %[ENG] Defining the keypad reference matrix.
    % Creo una matriz con todos los digitos posibles del teclado
    matrix = [1, 2, 3 ; 4, 5, 6 ; 7, 8, 9; 42, 0, 35];
    
    %[ESP] Cálculo de la energía de la señal de entrada.
    %[ENG] Calculating the energy of the input signal.
    % Calculo la energia de la señal temporal x(t) de entrada
    dt = 1/fs; 
    Ex = sumsqr(x)*dt;

    %[ESP] Inicio del bucle para procesar cada filtro.
    %[ENG] Starting the loop to process each filter.
    % Itero filtros del vector h donde convoluciono cada uno con la entrada
    % y obtengo una salida y(t) para determinar cual fue el digito n usado
    for i = 1:length(h)
        %[ESP] Extracción de los coeficientes del filtro actual.
        %[ENG] Extracting the coefficients from the current filter.
        % Obtengo los coeficientes de cada filtro usando Numerator
        coeficientes = h(i).Numerator;
        
        %[ESP] Aplicación del filtro (convolución) a la señal de entrada.
        %[ENG] Applying the filter (convolution) to the input signal.
        % Obtengo la salida de la convolucion de cada filtro con la entrada
        y = conv(x, coeficientes);
        
        %[ESP] Cálculo de la energía de la señal de salida filtrada.
        %[ENG] Calculating the energy of the filtered output signal.
        % Calculo la energia de la señal temporal y(t) de salida
        Ey = sumsqr(y)*dt;
        
        %[ESP] Detección de la fila o columna activa basada en la energía.
        %[ENG] Detecting the active row or column based on energy.
        % Pregunto y detecto el digito n a partir de la relacion de energias de y(t)
        % respecto de x(t) y hallo cual row y col corresponde de filtro
        if Ey/Ex >= 0.45 && i<= 4
            fila = i;
        elseif Ey/Ex >= 0.45
            columna = i - 4;
        end
    end
    
    %[ESP] Asignación del dígito final usando la fila y columna.
    %[ENG] Assigning the final digit using the row and column.
    n = matrix(fila, columna);
end