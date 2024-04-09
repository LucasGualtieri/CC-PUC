package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoAoJava.If_Else;

import java.util.*;

class Ex1 {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite os lados A, B e C (respectivamente): ");
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int C = scanner.nextInt();

		if (A == B && B == C) {
			System.out.println("Equilátero");
		} else if (A != B && B != C && C != A) {
			System.out.println("Escaleno");
		} else {
			System.out.println("Isósceles");
		}

		scanner.close();
	}
}
