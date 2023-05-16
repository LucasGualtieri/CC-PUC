#include <biblioteca_c.h>

typedef struct pessoa Pessoa; // Opcional -> Pessoa ciclano;

struct pessoa { // struct pessoa fulano;
	int idade, altura;
} globalPessoa;

// Juntando a declaração do Struct com o typedef
typedef struct pessoa2 { // pessoa2 é o nome da declaração do Struct
	int idade, peso;
} Pessoa2; // Pessoa2 é o nome usado para declarar objetos do tipo pessoa2

int main() {

	struct pessoa fulano;
	fulano.idade = 20;
	fulano.altura = 170;

	Pessoa ciclano;
	ciclano.idade = 21;
	ciclano.altura = 185;

	Pessoa2 beltrano;
	beltrano.idade = 23;
	beltrano.peso = 80;

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}