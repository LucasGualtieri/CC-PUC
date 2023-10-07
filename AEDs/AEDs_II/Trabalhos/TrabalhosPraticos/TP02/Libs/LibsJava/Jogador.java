package TP02.Libs.LibsJava;

public class Jogador {
	private int id, altura, peso, anoNascimento;
	private String nome, universidade, cidadeNascimento, estadoNascimento;

	public Jogador() {}

	public Jogador(String[] array) {
		this.setId(array[0]);
		this.setNome(array[1]);
		this.setAltura(array[2]);
		this.setPeso(array[3]);
		this.setUniversidade(array[4]);
		this.setAnoNascimento(array[5]);
		this.setCidadeNascimento(array[6]);
		this.setEstadoNascimento(array[7]);
	}

	// Getter e Setter - Id
	public int getId() { return this.id; }
	public void setId(String id) { this.id = Integer.parseInt(id); }
	public void setId(int id) { this.id = id; }
	
	// Getter e Setter - Nome
	public String getNome() { return this.nome; }
	public void setNome(String nome) { this.nome = nome; }

	// Getter e Setter - Altura
	public int getAltura() { return this.altura; }
	public void setAltura(int altura) { this.altura = altura; }
	public void setAltura(String altura) {
		if (altura.equals("nao informado")) {
			this.altura = -1;
			return;
		}
		this.altura = Integer.parseInt(altura);
	}

	// Getter e Setter - Peso
	public int getPeso() { return this.peso; }
	public void setPeso(int peso) { this.peso = peso; }
	public void setPeso(String peso) {
		if (peso.equals("nao informado")) {
			this.peso = -1;
			return;
		}
		this.peso = Integer.parseInt(peso);
	}

	// Getter e Setter - AnoNascimento
	public int getAnoNascimento() { return this.anoNascimento; }
	public void setAnoNascimento(int anoNascimento) { this.anoNascimento = anoNascimento; }
	public void setAnoNascimento(String anoNascimento) {
		if (anoNascimento.equals("nao informado")) {
			this.anoNascimento = -1;
			return;
		}
		this.anoNascimento = Integer.parseInt(anoNascimento);
	}

	// Getter e Setter - Universidade
	public String getUniversidade() { return this.universidade; }
	public void setUniversidade(String universidade) {
		this.universidade = universidade;
	}

	// Getter e Setter - CidadeNascimento
	public String getCidadeNascimento() { return this.cidadeNascimento; }
	public void setCidadeNascimento(String cidadeNascimento) {
		this.cidadeNascimento = cidadeNascimento;
	}

	// Getter e Setter - EstadoNascimento
	public String getEstadoNascimento() { return this.estadoNascimento; }
	public void setEstadoNascimento(String estadoNascimento) {
		this.estadoNascimento = estadoNascimento;
	}

	public Jogador Clone() {
		Jogador clone = new Jogador();

		clone.setId(this.getId());
		clone.setNome(this.getNome());
		clone.setAltura(this.getAltura());
		clone.setPeso(this.getPeso());
		clone.setUniversidade(this.getUniversidade());
		clone.setAnoNascimento(this.getAnoNascimento());
		clone.setCidadeNascimento(this.getCidadeNascimento());
		clone.setEstadoNascimento(this.getEstadoNascimento());

		return clone;

	}

	public void Mostrar() {
		System.out.printf("[%d ## ", this.getId());
		System.out.printf("%s ## ", this.getNome());
		System.out.printf("%d ## ", this.getAltura());
		System.out.printf("%d ## ", this.getPeso());
		System.out.printf("%d ## ", this.getAnoNascimento());
		System.out.printf("%s ## ", this.getUniversidade());
		System.out.printf("%s ## ", this.getCidadeNascimento());
		System.out.printf("%s]\n", this.getEstadoNascimento());
	}

}