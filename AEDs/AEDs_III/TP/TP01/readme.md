# Nome do Projeto

## 📝 Descrição
Neste projeto foi desenvolvido um CRUD de um Banco de Dados NoSQL. Atualmente o programa oferece uma interface em terminal que permite a manipulação de duas bases de dados, livros e autores. Adicionalmente foi implementado uma função que permite que o usuário liste todos os registros armazenados no arquivo de dados, e escolha de que forma os dados estarão ordenados.

Como parte dos requisitos do projeto voi

Como foi implementado a listagem dos registros:

falar como foi feito e como foi ordenado e falar dos problemas e do que é pensado pras proximas versões

Nesta versão do projeto a listagem mostra todos os registros o que pode ser tornar inviável tendo em vista o possível crescimento da base de dados.e da mesma forma ordenar uma grande base será necessário implementar a ordenação ordenação foi feita interamente em memória principal 

Seu grupo deve implementar uma rotina que permita o reaproveitamento desses espaços vazios de registros excluídos. Esse reaproveitamento deverá ser avaliado toda vez que fizermos uma entre as seguintes operações:

Inclusão de um novo registro
Alteração de um registro com aumento de tamanho
Obviamente, os espaços vazios devem ser controlados de alguma forma. Para isso, nas operações de exclusão e de alteração será importante ajustar o código para permitir esse controle.

Também será importante considerar o que é um desperdício aceitável no reuso de espaços. Por exemplo, isso seria alguma porcentagem do espaço disponível? Seria uma quantidade máxima de desperdício (em número de bytes)? O espaço vazio teria um tamanho mínimo (e seria incorporado ao registro anterior se muito pequeno)?

## Requisitos
- Liste os requisitos principais do projeto.
- Explique como o projeto atende a esses requisitos.

## Experiência do Grupo
- Relate a experiência do grupo durante o desenvolvimento.
- Discuta desafios enfrentados, operações difíceis e soluções encontradas.

## Checklist

1. **Gestão de Espaços Vazios:**
   - [ ] Definimos critérios para a gestão de espaços vazios.
   - [ ] Consideramos uma perda aceitável para o reuso de espaços vazios.

2. **CRUD com Arquivos de Tipos Genéricos:**
   - [ ] O código do CRUD está funcionando corretamente.

3. **Índice Direto com Tabela Hash Extensível:**
   - [ ] Implementamos um índice direto com tabela hash extensível.

4. **Operações de Inclusão e Alteração:**
   - [ ] A operação de inclusão busca o espaço vazio adequado.
   - [ ] A operação de alteração gerencia espaços vazios quando o registro cresce.

5. **Gerenciamento de Espaços Vazios:**
   - [ ] As operações de alteração e exclusão gerenciam espaços vazios para reutilização.

6. **Funcionamento e Originalidade:**
   - [ ] O trabalho está funcionando corretamente.
   - [ ] O trabalho está completo.
   - [ ] O trabalho é original e não uma cópia de um colega.

## Resultados
- Discuta os resultados alcançados pelo projeto.

## Licença
- Escolha uma licença apropriada para o seu projeto.

## Contato
- Informações de contato do grupo ou desenvolvedores.