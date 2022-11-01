#ifndef _ARTISTA_H_
#define _ARTISTA_H_

typedef struct
{
    char id[23];
    int seguidores;
    char **generos;
    char *nome;
    int popularidade;
} ARTISTA;

#endif