#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Artista.h"

struct Artista
{
    char id[23];
    int seguidores;
    char **generos;
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

    art->generos_allc = 0;
    art->nome_tam = 20;

    art->generos = (char **)calloc(art->generos_allc, sizeof(char *));

    for (i = 0; i < art->generos_allc; i++)
    {
        art->generos[i] = (char *)calloc(50, sizeof(char));
    }

    art->nome = (char *)calloc((1 + art->nome_tam), sizeof(char));
    
    return art;
}

void artista_le(p_Artista artista, char *linha)
{
    char *holder,*genero;
    int i=0;

    //atribuicao do id
    holder = strtok_r(linha,";",&linha);
    while(holder[i])
    {
        artista->id[i] = holder[i];
        i++; 
    }
    artista->id[i]='\0';

    //atribuicao do numero de seguidores
    artista->seguidores = atoi(strtok_r(linha,";",&linha));
    

    //atribuicao dos gneros no vet de generos
    holder = strtok_r(linha,";",&linha);

    while ((genero=strtok_r(holder,"|",&holder)))
    {
        //vrificação de genero nulo
        if (!strcmp(genero, "-"))
        {
            break;
        }
        
        //realocação para cada novo genero (por questões de eficiencia)
        if(artista->generos_qtd==artista->generos_allc)
        {
            artista->generos_allc += 1;
            artista->generos = (char**)realloc(artista->generos, artista->generos_allc*sizeof(char*));

            for(i=artista->generos_qtd;i<artista->generos_allc;i++)
            {
                artista->generos[i] = (char*)calloc(1, sizeof(char)*50);
            }
        }

        //atribuição dos caractees para a string atual do vetor de generos[]
        i=0;
        while (genero[i])
        {
            artista->generos[artista->generos_qtd][i] = genero[i];
            i++;
        }
        artista->generos[artista->generos_qtd][i] = '\0';
        
        artista->generos_qtd++;
    }

    //atribuicao do nome
    holder = strtok_r(linha,";",&linha);
    
    i=0;
    int numChars=0;
    while (holder[numChars])
    {
        if((numChars+1)>artista->nome_tam)
        {
            artista->nome_tam += 20;
            artista->nome = (char*)realloc(artista->nome, (1+artista->nome_tam)*sizeof(char));
        }
        artista->nome[numChars] = holder[numChars];
        numChars++;
    }

    artista->nome[numChars] = '\0';

    //atribuicao da popularidade
    artista->popularidade = atoi(strtok_r(linha,"\0",&linha));
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
