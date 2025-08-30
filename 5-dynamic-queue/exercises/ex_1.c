#include "../queue.h"
#include <stdio.h>

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
