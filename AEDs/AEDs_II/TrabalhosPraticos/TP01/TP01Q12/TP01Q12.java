import TrabalhosPraticos.Lib;

// clear && javac -cp ../../.. TP01Q12.java && java -cp ../../.. TP01Q12.java < pub.in > result.txt

class TP01Q12 {

	static final int UNKNOWN_CHAR = 65533;

	static String cifraDeCesar(String str, int chave) {
		return cifraDeCesarRec(str, 0, str.length() - 1, chave)
	}

	static String cifraDeCesar(String str) {
		return cifraDeCesarRec(str, 0, str.length() - 1, 3);
	}
	
	static String cifraDeCesarRec(String str, int index, int len, int chave) {
		String aux = "";
		char c = str.charAt(index);
		char cifrado = (c == UNKNOWN_CHAR) ? UNKNOWN_CHAR : (char)(c + chave);
		if (index == len) return String() += cifrado;
		return aux += cifrado + cifraDeCesarRec(str, index + 1, len, chave);
	}

	public static void main(String[] args) {
		String input = "";
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(cifraDeCesar(input));
		}
	}
}
