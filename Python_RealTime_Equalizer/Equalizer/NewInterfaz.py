import customtkinter as ctk  # Usaremos CustomTkinter para sliders modernos
from New_Funciones import (abrirArchivo, GraficaVacia, graficarEnTiempoReal, cerrarPrograma, 
                          ajustarAmplitud, aplicarFiltroLowPass, aplicarFiltroHighPass, 
                          aplicarFiltroBandPass, aplicarFiltroBandReject, reiniciarYReproducir, 
                          limpiarFiltros, aplicarDelayFijo)

# Función para ajustar el diseño de los sliders en función del tamaño de la ventana
def ajustar_centrado_sliders(event=None):
    ancho_ventana = raiz.winfo_width()
    if ancho_ventana > 1200:
        for columna in sliders_columnas:
            columna.pack_configure(padx=(ancho_ventana - 900) // 8)  # Ajuste dinámico del padding en función del tamaño
    else:
        for columna in sliders_columnas:
            columna.pack_configure(padx=70)  # Incrementamos el padding para mover los sliders hacia la derecha

# Función para actualizar los valores y nombres bajo cada slider
def actualizar_valor(label, slider):
    label.configure(text=f"Valor: {slider.get():.1f}")
    label.update_idletasks()  # Para hacer la actualización más fluida

# Crear la ventana principal
raiz = ctk.CTk()  # Usamos CustomTkinter para una apariencia más moderna
raiz.title("Filtro de Audio")
raiz.geometry("1200x800")  # Establecemos un tamaño de ventana por defecto
raiz.configure(fg_color="black")  # Cambiar el fondo de la ventana principal a negro

# Guardamos la ventana en una variable global para usarla en el manejo de excepciones
global global_raiz
global_raiz = raiz

# Marco para la gráfica
frame_grafica = ctk.CTkFrame(raiz, width=600, height=400, fg_color="black")  # Fondo negro para la gráfica también
frame_grafica.pack(side="top", fill="both", expand=True)  # Ocupa la parte superior de la ventana

# Crear la gráfica vacía al iniciar
figura, ax, line = GraficaVacia(frame_grafica)

# Marco para los controles de archivo y graficar
frame_controles = ctk.CTkFrame(raiz, fg_color="black")  # Fondo negro para los botones de control
frame_controles.pack(side="top", pady=10)

# Estilo personalizado para los botones con bordes blancos
boton_style = {
    "fg_color": "black",  # Fondo negro
    "text_color": "white",  # Texto blanco
    "hover_color": "#1DB954",  # Color verde al hacer clic (similar a Spotify)
    "font": ("Arial", 12),
    "corner_radius": 10,  # Bordes redondeados
    "border_color": "white",  # Bordes blancos
    "border_width": 2  # Grosor del borde
}

# Botón para abrir archivo
archivo_button = ctk.CTkButton(frame_controles, text="Abrir archivo", command=lambda: abrirArchivo(figura, ax, line), **boton_style)
archivo_button.pack(side="left", padx=10)

# Botón para graficar en tiempo real y reproducir
grafica_button = ctk.CTkButton(frame_controles, text="Graficar y Reproducir", command=lambda: graficarEnTiempoReal(figura, ax, line, raiz), **boton_style)
grafica_button.pack(side="left", padx=10)

# Botón para reiniciar la reproducción y la gráfica
reiniciar_button = ctk.CTkButton(frame_controles, text="Reiniciar y Reproducir", command=lambda: reiniciarYReproducir(figura, ax, line, raiz), **boton_style)
reiniciar_button.pack(side="left", padx=10)

# Botón para cerrar el programa
cerrar_button = ctk.CTkButton(frame_controles, text="Cerrar", command=lambda: cerrarPrograma(raiz), **boton_style)
cerrar_button.pack(side="left", padx=10)

# Marco para los filtros y sliders
frame_filtros_y_controles = ctk.CTkFrame(raiz, fg_color="black")  # Fondo negro para la sección de filtros
frame_filtros_y_controles.pack(side="top", pady=10, fill="x")

frame_filtros_botones = ctk.CTkFrame(frame_filtros_y_controles, fg_color="black")  # Fondo negro para los botones de filtros
frame_filtros_botones.pack(side="left", padx=10)

# Botones para aplicar diferentes filtros
low_pass_button = ctk.CTkButton(frame_filtros_botones, text="Filtro Pasa Bajos", command=lambda: aplicarFiltroLowPass(figura, ax, line, cutoff_slider.get()), **boton_style)
low_pass_button.pack(side="top", pady=5)

high_pass_button = ctk.CTkButton(frame_filtros_botones, text="Filtro Pasa Altos", command=lambda: aplicarFiltroHighPass(figura, ax, line, cutoff_slider.get()), **boton_style)
high_pass_button.pack(side="top", pady=5)

band_pass_button = ctk.CTkButton(frame_filtros_botones, text="Filtro Pasa Banda", command=lambda: aplicarFiltroBandPass(figura, ax, line, cutoff_slider.get()), **boton_style)
band_pass_button.pack(side="top", pady=5)

band_reject_button = ctk.CTkButton(frame_filtros_botones, text="Filtro Rechaza Banda", command=lambda: aplicarFiltroBandReject(figura, ax, line, cutoff_slider.get()), **boton_style)
band_reject_button.pack(side="top", pady=5)

limpiar_button = ctk.CTkButton(frame_filtros_botones, text="Limpiar Filtros", command=lambda: limpiarFiltros(figura, ax, line), **boton_style)
limpiar_button.pack(side="top", pady=5)

delay_fijo_button = ctk.CTkButton(frame_filtros_botones, text="Delay", command=lambda: aplicarDelayFijo(figura, ax, line, raiz, delay_slider.get()), **boton_style)
delay_fijo_button.pack(side="top", pady=5)

# Sliders modernos con CustomTkinter
frame_controles_deslizantes = ctk.CTkFrame(frame_filtros_y_controles, fg_color="black")  # Fondo negro para los sliders
frame_controles_deslizantes.pack(side="left", padx=10, fill="both")

# Dividimos los sliders en columnas
sliders_columnas = [ctk.CTkFrame(frame_controles_deslizantes, fg_color="black") for _ in range(4)]
for columna in sliders_columnas:
    columna.pack(side="left", pady=10, fill="y")

# Slider 1: Ajustar Amplitud (con funcionalidad y valor dinámico)
amplitud_slider = ctk.CTkSlider(sliders_columnas[0], from_=0.1, to=3, orientation="vertical", number_of_steps=29, button_color="#1DB954", button_hover_color="#1DB954")
amplitud_slider.set(1)
amplitud_slider.pack(side="top", pady=5)
amplitud_valor_label = ctk.CTkLabel(sliders_columnas[0], text="Valor: 1.00", font=("Arial", 10), fg_color="black", text_color="white")
amplitud_valor_label.pack(side="top")
ctk.CTkLabel(sliders_columnas[0], text="Ajustar Amplitud", font=("Arial", 10), fg_color="black", text_color="white").pack(side="top")

# Actualización en tiempo real al mover el slider
amplitud_slider.bind("<B1-Motion>", lambda event: [ajustarAmplitud(figura, ax, line, amplitud_slider.get()), actualizar_valor(amplitud_valor_label, amplitud_slider)])
amplitud_slider.bind("<ButtonRelease-1>", lambda event: [ajustarAmplitud(figura, ax, line, amplitud_slider.get())])

# Slider 2: Frecuencia de Corte (con funcionalidad y valor dinámico)
cutoff_slider = ctk.CTkSlider(sliders_columnas[1], from_=20, to=20000, orientation="vertical", number_of_steps=1998, button_color="#1DB954", button_hover_color="#1DB954")
cutoff_slider.set(1000)
cutoff_slider.pack(side="top", pady=5)
cutoff_valor_label = ctk.CTkLabel(sliders_columnas[1], text="Valor: 1000", font=("Arial", 10), fg_color="black", text_color="white")
cutoff_valor_label.pack(side="top")
ctk.CTkLabel(sliders_columnas[1], text="Frecuencia de Corte (Hz)", font=("Arial", 10), fg_color="black", text_color="white").pack(side="top")

# Actualización en tiempo real del valor del slider
cutoff_slider.bind("<B1-Motion>", lambda event: actualizar_valor(cutoff_valor_label, cutoff_slider))

# Slider 3: Orden del Filtro (con funcionalidad y valor dinámico)
order_slider = ctk.CTkSlider(sliders_columnas[2], from_=1, to=10, orientation="vertical", number_of_steps=9, button_color="#1DB954", button_hover_color="#1DB954")
order_slider.set(5)
order_slider.pack(side="top", pady=5)
order_valor_label = ctk.CTkLabel(sliders_columnas[2], text="Valor: 5", font=("Arial", 10), fg_color="black", text_color="white")
order_valor_label.pack(side="top")
ctk.CTkLabel(sliders_columnas[2], text="Orden del Filtro", font=("Arial", 10), fg_color="black", text_color="white").pack(side="top")

# Actualización en tiempo real del valor del slider
order_slider.bind("<B1-Motion>", lambda event: actualizar_valor(order_valor_label, order_slider))

# Slider 4: Tiempo de Delay (con funcionalidad y valor dinámico)
delay_slider = ctk.CTkSlider(sliders_columnas[3], from_=0.0, to=1.5, orientation="vertical", number_of_steps=15, button_color="#1DB954", button_hover_color="#1DB954")
delay_slider.set(0.5)
delay_slider.pack(side="top", pady=5)
delay_valor_label = ctk.CTkLabel(sliders_columnas[3], text="Valor: 0.50", font=("Arial", 10), fg_color="black", text_color="white")
delay_valor_label.pack(side="top")
ctk.CTkLabel(sliders_columnas[3], text="Tiempo de Delay (s)", font=("Arial", 10), fg_color="black", text_color="white").pack(side="top")

# Actualización en tiempo real del valor del slider
delay_slider.bind("<B1-Motion>", lambda event: actualizar_valor(delay_valor_label, delay_slider))

# Ajustar el centrado de sliders cuando la ventana cambia de tamaño
raiz.bind("<Configure>", ajustar_centrado_sliders)

# Ejecutar la interfaz
raiz.mainloop()
