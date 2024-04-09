package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Celulas.CelulaMatriz;

public class MatrizFlex {
	private int nLinhas, nColunas;
	private CelulaMatriz inicio;

	public MatrizFlex(int nLinhas, int nColunas) {
		
		this.nLinhas = nLinhas;
		this.nColunas = nColunas;

		this.AlocarCelulas();

	}

	public int getNLinhas() { return this.nLinhas; }
	public int getNColunas() { return this.nColunas; }
	public CelulaMatriz getInicio() { return inicio; }

	private void AlocarCelulas() {
	
		CelulaMatriz auxEsq, auxCima = null, tmp;

		this.inicio = tmp = auxEsq = auxCima = new CelulaMatriz(null, null);

		for (int i = 0; i < this.nColunas - 1; i++) {
			tmp = tmp.dir = new CelulaMatriz(tmp, null);
		}

		for (int i = 0; i < this.nLinhas - 1; i++) {
			auxCima.baixo = tmp = auxEsq = auxEsq.baixo = new CelulaMatriz(null, auxCima);
			for (int j = 0; j < this.nColunas - 1; j++) {
				auxCima = auxCima.dir;
				auxCima.baixo = tmp = tmp.dir = new CelulaMatriz(tmp, auxCima);
			}
			auxCima = auxEsq;
		}

	}

	// private void AlocarCelulas() {
	
	// 	CelulaMatriz auxEsq, auxCima = null, tmp;

	// 	this.inicio = tmp = auxEsq = new CelulaMatriz(null, auxCima);

	// 	for (int i = 0; i < this.nLinhas; i++) {
	// 		if (i != 0) tmp = auxEsq = auxEsq.baixo = new CelulaMatriz(null, auxCima);
	// 		for (int j = 0; j < this.nColunas - 1; j++) {
	// 			if (i != 0) auxCima.baixo = tmp;
	// 			tmp = tmp.dir = new CelulaMatriz(tmp, auxCima);
	// 			if (i != 0) auxCima = auxCima.dir;	
	// 		}
	// 		if (i != 0) auxCima.baixo = tmp;
	// 		auxCima = auxEsq;
	// 	}

	// }

	public void PreencherDoTeclado() {

		CelulaMatriz left = this.inicio;

		while (left != null) {
			CelulaMatriz i = left;
			while (i != null) {
				i.valor = Lib.readInt(false);
				i = i.dir;
			}
			i = left = left.baixo;
		}

	}

	public void MostrarDiagonalPrincipal() {

		CelulaMatriz i = this.inicio;

		while (i != null) {
			System.out.printf("%d ", i.valor);
			i = i.baixo;
			if (i != null) i = i.dir;
		}

		System.out.println();

	}

	public void MostrarDiagonalSecundaria() {
		CelulaMatriz i = this.inicio;

		while (i.dir != null) i = i.dir;

		while (i != null) {
			System.out.printf("%d ", i.valor);
			i = i.baixo;
			if (i != null) i = i.esq;
		}
		System.out.println();
	}

	public void Mostrar() {
		CelulaMatriz left = this.inicio;
		while (left != null) {
			CelulaMatriz i = left;
			while (i != null) {
				System.out.printf("%d ", i.valor);
				i = i.dir;
			}
			System.out.println();
			i = left = left.baixo;
		}
	}

}