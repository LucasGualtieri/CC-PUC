package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Celulas;

public class CelulaMatriz {
	public int valor;
	public CelulaMatriz esq, dir, cima, baixo;

	public CelulaMatriz() {
		valor = 0;
		esq = dir = cima = baixo = null;
	}

	public CelulaMatriz(CelulaMatriz esq, CelulaMatriz cima) {
		this.esq = esq;
		this.cima = cima;
	}

	public CelulaMatriz(int valor, CelulaMatriz esq, CelulaMatriz cima) {
		this.valor = valor;
		this.esq = esq;
		this.cima = cima;
	}
}
