package TP01;

// import java.util.InputMismatchException;
import java.util.List;

// clear && javac -cp ../ Principal.java && java -cp ../ Principal.java

// Fazer uma função para listar todos os livros *válidos*

class Principal {

	static int ReadChoice(int choiceCount) {
		int	 choice;
		boolean invalid = false;
	
		do {
			if (invalid) {
				Lib.cprintf("BOLD RED", "Valor inválido, ");
				System.out.print("tente novamente: ");
			}
			choice = Lib.readInt();
		} while (invalid = choice < 0 || choiceCount < choice);
	
		return choice;
	}

	static <T extends Registro> void Create(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Cadastrando na base de dados: %ss", arquivo.getNome());
		
		T object = arquivo.readNewInstance();
		System.out.println("\n" + object + "\n");
		
		Lib.cprintf("GREEN", "1 - Confirmar cadastro.\n");
		Lib.cprintf("RED", "2 - Cancelar cadastro.\n");
		System.out.print("\nEscolha uma das opções acima: ");
		
		int escolha = ReadChoice(2);
		
		if (escolha == 1) {
			try {
				arquivo.create(object);
				Lib.clearScreen();
				// System.out.println(object + "\n");
				Lib.cprintf("BOLD GREEN", "%s cadastrado com sucesso!\n\n", arquivo.getNome());
			} catch (Exception e) {
				Lib.cprintf("BOLD RED", "\n%s falha ao cadastrar.\n\n", arquivo.getNome());
			}
		}

		else {
			Lib.printdiv(1, 0, "Cadastro cancelado");
		}
	}

	static <T extends Registro> T Read(boolean print, Arquivo<T> arquivo) throws Exception {
		
		if (print) {
			Lib.clearScreen();
			Lib.printdiv(1, "Consultando na base de dados: %ss", arquivo.getNome());
		}
		
		System.out.printf("Insira o ID do %s: ", arquivo.getNome());
		int ID = Lib.readInt();

		T object = null;

		try {
			object = arquivo.read(ID);
			if (print) {
				Lib.clearScreen();
				Lib.cprintf("BOLD GREEN", "%s encontrado com sucesso!\n\n", arquivo.getNome());
				System.out.println(object + "\n");
			}
		}
		
		catch (Exception e) {
			if (print) Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			else throw new Exception();	
		}

		return object;
	}

	static <T extends Registro> void Update(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Atualizando a base de dados: %ss", arquivo.getNome());
		
		T oldObject, newObject;

		try { oldObject = Read(false, arquivo); }
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			return;
		}

		// ---------------------------------------------------------------------

		System.out.println("\n" + oldObject + "\n");

		Lib.cprintf("GREEN", "1 - Atualizar os dados.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = ReadChoice(2);

		if (escolha == 1) {
			System.out.println();
			newObject = arquivo.readNewInstance(oldObject.getID());
			System.out.println("\n" + newObject + "\n");
		}
		
		else {
			Lib.clearScreen();
			Lib.printdiv("Atualização cancelada");
			return;
		}

		// ---------------------------------------------------------------------

		Lib.cprintf("GREEN", "1 - Confirmar atualização.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		escolha = ReadChoice(2);

		if (escolha == 1) {
			arquivo.update(oldObject, newObject);
			Lib.clearScreen();
			Lib.cprintf("BOLD GREEN", "%s atualizado com sucesso!\n\n", arquivo.getNome());
		}

		else {
			Lib.clearScreen();
			Lib.printdiv("Atualização cancelada");
		}
	}

	static <T extends Registro> void Delete(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Excluindo da base de dados: %ss", arquivo.getNome());

		T object;

		try { object = Read(false, arquivo); }
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", arquivo.getNome());
			return;
		}

		System.out.println("\n" + object + "\n");
	
		Lib.cprintf("GREEN", "1 - Confirmar exclusão.\n");
		Lib.cprintf("RED", "2 - Cancelar exclusão.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = ReadChoice(2);

		if (escolha == 1) {
			// Não usei try-catch pois não encontrei motivos para falha na exclusão.
			arquivo.delete(object.getID());
			Lib.clearScreen();
			Lib.cprintf("BOLD GREEN", "%s excluído com sucesso!\n\n", arquivo.getNome());
		}

		else {
			Lib.clearScreen();
			Lib.printdiv("Exclusão cancelada");
		}
	}

	// Penso em fazer um esquema de paginação, ou seja, no parametro da função
	// defino qual página será retornada, e ai o usuário teria a opção de ir para a
	// próxima ou voltar.
	static <T extends Registro> void Listar(Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		
		List<T> list = arquivo.Listar();
		
		if (list == null) {
			Lib.printdiv("Base de dados vazia: %ss", arquivo.getNome());
			return;
		}

		Lib.printdiv(1, "Listando a base de dados: %ss", arquivo.getNome());

		arquivo.printHeader();

		int[] i = {1};
		list.forEach((teste) -> {
			System.out.printf("%d - %s", i[0]++, teste.toTable());
		});

		System.out.println();
	}

	static <T extends Registro> void CRUD(Arquivo<T> arquivo) throws Exception {

		Lib.clearScreen();
		
		int escolha;
		
		do {
			Lib.printdiv(1, "Base de dados: %ss", arquivo.getNome());

			System.out.println("1 - Cadastrar.");
			System.out.println("2 - Consultar.");
			System.out.println("3 - Atualizar.");
			System.out.println("4 - Deletar.");
			System.out.printf("5 - Listar todos os %ss.\n", arquivo.getNome());
			System.out.println("\n0 - Voltar.");
			System.out.print("\nEscolha uma das opções acima: ");

			escolha = ReadChoice(5);

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
		
		int escolha;
		
		do {
			Lib.clearScreen();
			Lib.printdiv(1, "SGBD");

			System.out.println("1 - Livros.");
			System.out.println("2 - Autores.");
			System.out.println("\n0 - Sair do programa.");
			System.out.print("\nEscolha uma das bases de dados: ");
			
			escolha = ReadChoice(2);
			
			switch (escolha) {
			case 1:
				ArquivoLivro<Livro> arquivo = new ArquivoLivro<>(
					Livro.getConstructor(),
					"Livro",
					"dados/livros.db"
				);
				CRUD(arquivo);
				arquivo.close();
				break;
			case 2:
				System.out.println("Base de dados: Autores");
				// Arquivo<Autor> arquivo;
				// arquivo = new Arquivo<>(Autor.getConstructor(), "dados/autores.db");
				break;
			}

		} while (escolha != 0);

		Lib.printdiv(1, 1, "FIM DO PROGRAMA");
	}
}