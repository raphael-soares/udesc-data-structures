#include <stdbool.h>
#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

int pair_sum(int vector[], int size, int number) {
  int sum = 0;

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if ((vector[i] + vector[j]) == number) {
        return 1;
      }
    }
  }

  return 0;
}

void test(int vector[], int size, int number, int expected) {
  int result = pair_sum(vector, size, number);
  if (result == expected) {
    printf(GREEN " PASS  k = %d\n" RESET, number);
  } else {
    printf(RED " FAIL  k = %d (expected %d, got %d)\n" RESET, number, expected,
           result);
  }
}

int main() {
  int v1[5] = {10, 15, 3, 7};
  test(v1, 5, 17, 1);

  int v2[4] = {-3, 9, 4, 1};
  test(v2, 4, 6, 1);

  int v3[2] = {0, 0};
  test(v3, 2, 0, 1);

  int v4[] = {1, 4, 4, 9};
  test(v4, sizeof(v4) / sizeof(v4[0]), 8, 1);

  int v5[] = {1, 2, 3, 9};
  test(v5, sizeof(v5) / sizeof(v5[0]), 15, 0);

  int v6[] = {7};
  test(v6, sizeof(v6) / sizeof(v6[0]), 14, 0);

  return 0;
}
