# Libraries — Funciones Utilitarias Reutilizables en C

Colección de bibliotecas de funciones reutilizables en C desarrolladas durante **Informática 1** en la **UTNBA (2022)**. Cada subcarpeta es un módulo autocontenido organizado por tema.

## Módulos

| Módulo | Archivos | Descripción |
|---|---|---|
| **Strings/** | `my_strings.c/h`, `main.c` | Manipulación de strings: copiar, comparar, tokenizar, longitud, etc. |
| **Sorting/** | `my_sorting.c/h`, `main.c` | Algoritmos de ordenamiento: burbuja, selección, inserción, etc. |
| **LinkedLists/** | `lists.h`, `singly_linked.c`, `doubly_linked.c`, `queue.c`, `stack.c`, `factorial_recursive.c` | Listas enlazadas, colas, pilas y funciones recursivas |
| **Matrix/** | `matrix_ops.c` | Creación, transposición, multiplicación y visualización de matrices |
| **FileIO/** | `file_copy.c`, `file_rename.c`, `file_open_filter.c`, `bin_file_rw.c`, `bin_read_int32.c` | Copia, renombrado, lectura/escritura binaria, lectura con filtrado |
| **Math/** | `math_funcs.c` | Funciones matemáticas utilitarias |
| **Bitwise/** | `bit_ops.c` | Utilidades de operaciones a nivel de bits |
| **Encryption/** | `string_encrypt.c` | Funciones de encriptación y desencriptación de strings |
| **Conversion/** | `itostr_strtol.c` | Conversiones entero-a-string (`itoa`) y string-a-long (`strtol`) |
| **Signals/** | `signals_example.c`, `signal_handling.c` | Ejemplos y utilidades de manejo de señales UNIX |
| **Networking/** | `sock_lib.c/h`, `ServerClient/` | Biblioteca de sockets e implementación servidor-cliente |
| **Misc/** | `char_num_bits_random.c`, `reverse_array.c`, `bubble_sort.c` | Utilidades varias independientes |

## Uso

Cada módulo puede compilarse de forma independiente con GCC. Para módulos con archivo de prueba `main.c`:

```bash
gcc -o test my_strings.c main.c -Wall
./test
```
