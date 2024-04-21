package arquivos;

import java.util.ArrayList;
import java.util.Collections;

import aeds3.Arquivo;
import entidades.Autor;

public class ArquivoAutores extends Arquivo<Autor> {

  public ArquivoAutores() throws Exception {
    super("autores", Autor.class.getConstructor());
  }

  public Autor[] readAll() throws Exception {
    arquivo.seek(TAM_CABECALHO);
    byte lapide;
    short tam;
    byte[] b;

    Autor c;
    ArrayList<Autor> autores = new ArrayList<>();
    while (arquivo.getFilePointer() < arquivo.length()) {
      lapide = arquivo.readByte();
      tam = arquivo.readShort();
      b = new byte[tam];
      arquivo.read(b);
      if (lapide != '*') {
        c = new Autor(); // Cria uma nova instância a cada autor
        c.fromByteArray(b);
        autores.add(c);
      }
    }
    Collections.sort(autores);
    Autor[] lista = (Autor[]) autores.toArray(new Autor[0]);
    return lista;
  }
}
