// 14a9bda1b98e57f1bf7b5be9cea2a674

const options = {
	method: "GET",
	headers: { accept: "application/json" },
};

let apiURL = "https://api.themoviedb.org/3/movie/popular?api_key=14a9bda1b98e57f1bf7b5be9cea2a674";

let promise = fetch(apiURL, options); // Returns a Promise

let newPromiseJSON = promise.then((response) => response.json()); // When resp (promise) is resolved, *then* it returns a reponse.

let json = newPromiseJSON.then((response) => response); // This is redundant, all these variables command lines are being executed sequentially and instantaneously, so they're all receving different promises, that will take some time to resolve, so this line is only really creating a new value to hold a new promise

json.then((response) => console.log(response));

json.then(Teste);

// json.catch((err) => console.error(err));

// The .map() method in JavaScript is used to create a new array by applying a function
// to each element of an existing array. It iterates over each element of the array, applies
// a callback function to each element, and returns a new array containing the results
// of calling the callback function on each element.

function Teste(jsonVar) {
	var resultado = jsonVar["results"];
	body.innerHTML = resultado.map(createCard).join("");
}

function createCard(obj) {
	let teste = {
		title: obj["title"],
		adulto: obj["adult"] ? "Sim" : "Não",
		imagem: obj["poster_path"],
		id: obj["id"],
	};
	return `
		<div class="card" style="width: 18rem">
			<a href="https://www.themoviedb.org/movie/${teste["id"]}">
				<img class="card-img-top" src="https://image.tmdb.org/t/p/w500/${teste["imagem"]}" alt="Card image cap" />
			</a>
			<div class="card-body">
				<p class="card-text">
					Title: ${teste["title"]}.<br>
					18+ ${teste["adulto"]}.
				</p>
				<button><a href="https://www.themoviedb.org/movie/${teste["id"]}">LINK</a></button>
			</div>
		</div>
	`;
}

// function Teste(jsonVar) {
// 	var resultado = jsonVar["results"];

// 	resultado.forEach((obj) => {
// 		// console.log(`Index ${index}:`);
// 		// console.log(JSON.stringify(resultado[index], null, 4));
// 		let teste = {
// 			title: obj["title"],
// 			adulto: obj["adult"] ? "Sim" : "Não",
// 			imagem: obj["poster_path"],
// 			id: obj["id"],
// 		};
// 		body.innerHTML += createCard(teste);
// 	});
// }

// function createCard(obj) {
// 	let cardString = `
// 	<div class="card" style="width: 18rem">
// 		<img class="card-img-top" src="https://image.tmdb.org/t/p/w500/${obj["imagem"]}" alt="Card image cap" />
// 		<div class="card-body">
// 			<p class="card-text">
// 				Title: ${obj["title"]}.<br>
// 				18+ ${obj["adulto"]}.
// 			</p>
// 			<button><a href="https://www.themoviedb.org/movie/${obj["id"]}">LINK</a></button>
// 		</div>
// 	</div>`;
// 	return cardString;
// }

onload = () => {
	// body.innerHTML += createCard();
};
