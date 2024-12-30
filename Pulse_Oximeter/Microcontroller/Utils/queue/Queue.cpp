/*
 * Queue.cpp
 *
 *  Created on: 8 dic 2024
 *      Author: facun
 */
#include "Queue.h"

bool Queue::enqueue(TaskFunction task, uint32_t data) {
	if (count < QUEUE_SIZE) {
		tasks[rear] = {task, data}; // Encola la tarea con datos asociados
		rear = (rear + 1) % QUEUE_SIZE;
		count++;
		return true;
	}
	return false;  // Cola llena
}

// Desencola una tarea
bool Queue::dequeue(Task& task) {
	if (count > 0) {
		task = tasks[front];
		front = (front + 1) % QUEUE_SIZE;
		count--;
		return true;
	}
	return false;  // Cola vacía
}

// Verifica si la cola está vacía
bool Queue::is_empty() { return count == 0; }

// Verifica si la cola está llena
bool Queue::is_full() { return count == QUEUE_SIZE; }

// Devuelve la cantidad de elementos en la cola
uint8_t Queue::size() { return count; }
