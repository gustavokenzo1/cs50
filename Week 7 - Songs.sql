# There were 8 different files, so in order to keep things clean, I'm going to put everything here.
# These were all based on a song database provided by Spotify and contains the top 100 songs streamed in 2018.

# 1.sql
SELECT name FROM songs;

# 2.sql
SELECT name FROM songs ORDER BY tempo ASC;

# 3.sql
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

# 4.sql
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;

# 5.sql
SELECT AVG(energy) FROM songs;

# 6.sql
SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Post Malone");

# 7.sql
SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Drake");

# 8.sql
SELECT name FROM songs WHERE name LIKE '%feat.%';
