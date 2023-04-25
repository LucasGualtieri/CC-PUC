import java.io.*;

class Personagem {
	private String nome;
	private int altura;
	private double peso;
	private String corDoCabelo;
	private String corDaPele;
	private String corDosOlhos;
	private String anoNascimento;
	private String genero;
	private String homeworld;

	public Personagem() {
	}

	public Personagem(String nome, int altura, double peso, String corDoCabelo, String corDaPele,
			String corDosOlhos, String anoNascimento, String genero, String homeworld) {
		this.nome = nome;
		this.altura = altura;
		this.peso = peso;
		this.corDoCabelo = corDoCabelo;
		this.corDaPele = corDaPele;
		this.corDosOlhos = corDosOlhos;
		this.anoNascimento = anoNascimento;
		this.genero = genero;
		this.homeworld = homeworld;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNome() {
		return nome;
	}

	public void setAltura(int altura) {
		this.altura = altura;
	}

	public int getAltura() {
		return altura;
	}

	public void setPeso(double peso) {
		this.peso = peso;
	}

	public double getPeso() {
		return peso;
	}

	public void setCorDoCabelo(String corDoCabelo) {
		this.corDoCabelo = corDoCabelo;
	}

	public String getCorDoCabelo() {
		return corDoCabelo;
	}

	public void setCorDaPele(String corDaPele) {
		this.corDaPele = corDaPele;
	}

	public String getCorDaPele() {
		return corDaPele;
	}

	public void setCorDosOlhos(String corDosOlhos) {
		this.corDosOlhos = corDosOlhos;
	}

	public String getCorDosOlhos() {
		return corDosOlhos;
	}

	public String getAnoNascimento() {
		return anoNascimento;
	}

	public void setAnoNascimento(String anoNascimento) {
		this.anoNascimento = anoNascimento;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}

	public String getHomeworld() {
		return homeworld;
	}

	public void setHomeworld(String homeworld) {
		this.homeworld = homeworld;
	}

	public Personagem clone() {
		Personagem cloned = new Personagem();

		cloned.nome = this.nome;
		cloned.altura = this.altura;
		cloned.peso = this.peso;
		cloned.corDoCabelo = this.corDoCabelo;
		cloned.corDaPele = this.corDaPele;
		cloned.corDosOlhos = this.corDosOlhos;
		cloned.anoNascimento = this.anoNascimento;
		cloned.genero = this.genero;
		cloned.homeworld = this.homeworld;

		return cloned;
	}
}

class Lista {
	static Personagem[] listaPersonagens = new Personagem[100];
	int contadorTamanho = 0;
	int numeroComparacoes = 0, numeroMovimentacoes = 0;

	// Inserir registro na última posição
	public void inserir(Personagem personagem) throws Exception {
		if (contadorTamanho >= listaPersonagens.length) {
			throw new Exception("Erro!");
		}

		listaPersonagens[contadorTamanho] = personagem;

		contadorTamanho++; // Incrementar o tamanho do vetor
	}

	// Criar função vazia
	public void ordenaPorMergesort() {
		ordenaPorMergesort(0, contadorTamanho - 1);
	}

	// Ordenar o vetor por Mergesort
	public void ordenaPorMergesort(int esq, int dir) {
		if (esq < dir) {
			int meio = (esq + dir) / 2;
			ordenaPorMergesort(esq, meio);
			ordenaPorMergesort(meio + 1, dir);
			intercalarVetores(esq, meio, dir);
		}
	}

	// Intercalar os vetores
	public void intercalarVetores(int esq, int meio, int dir) {
		// Definir tamanho dos dois subarrays
		int nEsq = (meio + 1) - esq;
		int nDir = dir - meio;
		Personagem[] arrayEsq = new Personagem[nEsq + 1];
		Personagem[] arrayDir = new Personagem[nDir + 1];

		// Sentinela no final dos dois arrays
		arrayEsq[nEsq] = arrayDir[nDir] = new Personagem();
		arrayEsq[nEsq].setHomeworld("zzzzzz"); // Garantir que nenhum homeWorld será maior
		arrayDir[nDir].setHomeworld("zzzzzz"); // Garantir que nenhum homeWorld será maior

		numeroMovimentacoes += 2;

		int iEsq, iDir, i;
		// Inicializar primeiro subarray
		for (iEsq = 0; iEsq < nEsq; iEsq++) {
			arrayEsq[iEsq] = listaPersonagens[esq + iEsq];

			numeroComparacoes++;
			numeroMovimentacoes++;
		}
		numeroComparacoes++;

		// Inicializar segundo subarray
		for (iDir = 0; iDir < nDir; iDir++) {
			arrayDir[iDir] = listaPersonagens[(meio + 1) + iDir];

			numeroComparacoes++;
			numeroMovimentacoes++;
		}
		numeroComparacoes++;

		// Intercalação propriamente dita
		for (iEsq = iDir = 0, i = esq; i <= dir; i++) {
			listaPersonagens[i] = ((arrayEsq[iEsq].getHomeworld()).compareTo(arrayDir[iDir].getHomeworld()) <= 0)
					? arrayEsq[iEsq++]
					: arrayDir[iDir++];

			numeroComparacoes++;
			numeroMovimentacoes++;
		}
		numeroComparacoes++;
	}

