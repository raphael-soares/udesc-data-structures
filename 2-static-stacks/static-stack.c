
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int *v;
  int size;
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

int main() {
  char word[] = "arara";
  int word_size = strlen(word);
  Stack *stack = create();

  for (int i = 0; i < word_size; i++) {
    push(stack, word[i]);
  }

  for (int i = 0; i < word_size /2; i++) {
    if (word[i] != pop(stack)) {
      printf("Not a palindrome \n");
      break;
    } else {
      printf("Is a palindrome \n");
      break;
    }
  }


  return 0;
}
