#include <stdio.h>

// clear && gcc StructForaDoScopo.c && ./a.out

typedef struct Pessoa {
	int idade;
	char sexo;
} Pessoa;

void AlteraPessoa(Pessoa* pessoa) {

	Pessoa p1;

	pessoa = &p1;

	pessoa->idade = 25;
	pessoa->sexo = 'F';

	printf("pessoa.idade: %d\n", pessoa->idade);
	printf("pessoa.sexo: %c\n", pessoa->sexo);
}

int main() {

	Pessoa pessoa = { 20, 'M' };

	AlteraPessoa(&pessoa);

	printf("-----------------\n");

	printf("pessoa.idade: %d\n", pessoa.idade);
	printf("pessoa.sexo: %c\n", pessoa.sexo);

	return 0;
}