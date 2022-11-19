#include <stdio.h>
#include <stdlib.h>
#include "Artista.h"
#include "Playlist.h"
#include "Propriedades.h"
#include "Musica.h"
#include "Spotify.h"

int main(int argc, char *argv[])
{
    p_Spotify sp = spotify_cria();
    spotify_inicia(sp,argv[1]);
    spotify_destroi(sp);

    return 0;
}