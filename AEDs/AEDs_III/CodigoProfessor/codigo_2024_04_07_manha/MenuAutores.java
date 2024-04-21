// -------------------------------------------------------
// A classe MenuAutores é responsável pela interação com
// o usuário. É a partir dela, que o usuário inclui, 
// altera, exclui e consulta as entidades cadastradas
// no banco de dados.
// 
// Adicionalmente, a classe MenuAutores oferece um método
// LeAutor() e outro MostraAutor() que cuidam da entrada
// e da saída de dados de autores e das classes relacionadas.
// -------------------------------------------------------

import java.util.Scanner;

import arquivos.ArquivoAutores;
import entidades.Autor;

public class MenuAutores {

  private static Scanner console = new Scanner(System.in);
  private ArquivoAutores arqAutores;

  public MenuAutores() {
    try {
      arqAutores = new ArquivoAutores();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  // ---------------------
  // LE_AUTOR
  // ---------------------
  public Autor leAutor() throws Exception {

    // Lê os campos iniciais
    System.out.print("\nNome: ");
    String nome = console.nextLine();

    // Cria e retorna o autor
    System.out.println();
    Autor c = new Autor(nome);
    return c;
  }

  // ---------------------
  // MOSTRA_AUTOR
  // ---------------------
  public void mostraAutor(Autor a) throws Exception {
    System.out.println("\nNome: " + a.getNome());
  }

  // ---------------------
  // MENU_AUTORES
  // ---------------------
  public void menu() {

    // Mostra o menu
    int opcao;
    do {
      System.out.println("\n\n\nBOOKAEDS 1.0");
      System.out.println("------------");
      System.out.println("\n> Início > Autores");
      System.out.println("\n1) Inclui autor");
      System.out.println("2) Busca autor");
      System.out.println("3) Altera autor");
      System.out.println("4) Exclui autor");
      System.out.println("\n0) Retornar ao menu anterior");

      System.out.print("\nOpção: ");
      try {
        opcao = Integer.valueOf(console.nextLine());
      } catch (NumberFormatException e) {
        opcao = -1;
      }

      // Seleciona a operação
      switch (opcao) {
        case 1:
          incluirAutor();
          break;
        case 2:
          buscarAutor();
          break;
        case 3:
          alterarAutor();
          break;
        case 4:
          excluirAutor();
          break;
        case 0:
          break;
        default:
          System.out.println("Opção inválida");
      }
    } while (opcao != 0);

    // Fecha os arquivos
    try {
      arqAutores.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  // ---------------------
  // INCLUIR_AUTOR
  // ---------------------
  public void incluirAutor() {

    // Lê um nov autor, testando se todos os campos foram preenchidos
    Autor novoAutor;
    try {
      boolean dadosCompletos = false;
      do {
        novoAutor = leAutor();
        if (novoAutor.getNome().length() == 0)
          System.out.println("Dados incompletos. Preencha todos os campos.");
        else
          dadosCompletos = true;
      } while (!dadosCompletos);
    } catch (Exception e) {
      System.out.println("Dados inválidos");
      e.printStackTrace();
      return;
    }

    try {
      // Insere o novo autor no banco de dados
      System.out.print("Confirma inclusão do autor (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        arqAutores.create(novoAutor);
      }
    } catch (Exception e) {
      System.out.println("Autor não pode ser criado.");
      e.printStackTrace();
      return;
    }

    System.out.println("\nAutor armazenado!");

  }

  // ---------------------
  // BUSCAR AUTOR
  // ---------------------
  public void buscarAutor() {
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Autores > Busca");

    try {
      // Lista as autores
      Autor[] autores = arqAutores.readAll();
      int i;
      System.out.println("\nAutores\n-------");
      for (i = 0; i < autores.length; i++) {
        System.out.println((i + 1) + ": " + autores[i].getNome());
      }

      // Lê a autor
      System.out.print("\nAutor a exibir: ");
      int a;
      Autor autor;
      String sAutor = console.nextLine();
      if (sAutor.length() > 0) {
        a = Integer.parseInt(sAutor);
        if (a > 0 && a <= autores.length) {
          autor = autores[a - 1];
        } else {
          System.out.println("Autor inválido!");
          return;
        }
      } else
        return;
      mostraAutor(autor);

    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

  // ---------------------
  // ALTERAR_AUTOR
  // ---------------------
  public void alterarAutor() {
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Autores > Alteração");

    try {
      // Lista as autores
      Autor[] autores = arqAutores.readAll();
      int i;
      System.out.println("\nAutores\n-------");
      for (i = 0; i < autores.length; i++) {
        System.out.println((i + 1) + ": " + autores[i].getNome());
      }

      // Lê a autor
      System.out.print("\nAutor a alterar: ");
      int c;
      Autor autor;
      String sAutor = console.nextLine();
      if (sAutor.length() > 0) {
        c = Integer.parseInt(sAutor);
        if (c > 0 && c <= autores.length) {
          autor = autores[c - 1];
        } else {
          System.out.println("Autor inválido!");
          return;
        }
      } else
        return;
      mostraAutor(autor);

      System.out.println("\nDigite os novos dados.\nDeixe em branco os que não desejar alterar.");
      Autor autor2;
      try {
        autor2 = leAutor();
      } catch (Exception e) {
        System.out.println("Dados inválidos");
        return;
      }
      if (autor2.getNome().length() > 0)
        autor.setNome(autor2.getNome());

      System.out.print("Confirma alteração do autor (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        if (arqAutores.update(autor))
          System.out.println("Autor alterado!");
        else
          System.out.println("Erro na alteração do autor!");
      } else
        System.out.println("Alteração cancelada!");
    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

  // ---------------------
  // EXCLUIR_AUTOR
  // ---------------------
  public void excluirAutor() {
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Autores > Exclusão");

    try {
      // Lista as autores
      Autor[] autores = arqAutores.readAll();
      int i;
      System.out.println("\nAutores\n-------");
      for (i = 0; i < autores.length; i++) {
        System.out.println((i + 1) + ": " + autores[i].getNome());
      }

      // Lê a autor
      System.out.print("\nAutor a excluir: ");
      int c;
      Autor autor;
      String sAutor = console.nextLine();
      if (sAutor.length() > 0) {
        c = Integer.parseInt(sAutor);
        if (c > 0 && c <= autores.length) {
          autor = autores[c - 1];
        } else {
          System.out.println("Autor inválido!");
          return;
        }
      } else
        return;
      mostraAutor(autor);

      System.out.print("Confirma exclusão da autor (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        if (arqAutores.delete(autor.getID()))
          System.out.println("Autor excluído!");
        else
          System.out.println("Erro na exclusão do autor!");
      } else
        System.out.println("Exclusão cancelada!");
    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

}
