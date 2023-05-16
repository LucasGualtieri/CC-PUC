package Java;

import java.util.Scanner;

// clear && javac sweeper.java && java sweeper < pub.in > out.txt

class sweeper {
	public static class Matrix {

	};

	public static int adjacentes(int rows, int columns, int matrix[][], int iLin, int jCol) {

		int adjacente = 0;

		// ----------- Testando topo -----------
		try {
			if (matrix[iLin - 1][jCol] == 1) {
				// System.out.println("--X--");
				adjacente++;
			}
		} catch (Exception e) {
		}

		// ----------- Testando lados -----------
		try {
			// Testando esquerda
			if (matrix[iLin][jCol - 1] == 1) {
				// System.out.println("--X--");
				adjacente++;
			}
		} catch (Exception e) {
		}

		try {
			// Testando direita
			if (matrix[iLin][jCol + 1] == 1) {
				// System.out.println("--X--");
				adjacente++;
			}
		} catch (Exception e) {
		}

		// ----------- Testando embaixo -----------
		try {
			if (matrix[iLin + 1][jCol] == 1) {
				// System.out.println("--X--");
				adjacente++;
			}
		} catch (Exception e) {
		}

		// System.out.println("\nadjacente: " + adjacente);

		return adjacente;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string = new String();

		do {

			string = scanner.nextLine();
			int rows = Integer.parseInt(string);
			string = scanner.nextLine();
			int columns = Integer.parseInt(string);

			int matrix[][] = new int[rows][columns];

			// Montando a matriz
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					string = scanner.nextLine();
					matrix[i][j] = Integer.parseInt(string);
				}
			}

			// Printando a matriz
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (matrix[i][j] == 1) {
						System.out.print(9);
					} else {
						int adjacentes = adjacentes(rows, columns, matrix, i, j);
						if (adjacentes > 0) {
							System.out.print(adjacentes);
						} else {
							System.out.print(0);
						}
					}
				}
				System.out.println();
			}
		} while (!string.equals("FIM"));

		scanner.close();
	}
}