
import java.io.File;
import java.util.Scanner;

import arquivos.ArquivoAutores;
import arquivos.ArquivoCategorias;
import arquivos.ArquivoLivros;
import entidades.Autor;
import entidades.Categoria;
import entidades.Livro;

public class Principal {

  private static Scanner console = new Scanner(System.in);

  public static void main(String[] args) {

    try {

      int opcao;
      do {
        System.out.println("\n\n\nBOOKAEDS 1.0");
        System.out.println("------------");
        System.out.println("\n> Início");
        System.out.println("\n1) Categorias");
        System.out.println("2) Autores");
        System.out.println("3) Livros");
        System.out.println("\n9) Reiniciar BD");
        System.out.println("\n0) Sair");

        System.out.print("\nOpção: ");
        try {
          opcao = Integer.valueOf(console.nextLine());
        } catch (NumberFormatException e) {
          opcao = -1;
        }

        switch (opcao) {
          case 1:
            (new MenuCategorias()).menu();
            break;
          case 2:
            (new MenuAutores()).menu();
            break;
          case 3:
            (new MenuLivros()).menu();
            break;
          case 9:
            preencherDados();
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
  }

  public static void preencherDados() {
    try {
      new File("dados/categorias.db").delete();
      new File("dados/categorias.hash_d.db").delete();
      new File("dados/categorias.hash_c.db").delete();
      new File("dados/autores.db").delete();
      new File("dados/autores.hash_d.db").delete();
      new File("dados/autores.hash_c.db").delete();
      new File("dados/livros.db").delete();
      new File("dados/livros.hash_d.db").delete();
      new File("dados/livros.hash_c.db").delete();
      new File("dados/livros_isbn.hash_d.db").delete();
      new File("dados/livros_isbn.hash_c.db").delete();
      new File("dados/livros_categorias.btree.db").delete();

      ArquivoLivros arqLivros = new ArquivoLivros();
      ArquivoCategorias arqCategorias = new ArquivoCategorias();
      ArquivoAutores arqAutores = new ArquivoAutores();

      arqCategorias.create(new Categoria("Romance"));
      arqCategorias.create(new Categoria("Educação"));
      arqCategorias.create(new Categoria("Sociologia"));
      arqCategorias.create(new Categoria("Policial"));
      arqCategorias.create(new Categoria("Aventura"));
      arqCategorias.create(new Categoria("Suspense"));

      arqAutores.create(new Autor("Homero"));
      arqAutores.create(new Autor("Lilian Bacich"));
      arqAutores.create(new Autor("Adolfo Tanzi Neto"));
      arqAutores.create(new Autor("Zygmunt Bauman"));
      arqAutores.create(new Autor("Plínio Dentzien"));
      arqAutores.create(new Autor("Ivan Izquierdo"));
      arqAutores.create(new Autor("Mariana Zapata"));

      arqLivros.create(new Livro("9788563560278", "Odisseia", 15.99F, 1));
      arqLivros.create(new Livro("9788584290483", "Ensino Híbrido", 39.90F, 2));
      arqLivros.create(new Livro("9786559790005", "Modernidade Líquida", 48.1F, 3));
      arqLivros.create(new Livro("9788582714911", "Memória", 55.58F, 1));
      arqLivros.create(new Livro("9786587150062", "Com Amor", 48.9F, 1));

      arqLivros.close();
      arqCategorias.close();
      arqAutores.close();

      System.out.println("Banco de dados reinicializado com dados de exemplo.");

    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
