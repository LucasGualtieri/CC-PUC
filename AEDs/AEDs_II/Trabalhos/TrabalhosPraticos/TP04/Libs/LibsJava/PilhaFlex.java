package TP03.Libs.LibsJava;

import TP03.Libs.LibsJava.Lib.Jogador;
import TP03.Libs.LibsJava.Celulas.CelulaPilha;

public class PilhaFlex {
	private int size;
	private CelulaPilha topo;

	public PilhaFlex() {
		topo = null;
		size = 0;
	}

	public int getSize() { return this.size; }

	public void Mostrar() throws Exception {
		if (this.topo == null) {
			throw new Exception("Erro ao mostrar: Pilha vazia.");
		}

		MostrarRec(size - 1, topo);
	}

	private void MostrarRec(int contador, CelulaPilha i) {
		if (i.baixo != null) MostrarRec(contador - 1, i.baixo);
		System.out.printf("[%d] ## ", contador);
		i.jogador.Mostrar();
	}

	// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

	public void Inserir(Jogador jogador) {
		topo = new CelulaPilha(jogador, topo);
		this.size++;
	}

	public Jogador Remover() throws Exception {

		if (this.topo == null) {
			throw new Exception("Erro ao remover: Pilha Flex vazia.");
		}

		CelulaPilha removido = topo;
		topo = topo.baixo;

		this.size--;

		return removido.jogador;

	}

}
