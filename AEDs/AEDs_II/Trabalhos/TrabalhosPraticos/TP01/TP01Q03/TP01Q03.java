// clear && javac -cp ../../.. TP01Q03.java && java -cp ../../.. TP01Q03.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q03 {

	static final int UNKNOWN_CHAR = 65533; // Representa o caractere � presente no pub.in

	static String cifraDeCesar(String str, int chave) {
		return cifraDeCesarAux(str, chave);
	}

	static String cifraDeCesar(String str) {
		return cifraDeCesarAux(str, 3);
	}

	/*
		- Codifica uma string a partir de uma chave.
		- Por padrão, é sempre 3, mas pode ser passada pelo usuário.
		- Cada caractere é deslocado em chave posições na tabela ASCII.
		- Como no arquivo 'pub.in', temos caracteres em um CHARSET
		diferente e temos muitas ocorrências do caractere '�',
		foi necessário fazer algumas comparações extras.
	*/
	static String cifraDeCesarAux(String str, int chave) {
		String aux = "";
		int len = str.length();
		for (int i = 0; i < len; i++) {
			char c = str.charAt(i);
			aux += c == UNKNOWN_CHAR ? UNKNOWN_CHAR : (char)(c + chave);
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
