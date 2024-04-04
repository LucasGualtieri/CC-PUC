package TP01.Livros;

// import java.io.IOException;
import java.lang.reflect.Constructor;

import TP01.Arquivo;
import TP01.Registro;

public class ArquivoLivro<T extends Registro> extends Arquivo<T> {

	// HashExtensivel<ParTituloID> indiceIndireto;

	/*
	 * ID + Titulo + Autor + Preco respectivamente
	 * Foi feito uma estimativa do comprimento médio dos:
	 * Títulos e Nomes de autores de livros ao redor do mundo
	 * Fonte: Microsoft Copilot
	*/
	// private final short registerAvgLength = 12; // 4 + (2 + 14) + (2 + 12) + 4.

	@SuppressWarnings("unchecked")
	public ArquivoLivro(String nome, String filePath) throws NoSuchMethodException, SecurityException, Exception {
		
		super((Constructor<T>)Livro.getConstructor(), nome, filePath);

		// indiceIndireto = new HashExtensivel<>(
		// 	ParTituloID.getConstructor(),
		// 	3,
		// 	filePath + nome + ".hashIndireta_d.db",
		// 	filePath + nome + ".hashIndireta_c.db"
		// );
	}

	// Para poder testar fazer um metodo que liste os excluidos.

	// private long getMelhorExcluido(short newLength) throws Exception, IOException {

	// 	file.seek(4); // Ir para a posição que marca a posição do Menor Registro Excluído.

	// 	long address = file.readLong(), fileLength = file.length();
	// 	long ultimoEndereco = address;
		
	// 	// -1 indica que a lista de Registros excluídos está vazia.
	// 	file.seek(address == -1 ? file.length() : address); // Ir para a posição do Menor Registro Excluído.

	// 	// Inserindo o primeiro Registro excluído na lista.
	// 	if (file.getFilePointer() == fileLength) {
	// 		// System.out.println("OLA MUNDOOO!!!");
	// 		// file.seek(address);
	// 		file.writeShort(newLength - 2); // -2 para desconsiderar o indicador de tamanho
	// 		address += 2;
	// 	}


	// 	while((address = file.getFilePointer()) < fileLength) {
			
	// 		short length = (short)(file.readShort() + 2); // Tamanho total do registro.
			
	// 		if (length < 0 && newLength <= Math.abs(length)) {
	// 			length = (short)Math.abs(length); // Tamanho total do registro.
	// 			/* Uma vez que encontramos o espaço para o novo registro
	// 			 * precisamos decidir se o quebramos em dois registros menores.
	// 			*/
	// 			short difference = (short)(length - newLength);

	// 			if (difference >= registerAvgLength) {
	// 				// file.seek(address);
	// 				file.writeShort(newLength - 2); // -2 pra desconsiderar o indicador de tamanho
	// 				file.skipBytes(newLength); // Posicionar o ponteiro no começo do segundo registro.
	// 				delete(difference); // Incluir a segunda metade do registro na lista de Registros excluídos.
	// 			}

	// 			else {
	// 				file.seek(address); // Voltar para desmarcar a lápide.
	// 				file.writeShort(length - 2); // -2 para desconsiderar o indicador de tamanho
	// 				long nextAddress = file.readLong();
	// 				file.seek(ultimoEndereco + 2);
	// 				file.writeLong(nextAddress);
	// 				address += 2;
	// 			}

	// 			// fileLength = 0; // Para encerrar o while.
	// 			break; // Tive que usar o break pq se não atualizaria de novo para uma pos errada
	// 		}

	// 		else {
	// 			if (length < 0) ultimoEndereco = address;
	// 			long nextAddress = file.readLong();
	// 			file.seek(nextAddress); // Pula para o próximo registro excluído.
	// 		}
	// 	}

	// 	// if (address == fileLength) {
	// 	// 	file.seek(address);
	// 	// 	file.writeShort(newLength - 2); // -2 para desconsiderar o indicador de tamanho
	// 	// 	address += 2;
	// 	// }

	// 	return address;
	// }

	// Remover cabeça quando terminar de reaproveitar todos
	// public int create(T object) throws Exception {

	// 	file.seek(0);
	// 	int ID = file.readInt() + 1; // Recuperar o último ID
	// 	object.setID(ID); // Settar o ID do objeto
		
	// 	// Voltar para o começo para atualizar o último ID.
	// 	file.seek(0);
	// 	file.writeInt(ID);
		
	// 	byte[] registro = object.toByteArray();
	// 	short length = (short)registro.length; 

