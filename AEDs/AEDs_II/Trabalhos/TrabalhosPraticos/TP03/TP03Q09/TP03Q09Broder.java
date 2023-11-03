import java.util.Scanner;

public class Q09 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); //numero de casos de teste

        // Entrada
        Matriz[] matrizes = new Matriz[n * 2];
        for(int i = 0; i < n * 2; i++){
            matrizes[i] = Matriz.lerMatriz(sc);
        }
        
        //Saída
        for(int i = 0; i < n * 2; i += 2){
            matrizes[i].mostrarDiagonalPrincipal();
            System.out.println();
            matrizes[i].mostrarDiagonalSecundaria();

            Matriz matrizSoma = matrizes[i].soma(matrizes[i + 1]);
            System.out.println();
            matrizSoma.imprimirMatriz();

            Matriz matrizMult = matrizes[i].multiplicacao(matrizes[i + 1]);
            matrizMult.imprimirMatriz();
        }
    }
}

// -------- CelulaMatriz MATRIZ --------
class CelulaMatriz {

    protected CelulaMatriz clone() {
        CelulaMatriz clone = new CelulaMatriz();
        clone.elemento = this.elemento;
        clone.sup = this.sup;
        clone.dir = this.dir;
        clone.inf = this.inf;
        clone.esq = this.esq;
        return clone;
    }

    public int elemento;
    public CelulaMatriz sup;
    public CelulaMatriz dir;
    public CelulaMatriz inf;
    public CelulaMatriz esq;

    public CelulaMatriz(int x) {
        this.elemento = x;
        this.sup = this.dir = this.inf = this.esq = null;
    }

    public CelulaMatriz() {
        this(0);
    }

}

// ----------- MATRIZ ---------

class Matriz {

    public CelulaMatriz inicio;
    public int linha, coluna;

    public Matriz() {
        this(3, 3);
    }

    public Matriz(int linha, int coluna) {
        this.linha = linha;
        this.coluna = coluna;
        alocacaoDeCelulas();
    }

    public void alocacaoDeCelulas() {
        inicio = new CelulaMatriz();
        CelulaMatriz temp = inicio;
        for (int i = 1; i < coluna; i++) {
            temp.dir = new CelulaMatriz();
            temp.dir.esq = temp;
            temp = temp.dir;
        }

        CelulaMatriz tmp = inicio;
        for (int l = 1; l < linha; l++, tmp = tmp.inf) {
            CelulaMatriz i = tmp;
            i.inf = new CelulaMatriz();
            i.inf.sup = i;
            CelulaMatriz j = i.inf;
            for (int c = 1; c < coluna; c++, j = j.dir) {
                i = i.dir;
                i.inf = new CelulaMatriz();
                i.inf.sup = i;
                i.inf.esq = j;
                j.dir = i.inf;
            }
        }
    }

    public void setElemento(int l, int c, int x) {
        CelulaMatriz atual = inicio;
        int i, j;
        for (i = 0; i < c; i++) {
            atual = atual.dir;
        }
        for (j = 0; j < l; j++) {
            atual = atual.inf;
        }
        atual.elemento = x;
    }

    public int getElemento(int l, int c) {
        CelulaMatriz atual = inicio;
        int i, j;
        for (i = 0; i < c; i++) {
            atual = atual.dir;
        }
        for (j = 0; j < l; j++) {
            atual = atual.inf;
        }
        return atual.elemento;
    }

    public Matriz soma(Matriz m) {
        Matriz resultado = null;

        if (this.linha == m.linha && this.coluna == m.coluna) {
            resultado = new Matriz(this.linha, this.coluna);
            for (int i = 0; i < linha; i++) {
                for (int j = 0; j < coluna; j++) {
                    int elemento = this.getElemento(i, j) + m.getElemento(i, j);
                    resultado.setElemento(i, j, elemento);
                }
            }
        }

        return resultado;
    }

    public Matriz multiplicacao(Matriz m) {
        Matriz resultado = null;
        if (this.coluna == m.linha) {
            resultado = new Matriz(this.linha, m.coluna);

            for (int i = 0; i < this.linha; i++) {
                for (int j = 0; j < m.coluna; j++) {
                    int soma = 0;
                    for (int k = 0; k < this.coluna; k++) {
                        soma += this.getElemento(i, k) * m.getElemento(k, j);
                    }
                    resultado.setElemento(i, j, soma);
                }
            }
        }
        return resultado;

    }

    public void mostrarDiagonalPrincipal() {
        for (int i = 0; i < this.linha; i++) {
            System.out.print(getElemento(i, i) + " ");
        }
    }

    public void mostrarDiagonalSecundaria() {
        for (int i = 0; i < this.linha; i++) {
            System.out.print(getElemento(i, this.coluna - 1 - i) + " ");
        }
    }

    public void imprimirMatriz() {
        for (int i = 0; i < this.linha; i++) {
            for (int j = 0; j < this.coluna; j++) {
                System.out.print(getElemento(i, j) + " ");
            }
            System.out.println();
        }
    }

    public static Matriz lerMatriz(Scanner sc) {

        int linhas = sc.nextInt();
        int colunas = sc.nextInt();
        Matriz m = new Matriz(linhas, colunas);

        sc.nextLine();
        for(int i = 0; i < linhas; i++){
            String entrada = sc.nextLine();
            String[] valores = entrada.split(" ");
            for(int j = 0; j < colunas; j++){
                m.setElemento(i, j, Integer.parseInt(valores[j]));
            }
        }

        return m;
    }

}