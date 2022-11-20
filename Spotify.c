#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Spotify.h"
#include "Artista.h"
#include "Musica.h"
#include "Playlist.h"
#include "Propriedades.h"
#include "Menu.h"

struct Spotify
{
    p_Artista* vet_artistas;
        int art_alocado;
        int art_qtd;

    p_Musica* vet_musicas;
        int msc_alocado;
        int msc_qtd;

    p_Playlist* vet_playlists;
        int pls_alocado;
        int pls_qtd;

};

p_Spotify spotify_cria()
{
    //alocamento da TAD principal
    p_Spotify sp = (p_Spotify)calloc(1,sizeof(struct Spotify));
    
    //alocamento do Vetor de Artistas
    sp->art_alocado = 500;
    sp->vet_artistas = (p_Artista *)calloc(1, sizeof(p_Artista)*sp->art_alocado);

    //alocamento do Vetor de Musicas
    sp->msc_alocado = 500;
    sp->vet_musicas = (p_Musica *)calloc(1, sizeof(p_Musica)*sp->msc_alocado);

    return sp;
}


void spotify_inicia(p_Spotify spotify, char path[])
{
    arquivo_ler_artista_csv(spotify, path);
    arquivo_ler_musica_csv(spotify, path);

    OPCOES_DO_MENU opt;
    while (1)
    {
        opt = menu_show_options(spotify);

        if(opt == FINALIZAR)
        {
            break;
        }
    }
    
}

void arquivo_ler_artista_csv(p_Spotify spotify, char path[])
{
    char caminho[1000];
    sprintf(caminho,"%s/artists_full.csv", path);
    FILE* artcsv = fopen(caminho,"r");

    if(!artcsv)
    {
        printf("ERRO AO ABRIR ARQUIVO CSV DOS ARTISTAS\n");
        exit(1);
    }
    
    char linha[250];

    while (fscanf(artcsv,"%[^\n]\n",linha)!=EOF)
    {
        if(spotify->art_qtd == spotify->art_alocado)
        {
            spotify->art_alocado*=2;
            spotify->vet_artistas = (p_Artista*)realloc(spotify->vet_artistas,
                                                       (spotify->art_alocado)*sizeof(p_Artista));
        }
        spotify->vet_artistas[spotify->art_qtd] = artista_cria();
        artista_le(spotify->vet_artistas[spotify->art_qtd],linha);
        spotify->art_qtd++;
    }
    
    fclose(artcsv);
}

void arquivo_ler_musica_csv(p_Spotify spotify, char path[]){
    char caminho[1000];
    sprintf(caminho,"%s/tracks_full.csv", path);
    FILE* msccsv = fopen(caminho,"r");

    if(!msccsv)
    {
        printf("ERRO AO ABRIR ARQUIVO CSV DAS MUSICAS\n");
        exit(1);
    }
    
    char linha[3000];
    
    while (fscanf(msccsv,"%[^\n]\n",linha)!=EOF)
    {
        if(spotify->msc_qtd == spotify->msc_alocado)
        {
            spotify->msc_alocado*=2;
            spotify->vet_musicas = (p_Musica*)realloc(spotify->vet_musicas,
                                                       (spotify->msc_alocado)*sizeof(p_Musica));
        }
        spotify->vet_musicas[spotify->msc_qtd] = musica_cria();
        musica_le(spotify->vet_musicas[spotify->msc_qtd],linha);
        spotify->msc_qtd++;
        
    }
    
    fclose(msccsv);
}

void arquivo_ler_playlist_bin(char path[]);

void arquivo_salvar_playlist_bin(char path[]);

void spotify_busca_musica_titulo(p_Spotify spotify,char *str)
{
    int i;
    // Loop que vai passar por todas as musicas do spotify
    for(i=0;i<spotify->msc_qtd;i++)
    {
        musica_busca_titulo(spotify->vet_musicas[i], str, i);
    }

    printf("\nPressione enter para voltar para o menu principal!");
    scanf("%*[^\n]\n");
}

void spotify_lista_musica(p_Spotify spotify, int id)
{
    musica_imprime_informacoes(spotify->vet_musicas[id], id);
    char **artistas_out;
    int qtd_artistas;
    qtd_artistas = musica_retorna_id_artistas(spotify->vet_musicas[id], &artistas_out);
    
    int i = 0,j;
    int achou=0; // variavel booleana (0 ou 1) para cobrir casos em que o artista nao exista no artists.csv
    printf("|# Informacoes dos artistas:\n");
    // Loop que vai passar por todos os artistas da musica
    for(i=0;i<qtd_artistas;i++)
    {
        j=0;
        achou=0;
        // Loop que vai ficar rodando no vetor que contem todos os artistar ate achar o artista que tem aquele id
        while(!(artista_compara_id(spotify->vet_artistas[j], artistas_out[i], &achou)))
        {
            if(j==(spotify->art_qtd-1))
                break;
            j++;
        }
        if(achou)
            artista_imprime(spotify->vet_artistas[j]);
        else
            musica_imprime_artista_inexistente(spotify->vet_musicas[id],i);
    }

    if(i==0)
    {
        printf("Essa musica nao possui nenhum artista registrado :/\n");
    }

    printf("\nPressione enter para voltar para o menu principal!");
    fgetc(stdin);
    scanf("%*[^\n]\n");
}

void spotify_destroi(p_Spotify spotify)
{
    for(int i = 0; i<spotify->art_qtd; i++)
    { 
        artista_destroi(spotify->vet_artistas[i]);
    }
    free(spotify->vet_artistas);
    
    for(int i = 0; i<spotify->msc_qtd; i++)
    { 
        musica_destroi(spotify->vet_musicas[i]);
    }
    free(spotify->vet_musicas);
    
    free(spotify);
}
