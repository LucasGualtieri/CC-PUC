package TP01.Autor;

import java.lang.reflect.Constructor;
import java.util.List;

import TP01.Arquivo;
import TP01.Registro;
import TP01.Lib;

public class ArquivoAutor<T extends Registro> extends Arquivo<T> {

	private final short registerMinLength = 35; // 2 + 4 +  (2 + 13) (2 + 3) + (2 + 3) + 4.

	// HashExtensivel<ParNomeID> indiceNome;

	@SuppressWarnings("unchecked")
	public ArquivoAutor(String nome, String filePath) throws NoSuchMethodException, SecurityException, Exception {
		
		super((Constructor<T>)Autor.getConstructor(), nome, filePath);

		// indiceTitulo = new HashExtensivel<>(
		// 	ParTituloID.getConstructor(),
		// 	3,
		// 	filePath + nome + ".hashTitulo_d.db",
		// 	filePath + nome + ".hashTitulo_c.db"
		// );
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }
	public String getNomePlural() { return nome + "es"; }
	public String getNomePluralLowerCase() { return nome.toLowerCase() + "es"; }
	
	public int create(T object) throws Exception {
		return create(true, registerMinLength, object);
	}

	protected int create(boolean createNewID, T object) throws Exception {
		return create(createNewID, registerMinLength, object);
	}

	public int read() throws Exception {

		// System.out.printf("Insira o ID do %s: ", getNomeLowerCase());
		System.out.println("Buscar por:");
		System.out.println("1 - ID.");
		Lib.cprintf(Lib.RED, "2 - Nome. Ainda não implementado.\n");
		Lib.cprintf(Lib.RED, "3 - Sobrenome. Ainda não implementado.\n");
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

	public int SortList(List<T> list) {
		System.out.println("Ordenar por:");
		System.out.println("1 - ID");
		System.out.println("2 - Nome");
		System.out.println("3 - Sobrenome");
		System.out.println("4 - Idade");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");
		
		int choice = Lib.ReadChoice(4);
		
		switch (choice) {
			case 1:
				list.sort((l1, l2) -> Integer.compare(l1.getID(), l2.getID()));
			break;
			case 2:
				list.sort((l1, l2) -> ((Autor)l1).getNome().compareTo(((Autor)l2).getNome()));
			break;
				case 3:
				list.sort((l1, l2) -> ((Autor)l1).getSobrenome().compareTo(((Autor)l2).getSobrenome()));
			break;
				case 4:
				list.sort((l1, l2) -> Integer.compare(((Autor)l1).getIdade(), ((Autor)l1).getIdade()));
			break;
		}

		return choice;
	}
}