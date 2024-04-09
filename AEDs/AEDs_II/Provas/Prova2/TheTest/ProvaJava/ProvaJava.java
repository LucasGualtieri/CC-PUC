package AEDs.AEDs_II.Provas.Prova2.TheTest.ProvaJava;

import java.util.*;

class ProvaJava {

    static class Processo {
        public int tempo, nDeCiclos;
    }

    static class Fila {
        public Processo[] array;
        public int maxSize, size;

        public Fila(int maxSize) {
            this.size = 0;
            this.maxSize = maxSize;
            this.array = new Processo[maxSize];
        }

        void Inserir(Processo processo) {

            if (this.size == this.maxSize) {
                System.out.println("Erro ao inserir: Fila cheia.");
                return;
            }

            this.array[this.size] = processo;
            this.size++;

        }

        void Remover() {
            if (this.size == 0) {
                System.out.println("Erro ao remover: Fila vazia.");
                return;
            }

            for (int i = 0; i < this.size - 1; i++) {
                this.array[i] = this.array[i + 1];
            }

            this.size--;
        }

    }

    static Scanner scanner = new Scanner(System.in);

    static Processo LerProcesso() {

        Processo processo = new Processo();

        processo.tempo = scanner.nextInt();
        processo.nDeCiclos = scanner.nextInt();

        return processo;
    }

    static void OrdenarPorTempo(Fila fila) {
        int N = fila.size;
        Processo[] array = fila.array;
    
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int menor = i;
                if (array[menor].tempo < array[j].tempo ) {
                    menor = j;
                }
                Processo aux = array[i];
                array[i] = array[menor];
                array[menor] = aux;
            }
        }
    }

    static int SomaDosProcessos(Fila fila) {

        int soma = 0;

        for (int i = 0; i < fila.size; i++) {
            soma += fila.array[i].tempo;
        }

        return soma;

    }

    static void ExecutarProcesso(Fila fila) {

    }

    public static void main(String[] args) {

        Fila fila = new Fila(500);
        
        
        while (scanner.hasNextLine()) {

            int soma = 0;
            int numeroDeProcessos = scanner.nextInt();

            for (int i = 0; i < numeroDeProcessos; i++) {

                Processo processo = LerProcesso();

                fila.Inserir(processo);

                ExecutarProcesso(fila);

                soma += SomaDosProcessos(fila);

                OrdenarPorTempo(fila);

            }

            System.out.println(soma);

        }


    }
}