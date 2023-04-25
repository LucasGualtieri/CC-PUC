import java.util.Scanner;

class palindromo {

	public static boolean Palindromo(String nome) {
		String reversedString = "";

		for (int i = 0; i < nome.length(); i++) {
			reversedString = nome.charAt(i) + reversedString;
		}

		for (int i = nome.length() - 1, j = 0; i > 0; i--) {
			if (nome.charAt(i) == nome.charAt(j)) {
				j++;
			} else {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String entrada = scanner.nextLine();

		while (!entrada.equals("FIM")) {

			if (Palindromo(entrada)) {
				System.out.println("SIM");
			} else {
				System.out.println("NAO");
			}

			entrada = scanner.nextLine();
		}

		scanner.close();
	}
}
