package Grafos.MatrizAdjacencia.Java;

public class Operacoes {

	public static void main(String[] args) {

		Graph.clearScreen();

		Graph<String> g = new Graph<>();

		g.addEdge("Lucas", "Gabriel");
		g.addEdge("Gabriel", "Felipe");
		g.addEdge("Felipe", "Lucas");

		System.out.println(g);

		System.out.println("----------------------");

		g.printMatrix();
		
		g.MapOnBFS((x) -> x + 1);
		g.printMatrix();

		int result = g.ReduceOnBFS((x, y) -> x + y);
		System.out.println("Result: " + result);

	}
}