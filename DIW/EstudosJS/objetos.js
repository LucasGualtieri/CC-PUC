// Um objeto é declarado entre chaves {}, porém pode ->
// -> ser atribuido a uma variável para poder ter um nome

let musica = {}; // Alternativamente -> let musica = new Object();

// Posso a qualquer momento adicionar chaves e valores a um objeto
musica.titulo = "Eleanor Rigby";
console.log(musica);

musica.releaseDate = "25/04/2022";
console.log(musica);

musica["length"] = 180;
console.log(musica);

let user = {
	nome: "Lucas",
	sobrenome: "Gualtieri Firace Evangelista",
	idade: 20,
};

let names = "nome"; // Chave sempre tem que ser string
let pessoa = {};
pessoa[names] = "Lucas";

console.log("\n", pessoa);

console.log(
	"idade" in user
		? `${user.nome} tem ${user.idade} anos`
		: "Objeto Lucas não tem idade"
);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// chave é um nome arbitrário
for (let chave in user) {
	console.log(`${chave} = ${user[chave]}`);
}

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// Posso ter objetos aninhados

let pessoas = {
	// Objeto que tem chaves e valores.
	lucas: {
		// lucas é uma chave cujo valor é um objeto

		nomeCompleto: "Lucas Gualtieri",
		idade: 20,
	},
	arjuna: {
		nomeCompleto: "Arjuna Hari",
		idade: 19,
	},
};

console.log(pessoas.lucas);
console.log(pessoas.lucas.nomeCompleto);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// Vetor com objetos, dessa forma podemos ciclar por cada um dos objetos, ->
// -> objetos aninhados não permitem isso
let pessoas1 = [
	{ nome: "Lucas", idade: 20 },
	{ nome: "Arjuna", idade: 19 },
	{ nome: "Gontcha", idade: 18 },
];

let array = [
	{ nome: "Lucas", idade: 20 },
	{ nome: "Arjuna", idade: 19 },
];

pessoas1.forEach((element) => console.log(element));
console.log("\n");

pessoas1.forEach((element) => console.log(element.nome));
console.log("\n");

pessoas1.forEach(function (f) {
	console.log(f.idade);
});

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

let pessoas2 = [
	(lucas1 = { nomeCompleto: "Lucas Gualtieri", idade: 20 }),
	(arjuna = { nomeCompleto: "Arjuna Hari", idade: 19 }),
	(gontcha = { nomeCompleto: "Gontcha Gonçalves", idade: 18 }),
];

// console.log(lucas1);
// console.log(lucas1.nomeCompleto);

pessoas2.forEach((element) => console.log(element));
pessoas2.forEach((element) => console.log(element.nomeCompleto));

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// Cópia e clonagem de objetos

// Cópia: É apenas uma copia do endereço de um objeto, alterar a cópia irá alterar o original
let copiaMusica = musica;
console.log(copiaMusica);

copiaMusica.length = 170;
console.log(copiaMusica);
console.log(musica);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// A clonagem se da da seguinte maneira

let cloneMusica = {}; // Você cria um objeto vazio

// E atribui todos os elemetos do outro objeto
for (let chave in musica) cloneMusica[chave] = musica[chave]; // chave é um nome arbitrário
cloneMusica.titulo = "Dust in the Wind";

console.log(cloneMusica);
console.log(musica);

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

//Função para criar objeto

// Essa variáveis poderiam ser definidade por um usuário, tipo um scanf
let nome = "Lucas";
let idade = 20;

let createUser = (nome, idade) => ({
	nome: nome,
	idade: idade,
	maiorIdade: () => idade >= 18,
});
// return { nome: nome, idade: idade, maiorIdade: () => this.idade >= 18 }; ->
// -> Não consegui fazer isso funcionar
// return { nome: nome, idade: idade, maiorIdade: idade >= 18 }; // Esse cara não altera maiorIdade dinamicamente

console.log("Salve: \n", createUser());

let newUser = createUser("Lucas", 20);

console.log(newUser, newUser.maiorIdade());
// console.log("\nMaior Idade: ", newUser.maiorIdade(),"\n");

newUser.idade = 17;
console.log(newUser);
console.log("\nMaior Idade: ", newUser.maiorIdade());

// ---------------------------------------------------------------------------------
console.log("\n-----------------------------\n");

// // Função construtora
function NewUser1(nome, idade) {
	this.nome = nome;
	this.idade = idade;
	this.maiorIdade = () => this.idade >= 18;
}

let newUser1 = new NewUser1("Lucas", 17);

console.log(newUser1);
console.log("\nMaior Idade: ", newUser1.maiorIdade());
