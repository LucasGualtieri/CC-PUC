// clear && javac IntroducaoAoJava.java && java IntroducaoAoJava str1 str2


class IntroducaoAoJava {
	
	static class Pessoa {
		public int idade;
		public Pessoa(int idade) {
			this.idade = idade;
		}
	}

	static void teste(Pessoa N) {
		System.out.println("N.idade: " + N.idade);
		N.idade = 10;
		// N = new Pessoa(0);
		// System.out.println("N.idade: " + N.idade);
	}

	public static void main(String[] olamundo) {
		Pessoa pessoa;
		pessoa = new Pessoa(15);
		// System.out.println("Idade: " + pessoa.idade);
		teste(pessoa);
	}
}