{
	// let é uma variável local. Nesse caso ela está presa nesse escopo e não pode ser vista de fora.
	let nomeLocal = "nomeLocal";

	// var é uma variável global e pode ser vista fora de seu escopo.
	// var não pode ser visto fora do escopo de funções.
	var nomeGlobal = "nomeGlobal";

	// Variáveis podem ser declaradas sem seus tipos serem especificados, dessa forma o tipo sempre será var
	nomeMarreco = "nomeMarreco";

	var marrecoMaster // Undefined

	let marrecoNull = null // Uma forma de limpar uma variável

	console.log(nomeLocal);
	console.log(marrecoNull);
}
console.log(nomeGlobal);
console.log(nomeMarreco);
console.log(marrecoMaster);

// O que define o tipo de uma variável em JS é seu valor, JS é uma linguagem dinâmica
// Os tipos de variáveis que JS tem internamente são string, number, bigInt e boolean.
// Uma variável que não tem o seu tipo ainda definido, -> 
// -> isto é, que não recebeu nenhum valor, será undefined, que é do tipo object.
// O tipo de uma variável pode ser alterado, na medida em que ela receba um novo valor. ->
// -> Por permitir essa alteração de tipo, JavaScript é classificada como uma linguagem fracamente tipada.
// Variáveis podem ser delcaradas dessa forma: let a = 2, b = 3, c;

{ // Variáveis do tipo number são internamente equivalentes a uma variável double.
	let int = 1; //int é só um nome, pelo que eu saiba não existe diferenciação de int e float.
	console.log(typeof(int));

	let float = 1.0; //float é só um nome, pelo que eu saiba não existe diferenciação de float e int.
	console.log(typeof(float));

	// Existe também BigInt - Para números inteiros com muitos e muitos dígitos;
}

{ // Variáveis do tipo string
	let string = "Nome"; //string é só um nome, pelo que eu saiba não existe diferenciação de string e char.
	console.log(typeof(string));

	let char = 'M'; //char é só um nome, pelo que eu saiba não existe diferenciação de char e string.
	console.log(typeof(char));

	// As strings podem ser delimitadas por apóstrofos (' ') ou aspas(" "). Os apóstrofos são usados para ->
	// -> combinar HTML e JS, isso para evitar confusão, estou fechando uma string, ou criando uma substring?
	// Há ainda uma terceira alternativa que é a delimitação pelo acento grave (` `). Nesse caso, ela é ->
	// -> chamada de template string e possui duas diferenças em relação às strings convencionais: ->
	
	// Uma template string pode conter várias linhas do código:
	/*	let poema = `O Poeta é um fingidor.
		Finge tão completamente
		Que chega a fingir que é dor
		A dor que deveras sente.
		(Fernando Pessoa)`;
	*/

	// Uma template string permite a interpolação de expressões:
	/*
		let a = 3, b = 5;
		console.log(`A soma de ${a} e ${b} é ${a+b}.`); 
	*/

	let a = 2, b = 3;
	let stringMult = `${a} * ${b} = ${a * b}`;
	let stringConcat = a + " * " + b + " = " + a * b; // Em strings o + concatena.
	console.log(stringMult);
	console.log(stringConcat);
}

{ // Variável de tipo boolean
	let bool = true;
	console.log(typeof(bool));

	let idade = 20;
	let podeTirarCarteira = idade >= 18;
	console.log(podeTirarCarteira);
}

// Variáveis também podem ser constantes.
// Constantes são variáveis de escopo local, assim como let, e até onde sei.
// Recomenda-se o uso de camelCase para os nomes das variáveis e apenas letras maiúsculas ->
// -> para os nomes das constantes (caso o nome tenha mais de uma palavra, separe-as usando o caráter '_')

{
	const PI = 3.14159;
	console.log(PI);
}