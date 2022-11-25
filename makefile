all: maker

CC = gcc
CODIGOS = spotify/Artista.c spotify/Menu.c spotify/Musica.c spotify/Artista.c spotify/Propriedades.c spotify/Playlist.c spotify/Spotify.c
HEADERS = spotify/Artista.h spotify/Menu.h spotify/Musica.h spotify/Artista.h spotify/Propriedades.h spotify/Playlist.h spotify/Spotify.h
override CFLAGS += -ggdb3 -lm -Wall

libspotify.a: $(CODIGOS) $(HEADERS)
	gcc -c spotify/Artista.c -o spotify/Artista.o $(CFLAGS)
	gcc -c spotify/Menu.c -o spotify/Menu.o $(CFLAGS)
	gcc -c spotify/Musica.c -o spotify/Musica.o $(CFLAGS)
	gcc -c spotify/Playlist.c -o spotify/Playlist.o $(CFLAGS)
	gcc -c spotify/Propriedades.c -o spotify/Propriedades.o $(CFLAGS)
	gcc -c spotify/Spotify.c -o spotify/Spotify.o $(CFLAGS)
	ar -crs libspotify.a spotify/Artista.o spotify/Menu.o spotify/Musica.o spotify/Playlist.o spotify/Propriedades.o spotify/Spotify.o

maker: libspotify.a main.c
	$(CC) -o main main.c -I spotify -L . -lspotify $(CFLAGS)

run:
	./main data

clean:
	@rm -f main *.a spotify/*.o *.txt

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt -s ./main data
