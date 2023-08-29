#include <stdio.h>
#include <stdlib.h>
#include "listaLinear.h"

// clear && gcc -o listaLinear listaLinear.c && ./listaLinear

int somaLista(Lista lista) {
	int soma = 0;
	for (int i = 0; i < lista.size; i++) {
		soma += lista.array[i];
	}
	return soma;
}

int maiorLista(Lista lista) {
	int maior = lista.array[0];
	for (int i = 1; i < lista.size; i++) {
		if (lista.array[i] > maior) maior = lista.array[i];
	}
	return maior;
}

void inverteLista(Lista* lista) {
	for (int i = 0; i < lista->size / 2; i++) {
		int aux = lista->array[i];
		lista->array[i] = lista->array[lista->size - i - 1];
		lista->array[lista->size - i - 1] = aux;
	}
}

int paresMultiDe5(Lista lista) {
	int contador = 0;
	for (int i = 0; i < lista.size; i++) {
		if (lista.array[i] % 2 == 0 && lista.array[i] % 5 == 0) contador ++;
	}
	return contador;
}

int main () {

	puts("==== LISTA LINEAR ====\n");

	Lista lista = newLista(6);
	
	lista.InserirInicio(1, &lista);
	lista.InserirFim(7, &lista);
	lista.InserirFim(9, &lista);
	lista.InserirInicio(3, &lista);
	lista.Inserir(8, 3, &lista);
	lista.Inserir(4, 2, &lista);
	lista.Mostrar(lista);

    int x1, x2, x3;
    
    x1 = lista.RemoverInicio(&lista);
    x2 = lista.RemoverFim(&lista);
    x3 = lista.Remover(2, &lista);
    
    printf("%d, %d, %d\n", x1, x2, x3);
    
	lista.Mostrar(lista);

	printf("A soma de todos os elementos da lista é: %d\n", somaLista(lista));
	printf("O maior elemento da lista é: %d\n", maiorLista(lista));
	printf("A lista invertida é:\n");
	inverteLista(&lista);
	lista.Mostrar(lista);

	printf("A quantidade de pares múltiplos de 5 é: %d\n", paresMultiDe5(lista));
}