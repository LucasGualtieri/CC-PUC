let pessoa = {
	nome: "Lucas",
	idade: 21,
};

let clone = (obj) => {
	let cloned = {};
	for (i in obj) cloned[i] = obj[i];
	return cloned;
};

// Struct em JS

function Pessoa(nome, idade) {
	return {
		nome: nome,
		idade: idade,
		adulto: () => idade >= 18,
	};
}

function Usuario(nome, idade) {
	this.nome = nome;
	this.idade = idade;
	this.isAdulto = () => this.idade >= 18;
}

function main() {
	// let teste = clone(pessoa);
	// teste.nome = "Lucas Gualtieri";

	// for (key in pessoa) {
	// 	console.log(`${key}: ${pessoa[key]}`);
	// }

	// let lucas = Pessoa("Gualtieri", 21);
	let lucas = new Usuario("Gualtieri", 21);

	// console.log(lucas.idade);
	// console.log(lucas.adulto());

	for (key in lucas) {
		if (key == "isAdulto") {
			console.log(`${key}: ${lucas[key]()}`);
		} else {
			console.log(`${key}: ${lucas[key]}`);
		}
	}
}

main();
