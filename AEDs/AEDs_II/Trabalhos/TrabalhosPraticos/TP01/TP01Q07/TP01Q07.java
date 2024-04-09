package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.TP01Q07;

import java.net.*;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP01.Lib;

import java.io.*;

// clear && javac -cp ../.. TP01Q07.java && java -cp ../.. TP01Q07.java < pub.in > result.txt

class TP01Q07 {

	/*
		- Essa classe se propõe a ajudar no processo
		de contagem, armazenamento e entrega do resultado final.	
	*/
	static class Contador {

		/*
			- Essas definições foram necessárias para
			lidar o os diferentes charsets, tanto
			para fazer as comparações, quanto para
			imprimir o resultado na tela.
			- Elas representam as vogais acentuadas.
		*/
		static final char aAgudo = 225;
		static final char eAgudo = 233;
		static final char iAgudo = 237;
		static final char oAgudo = 243;
		static final char uAgudo = 250;
		static final char aCrase = 224;
		static final char eCrase = 232;
		static final char iCrase = 236;
		static final char oCrase = 242;
		static final char uCrase = 249;
		static final char aTil = 227;
		static final char oTil = 245;
		static final char aCircunflexo = 226;
		static final char eCircunflexo = 234;
		static final char iCircunflexo = 238;
		static final char oCircunflexo = 244;
		static final char uCircunflexo = 251;

		int aNormalCount = 0;
		int eNormalCount = 0;
		int iNormalCount = 0;
		int oNormalCount = 0;
		int uNormalCount = 0;
		int aAgudoCount = 0;
		int eAgudoCount = 0;
		int iAgudoCount = 0;
		int oAgudoCount = 0;
		int uAgudoCount = 0;
		int aCraseCount = 0;
		int eCraseCount = 0;
		int iCraseCount = 0;
		int oCraseCount = 0;
		int uCraseCount = 0;
		int aTilCount = 0;
		int oTilCount = 0;
		int aCircunflexoCount = 0;
		int eCircunflexoCount = 0;
		int iCircunflexoCount = 0;
		int oCircunflexoCount = 0;
		int uCircunflexoCount = 0;

		/*
			- Recebe uma string contendo um arquvi HTML completo.
			- Conta a quantidade de vogais normais e acentuadas presentes.
			- Salva essas quantidades nos atributos da classe.
		*/
		Contador(String HTML) {
			int htmlLen = HTML.length();
			for (int i = 0; i < htmlLen; i++) {

				// Evitando os <tables>
				if (i < htmlLen - 7) {
					if (Lib.isEqual(HTML.substring(i, i + 7), "<table>")) {
						i += 7;
					}
				} else if (i < htmlLen - 4) { // Evitando os <br>
					if (Lib.isEqual(HTML.substring(i, i + 4), "<br>")) {
						i += 4;
					}
				}

				char c = HTML.charAt(i);
				if (c == 'a') aNormalCount++;
				else if (c == 'e') eNormalCount++;
				else if (c == 'i') iNormalCount++;
				else if (c == 'o') oNormalCount++;
				else if (c == 'u') uNormalCount++;
				else if (c == aAgudo) aAgudoCount++;
				else if (c == eAgudo) eAgudoCount++;
				else if (c == iAgudo) iAgudoCount++;
				else if (c == oAgudo) oAgudoCount++;
				else if (c == uAgudo) uAgudoCount++;
				else if (c == aCrase) aCraseCount++;
				else if (c == eCrase) eCraseCount++;
				else if (c == iCrase) iCraseCount++;
				else if (c == oCrase) oCraseCount++;
				else if (c == uCrase) uCraseCount++;
				else if (c == aTil) aTilCount++;
				else if (c == oTil) oTilCount++;
				else if (c == aCircunflexo) aCircunflexoCount++;
				else if (c == eCircunflexo) eCircunflexoCount++;
				else if (c == iCircunflexo) iCircunflexoCount++;
				else if (c == oCircunflexo) oCircunflexoCount++;
				else if (c == uCircunflexo) uCircunflexoCount++;
			}
		}
		
