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
	HashMap<Integer, T> hashVolta = new HashMap<>();

	int index;
	boolean diGraph;

	Graph(boolean diGraph) {
		index = 0;
		this.diGraph = diGraph;
		matrizAdjacencia = new ArrayList<>();
	}

	// Expands the matrix
	private int addNode(T x) {

		int matrixIndex = index++; 
		hashIda.put(x, matrixIndex);
		hashVolta.put(matrixIndex, x);

		matrizAdjacencia.add(new ArrayList<>());
		int size = matrizAdjacencia.size();

		for (int i = 0; i < size; i++) {
			if (i < size - 1) matrizAdjacencia.get(i).add(0);
			matrizAdjacencia.get(size - 1).add(0);
		}

		return matrixIndex;
	}

	public void addEdge(T a, T b) {

		Integer hashA = hashIda.get(a);
		Integer hashB = hashIda.get(b);

		// Criando o nó A
		if (hashA == null) hashA = addNode(a);

		// Criando o nó B
		if (hashB == null) hashB = addNode(b);

		matrizAdjacencia.get(hashA).set(hashB, 1);
		if (diGraph) {
			matrizAdjacencia.get(hashB).set(hashA, 1);
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

		System.out.print("  ");
	
		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print("\u001B[33m" + "\u001B[1m" + i + " \u001B[0m");
		}

		System.out.println();

		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print("\u001B[32m" + "\u001B[1m" + i + " \u001B[0m");
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				System.out.print(matrizAdjacencia.get(i).get(j) + " ");
			}
			System.out.println();
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
			s.delete(s.length() - 2, s.length());
			s.append("}\n");
		}

		s.deleteCharAt(s.length() - 1);

		return s.toString();
	}
}