// package AEDs.AEDs_III.TP;clear && javac Gerenciador.java && java Gerenciador

// clear && javac Gerenciador.java && java Gerenciador

import java.io.File;

class Gerenciador {
	public static void main(String[] args) throws Exception {

		String filePath = "dados/livros.db";

		// File f = new File(filePath);
		// f.delete();

		Arquivo<Livro> arquivoDeLivros = new Arquivo<>(Livro.getConstructor(), filePath);

		// arquivoDeLivros.Inicializar(0);

		Livro l1 = new Livro("Odisséia", "Homero", 15.99F);
		// Livro l2 = new Livro(5, "Ensino Híbrido", "Lilian Bacich", 39.90F);

		int idRetorno = arquivoDeLivros.create(l1);
		System.out.println("Livro criado com o ID: " + l1.getID());

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

		// id2 = arquivoDeLivros.create(l2);
		// System.out.println("Livro criado com o ID: " + id2);

		// l3 = arquivoDeLivros.read(id1);
		// System.out.println(l3);

		// l3 = arquivoDeLivros.read(id2);
		// System.out.println(l3);
	}
}