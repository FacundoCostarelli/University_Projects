from tkinter import filedialog, Button, Scale, Entry, Frame
import pyaudio
import soundfile as sf
import numpy as np
import threading
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from tkinter import BOTH
import sys
import os
from matplotlib import style
from scipy.signal import butter, lfilter
import queue

style.use('ggplot')

# Variables globales
p = pyaudio.PyAudio()
Amp = 1
chunk_size = 1024
buffer_queue = queue.Queue()
audio_stream = None
lock = threading.Lock()  # Inicializar el lock globalmente
stop_event = threading.Event()
data_filtrada = None
current_index = 0
audio_terminado = False
delay_aplicado = False
delay_buffer = np.array([])
decay = 0.5
sample_rate = None
filtro_aplicado = None
data_original = None
hilo_delay = None  # Asegúrate de definir esto globalmente

def GraficaVacia(frame):
    figura = plt.Figure(figsize=(5, 4), dpi=100, facecolor='black')
    ax = figura.add_subplot(111)
    ax.set_facecolor('black')
    line, = ax.plot([], [], color='limegreen', linewidth=1.5, antialiased=True)
    ax.set_title("Gráfico en Tiempo", fontsize=14, fontweight='bold', color='white')
    ax.set_xlabel("Tiempo (s)", fontsize=12, color='white')
    ax.set_ylabel("Amplitud", fontsize=12, color='white')
    ax.tick_params(axis='x', colors='white')
    ax.tick_params(axis='y', colors='white')
    ax.set_ylim(-1.1, 1.1)
    ax.grid(True, which='both', linestyle='--', linewidth=0.5, color='gray')
    
    if line.get_label()[0] != '_':
        ax.legend(loc='upper right', fontsize=10, frameon=True, facecolor='gray', edgecolor='white')

    canvas = FigureCanvasTkAgg(figura, master=frame)
    canvas.draw()
    canvas.get_tk_widget().pack(fill="both", expand=True)

    return figura, ax, line

def detenerAudio():
    global audio_stream

    try:
        if audio_stream is not None:
            audio_stream.stop_stream()
            audio_stream.close()
            audio_stream = None
    except OSError as e:
        print(f"Error al detener el stream de audio: {e}")

    stop_event.set()

def cerrarPrograma(raiz):
    global p

    detenerAudio()

    try:
        raiz.quit()
        raiz.destroy()
    except Exception as e:
        print(f"Error cerrando la ventana de Tkinter: {e}")

    if p is not None:
        try:
            p.terminate()
        except Exception as e:
            print(f"Error terminando PyAudio: {e}")

    sys.exit(0)

def abrirArchivo(figura, ax, line):
    global archivo_ruta, data, sample_rate, data_filtrada, data_original, current_index, buffer_acumulado, audio_stream, audio_terminado, stop_event
    global delay_aplicado, delay_buffer, delay_samples

    archivo = filedialog.askopenfile(title="Abrir", filetypes=[("Archivo WAV", "*.wav")])
    if archivo:
        detenerAudio()
        stop_event.set()
        archivo_ruta = archivo.name
        data, sample_rate = sf.read(archivo_ruta)

        if len(data.shape) == 2:
            data = data.mean(axis=1)

        data_filtrada = np.copy(data)
        data_original = np.copy(data)
        archivo.close()

        line.set_data([], [])
        ax.relim()
        ax.autoscale_view(True, True, True)
        figura.canvas.draw()

        current_index = 0
        buffer_acumulado = np.array([])
        audio_terminado = False
        stop_event.clear()

        delay_aplicado = False
        delay_buffer = np.array([])

def graficarEnTiempoReal(figura, ax, line, raiz):
    global audio_stream, sample_rate, buffer_acumulado, hilo_grafica

    detenerAudio()

    buffer_acumulado = np.array([])

    if audio_stream is None:
        audio_stream = p.open(format=pyaudio.paFloat32,
                              channels=1,
                              rate=sample_rate,
                              output=True,
                              frames_per_buffer=chunk_size,
                              stream_callback=audio_callback)
        audio_stream.start_stream()

    actualizarGraficaTkinter(figura, ax, line, raiz)

