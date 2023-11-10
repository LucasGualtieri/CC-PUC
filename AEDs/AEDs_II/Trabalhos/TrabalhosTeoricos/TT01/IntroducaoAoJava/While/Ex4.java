package TT01.IntroducaoAoJava.While;

import java.util.*;

class Ex4 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int soma = 0;

		for (int i = 0; i < 5; i++) {
			System.out.print("Nota do aluno " + (i + 1) + ": ");
			soma += scanner.nextInt();
		}

		System.out.println("A média dos 5 alunos é: " + soma / (float) 5);

		scanner.close();
	}
}
