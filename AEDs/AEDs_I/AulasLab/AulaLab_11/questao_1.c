#include <stdio.h>

/*
	Escreva um programa que leia um vetor G de 20 caracteres que representa o gabarito de
	uma prova. A seguir, para cada um dos alunos de uma turma, leia o vetor de vetorRespostas(R)
	e conte	o número de acertos. Mostre a nota do aluno e uma mensagem APROVADO, se a nota for
	>= a 6 ou REPROVADO, caso contrário. Cada questão correta vale 0,5 ponto.
*/

int main(void) {
	int numQuestoes = 0, questoesCertas = 0;
	char charRespostas, charGabarito;

	FILE* gabarito = fopen("gabarito.txt", "r");
	FILE* respostasFile = fopen("respostas.txt", "r");

	while (!feof(gabarito)) {
		fscanf(respostasFile, "%c", &charRespostas);
		fscanf(gabarito, "%c", &charGabarito);
		if (charRespostas == charGabarito || charRespostas == charGabarito + 32) {
			questoesCertas++;
		}
		fgetc(respostasFile), fgetc(gabarito);
		numQuestoes++;
	}

	float porcentagem = (100.0 * questoesCertas) / numQuestoes;

	printf("Nota: %g/%g\n", questoesCertas * 0.5, 0.5 * numQuestoes);
	printf("Questões certas: %d/%d\n", questoesCertas, numQuestoes);
	printf("Porcentagem de acerto: %.2f%%\n", porcentagem);

	if (porcentagem >= 60) {
		printf("Status: Aprovado!");
	} else if (porcentagem >= 40) {
		printf("Status: Recuperação");
	} else {
		printf("Status: Reprovado");
	}

	printf("\n\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}