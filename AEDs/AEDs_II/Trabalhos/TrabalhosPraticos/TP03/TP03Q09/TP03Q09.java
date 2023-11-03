package TP03.TP03Q09;

import TP03.Libs.LibsJava.Lib;
import TP03.Libs.LibsJava.MatrizFlex.CelulaMatriz;
import TP03.Libs.LibsJava.MatrizFlex.MatrizFlex;

// clear && javac -cp ../.. TP03Q09.java && java -cp ../.. TP03Q09.java < pub.in > result.txt

class TP03Q09 {

	public static MatrizFlex SomarMatrizes(MatrizFlex matriz1, MatrizFlex matriz2) {
		int nLinhas = matriz1.getNLinhas(), nColunas = matriz1.getNColunas();
		MatrizFlex matrizResultante = new MatrizFlex(nLinhas, nColunas);

		CelulaMatriz resultante, resultanteEsq = matrizResultante.getInicio();
		CelulaMatriz i, iEsq = matriz1.getInicio();
		CelulaMatriz j, jEsq = matriz2.getInicio();

		while (resultanteEsq != null) {
			resultante = resultanteEsq;
			i = iEsq;
			j = jEsq;
			while (resultante != null) {
				resultante.valor = i.valor + j.valor;
				resultante = resultante.dir;
				i = i.dir;
				j = j.dir;
			}
			resultante = resultanteEsq = resultanteEsq.baixo;
			i = iEsq = iEsq.baixo;
			j = jEsq = jEsq.baixo;
		}

		return matrizResultante;

	}

	public static MatrizFlex MultiplicarMatrizes(MatrizFlex matriz1, MatrizFlex matriz2) {
		int nLinhas = matriz1.getNLinhas(), nColunas = matriz1.getNColunas();
		MatrizFlex matrizResultante = new MatrizFlex(nLinhas, nColunas);

		CelulaMatriz resultante, resultanteEsq = matrizResultante.getInicio();
		CelulaMatriz i, iAux = matriz1.getInicio();
		CelulaMatriz j, jAux = matriz2.getInicio();

		while (resultanteEsq != null) {
			resultante = resultanteEsq;
			i = iAux;
			j = jAux;
			while (resultante != null) {
				for (int k = 0; k < nColunas; k++) {
					resultante.valor += i.valor * j.valor;
					i = i.dir;
					j = j.baixo;
				}
				resultante = resultante.dir;
				i = iAux;
				j = jAux.dir;
			}
			resultante = resultanteEsq = resultanteEsq.baixo;
			iAux = iAux.baixo;
		}

		return matrizResultante;

	}

	public static void main(String[] args) throws Exception {

		MatrizFlex matriz1, matriz2, matrizResultante;

		int numeroDeCasos = Lib.readInt();
		
		for (int i = 0; i < numeroDeCasos; i++) {

			matriz1 = new MatrizFlex(Lib.readInt(), Lib.readInt());
			matriz1.PreencherDoTeclado();

			matriz2 = new MatrizFlex(Lib.readInt(), Lib.readInt());
			matriz2.PreencherDoTeclado();

			matriz1.MostrarDiagonalPrincipal();
			matriz1.MostrarDiagonalSecundaria();

			matrizResultante = SomarMatrizes(matriz1, matriz2);
			matrizResultante.Mostrar();

			matrizResultante = MultiplicarMatrizes(matriz1, matriz2);
			matrizResultante.Mostrar();

		}
	}
}