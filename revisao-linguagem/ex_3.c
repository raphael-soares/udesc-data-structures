/*
Números primos são os números naturais que têm apenas dois divisores distintos: 1 e
ele mesmo. Faça um programa que solicite um número natural, em seguida, i
forme o número é primo ou não. 
  ○ Exemplo 1, dado o termo 23, a saída esperada é sim. 
  ○ Exemplo 2, dado o termo 77, a saída esperada é não
*/

#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

int is_prime(int number) {
  int is_prime = 1;
  for (int i = 2; i < number; i++){
    if (number % i == 0){
      is_prime = 0;
    }
  }
  return is_prime;
}

void test(int number, int expected) {
  int result = is_prime(number);
  if (result == expected) {
    printf(GREEN "is_prime(%d) ",number );
    printf("PASS \n" RESET);
  } else {
    printf(RED "is_prime(%d) ",number );
    printf("FAIL ");
    printf("(expected %d got %d)\n", expected, result);
  }
}

int main() {
  test(23, 1);
  test(77, 0);
  test(11, 1);
  test(12, 0);

  return 0;
}
