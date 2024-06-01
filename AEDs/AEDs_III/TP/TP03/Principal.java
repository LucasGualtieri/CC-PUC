package TP03;

import java.util.List;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.LinkedList;
import java.nio.file.DirectoryStream;

import TP03.Entidades.Livros.*;
import TP03.Entidades.Autores.*;
import TP03.EstruturasDeDados.Compressao.*;

class Principal {

	static final String path = "AEDs/AEDs_III/TP/TP03/Entidades/";

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

		if (escolha != 1) Lib.cprintf("BOLD RED", "Cadastro cancelado.\n\n");

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
			Lib.printdiv(1, "Pesquisando na base de dados: %s", arquivo.getNomePlural());
		}

		T object = null;

		try {
			int ID = arquivo.read();

			// Esse boco permite que o programa se comporte corretamente quando o usuário decide voltar para o menu anterior
			if (ID == 0) {
				Lib.clearScreen();
				return null;
			}

			if (ID != -1) {
				object = arquivo.read(ID);
				if (print) {
					Lib.clearScreen();
					Lib.cprintf("BOLD GREEN", "%s encontrado com sucesso!\n\n", arquivo.getNome());
					System.out.println(object + "\n");
				}
			}

			else {

				List<T> lista = arquivo.readInvertida();

				Lib.clearScreen();

				if (!lista.isEmpty()) {
					Lib.cprintf("BOLD GREEN", "Os seguintes %s foram encontrados:\n\n", arquivo.getNomePluralLowerCase());
					int[] i = {1};
					lista.forEach((obj) -> {
						System.out.printf("%d- %s", i[0]++, obj.toCSV());
					});
					System.out.println();
				}

				else {
					Lib.cprintf("BOLD RED", "Nenhum %s encontrado!\n\n", arquivo.getNomeLowerCase());
				}
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
			newObject = arquivo.readNewInstance(oldObject);
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

		if (escolha != 1) Lib.cprintf("BOLD RED", "Atualização cancelada.\n\n");

		else {
			try {
				arquivo.update(oldObject.getID(), newObject);
				Lib.cprintf("BOLD GREEN", "%s atualizado com sucesso!\n\n", arquivo.getNome());
				System.out.println(newObject + "\n");
			}
			catch (Exception e) {
				Lib.cprintf("BOLD RED", "Falha ao atualizar %s.\n", arquivo.getNomeLowerCase());
				Lib.cprintf("BOLD RED", "Motivo: %s.\n\n", e.getMessage());
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

	static <T extends Registro> void Backup(Arquivo<T> arquivo) throws Exception  {

		Lib.clearScreen();
		Lib.printdiv(1, "Realizando backup na base de dados: %s", arquivo.getNomePlural());

		Lib.cprintf("GREEN", "1 - Confirmar backup.\n");
		Lib.cprintf("RED", "2 - Cancelar backup.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = Lib.ReadChoice(2);

		Lib.clearScreen();

		if (escolha != 1) {
			Lib.cprintf("BOLD RED", "Backup cancelado.\n\n");
			return;
		}

		Path folderPath = Paths.get(path + arquivo.getNomePlural() + "/Dados");

		LZW compress = new LZW(arquivo.getNomePlural(), path + "../Backups/", true);

		try (DirectoryStream<Path> stream = Files.newDirectoryStream(folderPath)) {
			for (Path filePath : stream) {
				String fileName = filePath.getFileName().toString();
				byte[] fileBytes = Files.readAllBytes(filePath);
				compress.add(fileName, fileBytes);
			}
		}
		
		catch (Exception e) {
			e.printStackTrace();
			Lib.cprintf("BOLD RED", "Falha ao fazer o backup.\n\n");
			return;
		}

		Lib.cprintf("BOLD GREEN", "Dados dos %s salvos e comprimidos com sucesso!\n\n", arquivo.getNomePluralLowerCase());

		compress.close();

		System.out.println(compress);
	}

	static <T extends Registro> void RecoverBackup(Arquivo<T> arquivo) throws Exception  {

		Lib.clearScreen();
		Lib.printdiv(1, "Recuperando backup na base de dados: %s", arquivo.getNomePlural());

		Path folderPath = Paths.get(path + "../Backups/");

		List<Path> files = new LinkedList<>();

		try (DirectoryStream<Path> stream = Files.newDirectoryStream(folderPath)) {
			for (Path file : stream) {
				String str = file.getFileName().toString().substring(0, arquivo.getNomePlural().length());
				if (Files.isRegularFile(file) && str.equals(arquivo.getNomePlural())) files.add(file);
			}
		}

		catch (Exception e) {
			// e.printStackTrace();
			Lib.cprintf("BOLD RED", "Falha ao fazer a recuperação.\n\n");
			return;
		}

		System.out.println("Backups encontrados:\n");

		int i = 0;
		for (Path file : files) {
			String fileName = file.getFileName().toString();
			System.out.printf("%d - %s\n", ++i, fileName);
		}

		System.out.println("\n0 - Voltar.");

		System.out.print("\nEscolha uma das opções acima: ");

		int escolha = Lib.ReadChoice(i);

		if (escolha == 0) {
			Lib.clearScreen();
			Lib.cprintf("BOLD RED", "Recuperação cancelada.\n\n");
			return;
		}

		Path backup = files.get(escolha - 1);

		Lib.cprintf("GREEN", "\n1 - Confirmar recuperação.\n");
		Lib.cprintf("RED", "2 - Cancelar recuperação.\n");
		System.out.print("\nEscolha uma das opções acima: ");

		escolha = Lib.ReadChoice(2);

		Lib.clearScreen();

		if (escolha != 1) {
			Lib.cprintf("BOLD RED", "Recuperação cancelada.\n\n");
			return;
		}

		// System.out.println("File name: " + backup.getFileName());

		LZW decompress = new LZW(arquivo.getNomePlural(), path + "../Backups/", false);

		decompress.recover(backup);

		Lib.clearScreen();
		Lib.cprintf("BOLD GREEN", "Dados dos %s recuperados e descomprimidos com sucesso!\n\n", arquivo.getNomePluralLowerCase());
	}

	// A função CRUD permite o usuário escolher qual operação CRUD deseja executar.
	static <T extends Registro> void CRUD(Arquivo<T> arquivo) throws Exception {

		Lib.clearScreen();

		int choice;

		do {
			choice = arquivo.CRUDMenu();

			switch (choice) {
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
			case 6:
				Backup(arquivo);
				break;
			case 7:
				RecoverBackup(arquivo);
				break;
			}

		} while (choice != 0);
	}

	// A função main permite que o usuário escolha a base de dados que deseja trabalhar.
	public static void main(String[] args) throws Exception {

		int choice;

		Arquivo<Livro> arquivo = null;

		do {
			Lib.clearScreen();
			Lib.printdiv(1, "SGBD");

			System.out.println("1 - Livros.");
			System.out.println("2 - Autores.\n");
			System.out.println("0 - Sair do programa.\n");
			System.out.print("Escolha uma das bases de dados: ");

			choice = Lib.ReadChoice(2);

			switch (choice) {
				case 1:
					arquivo = new ArquivoLivro<>(path + "Livros/Dados/");
				break;
				case 2:
					arquivo = new ArquivoAutor<>(path + "Autores/Dados/");
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