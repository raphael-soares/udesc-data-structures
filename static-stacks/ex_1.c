#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int top;
  int *v;
  int size;
} Stack;

Stack *create(int size) {
  Stack *stack = malloc(sizeof(Stack));
  stack->v = malloc(sizeof(int) * size);
  stack->size = size;
  stack->top = 0;

  return stack;
}

int is_empty(Stack *stack) { return stack->top == 0; }

int is_full(Stack *stack) { return stack->top == stack->size; }

int peek(Stack *stack) {
  if (!is_empty(stack)) {
    return stack->v[stack->top - 1];
  } else {
    printf("Pilha vazia\n");
    exit(0);
  }
}

void push(Stack *stack, int value) {
  if (!is_full(stack)) {
    stack->v[stack->top++] = value;
  } else {
    printf("Pilha cheia\n");
    exit(0);
  }
}

int pop(Stack *stack) {
  if (!is_empty(stack)) {
    return stack->v[--stack->top];
  }

  return stack->v[--stack->top];
}

int main() {
  Stack *stack = create(10);
  int value = 1;

  while (!is_full(stack)) {
    push(stack, value++);
  }

  while (!is_empty(stack)) {
    printf("%d\n", pop(stack));
  }
}
