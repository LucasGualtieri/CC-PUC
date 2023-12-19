// clear && node teste.js

function sum(x, y) {
	return x + y;
}

function sub(x, y) {
	return x - y;
}

// Function declarations are loaded before any code is executed. This means that you can use the function before it’s declared in your code. This behavior is known as hoisting.
// Function expressions are not executed until the interpreter reaches that line of code. So, you cannot use a function expression before it’s defined in your code.

// So if limitting where functions can be accessed is something you wanna do, arrow functions can provide a more consise sintax

somar = (x, y) => x + y;

function main() {

	let x = 1, y = 2;
	let operation = sum;
	let z = operation(x, y);

	console.log("z:", z);
	operation = sub;

	z = operation(x, y);
	console.log("z:", z);
	
	// z = add(x, y); // Won't work because of how const (and let) variables work. They can only be used after the've been declared, but not var variables
	console.log("z:", z);

	z = somar(x, y);
	console.log("z:", z);
}

main();

// This is a function expression
const add = function(x, y) {
	return x + y;
}

var somar = (x, y) => x + y;