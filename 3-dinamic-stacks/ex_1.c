#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node *previous;
  int value;
} Node;

typedef struct {
  Node *top;
  int *v;
} Stack;

Stack *create() {
  Stack *stack = malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

int is_empty(Stack *stack) { return stack->top == NULL; }

void push(Stack *stack, int value) {
  Node *node = malloc(sizeof(Node));
  node->previous = stack->top;
  node->value = value;
  stack->top = node;
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    return 0;
  }
  Node *node = stack->top;
  stack->top = node->previous;
  int value = node->value;
  free(node);
  return value;
}

int peek(Stack *stack) {
  if (is_empty(stack)) {
    printf("The stack is empty\n");
    exit(0);
  }

  return stack->top->value;
}

int match(char *input, char symbol) {

  Stack *stack = create();
  int size = strlen(input);

  for (int i = 0; i < size; i++) {
    if (input[i] == symbol) {
      push(stack, 1);
    } else {
      if (is_empty(stack)) {
        return 0;
      }
      pop(stack);
    }
  }

  return is_empty(stack);
}

int main() {

  char input[] = "[[][]]";
  char symbol = '[';

  int bol = match(input, symbol);
  printf(" %d ", bol);

  return 0;
}
