import java.util.*;

class Ex13 {

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

	static void letraD() {

		System.out.println("\nLetra d):\n");

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

		for (int i = 0; i < colunas; i++) {
			int soma = 0;
			for (int j = 0; j < linhas; j++) {
				soma += matriz[j][i];
			}
			float media = (float) soma / (float) (colunas);
			System.out.printf("A média dos elementos da linha %d é: %.2f\n", i, media);
		}

		System.out.println("\n---------------------\n");
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

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

		for (int i = 0; i < linhas; i++) {
			int soma = 0;
			for (int j = 0; j < colunas; j++) {
				soma += matriz[i][j];
			}
			float media = (float) soma / (float) (linhas);
			System.out.printf("A média dos elementos da linha %d é: %.2f\n", i, media);
		}

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite a quantidade de linhas e colunas: ");
		int size = scanner.nextInt();

		int[][] matriz = new int[size][size];

		int contador = 1;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matriz[i][j] = contador++;
			}
		}

		System.out.println();
		MatrixPrint(matriz, size, size);

		int soma = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				soma += matriz[i][j];
			}
		}

		// ............rows e cols
		float media = (float) soma / (float) (size * size);

		System.out.println("A média dos elementos da matriz é: " + media);

		System.out.println("---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite a quantidade de linhas e colunas: ");
		int size = scanner.nextInt();

		int[][] matriz = new int[size][size];

		int contador = 1;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matriz[i][j] = contador++;
			}
		}

		System.out.println();
		MatrixPrint(matriz, size, size);

		System.out.println("A diagonal principal é composta por: ");
		System.out.print("{ ");
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					System.out.printf("%d", matriz[i][j]);
					System.out.printf("%s", i < size - 1 ? ", " : " }\n");
				}
			}
		}

		System.out.println("A diagonal secundária é composta por: ");
		System.out.print("{ ");
		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j < size; j++) {
				System.out.printf("%d", matriz[i][j - i]);
				System.out.printf("%s", i < size - 1 ? ", " : " }\n");
			}
		}

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
		} while ((invalid = choice < 0 || choice > 4));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex13 letras a) -> d)\n");
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
