import java.util.*;

class Ex7 {

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

	static void arrayConcat(int[] arrayUniao, int[] array1, int[] array2) {

		int i = 0;
		while (i < array1.length) {
			arrayUniao[i] = array1[i++];
		}
		int j = 0;
		while (j < array2.length) {
			arrayUniao[i++] = array2[j++];
		}
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		int[] array1 = { -123, 41, 62, 3 };
		int[] array2 = { 4000, 62, 561, -1323, 3 };

		int[] arrayUniao = new int[array1.length + array2.length];

		intArrayPrint(array1);
		intArrayPrint(array2);

		System.out.println("A união ordenada dos arrays sem repetições é:");

		arrayConcat(arrayUniao, array1, array2);
		sort(arrayUniao);

		System.out.print("{ ");
		int lastDifferent = arrayUniao[1];
		for (int i = 0; i < arrayUniao.length; i++) {
			if (lastDifferent != arrayUniao[i]) {
				System.out.printf("%d", arrayUniao[i]);
				System.out.printf("%s", i < arrayUniao.length - 1 ? ", " : " }\n");
				lastDifferent = arrayUniao[i];
			}
		}

		System.out.println("A interceção dos arrays sem repetições é:");

		System.out.print("{ ");
		for (int i = 0; i < array1.length; i++) {
			boolean hasAppeared = false;
			for (int j = 0; j < array2.length && !hasAppeared; j++) {
				if (array1[i] == array2[j]) {
					System.out.printf("%d", array1[i]);
					System.out.printf("%s", i < array1.length - 1 ? ", " : " }\n");
					hasAppeared = true;
				}
			}
		}

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		int[] array = { 7, 2, 25, 1, -50 };

		intArrayPrint(array);

		sort(array);

		intArrayPrint(array);

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite o tamanho do array: ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d°/%d inteiro: ", i + 1, size);
			array[i] = scanner.nextInt();
		}

		int menorIndex = 0, menor = Integer.MAX_VALUE;

		int currentIndex = 0;
		for (int num : array) {
			if (num < menor) {
				menorIndex = currentIndex;
				menor = num;
			}
			currentIndex++;
		}

		System.out.println("A posição do menor inteiro é: " + menorIndex);

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

		System.out.println("Ex7 letras a) -> c)\n");
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
