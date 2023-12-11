import java.util.Scanner;

class QuestaoArvore {

	// clear && javac QuestaoArvore.java && java QuestaoArvore < pub.in > result.txt

	static class No {

		int x;
		No esq, dir;

		public No(int x) {
			this.x = x;
			esq = dir = null;
		}
	}

	static class Arvore  {

		public No raiz;

		public Arvore(int[] array) {
			for (int i : array) {
				this.Inserir(i);
			}
		}

		public Arvore() { raiz = null; }

		public int getAltura() {
			return getAltura(0, this.raiz);
		}

		private int getAltura(int nivel, No i) {

			int altura = nivel;
			// 	int altura = nivel - 1; // Permite tirar o else

			if (i != null) {
				int alturaEsq = getAltura(nivel + 1, i.esq);
				int alturaDir = getAltura(nivel + 1, i.dir);
				altura = Math.max(alturaEsq, alturaDir);
			} else {
				altura--;
			}

			return altura;
		}

		public void Inserir(int x) {
			this.raiz = Inserir(x, this.raiz);
		}

		private No Inserir(int x, No i) {

			if (i == null) {
				i = new No(x);
			} else if (x < i.x) {
				i.esq = Inserir(x, i.esq);
			} else if (x > i.x) {
				i.dir = Inserir(x, i.dir);
			} else {
				System.out.println("Erro");
			}

			return i;
		}

		public void MostrarEmLargura() {
			int altura = this.getAltura();
			for (int i = 0; i <= altura; i++) {
				MostrarEmLargura(0, i, this.raiz);
			}
			System.out.println();
		}

		private void MostrarEmLargura(int nivel, int nivelVez, No i) {
			if (i != null) {
				if (nivel < nivelVez) {
					MostrarEmLargura(nivel + 1, nivelVez, i.esq);
					MostrarEmLargura(nivel + 1, nivelVez, i.dir);
				} else if (nivel == nivelVez) {
					System.out.printf("%d ", i.x);
				}
			}
		}
	}

	public static void main(String[] args) {
		
		// int[] array = { 8, 3, 10, 14, 6, 4, 13, 7, 1 };
		// Arvore arvore = new Arvore(array);
		
		Scanner sc = new Scanner(System.in);
		
		int qtdCasos = sc.nextInt();
		for (int i = 0; i < qtdCasos; i++) {

			System.out.printf("Case %d:\n", i + 1);

			int qtdNumeros = sc.nextInt();
			Arvore arvore = new Arvore();
			for (int j = 0; j < qtdNumeros; j++) {
				arvore.Inserir(sc.nextInt());
			}
			arvore.MostrarEmLargura();
			System.out.println();
		}
	}
}