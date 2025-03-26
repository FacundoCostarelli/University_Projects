/*
 * Queue.cpp
 *
 *  Created on: 8 dic 2024
 *      Author: Facundo Costarelli
 */

#include "Queue.h"




/* ESP
 * @brief Encola una tarea en la cola.
 *        Añade una tarea con datos asociados a la cola si hay espacio disponible.
 *
 * @param task Función de la tarea a encolar.
 * @param data Datos asociados a la tarea.
 * @return true si la tarea se encoló correctamente, false si la cola está llena.
 */
/* ENG
 * @brief Enqueues a task in the queue.
 *        Adds a task with associated data to the queue if there is space available.
 *
 * @param task Task function to enqueue.
 * @param data Data associated with the task.
 * @return true if the task was enqueued successfully, false if the queue is full.
 */

bool Queue::enqueue(TaskFunction task, uint32_t data) {
	// ESP: Verifico si hay espacio en la cola.
	// ENG: Check if there is space in the queue.
	if (count < QUEUE_SIZE) {

		// ESP: Encolo la tarea con los datos asociados.
		// ENG: Enqueue the task with the associated data.
		tasks[rear] = {task, data};

		// ESP: Actualizo el índice de la parte trasera de la cola (circular).
		// ENG: Update the rear index of the queue (circular).
		rear = (rear + 1) % QUEUE_SIZE;

		// ESP: Incremento el contador de elementos en la cola.
		// ENG: Increment the count of elements in the queue.
		count++;

		// ESP: Retorno true indicando que la tarea se encoló correctamente.
		// ENG: Return true indicating the task was enqueued successfully.
		return true;
	}

	// ESP: Retorno false si la cola está llena.
	// ENG: Return false if the queue is full.
	return false;
}




/* ESP
 * @brief Desencola una tarea de la cola.
 *        Remueve y devuelve la tarea en la parte frontal de la cola si hay elementos disponibles.
 *
 * @param task Referencia a la estructura Task donde se almacenará la tarea desencolada.
 * @return true si la tarea se desencoló correctamente, false si la cola está vacía.
 */
/* ENG
 * @brief Dequeues a task from the queue.
 *        Removes and returns the task at the front of the queue if there are elements available.
 *
 * @param task Reference to the Task structure where the dequeued task will be stored.
 * @return true if the task was dequeued successfully, false if the queue is empty.
 */

bool Queue::dequeue(Task& task) {
	// ESP: Verifico si hay elementos en la cola.
	// ENG: Check if there are elements in the queue
	if (count > 0) {
		// ESP: Obtengo la tarea en la parte frontal de la cola.
		// ENG: Get the task at the front of the queue.
		task = tasks[front];

		// ESP: Actualizo el índice de la parte frontal de la cola (circular).
		// ENG: Update the front index of the queue (circular).
		front = (front + 1) % QUEUE_SIZE;

		// ESP: Decremento el contador de elementos en la cola.
		// ENG: Decrement the count of elements in the queue.
		count--;

		// ESP: Retorno true indicando que la tarea se desencoló correctamente.
		// ENG: Return true indicating the task was dequeued successfully.
		return true;
	}

	// ESP: Retorno false si la cola está vacía.
	// ENG: Return false if the queue is empty.
	return false;
}




/* ESP
 * @brief Verifica si la cola está vacía.
 *
 * @return true si la cola está vacía, false en caso contrario.
 */
/* ENG
 * @brief Checks if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise.
 */

bool Queue::is_empty() {
	// ESP: Retorno true si no hay elementos en la cola.
	// ENG: Return true if there are no elements in the queue.
	return count == 0;
}




/* ESP
 * @brief Verifica si la cola está llena.
 *
 * @return true si la cola está llena, false en caso contrario.
 */
/* ENG
 * @brief Checks if the queue is full.
 *
 * @return true if the queue is full, false otherwise.
 */

bool Queue::is_full() {

	// ESP: Retorno true si la cola alcanzó su capacidad máxima.
	// ENG: Return true if the queue has reached its maximum capacity.
	return count == QUEUE_SIZE;
}




/* ESP
 * @brief Devuelve la cantidad de elementos en la cola.
 *
 * @return Número de elementos en la cola.
 */
/* ENG
 * @brief Returns the number of elements in the queue.
 *
 * @return Number of elements in the queue.
 */

uint8_t Queue::size() {
	// ESP: Retorno el número de elementos en la cola.
	// ENG: Return the number of elements in the queue
	return count;
}
