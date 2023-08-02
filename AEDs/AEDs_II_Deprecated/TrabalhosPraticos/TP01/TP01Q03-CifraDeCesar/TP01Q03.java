import java.util.Scanner;

public class TP01Q03 {

	public static String cifrar(String mensagem, int chave) {
		String mensagemCifrada = "";

		for (int i = 0; i < mensagem.length(); i++) {
			mensagemCifrada += (char) (mensagem.charAt(i) + chave);
		}

		return mensagemCifrada;
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String entrada = scanner.nextLine();

		while (!entrada.equals("FIM")) {

			System.out.println(cifrar(entrada, 3));

			entrada = scanner.nextLine();
		}

		scanner.close();
	}
}