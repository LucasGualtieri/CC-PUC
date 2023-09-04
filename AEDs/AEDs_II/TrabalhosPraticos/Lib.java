package TrabalhosPraticos;

import java.io.*;
import java.util.*;

public class Lib {

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