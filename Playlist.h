#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musica.h"
#include "Propriedades.h"

typedef struct Playlist *p_Playlist;

/***************************************************************************************
*    Recebe como parametro o ponteiro de uma PLAYLIST e de uma MUSICA
*
*    A partir da media da playlist vai calcular a DISTANCIA EUCLIDIANA
*
*    RETORNA A DISTANCIA EUCLIDIANA
****************************************************************************************/
double playlist_likeliness(p_Playlist playlist, p_Musica musica);

p_Playlist playlist_cria();

void playlist_listar_todas(p_Playlist* vetor_playlists, int playlists_qtd);

void playlist_listar_uma(p_Playlist* vetor_playlists, int playlists_qtd, p_Musica* vetor_musicas);

void playlist_adicionar_musica(p_Playlist *vet_playlists, int musicas_qtd, int playlists_qtd);

void playlist_gerar_relatorio_musicas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

void playlist_gerar_relatorio_artistas(p_Playlist * vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

/*
    Verifica se a musica esta inclusa na playlist

    Retorna 1 (True) se estiver, e 0 (False) se nao estiver
*/
int playlist_verifica_se_esta_incluso(p_Playlist playlist, int indice);

p_Propriedades playlist_retorna_media_propriedades(p_Playlist playlist, p_Musica *vet_musicas);

void playlist_destroi(p_Playlist playlist);

#endif