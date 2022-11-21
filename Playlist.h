#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musica.h"

typedef struct Playlist *p_Playlist;

/*
*    Recebe como parametro o ponteiro de uma PLAYLIST e de uma MUSICA
*
*    Vai utilizar a funcao propriedade_media_playlist para calcular a media da playlist
*
*    A partir da media da playlist vai calcular a DISTANCIA EUCLIDIANA
*
*    RETORNA A DISTANCIA EUCLIDIANA
*/
double playlist_likeliness(p_Playlist playlist, p_Musica musica);

p_Playlist playlist_cria();

void playlist_listar_todas(p_Playlist* vetor_playlists, int playlists_qtd);

void playlist_listar_uma(p_Playlist* vetor_playlists, int playlists_qtd, p_Musica* vetor_musicas);

void playlist_adicionar_musica(p_Playlist *vet_playlists, int musicas_qtd, int playlists_qtd);

void playlist_destroi(p_Playlist playlist);

#endif