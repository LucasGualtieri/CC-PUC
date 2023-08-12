import java.util.*;

class Ex0 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite o valor de N (Tamanho do arranjo): ");
		int size = scanner.nextInt();

		int[] array = new int[size];

		int soma = 0;
		for (int i = 0; i < size; i++) {
			System.out.print("Inteiro N° " + (i + 1) + ": ");
			array[i] = scanner.nextInt();
			soma += array[i];
		}

		float media = (float) soma / (float) size;

		for (int i = 0; i < size; i++) {
			if (array[i] > media) {
				System.out.println(array[i] + " está acima da média.");
			}
		}

		scanner.close();
	}
}
