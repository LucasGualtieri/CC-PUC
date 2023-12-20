package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Celulas.NoAN;

public class Alvinegra {

   private NoAN raiz;

    public Alvinegra() { raiz = null; }

	public NoAN getRaiz() { return this.raiz; }

	public static int CompareToStr(String chave, NoAN raiz, Log log) {
		log.incrementarComparacoes();
		return chave.compareTo(raiz.jogador.getNome());
	}

	public static int CompareToNome(Jogador jogador, NoAN raiz) {
		return jogador.getNome().compareTo(raiz.jogador.getNome());
	}

	public static int CompareToNome(NoAN no1, NoAN no2) {
		return no1.jogador.getNome().compareTo(no2.jogador.getNome());
	}

	private Filhos Balancear(NoAN raiz, Filhos filhos) {

		NoAN filho = filhos.getFilho();
		NoAN neto = filhos.getNeto();

		if (neto != null && neto.cor && filho.cor) {
			if (CompareToNome(raiz, filho) < 0 && CompareToNome(filho, neto) < 0) {
				// System.out.println("RotacaoSimplesEsq");
				filhos.setFilho(RotacaoSimplesEsq(raiz));
			} else if (CompareToNome(raiz, filho) < 0 && CompareToNome(filho, neto) > 0) {
				// System.out.println("RotacaoDuplaDirEsq");
				filhos.setFilho(RotacaoDuplaDirEsq(raiz));
			} else if (CompareToNome(raiz, filho) > 0 && CompareToNome(filho, neto) > 0) {
				// System.out.println("RotacaoSimplesDir");
				filhos.setFilho(RotacaoSimplesDir(raiz));
			} else {
				// System.out.println("RotacaoDuplaEsqDir");
				filhos.setFilho(RotacaoDuplaEsqDir(raiz));
			}
		} else {
			filhos.setFilho(raiz);
			filhos.setNeto(filho);
		}

		return filhos;
	}

	private NoAN RotacaoSimplesEsq(NoAN avo) {

		NoAN aux = avo.dir;
		avo.dir = aux.esq;
		aux.esq = avo;

		avo.cor = true;
		aux.cor = false;

		return aux;
	}

	private NoAN RotacaoSimplesDir(NoAN avo) {

		NoAN aux = avo.esq;
		avo.esq = aux.dir;
		aux.dir = avo;

		avo.cor = true;
		aux.cor = false;

		return aux;
	}

	private NoAN RotacaoDuplaDirEsq(NoAN avo) {
		avo.dir = RotacaoSimplesDir(avo.dir);
		return RotacaoSimplesEsq(avo);
	}

	private NoAN RotacaoDuplaEsqDir(NoAN raiz) {
		raiz.esq = RotacaoSimplesEsq(raiz.esq);
		return RotacaoSimplesDir(raiz);
	}

	public void Inserir(Jogador jogador) throws Exception {
		this.raiz = Inserir(jogador, this.raiz).getFilho();
		if (this.raiz.cor) this.raiz.cor = false;
	}

	private Filhos Inserir(Jogador jogador, NoAN raiz) throws Exception {

		Filhos filhos;

		if (Is4No(raiz)) Fragmentar(raiz); // Por algum motivo gera um result.txt diferente do esperado quando a fragmentação acontece na volta.

		if (raiz == null) {
			raiz = new NoAN(jogador, true);
			filhos = new Filhos(null, null);
		} else if (CompareToNome(jogador, raiz) < 0) {
			filhos = Inserir(jogador, raiz.esq);
			raiz.esq = filhos.getFilho();
		} else if (CompareToNome(jogador, raiz) > 0) {
			filhos = Inserir(jogador, raiz.dir);
			raiz.dir = filhos.getFilho();
		} else {
			String nome = jogador.getNome();
			String erro = "Erro ao inserir na Árvore: Valor " + nome + " repetido.";
			throw new Exception(erro);
		}

		return Balancear(raiz, filhos);
	}

	private boolean Is4No(NoAN raiz) {

		boolean resultado = false;

		if (raiz != null && raiz.esq != null && raiz.dir != null) {
			if (raiz.esq.cor && raiz.dir.cor) {
				resultado = true;
			}
		}

		return resultado;
	}

	void Fragmentar(NoAN i) {
		i.cor = !(i.dir.cor = i.esq.cor = false);
	}

	public void Mostrar() {
		Mostrar(this.raiz);
	}
	
	private void Mostrar(NoAN raiz) {
		if (raiz != null) {
			Mostrar(raiz.esq);
			System.out.println(raiz.jogador.getNome());
			Mostrar(raiz.dir);
		}
	}
	
	public void MostrarPre() {
		MostrarPre(this.raiz);
	}

	private void MostrarPre(NoAN raiz) {
		if (raiz != null) {
			System.out.println(raiz.jogador.getNome());
			MostrarPre(raiz.esq);
			MostrarPre(raiz.dir);
		}
	}
}

class Filhos {

	private NoAN filho, neto;

	public Filhos() {
		this(null, null);
	}

	public Filhos(NoAN filho, NoAN neto) {
		this.filho = filho;
		this.neto = neto;
	}

	public void setFilho(NoAN filho) { this.filho = filho; }
	public NoAN getFilho() { return this.filho; }
	
	public void setNeto(NoAN neto) { this.neto = neto; }
	public NoAN getNeto() { return this.neto; }
}
