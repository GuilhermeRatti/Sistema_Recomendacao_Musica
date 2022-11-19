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

    musica->nome_allc = 20;

    musica->nome = (char *)calloc(musica->nome_allc + 1, sizeof(char));
    
    musica->artistas_qtd = 0;

    musica->vet_art_id = (char**)calloc(musica->artistas_qtd, sizeof(char));
    musica->vet_art_nome = (char**)calloc(musica->artistas_qtd, sizeof(char));

    musica->propriedades = propriedades_cria();
   
    return musica;
}

void musica_le(p_Musica musica, char *linha)
{
    char *holder,*hold_art;
    int i=0;

    //atribuicao do id 
    i=0;
    holder = strtok_r(linha,";",&linha);
    
    while(holder[i])
    {
        musica->id[i] = holder[i];
        i++; 
    }
    musica->id[i]='\0';

    //atribuicao do nome da musica

    i=0;
    holder = strtok_r(linha,";",&linha);
   
    int numChars=0;
    while (holder[numChars])
    {
        if((numChars+1)>musica->nome_allc)
        {
            musica->nome_allc += 20;
            musica->nome = (char*)realloc(musica->nome, (1+musica->nome_allc)*sizeof(char));
        }
        musica->nome[numChars] = holder[numChars];
        numChars++;
    }

    musica->nome[numChars] = '\0';

    //atribuicao da popularidade
    musica->popularidade = atoi(strtok_r(linha,";",&linha));
    
    //atribuicao da duracao
    musica->duracao_ms = atoi(strtok_r(linha,";",&linha));
    
    //atribuicao do indicador de conteudo explicito
    musica->explicito = atoi(strtok_r(linha,";",&linha));
    
    //atribuicao dos nomes de artistas no vet de nomes
    i=0;
    holder = strtok_r(linha,";",&linha);

    int contador_chars = 20;

    while ((hold_art=strtok_r(holder,"|",&holder)))
    {
        
        contador_chars = 20;
        
        musica->artistas_qtd += 1;
        musica->vet_art_nome = (char**)realloc(musica->vet_art_nome, musica->artistas_qtd*sizeof(char*));
        musica->vet_art_id = (char**)realloc(musica->vet_art_id, musica->artistas_qtd*sizeof(char*));

        musica->vet_art_nome[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*(contador_chars+1));
        musica->vet_art_id[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*23);

        //atribuição dos caracteres para a string atual do vetor de nomes de artistas
        i=0;
        while (hold_art[i])
        {
            if (i+1>contador_chars)
            {
                contador_chars += 20;
                musica->vet_art_nome[musica->artistas_qtd-1] = (char*)realloc(musica->vet_art_nome[musica->artistas_qtd-1], sizeof(char)*(contador_chars+1));
            }
            
            musica->vet_art_nome[musica->artistas_qtd-1][i] = hold_art[i];
            i++;
        }
        musica->vet_art_nome[musica->artistas_qtd-1][i] = '\0';
        
    }

    //atribuicao dos ids de artistas no vet de ids
    i=0;
    holder = strtok_r(linha,";",&linha);

    while ((hold_art=strtok_r(holder,"|",&holder)))
    {   
        int contador=0; //contador de ids (vai se igualar a qtd_artistas) 

        //realocação para cada novo artista é feita no passo anterior

        //atribuição dos caracteres para a string atual do vetor de nome de artistas
        i=0;
        while (hold_art[i])
        {
            musica->vet_art_id[contador][i] = hold_art[i];
            i++;
        }
        musica->vet_art_id[contador][i] = '\0';

        contador++;
    }

    //atribuicao da data de lancamento
    i=0;
    holder = strtok_r(linha,";",&linha);

    while(holder[i])
    {
        musica->data_lancamento[i] = holder[i];
        i++; 
    }
    
    musica->data_lancamento[i]='\0';

    //atribuicao das propriedades

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
