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
	private String CPF;
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
		dos.writeUTF(this.CPF);
		dos.writeUTF(this.nome);
		dos.writeUTF(this.sobrenome);
		dos.writeInt(this.idade);

		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) {

		ByteArrayInputStream ba_in;
		
		try {
			ba_in = new ByteArrayInputStream(ba);
			DataInputStream dis = new DataInputStream(ba_in);
	
			this.ID = dis.readInt();
			this.CPF = dis.readUTF();
			this.nome = dis.readUTF();
			this.sobrenome = dis.readUTF();
			this.idade = dis.readInt();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void setNome(String nome) { this.nome = nome; }

	// Função para ler o CPF e testar se é um CPF valído (em termos do comprimento da string)
	public static String readCPF(boolean update) {
		
		String value = null;

		boolean invalid = false;

		do {
			if (invalid) {
				Lib.cprintf(Lib.BOLD + Lib.RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			value = Lib.readString();

			if (value.length() != 11 && value.length() != 0
				|| (value.length() == 0 && !update)
				|| value.contains(" ")
				|| value.contains("-")
			) { invalid = true; }

			else invalid = false;

		} while (invalid);

		return value;
	}

	public void setAll(boolean update) {

		System.out.print("Insira o CPF do autor: ");
		String aux = readCPF(update);
		if (aux.length() > 0) this.CPF = aux;

		System.out.print("Insira o nome do autor: ");
		aux = Lib.readString();
		if (aux.length() > 0) this.nome = aux;
		
		System.out.print("Insira o sobrenome do autor: ");
		aux = Lib.readString();
		if (aux.length() > 0) this.sobrenome = aux;

		System.out.print("Insira a idade do autor: ");
		int auxInt = Lib.readInt();
		if (auxInt > 0) this.idade = auxInt;

	}

	public void printHeader() {
		System.out.println("ID, CPF, Nome, Sobrenome, Idade");
	}

	public String toTable() {
		String str;
		str = this.ID + ", ";
		str += this.CPF  + ", ";
		str += this.nome  + ", ";
		str += this.sobrenome  + ", ";
		str += this.idade;

		return str + "\n";
	}

	public void printHeaderCSV() {
		System.out.println(
			Lib.BOLD + Lib.YELLOW + "ID, " +
			Lib.CYAN + "CPF, " +
			Lib.RED + "Nome, " +
			Lib.BLUE + "Sobrenome, " +
			Lib.GREEN + "Idade" + Lib.RESET
		);
	}

	public String toCSV() {

		String str;

		str = Lib.BOLD + Lib.YELLOW + this.ID + ", ";
		str += Lib.CYAN + this.CPF + ", ";
		str += Lib.RED + this.nome + ", ";
		str += Lib.BLUE + this.sobrenome  + ", ";
		str += Lib.GREEN + this.idade;
		str += Lib.RESET;

		return str + "\n";
	}

	public String toString() {

		String str = "";
		if (this.ID != -1) {
			str += Lib.YELLOW + Lib.BOLD + "ID: " + Lib.RESET + this.ID + "\n";
		}
		str += Lib.CYAN + Lib.BOLD + "CPF: " + Lib.RESET + this.CPF;
		str += Lib.RED + Lib.BOLD + "\nNome: " + Lib.RESET + this.nome;
		str += Lib.BLUE + Lib.BOLD + "\nSobrenome: " + Lib.RESET + this.sobrenome;
		str += Lib.GREEN + Lib.BOLD + "\nIdade: " + Lib.RESET + this.idade;

		return str;
	}


	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }

	public String getCPF() { return this.CPF; }
	
	public String getNome() { return this.nome; }

	public String getSobrenome() { return this.sobrenome; }

	public int getIdade() { return this.idade; }
}
