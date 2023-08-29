// clear && javac -cp ../../.. TP01Q05.java && java -cp ../../.. TP01Q05.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05 {

	static boolean OR(String str) {

		System.out.printf("Função OR: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			// System.out.println("Primeiro IF");
			return Lib.ctobool(c) || Lib.ctobool(str.charAt(2));
		}

		int indexOfParen = Lib.IndexOf(')', str) + 1;
		String expressaoEsqStr = str.substring(0, indexOfParen);
		String expressaoDirStr = str.substring(indexOfParen + 1);
		boolean expressaoEsq = searchForExpression(expressaoEsqStr);
		boolean expressaoDir = searchForExpression(expressaoDirStr);

		return expressaoEsq || expressaoDir;

	}

	static boolean AND(String str) {

		System.out.printf("Função AND: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			System.out.println("Primeiro IF");
			return Lib.ctobool(c) && Lib.ctobool(str.charAt(2));
		}

		// boolean resultado = expressao[0] && expressao[1];
		// for (int i = 2; i < ???; i++) {
		// 	resultado = resultado && expressao[i];
		// }
		// Preciso achar uma forma de contar as expressões
		// ideia de ir contando os parenteses que vao se abrindo
		// e subtraindo nos parenteses que forem se fechando
		// cria um vetor com elas, e fazer as comparações dentro do for
		// no final das contas vou retornar "resultado"

		// Essa linha está dando pau "3 1 1 0 or(or(and(not(and(A , B)) , not(C)) , and(not(A) , B , C) , and(A , B , C) , and(A , not(B) , not(C))) , and(A , not(B) , C))"

		int indexOfParen = Lib.IndexOf(')', str) + 1;
		String expressaoEsqStr = str.substring(0, indexOfParen);
		String expressaoDirStr = str.substring(indexOfParen + 1);
		boolean expressaoEsq = searchForExpression(expressaoEsqStr);
		boolean expressaoDir = searchForExpression(expressaoDirStr);
		// System.out.printf("expressaoEsq: %s\n", expressaoEsq);
		// System.out.printf("expressaoDir: %s\n", expressaoDir);

		return expressaoEsq && expressaoDir;

	}

	static boolean searchForExpression(String str) {

		System.out.printf("searchForExpression: '%s'\n", str);

		// Esse metodo inicia a busca e as chamadas recursivas
		// mas tbm precisa ser capaz de saber a hora de parar de buscar.

		// Talvez if (c == '/n' or c == /r) return something;

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			return Lib.ctobool(c);
		} else if (Lib.isEqual(str.substring(0, 3), "and")) {
			return AND(str.substring(4));
		} else if (Lib.isEqual(str.substring(0, 2), "or")) {
			return OR(str.substring(3));
		} else {
			System.out.println("NOT");
			return !searchForExpression(str.substring(4));
		}

		// return true;
	}

	static boolean algebraBooleana(String input) {
		
		char[] charArray = Lib.replaceAll(' ', "", input);
		System.out.printf("String: '%s'\n", Lib.toString(charArray));
		charArray = Lib.replaceAll("and", 'a', charArray);
		System.out.printf("String: '%s'\n", Lib.toString(charArray));
		return true;
		// // charArray = Lib.replaceAll("or", 'o', charArray);
		// // charArray = Lib.replaceAll("not", 'n', charArray);

		// int N = Lib.ctoi(charArray[0]);
		
		// // Substituindo os valores dos termos na String.
		// for (int i = 0; i < N; i++) {
		// 	char c = (char)('A' + i);
		// 	char replace = charArray[i + 1];
		// 	charArray = Lib.replaceAll(c, replace, charArray);
		// }

		// input = Lib.toString(charArray).substring(N + 1);
		// // System.out.printf("String: '%s'\n", input);

		// return searchForExpression(input);
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(algebraBooleana(input) ? 1 : 0);
		}
	}
}