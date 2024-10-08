// Import the readline module
const readline = require('readline');

// Create an interface to read lines from the terminal
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

// Helper function to get user input asynchronously
function getInput(question) {
	return new Promise((resolve) => {
		rl.question(question, (answer) => {
			resolve(answer);
		});
	});
}

function SomaDeRiemann(f, a, b, n = 1000000) {

	let soma = 0;
	const deltaX = (b - a) / n;

	for (let i = 1; i <= n; i++) {
		soma += deltaX * f(a + i * deltaX);
	}

	return soma;
}

// Main function
async function main() {

	let continuar = 'yes';

	while (continuar === 'yes' || continuar === 'y') {

		const expression = await getInput("Digite a função de x (por exemplo, 'x**2', 'x*2 + 2'): ");
		const a = parseFloat(await getInput("Digite o valor de a: "));
		const b = parseFloat(await getInput("Digite o valor de b: "));

		const f = new Function("x", `return ${expression};`);

		console.log(`Soma de Riemann: ${SomaDeRiemann(f, a, b)}`);

		// Ask the user if they want to calculate another Riemann sum
		continuar = (await getInput("Deseja calcular outra soma de Riemann? (Y/N): ")).trim().toLowerCase();
		console.log();
	}

	console.log("Encerrando o programa.");
	rl.close(); // Close the readline interface
}

main();