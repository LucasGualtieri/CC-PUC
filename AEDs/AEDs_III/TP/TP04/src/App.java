package TP04.src;

import TP04.src.utils.Utils;
import TP04.src.utils.Arquivo;

class App {

	static final String path = "AEDs/AEDs_III/TP/TP04/src/Entidades/";

	static int printMenu() {

		Utils.clearScreen();
		Utils.printdiv(1, "SGBD");

		System.out.println("1 - Livros.");
		System.out.println("2 - Autores.\n");
		System.out.println("0 - Sair do programa.\n");
		System.out.print("Escolha uma das bases de dados: ");

		return Utils.ReadChoice(2);
	}

	// A função main permite que o usuário escolha a base de dados que deseja trabalhar.
	public static void main(String[] args) throws Exception {

		int choice;

		Arquivo arquivo = new Arquivo();

		do {
			
			choice = printMenu();

			switch (choice) {
				case 1:
					// arquivo.setEntidade(new RegistroLivro);
					// arquivo = new ArquivoLivro<>(path + "Livros/Dados/");
				break;
				case 2:
					// arquivo = new ArquivoAutor<>(path + "Autores/Dados/");
				break;
			}

			if (choice != 0) arquivo.CRUDMenu();
			// arquivo.close();

		} while (choice != 0);

		Utils.printdiv(1, 1, "FIM DO PROGRAMA");
	}

	// public static void main(String[] args) throws Exception {

	// 	int choice;

	// 	// Arquivo arquivo = new Arquivo();
	// 	// EntityFactory factory = new EntityFactory();

	// 	do {
	// 		Utils.clearScreen();
	// 		Utils.printdiv(1, "SGBD");

	// 		System.out.println("1 - Livros.");
	// 		System.out.println("2 - Autores.\n");
	// 		System.out.println("0 - Sair do programa.\n");
	// 		System.out.print("Escolha uma das bases de dados: ");

	// 		choice = Utils.ReadChoice(2);

	// 		switch (choice) {
	// 			case 1:
	// 				// arquivo.setEntity(factory.createLivro());
	// 				// arquivo.setEntityLivro();
	// 			break;
	// 			case 2:
	// 				// arquivo = new ArquivoAutor<>(path + "Autores/Dados/");
	// 			break;
	// 		}

	// 		if (choice != 0) {
	// 			// CRUD(arquivo);
	// 			// arquivo.close();
	// 		}

	// 	} while (choice != 0);

	// 	Utils.printdiv(1, 1, "FIM DO PROGRAMA");
	// }

}