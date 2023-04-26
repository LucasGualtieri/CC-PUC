{
	let array = [4, 3, 2, 1];
	array.sort(); // Sorts the array in ascending order

	// let lastElementOfArray = array.pop(); // Removes the element at the last indice and returns it.

	// let firstElementOfArray = array.shift(); // Removes the element at the first indice and returns it.

	// let newArrayLength = array.push(5); // Expands the array to fit all the elements. Adds an element at the end of the array. Returns the new array size

	// let newArrayLength = array.unshift(0); // Adds an element to the first index of the array. Expands the array to fit all the elements. Returns the new array size

	// console.log(firstElementOfArray);

	// console.log(array);

	LucasG = {
		name: "Lucas Gualtieri",
		idade: 20,
		Endereco: {
			rua: "Norita",
			bairro: "Santa Tereza",
		},
		cpf: "13605269605",
	};

	// console.log(LucasG.Endereco.rua);
}

{
	class Person {
		// The # makes the attribute private.
		// But it hasn't been formalized, and '_' is the current convention.
		// The '_' does NOT make the attribute private, it's just for the user of the class to know with ease its state.
		#name;

		// In JS we can use the constructor to declare the variables.
		constructor(name) {
			// this.imCreatingAVar = 123;
			this.#name = this.#_Capitalize(name);
		}

		// The '_' before names is just a convention for stuff inside of a class.
		// Methods don't need 'function' before their name.
		#_Capitalize(string) {
			return `${string.charAt(0).toUpperCase()}${string.slice(1)}`;
		}

		// Setters and Getters in JS are bult-in the language.
		set setName(name) {
			this.#name = this.#_Capitalize(name);
		}

		get getName() {
			return this.#name;
		}
	}

	let p1 = new Person("lucas"); // There's no other way to create an object of a class.

	p1.setName = "gualtieri"; // Calls the constructor. -> p1.name("gualtieri") does not work;

	console.log(p1.getName);
}
