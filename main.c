#include <stdio.h>
#include <stdlib.h>
#include "Artistas.h"
#include "Musicas.h"
#include "Playlists.h"
#include "Propriedades.h"


int main(){

    p_Artista art = artista_cria();
    artista_destroi(art);

    return 0;
}