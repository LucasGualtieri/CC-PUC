package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoAoJava.Matrizes;

import java.util.*;

class Ex12 {

	static Scanner scanner = new Scanner(System.in);

	static void MatrixPrint(int[][] matriz, int colunas, int lin) {

		int[][] matrizAux = matriz;

		int maxElementWidth = 0;
		// Find the maximum width of matrix elements
		for (int i = 0; i < lin; i++) {
			for (int j = 0; j < colunas; j++) {
				int element = matrizAux[i][j];
				int elementWidth = 0;

				// Calculate the number of digits in the element
				while (element != 0) {
					element /= 10;
					elementWidth++;
				}

				if (elementWidth > maxElementWidth) {
					maxElementWidth = elementWidth;
				}
			}
		}

		for (int i = 0; i < colunas; i++) {
			for (int j = 0; j < matrizAux[i].length; j++) {
				String formattedValue = String.format("%" + maxElementWidth + "d", matrizAux[i][j]);
				System.out.print(formattedValue + " ");
			}
			System.out.println(); // Move to the next row
		}
		System.out.printf("\n");
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		System.out.print("Digite a quantidade de linhas: ");
		int linhas = scanner.nextInt();
		System.out.print("Digite a quantidade de colunas: ");
		int colunas = scanner.nextInt();

		int[][] matriz1 = new int[linhas][colunas];
		int[][] matriz2 = new int[linhas][colunas];
		int[][] matriz3 = new int[linhas][colunas];

		int contador = 1;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				matriz1[i][j] = contador;
				matriz2[i][j] = contador++;
			}
		}

		System.out.println();
		MatrixPrint(matriz1, linhas, colunas);

		MatrixPrint(matriz2, linhas, colunas);

		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
			}
		}

		MatrixPrint(matriz3, linhas, colunas);

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite a quantidade de linhas: ");
		int linhas = scanner.nextInt();
		System.out.print("Digite a quantidade de colunas: ");
		int colunas = scanner.nextInt();

		int[][] matriz = new int[linhas][colunas];

		int contador = 1;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				matriz[i][j] = contador++;
			}
		}

		System.out.println();
		MatrixPrint(matriz, linhas, colunas);

		// Transpondo a matriz

		int[][] matrizTransposta = new int[colunas][linhas];
		for (int i = 0; i < colunas; i++) {
			for (int j = 0; j < linhas; j++) {
				matrizTransposta[i][j] = matriz[j][i];
			}
		}

		System.out.println();
		MatrixPrint(matrizTransposta, linhas, colunas);

		System.out.println("---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite a quantidade de linhas: ");
		int linhas = scanner.nextInt();
		System.out.print("Digite a quantidade de colunas: ");
		int colunas = scanner.nextInt();

		int[][] matriz = new int[linhas][colunas];

		int contador = 1;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				matriz[i][j] = contador++;
			}
		}

		System.out.println();
		MatrixPrint(matriz, linhas, colunas);

		System.out.println("---------------------\n");
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

		System.out.println("Ex12 letras a) -> c)\n");
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
