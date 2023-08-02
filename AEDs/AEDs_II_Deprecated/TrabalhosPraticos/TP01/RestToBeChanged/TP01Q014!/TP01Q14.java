import java.util.Scanner;

public class TP01Q14 {
	private static int LeituraDoPubIn(String vetor[], Scanner sc, int c) {
		if (sc.hasNextLine() == true) {
			String str = sc.nextLine();
			vetor[c] = str;
			return LeituraDoPubIn(vetor, sc, c + 1);
		} else {
			return c;
		}
	}

	private static void TransformaStringEmVetorChar(String vetor[], int tamanhoDoVetor, int c) {
		if (c < tamanhoDoVetor) {
			if (vetor[c].length() > 5) {
				char vetorChar[] = new char[vetor[c].length()];
				vetorChar = vetor[c].toCharArray();
				ParseChar(vetorChar);
			}
			TransformaStringEmVetorChar(vetor, tamanhoDoVetor, c + 1);
		}
	}

	private static void ParseChar(char vetorChar[], int c) {
		int A, B, C, inicioPesq, fimPesq = -8008;
		A = vetorChar[2];
		B = vetorChar[4];
		C = vetorChar[6];
		int inicioIndice = 6;
		if (vetorChar[0] == '3') {
			inicioIndice = 8;
		}

		if (c < vetorChar.length) {
			if (vetorChar[c] == 'A') {
				vetorChar[c] = (char) A;
			} else if (vetorChar[c] == 'B') {
				vetorChar[c] = (char) B;
			} else if (vetorChar[c] == 'C') {
				vetorChar[c] = (char) C;
			}

			ParseChar(vetorChar, c + 1);
		}

		if (c < vetorChar.length) {
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
			ParseChar(vetorChar, c + 1);
		}

		if (c == vetorChar.length - 1) {
			System.out.println(vetorChar[fimPesq]);
		}
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

		if (inicioPesq > 1) {
			int newInicioPesq = -1;
			for (int c = inicioPesq - 2; c >= 0; c--) {
				if (vetorChar[c] == '(') {
					newInicioPesq = c;
					break;
				}
			}

			int newFimPesq = -1;
			for (int c = inicioPesq; c < vetorChar.length; c++) {
				if (vetorChar[c] == ')') {
					newFimPesq = c;
					break;
				}
			}

			if (newInicioPesq >= 0 && newFimPesq >= 0) {
				AlgebraBool(newInicioPesq, newFimPesq, vetorChar);
			}
		}
	}
}