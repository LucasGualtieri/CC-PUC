import java.util.Scanner;

public class sobrenome {

	public static boolean ehConsoante(char caractere) {
		if (caractere == 'a' || caractere == 'A') {
			return false;
		} else if (caractere == 'e' || caractere == 'E') {
			return false;
		} else if (caractere == 'i' || caractere == 'I') {
			return false;
		} else if (caractere == 'o' || caractere == 'O') {
			return false;
		} else if (caractere == 'u' || caractere == 'U') {
			return false;
		} else {
			return true;
		}
	}

	public static String ehDificil(String nome) {
		if (nome.length() <= 2) {
			return nome + " eh facil\n";
		}

		for (int i = 0; i < nome.length() - 2; i++) {
			if (ehConsoante(nome.charAt(i))
					&& ehConsoante(nome.charAt(i + 1))
					&& ehConsoante(nome.charAt(i + 2))) {
				return nome + " nao eh facil\n";
			}
		}

		return nome + " eh facil\n";
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNextLine()) {
			String nome = scanner.nextLine();
			System.out.print(ehDificil(nome));
		}

		scanner.close();
	}
}