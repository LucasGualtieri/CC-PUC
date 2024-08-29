package Grafos.MazeSolving;

import java.util.*;

// clear && javac maze.java && java maze.java

class Grafo {

	private Map<Integer, List<Integer>> adjList;

	public Grafo() {
		adjList = new HashMap<>();
	}

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

	public List<Integer> resolver(int inicio, int destino) {

        // Cria uma fila para a BFS e marca o nó de início como visitado
        Queue<Integer> fila = new LinkedList<>();
        Set<Integer> visitados = new HashSet<>();

		HashMap<Integer, Integer> antecessor = new HashMap<>();

        fila.add(inicio);
        visitados.add(inicio);

        // Enquanto a fila não estiver vazia, continue processando os nós
        while (!fila.isEmpty()) {

            int noAtual = fila.poll();
			if (noAtual == destino) break;
            // System.out.print(noAtual + " ");

            // Pega todos os vizinhos do nó atual
            for (int vizinho : adjList.get(noAtual)) {
                // Se o vizinho ainda não foi visitado, adiciona na fila e marca como visitado
                if (!visitados.contains(vizinho)) {
                    fila.add(vizinho);
                    visitados.add(vizinho);
					antecessor.put(vizinho, noAtual);
                }
            }
        }

		// Reconstruir caminho
		List<Integer> caminho = new ArrayList<>();

		int passo = destino;
		while (passo != inicio) {
			caminho.add(0, passo);
			passo = antecessor.get(passo);
		}

		caminho.add(0, passo);

		return caminho;
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

		System.out.println(grafo.resolver(1, 0));

	}
}