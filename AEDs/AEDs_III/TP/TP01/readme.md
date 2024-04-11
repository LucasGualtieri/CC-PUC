# ✍️ TP01 - AEDs III

## 📝 Descrição
<ol>
	<li>Neste projeto foi desenvolvido um <strong>CRUD</strong> (Create, Read, Update, Delete) de um Banco de Dados que faz processamento em arquivo. </li>
	<li>
		Em outras palavras o programa permite que o usuário realize as seguintes operações:
		<ul>
			<li>Criação de registros para livros e atores.</li>
			<li>Consulta de registros existentes.</li>
			<li>Atualização de informações nos registros.</li>
			<li>Remoção de registros.</li>
		</ul>
	</li>
	<li>A versão atual do programa oferece uma interface em terminal para a manipulação de duas bases de dados: livros e autores.</li>
	<li>
		Adicionalmente foi implementado uma função que permite o usuário:
		<ul>
			<li>Listar todos os registros armazenados no arquivo de dados.</li>
			<li>Escolher a forma como os dados serão ordenados na listagem.</li>
		</ul>
</ol>

## 🔍 Experiência do Grupo
\- Lucas Gualtieri: "O **TP01**, apesar de simples, mostrou-se muito mais trabalhoso do que inicialmente pensávamos. A implementação do **CRUD** foi relativamente fácil e rápida, embora tenha exigido várias modificações para manter coerência com o restante do desenvolvimento do trabalho. O código para reaproveitamento dos espaços vazios mostrou-se bastante complexo de administrar. A ideia inicial era uma solução **in-place** (sem necessidade de uso adicional de memória), consistindo em criar uma lista encadeada de registros excluídos dentro do próprio arquivo de dados. No entanto, essa abordagem mostrou-se difícil de manter os métodos **CRUD** concisos e de fácil compreensão. Por esse motivo, optamos por uma solução **out-place**, utilizando uma classe e um arquivo externo para gerenciar um índice de registros excluídos."

### Houve alguma operação mais difícil?
\- Lucas Gualtieri: "Não houve necessariamente uma operação mais difícil, mas a construção do índice de excluídos foi umas das partes mais complexas."
#### Vocês enfrentaram algum desafio na implementação?
\- Lucas Gualtieri: "Um projeto dessa complexidade é muito difícil de testar. Ou seja, é complicado garantir que não haja nenhum caso em que algo fora do esperado possa acontecer."
#### Os resultados foram alcançados?
\- Gabriel Quaresma: "Foram sim! Apesar de que gostaríamos de ter implementado mais coisas, o programa está funcional e compriu todos os requisitos."

## ⚙️ Requisitos
Como parte dos requisitos do projeto, foi implementada uma rotina que permite o reaproveitamento dos espaços vazios de registros excluídos. Esse reaproveitamento, juntamente com a inclusão de um índice direto (implementado com a tabela hash extensível), desencadeou modificações em todas as operações do CRUD. Tudo foi implementado adequadamente e está funcionando conforme o esperado.

## 📊 Resultados
### Como foi feito o reaproveitamento dos espaços vazios?
Como mencionado anteriormente, optamos por descartar a sugestão de implementação **in-place** (lista encadeada de registros excluídos) devido à dificuldade em alcançar uma solução elegante. Em vez disso, decidimos criar uma classe e um arquivo externo para gerenciar um índice de registros excluídos e armazená-los, respectivamente. Essa classe apresenta os métodos **CRUD** de um índice tradicional e foi integrada ao **CRUD** da classe arquivo. Outras abordagens, como a hash extensível e a árvore B+, foram consideradas fora do escopo do projeto. Optamos, então, por uma solução mais simples, porém muito eficiente.

Nossa escolha foi uma árvore binária que armazena tuplas ```Tuple<Tamanho, Endereco>```. Essa abordagem demonstrou ser eficiente, pois mantém os registros ordenados a todo tempo, permitindo a recuperação eficaz dos registros a serem reaproveitados. Toda operação de exclusão no arquivo de dados implica em uma inserção ou remoção na árvore binária, assim como na atualização do arquivo de excluídos.

O reaproveitamento de um espaço vazio ocorre quando um novo registro, seja ele criado por meio das operações **CREATE** ou **UPDATE**, pode caber "dentro" de algum registro marcado com lápide. Para determinar qual dos registros excluídos será utilizado, realizamos um caminhamento central na árvore até encontrar uma tupla com tamanho igual ou superior ao do novo registro.

### Como o arquivo de tuplas foi gerenciado?
<ol>
	<li>Durante a criação de um registro, percorremos o arquivo sequencialmente até encontrar a primeira lápide, visto que os registros possuem tamanho fixo, tornando qualquer lápide uma opção para reaproveitamento. Caso não haja outras lápides, a inserção ocorre no final do arquivo.</li>
	<li>A exclusão é realizada de forma lógica, marcando simplesmente a lápide.</li>
	<li>Dado que o arquivo de excluídos é composto por tuplas de tamanho fixo, uma atualização nunca implica em reposicionar o registro no arquivo.</li>
</ol>

### O que foi considerado um desperdício aceitável no reuso de espaços?
Foi estabelecido um tamanho fixo com base em uma estimativa do menor tamanho possível para um registro. Para versões futuras, planejamos usar abordagens mais sofisticadas, como análises estatísticas e cálculos de desvio padrão, a fim de determinar o tamanho mínimo ideal. Por enquanto, realizamos um cálculo simples, que será explicado a seguir.

