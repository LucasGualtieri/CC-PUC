// package AEDs.AEDs_III.TP;clear && javac Gerenciador.java && java Gerenciador

// clear && javac Gerenciador.java && java Gerenciador

class Gerenciador {
	public static void main(String[] args) throws Exception {

		String filePath = "dados/livros.db";

		Arquivo<Livro> arquivoDeLivros = new Arquivo<>(Livro.getConstructor(), filePath);

		arquivoDeLivros.Inicializar(0);

		Livro l1 = new Livro("Odisséia", "Homero", 15.99F);
		Livro l2 = new Livro(5, "Ensino Híbrido", "Lilian Bacich", 39.90F);
		// Livro l3 = new Livro();

		int id1, id2;
	
		id1 = arquivoDeLivros.create(l1);
		System.out.println("Livro criado com o ID: " + id1);

		id2 = arquivoDeLivros.create(l2);
		System.out.println("Livro criado com o ID: " + id2);

		boolean excluido = arquivoDeLivros.delete(id2);
		if (excluido) {
			System.out.println("Livro excluído com sucesso");
		} else {
			System.out.println("Livro já exclúido");
		}

		excluido = arquivoDeLivros.delete(id2);
		if (excluido) {
			System.out.println("Livro excluído com sucesso");
		} else {
			System.out.println("Livro já exclúido");
		}
		
		// id2 = arquivoDeLivros.create(l2);
		// System.out.println("Livro criado com o ID: " + id2);
		
		// l3 = arquivoDeLivros.read(id1);
		// System.out.println(l3);
		
		// l3 = arquivoDeLivros.read(id2);
		// System.out.println(l3);
	}
}