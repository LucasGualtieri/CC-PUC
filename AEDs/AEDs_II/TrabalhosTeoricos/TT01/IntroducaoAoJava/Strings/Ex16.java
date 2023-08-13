import java.util.*;

// Não entendi, peguei a resposta.
// e mesmo assim não entendi, abalo...

class Ex16 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String str = scanner.nextLine();
		int num = 0, tmp;
		for (int i = 0; i < str.length(); i++) {
			tmp = (int) (str.charAt(i) - 48);
			tmp *= (int) Math.pow(10, str.length() - i - 1);
			num += tmp;
		}

		System.out.println(num);

		scanner.close();
	}
}