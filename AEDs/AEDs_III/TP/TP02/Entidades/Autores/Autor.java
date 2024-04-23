package TP02.Entidades.Autores;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.lang.reflect.Constructor;
import java.util.Locale;

import TP02.Lib;
import TP02.Registro;


public class Autor implements Registro {
	
	private int ID;
	private String nome;
	private String sobrenome;
	private int idade;

	@SuppressWarnings("deprecation")
	Locale localeBR = new Locale("pt", "BR");

	public static Constructor<Autor> getConstructor() throws NoSuchMethodException, SecurityException {
		return Autor.class.getConstructor();
	}

	public Autor() { this(-1, "null", "null", -1); }

	public Autor(String nome, String sobrenome, int idade) { this(-1, nome, sobrenome, idade); }

	public Autor(int ID, String nome, String sobrenome, int idade) {
		this.ID = ID;
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.idade = idade;
	}

	public Autor(byte[] array) throws Exception { fromByteArray(array); }

	public byte[] toByteArray() throws Exception {

		ByteArrayOutputStream ba_out = null;

		ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		dos.writeInt(this.ID);
		dos.writeUTF(this.nome);
		dos.writeUTF(this.sobrenome);
		dos.writeInt(this.idade);

		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) {

		ByteArrayInputStream ba_in;
		
		try {
			ba_in= new ByteArrayInputStream(ba);
			DataInputStream dis = new DataInputStream(ba_in);
	
			this.ID = dis.readInt();
			this.nome = dis.readUTF();
			this.sobrenome = dis.readUTF();
			this.idade = dis.readInt();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String toString() {

		String str = "";
		if (this.ID != -1) str += "ID: " + this.ID + "\n";
		str += "Nome: " + this.nome;
		str += "\nAutor: " + this.sobrenome;
		str += "\nIdade: " + this.idade;

		return str;
	}

	public void setTitulo(String nome) { this.nome = nome; }

	public void setAll() {
		System.out.print("Insira o nome do autor: ");
		this.nome = Lib.readString();
		System.out.print("Insira o sobrenome do autor: ");
		this.sobrenome = Lib.readString();
		System.out.print("Insira a idade do autor: ");
		this.idade = Lib.readInt();
	}

	public void printHeader() {
		System.out.println("ID, ISBN, Título, Autor, Preço");
	}

	public String toTable() {
		String str;
		str = this.ID + ", ";
		str += this.nome  + ", ";
		str += this.sobrenome  + ", ";
		str += this.idade;

		return str + "\n";
	}

	public void printHeaderCSV() {
		System.out.println(
			Lib.BOLD + Lib.YELLOW + "ID, " +
			Lib.RED + "Nome, " +
			Lib.BLUE + "Sobrenome, " +
			Lib.GREEN + "Idade" + Lib.RESET
		);
	}

	public String toCSV() {

		String str;

		str = Lib.BOLD + Lib.YELLOW + this.ID + ", ";
		str += Lib.RED + this.nome + ", ";
		str += Lib.BLUE + this.sobrenome  + ", ";
		str += Lib.GREEN + this.idade;
		str += Lib.RESET;

		return str + "\n";
	}

	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }
	
	public String getNome() { return this.nome; }

	public String getSobrenome() { return this.sobrenome; }

	public int getIdade() { return this.idade; }
}
