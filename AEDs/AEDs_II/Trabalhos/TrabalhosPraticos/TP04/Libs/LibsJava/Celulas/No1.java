package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Celulas;

public class No1 {

	public int alturaMod15;
	public No1 esq, dir;
	public No2 raiz;

	public No1(int altura) { 
		this.alturaMod15 = altura;
		this.raiz = null;
		this.esq = this.dir = null;
	}
}
