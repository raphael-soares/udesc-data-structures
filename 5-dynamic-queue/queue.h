#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  struct Node *next;
  int value;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int *v;
} Queue;

Queue *create();
int empty(Queue *queue);
void add(Queue *queue, int value);
int remover(Queue *queue);

#endif
