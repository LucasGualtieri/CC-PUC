package AEDs.AEDs_III.TP00;
// package AEDs.AEDs_III.TP;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.lang.reflect.Constructor;
// import java.text.NumberFormat;

class Autor implements Registro {

	private int ID;
	private String nomeCompleto;
	private int idade;
	private int qtdLivrosEscritos;

	public static Constructor<Autor> getConstructor() throws NoSuchMethodException, SecurityException {
		return Autor.class.getConstructor();
	}

	public Autor() {
		this(-1, "", -1, -1);
	}

	public Autor(String t, int a, int p) {
		this(-1, t, a, p);
	}

	public Autor(int id, String t, int a, int p) {
		this.ID = id;
		this.nomeCompleto = t;
		this.idade = a;
		this.qtdLivrosEscritos = p;
	}

	public Autor(byte[] array) throws Exception {
		fromByteArray(array);
	}

	public int getID() { return this.ID; }
	public void setID(int i) { this.ID = i; }

	public byte[] toByteArray() throws Exception {

		ByteArrayOutputStream ba_out = null;

		ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		dos.writeInt(this.ID);
		dos.writeUTF(this.nomeCompleto);
		dos.writeShort(this.idade);
		dos.writeShort(this.qtdLivrosEscritos);

		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) {

		ByteArrayInputStream ba_in;
		
		try {
			ba_in= new ByteArrayInputStream(ba);
			DataInputStream dis = new DataInputStream(ba_in);
	
			this.ID = dis.readInt();
			this.nomeCompleto = dis.readUTF();
			this.idade = dis.readShort();
			this.qtdLivrosEscritos = dis.readShort();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String toString() {

		String str;
		str = "ID: " + this.ID;
		str += "\nNome: " + this.nomeCompleto;
		str += "\nIdade: " + this.idade;
		str += "\nLivros Escritos: " + this.qtdLivrosEscritos;

		return str;
	}

	public void setNomeCompleto(String nomeCompleto) { this.nomeCompleto = nomeCompleto; }
	public void setIdade(int idade) { this.idade = idade; }
}
