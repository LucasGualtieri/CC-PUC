import java.util.Scanner;

// clear && javac biblioteca.java && java biblioteca < pub.in > alun.out
public class biblioteca {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNextLine()) {
			int N = Integer.parseInt(scanner.nextLine());

			// Criando o Array
			String[] array = new String[N];

			// Montando o Array
			for (int i = 0; i < N; i++) {
				array[i] = scanner.nextLine();
			}

			// Ordenando o Array
			for (int i = 0; i < N; i++) {
				int menor = i;
				for (int j = i + 1; j < N; j++) {
					if (Integer.parseInt(array[menor]) > Integer.parseInt(array[j])) {
						menor = j;
					}
				}
				// Swapping
				String swap = array[menor]; // Menor valor do array na iteração
				array[menor] = array[i];
				array[i] = swap;
			}

			// Printando o Array
			for (int i = 0; i < N; i++) {
				System.out.println(array[i]);
			}
		}

		scanner.close();
	}
}
