public class Especial extends Conta {
	private double limite;

	public Especial() {
		super();
	}

	public double Saca(double val) {
		if (saldo - val + limite >= 0) {
			saldo -= val;
			return saldo;
		}
		System.out.printf("Limite insuficiente: %.2f\n", saldo);
		return saldo;
	}

	public void SetLimite(double limite) {
		this.limite = limite;
	}
}
