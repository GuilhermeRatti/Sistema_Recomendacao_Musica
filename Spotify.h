#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_
#include "Artista.h"
#include "Musica.h"
#include "Playlist.h"
#include "Propriedades.h"

typedef struct Spotify *p_Spotify;

typedef enum 
{
    CONTINUAR = 1,
    FINALIZAR = 0
}OPCOES_DO_MENU;

p_Spotify spotify_cria();

void spotify_inicia(p_Spotify spotify, char path[]);

void arquivo_ler_artista_csv(p_Spotify spotify,char path[]);

p_Artista* spotify_artista_realoca(p_Artista* vet_artista, int qtd_alocado);

void arquivo_ler_musica_csv(p_Spotify spotify, char path[]);

void arquivo_ler_playlist_bin(char path[]);

void arquivo_salvar_playlist_bin(char path[]);


/*
*    Percorre o vetor de musicas da TAD spotify
*    Chama a funcao musica_busca_titulo() para cada uma delas
*
*    Nao retorna nem printa nada
*/
void spotify_busca_musica_titulo(p_Spotify spotify, char *str);


/*
*    Recebe um id (STRING) para printar a musica equivalente a aquele id
*
*    Chama funcoes para printar os atributos de musica e artista
*/
void spotify_lista_musica(p_Spotify spotify, int id);

void spotify_playlist_cria(p_Spotify spotify);

void spotify_playlist_listar_todas(p_Spotify spotify);

void spotify_playlist_listar_uma(p_Spotify spotify);

void spotify_playlist_adicionar_musica(p_Spotify spotify);

void spotify_destroi(p_Spotify spotify);

#endif