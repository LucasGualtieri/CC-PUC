package AEDs.AEDs_II.AulasLab.Aquecimento.PalindromoEmJava;

import java.util.*;

// clear && javac palindromoEmJava.java && java palindromoEmJava < pub.in > alun.out

class PalindromoEmJava {

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