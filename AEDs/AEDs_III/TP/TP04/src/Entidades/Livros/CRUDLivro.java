package TP04.src.Entidades.Livros;

import java.util.List;

import TP02.Entidades.Livros.Livro;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.LinkedList;
import java.nio.file.DirectoryStream;

import TP04.src.utils.*;

public class CRUDLivro {

	// A função CRUD permite o usuário escolher qual operação CRUD deseja executar.
	public void CRUD(Arquivo<RegistroLivro> arquivo) throws Exception {

		Utils.clearScreen();

		int choice;

		do {
			choice = arquivo.CRUDMenu();

			switch (choice) {
				// case 1: Create(arquivo);		break;
				// case 2: Read(true, arquivo); 	break;
				// case 3: Update(arquivo);		break;
				// case 4: Delete(arquivo);		break;
				// case 5: Listar(arquivo);		break;
				// case 6: Backup(arquivo);		break;
				// case 7: RecoverBackup(arquivo); break;
			}

		} while (choice != 0);
	}

}
