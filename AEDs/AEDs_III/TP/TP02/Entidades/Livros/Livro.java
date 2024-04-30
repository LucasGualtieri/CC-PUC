package TP02.Entidades.Livros;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.lang.reflect.Constructor;
import java.text.NumberFormat;
import java.util.Locale;

import TP02.Lib;
import TP02.Registro;
// import TP02.Entidades.Autores.Autor;
// import TP02.Entidades.Autores.ArquivoAutor;
// import TP02.Entidades.Autores.Indices.ParCPFId;
import TP02.Entidades.Autores.ArquivoAutor;
import TP02.Entidades.Autores.Autor;

public class Livro implements Registro {
	
	private int ID;
	private String ISBN;
	private String titulo;
	private float preco;
	private int IDAutor;
	// private long address;

	@SuppressWarnings("deprecation")
	Locale localeBR = new Locale("pt", "BR");

	public static Constructor<Livro> getConstructor() throws NoSuchMethodException, SecurityException {
		return Livro.class.getConstructor();
	}

	public Livro() { this(-1, "null", -0F, -1); }

	public Livro(String titulo, float preco, int IDAutor) { this(-1, titulo, preco, IDAutor); }

	public Livro(int ID, String titulo, float preco, int IDAutor) {
		this.ID = ID;
		this.titulo = titulo;
		this.preco = preco;
		this.IDAutor = IDAutor;
	}

	public Livro(byte[] array) throws Exception { fromByteArray(array); }

	public byte[] toByteArray() throws Exception {

		ByteArrayOutputStream ba_out = null;

		ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		dos.writeInt(this.ID);
		dos.writeUTF(this.ISBN);
		dos.writeUTF(this.titulo);
		dos.writeFloat(this.preco);
		dos.writeInt(this.IDAutor);

		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) {

		ByteArrayInputStream ba_in;
		
		try {
			ba_in= new ByteArrayInputStream(ba);
			DataInputStream dis = new DataInputStream(ba_in);
	
			this.ID = dis.readInt();
			this.ISBN = dis.readUTF();
			this.titulo = dis.readUTF();
			this.preco = dis.readFloat();
			this.IDAutor = dis.readInt();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void setTitulo(String titulo) { this.titulo = titulo; }

	// Função para ler o ISBN e testar se é um ISBN valído (em termos do comprimento da string)
	public static String readISBN(boolean update) {
		
		String value = null;

		boolean invalid = false;

		do {
			if (invalid) {
				Lib.cprintf(Lib.BOLD + Lib.RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			value = Lib.readString();

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
		aux = Lib.readString();
		if (aux.length() > 0) this.titulo = aux;

		
		System.out.print("Insira o preço do livro: ");
		float auxF = Lib.readFloat();
		if (auxF != -1) preco = auxF;

		// System.out.print("Insira o CPF do autor do livro: ");
		// // System.out.print("Insira o NOME do autor do livro: "); // Deve mostrar uma lista
		// aux = Autor.readCPF(update);

		// if (aux.length() > 0) {
		// 	try {
		// 		ParCPFId pii = ArquivoAutor.indiceIndiretoCPF.read(ParCPFId.hashCPF(aux));
		// 		if (pii != null) this.IDAutor = pii.getId();
		// 		else {
		// 			// Cadastrar Autor
		// 			System.out.println("Não foi encontardo o autor por esse CPF");
		// 			System.exit(-1);
		// 		}
		// 	}

		// 	catch (Exception e) {}
		// }
	}

	// public void setAddress(long address) { this.address = address; }
	// public long getAddress() { return this.address; }

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
		// str += getAutorName() + ", ";
		str += NumberFormat.getCurrencyInstance(localeBR).format(this.preco);
		
		return str + "\n";
	}
	
	// Função que printa o cabeçalho com os dados dos livros em formato CSV com cores
	public void printHeaderCSV() {
		System.out.println(
			Lib.BOLD + Lib.YELLOW + "ID, " +
			Lib.CYAN + "ISBN, " +
			Lib.RED + "Título, " +
			Lib.BLUE + "Autor, " + 
			Lib.GREEN + "Preço" + Lib.RESET
		);
	}

	// Função que printa um livro em formato CSV com cores
	public String toCSV() {
		String str;

		str = Lib.BOLD + Lib.YELLOW + this.ID + ", ";
		str += Lib.CYAN + mascaraISBN() + ", ";
		str += Lib.RED + this.titulo  + ", ";
		// str += Lib.BLUE + getAutorName()  + ", ";
		str += Lib.GREEN + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);
		str += Lib.RESET;

		return str + "\n";
	}

	public String toString() {

		String str = "";
		if (this.ID != -1) {
			str += Lib.YELLOW + Lib.BOLD + "ID: " + Lib.RESET + this.ID + "\n";
		}
		str += Lib.CYAN + Lib.BOLD + "ISBN: " + Lib.RESET + this.ISBN;
		str += Lib.RED + Lib.BOLD + "\nTítulo: " + Lib.RESET + this.titulo;
		str += Lib.GREEN + Lib.BOLD + "\nPreço: " + Lib.RESET + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);
		// str += Lib.BLUE + Lib.BOLD + "\nAutor: " + Lib.RESET + getAutorName();
		// str += Lib.BLUE + Lib.BOLD + "\nAutor: " + Lib.RESET + getAutor();

		return str;
	}

	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }
	
	public String getISBN() { return this.ISBN; }

	public String getTitulo() { return this.titulo; }

	// public String getAutorName() {
	// 	String autorName = "null";

	// 	try {
	// 		Autor autor = ArquivoAutor.getFromIndex(this.IDAutor);
	// 		autorName = autor.getNome();
	// 	}

	// 	catch (Exception e) {
	// 		System.out.println("IDAutor: " + IDAutor);
	// 		System.out.println("Não foi possivel encontrar o autor");
	// 		System.out.println(e.getMessage());
	// 		System.exit(-1);
	// 	}
	
	// 	return autorName;
	// }

	public Autor getAutor(ArquivoAutor<Autor> arquivoAutor) {
		Autor autor = new Autor();

		try {
			Autor tmp = arquivoAutor.getFromIndex(this.IDAutor);
			if (tmp != null) autor = tmp;
		}

		catch (Exception e) {}
	
		return autor;
	}

	public float getPreco() { return this.preco; }
}
