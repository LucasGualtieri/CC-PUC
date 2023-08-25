// clear && javac -cp ../../.. TP01Q01.java && java -cp ../../.. TP01Q01.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q03 {
	static String cifraDeCesar(String str, int chave) {
		return cifraDeCesarAux(str, chave);
	}

	static String cifraDeCesar(String str) {
		return cifraDeCesarAux(str, 3);
	}

	static String cifraDeCesarAux(String str, int chave) {
		String aux = "";
		int len = str.length();
		for (int i = 0; i < len; i++) {
			aux += (char)(str.charAt(i) + chave);
		}
		return aux;
	}

	public static void main(String[] args) {
		String input = "";
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(cifraDeCesar(input));
		}
	}
}
