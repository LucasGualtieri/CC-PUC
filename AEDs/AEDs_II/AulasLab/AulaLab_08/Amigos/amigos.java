import java.util.Scanner;

public class amigos {

	// public static void printLista(String lista[], String character) {
	// for (int i = 0; i < listaLength; i++) {
	// printf("%s%s", lista[i], i < listaLength - 1 ? " " : character);
	// }
	// }

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String[] listaAtual = scanner.nextLine().split(" ");
		String[] listaNova = scanner.nextLine().split(" ");
		String amigo = scanner.nextLine();

		if (!amigo.equals("Nao")) {
			for (int i = 0; strcmp(listaAtual[i], amigo); i++) {
				printf("%s ", listaAtual[i]);
				position++;
			}

			printLista(listaNova, " ");

			printLista(position, "\n");

		} else {
			printLista(listaAtual, " ");
			printLista(listaNova, "\n");
		}
	}
}