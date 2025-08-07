SELECT
    movies.title
FROM
    movies

    JOIN stars s1 ON movies.id = s1.movie_id
    JOIN people p1 ON s1.person_id = p1.id AND p1.name = 'Bradley Cooper'

    JOIN stars s2 ON movies.id = s2.movie_id
    JOIN people p2 ON s2.person_id = p2.id AND p2.name = 'Jennifer Lawrence';
