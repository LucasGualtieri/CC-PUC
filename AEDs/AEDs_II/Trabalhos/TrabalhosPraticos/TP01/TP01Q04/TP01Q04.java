package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.TP01Q04;

import java.util.Random;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.Lib;

// clear && javac -cp ../.. TP01Q04.java && java -cp ../.. TP01Q04.java < pub.in > result.txt

class TP01Q04 {
	
	static Random gerador = new Random(4);

	static char randomChar() {
		return (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	}

	/*
		- Escolhe aleatóriamente dois caracteres.
		- Recebe uma string e modifica todas as
		ocorrências do primeiro caractere pelo
		segundo caractere gerado.
	*/
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
