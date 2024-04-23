package TP02.Entidades.Livros;

// import java.io.IOException;
import java.lang.reflect.Constructor;
import java.util.List;

import TP02.Lib;
import TP02.Registro;
import TP02.EstruturasDeDados.HashExtensivel;
import TP02.Entidades.Livros.Indices.ParIsbnId;
// import TP02.Entidades.Livros.Indices.ParTituloID;
import TP02.Arquivo;

public class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	// IndicadorDeTamanho + ID + ISBN + Titulo + Autor + Preço
	private final short registerMinLength = 35; // 2 + 4 +  (2 + 13) (2 + 3) + (2 + 3) + 4.

	private final String nome = "Livro";

	HashExtensivel<ParIsbnId> indiceIndiretoISBN;

	@SuppressWarnings("unchecked")
	public ArquivoLivro(String filePath) throws NoSuchMethodException, SecurityException, Exception {
		
		super((Constructor<T>)Livro.getConstructor(), "Livro", filePath);

		indiceIndiretoISBN = new HashExtensivel<>(
			ParIsbnId.getConstructor(), 4,
			filePath + nome + ".hashTitulo_d.db",
			filePath + nome + ".hashTitulo_c.db"
		);

		// indiceTitulo = new HashExtensivel<>(
		// 	ParTituloID.getConstructor(), 3,
		// 	filePath + nome + ".hashTitulo_d.db",
		// 	filePath + nome + ".hashTitulo_c.db"
		// );
	}

	public int create(T object) throws Exception {
		super.create(true, registerMinLength, object);
	    indiceIndiretoISBN.create(new ParIsbnId(((Livro)object).getISBN(), object.getID()));
		return object.getID();
	}

	protected int create(boolean createNewID, T object) throws Exception {
		super.create(createNewID, registerMinLength, object);
		indiceIndiretoISBN.create(new ParIsbnId(((Livro)object).getISBN(), object.getID()));
		return object.getID();
	}

	// Essa é uma função auxiliar à função read que permite que cada classe implemente seus métodos de busca
	// baseado nos atributos específicos daquela classe
	public int read() throws Exception {

		// System.out.printf("Insira o ID do %s: ", getNomeLowerCase());
		System.out.println("Buscar por:");
		System.out.println("1 - ID.");
		System.out.println("2 - ISBN.");
		// Lib.cprintf(Lib.RED, "2 - ISBN. Ainda não implementado.\n");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");

		int choice = Lib.ReadChoice(2);
		int ID = 0;

		switch (choice) {
		case 1:
			System.out.printf("Insira o ID do livro: ");
			ID = Lib.readInt();
		break;
		case 2:
			System.out.printf("Insira o ISBN do livro: ");
			String ISBN = Livro.readISBN();
			ParIsbnId pii = indiceIndiretoISBN.read(ParIsbnId.hashIsbn(ISBN));
			if (pii != null) ID = pii.getId();
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

		// System.out.println("\nOrdenar por:");
		// System.out.println("1 - Ordem crescente");
		// System.out.println("2 - Ordem descrescente");
		// System.out.println("\n0 - Voltar.");

		// System.out.print("Escolha uma das opções acima: ");
		
		// final int choice2 = Lib.ReadChoice(2);
		
		// final int asc = choice2 == 1 ? 1 : -1;

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