import java.util.*;

class Lib {

	static Scanner scanner = new Scanner(System.in);

	static boolean isEqual(String str1, String str2) {
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

	static String getstr() {
		String str = scanner.nextLine();
		return str.substring(0, str.length());
	}

	static String getstr(String msg) {
		System.out.printf("%s: ", msg);
		String str = scanner.nextLine();
		return str.substring(0, str.length());
	}

}

class TP01Q01 {

	static boolean isPalindromo(String palavra) {
		int len = palavra.length();

		for (int i = 0; i < len; i++) {
			if (palavra.charAt(i) != palavra.charAt(len - i - 1)) {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) {
		String str = Lib.getstr();
		while (!Lib.isEqual(str, "FIM")) {
			System.out.println(isPalindromo(str) ? "SIM" : "NAO");
			str = Lib.getstr();
		}
	}
}
