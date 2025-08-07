SELECT COUNT(*)
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE ratings.rating = 10.0;
