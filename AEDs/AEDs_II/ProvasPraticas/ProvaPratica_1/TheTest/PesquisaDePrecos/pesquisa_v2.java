import java.util.Scanner;

// clear && javac pesquisa_v2.java && java pesquisa_v2 < pub.in > out.txt
public class pesquisa_v2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int numeroDeEstados = Integer.parseInt(scanner.nextLine());
		boolean vantajoso = false;

		for (int i = 0; i < numeroDeEstados; i++) {
			String input[] = scanner.nextLine().split(" ");
			String estado = input[0];
			double precoAlcool = Double.parseDouble(input[1]);
			double precoGas = Double.parseDouble(input[2]);

			if ((precoAlcool * 100) / precoGas <= 70.0) {
				vantajoso = true;
				System.out.println(estado);
			}
		}

		if (!vantajoso) {
			System.out.print("*");
		}

		scanner.close();
	}
}
