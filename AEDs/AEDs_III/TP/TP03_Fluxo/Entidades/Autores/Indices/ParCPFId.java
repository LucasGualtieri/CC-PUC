package TP03.Entidades.Autores.Indices;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.lang.reflect.Constructor;

import TP03.EstruturasDeDados.RegistroHashExtensivel;

public class ParCPFId implements RegistroHashExtensivel<ParCPFId> {

	private String CPF;
	private int id;
	private short TAMANHO = 4 + 11;

	public ParCPFId() {
		this.CPF = "00000000000";
		this.id = -1;
	}

	public ParCPFId(String is, int i) {
		try {
			if (is.getBytes().length != 11) {
				throw new Exception("O CPF deve ter exatamente 11 dígitos");
			}
			this.CPF = is;
			this.id = i;
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String getCPF() {
		return CPF;
	}

	public int getId() {
		return id;
	}

	public short size() {
		return this.TAMANHO;
	}

	public static Constructor<ParCPFId> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParCPFId.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(baos);
		dos.write(this.CPF.getBytes());
		dos.writeInt(this.id);
		return baos.toByteArray();
	}

	public void fromByteArray(byte[] ba) throws IOException {
		ByteArrayInputStream bais = new ByteArrayInputStream(ba);
		DataInputStream dis = new DataInputStream(bais);
		byte[] b = new byte[11];
		dis.read(b);
		this.CPF = new String(b);
		this.id = dis.readInt();
	}

	@Override
	public int hashCode() {
		return ParCPFId.hashCPF(this.CPF);
	}

	public static int hashCPF(String CPF) {
		return Math.abs(CPF.hashCode());
	}

}
