
import matplotlib.pyplot as plt

# Datos del gráfico
frecuencias_nuevas = [1033.01, 1576.04, 1754.4, 2155.13, 2376.9, 2406.81, 2715.9, 3082.65, 3209.78, 3761.86, 3838.84, 4086.67, 4475.97, 4938.52, 5312.27, 5351.83, 5635.1, 6272.6, 6601.45, 6952.37, 7299.2, 7784.38, 8223.82, 8889.79, 9057.38, 9767.61, 10299.99, 10657.52, 12711.38, 15791.69]
ganancia_db = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.239296, -0.390443, -1.119036, -1.889811, -3.125353, -6.487732, -15.672911, -25.215336, -28.846419, -28.629261, -29.352047, -32.567779, -33.229944, -20.932504, -13.1613, -8.455272, -5.11414, -3.098039, -1.322756, -0.263992, 0.0, 0.0, 0.0]

# Crear gráfico con líneas punteadas
plt.figure(figsize=(10, 6))
plt.semilogx(frecuencias_nuevas, ganancia_db, marker='o', linestyle='-', color='blue', label='Ganancia (dB)')

# Agregar líneas verticales
for f in [3600, 9100]:
    plt.axvline(f, color='green', linestyle='--', linewidth=1, label='Límite banda de paso en 3600Hz y 9100Hz' if f == 3600 else "")
for f in [5450, 5900]:
    plt.axvline(f, color='blue', linestyle='--', linewidth=1, label='Límite banda de rechazo en 5450Hz y 5900Hz' if f == 5450 else "")

# Etiquetas y estilo
plt.title('Módulo del Filtro Elimina-Banda')
plt.xlabel('Frecuencia [Hz]')
plt.ylabel('Ganancia [dB]')
plt.grid(which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.show()
