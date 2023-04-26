import java.util.Scanner;

public class AlgebraBooleana {
	private static int LeituraDoPubIn(String vetor[]) {
		try (Scanner sc = new Scanner(System.in)) {
			int c = 0;

			do {
				String str = sc.nextLine();
				vetor[c] = str;
				c++;
			} while (sc.hasNextLine() == true);
			return c;
		}

	}

	private static void TransformaStringEmVetorChar(String vetor[], int tamanhoDoVetor) {

		for (int c = 0; c < tamanhoDoVetor; c++) {
			if (vetor[c].length() > 5) {
				char vetorChar[] = new char[vetor[c].length()];
				vetorChar = vetor[c].toCharArray();
				ParseChar(vetorChar);
			}
		}

	}

	private static void ParseChar(char vetorChar[]) {
		int A, B, C, inicioPesq, fimPesq = -8008;
		A = vetorChar[2];
		B = vetorChar[4];
		C = vetorChar[6];
		int inicioIndice = 6;
		if (vetorChar[0] == '3') {
			inicioIndice = 8;
		}

		for (int c = inicioIndice; c < vetorChar.length; c++) {
			if (vetorChar[c] == 'A') {
				vetorChar[c] = (char) A;
			} else if (vetorChar[c] == 'B') {
				vetorChar[c] = (char) B;
			} else if (vetorChar[c] == 'C') {
				vetorChar[c] = (char) C;
			}
		}

		for (int c = inicioIndice; c < vetorChar.length; c++) {
			if (vetorChar[c] == ')') {
				fimPesq = c;
				for (int j = c - 1; j > 0; j--) {
					if (vetorChar[j] == '(') {
						inicioPesq = j;
						AlgebraBool(inicioPesq, fimPesq, vetorChar);
						break;
					}

				}
			}
		}
		System.out.println(vetorChar[fimPesq]);

	}

	private static void AlgebraBool(int inicioPesq, int fimPesq, char[] vetorChar) {
		if (vetorChar[inicioPesq - 1] == 't') {
			for (int c = inicioPesq - 3; c < fimPesq; c++) {
				if (vetorChar[c] == '0') {
					vetorChar[fimPesq] = '1';
				} else if (vetorChar[c] == '1') {
					vetorChar[fimPesq] = '0';
				}
				vetorChar[c] = ' ';

			}

		} else if (vetorChar[inicioPesq - 1] == 'd') {
			vetorChar[fimPesq] = '1';
			for (int c = inicioPesq - 3; c < fimPesq; c++) {
				if (vetorChar[c] == '0') {
					vetorChar[fimPesq] = '0';
				}
				vetorChar[c] = ' ';
			}

		} else if (vetorChar[inicioPesq - 1] == 'r') {
			vetorChar[fimPesq] = '0';
			for (int c = inicioPesq - 2; c < fimPesq; c++) {
				if (vetorChar[c] == '1') {
					vetorChar[fimPesq] = '1';
				}
				vetorChar[c] = ' ';
			}
		}
	}

	public static void main(String[] args) {
		String[] vetor = new String[1000];
		int tamanhoDoVetor = LeituraDoPubIn(vetor);
		String novoVetor[] = new String[tamanhoDoVetor];
		novoVetor = vetor.clone();
		TransformaStringEmVetorChar(novoVetor, tamanhoDoVetor);
	}
}
