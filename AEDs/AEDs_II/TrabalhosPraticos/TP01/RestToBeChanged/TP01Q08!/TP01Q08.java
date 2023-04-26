import java.io.*;
import java.net.*;

public class TP01Q08 {
	public static void main(String[] args) throws Exception {

		String[] entrada = new String[1000];
		int n = 0;

		do {
			entrada[n] = MyIO.readLine();
		} while (!(isFim(entrada[n++])));
		n--;

		for (int i = 0; i < n; i++) {

			MyIO.println(saida(entrada[i], entrada[i + 1]));
		}
	}

	static boolean isFim(String s) {
		return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
	}

	public static String getHtml(String endereco) {

		URL url;
		InputStream is = null;
		BufferedReader br;
		String resp = "", line;

		try {
			url = new URL(endereco);
			is = url.openStream();
			br = new BufferedReader(new InputStreamReader(is));

			while ((line = br.readLine()) != null) {
				resp += line + "\n";
			}
		} catch (MalformedURLException mue) {
			mue.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}

		try {
			is.close();
		} catch (IOException ioe) {
			// nothing to see here
		}
		return resp;
	}

	public static String saida(String nomepag, String endereco) {
		String html;
		html = getHtml(endereco);
		return (ocorrenciaHtml(html) + " " + nomepag);
	}

	public static String ocorrenciaHtml(String html) {
		int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
		int x6 = 0, x7 = 0, x8 = 0, x9 = 0, x10 = 0, x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0,
				x18 = 0, x19 = 0, x20 = 0, x21 = 0, x22 = 0;
		int x23 = 0;
		int x24 = 0;
		int x25 = 0;
		String resp = "";

		for (int i = 0; i < html.length(); i++) {
			if (html.charAt(i) == 'a') {
				x1++;
			} else if (html.charAt(i) == 'e') {
				x2++;
			} else if (html.charAt(i) == 'i') {
				x3++;
			} else if (html.charAt(i) == 'o') {
				x4++;
			} else if (html.charAt(i) == 'u') {
				x5++;
			}

			if ((int) html.charAt(i) == 225) {
				x6++;
			} else if ((int) html.charAt(i) == 233) {
				x7++;
			} else if ((int) html.charAt(i) == 237) {
				x8++;
			} else if ((int) html.charAt(i) == 243) {
				x9++;
			} else if ((int) html.charAt(i) == 250) {
				x10++;
			}

			if ((int) html.charAt(i) == 224) {
				x11++;
			} else if ((int) html.charAt(i) == 232) {
				x12++;
			} else if ((int) html.charAt(i) == 236) {
				x13++;
			} else if ((int) html.charAt(i) == 242) {
				x14++;
			} else if ((int) html.charAt(i) == 249) {
				x15++;
			}

			if ((int) html.charAt(i) == 227) {
				x16++;
			} else if ((int) html.charAt(i) == 245) {
				x17++;
			}

			if ((int) html.charAt(i) == 226) {
				x18++;
			} else if ((int) html.charAt(i) == 234) {
				x19++;
			} else if ((int) html.charAt(i) == 238) {
				x20++;
			} else if ((int) html.charAt(i) == 244) {
				x21++;
			} else if ((int) html.charAt(i) == 251) {
				x22++;
			}

			if (isCons(html.charAt(i)) == true) {
				x23++;
			}

			if (html.charAt(i) == '<' && html.charAt(i + 1) == 'b' && html.charAt(i + 3) == 'r'
					&& html.charAt(i + 4) == '>') {
				x24++;
			}

			if (html.charAt(i) == '<' && html.charAt(i + 1) == 't' && html.charAt(i + 2) == 'a'
					&& html.charAt(i + 3) == 'b' && html.charAt(i + 4) == 'l' && html.charAt(i + 5) == 'e'
					&& html.charAt(i + 6) == '>') {
				x25++;
			}
		}

		x23 = x23 - ((x24 * 2) + (x25 * 3));
		x1 = x1 - (x25 * 1);
		x2 = x2 - (x25 * 1);

		resp = ("a(" + x1 + ") " + "e(" + x2 + ") " + "i(" + x3 + ") " + "o(" + x4 + ") " + "u(" + x5 + ") " + "á(" + x6
				+ ") " + "é(" + x7 + ") " + "í(" + x8 + ") " + "ó(" + x9 + ") " + "ú(" + x10 + ") " + "à(" + x11 + ") "
				+ "è(" + x12 + ") " + "ì(" + x13 + ") " + "ò(" + x14 + ") " + "ù(" + x15 + ") " + "ã(" + x16 + ") "
				+ "õ(" + x17 + ") " + "â(" + x18 + ") " + "ê(" + x19 + ") " + "î(" + x20 + ") " + "ô(" + x21 + ") "
				+ "û(" + x22 + ") " + "consoante(" + x23 + ") " + "<br>(" + x24 + ") " + "<table>(" + x25 + ")");

		return resp;
	}

	public static boolean isCons(char c) {
		boolean x2 = true;
		if (!((c >= 'b' && c >= 'd') || (c >= 'f' && c >= 'h') || (c >= 'j' && c >= 'n') || (c >= 'p' && c >= 't')
				|| (c >= 'v' && c >= 'z'))) {
			x2 = false;
		}

		return x2;
	}
}
