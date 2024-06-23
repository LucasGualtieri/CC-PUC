package TP04.src.Entidades.Autores.Indices;

import java.io.IOException;
import java.lang.reflect.Constructor;

import TP04.src.utils.StreamManager;
import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.EstruturasDeDados.RegistroHashExtensivel;

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
		}

		catch (Exception e) { e.printStackTrace(); }
	}

	public String getCPF() { return CPF; }

	public int getId() { return id; }

	public short size() { return this.TAMANHO; }

	public static Constructor<ParCPFId> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParCPFId.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {

		StreamManager sm = new StreamManager();

		sm.write(this.CPF.getBytes());
		sm.write(this.id);

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	public void fromByteArray(byte[] ba) throws IOException {

		Cipher c = new Cipher();
		// StreamManager sm = new StreamManager(ba);
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, ba));

		byte[] b = new byte[11];
		sm.read(b);

		this.CPF = new String(b);
		this.id = sm.readInt();
	}

	@Override
	public int hashCode() { return ParCPFId.hashCPF(this.CPF); }

	public static int hashCPF(String CPF) { return Math.abs(CPF.hashCode()); }

}
