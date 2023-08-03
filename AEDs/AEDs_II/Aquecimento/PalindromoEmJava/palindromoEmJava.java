import java.util.Scanner;

class palindromoEmJava {

	public static boolean isPalin(String input) {
		StringBuilder reversed = new StringBuilder(input);
		return input.equals(reversed.reverse().toString());
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		String input = new String();

		while (!(input = scanner.nextLine()).equals("FIM")) {
			System.out.println(isPalin(input) ? "SIM" : "NAO");
		}

		scanner.close();
	}
}