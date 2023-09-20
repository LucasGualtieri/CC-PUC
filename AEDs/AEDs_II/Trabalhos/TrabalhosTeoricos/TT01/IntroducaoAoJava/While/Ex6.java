import java.util.*;

class Ex6 {

	static Scanner scanner = new Scanner(System.in);

	// 1 2 3 4 5 6 7
	// 1 1 2 3 5 8 13
	static int fib(int N) {
		return N == 1 || N == 0 ? N : fib(N - 1) + fib(N - 2);
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite um valor inteiro positivo: ");
		int N = scanner.nextInt();

		System.out.println("O " + N + "° termo de fibonacci é: " + fib(N));

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Nota máxima da prova: ");
		int notaMaxima = scanner.nextInt();

		int somaDasNotas = 0;
		int alunosAbaixoDaMedia = 0;
		int alunosConceitoA = 0;

		int i = -1;
		while (++i < 20) {
			float aluno = scanner.nextFloat();
			somaDasNotas += aluno;
			if (aluno < notaMaxima * 0.6) {
				alunosAbaixoDaMedia++;
			}
			if (aluno >= notaMaxima * 0.9) {
				alunosConceitoA++;
			}
		}

		System.out.println("A média da turma é: " + somaDasNotas / 20.0);
		System.out.println("Alunos abaixo da média: " + alunosAbaixoDaMedia);
		System.out.println("Alunos conceito A: " + alunosConceitoA);

		System.out.println("\n---------------------\n");
	}

	public static void main(String[] args) {
		while (optionsMenu()) {
			continue;
		}
	}

	static int ReadingChoice() {
		int choice;
		boolean invalid = false;

		do {
			if (invalid) {
				System.out.println("Valor inválido, tente novamente: ");
			}
			choice = scanner.nextInt();
		} while ((invalid = choice < 0 || choice > 2));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex6 letras a) -> c)\n");
		System.out.println("0 - Sair do programa");
		System.out.println("1 - a)");
		System.out.println("2 - b)");
		System.out.print("Escolha uma das opções acima: ");

		int escolha = ReadingChoice();

		switch (escolha) {
			case 1:
				letraA();
				break;
			case 2:
				letraB();
				break;
		}

		return escolha != 0;
	}
}
