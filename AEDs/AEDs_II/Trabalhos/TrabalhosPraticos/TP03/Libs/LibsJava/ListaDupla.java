package TP03.Libs.LibsJava;

import TP03.Libs.LibsJava.Lib.Log;
import TP03.Libs.LibsJava.Lib.Jogador;
import TP03.Libs.LibsJava.Celulas.CelulaDupla;

public class ListaDupla {

	private int size;
	private CelulaDupla primeiro, ultimo;

	public ListaDupla() {
		primeiro = ultimo = new CelulaDupla();
		size = 0;
	}

	public CelulaDupla getPrimeiro() { return primeiro.dir; }
	public CelulaDupla getUltimo() { return ultimo; }

	public int getSize() { return this.size; }

	public void Mostrar() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao mostrar: Lista vazia.");
		}

		for (CelulaDupla i = this.primeiro.dir; i != null; i = i.dir) {
			i.jogador.MostrarQuickSort();
		}

	}

	// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

	public void swap(CelulaDupla var1, CelulaDupla var2, Log log) {
		Jogador aux = var1.jogador;
		var1.jogador = var2.jogador;
		var2.jogador = aux;
		log.incrementarMovimentacoes(3);
	}

	public int strcmp(String jog1, String jog2) {
		return jog1.compareTo(jog2);
	}

	public int CompareTo(CelulaDupla var1, CelulaDupla pivot, Log log) {

		log.incrementarComparacoes();
		
		Jogador jog1 = var1.jogador, pivotJog = pivot.jogador;
		
		int strComp = strcmp(jog1.getEstadoNascimento(), pivotJog.getEstadoNascimento());
	
		if (strComp == 0) {
			log.incrementarComparacoes();
			strComp = strcmp(jog1.getNome(), pivotJog.getNome());
		}
	
		return strComp;
	}

	public void InserirFim(Jogador jogador) {

		ultimo = ultimo.dir = new CelulaDupla(jogador, ultimo, null);
		this.size++;

	}
	
}
