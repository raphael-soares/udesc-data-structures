#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int tail;
  int *v;
  int size;
} Queue;

Queue *criar(int tamanho) {
  Queue *pilha = malloc(sizeof(Queue));
  pilha->v = malloc(sizeof(int) * tamanho);
  pilha->size = tamanho;
  pilha->tail = 0;
}

int vazia(Queue *pilha) { return pilha->tail == 0; }

int cheia(Queue *pilha) { return pilha->tail == pilha->size; }

int peek(Queue *pilha) {
  if (!vazia(pilha)) {
    return pilha->v[pilha->tail - 1];
  } else {
    printf("Pilha vazia\n");
    exit(0);
  }
}

void add(Queue *pilha, int valor) {
  if (!cheia(pilha)) {
    pilha->v[pilha->tail++] = valor;
  } else {
    printf("Pilha cheia\n");
    exit(0);
  }
}

int remove(Queue *pilha) {
  if (!vazia(pilha)) {
    return pilha->v[--pilha->tail];
  }
}

int main() {
  Queue *pilha = criar(10);
  int valor = 1;

  while (!cheia(pilha)) {
    add(pilha, valor++);
  }

  while (!vazia(pilha)) {
    printf("%d\n", remove(pilha));
  }
}
