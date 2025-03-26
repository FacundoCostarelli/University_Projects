function [n] = get_number_from_dtmf(x, fs)
%get_number_from_dtmf() decodifica una señal de audio DTMF
%
% Variables de entrada:
% x % Señal de audio DTMF a decodificar
% fs % Frecuencia de muestreo, en Hertz
%
% Variables de salida:
% n % Número (tecla de marcación) correspondiente a la señal de entrada

    % Genero un vector con cada uno de los filtros para iterar sobre ellos
    h = [row1(fs) row2(fs) row3(fs) row4(fs) colA(fs) colB(fs) colC(fs)];
    
    % Creo una matriz con todos los digitos posibles del teclado
    matrix = [1, 2, 3 ; 4, 5, 6 ; 7, 8, 9; 42, 0, 35];
    
    % Calculo la energia de la señal temporal x(t) de entrada
    dt = 1/fs; 
    Ex = sumsqr(x)*dt;

    % Itero filtros del vector h donde convoluciono cada uno con la entrada
    % y obtengo una salida y(t) para determinar cual fue el digito n usado
    for i = 1:length(h)
        % Obtengo los coeficientes de cada filtro usando Numerator
        coeficientes = h(i).Numerator;
        
        % Obtengo la salida de la convolucion de cada filtro con la entrada
        y = conv(x, coeficientes);
        
        % Calculo la energia de la señal temporal y(t) de salida
        Ey = sumsqr(y)*dt;
        
        % Pregunto y detecto el digito n a partir de la relacion de energias de y(t)
        % respecto de x(t) y hallo cual row y col corresponde de filtro
        if Ey/Ex >= 0.45 && i<= 4
            fila = i;
        elseif Ey/Ex >= 0.45
            columna = i - 4;
        end
    end
    
    n = matrix(fila, columna);
end