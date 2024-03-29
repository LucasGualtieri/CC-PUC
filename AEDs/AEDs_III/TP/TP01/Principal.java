package TP01;

// import java.io.FileNotFoundException;
// import java.io.IOException;
import java.util.InputMismatchException;

// clear && javac -cp ../ Principal.java && java -cp ../ Principal.java

// Fazer uma função para listar todos os livros *válidos*

class Principal {

	static int ReadChoice(int choiceCount) {
		int	 choice;
		boolean invalid = false;
	
		do {
			if (invalid) System.out.print("Valor inválido, tente novamente: ");
			choice = Lib.readInt();
			try {
			} catch (InputMismatchException e) { choice = -1; }

		} while (invalid = choice < 0 || choiceCount < choice);
	
		return choice;
	}

	static <T extends Registro> void Create(String obj, Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Cadastrando na base de dados: %ss", obj);
		
		T object = arquivo.readNewInstance();
		System.out.println("\n" + object + "\n");
		
		Lib.cprintf("GREEN", "1 - Confirmar cadastro.\n");
		Lib.cprintf("RED", "2 - Cancelar cadastro.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = ReadChoice(2);

		if (escolha == 1) {
			try {
				// No momento esse try-catch é inútil, mas quando fomos usar tabela hash, pode haver a possibilidade de colisão e nesse caso uma exceção será lançada.
				arquivo.create(object);
				Lib.clearScreen();
				Lib.cprintf("BOLD GREEN", "%s cadastrado com sucesso!\n\n", obj);
			} catch (Exception e) {
				Lib.cprintf("BOLD RED", "\n%s falha ao cadastrar.\n\n", obj);
			}
		}

		else {
			Lib.printdiv(1, 0, "Cadastro cancelado");
		}
	}

	static <T extends Registro> T Read(boolean print, String obj, Arquivo<T> arquivo) throws Exception {
		
		if (print) {
			Lib.clearScreen();
			Lib.printdiv(1, "Consultando na base de dados: %ss", obj);
		}
		
		System.out.printf("Insira o ID do %s: ", obj);
		int ID = Lib.readInt();
		
		T object = null;

		try {
			object = arquivo.read(ID);
			if (print) {
				Lib.clearScreen();
				Lib.cprintf("BOLD GREEN", "%s encontrado com sucesso!\n\n", obj);
				System.out.println(object + "\n");
			}
		} catch (Exception e) {
			if (print) {
				Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", obj);
			} else {
				throw new Exception();	
			}
		}

		return object;
	}

	static <T extends Registro> void Update(String obj, Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Atualizando a base de dados: %ss", obj);
		
		T object;

		try { object = Read(false, obj, arquivo); }
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", obj);
			return;
		}

		System.out.println("\n" + object + "\n");

		Lib.cprintf("GREEN", "1 - Atualizar os dados.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = ReadChoice(2);

		if (escolha == 1) {
			System.out.println();
			object = arquivo.readNewInstance();
			System.out.println("\n" + object + "\n");
		} else {
			Lib.printdiv(1, 0, "Atualização cancelada");
			return;
		}

		Lib.cprintf("GREEN", "1 - Confirmar atualização.\n");
		Lib.cprintf("RED", "2 - Cancelar atualização.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		escolha = ReadChoice(2);

		if (escolha == 1) {
			arquivo.update(object);
			Lib.clearScreen();
			Lib.cprintf("BOLD GREEN", "%s atualizado com sucesso!\n\n", obj);
		}

		else {
			Lib.printdiv(1, 0, "Cadastro cancelado");
		}
	}

	static <T extends Registro> void Delete(String obj, Arquivo<T> arquivo) throws Exception {
		
		Lib.clearScreen();
		Lib.printdiv(1, "Excluindo da base de dados: %ss", obj);

		T object;

		try { object = Read(false, obj, arquivo); }
		catch (Exception e) {
			Lib.cprintf("BOLD RED", "\n%s não encontrado.\n\n", obj);
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
			Lib.cprintf("BOLD GREEN", "%s excluído com sucesso!\n\n", obj);
		}

		else {
			Lib.printdiv(1, 0, "Exclusão cancelada");
		}
	}

	static <T extends Registro> void CRUD(String obj, Arquivo<T> arquivo) throws Exception {

		Lib.clearScreen();
		
		int escolha;
		
		do {
			Lib.printdiv(1, "Base de dados: %ss", obj);

			System.out.println("1 - Cadastrar.");
			System.out.println("2 - Consultar.");
			System.out.println("3 - Atualizar.");
			System.out.println("4 - Deletar.");
			System.out.println("\n0 - Voltar.");
			System.out.print("\nEscolha uma das opções acima: ");

			escolha = ReadChoice(4);

			switch (escolha) {
			case 1:
				Create(obj, arquivo);
				break;
			case 2:
				Read(true, obj, arquivo);
				break;
			case 3:
				Update(obj, arquivo);
				break;
			case 4:
				Delete(obj, arquivo);
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
				Arquivo<Livro> arquivo;
				arquivo = new Arquivo<>(Livro.getConstructor(), "dados/livros.db");
				CRUD("Livro", arquivo);
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