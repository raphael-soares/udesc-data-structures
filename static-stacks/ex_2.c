#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char word[] = "arara";
  int word_size = strlen(word);
  Stack *stack = create(word_size);

  for (int i = 0; i < word_size; i++) {
    push(stack, word[i]);
  }

  for (int i = 0; i < word_size; i++) {
    if (word[i] != pop(stack)) {
      printf("Not a palindrome \n");
      return 0;
    } else {
      printf("Is a palindrome \n");
      return 0;
    }
  }
}
