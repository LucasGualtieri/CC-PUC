// clear && javac -cp ../../.. TP01Q05.java && java -cp ../../.. TP01Q05.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05 {

	static boolean debugging = false;

	/*
		- Retorna o indice do fim da expressão atual
		- Retorna -1 se não houver mais expressões
	*/
	static int endOfCurExp(String str) {
		// if (debugging) System.out.printf("endOfCurExp: '%s'\n", str);

		int len = str.length();
		if (len == 0) return -1;

		int openParentesesCount = 0;
		int result = 1;
		for (int i = 0; i < len; i++) {
			char c = str.charAt(i);
			if (c == '(') openParentesesCount++;
			else if (c == ')' && --openParentesesCount == 0) {
				result = i + 1;
				i = len;
			}
		}
		if (Lib.substr(result, str).length() == 0) return -1;
		
		return result;
	}

	/*
		- Retorna o indice do começo da próxima expressão
		- Retorna -1 se não houver mais expressões
	*/
	static int startOfNextExp(String str) {
		return endOfCurExp(str) + 1;
	}

	/*
		- Retorna o resultado da operação -> termo atual || (Próximos N termos)
		- Se o termo é igual a '1' retorna true
		- Se o termo é igual a '0' retorna false || (Próximos N termos)
		- Faz os devidos redirecionamentos recursivos
	*/
	static boolean OR(String str) {

		if (debugging) System.out.printf("Função OR: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '1') return true;
		if (c == '0') return Lib.ctobool(c) || ORCompare(Lib.substr(2, str));
		return ORCompare(Lib.substr(0, endOfCurExp(str), str)) || ORCompare(Lib.substr(startOfNextExp(str), str)); //Maybe OR normal
	}

	/*
		- Identifica o termo atual e faz o redirecionamento recursivo necessário
		- Se houver mais termos faz uma comparação || (OR) com o termo atual
		e os próximos N termos seguintes.
		- Se o termo atual == '1' retorna true
		- Se houver próximos termos:
			- Se o termo atual == '0' retorna false || (Próximos N termos)
			- Se o termo atual == AND, OR ou NOT retorna o termo atual || (Próximos N termos)
		- Se não houver próximos termos:
			- Se o termo atual == '1' retorna true
			- Se o termo atual == AND, OR ou NOT retorna o resultado do termo atual
	*/
	static boolean ORCompare(String str) {
		if (debugging) System.out.printf("Função ORCompare: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(1, str.length() - 1, str);

		if (c == '1') return true;

		int indexEnd = endOfCurExp(Lib.substr(1, str));
		boolean hasNextExp = indexEnd > 0;
		if (debugging) System.out.printf("hasNextExp: %b\n", hasNextExp);

		if (c == '0') {
			if (!hasNextExp) return Lib.ctobool(c);
			return Lib.ctobool(c) || ORCompare(Lib.substr(2, str));
		}

		if (c == 'a') {
			if (debugging) System.out.println("c == 'a': " + str);
			if (!hasNextExp) return AND(Lib.substr(1, expressionString));
			return AND(Lib.substr(2, indexEnd, str)) || ORCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == 'o') {
			if (debugging) System.out.println("c == 'o': " + str);
			if (!hasNextExp) return OR(Lib.substr(1, expressionString));
			return OR(Lib.substr(2, indexEnd, str)) || ORCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == '!') {
			if (debugging) System.out.println("c == '!': " + str);
			if (!hasNextExp) return NOT(Lib.substr(1, expressionString));
			return NOT(Lib.substr(1, expressionString)) || ORCompare(Lib.substr(indexEnd + 2, str)); // + 1 pra start + 1 pelo !
		}

		return true; // Unreachable return

	}

	/*
		- Retorna o resultado da operação -> termo atual && (Próximos N termos)
		- Se o termo é igual a '0' retorna false
		- Se o termo é igual a '1' retorna true && (Próximos N termos)
		- Faz os devidos redirecionamentos recursivos
	*/
	static boolean AND(String str) {

		if (debugging) System.out.printf("Função AND: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '0') return false;
		if (c == '1') return Lib.ctobool(c) && ANDCompare(Lib.substr(2, str));
		return ANDCompare(Lib.substr(0, endOfCurExp(str), str)) && ANDCompare(Lib.substr(startOfNextExp(str), str));
	}

	/*
		- Identifica o termo atual e faz o redirecionamento recursivo necessário
		- Se houver mais termos faz uma comparação && (AND) com o termo atual
		e os próximos N termos seguintes.
		- Se o termo atual == '0' retorna false
		- Se houver próximos termos:
			- Se o termo atual == '1' retorna true && (Próximos N termos)
			- Se o termo atual == AND, OR ou NOT retorna o termo atual && (Próximos N termos)
		- Se não houver próximos termos:
			- Se o termo atual == '1' retorna true
			- Se o termo atual == AND, OR ou NOT retorna o resultado do termo atual
	*/
	static boolean ANDCompare(String str) {
		if (debugging) System.out.printf("Função ANDCompare: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(1, str.length() - 1, str);

		if (c == '0') return false;

		int indexEnd = endOfCurExp(Lib.substr(1, str));
		boolean hasNextExp = indexEnd > 0;
		if (debugging) System.out.printf("hasNextExp: %b\n", hasNextExp);

		if (c == '1') {
			if (!hasNextExp) return Lib.ctobool(c);
			return Lib.ctobool(c) && ANDCompare(Lib.substr(2, str));
		}

		if (c == 'a') {
			if (debugging) System.out.println("c == 'a': " + str);
			if (!hasNextExp) return AND(Lib.substr(1, expressionString));
			return AND(Lib.substr(2, indexEnd, str)) && ANDCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == 'o') {
			if (debugging) System.out.println("c == 'o': " + str);
			if (!hasNextExp) return OR(Lib.substr(1, expressionString));
			return OR(Lib.substr(2, indexEnd, str)) && ANDCompare(Lib.substr(indexEnd + 2, str));
		}
		
		if (c == '!') {
			if (debugging) System.out.println("c == '!': " + str);
			if (!hasNextExp) return NOT(Lib.substr(1, expressionString));
			return NOT(Lib.substr(1, expressionString)) && ANDCompare(Lib.substr(indexEnd + 2, str)); // + 1 pra start + 1 pelo !
		}

		return true; // Unreachable return

	}

	/*
		- Retorna true ou false se str.charAt(0) == '0' ou == '1'
		- Se str.charAt(0) != '0' ou == '1' nega o próximo redirecionamento
		recursivo chamando a função correspondente AND, OR ou NOT.
	*/
	static boolean NOT(String str) {

		if (debugging) System.out.printf("Função NOT: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '0' || c == '1') return !Lib.ctobool(c);
		return !searchForExpression(str);
	}

	/*
		- Recebe uma string contendo uma expressão Booleana já tratada.
		- Faz o primeiro redirecionamento recursivo chamando a função
		correspondente AND, OR ou NOT.
	*/
	static boolean searchForExpression(String str) {

		if (debugging) System.out.printf("searchForExpression: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(2, str.length() - 1, str);

		if (c == 'a') {
			return AND(expressionString);
		} else if (c == 'o') {
			return OR(expressionString);
		} else {
			if (debugging) System.out.println("NOT");
			return NOT(expressionString);
		}
	}

	/*
		- Recebe uma string contendo uma expressão Booleana.
		- Trata essa string:
			- Removendo os espaços
			- Substituindo os and's por a
			- Substituindo os or's por o
			- Substituindo os not's por !
			- Substituindo os valores das N variáveis,
			nas suas respectivas ocorrências na expressão.
		- Retorna o resultado da expressão.
	*/
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

		// Convertendo novamente para String.
		input = Lib.toString(charArray);
		// System.out.printf("String: '%s'\n", input);
		// System.out.printf("String: '%s'\n", Lib.toString(charArray));

		return searchForExpression(Lib.substr(N + 1, input));
	}

	public static void main(String[] args) {
		String input = new String();
		int i = 0;
		while((input = Lib.getstr()).charAt(0) != '0') {
			if (debugging) {
				System.out.printf("Resultado: %d°: %d\n", ++i, (algebraBooleana(input) ? 1 : 0));
			} else {
				System.out.println(algebraBooleana(input) ? 1 : 0);
			}
		}
	}
}