package TT01.IntroducaoAoJava.Arrays;

import java.util.*;

class Ex11 {

	static Scanner scanner = new Scanner(System.in);

	static void intArrayPrint(int[] array) {
		System.out.print("{ ");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d", array[i]);
			System.out.printf("%s", i < array.length - 1 ? ", " : " }\n");
		}
	}

	static void sort(int[] array) {
		for (int i = 0; i < array.length - 1; i++) {
			int menor = i;
			for (int j = i + 1; j < array.length; j++) {
				if (array[j] < array[menor]) {
					menor = j;
				}
			}
			int aux = array[i];
			array[i] = array[menor];
			array[menor] = aux;
		}
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		System.out.print("Digite um tamanho: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		System.out.println("Preencha o vetor");
		for (int i = 0; i < size; i++) {
			System.out.printf("%d° valor: ", i + 1);
			array[i] = scanner.nextInt();
		}

		sort(array);
		intArrayPrint(array);

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite um tamanho: ");
		int size1 = scanner.nextInt();
		System.out.print("Digite outro tamanho: ");
		int size2 = scanner.nextInt();

		int[] array1 = new int[size1];
		int[] array2 = new int[size2];

		for (int i = 0; i < size1; i++) {
			array1[i] = i + 1;
		}
		for (int i = 0; i < size2; i++) {
			array2[i] = -(i + 1);
		}

		int maior, menor;
		int[] arrayMaior, arrayMenor;

		if (size1 > size2) {
			maior = size1;
			arrayMaior = array1;
			menor = size2;
			arrayMenor = array2;
		} else {
			maior = size2;
			arrayMaior = array2;
			menor = size1;
			arrayMenor = array1;
		}

		System.out.print("{ ");
		for (int i = 0; i < maior; i++) {
			if (i < menor) {
				System.out.printf("%d,", arrayMenor[i]);
			}
			System.out.printf(" %d", arrayMaior[i]);
			System.out.printf("%s", i < maior - 1 ? ", " : " }\n");
		}

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite um tamanho: ");
		int size = scanner.nextInt();

		int[] array1 = new int[size];
		int[] array2 = new int[size];

		for (int i = 0; i < size; i++) {
			array1[i] = i + 1;
			array2[i] = -(i + 1);
		}

		System.out.print("{ ");
		for (int i = 0; i < size; i++) {
			System.out.printf("%d, %d", array1[i], array2[i]);
			System.out.printf("%s", i < size - 1 ? ", " : " }\n");
		}

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
		} while ((invalid = choice < 0 || 3 < choice));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex11 letras a) -> c)\n");
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
