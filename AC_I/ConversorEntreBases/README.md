# ✍️ Trabalho Extra - AC I

## 💻 Execute o programa no navegador - <a href="https://replit.com/@LucasGualtieriF/ConversorEntreBases" target="_blank">replit.com/LucasGualtieri</a>

## 📝 Sobre

Neste trabalho, construímos um programa em C que converte números entre as bases binária, decimal, octal e hexadecimal. Apesar de não haver uma interface gráfica "bonitinha", criamos um menu que permite que o usuário escolha as bases de conversão, pois achamos que seria legal que o usuário tivesse a opção de escolher a Base de Entrada e a Base de Saída.

<pre>
BE: Base de Entrada & BS Base de Saída
  BE    ->   BS
Decimal -> Binário
  10    ->  1010
</pre>

## 🤔 Lógica para as Conversões entre bases

A lógica usada para fazer as conversões foi a seguinte:

Se BE ≠ 10, convertemos o valor digitado pelo usuário para Decimal e depois convertemos esse valor para a Base Final.<br>
Se BE = 10, convertemos o valor diretamente para a base de saída.

## ⚙️ Algoritmos de conversão
Como descrito no tópico anterior, o programa possui apenas dois algoritmos de conversão:
- O primeiro converte um valor em qualquer base para Decimal. Fazemos isso através do seguinte somatório: <br>
	- Exemplo:<br>
 	 ![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/0d7ff605-6830-42c5-9cac-8b2912daed0c)
	- Fórmula matemática:<br>
	  ![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/867d5334-e38f-474e-a245-7a9f004e7429)<br>
	- Na prática, esse somatório foi escrito da seguinte maneira: <br>
 	![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/689875f8-6060-4c76-90e7-029af87bef69)<br>
#
- O segundo algoritmo converte um valor em base Decimal para qualquer outra base. Na verdade, temos 2 subalgoritmos: a primeira parte converte a parte inteira através de divisões sucessivas e a segunda parte converte a parte fracionária através de multiplicações sucessivas: <br>
	- Na parte inteira, dividimos o número pela Base de Saída, obtendo o resto e o quociente separadamente. Continuamos a dividir o quociente pela base, guardando os novos resto e quociente, até que o quociente seja igual a zero.<br>
	![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/37e025cf-b77e-41d1-a96d-8359bbc4b65a)<br>
	- Na parte fracionária, multiplicamos a parte fracionária do número decimal pela Base de Saída, considerando apenas a parte inteira produzida. Continuamos o processo até que a parte fracionária seja igual a zero ou até termos 5 casas de precisão.<br>
   ![image](https://github.com/LucasGualtieri/CC-PUC/assets/42350002/92a5b94f-960c-401f-83da-192615bd6153)
