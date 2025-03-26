% Facundo Costarelli 176.291-6

clc; % Limpia Command Window
clear; % Limpia Workspace al liberar memoria (variables)
close all; % Cierra todas las figura

%% Configuraciones iniciales
fs = 8000; % Muestras/segundo
d = 2; % Segundos

for n = 0:9
    %% Parte A: Funcion codificadora (generadora)
    [x, t] = make_signal_dtmf(n, fs, d);
    % Reproduzco el tono
    playblocking(audioplayer(x, fs));
    
    %% Parte B: Funcion decodificadora (detectora)
    resultado = get_number_from_dtmf(x, fs);
    disp(resultado);
end