package Grafos.MatrizAdjacencia.Java;

public class Grafo {

	static class Pessoa {
		private String nome;
		String sobrenome;

		Pessoa(String nome, String sobrenome) {
			this.nome = nome;
			this.sobrenome = sobrenome;
		}

		Pessoa(String nome) {
			this.nome = nome;
		}

		// public int hashCode() { return nome.hashCode(); }
		public String toString() { return nome; }
		// public String toString() { return nome + " " + sobrenome; }
	}

	// Função para limpar a tela
	static void clearScreen() {
		System.out.print("\033[H\033[2J");  
		System.out.flush();  
	}

	public static void main(String[] args) {

		Graph.clearScreen();

		Graph<Pessoa> g = new Graph<>();

		Pessoa lucas = new Pessoa("Lucas", "Gualtieri");
		Pessoa gabriel = new Pessoa("Gabriel", "Quaresma");
		Pessoa felipe = new Pessoa("Felipe", "Domingos");

		g.addEdge(lucas, gabriel);
		g.addEdge(gabriel, felipe);
		// g.addEdge(felipe, lucas);

		System.out.println(g.edgeExists(lucas, gabriel));
		System.out.println(g.edgeExists(gabriel, felipe));
		System.out.println(g.edgeExists(felipe, lucas));
		
		System.out.println("--------------");

		System.out.println(g);

		System.out.println("--------------");

		g.printMatrix();

		System.out.println("=========================");

		Graph<Integer> g2 = new Graph<>(true);

		g2.addEdge(1, 2);
		g2.addEdge(2, 1);
		g2.addEdge(2, 3, 3);
		// g2.addEdge(3, 1);

		System.out.println(g2.edgeExists(1, 2));
		System.out.println(g2.edgeExists(2, 3));
		System.out.println(g2.edgeExists(3, 1));
		
		System.out.println("--------------");

		System.out.println(g2);

		System.out.println("--------------");

		g2.printMatrix();
	}
}