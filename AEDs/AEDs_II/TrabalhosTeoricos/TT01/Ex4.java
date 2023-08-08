import java.util.*;

class Ex3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite o valor de N (Tamanho do arranjo): ");
		int size = scanner.nextInt();

		int[] array1 = new int[size];
		int[] array2 = new int[size];

		for (int i = 0; i < size; i++) {
			System.out.print("Array N° 1 elemento " + (i + 1) + ": ");
			array1[i] = scanner.nextInt();
			System.out.print("Array N° 2 elemento " + (i + 1) + ": ");
			array2[i] = scanner.nextInt();
		}

		System.out.println("A união dos dois arranjos é: ");
		System.out.println("A intercessão dos dois arranjos é: ");

		scanner.close();
	}
}