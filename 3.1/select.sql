SELECT album_title, album_year FROM albums
WHERE album_year = 2018;

SELECT track_name, duration FROM tracks
ORDER BY duration DESC
LIMIT 1;

SELECT track_names FROM tracks
WHERE duration >= 3.5;

SELECT title FROM collections
WHERE collections_year BETWEEN 2018 AND 2020
GROUP BY title
ORDER BY title;

SELECT person, FROM persons
WHERE person NOT LIKE '%% %';

SELECT band, FROM persons
WHERE band NOT LIKE '%% %';


SELECT track_name FROM tracks
WHERE track_name LIKE '%my%' OR track LIKE '%мой%';