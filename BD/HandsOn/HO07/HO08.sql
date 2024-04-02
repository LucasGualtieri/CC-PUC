-- Projetar o primeiro nome e o último nome dos atores que são diretores;
SELECT first_name, last_name
FROM
(SELECT first_name, last_name FROM actors) as AtoresDiretores
INTERSECT
(SELECT first_name, last_name FROM directors)

-- Projetar o primeiro nome e o último nome dos atores que não são diretores;
SELECT first_name, last_name
FROM
(SELECT first_name, last_name FROM actors) as AtoresDiretores
EXCEPT
(SELECT first_name, last_name FROM directors)

-- Projetar o primeiro nome e o último nome dos atores e diretores;
SELECT first_name, last_name
FROM
(SELECT first_name, last_name FROM actors) as AtoresDiretores
UNION
(SELECT first_name, last_name FROM directors)

-- Projetar o nome dos filmes que não são dirigidos por nenhum diretor;
SELECT name
FROM movies EXCEPT 
(SELECT name FROM movies_directors JOIN movies ON movies.id = movie_id)

-- ---------------------------------------------------------------------------

/*

Não consegui fazer as últimas duas

*/

-- Projetar primeiro nome e o último nome dos atores que não atuaram em pelo menos dois filmes;
SELECT first_name, last_name
FROM actors
JOIN (
	SELECT id
	FROM actors EXCEPT (
		SELECT actor_id
		FROM (
			SELECT actor_id, COUNT(*) AS qtdFilm
			FROM roles
			GROUP BY actor_id HAVING qtdFilm > 2
		) AS actor_id
	)
) AS A ON id = A.id

-- Projetar, por gênero e ano, o número médio de filmes com menos de dois atores atuando.
SELECT C.genre, year, COUNT(*) AS qtd
FROM (
	SELECT movies_genres.movie_id, movies_genres.genre
	FROM (
		SELECT id FROM movies EXCEPT (
			SELECT movie_id
			FROM (
				SELECT movie_id, COUNT(*) AS qtdActor
				FROM roles
				GROUP BY movie_id HAVING qtdActor > 2
			)
		AS A)
	) AS B
	JOIN movies_genres ON B.id = movie_id
) AS C
JOIN movies ON C.movie_id = id
GROUP BY C.genre, year