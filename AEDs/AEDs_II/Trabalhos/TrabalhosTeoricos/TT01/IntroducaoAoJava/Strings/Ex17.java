package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoAoJava.Strings;

import java.util.*;

class Ex17 {

	public static boolean isPalin(String input) {
		StringBuilder reversed = new StringBuilder(input);
		return input.equals(reversed.reverse().toString());
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String input;

		while (!(input = scanner.nextLine()).equals("FIM")) {
			System.out.println(isPalin(input) ? "SIM" : "NAO");
		}

		scanner.close();
	}
}