package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoOO;

class Ex3 {

	static class Ponto {
		private double x, y;
		private int id;
		private static int nextID = 0;

		Ponto() {
			this(0.0, 0.0);
		}

		Ponto(double x, double y) {
			this.x = x;
			this.y = y;
			id = nextID;
			nextID++;
		}

		void setX(double x) {
			this.x = x;
		}

		double getX() {
			return x;
		}

		void setY(double y) {
			this.y = y;
		}

		double getY() {
			return y;
		}

		double dist(Ponto other) {
			double dx = other.x - this.x;
			double dy = other.y - this.y;
			return Math.sqrt(dx * dx + dy * dy);
		}

		double dist(double x, double y) {
			double dx = x - this.x;
			double dy = y - this.y;
			return Math.sqrt(dx * dx + dy * dy);
		}

		static double dist(double x1, double y1, double x2, double y2) {
			double dx = x2 - x1;
			double dy = y2 - y1;
			return Math.sqrt(dx * dx + dy * dy);
		}

		static boolean isTriangulo(Ponto p1, Ponto p2, Ponto p3) {
			double a = p1.dist(p2);
			double b = p1.dist(p3);
			double c = p2.dist(p3);
			return a + b > c && a + c > b && b + c > a;
		}

		double getAreaRetangulo(Ponto other) {
			double width = Math.abs(other.x - this.x);
			double height = Math.abs(other.y - this.y);
			return width * height;
		}

		int getID() {
			return id;
		}

		static int getNextID() {
			return nextID;
		}
	}

	public static void main(String[] args) {
		Ponto p1 = new Ponto(4, 3);
		Ponto p2 = new Ponto(8, 5);
		Ponto p3 = new Ponto(9.2, 10);
		System.out.println("Distancia p1 entre e p2: " + p1.dist(p2));
		System.out.println("Distancia p1 entre e (5,2): " + p1.dist(5, 2));
		System.out.println("Distancia (4,3) entre e (5,2): " + Ponto.dist(4, 3, 5, 2));
		System.out.println("P1, P2, P3 sao triangulo:" + Ponto.isTriangulo(p1, p2, p3));
		System.out.println("Area retangulo:" + p1.getAreaRetangulo(p2));
		System.out.println("ID de P1: " + p1.getID());
		System.out.println("ID de P2: " + p2.getID());
		System.out.println("ID de P3: " + p3.getID());
		System.out.println("Next ID: " + Ponto.getNextID());
	}
}