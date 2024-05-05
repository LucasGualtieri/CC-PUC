package CodigoProfessor;

import java.util.Scanner;

import CodigoProfessor.aeds3.ListaInvertida;

import java.io.File;

public class TesteListaInvertida {

  // Método principal apenas para testes
  public static void main(String[] args) {

    ListaInvertida lista;
    Scanner console = new Scanner(System.in);

    try {
      File d = new File("dados");
      if (!d.exists())
        d.mkdir();
      lista = new ListaInvertida(4, "dados/dicionario.listainv.db", "dados/blocos.listainv.db");

      int opcao;
      do {
        System.out.println("\n\n-------------------------------");
        System.out.println("              MENU");
        System.out.println("-------------------------------");
        System.out.println("1 - Inserir");
        System.out.println("2 - Buscar");
        System.out.println("3 - Excluir");
        System.out.println("4 - Imprimir");
        System.out.println("0 - Sair");
        try {
          opcao = Integer.valueOf(console.nextLine());
        } catch (NumberFormatException e) {
          opcao = -1;
        }

        switch (opcao) {
          case 1: {

			// Inserção

            System.out.println("\nINCLUSÃO");
            System.out.print("Chave: ");
            String chave = console.nextLine();
            System.out.print("Dado: ");
            int dado = Integer.valueOf(console.nextLine());
            lista.create(chave, dado);
            lista.print();
          }
            break;
          case 2: {
            System.out.println("\nBUSCA");
            System.out.print("Chave: ");
            String chave = console.nextLine();
            int[] dados = lista.read(chave);
            System.out.print("Dado: ");
            for (int i = 0; i < dados.length; i++)
              System.out.print(dados[i] + " ");
          }
            break;
          case 3: {
            System.out.println("\nEXCLUSÃO");
            System.out.print("Chave: ");
            String chave = console.nextLine();
            System.out.print("Dado: ");
            int dado = Integer.valueOf(console.nextLine());
            lista.delete(chave, dado);
            lista.print();
          }
            break;
          case 4: {
            lista.print();
          }
            break;
          case 0:
            break;
          default:
            System.out.println("Opção inválida");
        }
      } while (opcao != 0);

    } catch (Exception e) {
      e.printStackTrace();
    }
    console.close();
  }
}