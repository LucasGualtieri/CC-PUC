package TP03.EstruturasDeDados.Tuplas;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.lang.reflect.Constructor;

import TP03.EstruturasDeDados.RegistroHashExtensivel;

public class ParIDEndereco implements RegistroHashExtensivel<ParIDEndereco> {

	private int id;
	private long endereco;
	final private int TAMANHO = 12;

	public ParIDEndereco() {
		this(-1, -1);
	}

	public ParIDEndereco(int i, long e) {
		this.id = i;
		this.endereco = e;
	}

	public int getId() {
		return id;
	}

	public long getEndereco() {
		return endereco;
	}

	public int hashCode() {
		return this.id;
	}

	public short size() {
		return TAMANHO;
	}

	public static Constructor<ParIDEndereco> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParIDEndereco.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {
		ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);
		dos.writeInt(this.id);
		dos.writeLong(this.endereco);
		return ba_out.toByteArray();
	}

	public void fromByteArray(byte[] ba) throws IOException {
		ByteArrayInputStream ba_in = new ByteArrayInputStream(ba);
		DataInputStream dis = new DataInputStream(ba_in);
		this.id = dis.readInt();
		this.endereco = dis.readLong();
	}
}