		/*
			Imprime na tela a vogal e a quantidade de vogais
			lidas do HTML. Esse método imprime as letras a partir
			das constantes presentes nessa classe, para garantir
			que o caractere impresso esteja corretamente renderizado.
		*/
		public void imprimir() {
			System.out.printf("a(%d) ", aNormalCount);
			System.out.printf("e(%d) ", eNormalCount);
			System.out.printf("i(%d) ", iNormalCount);
			System.out.printf("o(%d) ", oNormalCount);
			System.out.printf("u(%d) ", uNormalCount);
			System.out.printf("%c(%d) ", aAgudo, aAgudoCount);
			System.out.printf("%c(%d) ", eAgudo, eAgudoCount);
			System.out.printf("%c(%d) ", iAgudo, iAgudoCount);
			System.out.printf("%c(%d) ", oAgudo, oAgudoCount);
			System.out.printf("%c(%d) ", uAgudo, uAgudoCount);
			System.out.printf("%c(%d) ", aCrase, aCraseCount);
			System.out.printf("%c(%d) ", eCrase, eCraseCount);
			System.out.printf("%c(%d) ", iCrase, iCraseCount);
			System.out.printf("%c(%d) ", oCrase, oCraseCount);
			System.out.printf("%c(%d) ", uCrase, uCraseCount);
			System.out.printf("%c(%d) ", aTil, aTilCount);
			System.out.printf("%c(%d) ", oTil, oTilCount);
			System.out.printf("%c(%d) ", aCircunflexo, aCircunflexoCount);
			System.out.printf("%c(%d) ", eCircunflexo, eCircunflexoCount);
			System.out.printf("%c(%d) ", iCircunflexo, iCircunflexoCount);
			System.out.printf("%c(%d) ", oCircunflexo, oCircunflexoCount);
			System.out.printf("%c(%d) ", uCircunflexo, uCircunflexoCount);
		}
	}

	// Retorna verdadeiro se o caractere for consoante
	static boolean isConsonant(char c) {
		// return Lib.isAlpha(c) && !Lib.isVowel(c); // Alternativa menos custosa de se testar consoante
		return Lib.isPresent(Lib.toLower(c), "bcdfghjklmnpqrstvwxyz");
	}

	/*
		- Recebe um endereço/link/URL
		- Retorna uma string contendo o arquivo
		html inteiro a partir do endereço.
	*/
	static String getHTML(String endereco) {
		String line, html = "";
		try {
			URL url = new URL(endereco);
			InputStream is = url.openStream(); // throws an IOException
			Lib.br = new BufferedReader(new InputStreamReader(is));
			while ((line = Lib.br.readLine()) != null) { html += line + "\n"; }
		} catch (MalformedURLException mue) {
			mue.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
		return html;
	}

	/*
		- Retorna a quantidade de tags
		<br> presentes no html.
	*/
	static int lineBreakCount(String HTML) {
		int countLineBreak = 0;
		int htmlLen = HTML.length();
		int brLen = 4;
		for (int i = 0; i < htmlLen - brLen; i++) {
			if (Lib.isEqual(HTML.substring(i, i + brLen), "<br>")) {
				countLineBreak++;
			}
		}
		return countLineBreak;
	}

	/*
		- Retorna a quantidade de tags
		<table> presentes no html.
	*/
	static int tableCount(String HTML) {
		int countTable = 0;
		int htmlLen = HTML.length();
		int tableLen = 7;
		for (int i = 0; i < htmlLen - tableLen; i++) {
			if (Lib.isEqual(HTML.substring(i, i + tableLen), "<table>")) {
				countTable++;
			}
		}
		return countTable;
	}

	/*
		- Retorna a quantidade de consoantes
		minúsculas presentes no html.
	*/
	static int consonantCount(String HTML) {
		int countConsonant = 0;
		int htmlLen = HTML.length();
		for (int i = 0; i < htmlLen; i++) {
			// Evitando os <tables>
			if (i < htmlLen - 7) {
				if (Lib.isEqual(HTML.substring(i, i + 7), "<table>")) {
					i += 7;
				}
			} else if (i < htmlLen - 4) { // Evitando os <br>
				if (Lib.isEqual(HTML.substring(i, i + 4), "<br>")) {
					i += 4;
				}
			}
			char c = HTML.charAt(i);
			if (Lib.isLowerCase(c) && isConsonant(c)) countConsonant++;
		}
		return countConsonant;
	}

	public static void main(String[] args) {

		String nomeDaPagina = new String();
		while(!Lib.isEqual(nomeDaPagina = Lib.getstr(), "FIM")) {
			String URL = Lib.getstr();
			String HTML = getHTML(URL);
			Contador vogais = new Contador(HTML);
			vogais.imprimir();
			System.out.printf("consoante(%d) ", consonantCount(HTML));
			System.out.printf("<br>(%d) ", lineBreakCount(HTML));
			System.out.printf("<table>(%d) ", tableCount(HTML));
			System.out.println(nomeDaPagina);
		}
	}
}