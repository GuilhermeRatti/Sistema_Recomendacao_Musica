#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Spotify.h"

enum OPCOES
{
    BUSCAR_MUSICA = 1,
    LISTAR_MUSICA = 2,
    CRIAR_PLAYLIST = 3,
    LISTAR_TODAS_PLAYLISTS = 4,
    LISTAR_PLAYLIST = 5,
    ADICIONAR_MSC_PLAYLIST = 6,
    RECOMENDAR_MUSICA = 7,
    RELATORIO = 8,
    //FINALIZAR JA FOI DECLARADO COMO ZERO ANTERIORMENTE NO SPOTIFY
};

int menu_show_options(p_Spotify spotify)
{
    int opt;

    system("clear");

    printf("=====================================================\n                       Spotify\n=====================================================\n\n");

    printf("Digite uma das opcoes:\n");
    printf("%s%s%s%s%s%s%s%s%s",
            "   1 - Buscar musica\n",
            "   2 - Listar uma musica\n",
            "   3 - Criar uma playlist\n",
            "   4 - Listar playlists\n",
            "   5 - Listar uma playlist\n",
            "   6 - Adicionar uma musica na playlist\n",
            "   7 - Recomendar musicas parecidas com uma playlist\n",
            "   8 - Gerar Relatorio\n",
            "   0 - Finalizar o programa\n\n");

    printf("OPCAO: ");
    scanf("%d", &opt);

    system("clear");

    if(opt==BUSCAR_MUSICA)
    {
        menu_buscar_musica(spotify);
        return 1;
    }
    else if(opt == LISTAR_MUSICA)
    {
        menu_lista_musica(spotify);
        return 1;
    }
    else if (opt == CRIAR_PLAYLIST)
    {
        menu_playlist_cria(spotify);
        return 1;
    }
    else if (opt == LISTAR_TODAS_PLAYLISTS)
    {
        menu_playlist_listar_todas(spotify);
        return 1;
    }
    else if (opt == LISTAR_PLAYLIST)
    {
        menu_playlist_listar_uma(spotify);
        return 1;
    }
    else if (opt == ADICIONAR_MSC_PLAYLIST)
    {
        menu_playlist_adicionar_musica(spotify);
        return 1;
    }
    else
    {
        return 0;
    }
}

void menu_buscar_musica(p_Spotify spotify)
{
    char *str;
    char ch;
    int tam_text=0,tam_allc=30;
    printf("Digite o que deseja buscar em musicas: ");
    str = (char*)calloc(1,sizeof(char)*tam_allc);

    // While para ler o texto digitado caractere por caractere para
    // Possibilitar realocacao de espaco quando necessario
    scanf("\n%c", &ch);
    while (ch!='\n')
    {
        if((tam_text+1)==tam_allc)
        {
            tam_allc*=2;
            str = (char*)realloc(str,sizeof(char)*tam_allc);
        }

        str[tam_text] = ch;
        tam_text++;
        scanf("%c", &ch);
    }
    
    spotify_busca_musica_titulo(spotify,str);

    free(str);
}

void menu_lista_musica(p_Spotify spotify)
{
    int id_no_vet;

    printf("Digite o indice da musica desejada: ");
    scanf("%d",&id_no_vet);



    spotify_lista_musica(spotify,id_no_vet);
}

void menu_playlist_cria(p_Spotify spotify){
    spotify_playlist_cria(spotify);
}

void menu_playlist_listar_todas(p_Spotify spotify){
    spotify_playlist_listar_todas(spotify);
}

void menu_playlist_listar_uma(p_Spotify spotify){
    spotify_playlist_listar_uma(spotify);
}

void menu_playlist_adicionar_musica(p_Spotify spotify){
    spotify_playlist_adicionar_musica(spotify);
}