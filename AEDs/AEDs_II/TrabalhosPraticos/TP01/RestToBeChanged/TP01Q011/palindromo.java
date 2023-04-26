import java.util.Scanner;

// clear && javac palindromo.java && java palindromo < pub.in > out.txt

public class palindromo {
	public static boolean isPalindromo(String string, int comeco, int fim) {
		if (comeco >= fim) {
			return true;
		}

		if (string.charAt(comeco) != string.charAt(fim)) {
			return false;
		}

		return isPalindromo(string, ++comeco, --fim);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String string = scanner.nextLine();

		while (!string.equals("FIM")) {
			if (isPalindromo(string, 0, string.length() - 1)) {
				System.out.println("SIM");
			} else {
				System.out.println("NAO");
			}

			string = scanner.nextLine();
		}

		scanner.close();
	}
}