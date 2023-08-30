--Genres
insert into genre (genre_name) values ('rock');
insert into genre (genre_name) values ('jazz');
insert into genre (genre_name) values ('soul');
insert into genre (genre_name) values ('pop');
insert into genre (genre_name) values ('techno');

--Persons
insert into persons (band) values ('Led Zeppelin');
insert into persons (person) values ('Nina Simone');
insert into persons (person) values ('Madonna');
insert into persons (person) values ('Boris Brejcha');
insert into persons (band)values ('Pretty Reckless');
insert into persons (person) values ('Kali Uchis');
insert into persons (person) values ('Ray Charles');
insert into persons (person) values ('Aretha Franklin');

--Artists
insert into artists(genre_id, persons_id) values (1, 1);
insert into artists(genre_id, persons_id) values (2, 2);
insert into artists(genre_id, persons_id) values (4, 3);
insert into artists(genre_id, persons_id) values (5, 4);
insert into artists(genre_id, persons_id) values (1, 5);
insert into artists(genre_id, persons_id) values (3, 6);
insert into artists(genre_id, persons_id) values (3, 7);
insert into artists(genre_id, persons_id) values (3, 8);

--Genre_artists
insert into genre_artists(genre_id, artists_id) values (1, 1);
insert into genre_artists(genre_id, artists_id) values (2, 2);
insert into genre_artists(genre_id, artists_id) values (4, 3);
insert into genre_artists(genre_id, artists_id) values (5, 4);
insert into genre_artists(genre_id, artists_id) values (1, 5);
insert into genre_artists(genre_id, artists_id) values (3, 6);
insert into genre_artists(genre_id, artists_id) values (3, 7);
insert into genre_artists(genre_id, artists_id) values (3, 8);
insert into genre_artists(genre_id, artists_id) values (2, 7);
insert into genre_artists(genre_id, artists_id) values (2, 8);

--Albums
insert into albums(artists_id, album_title, album_year) values (8, 'Laughing on the Outside', 1963);
insert into albums(artists_id, album_title, album_year) values (1, 'Presence', 1976);
insert into albums(artists_id, album_title, album_year) values (2, 'Forbidden Fruit', 1961);
insert into albums(artists_id, album_title, album_year) values (3, 'Ray of Light', 1998);
insert into albums(artists_id, album_title, album_year) values (5, 'Hit Me Like a Man', 2012);
insert into albums(artists_id, album_title, album_year) values (6, 'Red Moon in Venus', 2023);
insert into albums(artists_id, album_title, album_year) values (7, 'Ray Charles', 1957);
insert into albums(artists_id, album_title, album_year) values (4, 'Space Diver', 2020);

--Album_artists
insert into album_artists(artists_id, albums_id) values (1, 2);
insert into album_artists(artists_id, albums_id) values (2, 3);
insert into album_artists(artists_id, albums_id) values (3, 4);
insert into album_artists(artists_id, albums_id) values (4, 8);
insert into album_artists(artists_id, albums_id) values (5, 5);
insert into album_artists(artists_id, albums_id) values (6, 6);
insert into album_artists(artists_id, albums_id) values (7, 7);
insert into album_artists(artists_id, albums_id) values (8, 1);

--Tracks
insert into tracks(albums_id, track_name, duration) values (1, 'Sklylark', 2.52);
insert into tracks(albums_id, track_name, duration) values (1, 'Where are you', 3.53);
insert into tracks(albums_id, track_name, duration) values (1, 'Solitude', 3.51);
insert into tracks(albums_id, track_name, duration) values (2, 'For Your Life', 6.24);
insert into tracks(albums_id, track_name, duration) values (2, 'Royal Orleans', 2.59);
insert into tracks(albums_id, track_name, duration) values (3, 'I’ll Look Around', 5.08);
insert into tracks(albums_id, track_name, duration) values (3, 'Memphis in June', 2.39);
insert into tracks(albums_id, track_name, duration) values (4, 'Little Star', 5.18);
insert into tracks(albums_id, track_name, duration) values (4, 'Sky Fits Heaven', 4.48);
insert into tracks(albums_id, track_name, duration) values (5, 'Hit Me Like A Man', 3.33);
insert into tracks(albums_id, track_name, duration) values (5, 'Under The Water', 4.04);
insert into tracks(albums_id, track_name, duration) values (6, 'Moonlight', 3.08);
insert into tracks(albums_id, track_name, duration) values (6, 'I Wish you Roses', 3.40);
insert into tracks(albums_id, track_name, duration) values (7, 'Come Back Baby', 2.51);
insert into tracks(albums_id, track_name, duration) values (8, 'Blue Lake', 8.10);

--Collections
insert into collection(title) values ('We love Rock');
insert into collection(title) values ('We love Jazz');
insert into collection(title) values ('We love Soul');
insert into collection(title) values ('We love 20 century');
insert into collection(title) values ('Collection 1');
insert into collection(title) values ('Collection 2');
insert into collection(title) values ('Morning mixtape');
insert into collection(title) values ('Collection 3');

--Track_collection
insert into track_collection(tracks_id, collection_id) values (3,8);
insert into track_collection(tracks_id, collection_id) values (4,7);
insert into track_collection(tracks_id, collection_id) values (12,6);
insert into track_collection(tracks_id, collection_id) values (1,5);
insert into track_collection(tracks_id, collection_id) values (8,4);
insert into track_collection(tracks_id, collection_id) values (15,3);
insert into track_collection(tracks_id, collection_id) values (5,2);
insert into track_collection(tracks_id, collection_id) values (14,1);
insert into track_collection(tracks_id, collection_id) values (13,4);
insert into track_collection(tracks_id, collection_id) values (7,4);
insert into track_collection(tracks_id, collection_id) values (6,4);
insert into track_collection(tracks_id, collection_id) values (10,4);
insert into track_collection(tracks_id, collection_id) values (15,4);
insert into track_collection(tracks_id, collection_id) values (9,4);
insert into track_collection(tracks_id, collection_id) values (11,4);
insert into track_collection(tracks_id, collection_id) values (12,4);

