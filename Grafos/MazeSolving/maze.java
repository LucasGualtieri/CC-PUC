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

		Queue<Integer> fila = new LinkedList<>();
		fila.add(inicio);

		// Map<Integer, Boolean> visitados = new HashMap<>();

		boolean visitados[] = new boolean[adjList.size()];
		for (int i = 0; i < visitados.length; i++) visitados[i] = false;

		int antecessor[] = new int[adjList.size()];
		for (int i = 0; i < antecessor.length; i++) antecessor[i] = -1;

		while (!fila.isEmpty()) {

			int u = fila.remove();
			visitados[u] = true;
			
			if (u == destino) break;
			
			for (int v : adjList.get(u)) {
				if (!visitados[v]) {
					fila.add(v);
					antecessor[v] = u;
				}
			}
		}

		// Reconstruir caminho
		List<Integer> caminho = new LinkedList<>();

		int passo = destino;
		while (passo != inicio) {
			caminho.add(0, passo);
			passo = antecessor[passo];
		}

		caminho.add(0, passo);

		return caminho;
    }

	public List<Integer> BuscaEm(int u) {

		Stack<Integer> estrutura = new Stack<>();
		estrutura.add(u);

		boolean descobertos[] = new boolean[adjList.size()];
		for (int i = 0; i < descobertos.length; i++) descobertos[i] = false;

		List<Integer> fechoTransitivoDireto = new ArrayList<>();
		descobertos[u] = true;

		while (!estrutura.isEmpty()) {

			int v = estrutura.pop();
			fechoTransitivoDireto.add(v);

			for (int adj : adjList.get(v)) {
				if (!descobertos[adj]) estrutura.add(adj);
				descobertos[adj] = true;
			}
		}

		return fechoTransitivoDireto;
    }

	public List<Integer> BuscaEmTeste(int u) {

		Stack<Integer> estrutura = new Stack<>();
		estrutura.add(u);

		boolean visitados[] = new boolean[adjList.size()];
		for (int i = 0; i < visitados.length; i++) visitados[i] = false;

		List<Integer> fechoTransitivoDireto = new ArrayList<>();

		while (!estrutura.isEmpty()) {

			int v = estrutura.pop();
			fechoTransitivoDireto.add(v);

			visitados[v] = true;

			for (int adj : adjList.get(v)) {
				if (!visitados[adj]) {
					estrutura.add(adj);
				}
			}
		}

		return fechoTransitivoDireto;
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

		System.out.println(grafo.BuscaEmTeste(1));
		// System.out.println(grafo.BuscaEm(1));

		// System.out.println(grafo.resolver(1, 0));

	}
}