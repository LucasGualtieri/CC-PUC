import java.text.DecimalFormat;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;

import java.io.IOException;

public class Livro {
	public int idLivro;
	public String titulo, autor;
	public float preco;

	DecimalFormat formatter = new DecimalFormat("#,##0.00");

	public Livro(int id, String titulo, String autor, float preco) {
		this.idLivro = id;
		this.titulo = titulo;
		this.autor = autor;
		this.preco = preco;
	}

	public Livro() {}

	public Livro(byte[] array) throws IOException {
		fromByteArray(array);
	}

	@Override
	public String toString() {

		String livro;
		
		livro = "ID: " + idLivro + "\n";
		livro += "Título: " + titulo + "\n";
		livro += "Autor: " + autor + "\n";
		livro += "Preço: R$ " + formatter.format(preco) + "\n";

		return livro;
	}

	public byte[] toByteArray() throws IOException {

		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(baos);

		// dos.writeInt(TAM);
		dos.writeInt(idLivro);
		dos.writeUTF(titulo);
		dos.writeUTF(autor);
		dos.writeFloat(preco);

		byte[] array = baos.toByteArray();
		
		dos.close();
		baos.close();

		return array;
	}

	public void fromByteArray(byte[] array) throws IOException {

		ByteArrayInputStream bais = new ByteArrayInputStream(array);
		DataInputStream dis = new DataInputStream(bais);

		idLivro = dis.readInt();
		titulo = dis.readUTF();
		autor = dis.readUTF();
		preco = dis.readFloat();

		dis.close();
		bais.close();
	}
}