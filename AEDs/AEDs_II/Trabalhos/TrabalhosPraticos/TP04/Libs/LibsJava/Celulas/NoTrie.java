package TP04.Libs.LibsJava.Celulas;

// import TP04.Libs.LibsJava.Lib.Jogador;

public class NoTrie {

    public NoTrie[] filhos;
    public boolean ehPalavra;

    public NoTrie() {
        this.filhos = new NoTrie[95];
        this.ehPalavra = false;
    }
}
