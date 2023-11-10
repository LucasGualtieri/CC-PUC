package TT01.IntroducaoAoJava.Arrays;

import java.util.*;

class Ex8 {

	static Scanner scanner = new Scanner(System.in);

	static void intArrayPrint(int[] array) {
		System.out.print("{ ");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d", array[i]);
			System.out.printf("%s", i < array.length - 1 ? ", " : " }\n");
		}
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		System.out.print("Digite um número inteiro positivo: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		int soma = 0;
		for (int i = 0; i < size; i++) {
			array[i] = i + 1;
			soma += i + 1;
		}

		float media = soma / size;

		System.out.println("A média do seguinte array é: " + media);
		intArrayPrint(array);

		System.out.println("Os números acima da média são:");

		System.out.print("{ ");
		for (int i = 0; i < size; i++) {
			if (array[i] > media) {
				System.out.print(array[i] + " ");
			}
		}
		System.out.println("}");

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		int[] notas = new int[5];

		int soma = 0, menorNota = Integer.MAX_VALUE;

		for (int i = 0; i < 5; i++) {
			System.out.printf("Nota do %d° aluno: ", i + 1);
			notas[i] = scanner.nextInt();
			soma += notas[i];

			menorNota = Integer.min(notas[i], menorNota);
		}

		float media = soma / (float) 5;

		System.out.println("\nA soma das notas é: " + soma);
		System.out.println("A média da turma é: " + media);
		System.out.println("A menor nota é: " + menorNota);

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		int[] array = { 10, 5, 8, 2, 8 };

		intArrayPrint(array);

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
		} while ((invalid = choice < 0 || choice > 3));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex8 letras a) -> c)\n");
		System.out.println("0 - Sair do programa");
		System.out.println("1 - a)");
		System.out.println("2 - b)");
		System.out.println("3 - c)");
		System.out.print("Escolha uma das opções acima: ");

		int escolha = ReadingChoice();

		switch (escolha) {
			case 1:
				letraA();
				break;
			case 2:
				letraB();
				break;
			case 3:
				letraC();
				break;
		}

		return escolha != 0;
	}
}
