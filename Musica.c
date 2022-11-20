#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Musica.h"
#include "Propriedades.h"
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

#define valor_alloc_nome 20
#define valor_alloc_id 23

struct Musica
{                              
    char id[23];               // O id sao 22 caracteres + \0
    char *nome;                // Alocacao dinamica
        int nome_allc;
    
    int popularidade;          // Um valor entre 0 e 100
    unsigned int duracao_ms;   // Duracao da musica em ms
    int explicito;             // 0 se nao tem conteudo explicito, 1 se tiver
    
    char **vet_art_nome;   // Vetor com os artistas da musica
    char **vet_art_id;      // Vetor com os ids dos artistas; cada id tem 22 caracteres + \0
        int artistas_qtd;

    
    char data_lancamento[11];  // AAAA-MM-DD + \0
    p_Propriedades propriedades; // Propriedades da musica
};

p_Musica musica_cria()
{
    p_Musica musica = (p_Musica)calloc(1, sizeof(struct Musica));

    musica->nome_allc = valor_alloc_nome;

    musica->nome = (char *)calloc(musica->nome_allc + 1, sizeof(char));
    
    musica->artistas_qtd = 0;

    musica->vet_art_id = (char**)calloc(musica->artistas_qtd, sizeof(char));
    musica->vet_art_nome = (char**)calloc(musica->artistas_qtd, sizeof(char));

    musica->propriedades = propriedades_cria();
   
    return musica;
}

void musica_le(p_Musica musica, char *linha)
{
    char *holder, *holder_2, *holder_artista_nome, *holder_artista_id;
    int i=0;

    //=> Parte de atribuicao do id da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
    
    while(holder[i])
    {
        musica->id[i] = holder[i];
        i++; 
    }
    musica->id[i]='\0';

    //=> Parte de atribuicao do nome da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
   
    int contador_chars=0;
    while (holder[contador_chars])
    {

        if((contador_chars+1)>musica->nome_allc)
        {
            musica->nome_allc += valor_alloc_nome;
            musica->nome = (char*)realloc(musica->nome, (1+musica->nome_allc)*sizeof(char));
        }

        musica->nome[contador_chars] = holder[contador_chars];
        contador_chars++;
    }

    musica->nome[contador_chars] = '\0';

    //=> Parte de atribuicao da popularidade da musica <=
    musica->popularidade = atoi(strtok_r(linha,";",&linha));
    
    //=> Parte de atribuicao da duracao da musica <=
    musica->duracao_ms = atoi(strtok_r(linha,";",&linha));
    
    //=> Parte de atribuicao do indicador de conteudo explicito da musica <=
    musica->explicito = atoi(strtok_r(linha,";",&linha));
    
    //=> Parte de atribuicao dos nomes e ids de artistas nos seus respectivos vets da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
    holder_2 = strtok_r(linha,";",&linha);

    //OSB: O numero de nomes de artistas e de ids de artistas é SEMPRE o mesmo, isso possibilita o mesmo while para as duas atribuicoes 
    while ((holder_artista_nome = strtok_r(holder,"|",&holder)) && (holder_artista_id=strtok_r(holder_2,"|",&holder_2)))
    {
        contador_chars = valor_alloc_nome;
        //-> Sub-parte de alocacao de um novo artista

        musica->artistas_qtd++;
        musica->vet_art_nome = (char**)realloc(musica->vet_art_nome, musica->artistas_qtd*sizeof(char*));
        musica->vet_art_id = (char**)realloc(musica->vet_art_id, musica->artistas_qtd*sizeof(char*));

        musica->vet_art_nome[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*(valor_alloc_nome+1));
        musica->vet_art_id[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*valor_alloc_id);

        //variavel contendo o ponteiro do nome e id do artista atual (para fins esteticos):
        char *artista_atual_nome = musica->vet_art_nome[musica->artistas_qtd-1];
        char *artista_atual_id = musica->vet_art_id[musica->artistas_qtd-1];
        
        //-> Sub-parte de atribuição dos caracteres para a string atual do vetor de nomes de artistas
        i=0;
        while (holder_artista_nome[i])
        {
            if (i+1>contador_chars)
            {
                contador_chars += valor_alloc_nome;
                
                musica->vet_art_nome[musica->artistas_qtd-1] = (char*)realloc(musica->vet_art_nome[musica->artistas_qtd-1], sizeof(char)*(contador_chars+1));
                artista_atual_nome = musica->vet_art_nome[musica->artistas_qtd-1];
            }
            
            artista_atual_nome[i] = holder_artista_nome[i];
            i++;
        }

        artista_atual_nome = '\0';
        
        //-> Sub-parte de atribuicao dos ids de artistas no vet de ids
        i=0;
        while (holder_artista_id[i])
        {
            artista_atual_id[i] = holder_artista_id[i];
            i++;
        }
        artista_atual_id[i] = '\0';

    }

    //=> Atribuicao da data de lancamento <=
    i=0;
    holder = strtok_r(linha,";",&linha);

    while(holder[i])
    {
        musica->data_lancamento[i] = holder[i];
        i++; 
    }
    
    musica->data_lancamento[i]='\0';

    //=> Atribuicao das propriedades <=
    propriedades_le(musica->propriedades, linha);

}


void musica_destroi(p_Musica musica)
{
    int i;

    for (i = 0; i < musica->artistas_qtd; i++)
    {
        free(musica->vet_art_id[i]);
        free(musica->vet_art_nome[i]);
    }

    free(musica->vet_art_id);
    free(musica->vet_art_nome);

    free(musica->nome);

    propriedades_destroi(musica->propriedades);

    free(musica);
}



/*p_Propriedades musica_propriedade_get(p_Musica musica){
    return musica->propriedades;
}*/
