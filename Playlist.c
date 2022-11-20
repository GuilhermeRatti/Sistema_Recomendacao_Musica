#include <stdio.h>
#include <stdlib.h>
#include "Playlist.h"
#include "Musica.h"
#include "Propriedades.h"

#define valor_alloc_nome 20

struct Playlist
{
    char *nome;
        int nome_allc;
    int *vet_musicas;
        int musicas_qtd;
        int musicas_allc;
};

//Solicita o nome de uma playlist e a adiciona em um array.
p_Playlist playlist_cria(){
    p_Playlist plist = (p_Playlist)calloc(1, sizeof(struct Playlist));

    plist->nome = (char *)calloc(valor_alloc_nome+1, sizeof(char));
    plist->vet_musicas = (int *)calloc(plist->musicas_qtd, sizeof(int));

    char char_atual;
    int char_contador=0;

    printf("Informe o nome desejado para a Playlist: ");
    scanf("%c", &char_atual);
    while (char_atual == '\n')
    {
        printf("NOME INVALIDO");
        scanf("%c", &char_atual);
    }
    while (char_atual != '\n')
    {
        if((char_contador+1)>plist->nome_allc)
        {
            plist->nome_allc += valor_alloc_nome;
            plist->nome = (char*)realloc(plist->nome, (1+plist->nome_allc)*sizeof(char));
        }
        
        plist->nome[char_contador] = char_atual;
        
        char_contador++;
        scanf("%c", &char_atual);
    }

    plist->nome[char_contador] = '\0';

    return plist;
}
/*
Exibe os dados de todas as playlists, uma por linha. Para cada playlist, deve ser exibido 
o índice da playlist no array, o nome da playlist e o número de músicas que ela possui.
*/
void playlist_listar_todas(p_Playlist* vetor_playlists, int qtd_pls){
    int i;

    for (i = 0; i < qtd_pls; i++)
    {
        printf("Playlis nº %d: '%s'\nContem %d musicas!\n\n", i,vetor_playlists[i]->nome,vetor_playlists[i]->musicas_qtd);
    }
    
}

/*
Solicita que o usuário digite o indice da playlist e apresenta na 
tela o nome da playlist e os títulos das músicas que ela possui.
*/
void playlist_listar_uma(p_Playlist* vetor_playlists, int qtd_pls, p_Musica* vetor_musicas){
    int i=-1, j=0, indx;

    printf("Informe o indice da playlist a ser exibida: ");
    scanf("%d", &i);
    printf("\n");

    while (i<0 || i>qtd_pls-1)
    {
        printf("\nNUMERO INVALIDO!\n\n");

        printf("Informe o indice da playlist a ser exibida: ");
        scanf("%d", &i);
        printf("\n");
    }

    printf("\nMusicas da Playlist: '%s'\n", vetor_playlists[i]->nome);

    for (j = 0; j < vetor_playlists[i]->musicas_qtd; j++)
    {
        indx = vetor_playlists[i]->vet_musicas[j];
        printf("> %s\n", musica_retorna_nome(vetor_musicas[indx]));
    }
    
    printf("\n");
}
/*
Solicita o índice de uma música e de uma 
playlist e adiciona a música a playlist.
*/
void playlist_adicionar_musica(p_Playlist *vet_playlists, int indx_playlist, int qtd_musicas){
    
    int indx_musica;

    printf("Informe o indice da musica a ser adicionada: ");
    scanf("%d", &indx_musica);
    printf("\n");

    while (indx_musica<0 || indx_musica>qtd_musicas-1)
    {
        printf("\nNUMERO INVALIDO!\n\n");

        printf("Informe o indice da musica a ser adicionada: ");
        scanf("%d", &indx_musica);
        printf("\n");
    }

    vet_playlists[indx_playlist]->musicas_qtd++;
    int qtd_atual = vet_playlists[indx_playlist]->musicas_qtd;

    vet_playlists[indx_playlist]->vet_musicas = (int *)realloc(vet_playlists[indx_playlist]->vet_musicas, qtd_atual*sizeof(int));

    vet_playlists[indx_playlist]->vet_musicas[qtd_atual-1] = indx_musica;
}

void playlist_destroi(p_Playlist plist){
    free(plist->nome);
    free(plist->vet_musicas);
    
    free(plist);
}




