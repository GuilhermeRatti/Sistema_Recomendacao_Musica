#ifndef _MUSICA_H_
#define _MUSICA_H_
#include "Artistas.h"
#include "Propriedades.h"

typedef struct
{                              
    char id[23];               // O id sao 22 caracteres + \0
    char *nome;                // Alocacao dinamica
    int popularidade;          // Um valor entre 0 e 100
    unsigned int duracao_ms;   // Duracao da musica em ms
    int explicito;             // 0 se nao tem conteudo explicito, 1 se tiver
    ARTISTA *vet_artistas;     // Vetor com os artistas da musica
    char *vet_id_art[23];      // Vetor com os ids dos artistas; cada id tem 22 caracteres + \0
    char data_lancamento[11];  // AAAA-MM-DD + \0
    PROPRIEDADES propriedades; // Propriedades da musica
} MUSICAS;


#endif