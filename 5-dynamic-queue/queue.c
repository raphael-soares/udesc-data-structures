#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue *create() {
  Queue *queue = malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

int empty(Queue *queue) { return queue->head == NULL; }

void add(Queue *queue, int value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  if (empty(queue)) {
    queue->head = node;
    queue->tail = node;
  } else {
    queue->tail->next = node;
    queue->tail = node;
  }
}

int remover(Queue *queue) {
  if (empty(queue)) {
    return 0;
  }

  Node *node = queue->head;
  queue->head = node->next;
  int value = node->value;

  free(node);
  return value;
}

int main() {
  Queue *queue = create();

  int i = 0;
  while (i < 10) {
    add(queue, i);
    printf("added value %d \n", i++);
  }

  while (!empty(queue)) {
    int value = remover(queue);
    printf("deleted value %d \n", value);
  }

  return 0;
}
