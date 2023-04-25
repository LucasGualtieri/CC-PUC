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

	// Contar o maior peso no vetor de personagens
	public int getMaiorPeso() {
		double maiorPeso = listaPersonagens[0].getPeso();

		for (int i = 1; i < contadorTamanho; i++) {
			if (listaPersonagens[i].getPeso() > maiorPeso) {
				maiorPeso = listaPersonagens[i].getPeso();
			}

			numeroComparacoes += 2;
		}

		return ((int) maiorPeso);
	}

	// Ordenar o vetor por Counting Sort
	public void ordenaPorCountingSort() {
		// Array para contar o numero de ocorrencias de cada elemento
		int[] count = new int[getMaiorPeso() + 1];
		Personagem[] ordenado = new Personagem[contadorTamanho];

		// Inicializar cada posição do array de contagem
		for (int i = 0; i < count.length; count[i] = 0, i++) {
			numeroComparacoes++;
		}

		// Agora, o count[i] contém o número de elemento iguais a i
		for (int i = 0; i < contadorTamanho; count[(int) listaPersonagens[i].getPeso()]++, i++) {
			numeroComparacoes++;
		}

		// Agora, o count[i] contém o número de elemento menores ou iguais a i
		for (int i = 1; i < count.length; count[i] += count[i - 1], i++) {
			numeroComparacoes++;
		}

		// Ordenando
		for (int i = contadorTamanho - 1; i >= 0; ordenado[count[(int) listaPersonagens[i].getPeso()]
				- 1] = listaPersonagens[i], count[(int) listaPersonagens[i].getPeso()]--, i--) {
			numeroComparacoes++;
		}

		// Atribuir ao vetor original o vetor ordenado
		for (int i = 0; i < contadorTamanho; i++) {
			listaPersonagens[i] = ordenado[i];
		}
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
}

public class TP02Q15 {
	public static void main(String[] args) throws Exception {
		MyIO.setCharset("ISO-8859-1");

		Lista listaPersonagens = new Lista();

		String caminhoArquivo = MyIO.readLine().replaceAll("é", "\u00e9");

		// Testar fim da do arquivo
		while (testaFim(caminhoArquivo) == false) {

			// Montar personagem e adicionar ao fim da lista
			listaPersonagens.inserir(montaPersonagem(caminhoArquivo));

			caminhoArquivo = MyIO.readLine().replaceAll("é", "\u00e9");
		}

		listaPersonagens.ordenaPorCountingSort(); // Ordenar por Seleção

		listaPersonagens.imprimeResultados(); // Imprimir os resultados

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