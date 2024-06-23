package TP04.src.EstruturasDeDados.Tuplas;

import java.io.IOException;
import java.lang.reflect.Constructor;

import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.EstruturasDeDados.RegistroHashExtensivel;
import TP04.src.utils.StreamManager;

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

		StreamManager sm = new StreamManager();

		sm.write(this.id);
		sm.write(this.endereco);

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	public void fromByteArray(byte[] ba) throws IOException {
		
		Cipher c = new Cipher();
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, ba));

		this.id = sm.readInt();
		this.endereco = sm.readLong();
	}
}
