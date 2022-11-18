#include <stdio.h>
#include <stdlib.h>
#include "Artistas.h"
#include "Musicas.h"
#include "Playlists.h"
#include "Propriedades.h"
#include "Spotify.h"

int main(int argc, char *argv[])
{
    printf("%s\n",argv[1]);
    p_Spotify sp = spotify_cria();
    // spotify_inicia(sp,argv[1]);
    spotify_destroi(sp);

    return 0;
}