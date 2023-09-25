#include <biblioteca_c.h>

// Crie uma função que retorne uma pessoa.

typedef struct pessoa Pessoa;
typedef struct pessoa* PessoaPorReferencia;

struct pessoa {
	int idade, altura, pesso;
};

PessoaPorReferencia CriaPessoa() {
	PessoaPorReferencia ptrPessoa = malloc(sizeof(Pessoa)); // Idealmente convetemos o retorno do Malloc pro tipo que queremos (PessoaPorReferencia)malloc(sizeof(Pessoa));
	(*ptrPessoa).altura = 180;
	// ptrPessoa->altura = 180;

	return ptrPessoa;
}

int main() {

	PessoaPorReferencia pessoa = CriaPessoa();
	// pessoa* pessoa = CriaPessoa();

	printf("Altura: %d\n", pessoa->altura); // printf("Altura: %d\n", (*pessoa).altura);

	free(pessoa);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}