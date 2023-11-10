package TT01.ArquivosEmJava.Ex5;

import TT01.ArquivosEmJava.Arq;

import java.util.*;

class Ex5 {
	static Scanner scanner = new Scanner(System.in);
	static Pilha pilha = new Pilha();

	static void inserir() {
		System.out.print("Digite o número que deseja inserir: ");
		pilha.inserir(scanner.nextInt());
		scanner.nextLine();
	}

	static void remover() {
		try {
			System.out.println("\n" + pilha.remover() + " removido da pilha.\n");
		} catch (Exception erro) {
			System.out.println(erro.getMessage());
		}
	}

	static int lendoEscolha() {
		int escolha;
		boolean invalido = false;

		do {
			if (invalido) {
				System.out.println("Valor inválido, tente novamente: ");
			}
			escolha = scanner.nextInt();
			scanner.nextLine();
		} while ((invalido = escolha < 0 || 4 < escolha));

		return escolha;
	}

	static int optionsMenu() {

		System.out.println("1 - Inserir");
		System.out.println("2 - Remover");
		System.out.println("3 - Listar");
		System.out.println("4 - Sair do programa\n");
		System.out.print("Escolha uma das opções acima: ");

		int escolha = lendoEscolha();

		switch (escolha) {
			case 1:
				inserir();
				break;
			case 2:
				remover();
				break;
			case 3:
				pilha.mostrar();
				break;
			case 4:
			default:
				return 0;
		}

		return escolha;
	}

	public static void main(String[] args) {

		preencherPilha();

		while (optionsMenu() != 0) {
			continue;
		}

		salvarPilha();

		scanner.close();
		System.out.println(("\n------- | FIM DO PROGRAMA | -------\n"));
	}

	static void salvarPilha() {

		String filePath = "AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex5/";

		String file = filePath + "pilha" + ".dat";

		Arq.openWrite(file);

		boolean pilhaHasNext = true;

		while (pilhaHasNext) {
			try {
				Arq.print(pilha.remover() + " ");
			} catch (Exception erro) {
				pilhaHasNext = false;
			}
		}

		pilhaHasNext = true;

		Arq.close();

		preencherPilha();

		Arq.openWrite(file);

		while (pilhaHasNext) {
			try {
				Arq.print(pilha.remover() + " ");
			} catch (Exception erro) {
				pilhaHasNext = false;
			}
		}

		Arq.close();
	}

	static void preencherPilha() {

		String filePath = "AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex5/";

		String file = filePath + "pilha" + ".dat";

		Arq.openRead(file);

		while (Arq.hasNext()) {
			pilha.inserir(Arq.readInt());
		}

		Arq.close();

	}
}
