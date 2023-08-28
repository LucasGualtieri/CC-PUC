package TrabalhosPraticos;

import java.util.*;

public class Lib {

	public static Scanner scanner = new Scanner(System.in);
	// private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("UTF-8")));

	public static boolean isEqual(String str1, String str2) {
		if (str1.length() != str2.length()) {
			return false;
		}
		for (int i = 0; i < str1.length(); i++) {
			if (str1.charAt(i) != str2.charAt(i)) {
				return false;
			}
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