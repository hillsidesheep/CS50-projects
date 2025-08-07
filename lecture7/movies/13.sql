SELECT DISTINCT
    p_actor.name
FROM
    people p_act
    JOIN stars s1 ON s1.person_id = p_act.id
    JOIN movies m ON m.id = s1.movie_id
    JOIN stars s2 ON s2.movie_id = m.id
    JOIN people p_actor ON p_actor.id = s2.person_id
WHERE
    p_act.name = 'Kevin Bacon'
    AND p_act.birth = 1958
    AND p_actor.name != 'Kevin Bacon';

