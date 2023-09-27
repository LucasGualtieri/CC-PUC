#include <stdio.h>
// #include "jogador.h"
// #include "fila.h"

typedef struct Jogador {

	int id, altura, peso, anoNascimento;
	String nome;
	String universiade;
	String cidadeNascimento;
	String estadoNascimento;

	int (*getId) (struct Jogador);
	int (*getAltura) (struct Jogador);
	int (*getPeso) (struct Jogador);
	int (*getAnoNascimento) (struct Jogador);
	String (*getNome) (struct Jogador);
	String (*getUniversidade) (struct Jogador);
	String (*getCidadeNascimento) (struct Jogador);
	String (*getEstadoNascimento) (struct Jogador);

} Jogador;

int main() {

	// Fila BD = newFila(40); // Tamanho de entradad do Pub.in



	// BD.printPlayer(0, BD);
	// BD.print(BD);
	// BD.close(&BD);

}