def actualizarGraficaTkinter(figura, ax, line, raiz, intervalo=100):
    global buffer_acumulado, sample_rate

    if buffer_queue.empty():
        raiz.after(intervalo, actualizarGraficaTkinter, figura, ax, line, raiz)
        return

    while not buffer_queue.empty():
        buffer_acumulado = np.append(buffer_acumulado, buffer_queue.get())

    max_puntos_grafica = 1500
    if len(buffer_acumulado) > max_puntos_grafica:
        step = len(buffer_acumulado) // max_puntos_grafica
        x_data = np.linspace(0, len(buffer_acumulado) / sample_rate, len(buffer_acumulado[::step]))
        y_data = buffer_acumulado[::step] * Amp
    else:
        x_data = np.linspace(0, len(buffer_acumulado) / sample_rate, len(buffer_acumulado))
        y_data = buffer_acumulado * Amp

    line.set_data(x_data, y_data)
    ax.relim()
    ax.autoscale_view(True, True, True)
    figura.canvas.draw()

    raiz.after(intervalo, actualizarGraficaTkinter, figura, ax, line, raiz)

# Función para ajustar la amplitud
def ajustarAmplitud(figura, ax, line, nuevo_valor):
    global Amp
    Amp = nuevo_valor  # Actualizar el valor global de la amplitud
    print(f"Amplitud ajustada a: {Amp}")

# Función de callback para procesar audio en tiempo real
def audio_callback(in_data, frame_count, time_info, status):
    global Amp, current_index, data_filtrada, filtro_aplicado, audio_terminado, delay_aplicado, delay_buffer, decay, delay_samples

    if current_index < len(data_filtrada):
        # Obtener el bloque actual del audio
        chunk = data_filtrada[current_index:current_index + frame_count]
        current_index += frame_count

        # Ajustar el tamaño del chunk si el último bloque es más pequeño que frame_count
        if len(chunk) < frame_count:
            frame_count = len(chunk)

        # Aplicar el delay si está activado
        if delay_aplicado:
            if len(delay_buffer) < frame_count:
                chunk_delay = delay_buffer[:len(delay_buffer)]
            else:
                chunk_delay = delay_buffer[:frame_count]

            delay_buffer = np.roll(delay_buffer, -frame_count)
            delay_buffer[-frame_count:] = np.pad(chunk, (0, max(0, frame_count - len(chunk))), 'constant')

            chunk = chunk + decay * chunk_delay

        # Aplicar el filtro si hay uno activo
        if filtro_aplicado is not None:
            chunk = filtro_aplicado(chunk, sample_rate)

        # Aplicar el ajuste de amplitud en tiempo real
        chunk = np.atleast_1d(chunk).flatten() * Amp

        # Acumular el buffer de audio en la cola
        buffer_queue.put(chunk)

    else:
        chunk = np.zeros(frame_count)
        audio_terminado = True

    return (np.clip(chunk, -1.0, 1.0).astype(np.float32).tobytes(), pyaudio.paContinue)

def limpiarFiltros(figura, ax, line):
    global data_original, data_filtrada, buffer_acumulado, filtro_aplicado, current_index, audio_terminado

    # No detener el audio ni el hilo de la gráfica, solo limpiar los filtros
    data_filtrada = np.copy(data_original)
    filtro_aplicado = None

    # Mantener el buffer acumulado y el índice actual
    line.set_data([], [])
    ax.relim()
    ax.autoscale_view(True, True, True)
    figura.canvas.draw()

    print("Filtros limpiados. Continuando reproducción sin modificar el estado del audio.")

