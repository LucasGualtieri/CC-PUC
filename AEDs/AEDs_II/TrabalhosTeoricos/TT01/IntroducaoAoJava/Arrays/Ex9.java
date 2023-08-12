import java.util.*;

class Ex9 {

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

		System.out.print("Digite um número inteiro e positivo: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = i + 1;
		}

		intArrayPrint(array);

		int pares = 0, divPor3 = 0;

		for (int i = 0; i < size; i++) {
			if (array[i] % 2 == 0) {
				pares++;
			}
			if (array[i] % 3 == 0) {
				divPor3++;
			}
		}

		System.out.println("O número de números pares é: " + pares);
		System.out.println("O número de divisíveis por 3 é: " + divPor3);

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite um número inteiro e positivo: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		int menorIndice = 0, menor = Integer.MAX_VALUE;

		for (int i = 0; i < size; i++) {
			System.out.printf("%d° inteiro: ", i + 1);
			array[i] = scanner.nextInt();

			if (array[i] < menor) {
				menor = array[i];
				menorIndice = i;
			}
		}

		intArrayPrint(array);

		System.out.print("A posição do menor elemento é: " + menorIndice);

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite um número inteiro e positivo: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = i + 1;
		}

		intArrayPrint(array);

		if (size % 2 == 0) {
			for (int i = 0; i < size; i++) {
				System.out.printf("%d + %d = %d\n", array[i], array[i + 1], array[i] + array[++i]);
			}
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
		} while ((invalid = choice < 0 || choice > 3));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex9 letras a) -> c)\n");
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
