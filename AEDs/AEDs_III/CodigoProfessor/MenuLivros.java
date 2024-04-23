// -------------------------------------------------------
// A classe MenuLivro é responsável pela interação com
// o usuário. É a partir dela, que o usuário inclui, 
// altera, exclui e consulta as entidades cadastradas
// no banco de dados.
// 
// Adicionalmente, a classe MenuLivro oferece um método
// LeLivro() e outro MostraLivro() que cuidam da entrada
// e da saída de dados de livros e das classes relacionadas.
// -------------------------------------------------------

import java.text.NumberFormat;
import java.util.Scanner;

import arquivos.ArquivoCategorias;
import arquivos.ArquivoLivros;
import entidades.Categoria;
import entidades.Livro;

public class MenuLivros {

  private static Scanner console = new Scanner(System.in);
  private ArquivoLivros arqLivros;
  private ArquivoCategorias arqCategorias;

  public MenuLivros() {
    try {
      arqLivros = new ArquivoLivros();
      arqCategorias = new ArquivoCategorias();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  // ---------------------
  // LE_LIVRO
  // ---------------------
  public Livro leLivro() throws Exception {

    // Lê os campos iniciais
    System.out.print("\nISBN: ");
    String isbn = console.nextLine();
    System.out.print("Título: ");
    String titulo = console.nextLine();
    System.out.print("Preço: R$ ");
    float preco;
    String sPreco = console.nextLine();
    if (sPreco.length() > 0)
      preco = Float.parseFloat(sPreco);
    else
      preco = -1F;

    // Lista as categorias
    Categoria[] categorias = arqCategorias.readAll();
    int i;
    System.out.println("Categorias");
    for (i = 0; i < categorias.length; i++) {
      System.out.println((i + 1) + ": " + categorias[i].getNome());
    }

    // Lê a categoria
    System.out.print("Categoria: ");
    int c, categoria;
    String sCategoria = console.nextLine();
    if (sCategoria.length() > 0) {
      c = Integer.parseInt(sCategoria);
      if (c > 0 && c <= categorias.length)
        categoria = categorias[c - 1].getID();
      else
        categoria = -1;
    } else
      categoria = -1;

    // Cria e retorna o livro
    System.out.println();
    Livro l = new Livro(isbn, titulo, preco, categoria);
    return l;
  }

  // ---------------------
  // MOSTRA_LIVRO
  // ---------------------
  public void mostraLivro(Livro l) throws Exception {
    Categoria c = arqCategorias.read(l.getIdCategoria());
    String nomeCategoria = c == null ? "Categoria inválida" : c.getNome();
    System.out.println(
        "\nISBN: " + l.getIsbn() +
            "\nTítulo: " + l.getTitulo() +
            "\nPreço: " + NumberFormat.getCurrencyInstance().format(l.getPreco()) +
            "\nCategoria: " + nomeCategoria);
  }

  // ---------------------
  // MENU_LIVROS
  // ---------------------
  public void menu() {

    // Mostra o menu
    int opcao;
    do {
      System.out.println("\n\n\nBOOKAEDS 1.0");
      System.out.println("------------");
      System.out.println("\n> Início > Livros");
      System.out.println("\n1) Inclui livro");
      System.out.println("2) Busca livro");
      System.out.println("3) Altera livro");
      System.out.println("4) Exclui livro");
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
          incluirLivro();
          break;
        case 2:
          buscarLivro();
          break;
        case 3:
          alterarLivro();
          break;
        case 4:
          excluirLivro();
          break;
        case 0:
          break;
        default:
          System.out.println("Opção inválida");
      }
    } while (opcao != 0);

    // Fecha os arquivos
    try {
      arqLivros.close();
      arqCategorias.close();
    } catch (Exception e) {
      e.printStackTrace();
    }

  }

  // ---------------------
  // INCLUIR_LIVRO
  // ---------------------
  public void incluirLivro() {

    // Lê um novo livro, testando se todos os campos foram preenchidos
    Livro novoLivro;
    try {
      boolean dadosCompletos = false;
      do {
        novoLivro = leLivro();
        if (novoLivro.getIsbn().length() == 0 || novoLivro.getTitulo().length() == 0
            || novoLivro.getPreco() < 0
            || novoLivro.getIdCategoria() < 0)
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
      // Testa se já existe um livro com esse ISBN
      if (arqLivros.readISBN(novoLivro.getIsbn()) != null) {
        System.out.println("Já existe um livro com esse ISBN.");
        return;
      }

      // Insere o novo livro no banco de dados
      System.out.print("Confirma inclusão do livro (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        arqLivros.create(novoLivro);
      }
    } catch (Exception e) {
      System.out.println("Livro não pode ser criado");
      e.printStackTrace();
      return;
    }

    System.out.println("\nLivro armazenado!");

  }

  // ---------------------
  // BUSCAR LIVRO
  // ---------------------
  public void buscarLivro() {
    String isbn;
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Livros > Busca");
    System.out.print("\nISBN: ");
    isbn = console.nextLine();
    if (isbn.length() == 0)
      return;

    try {
      Livro l = arqLivros.readISBN(isbn);
      if (l == null) {
        System.out.println("Livro não encontrado.");
        return;
      }
      mostraLivro(l);
    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

  // ---------------------
  // ALTERAR_LIVRO
  // ---------------------
  public void alterarLivro() {
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Livros > Alteração");
    System.out.print("\nISBN: ");
    String isbn = console.nextLine();
    if (isbn.length() == 0)
      return;

    try {
      Livro livro = arqLivros.readISBN(isbn);
      if (livro == null) {
        System.out.println("Livro não encontrado.");
        return;
      }
      mostraLivro(livro);

      System.out.println("\nDigite os novos dados.\nDeixe em branco os que não desejar alterar.");
      Livro livro2;
      try {
        livro2 = leLivro();
      } catch (Exception e) {
        System.out.println("Dados inválidos");
        return;
      }
      if (livro2.getIsbn().length() > 0)
        livro.setIsbn(livro2.getIsbn());
      if (livro2.getTitulo().length() > 0)
        livro.setTitulo(livro2.getTitulo());
      if (livro2.getPreco() > 0)
        livro.setPreco(livro2.getPreco());
      if (livro2.getIdCategoria() > 0)
        livro.setIdCategoria(livro2.getIdCategoria());

      System.out.print("Confirma alteração do livro (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        if (arqLivros.update(livro))
          System.out.println("Livro alterado!");
        else
          System.out.println("Erro na alteração do livro!");
      } else
        System.out.println("Alteração cancelada!");
    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

  // ---------------------
  // EXCLUIR_LIVRO
  // ---------------------
  public void excluirLivro() {
    System.out.println("\n\n\nBOOKAEDS 1.0");
    System.out.println("------------");
    System.out.println("\n> Início > Livros > Exclusão");
    System.out.print("\nISBN: ");
    String isbn = console.nextLine();
    if (isbn.length() == 0)
      return;

    try {
      Livro livro = arqLivros.readISBN(isbn);
      if (livro == null) {
        System.out.println("Livro não encontrado.");
        return;
      }
      mostraLivro(livro);

      System.out.print("Confirma exclusão do livro (S/N)? ");
      char resp = console.nextLine().charAt(0);
      if (resp == 'S' || resp == 's') {
        if (arqLivros.delete(livro.getID()))
          System.out.println("Livro excluído!");
        else
          System.out.println("Erro na exclusão do livro!");
      } else
        System.out.println("Exclusão cancelada!");
    } catch (Exception e) {
      System.out.println("Erro no acesso ao arquivo");
      e.printStackTrace();
    }
  }

}
