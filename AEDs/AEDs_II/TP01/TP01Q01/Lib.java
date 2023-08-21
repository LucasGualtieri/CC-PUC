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