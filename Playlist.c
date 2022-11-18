#include <stdio.h>
#include <stdlib.h>
#include "Playlist.h"
#include "Musica.h"
#include "Propriedades.h"

struct Playlist
{
    char *nome;
    int qtd_musicas;
    int qtd_alocado;
    p_Musica *vet_musicas;
};

