package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoAoJava.Strings;

import java.util.*;

class Ex15 {
	static boolean onlyDigits(String string) {
		for (int i = 0; i < string.length(); i++) {
			if (string.charAt(i) < '0' || '9' < string.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite uma string: ");
		String string = scanner.nextLine();

		System.out.println(onlyDigits(string) ? "SIM" : "NAO");

		scanner.close();
	}
}