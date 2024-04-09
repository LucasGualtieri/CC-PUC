package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.TP01Q01;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.Lib;

// clear && javac -cp ../.. TP01Q01.java && java -cp ../.. TP01Q01.java < pub.in > result.txt

class TP01Q01 {

	/*
		- Retorna true ou false se a palavra for ou não um palíndromo.
		- Faço isso testando as extremidades da palavra até chegar no meio da palavra.
	*/
	static boolean isPalindromo(String palavra) {
		int len = palavra.length();

		for (int i = 0; i < len; i++) {
			if (palavra.charAt(i) != palavra.charAt(len - i - 1)) {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) {
		String str = Lib.getstr();
		while (!Lib.isEqual(str, "FIM")) {
			System.out.println(isPalindromo(str) ? "SIM" : "NAO");
			str = Lib.getstr();
		}
	}
}