	// Imprimir resultados
	public void imprimeResultados() {
		for (int i = 0; i < contadorTamanho; i++) {
			MyIO.print(" ## " + listaPersonagens[i].getNome());
			MyIO.print(" ## " + listaPersonagens[i].getAltura());
			if (listaPersonagens[i].getPeso() % 1 == 0) {
				MyIO.print(" ## " + (int) listaPersonagens[i].getPeso());
			} else {
				MyIO.print(" ## " + listaPersonagens[i].getPeso());
			}
			MyIO.print(" ## " + listaPersonagens[i].getCorDoCabelo());
			MyIO.print(" ## " + listaPersonagens[i].getCorDaPele());
			MyIO.print(" ## " + listaPersonagens[i].getCorDosOlhos());
			MyIO.print(" ## " + listaPersonagens[i].getAnoNascimento());
			MyIO.print(" ## " + listaPersonagens[i].getGenero());
			MyIO.print(" ## " + listaPersonagens[i].getHomeworld());
			MyIO.println(" ## ");
		}
	}

	// Criar arquivo de log
	public void criarLog(long tempoInicial) {
		long tempoFinal = System.currentTimeMillis(); // Gravar o tempo do fim da execução

		Arq.openWrite("matricula_mergesort.txt");
		Arq.println(
				"Matricula: 790052\t" + "Numero Comparacoes: " + numeroComparacoes + "\t" + "Numero de Movimentacoes: "
						+ numeroMovimentacoes + "\t" + "Tempo Execucao: " + (tempoFinal - tempoInicial) + "ms");
		Arq.close();
	}
}

public class TP02Q17 {
	public static void main(String[] args) throws Exception {
		MyIO.setCharset("ISO-8859-1");
		long tempoInicial = System.currentTimeMillis(); // Gravar tempo de início de execução

		Lista listaPersonagens = new Lista();

		String caminhoArquivo = MyIO.readLine().replaceAll("é", "\u00e9");

		// Testar fim da do arquivo
		while (testaFim(caminhoArquivo) == false) {

			// Montar personagem e adicionar ao fim da lista
			listaPersonagens.inserir(montaPersonagem(caminhoArquivo));

			caminhoArquivo = MyIO.readLine().replaceAll("é", "\u00e9");
		}

		listaPersonagens.ordenaPorMergesort(); // Ordenar por Mergesort

		listaPersonagens.imprimeResultados(); // Imprimir os resultados

		listaPersonagens.criarLog(tempoInicial); // Passar o tempo de início da execução
	}

	// Testar fim do arquivo
	public static boolean testaFim(String palavra) {
		boolean teste = false;

		if (palavra.equals("FIM")) {
			teste = true;
		}

		return teste;
	}

	// Retornar personagem lido
	public static Personagem montaPersonagem(String caminhoArquivo) throws Exception {
		RandomAccessFile leitura = new RandomAccessFile(caminhoArquivo, "r");

		String descricaoPersonagem = leitura.readLine().replaceAll("é", "\u00e9");

		Personagem personagem = new Personagem();
		int contadorDoisPontos = 0; // Contar separadores

		for (int i = 0; i < descricaoPersonagem.length(); i++) {
			if (descricaoPersonagem.charAt(i) == ':') {
				contadorDoisPontos++;

				switch (contadorDoisPontos) {
					case 1:
						personagem.setNome(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 2:
						String atributoInteiro = leituraAtributo(descricaoPersonagem, i + 3);
						if (atributoInteiro.equals("unknown")) {
							personagem.setAltura(0);
						} else {
							personagem.setAltura(Integer.parseInt(atributoInteiro));
						}
						break;
					case 3:
						String atributoDouble = leituraAtributo(descricaoPersonagem, i + 3).replaceAll(",", ".");
						if (atributoDouble.equals("unknown")) {
							personagem.setPeso(0);
						} else {
							personagem.setPeso(Double.parseDouble(atributoDouble));
						}
						break;
					case 4:
						personagem.setCorDoCabelo(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 5:
						personagem.setCorDaPele(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 6:
						personagem.setCorDosOlhos(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 7:
						personagem.setAnoNascimento(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 8:
						personagem.setGenero(leituraAtributo(descricaoPersonagem, i + 3));
						break;
					case 9:
						personagem.setHomeworld(leituraAtributo(descricaoPersonagem, i + 3));
						i = descricaoPersonagem.length(); // Encerra os ciclos de repetição desnecessários
						break;
					default:
						break;
				}
			}
		}

		leitura.close();

		return personagem;
	}

	// Retornar valor do atributo do personagem
	public static String leituraAtributo(String descricaoPersonagem, int index) {
		String atributo = new String();

		while (descricaoPersonagem.charAt(index) != '\'') {
			atributo += descricaoPersonagem.charAt(index);

			index++;
		}

		return atributo;
	}
}