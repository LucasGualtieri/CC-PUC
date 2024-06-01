# ✍️ TP03 - AEDs III

## 📝 Descrição
<ol>
	<li>Nesta terceira iteração do projeto algumas funcionalidades adicionais foram implementadas:
		<ol>
			<li>O usuário agora pode fazer um backup compactado dos dados das entidades "Livros" e "Autores".</li>
			<li>Adicionalmente, o usuário pode escolher entre os backups disponíveis e descompactá-los.</li>
		</ol>
</ol>

## 🔍 Experiência do Grupo
- Todos os requisitos foram implementados, apesar de termos enfrentado dificuldades em alguns momentos com o algoritmo de compressão LZW. Como nosso objetivo era modificar o código mostrado em sala para que usasse um HashMap e, assim, melhorar a performance, tivemos também que descobrir como corrigir o erro do código original. .Todos os resultados esperados foram alcançados.

Não conseguimos implementar a compressão em fluxo, ou seja, de pequenos chunks de dados em pequenos chunks de dados

## ⚙️ Descrição dos métodos implementados

```java
// Esta é uma versão simplificada do código real (por questões de simplicidade) do novo método CRUD.
// ...
static <T extends Registro> void Backup(Arquivo<T> arquivo) throws Exception  {

	Path folderPath = Paths.get(path + arquivo.getNomePlural() + "/Dados");

	LZW compress = new LZW(arquivo.getNomePlural(), path + "../Backups/", true);

	DirectoryStream<Path> stream = Files.newDirectoryStream(folderPath);

	for (Path filePath : stream) {
		String fileName = filePath.getFileName().toString();
		byte[] fileBytes = Files.readAllBytes(filePath);
		compress.add(fileName, fileBytes);
	}

	compress.close();
}
```

```java
// Este método é reponsável por retornar uma lista de Strings que então
// serão usadas nos processos de inclusão e exclusão da classe ListaInvertida
public void add(String fileName, byte[] fileBytes) throws Exception {

	byte[] compressedFile = comprimir(fileBytes);

	Tuple<Integer, Integer> tamanhos = new Tuple<>(fileBytes.length, compressedFile.length);
	taxasDeCompressao.add(new Tuple<>(fileName, tamanhos));

	totalBytes += fileBytes.length;
	totalComprimido += compressedFile.length;

	this.N++;

	file.writeUTF(fileName);
	file.writeInt(compressedFile.length);
	file.writeByte(BITS_POR_INDICE);
	file.write(compressedFile);
}
```

```java

// Este método é responsável por:
// - Ler o título digitado pelo usuário.
// - 'Limpar' e 'Tokenizar' a String lida.
// - Fazer a interseção entre os conjuntos retornados pelas N palavras chave da pesquisa.
// - Fazer M (sendo M o número de ID do conjunto final) pesquisas no índice direto para montar uma LinkedList de Livros.
static <T extends Registro> void RecoverBackup(Arquivo<T> arquivo) throws Exception  {

	Path folderPath = Paths.get(path + "../Backups/");

	List<Path> files = new LinkedList<>();

	DirectoryStream<Path> stream = Files.newDirectoryStream(folderPath)
	for (Path file : stream) {
		String str = file.getFileName().toString().substring(0, arquivo.getNomePlural().length());
		if (Files.isRegularFile(file) && str.equals(arquivo.getNomePlural())) files.add(file);
	}

	System.out.println("Backups encontrados:\n");

	int i = 0;
	for (Path file : files) {
		String fileName = file.getFileName().toString();
		System.out.printf("%d - %s\n", ++i, fileName);
	}

	System.out.print("\nEscolha uma das opções acima: ");

	int escolha = Lib.ReadChoice(i);

	Path backup = files.get(escolha - 1);

	LZW decompress = new LZW(arquivo.getNomePlural(), path + "../Backups/", false);
	decompress.recover(backup);
}
```

```java
// A descrição desse código está incompleta...
public void recover(Path path) throws Exception {
	String folderName = path.getFileName().toString().substring(0, path.getFileName().toString().length() - 3);
	File folder = new File(filePath + "../Backups/" + folderName);
	folder.mkdir();

	AbrirArquivoDescomprimir(path);

	this.N = file.readInt();

	for (int i = 0 ; i < N; i++) {

		String fileName = file.readUTF();

		System.out.println("file: " + filePath + folderName + "/" + fileName);

		RandomAccessFile backup = new RandomAccessFile(filePath + folderName + "/" + fileName, "rw");

		int fileSize = file.readInt();
		BITS_POR_INDICE = file.readByte();

		byte[] compressedBytes = new byte[fileSize];

		file.read(compressedBytes);

		backup.write(descomprimir(compressedBytes));
		backup.close();
	}
}
```

#### Breve demonstração das novas funcionalidades.
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/26121f22-9b2d-473e-998a-f5c77d792af3)
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/1788f147-6022-4387-89c5-31e907aabe82)
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/ed9aef49-b4bd-49a3-8803-a9c4ef5432ca)
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/6fac2f29-7a72-408f-ba84-42a41dea6520)
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/eaa48837-3a50-49f5-8772-f8b395e790fb)
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/788e2901-62cc-41c5-a09b-e1e4453b9252)

## ✅ Checklist

1. **Modificação das funções CRUD:**
	- [X] Há uma rotina de compactação usando o algoritmo LZW para fazer backup dos arquivos?
	- [X] Há uma rotina de descompactação usando o algoritmo LZW para recuperação dos arquivos?
	- [X] O usuário pode escolher a versão a recuperar?

3. **Qual foi a taxa de compressão alcançada por esse backup?**
	- A taxa de compressão alcançada com a compressão LZW, usando *BITS_POR_INDICE* variável, foi em média de 40%.

6. **Funcionamento e Originalidade:**
	- [X] O trabalho está funcionando corretamente.
	- [X] O trabalho está completo.
	- [X] O trabalho é original e não uma cópia de um colega.

## 📝 Integrantes
 - Lucas Gualtieri
 - Gabriel Quaresma de Oliveira
 - Júlio César Gonzaga Ferreira Silva
 - Suzane Lemos de Lima
