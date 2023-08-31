// clear && javac -cp ../../.. TP01Q07.java && java -cp ../../.. TP01Q07.java < pub.in > result.txt

// import TrabalhosPraticos.Lib;
import java.net.*;
import java.io.*;


import java.util.*;

class Lib {

	public static Scanner scanner = new Scanner(System.in);
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int ctoi(char c) { return c - 48; }
	public static boolean ctobool(char c) { return c == '1'; }
	public static char toUpper(char c) { return 'a' <= c && c <= 'z' ? (char)(c - 32) : c; }
	public static char toLower(char c) { return 'A' <= c && c <= 'Z' ? (char)(c + 32) : c; }
	public static boolean isNumber(char c) { return '0' <= c && c <= '9'; };
	public static boolean isAlpha(char c) { return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z'; }

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
}

class TP01Q07 {

	static final char aNormal = 'a';
	static final char eNormal = 'e';
	static final char iNormal = 'i';
	static final char oNormal = 'o';
	static final char uNormal = 'u';
	static final char aAgudo = 225;
	static final char eAgudo = 233;
	static final char iAgudo = 237;
	static final char oAgudo = 243;
	static final char uAgudo = 250;
	static final char aCrase = 224;
	static final char eCrase = 232;
	static final char iCrase = 236;
	static final char oCrase = 242;
	static final char uCrase = 249;
	static final char aTil = 227;
	static final char oTil = 245;
	static final char aCircunflexo = 226;
	static final char eCircunflexo = 234;
	static final char iCircunflexo = 238;
	static final char oCircunflexo = 244;
	static final char uCircunflexo = 251;

	static class Contador {
		int aNormalCount = 0;
		int eNormalCount = 0;
		int iNormalCount = 0;
		int oNormalCount = 0;
		int uNormalCount = 0;
		int aAgudoCount = 0;
		int eAgudoCount = 0;
		int iAgudoCount = 0;
		int oAgudoCount = 0;
		int uAgudoCount = 0;
		int aCraseCount = 0;
		int eCraseCount = 0;
		int iCraseCount = 0;
		int oCraseCount = 0;
		int uCraseCount = 0;
		int aTilCount = 0;
		int oTilCount = 0;
		int aCircunflexoCount = 0;
		int eCircunflexoCount = 0;
		int iCircunflexoCount = 0;
		int oCircunflexoCount = 0;
		int uCircunflexoCount = 0;

		Contador(String HTML) {
			int htmlLen = HTML.length();
			for (int i = 0; i < htmlLen; i++) {
				char c = HTML.charAt(i);
				if ((int)c == 97) aNormalCount++;
				else if ((int)c == 101) eNormalCount++;
				else if ((int)c == 105) iNormalCount++;
				else if ((int)c == 111) oNormalCount++;
				else if ((int)c == 117) uNormalCount++;
				else if ((int)c == 225) aAgudoCount++;
				else if ((int)c == 233) eAgudoCount++;
				else if ((int)c == 237) iAgudoCount++;
				else if ((int)c == 243) oAgudoCount++;
				else if ((int)c == 250) uAgudoCount++;
				else if ((int)c == 224) aCraseCount++;
				else if ((int)c == 232) eCraseCount++;
				else if ((int)c == 236) iCraseCount++;
				else if ((int)c == 242) oCraseCount++;
				else if ((int)c == 249) uCraseCount++;
				else if ((int)c == 227) aTilCount++;
				else if ((int)c == 245) oTilCount++;
				else if ((int)c == 226) aCircunflexoCount++;
				else if ((int)c == 234) eCircunflexoCount++;
				else if ((int)c == 238) iCircunflexoCount++;
				else if ((int)c == 244) oCircunflexoCount++;
				else if ((int)c == 251) uCircunflexoCount++;
			}
		}
		
		public void imprimir() {
			System.out.print("a(" + aNormalCount + ") ");
			System.out.printf("e(%d) ", eNormalCount);
			System.out.printf("i(%d) ", iNormalCount);
			System.out.printf("o(%d) ", oNormalCount);
			System.out.printf("u(%d) ", uNormalCount);
			System.out.print('á' + "(" + aAgudoCount +") ");
			System.out.printf("é(%d) ", eAgudoCount);
			System.out.printf("í(%d) ", iAgudoCount);
			System.out.printf("ó(%d) ", oAgudoCount);
			System.out.printf("ú(%d) ", uAgudoCount);
			System.out.printf("à(%d) ", aCraseCount);
			System.out.printf("è(%d) ", eCraseCount);
			System.out.printf("ì(%d) ", iCraseCount);
			System.out.printf("ò(%d) ", oCraseCount);
			System.out.printf("ù(%d) ", uCraseCount);
			System.out.printf("ã(%d) ", aTilCount);
			System.out.printf("õ(%d) ", oTilCount);
			System.out.printf("â(%d) ", aCircunflexoCount);
			System.out.printf("ê(%d) ", eCircunflexoCount);
			System.out.printf("î(%d) ", iCircunflexoCount);
			System.out.printf("ô(%d) ", oCircunflexoCount);
			System.out.printf("û(%d) ", uCircunflexoCount);
		}

	}

	static String getHTML(String endereco) {
		String line, html = "";
		try {
			URL url = new URL(endereco);
			InputStream is = url.openStream(); // throws an IOException
			Lib.br = new BufferedReader(new InputStreamReader(is));
			while ((line = Lib.br.readLine()) != null) { html += line + "\n"; }
		} catch (MalformedURLException mue) {
			mue.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
		return html;
	}

	static int lineBreakCount(String HTML) {
		int countLineBreak = 0;
		int htmlLen = HTML.length();
		int brLen = 4;
		for (int i = 0; i < htmlLen - brLen; i++) {
			if (Lib.isEqual(HTML.substring(i, i + brLen), "<br>")) {
				countLineBreak++;
			}
		}
		return countLineBreak;
	}

	static int tableCount(String HTML) {
		int countTable = 0;
		int htmlLen = HTML.length();
		int tableLen = 7;
		for (int i = 0; i < htmlLen - tableLen; i++) {
			if (Lib.isEqual(HTML.substring(i, i + tableLen), "<table>")) {
				countTable++;
			}
		}
		return countTable;
	}

	static boolean isConsonant(char c) {
		return Lib.isPresent(Lib.toLower(c), "bcdfghjklmnpqrstvwxyz");
	}

	static int consonantCount(String HTML) {
		int countConsonant = 0;
		int htmlLen = HTML.length();
		for (int i = 0; i < htmlLen; i++) {
			char c = HTML.charAt(i);
			if (isConsonant(c)) countConsonant++;
		}
		return countConsonant;
	}

	public static void main(String[] args) {

		String nomeDaPagina = new String();
		while(!Lib.isEqual(nomeDaPagina = Lib.getstr(), "FIM")) {
			String URL = Lib.getstr();
			String HTML = getHTML(URL);

			Contador vogais = new Contador(HTML);
			vogais.imprimir();
			System.out.printf("consoante(%d) ", consonantCount(HTML));
			System.out.printf("<br>(%d) ", lineBreakCount(HTML));
			System.out.printf("<table>(%d) ", tableCount(HTML));
			System.out.println(nomeDaPagina);
		}
	}
}