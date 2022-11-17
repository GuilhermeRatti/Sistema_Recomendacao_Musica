#include "Artistas.h"

struct Artista
{
    char id[23];
    int seguidores;
    char *generos[30];
    char *nome;
    int popularidade;
};

/*
id: id do artista na base do Spotify;
Seguidores: Número de seguidores;
Generos: Uma lista de generos associados ao artista. Observe que por ser uma lista, deverá tratar
diferentemente;
Nome do artista;
Popularidade: Popularidade do artista entre 0 e 10
*/