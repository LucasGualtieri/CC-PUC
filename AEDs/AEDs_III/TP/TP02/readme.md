# ✍️ TP02 - AEDs III

## 📝 Descrição
<ol>
	<li>Nesta segunda iteração do projeto algumas funcionalidades adicionais foram implementadas:
		<ol>
			<li>Um indice indireto de ISBN para a classe livro.</li>
			<li>Um indice indireto de CPF para a classe autor.</li>
			<li>Um novo método que permite que o usuário pesquise por um livro a partir de seu título</li>
		</ol>
</ol>

## 🔍 Experiência do Grupo
- Todos os requisitos foram implementados de forma tranquila e rápida, sem grandes problemas. Todos os resultados esperados foram alcançados.

## ⚙️ Descrição dos métodos implementados

```java
// Este método é chamado na função CREATE da classe ArquivoLivro e é responsável por inserir as palavras chaves
// juntamente ao ID da entidade à classe ListaInvertida
private void createInvertida(String titulo, int ID) throws Exception {

	List<String> lista = LimparETokenizarString(titulo);

	for (String str : lista) {
		listaInvertidaTitulos.create(str, ID);
	}
}

// Este método é chamado na função DELETE da classe ArquivoLivro e é responsável por desassociar o ID da entidade
// das suas respectivas palavras chaves.
private void deleteInvertida(String titulo, int ID) throws Exception {

	List<String> lista = LimparETokenizarString(titulo);

	for (String str : lista) {
		listaInvertidaTitulos.delete(str, ID);
	}
}
```

```java
// Este método é reponsável por retornar uma lista de Strings que então
// serão usadas nos processos de inclusão e exclusão da classe ListaInvertida
private List<String> LimparETokenizarString(String str) {
	str = removerAcentos(str.toLowerCase());
	return removerStopWords(str);
}

// Este método remove todos os caracteres acentuadas de uma determinada string
private String removerAcentos(String str) {
	String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD);
	Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
	return pattern.matcher(nfdNormalizedString).replaceAll("");
}

// Esse método quebra a string em um array de strings, quebrando a string nos espaços.
// Ele itera no array de strings e pesquisa cada uma das strings numa hash de stop-words
// e insere a palavra numa lista de strings caso a palavra não seja uma stop-word.
private List<String> removerStopWords(String string) {

	List<String> arrayLimpo = new ArrayList<>();

	for (String str : string.split(" ")) {
		if (!stopWords.contains(str)) {
			arrayLimpo.add(str);
		}
	}

	return arrayLimpo;
}

// Esse metodo cria uma tabela hash de stop-words a partir de um arquivo.txt que encontramos
// na internet que contém centenas de stop words em portuges
private void CriarStopWordsList() {

	stopWords = new HashSet<>();
	
	String filePath = "AEDs/AEDs_III/TP/TP02/EstruturasDeDados/StopWords.txt";
	String fileLine;

	try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
		while ((fileLine = br.readLine()) != null) {
			stopWords.add(fileLine);
		}
	} catch (IOException e) {
		e.printStackTrace();
	}
}
```

```java

// Este método é responsável por:
// - Ler o título digitado pelo usuário.
// - 'Limpar' e 'Tokenizar' a String lida.
// - Fazer a interseção entre os conjuntos retornados pelas N palavras chave da pesquisa.
// - Fazer M (sendo M o número de ID do conjunto final) pesquisas no índice direto para montar uma LinkedList de Livros.
public List<T> readInvertida() throws Exception {

	System.out.printf("Insira o título do livro: ");
	String titulo = Lib.readString();

	List<String> palavras = LimparETokenizarString(titulo);

	HashSet<Integer> conjutoIDs = new HashSet<>();
	
	int[] dados = listaInvertidaTitulos.read(palavras.get(0));
	
	for (int i : dados) conjutoIDs.add(i);

	for (int i = 1; i < palavras.size(); i++) {
		dados = listaInvertidaTitulos.read(palavras.get(i));
		IntersecDeConjutos(conjutoIDs, dados);
		if (conjutoIDs.isEmpty()) break;
	}

	List<T> objects = new LinkedList<>();

	for (int ID : conjutoIDs) {
		try { objects.add(read(ID)); }
		catch (Exception e) {}
	}

	return objects;
}

// Esse método faz a interceção entre dois conjuntos, usamos uma hash para armazenar
// o conjunto resultante pois assim conseguimos reduzir o custo que seria O(n × m) para O(n).
private void IntersecDeConjutos(HashSet<Integer> conjunto1, int[] conjunto2) {
	for (int i : conjunto2) {
		if (!conjunto1.contains(i)) conjunto1.remove(i);
	}
}
```
#### O método readInvertida foi incluido no método read da classe arquivo e uma nova opção de pesquisa foi adicionada no menu. 
![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/8300b263-fe47-4c81-b46f-98e2ec4ff4c7)

## ✅ Checklist

1. **Modificação das funções CRUD:**
	- [X] A inclusão de um livro acrescenta os termos do seu título à lista invertida?
	- [X] A alteração de um livro modifica a lista invertida removendo ou acrescentando termos do título?
	- [X] A remoção de um livro gera a remoção dos termos do seu título na lista invertida?

2. **Pesquisa por registros:**
	- [X] Há uma busca por palavras que retorna os livros que possuam essas palavras?
	- [X] Essa busca pode ser feita com mais de uma palavra?

3. **Stop Words e funcionalidades extras:**
	- [X] As stop words foram removidas de todo o processo?
	- [X] Que modificação, se alguma, você fez para além dos requisitos mínimos desta tarefa?

6. **Funcionamento e Originalidade:**
	- [X] O trabalho está funcionando corretamente.
	- [X] O trabalho está completo.
	- [X] O trabalho é original e não uma cópia de um colega.

## 📝 Integrantes
 - Lucas Gualtieri
 - Gabriel Quaresma de Oliveira
 - Júlio César Gonzaga Ferreira Silva
 - Suzane Lemos de Lima
