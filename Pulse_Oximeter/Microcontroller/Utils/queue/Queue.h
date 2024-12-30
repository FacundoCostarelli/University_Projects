#include <LPC845.h>
#define QUEUE_SIZE 50

typedef void (*TaskFunction)(uint32_t);

// Nueva estructura para manejar tareas con datos asociados
struct Task {
    TaskFunction function; // Puntero a la función a ejecutar
    uint32_t data;         // Datos asociados a la tarea
};

class Queue {
   private:
	Task tasks[QUEUE_SIZE];  // Array circular para almacenar tareas
    uint8_t front = 0;               // Índice del frente de la cola
    uint8_t rear = 0;                // Índice del final de la cola
    uint8_t count = 0;               // Cantidad de elementos en la cola

   public:
    // Encola una tarea
    bool enqueue(TaskFunction task, uint32_t data);

    // Desencola una tarea
    bool dequeue(Task& task);

    // Verifica si la cola está vacía
    bool is_empty();

    // Verifica si la cola está llena
    bool is_full();

    // Devuelve la cantidad de elementos en la cola
    uint8_t size();
};
