
import matplotlib.pyplot as plt

# Datos embebidos
frecuencias_nuevas = [1033.01, 1576.04, 1754.4, 2155.13, 2376.9, 2406.81, 2715.9, 3082.65, 3209.78, 3761.86, 3838.84, 4086.67, 4475.97, 4938.52, 5312.27, 5351.83, 5635.1, 6272.6, 6601.45, 6952.37, 7299.2, 7784.38, 8223.82, 8889.79, 9057.38, 9767.61, 10299.99, 10657.52, 12711.38, 15791.69]
desfase_rad = [0.0, 0.075398, 0.326726, 0.457416, 0.640885, 0.769062, 0.854513, 1.026044, 1.388584, 1.512991, 1.67761, 1.809557, 1.979203, 2.060885, 1.837831, 1.653734, 1.53938, 1.451415, 1.785681, 2.412743, 3.308097, 3.606548, 3.864159, 4.172035, 4.432787, 4.63699, 4.825486, 4.963716, 5.353274, 5.654867]

# Invertir signo del desfase para seguir la convención de fase decreciente
desfase_rad_invertido = [-phi for phi in desfase_rad]

# Crear el gráfico
plt.figure(figsize=(10, 6))
plt.semilogx(frecuencias_nuevas, desfase_rad_invertido, marker='o', linestyle='-', color='darkred', label='Fase')

# Líneas verticales: límites de banda de paso y rechazo
for f in [3600, 9100]:
    plt.axvline(f, color='green', linestyle='--', linewidth=1, label='Límite banda de paso en 3600Hz y 9100Hz' if f == 3600 else "")
for f in [5450, 5900]:
    plt.axvline(f, color='blue', linestyle='--', linewidth=1, label='Límite banda de rechazo en 5450Hz y 5900Hz' if f == 5450 else "")

# Configuración del gráfico
plt.title('Fase del Filtro Elimina-Banda')
plt.xlabel('Frecuencia [Hz]')
plt.ylabel('Fase [rad]')
plt.grid(which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.show()