# Funciones para aplicar diferentes filtros
def aplicarFiltroLowPass(figura, ax, line, cutoff):
    global filtro_aplicado
    filtro_aplicado = lambda chunk, fs: low_pass_filter(chunk, cutoff, fs)

def aplicarFiltroHighPass(figura, ax, line, cutoff):
    global filtro_aplicado
    filtro_aplicado = lambda chunk, fs: high_pass_filter(chunk, cutoff, fs)

def aplicarFiltroBandPass(figura, ax, line, cutoff):
    global filtro_aplicado
    filtro_aplicado = lambda chunk, fs: band_pass_filter(chunk, cutoff * 0.9, cutoff * 1.1, fs)

def aplicarFiltroBandReject(figura, ax, line, cutoff):
    global filtro_aplicado
    filtro_aplicado = lambda chunk, fs: band_reject_filter(chunk, cutoff * 0.9, cutoff * 1.1, fs)

def low_pass_filter(data, cutoff, fs, order=5):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    b, a = butter(order, normal_cutoff, btype='low', analog=False)
    return lfilter(b, a, data)

def high_pass_filter(data, cutoff, fs, order=5):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    b, a = butter(order, normal_cutoff, btype='high', analog=False)
    return lfilter(b, a, data)

def band_pass_filter(data, lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return lfilter(b, a, data)

def band_reject_filter(data, lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='bandstop')
    return lfilter(b, a, data)

def aplicarDelayFijo(figura, ax, line, raiz, delay_time):
    global delay_aplicado, delay_buffer, delay_samples, sample_rate, data_filtrada, hilo_delay

    if audio_terminado:
        print("El audio ha terminado. Reinicia el audio antes de aplicar otro delay.")
        return

    detener_hilo_y_audio()

    # Asegurarse de que solo un hilo de delay se ejecute a la vez
    with lock:
        def aplicarDelay(delay_time):
            audio_duration = len(data_filtrada) / sample_rate
            if delay_time > audio_duration:
                delay_time = audio_duration
                print(f"Delay ajustado a la duración del audio: {delay_time} segundos.")

            global delay_aplicado, delay_samples, delay_buffer
            delay_samples = int(sample_rate * delay_time)
            delay_buffer = np.zeros(delay_samples)
            delay_aplicado = True

            reiniciarYReproducir(figura, ax, line, raiz)

            while not stop_event.is_set():
                pass

        hilo_delay = threading.Thread(target=aplicarDelay, args=(delay_time,))
        hilo_delay.daemon = True
        hilo_delay.start()

def detener_hilo_y_audio():
    global hilo_delay, audio_stream, stop_event

    # Aseguramos que `hilo_delay` sea reconocido como global
    global hilo_delay

    stop_event.set()

    if hilo_delay and hilo_delay.is_alive():
        print("Esperando a que el hilo de delay anterior termine...")
        hilo_delay.join()
        print("Hilo de delay anterior terminado.")

    if audio_stream is not None:
        print("Deteniendo el stream de audio...")
        audio_stream.stop_stream()
        audio_stream.close()
        audio_stream = None

    liberar_recursos()
    stop_event.clear()

# Función para liberar buffers y recursos de audio
def liberar_recursos():
    global delay_buffer, buffer_acumulado
    delay_buffer = np.array([])
    buffer_acumulado = np.array([])
    print("Recursos de audio y buffers liberados.")

# Función para limpiar buffers acumulados
def limpiar_buffers():
    global buffer_acumulado, delay_buffer
    buffer_acumulado = np.array([])
    delay_buffer = np.array([])
    print("Buffers limpiados.")

def reiniciarYReproducir(figura, ax, line, raiz):
    global current_index, buffer_acumulado, data_filtrada, audio_terminado, stop_event
    detenerAudio()

    current_index = 0
    buffer_acumulado = np.array([])
    audio_terminado = False
    data_filtrada = np.copy(data_original)

    graficarEnTiempoReal(figura, ax, line, raiz)