**Como avaliamos o que é um espaço suficiente para a inserção de um registro.** <br>
Para fazer essa avaliação foi estabelecido que cada classe determinará um tamanho mínimo para seus registros, que será utilizado no momento de calcular a diferença entre o tamanho de dois registros.
<ul>
	<li>
		Para calcular o tamanho mínimo de um registro, inicialmente realizamos uma estimativa baseada em um tamanho médio. No entanto, mais tarde percebemos a necessidade de estabelecer um tamanho mínimo para evitar a subutilização dos espaços vazios.
	</li>
	<li>
		O tamanho mínimo foi definido como:<br>
		Tamanho Mínimo = (A soma do tamanho dos atributos de tamanho fixo) + 5 × (Quantidade de Strings)
	</li>
	<li>
		Sendo assim após identificarmos o espaço vazio a ser reaproveitado, avaliamos se a diferença (em tamanho) entre o novo registro e o registro excluído é suficiente para a inserção de um possível terceiro registro. Se for o caso, dividimos o registro excluído em dois: na primeira parte, inserimos o novo registro e atualizamos o indicador de tamanho; na segunda parte, criamos um novo registro (excluído) com uma nova lápide e um novo indicador de tamanho, e o incluímos no índice de excluídos. No entanto, se essa diferença não for suficiente para acomodar um terceiro registro, mantemos o indicador de tamanho e incluímos o restante (a diferença) como lixo, como parte do novo registro.
	</li>
</ul>

Em outras palavras, para alcançar o reaproveitamento de espaços vazios no arquivo de dados, mantemos duas estruturas auxiliares paralelas: uma árvore binária e um arquivo de dados. Durante a inicialização do programa, executamos uma rotina para inserir todos os registros (exceto os marcados com a lápide) do arquivo de tuplas na árvore e, a cada inserção ou remoção, atualizamos tanto a árvore quanto o arquivo. É importante destacar que essa implementação considera que a quantidade de registros no índice de excluídos sempre caberá na memória principal, assumindo que esse número será baixo tanto em termos de registros quanto de bytes, já que cada tupla ocupa apenas 10 bytes. Implementações mais sofisticadas, como a árvore B+, nos possibilitariam um crescimento muito maior dos registros excluídos e serão consideradas em versões futuras do projeto.

## 💻 Implementações Futuras
Para as próximas versões e trabalhos futuros, pretendemos implementar o seguinte:

1. **Índice de Registros Excluídos com Árvore B+**:
	- Atualmente, nossa implementação precisa caber na memória principal. No entanto, caso haja um grande desbalanceamento, poderíamos enfrentar problemas. A inclusão de um índice de registros excluídos usando uma estrutura de dados como a Árvore B+ pode ajudar a otimizar essa funcionalidade.

2. **Índices Indiretos para Atributos das Bases (Livros e Autores)**:
	- Propomos criar índices indiretos para todos os atributos das bases de dados, incluindo títulos, nomes, sobrenomes, ISBNs, CPFs etc. Esses índices facilitarão a busca e a recuperação eficiente de informações.

3. **Uso da Classe `Tuple<Key, Value>` para índices**:
	Para melhor reaproveitamento e redução de redundâncias, planejamos utilizar a classe `Tuple<Key, Value>` para todos os índices. Isso implicará na modificação das classes da tabela hash e da árvore B+.

4. **Esquema de Paginação com Árvore B+**:
	- Ao listar registros, consideramos implementar um esquema de paginação usando uma Árvore B+. Dessa forma, não exibiríamos todos os registros de uma vez, mas sim sob demanda do usuário, semelhante a um site de marketplace.

5. **Relacionamentos entre entidades com Árvore B+**:
	- Quando um livro for criado, ele será associado a um autor. O autor é um registro complexo com muitos atributos, portanto, não poderia ser um campo do livro. Em vez disso, o autor deve ser tratado como um registro independente do livro. Para manter essa associação ou relacionamento, podemos usar uma Árvore B+. Isso nos permitiria, por exemplo, buscar todos os livros de um determinado autor ou descobrir quem escreveu um livro específico.

6. **Inclusão do Algoritmo de Intercalação Balanceada**:
	- Talvez simplemente pelo desafio da implementação e para tornar o trabalho mais completo.

## ✅ Checklist

1. **Gestão de Espaços Vazios:**
	- [X] Definimos critérios para a gestão de espaços vazios.
	- [X] Consideramos uma perda aceitável para o reuso de espaços vazios.

2. **CRUD com Arquivos de Tipos Genéricos:**
	- [X] O código do CRUD está funcionando corretamente.

3. **Índice Direto com Tabela Hash Extensível:**
	- [X] Implementamos um índice direto com tabela hash extensível.

4. **Operações de Inclusão e Alteração:**
	- [X] A operação de inclusão busca o espaço vazio adequado.
	- [X] A operação de alteração gerencia espaços vazios quando o registro cresce.

5. **Gerenciamento de Espaços Vazios:**
	- [X] As operações de alteração e exclusão gerenciam espaços vazios para reutilização.

6. **Funcionamento e Originalidade:**
	- [X] O trabalho está funcionando corretamente.
	- [X] O trabalho está completo.
	- [X] O trabalho é original e não uma cópia de um colega.

## 📝 Integrantes
 - Lucas Gualtieri
 - Gabriel Quaresma de Oliveira