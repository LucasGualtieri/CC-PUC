package AEDs.AEDs_II.Provas.EstudosExtras.Solitario;

import java.util.Scanner;

// clear && javac solitario.java && java solitario < pub.in > alun.out
public class solitario {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int N;

		while ((N = scanner.nextInt()) != 0) {
			int array[] = new int[N];

			for (int i = 0; i < N; i++) {
				array[i] = scanner.nextInt();
			}

			// Ordenando o Array
			for (int i = 0; i < N; i++) {
				int menor = i;
				for (int j = i + 1; j < N; j++) {
					if (array[menor] > array[j]) {
						menor = j;
					}
				}
				// Swapping
				int swap = array[menor];
				array[menor] = array[i];
				array[i] = swap;
			}

			System.out.println(array[N - 1]);
		}

		scanner.close();
	}
}
