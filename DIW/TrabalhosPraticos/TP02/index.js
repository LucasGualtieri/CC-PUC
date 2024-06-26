function main() {
	FetchReleasesSection({ dates: "2018-01-01,2024-03-28", page_size: 8 });
	// FetchReleasesSection();
	// FetchReleasesSection();
}

const options = {
	method: "GET",
	headers: { accept: "application/json" },
};

// Achar um jeito de esconder a KEY do usuário
let apiKEY = "13c033a42f8549eb9612748fa44a0e3a";

main();

function ApiURL(endPoint, queryParameters) {
	return `https://api.rawg.io/api/${endPoint}?key=${apiKEY}${ObjectToString(queryParameters)}`;
}

function ObjectToString(obj) {
	let string = "";
	for (const key in obj) if (obj[key] != undefined) string += `&${key}=${obj[key]}`;
	string = string.replaceAll(" ", "%20");
	return string;
}

function Sort(array, att, ascending = true) {
	let N = array.length;
	for (let i = 0; i < N - 1; i++) {
		let menor = i;
		for (let j = i; j < N; j++) {
			if (ascending) {
				if (array[menor][att] > array[j][att]) menor = j;
			} else {
				if (array[menor][att] < array[j][att]) menor = j;
			}
		}
		let aux = array[i];
		array[i] = array[menor];
		array[menor] = aux;
	}
}

addEventListener("applyFilters", () => {
	let getParametros = (categoria) => {
		let string = [];

		let array = document.querySelectorAll(`#dropdown-${categoria} li input`);

		array.forEach((input) => {
			if (input.checked) {
				string.push(input.id);
			}
		});

		let resultado = string.join(",");
		return resultado.length > 0 ? resultado : undefined;
	};

	let date = dataLimiteInferior.value + "," + dataLimiteSuperior.value;

	let genre = getParametros("generos");
	let developer = getParametros("developers");
	let tag = getParametros("tags");
	let publisher = getParametros("publishers");

	let radioInputs = document.querySelectorAll('input[name="order"]');

	let order;
	radioInputs.forEach((input) => {
		if (input.checked) order = input.id;
	});

	let queryParameters = {
		dates: date,
		page_size: 8,
		genres: genre,
		developers: developer,
		tags: tag,
		publishers: publisher,
		ordering: order,
		// ordering: "-rating",
		// ordering: "-released",
		// metacritic: "80,100",
	};

	FetchReleasesSection(queryParameters);
});

function FetchReleasesSection(queryParameters) {
	let endPoint = "games";

	// let queryParameters = {
	// 	search: "Counter Strike",
	// 	// ordering: "-released",
	// 	page_size: 6,
	// };

	let apiURL = ApiURL(endPoint, queryParameters);

	console.log("API URL: " + apiURL);

	fetch(apiURL, options)
		.then((response) => response.json())
		.then((json) => {
			// FinalizarLoadingScreen();
			MappingCards(json);
		})
		.catch((err) => console.error(err));
}

function MappingCards(jsonVar) {
	var resultado = jsonVar["results"];

	// Sort(resultado, "name");

	console.log("resultado: ", resultado);

	let gameCards = document.querySelector(".game-cards");

	gameCards.innerHTML = resultado.slice(0, 8).map(createCard).join("");
}

function createCard(obj) {
	return `
	<div class="card text-center">
		<div class="card-header">
			<label>${obj["name"]}</label>
			<label>${obj["metacritic"]}/100</label>
		</div>
		<div class="card-body">
			<img class="card-img-top" src="${obj["background_image"]}" alt="Card image cap" />
		</div>
	</div>
	`;
}

// let currentPage = 1;
// const pageSize = 20; // Number of games per page

// Pagination, a way to fetch more the 20 games at a time

// function fetchGames(page) {
//     const apiURL = `${endPoint}?key=${apiKEY}&page=${page}&page_size=${pageSize}`;

//     return fetch(apiURL, options)
//         .then((response) => response.json())
//         .then((data) => {
//             // Process the data (e.g., display games on your website)
//             console.log(data.results); // Adjust this according to your needs
//             return data;
//         });
// }

// function fetchAllGames() {
//     // Fetch the first page of games
//     fetchGames(currentPage)
//         .then((data) => {
//             // Check if there are more pages available
//             const totalPages = data.count / pageSize;
//             if (currentPage < totalPages) {
//                 // Fetch the next page recursively
//                 currentPage++;
//                 fetchAllGames();
//             }
//         })
//         .catch((error) => console.error("Error fetching games:", error));
// }

// fetchAllGames();
