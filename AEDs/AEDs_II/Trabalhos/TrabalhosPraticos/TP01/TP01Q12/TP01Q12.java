package TP01.TP01Q12;

// clear && javac -cp ../.. TP01Q12.java && java -cp ../.. TP01Q12.java < pub.in > result.txt

import TP01.Lib;

class TP01Q12 {

	static final int UNKNOWN_CHAR = 65533; // Representa o caractere � presente no pub.in

	static String cifraDeCesar(String str, int chave) {
		return cifraDeCesarRec(str, 0, str.length() - 1, chave);
	}

	static String cifraDeCesar(String str) {
		return cifraDeCesarRec(str, 0, str.length() - 1, 3);
	}

	/*
		- Codifica uma string a partir de uma chave.
		- Por padrão, é sempre 3, mas pode ser passada pelo usuário.
		- Cada caractere é deslocado em chave posições na tabela ASCII.
		- Como no arquivo 'pub.in', temos caracteres em um CHARSET
		diferente e temos muitas ocorrências do caractere '�',
		foi necessário fazer algumas comparações extras.
	*/
	static String cifraDeCesarRec(String str, int index, int len, int chave) {
		char c = str.charAt(index);
		char cifrado = (c == UNKNOWN_CHAR) ? UNKNOWN_CHAR : (char)(c + chave);
		if (index == len) return new String() + cifrado;
		return cifrado + cifraDeCesarRec(str, index + 1, len, chave);
	}

	public static void main(String[] args) {
		String input = "";
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(cifraDeCesar(input));
		}
	}
}
