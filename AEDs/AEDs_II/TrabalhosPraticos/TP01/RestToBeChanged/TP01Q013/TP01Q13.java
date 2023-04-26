public class TP01Q13 {

	public static void main(String[] args) {
		String entrada = new String("");

		while (true) {

			entrada = MyIO.readLine();

			if (entrada.compareTo("FIM") == 0) {
				break;
			}

			MyIO.println(cifrar(entrada, 0));
		}
	}

	public static String cifrar(String mensagem, int i) {
		if (i == mensagem.length()) {
			return "";
		}
		int chave = 3;
		char letra = (char) (mensagem.charAt(i) + chave);
		return letra + cifrar(mensagem, i + 1);
	}
}