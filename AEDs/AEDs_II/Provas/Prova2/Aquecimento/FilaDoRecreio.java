package AEDs.AEDs_II.Provas.Prova2.Aquecimento;

import java.util.*;

class FilaDoRecreio {
	
	static Scanner scanner = new Scanner(System.in);
	
	static void swap(int x, int y, int[] array) {
		int aux = array[x];
		array[x] = array[y];
		array[y] = aux;
	}

	static int SelectionSort(int[] array) {

		int alunosDesordenados = 0;

		for (int i = 0; i < array.length - 1; i++) {
			int maior = i;
			for (int j = i + 1; j < array.length; j++) {
				if (array[maior] < array[j]) maior = j;
			}
			if (maior != i) {
				alunosDesordenados += 2;
				swap(maior, i, array);
			}
		}

		return array.length - alunosDesordenados;

	}

	public static void main(String[] args) {

		int casosDeTeste = scanner.nextInt();

		for (int i = 0; i < casosDeTeste; i++) {
			int numeroDeAlunos = scanner.nextInt();
			int[] notas = new int[numeroDeAlunos];
			for (int j = 0; j < numeroDeAlunos; j++) {
				notas[j] = scanner.nextInt();
			}
			System.out.println(SelectionSort(notas));
		}
	}
}