package TP01.Livros;

// import java.io.IOException;
import java.lang.reflect.Constructor;
import java.util.List;

import TP01.Registro;
import TP01.Lib;
import TP01.Indices.Arquivo;
import TP01.Indices.HashExtensivel;

public class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	// IndicadorDeTamanho + ID + ISBN + Titulo + Autor + Preço
	private final short registerMinLength = 35; // 2 + 4 +  (2 + 13) (2 + 3) + (2 + 3) + 4.

	// HashExtensivel<ParTituloID> indiceIndireto;

	/*
	 * ID + Titulo + Autor + Preco respectivamente
	 * Foi feito uma estimativa do comprimento médio dos:
	 * Títulos e Nomes de autores de livros ao redor do mundo
	 * Fonte: Microsoft Copilot
	*/
	// private final short registerAvgLength = 12; // 4 + (2 + 14) + (2 + 12) + 4.

	HashExtensivel<ParTituloID> indiceTitulo;

	@SuppressWarnings("unchecked")
	public ArquivoLivro(String nome, String filePath) throws NoSuchMethodException, SecurityException, Exception {
		
		super((Constructor<T>)Livro.getConstructor(), nome, filePath);

		// indiceTitulo = new HashExtensivel<>(
		// 	ParTituloID.getConstructor(),
		// 	3,
		// 	filePath + nome + ".hashTitulo_d.db",
		// 	filePath + nome + ".hashTitulo_c.db"
		// );
	}

	public int create(T object) throws Exception {
		return create(true, registerMinLength, object);
	}

	protected int create(boolean createNewID, T object) throws Exception {
		return create(createNewID, registerMinLength, object);
	}

	// Essa é uma função auxiliar à função read que permite que cada classe implemente seus métodos de busca
	// baseado nos atributos específicos daquela classe
	public int read() throws Exception {

		// System.out.printf("Insira o ID do %s: ", getNomeLowerCase());
		System.out.println("Buscar por:");
		System.out.println("1 - ID.");
		Lib.cprintf(Lib.RED, "2 - ISBN. Ainda não implementado.\n");
		Lib.cprintf(Lib.RED, "3 - Título. Ainda não implementado.\n");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");

		int choice = Lib.ReadChoice(1);
		int ID = 0;

		switch (choice) {
		case 1:
			System.out.printf("Insira o ID do livro: ");
			ID = Lib.readInt();
		break;
		default:
			// System.out.printf("Insira o título do livro: ");
			// ID = indiceTitulo.read(Lib.readString()).getId();
			break;
		}

		return ID;
	}

	// Essa função permite que o usuário escolha de que forma gostaria de apresentar os dados na listagem
	public int SortList(List<T> list) {
		System.out.println("Ordenar por:");
		System.out.println("1 - ID");
		System.out.println("2 - ISBN");
		System.out.println("3 - Título");
		System.out.println("4 - Autor");
		System.out.println("5 - Preço.");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");
		
		int choice = Lib.ReadChoice(5);
		
		switch (choice) {
			case 1:
				list.sort((l1, l2) -> Integer.compare(l1.getID(), l2.getID()));
			break;
			case 2:
				list.sort((l1, l2) -> ((Livro)l1).getISBN().compareTo(((Livro)l2).getISBN()));
			break;
				case 3:
				list.sort((l1, l2) -> ((Livro)l1).getTitulo().compareTo(((Livro)l2).getTitulo()));
			break;
				case 4:
				list.sort((l1, l2) -> ((Livro)l1).getAutor().compareTo(((Livro)l2).getAutor()));
			break;
				case 5:
				list.sort((l1, l2) -> Float.compare(((Livro)l1).getPreco(), ((Livro)l2).getPreco()));
			break;
		}

		return choice;
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }
	public String getNomePlural() { return nome + "s"; }
	public String getNomePluralLowerCase() { return nome.toLowerCase() + "s"; }
}