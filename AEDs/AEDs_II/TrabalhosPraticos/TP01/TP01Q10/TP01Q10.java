import TrabalhosPraticos.Lib;

// clear && javac -cp ../../.. TP01Q10.java && java -cp ../../.. TP01Q10.java < pub.in > result.txt

class TP01Q10 {

	static boolean isPalindromoRec(String palavra, int left, int right) {
		if (palavra.charAt(left) != palavra.charAt(right)) return false;
		return (left > right) ? true : isPalindromoRec(palavra, left + 1, right - 1);
	}

	static boolean isPalindromo(String palavra) {
		return	isPalindromoRec(palavra, 0, palavra.length() - 1);
	}

	public static void main(String[] args) {
		String str = Lib.getstr();
		while (!Lib.isEqual(str, "FIM")) {
			System.out.println(isPalindromo(str) ? "SIM" : "NAO");
			str = Lib.getstr();
		}
	}
}