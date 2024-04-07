package TP00;
// package AEDs.AEDs_III.TP;clear && javac Gerenciador.java && java Gerenciador

// clear && javac Gerenciador.java && java Gerenciador

import java.io.File;

class Gerenciador {

	public static void main(String[] args) throws Exception {

		String pathArquivoDeLivros = "dados/livros.db";
		String pathArquivoDeAutores = "dados/autores.db";

		new File(pathArquivoDeLivros).delete();
		new File(pathArquivoDeAutores).delete();

		Arquivo<Livro> arquivoDeLivros = new Arquivo<>(Livro.getConstructor(), pathArquivoDeLivros);
		Arquivo<Autor> arquivoDeAutores = new Arquivo<>(Autor.getConstructor(), pathArquivoDeAutores);

		// arquivoDeLivros.Inicializar(0);

		Livro l1 = new Livro("Odisséia", "Homero", 15.99F);
		Autor a1 = new Autor("Nome Sobrenome", 50, 5);
		// Livro l2 = new Livro(5, "Ensino Híbrido", "Lilian Bacich", 39.90F);

		arquivoDeLivros.create(l1);
		int idAutor = arquivoDeAutores.create(a1);
		System.out.println("Livro criado com o ID: " + l1.getID());
		System.out.println("Autor criado com o ID: " + idAutor);

		// idRetorno = arquivoDeLivros.create(l2);
		// System.out.println("Livro criado com o ID: " + id2);

		// if (arquivoDeLivros.delete(l1.getID())) {
		// System.out.println("Livro excluído com sucesso");
		// } else {
		// System.out.println("Livro já exclúido");
		// }

		// if (arquivoDeLivros.delete(l1.getID())) {
		// System.out.println("Livro excluído com sucesso");
		// } else {
		// System.out.println("Livro já exclúido");
		// }

		Livro livro = arquivoDeLivros.read(l1.getID());
		if (livro != null) {
			System.out.println(livro.toString());
		} else {
			System.out.println("Livro não encontrado");
		}

		l1.setTitulo("Teste Novo Titulo");
		if (arquivoDeLivros.update(l1)) {
			System.out.println("Livro atualizado com sucesso");
		} else {
			System.out.println("Livro não pode ser atualizado");
		}

		livro = arquivoDeLivros.read(l1.getID());
		if (livro != null) {
			System.out.println(livro.toString());
		} else {
			System.out.println("Livro não encontrado");
		}
		
		System.out.println("---------------------------");

		Autor autor = arquivoDeAutores.read(a1.getID());
		if (autor != null) {
			System.out.println(autor.toString());
		} else {
			System.out.println("Autor não encontrado");
		}

		a1.setNomeCompleto("Novo nome");
		a1.setIdade(55);
		if (arquivoDeAutores.update(a1)) {
			System.out.println("Autor atualizado com sucesso");
		} else {
			System.out.println("Autor não pode ser atualizado");
		}

		autor = arquivoDeAutores.read(a1.getID());
		if (autor != null) {
			System.out.println(autor.toString());
		} else {
			System.out.println("Autor não encontrado");
		}

		if (arquivoDeAutores.delete(a1.getID())) {
			System.out.println("Autor excluído com sucesso");
		} else {
			System.out.println("Autor não pode ser excluído");
		}
		
		autor = arquivoDeAutores.read(a1.getID());
		if (autor != null) {
			System.out.println(autor.toString());
		} else {
			System.out.println("Autor não encontrado");
		}

		// id2 = arquivoDeLivros.create(l2);
		// System.out.println("Livro criado com o ID: " + id2);

		// l3 = arquivoDeLivros.read(id1);
		// System.out.println(l3);

		// l3 = arquivoDeLivros.read(id2);
		// System.out.println(l3);
	}
}