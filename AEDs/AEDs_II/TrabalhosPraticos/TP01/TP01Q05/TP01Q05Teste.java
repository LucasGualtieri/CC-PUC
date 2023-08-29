// clear && javac -cp ../../.. TP01Q05Teste.java && java -cp ../../.. TP01Q05Teste.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05Teste {

	static boolean teste(String str) {


		// System.out.printf("Função AND: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			// System.out.println("Primeiro IF");
			return Lib.ctobool(c) && Lib.ctobool(str.charAt(2));
		}
		
		System.out.printf("teste: '%s'\n", str);

		int indexOfParen = Lib.IndexOf(')', str) + 1;
		String expressaoEsqStr = str.substring(0, indexOfParen);
		String expressaoDirStr = str.substring(indexOfParen + 1);

		boolean expressaoEsq = searchForExpression(expressaoEsqStr);
		boolean expressaoDir = searchForExpression(expressaoDirStr);

		if (Lib.isEqual(str.substring(0, 3), "and")) {
			return expressaoEsq && expressaoDir;
		} else if (Lib.isEqual(str.substring(0, 2), "or")) {
			return expressaoEsq || expressaoDir;
		} else if (Lib.isEqual(str.substring(0, 3), "not")) {
			return !(expressaoEsq || expressaoDir);
		}

		return false; // Teoricamente esse é um return "sentinela"

	}

	static boolean searchForExpression(String str) {

		System.out.printf("searchForExpression: '%s'\n", str);

		// Esse metodo inicia a busca e as chamadas recursivas
		// mas tbm precisa ser capaz de saber a hora de parar de buscar.

		// Talvez if (c == '/n' or c == /r) return something;

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			System.out.println("IF");
			return Lib.ctobool(c);
		} else {
			System.out.println("ELSE");
			return teste(str);
		}

		// return true; // Teoricamente esse é um return "sentinela"
	}

	static boolean algebraBooleana(String input) {
		
		char[] charArray = Lib.replaceAll(' ', "", input);

		int N = Lib.ctoi(charArray[0]);
		
		// Substituindo os valores dos termos na String.
		for (int i = 0; i < N; i++) {
			char c = (char)('A' + i);
			char replace = charArray[i + 1] == '1' ? '1' : '0';
			charArray = Lib.replaceAll(c, replace, charArray);
		}

		input = Lib.toString(charArray).substring(3);
		// System.out.printf("String: '%s'\n", input);

		return searchForExpression(input);
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(algebraBooleana(input) ? 1 : 0);
		}
	}
}
