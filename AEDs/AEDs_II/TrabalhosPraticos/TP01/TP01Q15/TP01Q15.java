// clear && javac -cp ../../.. TP01Q15.java && java -cp ../../.. TP01Q15.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q15 {

	static boolean isVowel(char c) {
		return Lib.isPresent(Lib.toLower(c), "aeiou");
	}

	static boolean isConsonant(char c) {
		return Lib.isPresent(Lib.toLower(c), "bcdfghjklmnpqrstvwxyz");
	}

	static boolean isAllVowels(String input, int len) {
		if (len == 0) return true;
		char c = input.charAt(len - 1);
		return (!Lib.isAlpha(c) || isConsonant(c)) ? false : isAllVowels(input, len - 1);
	}

	static boolean isAllConsonants(String input, int len) {
		if (len == 0) return true;
		char c = input.charAt(len - 1);
		return (!Lib.isAlpha(c) || isVowel(c)) ? false : isAllConsonants(input, len - 1);
	}

	static boolean isInteger(String input, int len) {
		if (len == 0) return true;
		char c = input.charAt(len - 1);
		return (!Lib.isNumber(c)) ? false : isInteger(input, len - 1);
	}

	static boolean isFloatingPoint(String input, int len, int dotsCount) {
		if (len == 0) return true;
		char c = input.charAt(len - 1);
		if (c == '.' && ++dotsCount > 1) return false;
		if (!Lib.isNumber(c) && c != '.') return false;
		return isFloatingPoint(input, len - 1, dotsCount);
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			int len = input.length();
			input = Lib.replaceAll(',', '.', input);
			System.out.print(isAllVowels(input, len) ? "SIM " : "NAO ");
			System.out.print(isAllConsonants(input, len) ? "SIM " : "NAO ");
			System.out.print(isInteger(input, len) ? "SIM " : "NAO ");
			System.out.println(isFloatingPoint(input, len, 0) ? "SIM" : "NAO");
		}
	}
}