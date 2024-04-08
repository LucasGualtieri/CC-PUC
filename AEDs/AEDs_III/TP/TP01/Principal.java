package TP01;

import java.util.List;

import TP01.Autor.ArquivoAutor;
import TP01.Livros.ArquivoLivro;
import TP01.Livros.Livro;

// clear && javac -d Classes -cp ../ Principal.java && java -cp Classes Principal.java

/*
 * /usr/lib/jvm/java-19-openjdk-amd64/bin/java -XX:+ShowCodeDetailsInExceptionMessages -cp /home/lucas/.vscode-server/data/User/workspaceStorage/806c8f962603aef4653ee3ae9c715a28/redhat.java/jdt_ws/CC-PUC_cc5a22eb/bin TP01.Principal
*/

class Principal {

	static <T extends Registro> void Create(Arquivo<T> arquivo) throws Exception {

		Lib.clearScreen();
		Lib.printdiv(1, "Cadastrando na base de dados: %s", arquivo.getNomePlural());

		T object = arquivo.readNewInstance();
		System.out.println("\n" + object + "\n");

		Lib.cprintf("GREEN", "1 - Confirmar cadastro.\n");
		Lib.cprintf("RED", "2 - Cancelar cadastro.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = Lib.ReadChoice(2);

		Lib.clearScreen();

		if (escolha != 1) Lib.cprintf("RED", "Cadastro cancelado.\n\n");

		else {
			try {
				arquivo.create(object);
				Lib.cprintf("BOLD GREEN", "%s cadastrado com sucesso!\n\n", arquivo.getNome());
				System.out.println(object + "\n");
			}
			catch (Exception e) {
				Lib.cprintf("BOLD RED", "Falha ao cadastrar %s.\n\n", arquivo.getNomeLowerCase());
				// Lib.cprintf("BOLD RED", "Falha ao cadastrar %s: %s\n\n", arquivo.getNomeLowerCase(), e.getMessage());
			}
		}
	}

	static <T extends Registro> T Read(boolean print, Arquivo<T> arquivo) throws Exception {

		if (print) {
			Lib.clearScreen();
			Lib.printdiv(1, "Consultando na base de dados: %s", arquivo.getNomePlural());
		}
		
		T object = null;

		try {
			int ID = arquivo.read();
			
			if (ID == 0) {
				Lib.clearScreen();
				return null;
			}
			
			object = arquivo.read(ID);
			if (print) {
				Lib.clearScreen();
				Lib.cprintf("BOLD GREEN", "%s encontrado com sucesso!\n\n", arquivo.getNome());
				System.out.println(object + "\n");
			}
		}

		catch (Exception e) {
			if (print) Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			else throw new Exception("Registro não encontrado.");	
		}

		return object;
	}

	// Quando cancelar a atualização esta mandando mensagem de livro não encontrado
	static <T extends Registro> void Update(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Atualizando a base de dados: %s", arquivo.getNomePlural());
		
		T oldObject, newObject;

		try {
			oldObject = Read(false, arquivo);
			if (oldObject == null) {
				Lib.clearScreen();
				return;
			}
		}
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			return;
		}

		// -----------------------------------------------------------------------------------------------

		System.out.println("\n" + oldObject + "\n");

		Lib.cprintf("GREEN", "1 - Atualizar os dados.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");
		
		int escolha = Lib.ReadChoice(2);
		
		if (escolha == 1) {
			System.out.println();
			newObject = arquivo.readNewInstance(oldObject.getID());
			System.out.println("\n" + newObject + "\n");
		}
		
		else {
			Lib.clearScreen();
			Lib.cprintf("BOLD RED", "\nAtualização cancelada.\n\n");
			return;
		}

		// -----------------------------------------------------------------------------------------------

		Lib.cprintf("GREEN", "1 - Confirmar atualização.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		escolha = Lib.ReadChoice(2);

		Lib.clearScreen();

		if (escolha != 1)Lib.cprintf("BOLD RED", "Atualização cancelada.\n\n");

		else {
			try {
				arquivo.update(oldObject.getID(), newObject);
				Lib.cprintf("BOLD GREEN", "%s atualizado com sucesso!\n\n", arquivo.getNome());
				System.out.println(newObject + "\n");
			}
			catch (Exception e) {
				Lib.cprintf("BOLD RED", "Falha ao atualizar %s.\n\n", arquivo.getNomeLowerCase());
				// Lib.cprintf("BOLD RED", "Falha ao cadastrar %s: %s\n\n", arquivo.getNomeLowerCase(), e.getMessage());
			}
		}
	}

	static <T extends Registro> void Delete(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Excluindo da base de dados: %s", arquivo.getNomePlural());

		T object;

		try { 
			object = Read(false, arquivo);
			if (object == null) {
				Lib.clearScreen();
				return;
			}
		}
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			return;
		}

		System.out.println("\n" + object + "\n");
	
		Lib.cprintf("GREEN", "1 - Confirmar exclusão.\n");
		Lib.cprintf("RED", "2 - Cancelar exclusão.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = Lib.ReadChoice(2);
		
		Lib.clearScreen();

		if (escolha == 1) {
			// Não usei try-catch pois não encontrei motivos para falha na exclusão.
			arquivo.delete(object.getID());
			Lib.cprintf("BOLD GREEN", "%s excluído com sucesso!\n\n", arquivo.getNome());
		}

		else Lib.printdiv("Exclusão cancelada");
	}

	static <T extends Registro> void Listar(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();

		List<T> list = arquivo.Listar();

		if (list == null) {
			Lib.printdiv("Base de dados vazia: %s", arquivo.getNomePlural());
			return;
		}

		Lib.printdiv(1, "Listando a base de dados: %s", arquivo.getNomePlural());

		if (arquivo.SortList(list) == 0) {
			Lib.clearScreen();
			return;
		}
		
		Lib.clearScreen();
		Lib.printdiv(1, "Listando a base de dados: %s", arquivo.getNomePlural());

		arquivo.printHeaderCSV();

		int[] i = {1};
		list.forEach((teste) -> {
			System.out.printf("%d- %s", i[0]++, teste.toCSV());
		});

		System.out.println();
	}

	static <T extends Registro> void CRUD(Arquivo<T> arquivo) throws Exception {

		Lib.clearScreen();

		int escolha;

		do {
			Lib.printdiv(1, "Base de dados: %s", arquivo.getNomePlural());

			System.out.println("1 - Cadastrar.");
			System.out.println("2 - Consultar.");
			System.out.println("3 - Atualizar.");
			System.out.println("4 - Deletar.");
			System.out.printf("5 - Listar todos os %s.\n", arquivo.getNomePluralLowerCase());
			System.out.println("\n0 - Voltar.");
			System.out.print("\nEscolha uma das opções acima: ");

			escolha = Lib.ReadChoice(5);

			switch (escolha) {
			case 1:
				Create(arquivo);
				break;
			case 2:
				Read(true, arquivo);
				break;
			case 3:
				Update(arquivo);
				break;
			case 4:
				Delete(arquivo);
				break;
			case 5:
				Listar(arquivo);
				break;
			}

		} while (escolha != 0);
	}

	public static void main(String[] args) throws Exception {
		
		int choice;
		
		Arquivo<Livro> arquivo = null;

		do {
			Lib.clearScreen();
			Lib.printdiv(1, "SGBD");

			System.out.println("1 - Livros.");
			System.out.println("2 - Autores.");
			System.out.println("\n0 - Sair do programa.");
			System.out.print("\nEscolha uma das bases de dados: ");
			
			choice = Lib.ReadChoice(2);

			switch (choice) {
				case 1:
					arquivo = new ArquivoLivro<>("Livro", "AEDs/AEDs_III/TP/TP01/Livros/Dados/");
				break;
				case 2:
					arquivo = new ArquivoAutor<>("Autor", "AEDs/AEDs_III/TP/TP01/Autor/Dados/");
				break;
			}

			if (choice != 0) {
				CRUD(arquivo);
				arquivo.close();
			}

		} while (choice != 0);

		Lib.printdiv(1, 1, "FIM DO PROGRAMA");
	}
}

// Quando o Update diminuir demais o registro aproveitar o espaço. Se diminuir a ponto de no lixo caber um registro novo
// Fazer o mesmo quando na criação, quando o registro é pequeno???

// Juntar dois registros excluídos que estejam adjacentes

// Penso em fazer um esquema de paginação, ou seja, no parametro da função
// defino qual página será retornada, e ai o usuário teria a opção de ir para a
// próxima ou voltar.
