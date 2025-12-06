% Author: Facundo Costarelli

%[ESP] Limpieza de la ventana de comandos.
%[ENG] Clearing the command window.
clc; % Limpia Command Window

%[ESP] Limpieza de todas las variables del espacio de trabajo.
%[ENG] Clearing all variables from the workspace.
clear; % Limpia Workspace al liberar memoria (variables)

%[ESP] Cierre de todas las ventanas de figuras abiertas.
%[ENG] Closing all open figure windows.
close all; % Cierra todas las figura

%% Configuraciones iniciales
%[ESP] Definición de la frecuencia de muestreo.
%[ENG] Defining the sampling frequency.
fs = 8000; % Muestras/segundo

%[ESP] Definición de la duración de la señal.
%[ENG] Defining the signal duration.
d = 2; % Segundos

%[ESP] Inicio del bucle para iterar sobre los dígitos del 0 al 9.
%[ENG] Starting the loop to iterate through digits 0 to 9.
for n = 0:9
    %% Parte A: Funcion codificadora (generadora)
    %[ESP] Generación de la señal DTMF para el dígito 'n'.
    %[ENG] Generating the DTMF signal for the digit 'n'.
    [x, t] = make_signal_dtmf(n, fs, d);

    %[ESP] Reproducción del tono generado.
    %[ENG] Playing the generated tone.
    % Reproduzco el tono
    playblocking(audioplayer(x, fs));
    
    %% Parte B: Funcion decodificadora (detectora)
    %[ESP] Decodificación de la señal para obtener el dígito.
    %[ENG] Decoding the signal to get the digit.
    resultado = get_number_from_dtmf(x, fs);

    %[ESP] Muestra del resultado de la decodificación en la consola.
    %[ENG] Displaying the decoding result in the console.
    disp(resultado);
end