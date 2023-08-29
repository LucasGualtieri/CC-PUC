// clear && javac -cp ../../.. TP01Q05.java && java -cp ../../.. TP01Q05.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05 {

	static String[] ExpressionsStr(String str) {
		int expressionCount = 0;
		int len = str.length();

		int[] startOfExpressions = new int[10]; // 10 é um número arbitrário grande

		for (int i = 0; i < len; i++) {
			char c = str.charAt(i);
			if (c == 'a' || c == 'o' || c == '!') { // Achamos uma expressão
				startOfExpressions[expressionCount++] = i;
				// Agora precisamos skipar a expressão inteira.
				int openParentesesCount = 1;
				for (int j = i + 1; j < len; j++) {
					c = str.charAt(j);
					if (c == '(') openParentesesCount++;
					if (c == ')') openParentesesCount--;
					if (openParentesesCount == 0) {
						j = len; // jota é o fim da expressao
						startOfExpressions[expressionCount++] = j;
					}
				}
			} else if (c == '1' || c == '0') { // Achamos um termo { A, B ou C}
				startOfExpressions[expressionCount++] = i;
			}
		}

		String[] arrayOfExpressions = new String[expressionCount];
		// for (int i = 0; i < expressionCount; i++) {
		// 	arrayOfExpressions[i] = str.substring(startOfExpressions[i], startOfExpressions[i + 1]);
		// }

		System.exit(1);

		return arrayOfExpressions;

	}

	static boolean[] ExpressionsBool(String[] arrayOfExpressionsStr) {
		
		boolean[] arrayOfExpressionsBool = new boolean[arrayOfExpressionsStr.length];
		for (int i = 0; i < arrayOfExpressionsBool.length; i++) {
			arrayOfExpressionsBool[i] = searchForExpression(arrayOfExpressionsStr[i]);
		}

		return arrayOfExpressionsBool;

		// int indexOfParen = Lib.IndexOf(')', str) + 1;
		// String expressaoEsqStr = str.substring(0, indexOfParen);
		// String expressaoDirStr = str.substring(indexOfParen + 1);
		// boolean expressaoEsq = searchForExpression(expressaoEsqStr);
		// boolean expressaoDir = searchForExpression(expressaoDirStr);
		// // System.out.printf("expressaoEsq: %s\n", expressaoEsq);
		// // System.out.printf("expressaoDir: %s\n", expressaoDir);
	}

	static boolean OR(String str) {

		System.out.printf("Função OR: '%s'\n", str);

		return true;

		// char c = str.charAt(0);
		// if (c == '1' || c == '0') {
		// 	// System.out.println("Primeiro IF");
		// 	return Lib.ctobool(c) || Lib.ctobool(str.charAt(2));
		// }

		// int indexOfParen = Lib.IndexOf(')', str) + 1;
		// String expressaoEsqStr = str.substring(0, indexOfParen);
		// String expressaoDirStr = str.substring(indexOfParen + 1);
		// boolean expressaoEsq = searchForExpression(expressaoEsqStr);
		// boolean expressaoDir = searchForExpression(expressaoDirStr);

		// return expressaoEsq || expressaoDir;

	}

	static boolean AND(String str) {

		System.out.printf("Função AND: '%s'\n", str);
		boolean[] boolExpressions = ExpressionsBool(ExpressionsStr(str));

		return true;


		// boolean resultado = boolExpressions[0] && boolExpressions[1];
		// for (int i = 2; i < strExpressions.length i++) {
		// 	resultado = resultado && boolExpressions[i];
		// }

		// return resultado;

		// -------------------------------

		// char c = str.charAt(0);
		// if (c == '1' || c == '0') {
		// 	System.out.println("Primeiro IF");
		// 	return Lib.ctobool(c) && Lib.ctobool(str.charAt(2));
		// }

		// boolean resultado = expressao[0] && expressao[1];
		// for (int i = 2; i < ???; i++) {
		// 	resultado = resultado && expressao[i];
		// }
		// for (int i = 2; i < ???; i++) {
		// 	resultado = resultado && expressao[i];
		// }
		// Preciso achar uma forma de contar as expressões
		// ideia de ir contando os parenteses que vao se abrindo
		// e subtraindo nos parenteses que forem se fechando
		// cria um vetor com elas, e fazer as comparações dentro do for
		// no final das contas vou retornar "resultado"

		// Essa linha está dando pau "3 1 1 0 or(or(and(not(and(A , B)) , not(C)) , and(not(A) , B , C) , and(A , B , C) , and(A , not(B) , not(C))) , and(A , not(B) , C))"


		// return expressaoEsq && expressaoDir;

	}

	static boolean searchForExpression(String str) {

		System.out.printf("searchForExpression: '%s'\n", str);

		// Esse metodo inicia a busca e as chamadas recursivas
		// mas tbm precisa ser capaz de saber a hora de parar de buscar.

		// Talvez if (c == '/n' or c == /r) return something;

		char c = str.charAt(0);
		if (c == '1' || c == '0') {
			return Lib.ctobool(c);
		} else if (c == 'a') {
			return AND(str.substring(2));
		} else if (c == 'o') {
			return OR(str.substring(2));
		} else {
			System.out.println("NOT");
			return !searchForExpression(str.substring(2));
		}
	}

	static boolean algebraBooleana(String input) {
		
		char[] charArray = Lib.replaceAll(' ', "", input);
		charArray = Lib.replaceAll("and", 'a', charArray);
		charArray = Lib.replaceAll("or", 'o', charArray);
		charArray = Lib.replaceAll("not", '!', charArray);
		// System.out.printf("String: '%s'\n", Lib.toString(charArray));

		int N = Lib.ctoi(charArray[0]);
		
		// Substituindo os valores dos termos na String.
		for (int i = 0; i < N; i++) {
			char c = (char)('A' + i);
			char replace = charArray[i + 1];
			charArray = Lib.replaceAll(c, replace, charArray);
		}

		input = Lib.toString(charArray).substring(N + 1);
		// System.out.printf("String: '%s'\n", input);
		// System.out.printf("String: '%s'\n", Lib.toString(charArray));

		return searchForExpression(input);
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "FIM")) {
			System.out.println(algebraBooleana(input) ? 1 : 0);
		}
	}
}