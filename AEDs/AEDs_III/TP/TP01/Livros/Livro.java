package TP01.Livros;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.lang.reflect.Constructor;
import java.text.NumberFormat;
import java.util.Locale;

import TP01.Lib;
import TP01.Registro;

public class Livro implements Registro {
	
	private int ID;
	private String ISBN;
	private String titulo;
	private String autor;
	private float preco;
	// private long address;

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

		ByteArrayOutputStream ba_out = null;

		ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		dos.writeInt(this.ID);
		dos.writeUTF(this.ISBN);
		dos.writeUTF(this.titulo);
		dos.writeUTF(this.autor);
		dos.writeFloat(this.preco);

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
			this.autor = dis.readUTF();
			this.preco = dis.readFloat();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String toString() {

		String str = "";
		if (this.ID != -1) str += "ID: " + this.ID + "\n";
		str += "Título: " + this.titulo;
		str += "\nAutor: " + this.autor;
		str += "\nPreço: " + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);

		return str;
	}

	public void setTitulo(String titulo) { this.titulo = titulo; }

	// Função para ler o ISBN e testar se é um ISBN valído (em termos do comprimento da string)
	private String readISBN() {
		
		String value = "invalid";

		boolean invalid = false;

		do {
			if (invalid) {
				Lib.cprintf(Lib.BOLD + Lib.RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			value = Lib.readString();
			if (value.length() != 10 && value.length() != 13
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
        
        // Verifica o comprimento do ISBN
        int length = ISBN.length();
        
		// Máscara para ISBN de 10 dígitos
        if (length == 10) {
            builder.append(ISBN.substring(0, 1))
			.append("-")
			.append(ISBN.substring(1, 4))
			.append("-")
			.append(ISBN.substring(4, 9))
			.append("-")
			.append(ISBN.substring(9));
        }

		// Máscara para ISBN de 13 dígitos
		else if (length == 13) {
            builder.append(ISBN.substring(0, 3))
			.append("-")
			.append(ISBN.substring(3, 4))
			.append("-")
			.append(ISBN.substring(4, 7))
			.append("-")
			.append(ISBN.substring(7, 12))
			.append("-")
			.append(ISBN.substring(12));
		}
        
        return builder.toString();
	}

	// Método que faz uma interface com o usário e o permite que insira os dados do livro
	public void setAll() {
		System.out.print("Insira o ISBN do livro: ");
		ISBN = readISBN();
		System.out.print("Insira o título do livro: ");
		titulo = Lib.readString();
		System.out.print("Insira o nome do autor do livro: ");
		autor = Lib.readString();
		System.out.print("Insira o preço do livro: ");
		preco = Lib.readFloat();
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
		str += this.autor  + ", ";
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
		str += Lib.BLUE + this.autor  + ", ";
		str += Lib.GREEN + NumberFormat.getCurrencyInstance(localeBR).format(this.preco);
		str += Lib.RESET;

		return str + "\n";
	}

	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }
	
	public String getISBN() { return this.ISBN; }

	public String getTitulo() { return this.titulo; }

	public String getAutor() { return this.autor; }

	public float getPreco() { return this.preco; }
}
