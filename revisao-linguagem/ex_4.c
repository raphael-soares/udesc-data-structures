/*
Dado uma matriz quadrada m de números inteiros e de tamanho n, calcule a soma
as diagonais principal e secundária.
  ○ Exemplo, dado m = [
      [1, 2, 3, 4],
      [4, 3, 2, 1],
      [7, 8, 9, 6],
      [6, 5, 4, 3]
    ], a saída esperada é 16 e 20
*/

#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

typedef struct {
  int primary;
  int secondary;
} Diagonals;

Diagonals diagonals(int size, int matrix[size][size]) {
  Diagonals d = {0, 0};
  for (int i = 0; i < size; i++) {
    d.primary += matrix[i][i];
    d.secondary += matrix[i][size - 1 - i];
  }
  return d;
}

void test(Diagonals result, Diagonals expected) {

  if ((result.primary == expected.primary) &&
      (result.secondary == expected.secondary)) {
    printf(GREEN "PASS ");
    printf("(expected %d and %d got %d and %d)\n", expected.primary,
           expected.secondary, result.primary, result.secondary);
  } else {
    printf(RED "FAIL ");
    printf("(expected %d and %d got %d and %d)\n", expected.primary,
           expected.secondary, result.primary, result.secondary);
  }
}

int main() {

  test(diagonals(
           4,
           (int[4][4]){{1, 2, 3, 4}, {4, 3, 2, 1}, {7, 8, 9, 6}, {6, 5, 4, 3}}),
       (Diagonals){16, 20});

  test(diagonals(3, (int[3][3]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}),
       (Diagonals){15, 15});

  test(diagonals(3, (int[3][3]){{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}}),
       (Diagonals){-15, -15});

  test(diagonals(2, (int[2][2]){{10, 20}, {30, 40}}), (Diagonals){50, 50});

  test(diagonals(5, (int[5][5]){{1, 0, 0, 0, 2},
                                {0, 3, 0, 4, 0},
                                {5, 0, 6, 0, 7},
                                {0, 8, 0, 9, 0},
                                {10, 0, 0, 0, 11}}),
       (Diagonals){30, 30});

  return 0;
}
