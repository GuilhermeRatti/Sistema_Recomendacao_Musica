#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_
#include "Artistas.h"
#include "Musicas.h"
#include "Playlists.h"
#include "Propriedades.h"

typedef struct Spotify *p_Spotify;

p_Spotify spotify_cria();

void spotify_inicia(p_Spotify spotify, char path[]);

void arquivo_ler_artista_csv(p_Spotify spotify,char path[]);

p_Artista* spotify_artista_realoca(p_Artista* vet_artista, int qtd_alocado);

void arquivo_ler_musica_csv(p_Spotify spotify, char path[]);

void arquivo_ler_playlist_bin(char path[]);

void arquivo_salvar_playlist_bin(char path[]);

void spotify_destroi(p_Spotify spotify);

#endif