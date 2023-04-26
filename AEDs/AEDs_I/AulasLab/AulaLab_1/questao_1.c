#include <stdio.h>

/*
Autor - Lucas Gualtieri

*/

int main(void) {

  int numero = 10, fator = 3;

  printf("\nHello World\n\n");
  printf("O valor salvo na variável 'número' é %d\n", numero);
  printf("O resultado do cálculo (numero + 7) é %d\n", (numero + 7));
  printf("O resultado do cálculo (numero * fator) é %d\n", (numero * fator));
  printf("O valor salvo é %d na variável 'número' e %d na variável 'fator'\n", numero, fator);

  int a = 10, b = 20, c = 30;
  printf("\nA soma de A + B + C é %d\n\n", (a + b + c)); // A soma funciona sem os () mas é bom manter bons hábitos

  // Loop printf, 3 repetições
  for (int repeat = 0; repeat < 3; repeat++) {
    printf("Hello World\n");
  };

  return 0;
}