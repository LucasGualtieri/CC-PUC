// clear && javac -cp ../../.. TP01Q06.java && java -cp ../../.. TP01Q06.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q06 {

	// Retorna true se o caractere for vogal.
	static boolean isVowel(char c) {
		return Lib.isPresent(Lib.toLower(c), "aeiou");
	}

	// Retorna true se o caractere for consoante.
	static boolean isConsonant(char c) {
		return Lib.isPresent(Lib.toLower(c), "bcdfghjklmnpqrstvwxyz");
	}

	// Retorna true se a String possuir somente vogais.
	static boolean isAllVowels(String input) {
		boolean result = true;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			char c = input.charAt(i);
			if (!Lib.isAlpha(c) || isConsonant(c)) {
				result = false;
				i = len;
			}
		}
		return result;
	}

	// Retorna true se a String possuir somente consoantes.
	static boolean isAllConsonants(String input) {
		boolean result = true;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			char c = input.charAt(i);
			if (!Lib.isAlpha(c) || isVowel(c)) {
				result = false;
				i = len;
			}
		}
		return result;
	}

	// Retorna true se a String representar um número inteiro.
	static boolean isInteger(String input) {
		boolean result = true;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			if (!Lib.isNumber(input.charAt(i))) {
				result = false;
				i = len;
			}
		}
		return result;
	}

	// Retorna true se a String representar um número real.
	static boolean isFloatingPoint(String input) {
		boolean result = true;
		int len = input.length();
		int dotsCount = 0;
		input = Lib.replaceAll(',', '.', input);
		for (int i = 0; i < len; i++) {
			char c = input.charAt(i);
			if (c == '.' && ++dotsCount > 1) {
				result = false;
				i = len;
			} else if (!Lib.isNumber(c) && c != '.') {
				result = false;
				i = len;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.print(isAllVowels(input) ? "SIM " : "NAO ");
			System.out.print(isAllConsonants(input) ? "SIM " : "NAO ");
			System.out.print(isInteger(input) ? "SIM " : "NAO ");
			System.out.println(isFloatingPoint(input) ? "SIM" : "NAO");
		}
	}
}