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
\- Lucas Gualtieri: "O <strong>TP01</strong>, apesar de simples, mostrou-se muito mais trabalhoso do que inicialmente pensávamos. A implementação do <strong>CRUD</strong> foi relativamente fácil e rápida, embora tenha exigido várias modificações para manter coerência com o restante do desenvolvimento do trabalho. O código para reaproveitamento dos espaços vazios mostrou-se bastante complexo de administrar. A ideia inicial era uma solução <strong>in-place</strong> (sem necessidade de uso adicional de memória), consistindo em criar uma lista encadeada de registros excluídos dentro do próprio arquivo de dados. No entanto, essa abordagem mostrou-se difícil de manter os métodos <strong>CRUD</strong> concisos e de fácil compreensão. Por esse motivo, optamos por uma solução <strong>out-place</strong>, utilizando uma classe e um arquivo externo para gerenciar um índice de registros excluídos."

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
- Discuta os resultados alcançados pelo projeto.
Também será importante considerar o que é um desperdício aceitável no reuso de espaços. Por exemplo, isso seria alguma porcentagem do espaço disponível? Seria uma quantidade máxima de desperdício (em número de bytes)? O espaço vazio teria um tamanho mínimo (e seria incorporado ao registro anterior se muito pequeno)?

## 💻 Implementações Futuras
Para próximas versões e próximos trabalhos pretendemos implementar:
- Índice de registros excluídos implementado com uma Árvore B+
	- Por conta que a implementação atual precisa caber em memoria principal teriamos um problema caso houvesse um grande desbalaço...
- Índices indiretos para todos os atruibutos de ambas as bases: livros e autores.
	- Teriamos então indices para titulo, nome, sobrenome, ISBN, CPF ...
- Uso da classe Tuple<Key, Value> para todos os índices, sendo assim modificando as classes da tabela hash e arvore b+
	- Para melhor reaproveitamento / diminuição de redundancias
- Esquema de paginação possivelmente usando Arvore B+ na hora da listagem para que não sejam mostrados todos registros mas sim sob demanda do usuário como em um site de marketplace
- Inclusão do algoritmo de intercalação balanceada

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