#include "Spotify.h"
#include "Artistas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Artistas.h"

struct Spotify
{
    p_Artista* vet_artistas;
    int art_alocado;
    int qtd_art;
};

p_Spotify spotify_cria()
{
    p_Spotify sp = (p_Spotify)calloc(1,sizeof(struct Spotify));
    sp->art_alocado = 2;
    sp->vet_artistas = (p_Artista *)calloc(1,sizeof(p_Artista)*sp->art_alocado);

    return sp;
}

void spotify_inicia(p_Spotify spotify, char path[])
{
    arquivo_ler_artista_csv(spotify,path);
}

void arquivo_ler_artista_csv(p_Spotify spotify, char path[])
{
    char caminho[1200];
    sprintf(caminho,"%s/artists_2.csv", path);
    FILE* artcsv = fopen(caminho,"r");

    printf("%s",caminho);
    if(!artcsv)
    {
        printf("ERRO AO ABRIR ARQUIVO ARTISTA.CSV");
        exit(1);
    }
    
    char linha[250];

    while (fscanf(artcsv,"%[^\n]\n",linha)!=EOF)
    {
        if(spotify->qtd_art == spotify->art_alocado)
        {
            spotify->art_alocado*=2;
            spotify->vet_artistas = (p_Artista*)realloc(spotify->vet_artistas,
                                                       (spotify->art_alocado)*sizeof(p_Artista));
        }
        spotify->vet_artistas[spotify->qtd_art] = artista_cria();
        artista_le(spotify->vet_artistas[spotify->qtd_art],linha);
        spotify->qtd_art++;
    }
    
    fclose(artcsv);
}

void arquivo_ler_musica_csv(char path[]);

void arquivo_ler_playlist_bin(char path[]);

void arquivo_salvar_playlist_bin(char path[]);

void spotify_destroi(p_Spotify spotify)
{
    for(int i = 0; i<spotify->qtd_art; i++)
    { 
        artista_destroi(spotify->vet_artistas[i]);
    }
    free(spotify->vet_artistas);
    free(spotify);
}
