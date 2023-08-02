import java.util.Scanner;

// clear && javac Assassinos.java && java Assassinos < pub.in > out.txt

class Assassino {
	private String nome;
	private int assassinatos;

	public Assassino() {
		this("");
	}

	public Assassino(String nome) {
		this.nome = nome;
		this.novoAssassinato();
	}

	void setNome(String nome) {
		this.nome = nome;
	}

	String getNome() {
		return nome;
	}

	int getAssassinatos() {
		return assassinatos;
	}

	public void novoAssassinato() {
		this.assassinatos++;
	}
}

class ListaAssassinos {
	private Assassino[] array;
	private int n;

	public ListaAssassinos() {
		this(30);
	}

	public ListaAssassinos(int tamanho) {
		array = new Assassino[tamanho];
		n = 0;
	}

	int getN() {
		return n;
	}

	Assassino[] getArray() {
		return array;
	}

	String getArrayNome(int index) {
		return getArray()[index].getNome();
	}

	public void inserirFim(Assassino Assassino) throws Exception {

		// validar insercao
		if (n >= array.length) {
			throw new Exception("Erro ao inserir!");
		}

		array[n] = Assassino;
		n++;
	}

	public Assassino remover(int pos) throws Exception {

		// validar remocao
		if (n == 0 || pos < 0 || pos >= n) {
			throw new Exception("Erro ao remover!");
		}

		Assassino resp = array[pos];
		n--;

		for (int i = pos; i < n; i++) {
			array[i] = array[i + 1];
		}

		return resp;
	}
}

class ListaAssassinados {
	private String[] array;
	private int n;

	public ListaAssassinados() {
		this(30);
	}

	public ListaAssassinados(int tamanho) {
		array = new String[tamanho];
		n = 0;
	}

	int getN() {
		return n;
	}

	String[] getArray() {
		return array;
	}

	public void inserirFim(String Listaassassinados) throws Exception {

		// validar insercao
		if (n >= array.length) {
			throw new Exception("Erro ao inserir!");
		}

		array[n] = Listaassassinados;
		n++;
	}
}

public class Assassinos {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(System.in);

		ListaAssassinos assassinos = new ListaAssassinos();
		ListaAssassinados assassinados = new ListaAssassinados();

		String input[] = scanner.nextLine().split(" ");

		while (!input[0].equals("FIM")) {

			String nomeDoAssassino = input[0];
			String nomeDoAssassinado = input[1];

			if (hasKilled(nomeDoAssassino, assassinos)) {
				// Incrementamos o número de assassinatos
				int indexOfNome = idexOfNome(nomeDoAssassino, assassinos);
				assassinos.getArray()[indexOfNome].novoAssassinato();
			} else {
				// Criamos um novo assassino e adicionamos à lista
				Assassino assassino = new Assassino(nomeDoAssassino);
				assassinos.inserirFim(assassino);
			}

			// Criamos a lista de assassinados
			assassinados.inserirFim(nomeDoAssassinado);

			input = scanner.nextLine().split(" ");
		}

		// Removendo os Assassinos assassinados
		for (int i = 0; i < assassinos.getN(); i++) {
			for (int j = 0; j < assassinados.getN(); j++) {
				if (assassinos.getArrayNome(i).equals(assassinados.getArray()[j])) {
					assassinos.remover(i);
				}
			}
		}

		// Ordenando o Array

		// Printando o Array
		System.out.println("HALL OF MURDERERS");
		for (int i = 0; i < assassinos.getN(); i++) {
			System.out.print(assassinos.getArray()[i].getNome() + " ");
			System.out.print(assassinos.getArray()[i].getAssassinatos());
			System.out.print(i < assassinos.getN() - 1 ? "\n" : "");
		}

		scanner.close();
	}

	public static void selectionSort(ListaAssassinos assassinos) {
		for (int i = 0; i < assassinos.getN(); i++) {
			int menor = i;
			for (int j = i + 1; j < assassinos.getN(); j++) {
				// assassinos[menor] > assassinos[j])
				if (ordermLexografica(assassinos.getArrayNome(menor), assassinos.getArrayNome(j))) {
					menor = j;
				}
			}
			// Swapping
			Assassino swap = assassinos.getArray()[menor];
			assassinos.getArray()[menor] = assassinos.getArray()[i];
			assassinos.getArray()[i] = swap;
		}
	}

	public static int idexOfNome(String nomeDoAssassino, ListaAssassinos assassinos) {
		for (int i = 0; i < assassinos.getN(); i++) {
			if (assassinos.getArrayNome(i).equals(nomeDoAssassino)) {
				return i;
			}
		}
		return 0;
	}

	public static boolean hasKilled(String nomeDoAssassino, ListaAssassinos assassinos) {
		for (int i = 0; i < assassinos.getN(); i++) {
			// Conferindo se o assassino já apareceu antes
			if (assassinos.getArrayNome(i).equals(nomeDoAssassino)) {
				return true;
			}
		}
		return false;
	}

	private static boolean ordermLexografica(String nome1, String nome2) {

		nome1.toLowerCase();
		nome2.toLowerCase();

		if (nome1.length() > nome2.length()) {
			return true;
		} else if (nome1.length() < nome2.length()) {
			return false;
		} else {
			for (int i = 0; i < nome1.length(); i++) {
				if (nome1.charAt(i) > nome2.charAt(i)) {
					return true;
				} else if (nome1.charAt(i) < nome2.charAt(i)) {
					return false;
				}
			}
		}
		return false; // Esse código é inalcançável, ele tá aqui pra não bugar
	}
}