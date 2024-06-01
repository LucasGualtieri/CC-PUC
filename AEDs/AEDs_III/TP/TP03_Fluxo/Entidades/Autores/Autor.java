package TP03.Entidades.Autores;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.lang.reflect.Constructor;
import java.util.Locale;

import TP03.Lib;
import TP03.Registro;

// Para fazer um relacionamento 1->N com Autores de Livros precisarei:
//		Criar uma chave estrangeira em Livro: IDAutor
// 		Modificar os métodos de criação de livros:
//			- O usuário pesquisa o nome do autor / CPF, se existe salva o ID, caso contrário vai para a rotina de criação de Autor
// 		Modificar os métodos de Listagem de livros:
//			- Ao mostrar livro, fazemos uma pesquisa no indice direto de autores para poder mostrar seus dados (somente o nome mesmo)
// 		No momento de salvar o IDAutor também precisamos inserir o id do livro na arvore b+, (IDAutor, IDLivro)
// 			- Dessa forma podemos alterar a rotina de listagem de autores, mostrando a quantidade de livros escritos
// 			- E na hora de mostrar um Autor em específico mostramos seus livros

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

	public Autor() { this(-1, "null", "null", "null", -1); }

	public Autor(String CPF, String nome, String sobrenome, int idade) { this(-1, CPF, nome, sobrenome, idade); }

	public Autor(int ID, String CPF, String nome, String sobrenome, int idade) {
		this.ID = ID;
		this.CPF = CPF;
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

	// Função para printar o CPF com a máscara
	private String mascaraCPF() {
		StringBuilder builder = new StringBuilder();
		
		builder.append(CPF.substring(0, 3))
		.append(".")
		.append(CPF.substring(3, 6))
		.append(".")
		.append(CPF.substring(6, 9))
		.append("-")
		.append(CPF.substring(9));
		
		return builder.toString();
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
		str += Lib.CYAN + mascaraCPF() + ", ";
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
		str += Lib.CYAN + Lib.BOLD + "CPF: " + Lib.RESET + mascaraCPF();
		str += Lib.RED + Lib.BOLD + "\nNome: " + Lib.RESET + this.nome;
		str += Lib.BLUE + Lib.BOLD + "\nSobrenome: " + Lib.RESET + this.sobrenome;
		str += Lib.GREEN + Lib.BOLD + "\nIdade: " + Lib.RESET + this.idade;

		return str;
	}

	public static int compare(Autor x, Autor y) {
		return x.compareTo(y);
	}

	public int compareTo(Autor y) {
		return this.nome.compareTo(y.getNome());
	}

	public void setID(int i) { this.ID = i; }
	public int getID() { return this.ID; }

	public String getCPF() { return this.CPF; }
	
	public String getNome() { return this.nome; }

	public String getSobrenome() { return this.sobrenome; }

	public int getIdade() { return this.idade; }
}
