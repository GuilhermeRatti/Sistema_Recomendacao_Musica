#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musica.h"

typedef struct Playlist *p_Playlist;

/*
    Recebe como parametro o ponteiro de uma PLAYLIST e de uma MUSICA

    Vai utilizar a funcao propriedade_media_playlist para calcular a media da playlist

    A partir da media da playlist vai calcular a DISTANCIA EUCLIDIANA

    RETORNA A DISTANCIA EUCLIDIANA
*/
double playlist_likeliness(p_Playlist playlist, p_Musica musica);

#endif