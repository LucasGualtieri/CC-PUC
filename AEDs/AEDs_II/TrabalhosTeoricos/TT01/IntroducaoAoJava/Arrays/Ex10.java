import java.util.*;

class Ex10 {

	static Scanner scanner = new Scanner(System.in);

	static void intArrayPrint(int[] array) {
		System.out.print("{ ");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d", array[i]);
			System.out.printf("%s", i < array.length - 1 ? ", " : " }\n");
		}
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite um número inteiro e positivo: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = i + 1;
		}

		intArrayPrint(array);

		int soma = 0;

		int aux;
		for (int i = 0; i < size / 2; i++) {
			aux = array[i];
			if (aux % 3 == 0) {
				soma += aux;
			}
		}

		System.out.println("Soma dos múltiplos de 3: " + soma);

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

		for (int i = 0; i < size / 2; i++) {
			System.out.printf("%d + %d = %d\n", array[i], array[size - 1 - i], array[i] + array[size - 1 - i]);
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
		} while ((invalid = choice < 0 || choice > 2));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex10 letras a) -> b)\n");
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
