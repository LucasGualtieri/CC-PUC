package Grafos.MatrizAdjacencia.Java;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Graph<T> {

	public interface Reduce {
		int reduce(int x, int y);
	}
	public interface Map {
		int map(int x);
	}

	private List<List<Integer>> matrizAdjacencia;
	private HashMap<T, Integer> hashIda = new HashMap<>();
	private List<T> hashVolta = new ArrayList<>();
	private // HashMap<Integer, T> hashVolta = new HashMap<>();

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

	public int ReduceOnBFS(Reduce r) {

		int result = 0;

		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				int x = matrizAdjacencia.get(i).get(j);
				result = r.reduce(result, x);
			}
		}

		return result;
	}

	public void MapOnBFS(Map m) {

		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				int x = matrizAdjacencia.get(i).get(j);
				matrizAdjacencia.get(i).set(j, m.map(x));
			}
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

		// Calculates the maximum number of digits
		int maxIndexDigits = String.valueOf(matrizAdjacencia.size() - 1).length();

		for (int i = 0; i < maxIndexDigits + 1; i++) System.out.print(" ");

		// Print column indices with proper alignment
		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			cprintf("BOLD YELLOW", "%" + (maxIndexDigits) + "d", i);
			System.out.print(" ");
		}  

		System.out.println();

		for (int i = 0; i < matrizAdjacencia.size(); i++) {
			cprintf("BOLD GREEN", "%" + (maxIndexDigits) + "d", i);
			for (int j = 0; j < matrizAdjacencia.get(i).size(); j++) {
				cprintf(
					(i == j ? "GRAY" : ""), "%" + (maxIndexDigits + 1) + "d", 
					matrizAdjacencia.get(i).get(j)
				);
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
			if (s.charAt(s.length() - 1) != '{') {
				s.delete(s.length() - 2, s.length());
			}
			s.append("}\n");
		}

		s.deleteCharAt(s.length() - 1);

		return s.toString();
	}

	public static void cprintf(String color, String format, Object...args) {

		final String BOLD = "\u001B[1m";
		final String GRAY = "\u001B[30m";
		final String RED = "\u001B[31m";
		final String GREEN = "\u001B[32m";
		final String YELLOW = "\u001B[33m";
		final String BLUE = "\u001B[34m";
		final String MAGENTA = "\u001B[35m";
		final String CYAN = "\u001B[36m";
		final String RESET = "\u001B[0m";

		if (color == "BOLD") color = BOLD;
		else if (color == "GRAY") color = GRAY;
		else if (color == "BOLD GRAY") color = BOLD + GRAY;
		else if (color == "RED") color = RED;
		else if (color == "BOLD RED") color = BOLD + RED;
		else if (color == "GREEN") color = GREEN;
		else if (color == "BOLD GREEN") color = BOLD + GREEN;
		else if (color == "YELLOW") color = YELLOW;
		else if (color == "BOLD YELLOW") color = BOLD + YELLOW;
		else if (color == "BLUE") color = BLUE;
		else if (color == "BOLD BLUE") color = BOLD + BLUE;
		else if (color == "MAGENTA") color = MAGENTA;
		else if (color == "BOLD MAGENTA") color = BOLD + MAGENTA;
		else if (color == "CYAN") color = CYAN;
		else if (color == "BOLD CYAN") color = BOLD + CYAN;

		System.out.printf(color + format + RESET, args);
	}
	
	// Função para limpar a tela
	public static void clearScreen() {
		System.out.print("\033[H\033[2J");  
		System.out.flush();  
	}

}