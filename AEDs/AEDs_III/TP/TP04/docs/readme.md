# ✍️ TP04 - AEDs III

## 📝 Descrição
<ol>
	<li>Nesta quarta iteração do projeto algumas funcionalidades adicionais foram implementadas:
		<ol>
			<li>Métodos de cifragem por Viegenere e por Colunas foram criados.</li>
			<li>Uma nova classe chamada <strong>StreamManager</strong> foi criada para abstrair o uso das classes ByteArrayOutputStream, DataOutputStream e DataInputStream.</li>
		</ol>
</ol>

## 🔍 Experiência do Grupo
 - Todos os requisitos foram implementados de forma tranquila e rápida, sem grandes problemas. Todos os resultados esperados foram alcançados.

## ⚙️ Descrição dos métodos implementados

```java
/**
 * Classe que representa um sistema de cifra utilizando diferentes estratégias de criptografia.
 */
public class Cipher {

	/** Array de estratégias de criptografia utilizadas pela classe */
	CipherStrategy[] strategies;

	/** Chave padrão utilizada para cifragem */
	public static final byte[] KEY = "AEDsIII".getBytes();

	/**
	 * Construtor que aceita uma ou mais estratégias de criptografia.
	 * 
	 * @param strategies Estratégias de criptografia a serem utilizadas.
	 */
	public Cipher(CipherStrategy... strategies) { this.strategies = strategies; }

	/**
	 * Construtor padrão que inicializa com as estratégias Viegenere e Colunas.
	 */
	public Cipher() {

		strategies = new CipherStrategy[2];
		strategies[0] = new Viegenere();
		strategies[1] = new Colunas();
	}

	/**
	 * Método para cifrar os dados utilizando a(s) estratégia(s) definida(s).
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = Arrays.copyOf(data, data.length);

		for (CipherStrategy strategy : strategies) {
			cipheredData = strategy.cipher(key, cipheredData);
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a(s) estratégia(s) definida(s).
	 * 
	 * @param key          Chave utilizada para decifrar os dados.
	 * @param cipheredData Dados cifrados a serem decifrados.
	 * @return Dados decifrados.
	 */
	public byte[] decipher(byte[] key, byte[] cipheredData) {

		byte[] decipheredData = Arrays.copyOf(cipheredData, cipheredData.length);

		for (int i = strategies.length - 1; i >= 0; i--) {
			decipheredData = strategies[i].decipher(key, decipheredData);
		}

		return decipheredData;
	}
}
```

```java
/**
 * Classe que implementa a estratégia de criptografia de Viegenere.
 */
public class Viegenere implements CipherStrategy {

	/**
	 * Método para cifrar os dados utilizando a cifra de Viegenere.
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	@Override
	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = new byte[data.length];

		for (int i = 0; i < data.length; i++) {
			cipheredData[i] = (byte)(data[i] + key[i % key.length]);
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a cifra de Viegenere.
	 * 
	 * @param key  Chave utilizada para decifrar os dados.
	 * @param data Dados a serem decifrados.
	 * @return Dados decifrados.
	 */
	@Override
	public byte[] decipher(byte[] key, byte[] data) {

		byte[] decipheredData = new byte[data.length];

		for (int i = 0; i < data.length; i++) {
			decipheredData[i] = (byte)(data[i] - key[i % key.length]);
		}

		return decipheredData;
	}
}

```

```java
/**
 * Classe que implementa a estratégia de criptografia por transposição de colunas.
 */
public class Colunas implements CipherStrategy {

	/**
	 * Método para cifrar os dados utilizando a transposição de colunas.
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	@Override
	public byte[] cipher(byte[] key, byte[] data) {

		int width = key.length;
		int height = (int)Math.ceil((float)data.length / width);

		char[][] matrix = new char[height][width];
		int counter = 0;

		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {

				if (counter < data.length) {
					matrix[i][j] = (char)data[counter++];
				}
				
				else matrix[i][j] = 256;  // Valor que representa espaço vazio na matriz.
			}
		}

		byte[] cipheredData = new byte[data.length];
		counter = 0;

		for (int j = 0; j < key.length; j++) {
			for (int i = 0; i < height; i++) {
				if (matrix[i][j] != 256) {
					cipheredData[counter++] = (byte)matrix[i][j];
				}
			}
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a transposição de colunas.
	 * 
	 * @param key  Chave utilizada para decifrar os dados.
	 * @param data Dados cifrados a serem decifrados.
	 * @return Dados decifrados.
	 */
	@Override
	public byte[] decipher(byte[] key, byte[] data) {

		int width = key.length;
		int height = (int)Math.ceil((float)data.length / width);

		char[][] matrix = new char[height][width];
		int counter = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (counter++ >= data.length) {
					matrix[i][j] = 256;  // Valor que representa espaço vazio na matriz.
				}
			}
		}

		counter = 0;

		for (int j = 0; j < key.length; j++) {
			for (int i = 0; i < height; i++) {
				if (counter >= data.length || matrix[i][j] == 256) {
					break;
				}
				matrix[i][j] = (char)data[counter++];
			}
		}

		byte[] decipheredData = new byte[data.length];
		counter = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (matrix[i][j] == 256) break;
				decipheredData[counter++] = (byte)matrix[i][j];
			}
		}

		return decipheredData;
	}
}

```

## Exemplo do uso dos métodos de cifragem no toByteArray() e fromByteArray().
```java
	public byte[] toByteArray() throws Exception {

		StreamManager sm = new StreamManager();

		sm.write(this.ID);
		sm.writeUTF(this.ISBN);
		sm.writeUTF(this.titulo);
		sm.writeUTF(this.autor);
		sm.write(this.preco);

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	public void fromByteArray(byte[] ba) {

		Cipher c = new Cipher();
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, ba));

		try {
			this.ID = sm.readInt();
			this.ISBN = sm.readUTF();
			this.titulo = sm.readUTF();
			this.autor = sm.readUTF();
			this.preco = sm.readFloat();
		}

		catch (IOException e) { e.printStackTrace(); }
	}
```

## ✅ Checklist

- [X] Há uma função de cifragem em todas as classes de entidades, envolvendo pelo menos duas operações diferentes e usando uma chave criptográfica?
- [X] Uma das operações de cifragem é baseada na substituição e a outra na transposição?
- [X] O trabalho está funcionando corretamente?
- [X] O trabalho está completo?
- [X] O trabalho é original e não a cópia de um trabalho de um colega?

## 📝 Integrantes
 - Lucas Gualtieri
 - Gabriel Quaresma de Oliveira
 - Júlio César Gonzaga Ferreira Silva
 - Suzane Lemos de Lima
