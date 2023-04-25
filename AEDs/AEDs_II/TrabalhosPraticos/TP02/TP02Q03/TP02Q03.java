import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

class Lista {
	private Personagem[] array;
	private int n;

	public Lista() {
		this(86);
	}

	public Lista(int tamanho) {
		array = new Personagem[tamanho];
		n = 0;
	}

	int getN() {
		return n;
	}

	Personagem[] getArray() {
		return array;
	}

	// ANCHOR - listaAction
	public void listaAction(String str) throws Exception {

		String listaAction = str.substring(0, 2);

		if (listaAction.equals("II") || listaAction.equals("I*") || listaAction.equals("IF")) {

			Personagem personagem = new Personagem();
			// String filePath = str.substring(str.indexOf('/', 3)); // Alternativa do Verde
			String filePath = str.substring(str.indexOf("./", 3));
			personagem.Ler(filePath);

			switch (listaAction) {
				case "II":
					// System.out.println("Inserindo no Início");
					this.inserirInicio(personagem);
					break;
				case "I*":
					int insertionIdex = Integer.parseInt(str.substring(3, str.indexOf(" ", 3)));
					// System.out.println("Inserindo em " + insertionIdex);
					this.inserir(personagem, insertionIdex);
					break;
				default:
					// System.out.println("Inserindo no Fim");
					this.inserirFim(personagem);
					break;
			}
		} else {
			switch (listaAction) {
				case "RI":
					System.out.println("(R) " + array[0].getNome());
					this.removerInicio();
					break;
				case "R*":
					// System.out.println(str.substring(3));
					int removalIdex = Integer.parseInt(str.substring(3).trim());
					System.out.println("(R) " + array[removalIdex].getNome());
					this.remover(removalIdex);
					break;
				case "RF":
					System.out.println("(R) " + array[n - 1].getNome());
					this.removerFim();
					break;
				default:
			}
		}
	}

	/**
	 * Insere um elemento na primeira posicao da lista e move os demais
	 * elementos para o fim da lista.
	 * 
	 * @param personagem elemento a ser inserido.
	 * @throws Exception Se a lista estiver cheia.
	 */
	public void inserirInicio(Personagem personagem) throws Exception {

		// validar insercao
		if (n >= array.length) {
			throw new Exception("Erro ao inserir!");
		}

		// levar elementos para o fim do array
		for (int i = n; i > 0; i--) {
			array[i] = array[i - 1];
		}

		array[0] = personagem;
		n++;
	}

	/**
	 * Insere um elemento na ultima posicao da lista.
	 * 
	 * @param personagem elemento a ser inserido.
	 * @throws Exception Se a lista estiver cheia.
	 */
	public void inserirFim(Personagem personagem) throws Exception {

		// validar insercao
		if (n >= array.length) {
			throw new Exception("Erro ao inserir!");
		}

		array[n] = personagem;
		n++;
	}

	/**
	 * Insere um elemento em uma posicao especifica e move os demais
	 * elementos para o fim da lista.
	 * 
	 * @param personagem elemento a ser inserido.
	 * @param pos        Posicao de insercao.
	 * @throws Exception Se a lista estiver cheia ou a posicao invalida.
	 */
	public void inserir(Personagem personagem, int pos) throws Exception {

		// validar insercao
		if (n >= array.length || pos < 0 || pos > n) {
			throw new Exception("Erro ao inserir!");
		}

		// levar elementos para o fim do array
		for (int i = n; i > pos; i--) {
			array[i] = array[i - 1];
		}

		array[pos] = personagem;
		n++;
	}

	/**
	 * Remove um elemento da primeira posicao da lista e movimenta
	 * os demais elementos para o inicio da mesma.
	 * 
	 * @return resp int elemento a ser removido.
	 * @throws Exception Se a lista estiver vazia.
	 */
	public Personagem removerInicio() throws Exception {
		// validar remocao
		if (n == 0) {
			throw new Exception("Erro ao remover!");
		}

		Personagem resp = array[0];
		n--;

		for (int i = 0; i < n; i++) {
			array[i] = array[i + 1];
		}

		return resp;
	}

