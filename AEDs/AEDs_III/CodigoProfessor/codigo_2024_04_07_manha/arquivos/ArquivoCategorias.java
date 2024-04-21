package arquivos;

import java.util.ArrayList;
import java.util.Collections;

import aeds3.Arquivo;
import entidades.Categoria;

public class ArquivoCategorias extends Arquivo<Categoria> {

  public ArquivoCategorias() throws Exception {
    super("categorias", Categoria.class.getConstructor());
  }

  public Categoria[] readAll() throws Exception {
    arquivo.seek(TAM_CABECALHO);
    byte lapide;
    short tam;
    byte[] b;

    Categoria c;
    ArrayList<Categoria> categorias = new ArrayList<>();
    while (arquivo.getFilePointer() < arquivo.length()) {
      lapide = arquivo.readByte();
      tam = arquivo.readShort();
      b = new byte[tam];
      arquivo.read(b);
      if (lapide != '*') {
        c = new Categoria(); // Cria uma nova instância a cada categoria
        c.fromByteArray(b);
        categorias.add(c);
      }
    }
    Collections.sort(categorias);
    Categoria[] lista = (Categoria[]) categorias.toArray(new Categoria[0]);
    return lista;
  }

}
