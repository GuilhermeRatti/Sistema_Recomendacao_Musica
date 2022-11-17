#include "Playlists.h"
#include "Musicas.h"
#include "Propriedades.h"

struct Playlists
{
    char *nome;
    int qtd_musicas;
    int qtd_alocado;
    p_Musicas *vet_musicas;
};

