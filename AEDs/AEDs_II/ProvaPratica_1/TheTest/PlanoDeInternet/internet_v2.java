import java.util.Scanner;

// clear && javac internet_v2.java && java internet_v2 < pub.in > out.txt
public class internet_v2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		final int quotaMensalMB = scanner.nextInt(); // Constante
		int numeroDeMeses = scanner.nextInt();
		int saldoAtual = 0; // Acumulativo

		for (int i = 0; i < numeroDeMeses; i++) {
			int gastoNoMes = scanner.nextInt();

			saldoAtual += quotaMensalMB;
			saldoAtual -= gastoNoMes;
		}

		saldoAtual += quotaMensalMB; // numeroDeMeses + 1

		System.out.print(saldoAtual);

		scanner.close();
	}
}