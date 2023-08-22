import TrabalhosPraticos.Lib;

// clear && javac -cp ../../.. TP01Q01.java && java -cp ../../.. TP01Q01.java < pub.in > result.txt

class TP01Q01 {

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
