import java.util.*;

class Ex6 {

	static Scanner scanner = new Scanner(System.in);

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite um valor inteiro positivo: ");
		int N = scanner.nextInt();

		int i = 1;
		while (i <= N * 2) {
			System.out.println(i);
			i += 2;
		}

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		int i = 0;
		while (++i <= 10) {
			System.out.println(i);
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

		System.out.println("Ex3 letras a) -> c)\n");
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
