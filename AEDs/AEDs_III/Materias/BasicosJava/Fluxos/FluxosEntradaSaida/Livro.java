package AEDs.AEDs_III.Materias.BasicosJava.Fluxos.FluxosEntradaSaida;

import java.text.DecimalFormat;

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

	@Override
	public String toString() {

		String livro;
		
		livro = "ID: " + idLivro + "\n";
		livro += "Título: " + titulo + "\n";
		livro += "Autor: " + autor + "\n";
		livro += "Preço: R$ " + formatter.format(preco) + "\n";

		return livro;
	}
}