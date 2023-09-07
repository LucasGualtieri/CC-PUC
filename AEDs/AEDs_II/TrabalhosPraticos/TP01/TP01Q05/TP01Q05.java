// clear && javac -cp ../../.. TP01Q05.java && java -cp ../../.. TP01Q05.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05 {

	static boolean debugging = false;

	static int endOfCurExp(String str) {
		if (debugging) System.out.printf("endOfCurExp: '%s'\n", str);
		// if (debugging) System.out.print("endOfCurExp: ");
		int len = str.length();
		if (len == 0) return 0;

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

	static int startOfNextExp(String str) {
		return endOfCurExp(str) + 1;
	}

	static boolean OR(String str) {

		if (debugging) System.out.printf("Função OR: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '1') return true;
		if (c == '0') return Lib.ctobool(c) || ORCompare(Lib.substr(2, str));
		return ORCompare(Lib.substr(0, endOfCurExp(str), str)) || ORCompare(Lib.substr(startOfNextExp(str), str)); //Maybe OR normal
	}

	static boolean ORCompare(String str) {
		if (debugging) System.out.printf("Função ORCompare: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(1, str.length(), str);

		if (c == '0') return false;

		int indexEnd = endOfCurExp(Lib.substr(1, str));
		if (debugging) System.out.println("indexEnd: " + indexEnd);
		boolean hasNextExp = indexEnd > 0;

		if (c == '1' && hasNextExp) {
			if (c == '1' && !hasNextExp) return Lib.ctobool(c);
			return Lib.ctobool(c) || ORCompare(Lib.substr(2, str));
		}

		if (c == 'a') {
			if (debugging) System.out.println("c == 'a': " + str);
			if (!hasNextExp) return AND(Lib.substr(2, str.length() - 1, str));
			return AND(Lib.substr(2, indexEnd, str)) || ORCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == 'o') {
			if (debugging) System.out.println("c == 'o': " + str);
			if (!hasNextExp) return OR(Lib.substr(2, str.length() - 1, str));
			return OR(Lib.substr(2, indexEnd, str)) || ORCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == '!') {
			if (debugging) System.out.println("c == '!': " + str);
			if (!hasNextExp) return NOT(Lib.substr(1, expressionString));
			return NOT(Lib.substr(1, expressionString)) || ORCompare(Lib.substr(indexEnd + 2, str)); // + 1 pra start + 1 pelo !
		}

		return true; // Unreachable return

	}

	static boolean AND(String str) {

		if (debugging) System.out.printf("Função AND: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '0') return false;
		if (c == '1') return Lib.ctobool(c) && ANDCompare(Lib.substr(2, str));
		return ANDCompare(Lib.substr(0, endOfCurExp(str), str)) && ANDCompare(Lib.substr(startOfNextExp(str), str));
	}

	static boolean ANDCompare(String str) {
		if (debugging) System.out.printf("Função ANDCompare: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(1, str.length(), str);

		if (c == '0') return false;

		int indexEnd = endOfCurExp(Lib.substr(1, str));
		if (debugging) System.out.printf("indexEnd: %d\n", indexEnd);
		boolean hasNextExp = indexEnd > 0;

		if (c == '1' && hasNextExp) {
			if (c == '1' && !hasNextExp) return Lib.ctobool(c);
			return Lib.ctobool(c) && ANDCompare(Lib.substr(2, str));
		}

		if (c == 'a') {
			if (debugging) System.out.println("c == 'a': " + str);
			if (!hasNextExp) return AND(Lib.substr(2, str.length() - 1, str));
			return AND(Lib.substr(2, indexEnd, str)) && ANDCompare(Lib.substr(indexEnd + 2, str));
		}

		if (c == 'o') {
			if (debugging) System.out.println("c == 'o': " + str);
			if (!hasNextExp) return OR(Lib.substr(2, str.length() - 1, str));
			return OR(Lib.substr(2, indexEnd, str)) && ANDCompare(Lib.substr(indexEnd + 2, str));
		}
		
		if (c == '!') {
			if (debugging) System.out.println("c == '!': " + str);
			if (!hasNextExp) return NOT(Lib.substr(1, expressionString));
			return NOT(Lib.substr(1, expressionString)) && ANDCompare(Lib.substr(indexEnd + 2, str)); // + 1 pra start + 1 pelo !
		}

		return true; // Unreachable return

	}

	static boolean NOT(String str) {

		if (debugging) System.out.printf("Função NOT: '%s'\n", str);

		char c = str.charAt(0);
		if (c == '0' || c == '1') return !Lib.ctobool(c);
		return !searchForExpression(str);
	}

	static boolean searchForExpression(String str) {

		if (debugging) System.out.printf("searchForExpression: '%s'\n", str);

		char c = str.charAt(0);
		String expressionString = Lib.substr(2, str.length() - 1, str);
		if (c == '1' || c == '0') {
			return Lib.ctobool(c);
		} else if (c == 'a') {
			return AND(expressionString);
		} else if (c == 'o') {
			return OR(expressionString);
		} else {
			if (debugging) System.out.println("NOT");
			return NOT(expressionString);
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

		input = Lib.toString(charArray);
		input = Lib.substr(N + 1, input);
		// System.out.printf("String: '%s'\n", input);
		// System.out.printf("String: '%s'\n", Lib.toString(charArray));

		return searchForExpression(input);
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