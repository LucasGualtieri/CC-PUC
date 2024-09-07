package Grafos;

import java.util.*;

// clear && javac excentricidade.java && java excentricidade.java

class Grafo {

	private Map<Integer, List<Integer>> adjList;

	public Grafo() { adjList = new HashMap<>(); }

	public void adicionarAresta(int origem, int destino) {

		adjList.putIfAbsent(origem, new ArrayList<>());
		adjList.putIfAbsent(destino, new ArrayList<>());
		adjList.get(origem).add(destino);
		adjList.get(destino).add(origem);
	}

	public void imprimirGrafo() {
		for (int no : adjList.keySet()) {
			System.out.print(no + " -> ");
			for (int vizinho : adjList.get(no)) {
				System.out.print(vizinho + " ");
			}
			System.out.println();
		}
	}

	public int excentricidade(int u) {

		Queue<Integer> fila = new LinkedList<>();
		Set<Integer> visitados = new HashSet<>();
		HashMap<Integer, Integer> antecessor = new HashMap<>();

		fila.add(u);
		visitados.add(u);

		int noAtual = 0;

		while (!fila.isEmpty()) {

			noAtual = fila.poll();

			for (int vizinho : adjList.get(noAtual)) {

				if (!visitados.contains(vizinho)) {

					fila.add(vizinho);
					visitados.add(vizinho);
					antecessor.put(vizinho, noAtual);
				}
			}
		}

		int distancia = 0;
		int passo = noAtual;

		while (passo != u) {
			distancia++;
			passo = antecessor.get(passo);
		}

		return distancia;
	}

	public static void main(String[] args) throws InterruptedException {

		Grafo grafo = new Grafo();

		// Adicionando as arestas conforme a imagem
		{
			grafo.adicionarAresta(1, 2);
			grafo.adicionarAresta(2, 3);
			grafo.adicionarAresta(3, 4);
			grafo.adicionarAresta(3, 5);
			grafo.adicionarAresta(5, 6);
			grafo.adicionarAresta(7, 6);
			grafo.adicionarAresta(7, 32);
			grafo.adicionarAresta(8, 7);
			grafo.adicionarAresta(9, 8);
			grafo.adicionarAresta(9, 10);
			grafo.adicionarAresta(9, 14);
			grafo.adicionarAresta(11, 10);
			grafo.adicionarAresta(11, 12);
			grafo.adicionarAresta(12, 13);

			grafo.adicionarAresta(14, 15);
			grafo.adicionarAresta(15, 16);
			grafo.adicionarAresta(16, 17);
			grafo.adicionarAresta(17, 18);
			grafo.adicionarAresta(18, 19);
			grafo.adicionarAresta(19, 20);
			grafo.adicionarAresta(20, 21);
			grafo.adicionarAresta(21, 22);
			grafo.adicionarAresta(21, 29);
			grafo.adicionarAresta(22, 23);
			grafo.adicionarAresta(23, 24);
			grafo.adicionarAresta(24, 25);
			grafo.adicionarAresta(26, 25);
			grafo.adicionarAresta(27, 26);
			grafo.adicionarAresta(26, 28);
			grafo.adicionarAresta(28, 0);
			grafo.adicionarAresta(29, 30);
			grafo.adicionarAresta(30, 31);
			grafo.adicionarAresta(32, 33);
			grafo.adicionarAresta(33, 34);
			grafo.adicionarAresta(34, 35);
		}

		// grafo.adicionarAresta(13, 0);

		// System.out.println("Começo");

		// for (int j = 0; j < 60; j++) {
		// 	for (int i = 0; i < 5000; i++) {
		// 		grafo.resolver(1, 0);
		// 	}
		// 	// Thread.sleep(100);
		// }

		// System.out.println(grafo.resolver(1, 0));

		int raio = Integer.MAX_VALUE;
		int diametro = Integer.MIN_VALUE;

		for (int i = 0; i <= 35; i++) {

			int value = grafo.excentricidade(i);

			if (value < raio) raio = value;
			else if (value > diametro) diametro = value;

			System.out.printf("Excentricidade de %d = %d\n", i, value);
		}

		System.out.println("Raio: " + raio);
		System.out.println("Diametro: " + diametro);

	}
}