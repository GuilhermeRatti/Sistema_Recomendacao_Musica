#include <stdio.h>
#include <stdlib.h>
#include "Artistas.h"

struct Artista
{
    char id[23];
    int seguidores;
    char **generos;
        int generos_tam;
        int generos_allc;
        int generos_qtd;
    char *nome;
        int nome_tam;
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

p_Artista artista_cria(){
    int i;

    p_Artista art = (p_Artista)calloc(1, sizeof(struct Artista));

    art->generos_allc = 10;
    art->generos_tam = 30;
    art->nome_tam = 30;

    art->generos = (char **)calloc(art->generos_allc, sizeof(char *));

    for ( i = 0; i < art->generos_allc; i++)
    {
        art->generos[i] = (char *)calloc(art->generos_tam, sizeof(char));
    }

    art->nome = (char *)calloc(art->nome_tam, sizeof(char));
    
    return art;
}

void artista_le(p_Artista artista){

}

void artista_destroi(p_Artista artista){

    int i;

    for (i = 0; i < artista->generos_allc; i++)
    {
        free(artista->generos[i]);
    }

    free(artista->generos);
    free(artista->nome);
    free(artista);

}
