// Em js é possível atribuir valores padrões aos parâmetros
// Não preciso, na verdade nem posso usar let no parametro
function teste(a = 0, b = 0) {
	return a + b;
}

console.log("2 + 0 = ", teste(2)); // 2
console.log("2 + 3 = ", teste(2, 3)); // 5

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// IFFE - Immediately Invoked Function Expressions
console.log(
	(function (a, b) {
		//função anônima.
		return a + b;
	})(4, 5) // 9
);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

let isEnable = function (a, b = 1) {
	return a > b ? true : false;
};

// Should be false = "Not enabled"
console.log(isEnable(3, 5) ? "Is enabled!" : "Not enabled");

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

let soma = function (a, b) {
	return a + b;
};

console.log("3 + 5 = ", soma(3, 5));
console.log(soma); // Neste momento não vale nada, mesmo com a linha a cima.

soma = soma(3, 5); // Agora sim, passa a valer 8

let a = soma + 2;
console.log(a);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// A atribuição acontece logo na declaração, pois ->
// -> assim posso passa-la como parametro para outra função.

let sum = (a, b) => a + b;
let sub = (a, b) => a - b;
let mult = (a, b) => a * b;
let div = (a, b) => a / b;

function executa(fn, a, b) {
	return fn(a, b);
}

console.log(executa(sum, 12, 3));
console.log(executa(sub, 12, 3));
console.log(executa(mult, 12, 3));
console.log(executa(div, 12, 3));

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// Essa função precisa ter nome por ser recursiva. Ela poderia obviamente ter sido ->
// -> feita sem ser uma let fat, e depois atribuida para uma variável, mas funções ->
// -> recursivas sempre vão precisar de nome.
let fat = function fatorial(n) {
	return n == 1 ? 1 : n * fatorial(n - 1);
};

// console.log(fatorial(5)); // Não funciona
console.log(fat(5));

fat = fat(5);
console.log(fat);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// Agora sim, a tão esperada Arrow Function!!!
function mult2(a, b) {
	return a * b;
}
console.log(mult(2, 3)); // 6

// A Arrow Function precisa ser atribuida a uma variavel logo na sua declaração
let multArrow = (a, b) => a * b;
console.log(multArrow(3, 3)); // 9

let hello = function () {
	return "Hello World!";
};
console.log(hello());

let helloArrow = () => "Hello World!";
console.log(helloArrow());

let helloArrowPar = (val) => "Hello " + val;
console.log(helloArrowPar("Lucas"));

let arrowFunction = () => {
	console.log("Olá mundo");
};

arrowFunction();
