/*
Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
elemento no índice i seja o produto de todos os números na matriz original, com
exceção de i.
  ○ Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
  ○ Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]
*/

#include <stdio.h>
#include <stdlib.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

int *vector_items_product(int vector[/* size */], int size) {
  int *product_vector = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {

    int multi = 1;
    for (int j = 0; j < size; j++) {
      if (i != j) {
        multi = multi * vector[j];
      }
    }

    product_vector[i] = multi;
    multi = 1;
  }

  return product_vector;
}

void print_vector(int vector[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
}

void test(int result[], int size, int expected[]) {
  int error = 0;

  for (int i = 0; i < size; i++) {
    if (result[i] != expected[i]) {
      error = 1;
    }
  }

  if (!error) {
    printf(GREEN " PASS \n" RESET);
  } else {
    printf(RED " FAIL ");
    printf("(expected [");
    print_vector(expected, 3);
    printf("] got [");
    print_vector(result, 3);
    printf("] ) \n" RESET);
  }
}

void run_test(int input[], int size, int expected[]) {
  int *result = vector_items_product(input, size);
  test(result, size, expected);
  free(result);
}

int main() {
  run_test((int[]){3, 2, 1}, 3, (int[]){2, 3, 6});
  run_test((int[]){2, 5}, 2, (int[]){5, 2});
  run_test((int[]){-1, 2, -3}, 3, (int[]){-6, 3, -2});
  run_test((int[]){1, 2, 0, 4}, 4, (int[]){0, 0, 8, 0});

  return 0;
}
