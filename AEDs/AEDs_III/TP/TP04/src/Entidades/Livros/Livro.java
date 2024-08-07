package TP04.src.Entidades.Livros;

import java.util.Locale;
import java.text.NumberFormat;
import java.lang.reflect.Constructor;

import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.utils.Registro;
import TP04.src.utils.StreamManager;
import TP04.src.utils.Utils;

public class Livro implements Registro {

	private int ID;
	private String ISBN;
	private String titulo;
	private String autor;
	private float preco;

	@SuppressWarnings("deprecation")
	Locale localeBR = new Locale("pt", "BR");

	public static Constructor<Livro> getConstructor() throws NoSuchMethodException, SecurityException {
		return Livro.class.getConstructor();
	}

	public Livro() { this(-1, "null", "null", -0F); }

	public Livro(String titulo, String autor, float preco) { this(-1, titulo, autor, preco); }

	public Livro(int ID, String titulo, String autor, float preco) {
		this.ID = ID;
		this.titulo = titulo;
		this.autor = autor;
		this.preco = preco;
	}

	public Livro(byte[] array) throws Exception { fromByteArray(array); }

	public byte[] toByteArray() throws Exception {

		StreamManager sm = new StreamManager();

		sm.write(this.ID);
		sm.writeUTF(this.ISBN);
		sm.writeUTF(this.titulo);
		sm.writeUTF(this.autor);
		sm.write(this.preco);

		return sm.toByteArray();
	}

	public void fromByteArray(byte[] ba) {

		byte[] deciphered = new Cipher().decipher(Cipher.KEY, ba);
		StreamManager sm = new StreamManager(deciphered);

		try {
			this.ID = sm.readInt();
			this.ISBN = sm.readUTF();
			this.titulo = sm.readUTF();
			this.autor = sm.readUTF();
			this.preco = sm.readFloat();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// Função para ler o ISBN e testar se é um ISBN valído (em termos do comprimento da string)
	public static String readISBN(boolean update) {

		String value = null;

		boolean invalid = false;

		do {
			if (invalid) {
				Utils.cprintf(Utils.BOLD + Utils.RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			value = Utils.readString();

			if (value.length() != 13 && value.length() != 0
				|| (value.length() == 0 && !update)
				|| value.contains(" ")
				|| value.contains("-")
			) { invalid = true; }

			else invalid = false;

		} while (invalid);

		return value;
	}

	// Função para printar o ISBN com a máscara
	private String mascaraISBN() {
		StringBuilder builder = new StringBuilder();

		builder.append(ISBN.substring(0, 3))
		.append("-")
		.append(ISBN.substring(3, 4))
		.append("-")
		.append(ISBN.substring(4, 7))
		.append("-")
		.append(ISBN.substring(7, 12))
		.append("-")
		.append(ISBN.substring(12));

		return builder.toString();
	}

	// Método que faz uma interface com o usário e o permite que insira os dados do livro
	public void setAll(boolean update) {

		System.out.print("Insira o ISBN do livro: ");
		String aux = readISBN(update);
		if (aux.length() > 0) this.ISBN = aux;

		System.out.print("Insira o título do livro: ");
		aux = Utils.readString();
		if (aux.length() > 0) this.titulo = aux;

		System.out.print("Insira o nome do autor do livro: ");
		aux = Utils.readString();
		if (aux.length() > 0) this.autor = aux;

		System.out.print("Insira o preço do livro: ");
		float auxF = Utils.readFloat();
		if (auxF != -1) preco = auxF;
	}

	// Função que printa o cabeçalho com os dados dos livros em formato CSV
	public void printHeader() {
		System.out.println("ID, ISBN, Título, Autor, Preço");
	}

	// Função que printa um livro em formato CSV
	public String toTable() {
		String str;
		str = this.ID + ", ";
		str += this.ISBN  + ", ";
		str += this.titulo  + ", ";
		str += this.autor + ", ";
		str += NumberFormat.getCurrencyInstance(localeBR).format(this.preco);

		return str + "\n";
	}

	// Função que printa o cabeçalho com os dados dos livros em formato CSV com cores
	public void printHeaderCSV() {
		System.out.println(
			Utils.BOLD + Utils.YELLOW + "ID, " +
			Utils.CYAN + "ISBN, " +
			Utils.RED + "Título, " +
			Utils.BLUE + "Autor, " +
			Utils.GREEN + "Preço" + Utils.RESET
		);
	}

	// Função que printa um livro em formato CSV com cores
	public String toCSV() {
		String str;

		str = Utils.BOLD + Utils.YELLOW + this.ID + ", ";
		str += Utils.CYAN + mascaraISBN() + ", ";
		str += Utils.RED + this.titulo  + ", ";
		str += Utils.BLUE + this.autor  + ", ";
		str += Utils.GREEN + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);
		str += Utils.RESET;

		return str + "\n";
	}

	public String toString() {

		String str = "";
		if (this.ID != -1) {
			str += Utils.YELLOW + Utils.BOLD + "ID: " + Utils.RESET + this.ID + "\n";
		}
		str += Utils.CYAN + Utils.BOLD + "ISBN: " + Utils.RESET + this.ISBN;
		str += Utils.RED + Utils.BOLD + "\nTítulo: " + Utils.RESET + this.titulo;
		str += Utils.BLUE + Utils.BOLD + "\nAutor: " + Utils.RESET + this.autor;
		str += Utils.GREEN + Utils.BOLD + "\nPreço: " + Utils.RESET + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);

		return str;
	}

	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }

	public String getISBN() { return this.ISBN; }

	public void setTitulo(String titulo) { this.titulo = titulo; }
	public String getTitulo() { return this.titulo; }

	public void setAutor(String autor) { this.autor = autor; }
	public String getAutor() { return this.autor; }

	public float getPreco() { return this.preco; }
}
