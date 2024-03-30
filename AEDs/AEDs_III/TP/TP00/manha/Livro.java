import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.text.NumberFormat;

import aeds3.Registro;

public class Livro implements Registro {

  private int ID;
  private String isbn;
  private String titulo;
  private float preco;

  public Livro() {
    this(-1, "", "", 0F);
  }

  public Livro(String i, String t, float p) {
    this(-1, i, t, p);
  }

  public Livro(int id, String i, String t, float p) {
    this.ID = id;
    this.isbn = i;
    this.titulo = t;
    this.preco = p;
  }

  public int getID() {
    return this.ID;
  }

  public void setID(int i) {
    this.ID = i;
  }

  public void setIsbn(String isbn) {
    this.isbn = isbn;
  }

  public String getIsbn() {
    return isbn;
  }

  public void setTitulo(String titulo) {
    this.titulo = titulo;
  }

  public String getTitulo() {
    return titulo;
  }

  public byte[] toByteArray() throws Exception {
    ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
    DataOutputStream dos = new DataOutputStream(ba_out);
    dos.writeInt(this.ID);
    dos.writeUTF(this.isbn);
    dos.writeUTF(this.titulo);
    dos.writeFloat(this.preco);
    return ba_out.toByteArray();
  }

  public void fromByteArray(byte[] ba) throws Exception {
    ByteArrayInputStream ba_in = new ByteArrayInputStream(ba);
    DataInputStream dis = new DataInputStream(ba_in);
    this.ID = dis.readInt();
    this.isbn = dis.readUTF();
    this.titulo = dis.readUTF();
    this.preco = dis.readFloat();
  }

  public String toString() {
    return "ID: " + this.ID +
        "\nISBN: " + this.isbn +
        "\nTítulo: " + this.titulo +
        "\nPreço: " + NumberFormat.getCurrencyInstance().format(this.preco);
  }

  public int compareTo(Object b) {
    return this.getID() - ((Livro) b).getID();
  }

  @Override
  public Object clone() throws CloneNotSupportedException {
    return super.clone();
  }

}