	// 	long address = getMelhorExcluido((short)(length + 2)); // Tamanho + indicador de tamanho

	// 	file.seek(address); // Vai pra melhor posição para criar o registro

	// 	// file.writeShort(length);
	// 	file.write(registro);

	// 	indiceDireto.create(new ParIDEndereco(ID, address - 2));

	// 	return ID;
	// }

	// public void delete(int ID) throws Exception {

	// 	long address = indiceDireto.read(ID).getEndereco();

	// 	file.seek(address); // Ir para a posição do registro para pegar seu tamanho.
	// 	short tamanhoRegistro = file.readShort(); // Tamanho total do registro.
	// 	file.seek(address); // Voltar para o começo do registro.

	// 	delete((short)(tamanhoRegistro + 2)); // Foi necessário garantir que era short para que a sobrecarga de método funcionasse, certamente será melhor arrumar outro nome pra esse método

	// 	indiceDireto.delete(ID);
	// }

	// Talvez um nome melhor? AtualizarListaExcluidos?
	// Inserção ordenada na lista de registros excluidos
	// private void delete(short newLength) throws Exception {
		
	// 	// Tenho que fazer a posição do menor excluido ser -1 quando a lista vazia
	// 	// e fazer as alterações necessarias no código.
		
	// 	long pos = file.getFilePointer(); // Salva a posição do registro a ser excluído.
		
	// 	file.seek(4); // Ir para a posição que marca a posição do Menor Registro Excluído.
	// 	long posAnterior = file.getFilePointer(); // Incialmente a posição anterior é a própria "Célula cabeça".
	// 	long address = file.readLong(), fileLength = file.length(); // Leio a posição desse Primeiro registro.

	// 	// file.seek(address); // Ir para a posição do Menor Registro Excluído.
	// 	// -1 indica que a lista de Registros excluídos está vazia.
	// 	file.seek(address == -1 ? file.length() : address); // Ir para a posição do Menor Registro Excluído. Ou fazer o "InserirNaCabeça()"

	// 	while((address = file.getFilePointer()) < fileLength) {
	// 		short length = (short)(Math.abs(file.readShort()) + 2); // Tamanho total do registro.
			
	// 		if (newLength < length) {
	// 			// Vou para o anterior depois do indicador de tamanho;
	// 			file.seek(posAnterior);
	// 			// Pulo o indicador de tamanho, pois esse é o cabeçalho
	// 			if (file.getFilePointer() != 4) file.skipBytes(2);
	// 			file.writeLong(pos); // Inserir o novo registro.

	// 			// fileLength = 0;
	// 			break;
	// 		}

	// 		else {
	// 			long nextAddress = file.readLong();

	// 			if (nextAddress == -1) {
	// 				// inserir fim
	// 				file.writeLong(pos); // Escrevo a posição do novo.
	// 				address = -1;
	// 				break;
	// 			}

	// 			else {
	// 				file.seek(nextAddress); // Pula para o próximo registro excluído.
	// 				posAnterior = address; // Salvando a posição antes de avançar.
	// 			}
	// 		}
	// 	}

	// 	if (address == fileLength) { // Isso está errado, pois eu não necessariamente quero atualizar a cabeça quando a condição bate
	// 		file.seek(4);
	// 		file.writeLong(pos);
	// 		address = -1;
	// 	}

	// 	file.seek(pos); // Vou para a posição do meu novo regsitro excluido e dps do indicador de tamhbo
	// 	file.writeShort(-(newLength - 2)); // Escrevo o número negativo, pois está marcado como lápide. -2 pois o tamanho estava considerando o indicador de tamanho
	// 	file.writeLong(address == -1 ? -1 : address); // Aponto o meu novo exluido para o proximo;
	// }

	// public T readISBN(int isbn) throws IOException, Exception {
		
	// 	T objReturn = null;

	// 	file.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
	// 	long len = file.length();
	// 	short tamanhoRegistro;

	// 	while(file.getFilePointer() < len) {

	// 		tamanhoRegistro = file.readShort();
			
	// 		if (tamanhoRegistro > 0) {
				
	// 			byte[] registro = new byte[tamanhoRegistro];
	// 			file.read(registro);
				
	// 			T object = Instanciador(registro);
				
	// 			// if (object.getID() == id) {
	// 			// 	objReturn = object;
	// 			// 	file.seek(len);
	// 			// }
	// 		}

	// 		else {
	// 			file.skipBytes(Math.abs(tamanhoRegistro));
	// 		}
	// 	}

	// 	return objReturn;
	// }
}