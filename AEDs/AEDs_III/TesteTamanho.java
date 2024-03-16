package AEDs.AEDs_III;

// clear && javac TesteTamanho.java && java TesteTamanho.java

class TesteTamanho {
	public static void main(String[] args) {

		int availableMemory = 16; // 16 GB
		int M; // Número de Destinos

		for (M = 2; M <= 8; M++) {
			int x = availableMemory / (2 * M); // Tamanho de cada Fila
			System.out.printf("Número de Filas: %d\n", M);
			System.out.printf("Cada fila caberia %d destinos\n", x);
			System.out.println("------------------");
		}
	}
}