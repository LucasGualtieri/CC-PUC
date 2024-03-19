package TP00;
// package AEDs.AEDs_III.TP;

import java.io.IOException;
import java.lang.reflect.Constructor;

class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	public ArquivoLivro(Constructor<T> construtor) {
		super(construtor);
	}

	public T readISBN(int isbn) throws IOException, Exception {
		
		T objReturn = null;

		arq.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = arq.length();
		short tamanhoRegistro;

		while(arq.getFilePointer() < len) {

			tamanhoRegistro = arq.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				arq.read(registro);
				
				T obj = Instanciador(registro);
				
				// if (obj.getID() == id) {
				// 	objReturn = obj;
				// 	arq.seek(len);
				// }
			}

			else {
				arq.skipBytes(Math.abs(tamanhoRegistro));
			}
		}

		return objReturn;
	}
}