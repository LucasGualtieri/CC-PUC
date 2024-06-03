package TP03.Entidades.Livros;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.text.Normalizer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.regex.Pattern;

import TP03.*;
// import TP03.Entidades.*;
import TP03.EstruturasDeDados.*;
import TP03.Entidades.Livros.Indices.*;

public class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	// IndicadorDeTamanho + ID + ISBN + Titulo + Autor + Preço
	private final short registerMinLength = 35; // 2 + 4 + (2 + 13) (2 + 3) + (2 + 3) + 4.

	// private final String nome = "Livro";

	HashExtensivel<ParIsbnId> indiceIndiretoISBN;
	ListaInvertida listaInvertidaTitulos;

	HashSet<String> stopWords;

	@SuppressWarnings("unchecked")
	public ArquivoLivro(String filePath) throws NoSuchMethodException, SecurityException, Exception {

		super((Constructor<T>)Livro.getConstructor(), "Livro", filePath);

		indiceIndiretoISBN = new HashExtensivel<>(
			ParIsbnId.getConstructor(), 4,
			filePath + nome + ".hashISBN_d.db",
			filePath + nome + ".hashISBN_c.db"
		);

		listaInvertidaTitulos = new ListaInvertida(
			4,
			filePath + nome + "dicionario.listainvTitulo.db",
			filePath + nome + "blocos.listainvTitulo.db"
		);

		CriarStopWordsList();
	}

	public int create(T object) throws Exception {
		super.create(true, registerMinLength, object);
	    indiceIndiretoISBN.create(new ParIsbnId(((Livro)object).getISBN(), object.getID()));
		createInvertida(((Livro)object).getTitulo(), object.getID());
		return object.getID();
	}
	
	protected int create(boolean createNewID, T object) throws Exception {
		super.create(createNewID, registerMinLength, object);
		indiceIndiretoISBN.create(new ParIsbnId(((Livro)object).getISBN(), object.getID()));
		createInvertida(((Livro)object).getTitulo(), object.getID());
		return object.getID();
	}

	// Essa é uma função auxiliar à função read que permite que cada classe implemente seus métodos de busca
	// baseado nos atributos específicos daquela classe
	public int read() throws Exception {

		// System.out.printf("Insira o ID do %s: ", getNomeLowerCase());
		System.out.println("Buscar por:");
		System.out.println("1 - ID.");
		System.out.println("2 - ISBN.");
		System.out.println("3 - Título.");
		System.out.println("\n0 - Voltar.");
		System.out.print("\nEscolha uma das opções acima: ");

		int choice = Lib.ReadChoice(3);
		int ID = 0;

		switch (choice) {
			case 1:
				System.out.printf("Insira o ID do livro: ");
				ID = Lib.readInt();
			break;
			case 2:
				System.out.printf("Insira o ISBN do livro: ");
				String ISBN = Livro.readISBN(false);
				ParIsbnId pii = indiceIndiretoISBN.read(ParIsbnId.hashIsbn(ISBN));
				if (pii != null) ID = pii.getId();
			case 3:
				ID = -1; // Condição que define que a pesquisa será feita por meio da lista invertida.
			break;
			default:
				// System.out.printf("Insira o título do livro: ");
				// ID = indiceTitulo.read(Lib.readString()).getId();
			break;
		}

		return ID;
	}

	// ------------ Lista Invertida --------------------------

	private void CriarStopWordsList() {

		stopWords = new HashSet<>();
		
		String filePath = "AEDs/AEDs_III/TP/TP03/EstruturasDeDados/StopWords.txt";
		String fileLine;

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            while ((fileLine = br.readLine()) != null) {
				stopWords.add(fileLine);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	private List<String> removerStopWords(String string) {

		List<String> arrayLimpo = new ArrayList<>();

		for (String str : string.split(" ")) {
			if (!stopWords.contains(str)) {
				arrayLimpo.add(str);
			}
		}

		return arrayLimpo;
	}

	private String removerAcentos(String str) {
		String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD);
		Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
		return pattern.matcher(nfdNormalizedString).replaceAll("");
	}

	private List<String> LimparString(String str) {
		str = removerAcentos(str.toLowerCase());
		return removerStopWords(str);
	}

	private void createInvertida(String titulo, int ID) throws Exception {

		List<String> lista = LimparString(titulo);

		for (String str : lista) {
			// System.out.println("Resultado: " + str);
			listaInvertidaTitulos.create(str, ID);
		}
	}

	private void deleteInvertida(String titulo, int ID) throws Exception {

		List<String> lista = LimparString(titulo);

		for (String str : lista) {
			listaInvertidaTitulos.delete(str, ID);
		}
	}

	private void IntersecDeConjuntos(HashSet<Integer> conjunto1, int[] conjunto2) {

		HashSet<Integer> conjunto2Set = new HashSet<>();

		for (int i : conjunto2) conjunto2Set.add(i);

		conjunto1.retainAll(conjunto2Set);
	}

	public List<T> readInvertida() throws Exception {

		System.out.printf("Insira o título do livro: ");
		String titulo = Lib.readString();

		List<String> palavras = LimparString(titulo);

		HashSet<Integer> conjutoIDs = new HashSet<>();
		
		int[] dados = listaInvertidaTitulos.read(palavras.get(0));
		
		for (int i : dados) conjutoIDs.add(i);

		for (int i = 1; i < palavras.size(); i++) {
			dados = listaInvertidaTitulos.read(palavras.get(i));
			IntersecDeConjuntos(conjutoIDs, dados);
			if (conjutoIDs.isEmpty()) break;
		}

		List<T> objects = new LinkedList<>();

		for (int ID : conjutoIDs) {
			try { objects.add(read(ID)); }
			catch (Exception e) {}
		}

		return objects;
	}

	// ---------------------------------------------------------------

	public void delete(int ID) throws Exception {
		
		Livro l = (Livro)super.read(ID);
		
		super.delete(ID);
		
		String ISBN = l.getISBN();
		
		indiceIndiretoISBN.delete(ParIsbnId.hashIsbn(ISBN));
		deleteInvertida(((Livro)l).getTitulo(), l.getID());
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

	public int CRUDMenu() {

		Lib.printdiv(1, "Base de dados: Livros");

		System.out.println("1 - Cadastrar.");
		System.out.println("2 - Pesquisar.");
		System.out.println("3 - Atualizar.");
		System.out.println("4 - Deletar.");
		System.out.println("5 - Listar todos os livros.");
		System.out.println("6 - Fazer backup compactado.");
		System.out.println("7 - Recuperar backup compactado.\n");
		System.out.println("0 - Voltar.\n");
		System.out.print("Escolha uma das opções acima: ");

		return Lib.ReadChoice(7);
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }
	public String getNomePlural() { return nome + "s"; }
	public String getNomePluralLowerCase() { return nome.toLowerCase() + "s"; }
}