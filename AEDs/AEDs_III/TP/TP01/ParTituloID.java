package TP01;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.lang.reflect.Constructor;

public class ParTituloID implements RegistroHashExtensivel {

	private String titulo;
	private int ID;
	final private int TAMANHO = 12;

	public ParTituloID() { this("", -1); }

	public ParTituloID(String titulo, int ID) {
		this.titulo = titulo;
		this.ID = ID;
	}

	public int getId() { return ID; }

	public String getTitulo() { return titulo; }

	public int hashCode() { return Math.abs(titulo.hashCode()); }

	public short size() { return TAMANHO; }

	public static Constructor<ParTituloID> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParTituloID.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {
		ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);
		
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
