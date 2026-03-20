/**
 * @file    RespuestasTeoricas.c
 * @brief   [ESP] Respuestas teóricas del 1er Parcial 2022.
 *          [ENG] Theoretical answers for the 1st Midterm 2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

/* 
 * [ESP] Respuestas Teóricas 
 * [ENG] Theoretical Answers
 * 
 * 1) 
 * [ESP] Según las siguientes declaraciones:
 * [ENG] According to the following declarations:
 * char cadena[10]="Info 1"; // array de char de tamaño 10, solo 6 ocupados por caracteres, resto \0
 * char *p=cadena;           // puntero simple apuntando al array
 *
 * [ESP] Indicar la salida en una arquitectura de 64bits:
 * [ENG] Indicate the output in a 64-bit architecture:
 *
 * printf("%li\n",sizeof(cadena)); // [ESP] 10 bytes [ENG] 10 bytes
 * printf("%li\n",strlen(cadena)); // [ESP] 6 caracteres [ENG] 6 characters
 * printf("%li\n",sizeof(p));      // [ESP] 8 bytes (tamaño de puntero) [ENG] 8 bytes (pointer size)
 * printf("%li\n",strlen(p));      // [ESP] 6 caracteres [ENG] 6 characters
 * printf("%li\n",sizeof(*p));     // [ESP] 1 byte (tamaño de un char) [ENG] 1 byte (char size)
 * 
 * 
 * 2) 
 * [ESP] Diferencia entre Unión y Estructura.
 * [ENG] Difference between Union and Structure.
 *
 * [ESP] - Estructura (struct): Permite agrupar variables de distintos tipos en un solo bloque. El tamaño
 *         total será la suma de todos sus miembros. Todos pueden almacenar valores a la vez.
 * [ENG] - Structure (struct): Allows grouping variables of different types. Total size is the sum of
 *         all members. All members can store values simultaneously.
 *
 * [ESP] - Unión (union): Comparte el mismo bloque de memoria para todos los miembros. El tamaño
 *         es igual al tamaño del miembro más grande. Sólo un miembro puede ser modificado y leído a
 *         la vez correctamente.
 * [ENG] - Union (union): Shares the same memory block for all members. The size matches the
 *         largest member. Only one member can be accurately stored/accessed at a time.
 */
