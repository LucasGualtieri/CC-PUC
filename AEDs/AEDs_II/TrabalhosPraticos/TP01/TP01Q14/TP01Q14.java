// clear && javac -cp ../../.. TP01Q14.java && java -cp ../../.. TP01Q14.java < pub.in > result.txt

// import TrabalhosPraticos.Lib;

import java.io.*;
import java.util.*;

class TP01Q14 {

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

class Lib {

	public static Scanner scanner = new Scanner(System.in);
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int ctoi(char c) { return c - 48; }
	public static boolean ctobool(char c) { return c == '1'; }
	public static char toUpper(char c) { return 'a' <= c && c <= 'z' ? (char)(c - 32) : c; }
	public static char toLower(char c) { return 'A' <= c && c <= 'Z' ? (char)(c + 32) : c; }
	public static boolean isNumber(char c) { return '0' <= c && c <= '9'; };
	public static boolean isAlpha(char c) { return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z'; }
	public static boolean isLowerCase(char c) { return 'a' <= c && c <= 'z'; }

	public static boolean isPresent(char c, String str) {
		boolean result = false;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str.charAt(i) == c) {
				result = true;
				i = len;
			}
		}
		return result;
	}

	public static int IndexOf(char c, String str) {
		int index = 0;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str.charAt(i) == c) {
				index = i;
				i = len;
			}
		}
		return index;
	}

	public static String toString(char[] array) {
		String aux = "";
		for (int i = 0; i < array.length; i++) {
			aux += array[i];
		}
		return aux;
	}

	public static String substr(int start, int end, String str) {
		
		int strLen = str.length();

		if (start < 0) {
			start = 0; 
		}
		
		if (end > strLen) {
			end = strLen; 
		}

		if (start >= end) {
			return "";
		}
		
		String aux = "";
		for (int i = start; i < end; i++) {
			aux += str.charAt(i);
		}

		return aux;
	}

	public static String substr(int start, String str) {
		int strLen = str.length();

		// System.out.println("In: substr(): " + str);
		// System.out.printf("In: substr(): %s, start: %d\n", str, start);

		if (start < 0) {
			start = 0;
		}

    	if (start >= strLen) {
    	    return "";
		}

		String aux = "";
		for (int i = start; i < strLen; i++) {
			aux += str.charAt(i);
		}

		return aux;
	}

	public static String replaceAll(char baseChar, char newChar, String str) {
		
		String aux = "";
		int strLen = str.length();

		for (int i = 0; i < strLen; i++) {
			char c = str.charAt(i);
			if (c == baseChar) aux += newChar;
			else aux += c;
		}

		return aux;
	}

	public static char[] replaceAll(String baseStr, char newChar, char[] charrArray) {
		
		String str = toString(charrArray);

		String aux = "";
		int strLen = str.length();
		int baseStrLen = baseStr.length();
		// System.out.println("BaseStrLen: " + baseStrLen);
		for (int i = 0; i < strLen; i++) {
			boolean subsstr = i < strLen - baseStrLen;
			if (subsstr && isEqual(str.substring(i, i + baseStrLen), baseStr)) {
				// System.out.println("Subs: " + str.substring(i, i + baseStrLen));
				aux += newChar;
				i += baseStrLen - 1;
			} else {
				aux += str.charAt(i);
			}
		}

		return aux.toCharArray();
	}

	public static char[] replaceAll(char baseChar, String newStr, String str) {
		
		String aux = "";

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == baseChar) aux += newStr;
			else aux += str.charAt(i);
		}

		return aux.toCharArray();
	}

	public static char[] replaceAll(char baseChar, char newChar, char[] str) {
		
		String aux = "";

		for (int i = 0; i < str.length; i++) {
			if (str[i] == baseChar) aux += newChar;
			else aux += str[i];
		}

		return aux.toCharArray();
	}

	public static char[] replaceAll(char baseChar, String newStr, char[] str) {
		
		String aux = "";

		for (int i = 0; i < str.length; i++) {
			if (str[i] == baseChar) aux += newStr;
			else aux += str[i];
		}

		return aux.toCharArray();
	}

	public static boolean isEqual(String str1, String str2) {
		if (str1.length() != str2.length()) return false;

		for (int i = 0; i < str1.length(); i++) {
			if (str1.charAt(i) != str2.charAt(i)) return false;
		}

		return true;
	}
	
	// public static char readChar(){
	// 	return readInt(); // (char)readInt();
	// }

	// public static int readInt() { // Talvez tenha que pegar o getChar do MyIO mais uma vez caso isso não funcione
	// 	char int; // char resp = ' ';
	// 	try {
	// 		resp = (char)in.read();
	// 	} catch(Exception e) {}
	// 	return resp;
	// }

	public static String getstr() {
		String str = scanner.nextLine();
		return str.substring(0, str.length());
	}

	public static String getstr(String msg) {
		System.out.printf("%s: ", msg);
		String str = scanner.nextLine();
		return str.substring(0, str.length());
	}

	private static void flush() throws Exception {
		try {
			scanner.nextLine();
		} catch (Exception e) {}
	}

	public static float getFloat() throws Exception {
		float floatValue = scanner.nextFloat();
		flush();
		return floatValue;
	}

	public static double getDouble() throws Exception {
		double doubleValue = scanner.nextDouble();
		flush();
		return doubleValue;
	}

	public static int getInt() throws Exception {
		int integer = scanner.nextInt();
		flush();
		return integer;
	}
}