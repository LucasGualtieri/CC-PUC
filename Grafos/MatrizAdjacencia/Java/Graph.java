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

	Graph(int nodes, boolean diGraph) {

		index = 0;

		this.diGraph = diGraph;

		matrizAdjacencia = new ArrayList<>(nodes);

		for (int i = 0; i < nodes; i++) {
			List<Integer> l = new ArrayList<>(nodes);
			for (int j = 0; j < nodes; j++) {
				l.add(0);
			}
			matrizAdjacencia.add(l);
		}
	}

	public void addEdge(T a, T b) {

		Integer hashA = hashIda.get(a);
		Integer hashB = hashIda.get(b);

		// Criando o nó A
		if (hashA == null) {
			hashIda.put(a, hashA = index++);
			hashVolta.put(hashA, a);
		}
		
		// Criando o nó B
		if (hashB == null) {
			hashIda.put(b, hashB = index++);
			hashVolta.put(hashB, b);
		}

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

		System.out.print("   ");
	
		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print(i + " ");
		}

		System.out.println();

		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			System.out.print(i + "| ");
			for (int j = 0; j < matrizAdjacencia.size(); j++) {
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
			for (int j = 0; j < matrizAdjacencia.size(); j++) {
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