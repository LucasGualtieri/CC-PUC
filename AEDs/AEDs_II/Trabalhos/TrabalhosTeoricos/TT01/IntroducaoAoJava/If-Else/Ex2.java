import java.util.*;

class Ex2 {

	static Scanner scanner = new Scanner(System.in);

	static void letraD() {

		System.out.println("\nLetra d):\n");

		System.out.print("Qtd de gols do mandante: ");
		int M = scanner.nextInt();
		System.out.print("Qtd de gols do visitante: ");
		int V = scanner.nextInt();

		if (M > V) {
			System.out.println("O mandante ganhou!");
		} else if (V > M) {
			System.out.println("O visitante ganhou!");
		} else {
			System.out.println("Deu empate");
		}

		System.out.println("\n---------------------\n");
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		System.out.print("1° valor inteiro: ");
		int X = scanner.nextInt();
		System.out.print("2° valor inteiro: ");
		int Y = scanner.nextInt();

		if (X > 45 || Y > 45) {
			System.out.println(X + Y);
		} else if (X > 20 && Y > 20) {
			System.out.println(X > Y ? X - Y : Y - X);
		} else if ((X < 10 && Y != 0) || (Y < 10 && X != 0)) {
			System.out.println(Y != 0 ? X / Y : Y / X);
		} else {
			System.out.println("Lucas Gualtieri");
		}

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		int maior = Integer.MIN_VALUE;

		for (int i = 0; i < 10; i++) {
			System.out.print(10 - i + "° valor inteiro: ");
			int value = scanner.nextInt();
			if (value > maior) {
				maior = value;
			}
		}

		System.out.println("\nMaior valor é " + maior);
		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		int[] array = new int[3];

		for (int i = 0; i < array.length; i++) {
			System.out.print(i + 1 + "° valor inteiro: ");
			array[i] = scanner.nextInt();
		}

		int A = array[0], B = array[1], C = array[2];
		int maior, menor;

		if (A > B && A > C) {
			maior = A;
			menor = B < C ? B : C;
		} else if (B > A && B > C) {
			maior = B;
			menor = A < C ? A : C;
		} else {
			maior = C;
			menor = A < B ? A : B;
		}

		System.out.println("\nMaior valor é " + maior);
		System.out.println("Menor valor é " + menor);
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
		} while ((invalid = choice < 0 || choice > 4));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex2 letras a) -> d)\n");
		System.out.println("0 - Sair do programa");
		System.out.println("1 - a)");
		System.out.println("2 - b)");
		System.out.println("3 - c)");
		System.out.println("4 - d)");
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
			case 4:
				letraD();
				break;
		}

		return escolha != 0;
	}
}