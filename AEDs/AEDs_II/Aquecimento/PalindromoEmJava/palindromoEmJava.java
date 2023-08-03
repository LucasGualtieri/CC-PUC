import java.util.Scanner;

/*
	"a�a"					- SIM
	"a��a"					- SIM
	"aça"					- SIM
	"açça"					- SIM
	"açaça"					- SIM
	"açéa"					- NAO
	"açéaaéça"				- SIM
	"açéaéça"				- SIM
	"marrocos - socorram" 	- SIM
*/

class palindromoEmJava {

	public static boolean isPalin(String input) {
		String reversed = new StringBuilder(input).reverse().toString();
		return input.equals(reversed);
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		String input = new String();

		while (!(input = scanner.nextLine()).equals("FIM")) {
			// System.out.println(input);
			System.out.println(isPalin(input) ? "SIM" : "NAO");
		}

		scanner.close();
	}
}