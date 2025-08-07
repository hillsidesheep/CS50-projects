SELECT AVG(songs.energy) AS average_energy
FROM songs
JOIN artists ON artists.id = songs.artist_id
WHERE artists.name = 'Drake';
