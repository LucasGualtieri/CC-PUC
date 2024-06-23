package TP04.src.Entidades.Livros.Indices;

import java.io.IOException;
import java.lang.reflect.Constructor;

import TP04.src.utils.StreamManager;
import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.EstruturasDeDados.RegistroHashExtensivel;

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

		StreamManager sm = new StreamManager();

		sm.writeUTF(this.titulo);
		sm.write(this.ID);

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	public void fromByteArray(byte[] ba) throws IOException {

		Cipher c = new Cipher();
		// StreamManager sm = new StreamManager(ba);
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, ba));

		this.titulo = sm.readUTF();
		this.ID = sm.readInt();
	}
}
