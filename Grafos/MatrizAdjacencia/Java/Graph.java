package Grafos.MatrizAdjacencia.Java;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

interface Graphable {
	int hashCode();
}

class Graph<T> implements Graphable {

	List<List<Integer>> matrizAdjacencia;
	HashMap<T, Integer> hashIda = new HashMap<>();
	List<T> hashVolta = new ArrayList<>();
	// HashMap<Integer, T> hashVolta = new HashMap<>();

	int index;
	boolean diGraph;

	Graph() { this(false); }

	Graph(boolean diGraph) {
		index = 0;
		this.diGraph = diGraph;
		matrizAdjacencia = new ArrayList<>();
	}

	// Expands the matrix
	private int addNode(T x) {

		int matrixIndex = index++; 
		hashIda.put(x, matrixIndex);
		hashVolta.add(x);
		// hashVolta.put(matrixIndex, x);

		matrizAdjacencia.add(new ArrayList<>());
		int size = matrizAdjacencia.size();

		for (int i = 0; i < size; i++) {
			if (i < size - 1) matrizAdjacencia.get(i).add(0);
			matrizAdjacencia.get(size - 1).add(0);
		}

		return matrixIndex;
	}

	public void addEdge(T a, T b) {
		addEdge(a, b, 1);
	}

	public void addEdge(T a, T b, int weight) {

		Integer hashA = hashIda.get(a);
		Integer hashB = hashIda.get(b);

		// Criando o nó A
		if (hashA == null) hashA = addNode(a);

		// Criando o nó B
		if (hashB == null) hashB = addNode(b);

		matrizAdjacencia.get(hashA).set(hashB, weight);
		if (!diGraph) {
			matrizAdjacencia.get(hashB).set(hashA, weight);
		}
	}

	public boolean edgeExists(T a, T b) {

		Integer hashA = hashIda.get(a);
		Integer hashB = hashIda.get(b);
		int x;

		if (hashA != null && hashB != null) {
			x = matrizAdjacencia.get(hashA).get(hashB);
		}
		else return false;

		return x == 1;
	}

	void printMatrix() {

		final String BOLD = "\u001B[1m";
		final String GRAY = "\u001B[30m";
		// final String RED = "\u001B[31m";
		final String GREEN = "\u001B[32m";
		final String YELLOW = "\u001B[33m";
		final String RESET = "\u001B[0m";

		System.out.print("  ");
	
		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print(YELLOW + BOLD + i + " \u001B[0m");
		}

		System.out.println();


		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print(GREEN + BOLD + i + " " + RESET);
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				if (i == j) System.out.print(GRAY + matrizAdjacencia.get(i).get(j) + " " + RESET);
				else System.out.print(matrizAdjacencia.get(i).get(j) + " ");
			}
			System.out.println("\u001B[0m");
		}
	}

	public String toString() {
		StringBuilder s = new StringBuilder();

		for (int i = 0; i < matrizAdjacencia.size(); ++i) {
			T a = hashVolta.get(i);
			s.append(a + " -> {");
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				T b = hashVolta.get(j);
				if (matrizAdjacencia.get(i).get(j) != 0) {
					s.append("(" + a + ", " + b + "), ");
				}
			}
			if (s.charAt(s.length() - 1) != '{') {
				s.delete(s.length() - 2, s.length());
			}
			s.append("}\n");
		}

		s.deleteCharAt(s.length() - 1);

		return s.toString();
	}
}