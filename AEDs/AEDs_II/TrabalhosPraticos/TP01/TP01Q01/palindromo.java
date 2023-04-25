class TP01Q01 {

	public static boolean Palindromo(String nome) {
		String reversedString = "";

		for (int i = 0; i < nome.length(); i++) {
			reversedString = nome.charAt(i) + reversedString;
		}

		for (int i = nome.length() - 1, j = 0; i > 0; i--) {
			if (nome.charAt(i) == nome.charAt(j)) {
				j++;
			} else {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		String entrada = new String("");

		while (true) {

			entrada = MyIO.readLine();

			if (entrada.compareTo("FIM") == 0) {
				break;
			}

			if (Palindromo(entrada)) {
				System.out.println("SIM");
			} else {
				System.out.println("NAO");
			}

		}
	}
}
