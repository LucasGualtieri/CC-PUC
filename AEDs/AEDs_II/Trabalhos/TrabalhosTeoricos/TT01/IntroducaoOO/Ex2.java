package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.IntroducaoOO;

class Ex2 {
	static class Retangulo {
		double base, altura;

		Retangulo() {
			this(0.0, 0.0);
		}

		Retangulo(double base, double altura) {
			this.base = base;
			this.altura = altura;
		}

		double getArea() {
			return base * altura;
		}

		double getPerimetro() {
			return base * 2 + altura * 2;
		}

		double getDiagonal() {
			return Math.sqrt(Math.pow(base, 2) + Math.pow(altura, 2));
		}

	}

	public static void main(String[] args) {
		Retangulo r1, r2;
		r1 = new Retangulo(5, 10);
		r2 = new Retangulo(4, 3);

		System.out.printf("r1.area(): %.2f - r1.perim(): %.2f\n", r1.getArea(), r1.getPerimetro());
		System.out.printf("r2.diagonal(): %.2f\n", r2.getDiagonal());

	}
}