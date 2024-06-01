package TP03.Entidades.Livros.Indices;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.lang.reflect.Constructor;

import TP03.EstruturasDeDados.RegistroHashExtensivel;

public class ParTituloID implements RegistroHashExtensivel<ParTituloID> {

	private String titulo;
	private int ID;
	final private int TAMANHO = 4 + 40;

	public ParTituloID() throws IOException {
		this("", -1);
	}

	public ParTituloID(String titulo, int ID) throws IOException {
		
		byte[] bytes = titulo.getBytes();		
		this.titulo = new String(bytes, 0, 38); // Limita a string a 38 bytes e elimina o resto
		this.ID = ID;
	}

	public String getTitulo() { return titulo; }

	public int getId() { return ID; }

	public int hashCode() { return this.titulo.hashCode(); }

	public short size() { return TAMANHO; }

	public static Constructor<ParTituloID> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParTituloID.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {
		ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(new ByteArrayOutputStream());
	
		dos.writeUTF(this.titulo);
		dos.writeInt(this.ID);
		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) throws IOException {
		ByteArrayInputStream ba_in = new ByteArrayInputStream(ba);
		DataInputStream dis = new DataInputStream(ba_in);
		this.titulo = dis.readUTF();
		this.ID = dis.readInt();
	}
}
