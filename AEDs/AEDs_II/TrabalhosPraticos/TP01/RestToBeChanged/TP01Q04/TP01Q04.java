import java.util.Random;

public class TP01Q04 {

	public static String modify(String s, char a, char b) {

		String resp = "";

		for (int x = 0; x < s.length(); x++) {
			if (s.charAt(x) == a) {
				resp += b;
			} else {
				resp += s.charAt(x);
			}
		}

		return resp;

	}

	public static void main(String[] args) {

		Random ram = new Random();
		ram.setSeed(4);

		String entrada = new String("");

		while (true) {

			entrada = MyIO.readLine();

			if (entrada.compareTo("FIM") == 0) {
				break;
			}

			MyIO.println(modify(entrada,
					((char) ('a' + (Math.abs(ram.nextInt()) % 26))),
					((char) ('a' + (Math.abs(ram.nextInt()) % 26)))));
		}

	}
}