	/**
	 * Remove um elemento da ultima posicao da lista.
	 * 
	 * @return resp int elemento a ser removido.
	 * @throws Exception Se a lista estiver vazia.
	 */
	public Personagem removerFim() throws Exception {

		// validar remocao
		if (n == 0) {
			throw new Exception("Erro ao remover!");
		}

		return array[--n];
	}

	/**
	 * Remove um elemento de uma posicao especifica da lista e
	 * movimenta os demais elementos para o inicio da mesma.
	 * 
	 * @param pos Posicao de remocao.
	 * @return resp int elemento a ser removido.
	 * @throws Exception Se a lista estiver vazia ou a posicao for invalida.
	 */
	public Personagem remover(int pos) throws Exception {

		// validar remocao
		if (n == 0 || pos < 0 || pos >= n) {
			throw new Exception("Erro ao remover!");
		}

		Personagem resp = array[pos];
		n--;

		for (int i = pos; i < n; i++) {
			array[i] = array[i + 1];
		}

		return resp;
	}

	/**
	 * Mostra os elementos da lista separados por espacos.
	 */
	public void mostrar() {
		System.out.print("[ ");
		for (int i = 0; i < n; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println("]");
	}

	/**
	 * Procura um elemento e retorna se ele existe.
	 * 
	 * @param personagem elemento a ser pesquisado.
	 * @return <code>true</code> se o array existir,
	 *         <code>false</code> em caso contrario.
	 */
	public boolean pesquisar(Personagem personagem) {
		boolean retorno = false;
		for (int i = 0; i < n && retorno == false; i++) {
			retorno = (array[i] == personagem);
		}
		return retorno;
	}
}

class Personagem {
	private String nome;
	private int altura;
	private double peso;
	private String corDoCabelo;
	private String corDaPele;
	private String corDosOlhos;
	private String anoNascimento;
	private String genero;
	private String homeworld;

	Personagem() {
		setNome("");
		setAltura(0);
		setPeso(0.0);
		setCorDoCabelo("");
		setCorDaPele("");
		setCorDosOlhos("");
		setAnoNascimento("");
		setGenero("");
		setHomeworld("");
	}

	// Setter e Getter para o atributo nome
	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNome() {
		return nome;
	}

	// Setter e Getter para o atributo altura
	public void setAltura(int altura) {
		this.altura = altura;
	}

	public int getAltura() {
		return altura;
	}

	// Setter e Getter para o atributo peso
	public void setPeso(double peso) {
		this.peso = peso;
	}

	public double getPeso() {
		return peso;
	}

	// Setter e Getter para o atributo corDoCabelo
	public void setCorDoCabelo(String corDoCabelo) {
		this.corDoCabelo = corDoCabelo;
	}

	public String getCorDoCabelo() {
		return corDoCabelo;
	}

	// Setter e Getter para o atributo corDaPele
	public void setCorDaPele(String corDaPele) {
		this.corDaPele = corDaPele;
	}

	public String getCorDaPele() {
		return corDaPele;
	}

	// Setter e Getter para o atributo corDosOlhos
	public void setCorDosOlhos(String corDosOlhos) {
		this.corDosOlhos = corDosOlhos;
	}

	public String getCorDosOlhos() {
		return corDosOlhos;
	}

	// Setter e Getter para o atributo anoNascimento
	public void setAnoNascimento(String anoNascimento) {
		this.anoNascimento = anoNascimento;
	}

	public String getAnoNascimento() {
		return anoNascimento;
	}

	// Setter e Getter para o atributo genero
	public void setGenero(String genero) {
		this.genero = genero;
	}

	public String getGenero() {
		return genero;
	}

	// Setter e Getter para o atributo homeworld
	public void setHomeworld(String homeworld) {
		this.homeworld = homeworld;
	}

	public String getHomeworld() {
		return homeworld;
	}

	// ANCHOR - Ler
	public void Ler(String filePath) throws Exception {

		FileInputStream fstream = new FileInputStream(filePath);
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(fstream));
		String jsonString = bufferedReader.readLine();
		bufferedReader.close();

