package TT01.IntroducaoAoJava.If_Else;

import java.util.*;

class Ex3 {

	static Scanner scanner = new Scanner(System.in);

	static void letraC() {

		System.out.println("\nLetra c):\n");

		int[] array = new int[10];
		int maior = Integer.MIN_VALUE;
		int menor = Integer.MAX_VALUE;

		for (int i = 0; i < array.length; i++) {
			System.out.print(10 - i + "° valor inteiro: ");
			array[i] = scanner.nextInt();
			if (array[i] > maior) {
				maior = array[i];
			}
			if (array[i] < menor) {
				menor = array[i];
			}
		}

		System.out.println("\nMaior valor é " + maior);
		System.out.println("Menor valor é " + menor);

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("1° valor real");
		float X = scanner.nextFloat();
		System.out.print("2° valor real");
		float Y = scanner.nextFloat();

		float menor = X < Y ? X : Y;

		System.out.println(Math.pow(menor, 3));
		System.out.println(Math.log(X) / Math.log(Y));

		System.out.println("\n---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Valor do salário bruto: ");
		double salario = scanner.nextDouble();
		System.out.print("Valor da prestação: ");
		double prestacao = scanner.nextDouble();

		if (prestacao < salario * 0.4) {
			System.out.println("Empréstimo será concedido!");
		} else {
			System.out.println("Empréstimo não será concedido!");
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

		System.out.println("Ex3 letras a) -> c)\n");
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