public class Conta {

	// -------- Atributos --------

	private String titular;
	protected double saldo;
	private int numero;

	// -------- Construtores --------

	public Conta() {
		titular = new String("titular");
		saldo = 0;
		numero = 0;
	}

	public Conta(String titular, double saldo, int numero) {
		this.titular = new String(titular);
		this.saldo = saldo;
		this.numero = numero;
	}

	// -------- Métodos --------

	public double Deposita(double val) {
		saldo += val;
		return saldo;
	}

	public double Saca(double val) {
		if (saldo - val >= 0) {
			saldo -= val;
			return saldo;
		}
		System.out.printf("Saldo insuficiente: %.2f\n", saldo);
		return saldo;
	}

	public void Imprime() {
		System.out.println("Titular = " + titular);
		System.out.println("Saldo = " + saldo);
		System.out.println("Numero = " + numero);
	}

	// -------- Setters --------

	public void SetTitular(String titular) {
		this.titular = titular;
	}

	public void SetSaldo(double saldo) {
		this.saldo = saldo;
	}

	public void SetNumero(int numero) {
		this.numero = numero;
	}

	// -------- Getters --------

	public String GetTitular() {
		return titular;
	}

	public double GetSaldo() {
		return saldo;
	}

	public int GetNumero() {
		return numero;
	}
}