		// Separando keys e values e atribuindo a suas variaveis
		String[] pairs = jsonString.substring(1, jsonString.length() - 1).split(", '");
		for (String pair : pairs) {
			String[] keyValue = pair.split(":");
			String key = keyValue[0].replaceAll("\'", "");
			String value = keyValue[1].replaceAll("\'", "").trim();

			if (key.equals("name")) {
				setNome(value);
			} else if (key.equals("height")) {
				if (value.equals("unknown")) {
					setAltura(0);
					continue;
				}
				setAltura(Integer.parseInt(value));
			} else if (key.equals("mass")) {
				if (value.equals("unknown")) {
					setPeso(0);
					continue;
				}
				setPeso(Double.parseDouble(value.replaceAll(",", "")));
			} else if (key.equals("hair_color")) {
				setCorDoCabelo(value);
			} else if (key.equals("skin_color")) {
				setCorDaPele(value);
			} else if (key.equals("eye_color")) {
				setCorDosOlhos(value);
			} else if (key.equals("birth_year")) {
				setAnoNascimento(value);
			} else if (key.equals("gender")) {
				setGenero(value);
			} else if (key.equals("homeworld")) {
				setHomeworld(value);
			} else {
				break;
			}
		}
	}

	// ANCHOR - Imprimir
	public void Imprimir() {

		// Prints com MyIO pra bugar os acentos
		System.out.print(" ## " + this.nome);
		System.out.print(" ## " + this.altura);
		if (this.peso % 1.0 != 0) {
			System.out.print(" ## " + String.format("%s", this.peso));
		} else {
			System.out.print(" ## " + String.format("%.0f", this.peso));
		}
		System.out.print(" ## " + this.corDoCabelo);
		System.out.print(" ## " + this.corDaPele);
		System.out.print(" ## " + this.corDosOlhos);
		System.out.print(" ## " + this.anoNascimento);
		System.out.print(" ## " + this.genero);
		System.out.print(" ## " + this.homeworld);
		System.out.print(" ## ");
	}

	public Personagem clone() {
		Personagem cloned = new Personagem();

		cloned.nome = this.nome;
		cloned.altura = this.altura;
		cloned.peso = this.peso;
		cloned.corDoCabelo = this.corDoCabelo;
		cloned.corDaPele = this.corDaPele;
		cloned.corDosOlhos = this.corDosOlhos;
		cloned.anoNascimento = this.anoNascimento;
		cloned.genero = this.genero;
		cloned.homeworld = this.homeworld;

		return cloned;
	}
}

public class TP02Q03 {
	// ANCHOR - Main
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);

		Lista lista = new Lista(70);

		String input = scanner.nextLine();

		while (!input.equals("FIM")) {
			Personagem personagem = new Personagem();

			personagem.Ler(input);
			// personagem.Imprimir();

			lista.inserirFim(personagem);

			input = scanner.nextLine();
		}

		int listaActionsNumber = Integer.parseInt(scanner.nextLine());

		for (int i = 0; i < listaActionsNumber; i++) {
			lista.listaAction(scanner.nextLine());
		}

		for (int i = 0; i < lista.getN(); i++) {
			System.out.print("[" + i + "] ");
			lista.getArray()[i].Imprimir();
			System.out.print((i < lista.getN() - 1) ? "\n" : "");
		}

		scanner.close();
	}
}

// Essa alternativa serveria caso quisesse usar MyIO para printar os nomes com
// acentos bugados
// RandomAccessFile file = new RandomAccessFile(filePath, "r");
// String jsonString = file.readLine();
// file.close();

// Método alternativo pra lidar com o JSON
// String nomeKey = input.substring(input.indexOf("name"), input.indexOf("',") +
// 2);
// // String nomeValue = nomeKey.substring(nomeKey.indexOf(": '") + 3,
// nomeKey.indexOf("',"));

// Personagem(String nome, int altura, double peso, String corDoCabelo, String
// corDaPele, String corDosOlhos,
// String anoNascimento, String genero, String homeworld) {
// setNome(nome);
// setAltura(altura);
// setPeso(peso);
// setCorDoCabelo(corDoCabelo);
// setCorDaPele(corDaPele);
// setCorDosOlhos(corDosOlhos);
// setAnoNascimento(anoNascimento);
// setGenero(genero);
// setHomeworld(homeworld);
// }