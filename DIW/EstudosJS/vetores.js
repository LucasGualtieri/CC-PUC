let nomes = ["Lucas", "Gualtieri", "Firace"];
console.log(nomes);
console.log(nomes[1]);
console.log(typeof(nomes)); // Vetor é um 'Object'.

// Em JS um array/vetor não precisa armazenar valores de um mesmo tipo.
let vetor = ["Lucas", 3, true];
console.log(vetor);
console.log(vetor[0]);

vetor[0] = "Gualtieri";
console.log(vetor);

// Isso é um especificidade de JS, outras linguagens ->
// -> não permitem que eu aumente o tamanho de um vetor 
vetor[3] = "Lucas";
console.log(vetor);

vetor[6] = 12; // Nessa caso as posições 4 e 5 estarão vazias.
console.log(vetor);

console.log(vetor.length); // 7

console.log(vetor);
for (let i = 0; i < vetor.length; i++) {
	console.log(vetor[i]);
}

// Para evitar criar espaços vazios em um vetor
vetor[vetor.length] = "Firace";
console.log(vetor);

let array = []; // Em JS não há a necessidade de especificar o tamanho para um vetor vazio.

let array2 = new Array(); // Função construtora, pq? No idea

let alfabeto = ['c', 'b', 'a', 'd'];
alfabeto.sort(); // Ordena o vetor, nesse caso em ordem alfabética.
console.log(alfabeto);

console.log(alfabeto.pop()); // retorna e remove o último elemento de um vetor.
console.log(alfabeto);

alfabeto.push('d'); // Adiciona um elemento ao final de um vetor.
console.log(alfabeto);

console.log(alfabeto.shift()); // Retorna e Remove o primeiro elemento de um vetor.
console.log(alfabeto);

alfabeto.unshift('a'); // Adiciona um elemento na primeira posição de um vetor.
console.log(alfabeto);

alfabeto.unshift('A'); // Adiciona um elemento na primeira posição de um vetor.
console.log(alfabeto);

numeros = [1, 2, 3, 4, 5];
// for (let i = 0; i < numeros.length; i++) console.log(numeros[i]);

// par é um parametro que recebe para cada um dos itens de um vetor, ->
// -> um de cada vez, nesse caso eu printei usando console.log, mas poderia fazer outras coisas
numeros.forEach(par => console.log(par));

numeros.forEach(par => console.log(par + 1));

// ---------------------------------------------------------------------------------
// Um vetor constante não muda nada

console.log("\n-----------------------------\n");

const vetorConst = [1, 2, 3, 4];
vetorConst[vetorConst.length] = vetorConst.length + 1;
vetorConst[0] = 0;
console.log(vetorConst);