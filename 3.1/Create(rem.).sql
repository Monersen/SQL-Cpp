create table if not exists country (
id serial primary key,
contry_name varchar(60)
);

create table if not exists persons (
id serial primary key,
person varchar(60),
band varchar(60),
country_id integer references country(id)
);

create table if not exists genre (
id serial primary key,
genre_name varchar(60) not null
);

create table if not exists artists (
id serial primary key,
persons_id integer references persons(id),
genre_id integer references genre(id)
);

create table if not exists genre_artists (
genre_id integer references genre(id),
artists_id integer references artists(id),
constraint bk primary key (genre_id, artists_id)
);

create table if not exists albums (
id serial primary key,
album_title varchar(60) not null,
album_year integer,
artists_id integer references artists(id)
);

create table if not exists album_artists (
artists_id integer references artists(id),
albums_id integer references albums(id),
constraint vk primary key (artists_id, albums_id)
);

create table if not exists tracks (
id serial primary key,
track_name varchar(60) not null,
duration float not null,
albums_id integer references albums(id)
);

create table if not exists collection (
id serial primary key,
title varchar (60) not null
);

create table if not exists track_collection (
tracks_id integer references tracks(id),
collection_id integer references collection(id),
constraint pk primary key (tracks_id, collection_id)
);
