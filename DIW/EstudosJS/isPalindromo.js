// clear && node isPalindromo.js

function isPalindromo(string) {

	let resultado = true;
	let length = string.length;

	for (let i = 0; i < length; i++) {
		if (string[i] != string[length - i - 1]) {
			resultado = false;
			i = length;
		}
	}

	return resultado;
}

function main() {

	let string = "marrocos - socorram";

	if (isPalindromo(string)) {
		console.log("É palíndromo");
	} else {
		console.log("Não é palíndromo");
	}
}

main();