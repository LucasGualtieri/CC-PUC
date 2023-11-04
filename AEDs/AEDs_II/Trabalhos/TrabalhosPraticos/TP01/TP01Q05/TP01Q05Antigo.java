package TP01.TP01Q05;

import TP01.Lib;

// clear && javac -cp ../.. TP01Q05.java && java -cp ../.. TP01Q05.java < pub.in > result.txt

class TP01Q05 {

	static boolean debugging = true;

	static int indexOfNextExp(String str) {
		if (debugging) System.out.println("indexOfNextExp: " + str);
		if (debugging) System.out.print("indexOfNextExp: ");
		int len = str.length();
		int openParentesesCount = 0;
		int result = 0;
		for (int i = 0; i < len; i++) {
			char c = str.charAt(i);
			if (c == '(') openParentesesCount++;
			else if (c == ')' && --openParentesesCount == 0) {
				result = i + 2;
				i = len;
			} 
		}
		// if (debugging) System.out.println("result: " + result);
		if (debugging) System.out.println("str.substring(result).length() == 0: " + (str.substring(result).length() == 0));
		if (str.substring(result).length() == 0) return -1;
		return result;
	}

	// static int indexOfNextExp(String str) {
	// 	System.out.println("indexOfNextExp: " + str);
	// 	int len = str.length();
	// 	int openParentesesCount = 1;
	// 	int result = 0;
	// 	for (int i = 0; i < len; i++) {
	// 		char c = str.charAt(i);
	// 		if (c == '(') openParentesesCount++;
	// 		else if (c == ')' && --openParentesesCount == 0) {
	// 			result = i;
	// 			i = len;
	// 		} 
	// 	}
	// 	// System.out.println("result: " + result);
	// 	return result - 1;
	// }

	static boolean OR(String str) {

		if (debugging) System.out.printf("Função OR: '%s'\n", str);

		char c = str.charAt(0);
		// String nextComp = 
		if (c == '1') return true;
		else if (c == '0') {
			if (debugging) System.out.printf("Função OR: else if (c == '0')\n");
			return Lib.ctobool(c) || ORCompare(str.substring(2));
		} else {
			int indexOfNextExpVal = indexOfNextExp(str);
			boolean hasNextExp = indexOfNextExpVal > 0;
			if (!hasNextExp) return OR(str.substring(2));
			return searchForExpression(str) || ORCompare(str.substring(indexOfNextExpVal));
		}
	}

	static boolean ORCompare(String str) {
		if (debugging) System.out.printf("Função ORCompare: '%s'\n", str);

		int indexOfNextExpVal = indexOfNextExp(str);
		boolean hasNextExp = indexOfNextExpVal > 0;

		char c = str.charAt(0);
		String expressionString = str.substring(2); // Talvez possa ser um problema
		if (c == 'a') {
			if (!hasNextExp) return AND(expressionString);
			return AND(expressionString) || ORCompare(str.substring(indexOfNextExpVal));
		} else if (c == 'o') {
			return OR(expressionString);
		} else if (c == '!') {
			return !searchForExpression(expressionString);
		} else {
			if (debugging) System.out.println("ORCompare: Else");
			if (str.charAt(1) == ')') {
				if (debugging) System.out.println("str.charAt(1) == ')'");
				if (debugging) System.out.println("Lib.ctobool(c): " + Lib.ctobool(c));
				return Lib.ctobool(c);
			}
			else return Lib.ctobool(c) || ORCompare(str.substring(2));
		} 
	}

	static boolean AND(String str) {

		if (debugging) System.out.printf("Função AND: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '0') return false;
		else if (c == '1') {
			boolean teste = ANDCompare(str.substring(2));
			if (debugging) System.out.println("teste: " + teste);
			return Lib.ctobool(c) && teste;
		}
		else return ANDCompare(str) && ANDCompare(str.substring(indexOfNextExp(str)));
	}

	static boolean ANDCompare(String str) {
		if (debugging) System.out.printf("Função ANDCompare: '%s'\n", str);

		int indexOfNextExpVal = indexOfNextExp(str);
		// if (debugging) System.out.println("indexOfNextExpVal: " + indexOfNextExpVal);
		boolean hasNextExp = indexOfNextExpVal > 0;

		char c = str.charAt(0);
		String expressionString = str.substring(2);

		if (c == 'a') {
			return AND(expressionString);
		} else if (c == 'o') {
			// return OR(expressionString);
			if (!hasNextExp) {
				if (debugging) System.out.println("!hasNextExp");
				return OR(expressionString);
			}
			if (debugging) System.out.println("hasNextExp");
			return OR(expressionString) && ANDCompare(str.substring(indexOfNextExpVal));
		} else if (c == '!') {
			if (debugging) System.out.println("else if (c == '!'): " + str);
			if (!hasNextExp) return !searchForExpression(expressionString);
			try {
				return !searchForExpression(expressionString) && ANDCompare(str.substring(indexOfNextExpVal));
			} catch (Exception e) {	
				return !searchForExpression(expressionString);
			}
		} else {
			if (debugging) System.out.println("ANDCompare: Else");
			if (c == '0') return false;
			if (str.charAt(1) == ')') return Lib.ctobool(c);
			else return Lib.ctobool(c) && ANDCompare(str.substring(2));
		} 
	}

	static boolean searchForExpression(String str) {

		if (debugging) System.out.printf("searchForExpression: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = str.substring(2);
		if (c == '1' || c == '0') {
			return Lib.ctobool(c);
		} else if (c == 'a') {
			return AND(expressionString);
		} else if (c == 'o') {
			return OR(expressionString);
		} else {
			if (debugging) System.out.println("NOT");
			return !searchForExpression(expressionString);
		}
	}

		static boolean algebraBooleana(String input) {
		
		input = Lib.replaceAll(' ', "", input);
		input = Lib.replaceAll("and", 'a', input);
		input = Lib.replaceAll("or", 'o', input);
		input = Lib.replaceAll("not", '!', input);
		// System.out.printf("String: '%s'\n", Lib.toString(input));

		int N = Lib.ctoi(input.charAt(0));
		
		// Substituindo os valores dos termos na String.
		for (int i = 0; i < N; i++) {
			char c = (char)('A' + i);
			char replace = input.charAt(i + 1);
			input = Lib.replaceAll(c, replace, input);
		}

		// System.out.printf("String: '%s'\n", input);
		// System.out.printf("String: '%s'\n", Lib.toString(charArray));

		return searchForExpression(Lib.substr(N + 1, input));
	}

	public static void main(String[] args) {
		String input = new String();
		while((input = Lib.getstr()).charAt(0) != '0') {
			// System.out.println("Resultado: " + (algebraBooleana(input) ? 1 : 0));
			System.out.println(algebraBooleana(input) ? 1 : 0);
		}
	}
}