/*
Run-length encoding (RLE) é uma forma simples de compressão de textos. A ideia
desta técnica é representar caracteres repetidos sucessivamente com um contador
seguido pelo caractere. Dada uma string, retorne o texto resultante da aplicação
da técnica RLE.

  ○ Exemplo, dada a string "AAAABBBCCDAA", a saída compactada deve ser
  "4A3B2C1D2A"
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void append(char *dest, const char *src) {
  int len_dest = strlen(dest);
  int len_src = strlen(src);
  strcpy(dest + len_dest, src); 
}

char *run_lenght_econding(char *str) {
  size_t string_size = strlen(str);
  char *new_string = calloc(string_size * 10, 1); // zera tudo

  for (int i = 0; i < string_size; i++) {
    int qtd_occour = 0;
    char current_letter = str[i];

    for (int j = i; j < string_size; j++) {
      if (str[j] != current_letter) {
        break;
      }

      qtd_occour++;
    }
    if (qtd_occour == 0) {
      qtd_occour = 1;
    }

    char temp[12];
    sprintf(temp, "%d", qtd_occour);
    append(new_string, temp);
    append(new_string, &current_letter);
  }
  char char_str[2] = {'\0'};
  append(new_string, char_str);

  return new_string;
}

void test(char input[], char expected[]) {
  char *result = run_lenght_econding(input);
  int error = strcmp(result, expected) != 0;

  if (!error) {
    printf(GREEN " PASS \n" RESET);
  } else {
    printf(RED "given %s FAIL expected %s, got %s " RESET, input, expected,
           result);
  }
}

int main() {
  test("AAAABBBCCDAA", "4A3B2C1D2A");
  return 0;
}
