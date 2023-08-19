import java.util.*;

class Ex4 {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		String filePath = "AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex4/";

		System.out.print("Digite o nome do arquivo: ");
		String file = filePath + scanner.next() + ".txt";

		String fileContent = Arq.openReadClose(file);
		Arq.openWrite(file);

		for (int i = 0; i < fileContent.length() - 1; i++) {
			// System.out.println("Ola");
			char c = (char) (((int) fileContent.charAt(i)) + 3);
			System.out.print(c);
			Arq.print(c);
		}
		Arq.close();

		System.out.print("\nDigite o nome do arquivo: ");
		file = filePath + scanner.next() + ".txt";

		fileContent = Arq.openReadClose(file);

		System.out.print("\nA mensagem descriptografada é: ");

		for (int i = 0; i < fileContent.length() - 1; i++) {
			// System.out.println("Ola");
			char c = (char) (((int) fileContent.charAt(i)) - 3);
			System.out.print(c);
		}

		System.out.println();

		scanner.close();
	}
}
