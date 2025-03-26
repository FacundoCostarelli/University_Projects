/*
 * Queue.h
 *
 *  Created on: 8 dic 2024
 *      Author: Facundo Costarelli
 */

/* ESP
 * @brief Este archivo define una cola circular para gestionar tareas que incluyen una función y datos asociados.
 *        La cola tiene un tamaño fijo y permite encolar, desencolar y verificar su estado (vacía, llena, etc.).
 *
 *      **Definiciones**
 *
 *      QUEUE_SIZE:         Tamaño máximo de la cola, definido como 50.
 *
 *      **Estructuras**
 *
 *      Task:               Estructura que representa una tarea en la cola.
 *                          - function: Puntero a la función que se ejecutará como parte de la tarea.
 *                          - data:     Datos asociados a la tarea, que se pasarán a la función.
 *
 *      **Clase Queue**
 *
 *      **Variables Privadas**
 *
 *      tasks:              Array circular que almacena las tareas en la cola.
 *      front:              Índice que apunta al frente de la cola (primer elemento).
 *      rear:               Índice que apunta al final de la cola (último elemento).
 *      count:              Número de elementos actualmente en la cola.
 *
 *      **Métodos Públicos**
 *
 *      enqueue(TaskFunction task, uint32_t data):
 *                          Método para encolar una tarea. Recibe un puntero a la función y los datos asociados.
 *                          Devuelve `true` si la tarea se encoló correctamente, o `false` si la cola está llena.
 *
 *      dequeue(Task& task):
 *                          Método para desencolar una tarea. Recibe una referencia a una estructura `Task` donde
 *                          se almacenará la tarea desencolada. Devuelve `true` si la tarea se desencoló correctamente,
 *                          o `false` si la cola está vacía.
 *
 *      is_empty():         Método que devuelve `true` si la cola está vacía, o `false` en caso contrario.
 *
 *      is_full():          Método que devuelve `true` si la cola está llena, o `false` en caso contrario.
 *
 *      size():             Método que devuelve el número de elementos actualmente en la cola.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file defines a circular queue for managing tasks that include a function and associated data.
 *        The queue has a fixed size and allows enqueueing, dequeueing, and checking its state (empty, full, etc.).
 *
 *      **Definitions**
 *
 *      QUEUE_SIZE:         Maximum size of the queue, defined as 50.
 *
 *      **Structures**
 *
 *      Task:               Structure representing a task in the queue.
 *                          - function: Pointer to the function to be executed as part of the task.
 *                          - data:     Data associated with the task, which will be passed to the function.
 *
 *      **Class Queue**
 *
 *      **Private Variables**
 *
 *      tasks:              Circular array that stores the tasks in the queue.
 *      front:              Index pointing to the front of the queue (first element).
 *      rear:               Index pointing to the rear of the queue (last element).
 *      count:              Number of elements currently in the queue.
 *
 *      **Public Methods**
 *
 *      enqueue(TaskFunction task, uint32_t data):
 *                          Method to enqueue a task. Takes a pointer to the function and the associated data.
 *                          Returns `true` if the task was enqueued successfully, or `false` if the queue is full.
 *
 *      dequeue(Task& task):
 *                          Method to dequeue a task. Takes a reference to a `Task` structure where the dequeued
 *                          task will be stored. Returns `true` if the task was dequeued successfully, or `false`
 *                          if the queue is empty.
 *
 *      is_empty():         Method that returns `true` if the queue is empty, or `false` otherwise.
 *
 *      is_full():          Method that returns `true` if the queue is full, or `false` otherwise.
 *
 *      size():             Method that returns the number of elements currently in the queue.
 *
 * @param None
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <LPC845.h>

#define QUEUE_SIZE 50

typedef void (*TaskFunction)(uint32_t);

struct Task {
    TaskFunction function;
    uint32_t data;
};

class Queue {
   private:
	Task tasks[QUEUE_SIZE];
    uint8_t front = 0;
    uint8_t rear = 0;
    uint8_t count = 0;

   public:
    bool enqueue(TaskFunction task, uint32_t data);
    bool dequeue(Task& task);
    bool is_empty();
    bool is_full();
    uint8_t size();
};

#endif /* QUEUE_H_ */
