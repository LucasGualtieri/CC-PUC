// clear && javac -cp ../../.. TP01Q04.java && java -cp ../../.. TP01Q04.java < pub.in > result.txt

import TrabalhosPraticos.Lib;
import java.util.Random;

class TP01Q04 {
	
	static Random gerador = new Random(4);

	static char randomChar() {
		return (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	}

	static String aleatorio(String input) {
		char baseChar = randomChar();
		char newChar = randomChar();

		String aux = new String();
		int len = input.length();
		for (int i = 0; i < len; i++) {
			char c = input.charAt(i);
			aux += c == baseChar ? newChar : c;
		}

		return aux;
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(aleatorio(input));
		}
	}
}
