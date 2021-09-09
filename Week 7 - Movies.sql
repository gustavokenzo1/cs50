'''
Done using IMDb's database 
Separated in 13 different exercises, but I appended everything into here.
.schema for reference:

CREATE TABLE movies (
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    PRIMARY KEY(id)
                );
CREATE TABLE stars (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE directors (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE ratings (
                movie_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id)
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            );
'''

1.sql:

SELECT title FROM movies WHERE year = "2008";

2.sql:

SELECT birth FROM people WHERE name = "Emma Stone";

3.sql:

SELECT title FROM movies WHERE year > 2017 ORDER BY title;

4.sql:

# Here I had to pause and rewatch the "JOIN" part because it started to get hard  

SELECT COUNT(title) FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE rating = 10;

5.sql:

# Here it got easy again. Pretty straight foward.

SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year ASC;

6.sql:

SELECT AVG(rating) FROM movies 
JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2012;

7.sql:

SELECT title, rating FROM movies 
JOIN ratings ON movies.id = ratings.movie_id 
WHERE year = 2010 ORDER BY rating DESC, title ASC;

8.sql:

SELECT name FROM people 
JOIN stars ON stars.person_id = people.id 
JOIN movies ON stars.movie_id = movies.id 
WHERE title = 'Toy Story';

9.sql:

SELECT DISTINCT(name) FROM people 
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id 
WHERE year = 2004 ORDER BY birth;

10.sql:

SELECT DISTINCT(name) FROM people 
JOIN directors ON directors.person_id = people.id
JOIN movies ON directors.movie_id = movies.id 
JOIN ratings ON ratings.movie_id = movies.id
WHERE rating >= 9;

11.sql:

SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE name = 'Chadwick Boseman' ORDER BY rating DESC LIMIT 5;

12.sql:

SELECT DISTINCT(title) FROM movies 
JOIN stars ON stars.person_id = people.id
JOIN people ON stars.movie_id = movies.id
WHERE name = 'Johnny Depp' AND title IN 
(SELECT DISTINCT(title) FROM movies 
JOIN stars ON stars.person_id = people.id
JOIN people ON stars.movie_id = movies.id
WHERE name = 'Helena Bonham Carter');

13.sql: 

#This was just cruel, David/Brian... give me more please
SELECT DISTINCT(name) FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (SELECT movies.id FROM movies
JOIN stars ON stars.person_id = people.id
JOIN people ON stars.movie_id = movies.id
WHERE people.name = 'Kevin Bacon' AND birth = '1958')
AND people.name != 'Kevin Bacon';

CONCLUSIONS: If we want to reference something that is in another table, you have to JOIN them, paying attention to
their PRIMARY KEY, FOREIGN KEY and REFERENCES, they should guide us. Nested selections are very useful for double conditions. 
