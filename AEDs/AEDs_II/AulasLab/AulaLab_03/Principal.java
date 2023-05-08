public class Principal {
	public static void main(String[] args) {
		// Conta Lucas = new Conta();
		Especial Lucas = new Especial();

		Lucas.SetTitular("Lucas");
		Lucas.SetSaldo(1000);
		Lucas.SetLimite(5000);
		Lucas.SetNumero(1);

		Lucas.Imprime();
		// System.out.println(Lucas);

		System.out.println("Saldo " + Lucas.Saca(2500));
		// System.out.println("Saldo " + Lucas.Deposita(5));
		// System.out.println("Saldo " + Lucas.Saca(1001));

	}
}