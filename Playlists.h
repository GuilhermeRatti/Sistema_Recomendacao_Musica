#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musicas.h"

typedef struct Playlists *p_Playlists;

/*
    Recebe como parametro o ponteiro de uma PLAYLIST e de uma MUSICA

    Vai utilizar a funcao propriedade_media_playlist para calcular a media da playlist

    A partir da media da playlist vai calcular a DISTANCIA EUCLIDIANA

    RETORNA A DISTANCIA EUCLIDIANA
*/
double playlist_likeliness(p_Playlists playlist, p_Musicas musica);

#endif