package Restos;

import java.util.Arrays;

// clear && javac TesteTamanho.java && java TesteTamanho.java

class TesteTamanho {
	public static void main(String[] args) {

		int availableMemory = 16; // 16 GB
		int M; // Número de Destinos

		String[] strings = new String[3];
        Arrays.fill(strings, new String("LUCAS"));

		// Assim como no JS
		Arrays.asList(strings).forEach(str -> {
			System.out.print("str: ");
			System.out.println(str);
		});

		// Arrays.asList(strings).forEach(str -> System.out.println(str));

		// for (String str : strings) {
		// 	System.out.println(str);
		// }
	
		System.out.println("------------------");

		for (M = 2; M <= 8; M++) {
			int x = availableMemory / (2 * M); // Tamanho de cada Fila
			System.out.printf("Número de Filas: %d\n", M);
			System.out.printf("Cada fila caberia %d destinos\n", x);
			System.out.println("------------------");
		}
	}
}