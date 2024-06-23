package TP04.src.Entidades.Livros.Indices;

import java.io.IOException;
import java.lang.reflect.Constructor;

import TP04.src.utils.StreamManager;
import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.EstruturasDeDados.RegistroHashExtensivel;

public class ParIsbnId implements RegistroHashExtensivel<ParIsbnId> {

	private String isbn;
	private int id;
	private short TAMANHO = 17;

	public ParIsbnId() {
		this.isbn = "0000000000000";
		this.id = -1;
	}

	public ParIsbnId(String is, int i) {

		try {

			if (is.getBytes().length != 13) {
				throw new Exception("O ISBN deve ter exatamente 13 dígitos");
			}

			this.isbn = is;
			this.id = i;
		} 

		catch (Exception e) { e.printStackTrace(); }
	}

	public String getIsbn() { return isbn; }

	public int getId() { return id; }

	public short size() { return this.TAMANHO; }

	public static Constructor<ParIsbnId> getConstructor() throws NoSuchMethodException, SecurityException {
		return ParIsbnId.class.getConstructor();
	}

	public byte[] toByteArray() throws IOException {

		StreamManager sm = new StreamManager();

		sm.writeUTF(this.isbn);
		sm.write(this.id);

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	public void fromByteArray(byte[] ba) throws IOException {

		Cipher c = new Cipher();
		// StreamManager sm = new StreamManager(ba);
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, ba));

		byte[] b = sm.read(13);
		this.isbn = new String(b);
		this.id = sm.readInt();
	}

	@Override
	public int hashCode() { return ParIsbnId.hashIsbn(this.isbn); }

	public static int hashIsbn(String isbn) { return Math.abs(isbn.hashCode()); }

}
