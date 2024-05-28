package AEDs.AEDs_III.Materias.FilaDePrioridades;

public class Principal {

	private static class Pessoa implements Comparable<Pessoa> {

		public String nome;
		public int idade;

		public Pessoa(String nome, int idade) {
			this.nome = nome;
			this.idade = idade;
		}

		@Override
		public int compareTo(Pessoa arg0) {
			return Integer.compare(idade, arg0.idade);
		}

		public String toString() {
			return String.format("[%s, %d]", nome, idade);
		}
	}

	public static void main(String[] args) {

		PriorityQueue<Pessoa> q = new PriorityQueue<>();

		q.add(new Pessoa("Ga", 21));
		System.out.println(q);
		q.add(new Pessoa("Go", 21));
		System.out.println(q);
		q.add(new Pessoa("L", 20));
		System.out.println(q);
		q.add(new Pessoa("A", 22));
		System.out.println(q);
		q.add(new Pessoa("B", 22));
		System.out.println(q);
		q.add(new Pessoa("C", 19));
		System.out.println(q);

	}
}
