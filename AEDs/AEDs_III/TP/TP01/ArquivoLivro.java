package TP01;

import java.io.IOException;
import java.lang.reflect.Constructor;

public class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	HashExtensivel<ParTituloID> indiceIndireto;

	public ArquivoLivro(Constructor<T> construtor, String nome, String filePath) throws NoSuchMethodException, SecurityException, Exception {
		super(construtor, nome, filePath);

		indiceIndireto = new HashExtensivel<>(
			ParTituloID.getConstructor(),
			3,
			"dados/" + nome + ".hashIndireta_d.db",
			"dados/" + nome + ".hashIndireta_c.db"
		);
	}

	public T readISBN(int isbn) throws IOException, Exception {
		
		T objReturn = null;

		file.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = file.length();
		short tamanhoRegistro;

		while(file.getFilePointer() < len) {

			tamanhoRegistro = file.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				file.read(registro);
				
				T obj = Instanciador(registro);
				
				// if (obj.getID() == id) {
				// 	objReturn = obj;
				// 	file.seek(len);
				// }
			}

			else {
				file.skipBytes(Math.abs(tamanhoRegistro));
			}
		}

		return objReturn;
	}
}