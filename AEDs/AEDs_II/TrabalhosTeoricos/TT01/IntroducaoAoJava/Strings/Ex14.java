import java.util.*;

class Ex14 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite uma string: ");
		String string = scanner.nextLine();

		System.out.print("Digite um caractere: ");
		char c = scanner.nextLine().charAt(0);

		int soma = 0;

		for (int i = 0; i < string.length(); i++) {
			if (string.charAt(i) == c) {
				soma++;
			}
		}

		System.out.printf("O caractere '%c' apareceu %d vezes\n", c, soma);

		scanner.close();
	}
}