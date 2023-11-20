PUC-Minas
Instituto de Ciências Exatas e Informatica
Curso de Ciência da Computação
Arquitetura de Computadores I

Pacote de programas para fundamentos de sistemas digitais

Itens

- 8085    v1.0 e v2.0
- CPUSim  v3.9.0
- Icarus  Verilog v.12 com GTKWave v3.3.100
- JFLAP   v7.1
- Logisim v2.16.1.x (ou superior, versão mais atualizada) 

Instalação

O arquivo compactado deverá ser expandido em uma 
pasta  de  sua  preferência, por exemplo em  C:\.
Recomenda-se não  usar  pasta  cujo  nome  possua
espaços em branco, acentos ou cedilha.

Os  atalhos  (.lnk)  deverão  ser  verificados  e 
editados para corresponder a essa pasta.

Os arquivos terminados em  (.bat)  também deverão 
ser editados para ajuste dos caminhos (path).

Recomenda-se  testar  previamente o funcionamento 
de todos os programas,  mesmo sem previsões  para
usos imediatos.

Para maior  comodidade  sugere-se  acrescentar  à
variável  de  ambiente  PATH  o  caminho  para as
pastas  que  contenham os  programas  executáveis
(bin), principalmente o Icarus_Verilog (iverilog) 
e GTKWave.

A variável de ambiente PATH deverá indicar o 
caminho para a pasta de programas executáveis,
por exemplo

C:\Icarus_Verilog_v11b2\bin
C:\Icarus_Verilog_v11b2\gtkwave\bin

Em linha de comando, após definir a variável PATH,
para se compilar um programa em Verilog, usar:

iverilog -o program.vvp program.v

A extensão (.v) deverá ser associada ao arquivo fonte
e a extenão  (.vvp)  deverá ser associada  ao arquivo 
objeto  cuja execução poderá ser feita como  descrito 
a seguir

vvp program.vvp

Recomenda-se  manter  as  extensões  ".v"  e  ".vvp"
em minúsculas, independente do sistema operacional.
A extensão ".vhdl" será reservada para outra linguagem.

Na pasta principal há um programa exemplo "hello.v",
o qual poderá ser usado para testes

iverilog -o hello.vvp hello.v
vvp hello.vvp
 


Observações

Qualquer editor de textos poderá ser associado
para programas em Verilog. Sugere-se o uso de
editores nativos do próprio sistema operacional.

A maioria dos programas selecionados funcionarão
em ambientes de quaisquer sistemas operacionais,
com Java, pelo menos, a versão 1.8.xx instalada.
O Icarus_Verilog e o GTKWAVE são dependentes 
de plataforma e requerem maior atenção.

A versão sugerida para ambiente Windows já está
atualizada, manualmente, o que não ocorre na
versão de distribuição disponível no site.
Por iso, sugere-se o uso da primeira, tomando
as providências necessárias para a sua 
localização no sistema operacional.

Em ambientes Linux o Icarus_Verilog e o GTKWAVE
podem ser instalados via

sudo apt-get install iverilog gtkwave
ou
sudo apt     install iverilog gtkwave

embora as versões possam diferir entre sistemas,
outras ainda recentes, serão aceitáveis.

Caso não seja possível instalar, recomendam-se
compiladores online gratuitos como

https://www.tutorialspoint.com/compile_verilog_online.php
https://www.jdoodle.com/execute-verilog-online/

https://www.edaplayground.com
// necessário cadastrar-se

Para os demais programas basta a simples cópia
para a pasta /opt e configuração de permissões
para execução.
