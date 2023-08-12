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

	static void letraC() {

		System.out.println("\nLetra b):\n");

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

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

		for (int i = 0; i < size; i++) {
			System.out.printf("%d, %d", array1[i], array1[i]);
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
