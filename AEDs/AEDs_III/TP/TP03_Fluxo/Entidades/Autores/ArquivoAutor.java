package TP03.Entidades.Autores;

import java.util.List;
import java.lang.reflect.Constructor;

import TP03.*;
import TP03.EstruturasDeDados.*;
import TP03.Entidades.Autores.Indices.ParCPFId;

public class ArquivoAutor<T extends Registro> extends Arquivo<T> {

	// IndicadorDeTamanho + ID + CPF + Nome + Sobrenome + Idade
	private final short registerMinLength = 33; // 2 + 4 + (2 + 11) + (2 + 3) (2 + 3) + 4.
	// private final String nome = "Autor";

	HashExtensivel<ParCPFId> indiceIndiretoCPF;
	// HashExtensivel<ParNomeID> indiceNome;

	@SuppressWarnings("unchecked")
	public ArquivoAutor(String filePath) throws NoSuchMethodException, SecurityException, Exception {
		
		super((Constructor<T>)Autor.getConstructor(), "Autor", filePath);

		indiceIndiretoCPF = new HashExtensivel<>(
			ParCPFId.getConstructor(), 4,
			filePath + nome + ".hashCPF_d.db",
			filePath + nome + ".hashCPF_c.db"
		);
	}

	public int create(T object) throws Exception {
		super.create(true, registerMinLength, object);
		indiceIndiretoCPF.create(new ParCPFId(((Autor)object).getCPF(), object.getID()));
		return object.getID();
	}

	protected int create(boolean createNewID, T object) throws Exception {
		super.create(createNewID, registerMinLength, object);
		indiceIndiretoCPF.create(new ParCPFId(((Autor)object).getCPF(), object.getID()));
		return object.getID();
	}

	// Essa é uma função auxiliar à função read que permite que cada classe implemente seus métodos de busca
	// baseado nos atributos específicos daquela classe
	public int read() throws Exception {

		// System.out.printf("Insira o ID do %s: ", getNomeLowerCase());
		System.out.println("Buscar por:");
		System.out.println("1 - ID.");
		System.out.println("2 - CPF.");
		Lib.cprintf(Lib.RED, "3 - Nome / Sobrenome. Ainda não implementado.\n");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");

		int choice = Lib.ReadChoice(2);
		int ID = 0;

		switch (choice) {
			case 1:
				System.out.printf("Insira o ID do autor: ");
				ID = Lib.readInt();
			break;
			case 2:
				System.out.printf("Insira o CPF do autor: ");
				String CPF = Autor.readCPF(false);
				ParCPFId pii = indiceIndiretoCPF.read(ParCPFId.hashCPF(CPF));
				if (pii != null) ID = pii.getId();
			break;
			default:
				// System.out.printf("Insira o título do livro: ");
				// ID = indiceTitulo.read(Lib.readString()).getId();
			break;
		}

		return ID;
	}

	// public void update(int ID, T newObj) throws IOException, Exception {
	// 	ParIDEndereco pie = indiceDireto.read(ID);
	// 	delete(pie.getId());
	// 	create(false, newObj);
	// }

	public void delete(int ID) throws Exception {
		
		Autor a = (Autor)super.read(ID);
		
		super.delete(ID);

		String CPF = a.getCPF();

		indiceIndiretoCPF.delete(ParCPFId.hashCPF(CPF));
	}

	// Essa função permite que o usuário escolha de que forma gostaria de apresentar os dados na listagem
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
				list.sort((l1, l2) -> Integer.compare(((Autor)l1).getIdade(), ((Autor)l2).getIdade()));
			break;
		}

		return choice;
	}

	public int CRUDMenu() {

		Lib.printdiv(1, "Base de dados: Autores");

		System.out.println("1 - Cadastrar.");
		System.out.println("2 - Pesquisar.");
		System.out.println("3 - Atualizar.");
		System.out.println("4 - Deletar.");
		System.out.println("5 - Listar todos os autores.");
		System.out.println("6 - Fazer backup compactado.");
		System.out.println("7 - Recuperar backup compactado.\n");
		System.out.println("0 - Voltar.\n");
		System.out.print("Escolha uma das opções acima: ");

		return Lib.ReadChoice(7);
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }
	public String getNomePlural() { return nome + "es"; }
	public String getNomePluralLowerCase() { return nome.toLowerCase() + "es"; }
}