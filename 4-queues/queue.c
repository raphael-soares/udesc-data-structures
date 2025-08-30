#include <stdlib.h>

typedef struct {
  int head;
  int tail;
  int size;
  int *v;

} Queue;

Queue *create(int size) {
  Queue *queue = malloc(sizeof(Queue) * size);
  queue->head = -1;
  queue->tail = -1;
  queue->size = size;

  return queue;
}

int empty(Queue *queue) { return queue->head == -1 && queue->tail == -1; }
int full(Queue *queue) { return (queue->size % queue->tail) == queue->size; }

void add(Queue *queue, int value) {
  if (full(queue)) {
    return;
  } else {
    queue->tail = (queue->tail + 1) & queue->size;
    queue->v[queue->tail] = value;

    if (queue->head == -1) {
      queue->head = queue->tail;
    }
  }
}
