-- Projetar o primeiro nome e o último nome dos atores de sexo feminino;
SELECT first_name, last_name FROM actors WHERE gender = 'F'

-- Projetar o nome dos filmes com ano superior à 1999;
SELECT name FROM movies WHERE year > 1999

-- Projetar o nome do filme e o nome do diretor de cada filme;
-- INNER JOIN é sinônimo de JOIN
SELECT first_name, last_name, name
FROM   movies_directors
JOIN   directors ON director_id = directors.id
JOIN   movies ON movie_id = movies.id

-- Projetar o nome do filme, nome do ator e o papel que cada ator teve no filme para filmes com ranking acima da nota 6;
SELECT name, first_name, last_name, role, rank
FROM ((actors
JOIN roles
ON actors.id = roles.actor_id)
JOIN movies ON movies.id = movie_id)
WHERE rank > 6

-- Projetar o nome do diretor e o número de filmes que cada diretor dirigiu;
SELECT first_name, last_name, COUNT(*) AS number_of_movies
	FROM (
		movies_directors JOIN directors
		ON director_id = directors.id
	)
GROUP BY directors.first_name, directors.last_name;

-- Projetar o gênero e o número de filmes de cada gênero; 
SELECT   genre, COUNT(*) AS number_of_movies
FROM     movies_genres
GROUP BY genre;

-- Projetar o gênero, o ranking (nota) médio, mínimo e máximo dos filmes do gênero.
SELECT genre,
AVG(movies.rank) AS avg_rank,
MIN(movies.rank) AS min_rank,
MAX(movies.rank) AS max_rank
FROM (
	movies JOIN movies_genres ON movies.id = movie_id
)
GROUP BY genre;