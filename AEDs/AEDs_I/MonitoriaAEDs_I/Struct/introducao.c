#include <biblioteca_c.h>

typedef int* ints; // Theoldo tem isso no io.h

typedef struct Pessoa {
	char nome;
	int idade;
} Pessoa;

typedef Pessoa* PessoaRef;

void fn(PessoaRef ptrPessoa) {
	(*ptrPessoa).idade = 20;
}

int main() {

	Pessoa pessoa;

	fn(&pessoa);

	printf("Idade: %d\n", pessoa.idade);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}