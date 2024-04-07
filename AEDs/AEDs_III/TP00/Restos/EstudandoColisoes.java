package Restos;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Random;

class EstudandoColisoes {

	// clear && javac Teste.java && java Teste.java

	static class Dupla {
		Integer valor;
		int colisoes;

		public Dupla(Integer valor) {
			this.valor = valor;
			this.colisoes = 1;
		}

		public void setColisoes() {
			this.colisoes++;
		}

		public int getValor() {
			return valor;
		}

		public String toString() {
			String str = "Valor: ";

			str += valor.toString();
			str += ", Colisões: ";
			str += String.valueOf(colisoes);
			str += "\n";


			return str;
		}
	}

	public static Dupla exists(Integer integer, List<Dupla> colisoes) {
		for (int i = 0; i < colisoes.size(); i++) {
			if (colisoes.get(i).getValor() == integer) {
				return colisoes.get(i);
			}
		}
		return null;
	}

	public static List<Dupla> numberOfColisions(List<Integer> array) {

		List<Dupla> colisoes = new ArrayList<>();

		int total = 0;

		for (int i = 0; i < array.size() - 1; i++) {
			for (int j = i + 1; j < array.size(); j++) {
				if (array.get(i) == array.get(j)) {
					total++;
					Dupla n = exists(array.get(j), colisoes);
					if (n != null) {
						n.setColisoes();
					} else {
						colisoes.add(new Dupla(array.get(j)));
					}
					array.remove(array.get(j));
				}
			}
		}

		System.out.println("Total: " + total);

		return colisoes;
	}

	public static void main(String[] args) {

		int N = 26;

		List<Integer> array = new ArrayList<>();

		Random gerador = new Random(System.currentTimeMillis());

		for (int i = 0; i < N; i++) {
			
			// int x = gerador.nextInt();
			// int z = x % N;
			
			// int x = gerador.nextInt();
			// int y = x & 0x7FFFFFFF;
			// int z = y % N;
			
			// int x = gerador.nextInt();
			// int y = x & 0x7FFFFFFF;
			// int z = ((y % N) + N) % N;
			
			int x = gerador.nextInt();
			int z = Integer.hashCode(x) % N;

			array.add(z);

			// System.out.println(x);
			// System.out.println(y);
			System.out.print(z + " ");
		}

		System.out.println("\n---------------------");

		// array.forEach(number -> {
		// 	System.out.print(number + " ");
		// });
		
		List<Dupla> newArray = numberOfColisions(array);
		newArray.forEach(number -> System.out.print(number));
		
		// for (int i = 0; i < 25; i++) {
		// 	// int index1 = (-i % N + N) % N;
		// 	// int index2 = (i % N + N) % N;
		// 	int index1 = Math.abs((-i + Integer.MAX_VALUE)) % N;
		// 	int index2 = Math.abs((i + Integer.MAX_VALUE)) % N;
	
		// 	System.out.println(index1);
		// 	System.out.println(index2);
		// 	System.out.println("-----------------");
		// }

	}
}