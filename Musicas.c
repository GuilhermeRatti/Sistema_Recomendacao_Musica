#include <stdio.h>
#include <stdlib.h>
#include "Artistas.h"
#include "Propriedades.h"
#include "Musicas.h"

struct Musicas
{                              
    char id[23];               // O id sao 22 caracteres + \0
    char *nome;                // Alocacao dinamica
        int nome_tam;
    
    int popularidade;          // Um valor entre 0 e 100
    unsigned int duracao_ms;   // Duracao da musica em ms
    int explicito;             // 0 se nao tem conteudo explicito, 1 se tiver
    
    char **vet_art_nome;   // Vetor com os artistas da musica
    char **vet_art_id;      // Vetor com os ids dos artistas; cada id tem 22 caracteres + \0
        int qtd_artistas;
    
    char data_lancamento[11];  // AAAA-MM-DD + \0
    p_Propriedades propriedades; // Propriedades da musica
};

p_Propriedades musica_propriedade_get(p_Musicas musica);

/*
id: id spotify da track
nome: nome da música
popularity: Popularidade da música entre 0 e 100
duracao_ms: Duração da música em ms
explicit: Se contem conteudo explicito ou não
artists: Listas de artistas que criaram a musica
id_artists: id dos artistas que criaram a música
data de lançamento
*/