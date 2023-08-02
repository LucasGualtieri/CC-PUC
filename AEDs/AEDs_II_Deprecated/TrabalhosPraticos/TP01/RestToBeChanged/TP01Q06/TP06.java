public class TP06 {
	public static boolean X1(String s) {
		String vogais = "aeiouAEIOU";
		for (int i = 0; i < s.length(); i++) {
			if (!vogais.contains(String.valueOf(s.charAt(i)))) {
				return false;
			}
		}
		return true;
	}

	public static boolean X2(String s) {
		String consoantes = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
		for (int i = 0; i < s.length(); i++) {
			if (!consoantes.contains(String.valueOf(s.charAt(i)))) {
				return false;
			}
		}
		return true;
	}

	public static boolean X3(String s) {
		try {
			Integer.parseInt(s);
			return true;
		} catch (NumberFormatException e) {
			return false;
		}
	}

	public static boolean X4(String s) {
		try {
			Double.parseDouble(s);
			return true;
		} catch (NumberFormatException e) {
			return false;
		}
	}

	public static void main(String[] args) {
		String entrada = new String("");

		while (true) {
			entrada = MyIO.readLine();

			if (entrada.compareTo("FIM") == 0) {
				break;
			}
			if (X1(entrada)) {
				System.out.print("SIM ");
			} else {
				System.out.print("NAO ");
			}

			if (X2(entrada)) {
				System.out.print("SIM ");
			} else {
				System.out.print("NAO ");
			}

			if (X3(entrada)) {
				System.out.print("SIM ");
			} else {
				System.out.print("NAO ");
			}

			if (X4(entrada)) {
				System.out.print("SIM ");
			} else {
				System.out.print("NAO ");
			}
			System.out.println();
		}

	}
}