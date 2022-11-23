#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Playlist.h"
#include "Musica.h"
#include "Propriedades.h"
#include "Spotify.h"

#define valor_alloc_nome 1

struct Playlist
{
    char *nome;
    int nome_allc;
    int *vet_musicas;
    int musicas_qtd;
};

// Solicita o nome de uma playlist e a adiciona em um array.
p_Playlist playlist_cria()
{
    p_Playlist plist = (p_Playlist)calloc(1, sizeof(struct Playlist));

    plist->nome = (char *)calloc(valor_alloc_nome + 1, sizeof(char));
    plist->vet_musicas = (int *)calloc(plist->musicas_qtd, sizeof(int));

    char char_atual;
    int char_contador = 0;

    printf("Informe o nome desejado para a Playlist: ");
    scanf("\n%c", &char_atual);
    while (char_atual == '\n' || char_atual == ' ')
    {
        printf("\nNOME INVALIDO\n");
        scanf("%c", &char_atual);
    }
    while (char_atual != '\n')
    {
        if ((char_contador + 1) > plist->nome_allc)
        {
            plist->nome_allc += valor_alloc_nome;
            plist->nome = (char *)realloc(plist->nome, (1 + plist->nome_allc) * sizeof(char));
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
void playlist_listar_todas(p_Playlist *vetor_playlists, int playlists_qtd)
{
    int i;

    if (playlists_qtd == 0)
    {
        printf("Nao ha playlists!");
    }
    else
    {
        printf("####################### PLAYLISTS #######################\n");
        for (i = 0; i < playlists_qtd; i++)
        {
            printf("\nPlaylist de indice %d - '%s' - Contem %d musicas!", i, vetor_playlists[i]->nome, vetor_playlists[i]->musicas_qtd);
        }
    }

    printf("\n\nPressione enter para voltar para o menu principal!");
    fgetc(stdin);
    scanf("%*[^\n]%*c");
}

/*
Solicita que o usuário digite o indice da playlist e apresenta na
tela o nome da playlist e os títulos das músicas que ela possui.
*/
void playlist_listar_uma(p_Playlist *vetor_playlists, int playlists_qtd, p_Musica *vetor_musicas)
{
    int i = -1, j = 0, indx;

    if (playlists_qtd == 0)
    {
        printf("Nao ha playlists!");
    }
    else
    {
        printf("\nInforme o indice da playlist a ser exibida: ");
        scanf("%d", &i);

        while (i < 0 || i > playlists_qtd - 1)
        {
            printf("\nNUMERO INVALIDO!\n\n");

            printf("\nInforme o indice da playlist a ser exibida: ");
            scanf("%d", &i);
        }

        if (vetor_playlists[i]->musicas_qtd == 0)
        {
            printf("\nA playlist %d - '%s' - nao contem musicas!", i, vetor_playlists[i]->nome);
        }
        else
        {
            printf("\nMusicas da Playlist: '%s'\n", vetor_playlists[i]->nome);

            for (j = 0; j < vetor_playlists[i]->musicas_qtd; j++)
            {
                indx = vetor_playlists[i]->vet_musicas[j];
                printf("> %s\n", musica_retorna_nome(vetor_musicas[indx]));
            }

            printf("\n");
        }
    }

    printf("\n\nPressione enter para voltar para o menu principal!");
    fgetc(stdin);
    scanf("%*[^\n]%*c");
}

void playlist_adicionar_musica(p_Playlist *vet_playlists, int musicas_qtd, int playlists_qtd)
{

    int indx_musica, indx_playlist;

    if (playlists_qtd == 0)
    {
        printf("Nao ha playlists!");
    }
    else
    {
        printf("\nInforme o indice da musica a ser adicionada: ");
        scanf("%d", &indx_musica);

        while (indx_musica < 0 || indx_musica > musicas_qtd - 1)
        {
            printf("\nNUMERO INVALIDO!\n\n");

            printf("Informe o indice da musica a ser adicionada: ");
            scanf("%d", &indx_musica);
            printf("\n");
        }

        printf("Informe o indice da playlist em que a musica eh adicionada: ");
        scanf("%d", &indx_playlist);

        while (indx_playlist < 0 || indx_playlist > playlists_qtd - 1)
        {
            printf("\nNUMERO INVALIDO!\n\n");

            printf("Informe o indice da playlist em que a musica eh adicionada: ");
            scanf("%d", &indx_playlist);
        }

        // verificacao de musica ja adicionada
        int i, flag_ja_adicionada = 0;
        for (i = 0; i < vet_playlists[indx_playlist]->musicas_qtd; i++)
        {
            if (vet_playlists[indx_playlist]->vet_musicas[i] == indx_musica)
            {
                flag_ja_adicionada = 1;
                break;
            }
        }

        if (flag_ja_adicionada)
        {
            printf("\nMusica ja adicionada!");
        }
        else
        {
            vet_playlists[indx_playlist]->musicas_qtd++;
            int qtd_atual = vet_playlists[indx_playlist]->musicas_qtd;

            vet_playlists[indx_playlist]->vet_musicas = (int *)realloc(vet_playlists[indx_playlist]->vet_musicas, qtd_atual * sizeof(int));

            vet_playlists[indx_playlist]->vet_musicas[qtd_atual - 1] = indx_musica;

            printf("\nMusica adicionada com sucesso!");
        }
    }

    printf("\n\nPressione enter para voltar para o menu principal!");
    fgetc(stdin);
    scanf("%*[^\n]%*c");
}

void playlist_gerar_relatorio_musicas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas)
{
    int i, j, k, musicas_relatorio_qtd = 0, flag_adicionada = 0;

    int *musicas_indx = calloc(0, sizeof(int));
    int *musicas_aparicoes = calloc(0, sizeof(int));

    for (i = 0; i < playlists_qtd; i++)
    {
        for (j = 0; j < vet_playlists[i]->musicas_qtd; j++)
        {
            flag_adicionada = 0;

            for (k = 0; k < musicas_relatorio_qtd; k++)
            {
                if (vet_playlists[i]->vet_musicas[j] == musicas_indx[k])
                {
                    musicas_aparicoes[k]++;
                    flag_adicionada = 1;
                    break;
                }
            }

            if (!flag_adicionada)
            {
                musicas_relatorio_qtd++;
                musicas_indx = realloc(musicas_indx, musicas_relatorio_qtd * sizeof(int));
                musicas_aparicoes = realloc(musicas_aparicoes, musicas_relatorio_qtd * sizeof(int));

                musicas_indx[musicas_relatorio_qtd - 1] = vet_playlists[i]->vet_musicas[j];
                musicas_aparicoes[musicas_relatorio_qtd - 1] = 1;
            }
        }
    }

    if (musicas_relatorio_qtd == 0)
    {
        printf("Nao ha musicas em nenhuma playlist...\nRelatorio de musicas cancelado!\n\n");
    }
    else
    {
        FILE *relatorio_musicas = fopen("Relatorio_Playlists_Musicas.txt", "w");

        int primeira_maior_aparicao = 0;
        int segunda_maior_aparicao = 0;
        int proxima_maior_aparicao = 0;

        for (i = 0; i < musicas_relatorio_qtd; i++)
        {
            if (primeira_maior_aparicao < musicas_aparicoes[i])
            {
                segunda_maior_aparicao = primeira_maior_aparicao;
                primeira_maior_aparicao = musicas_aparicoes[i];
            }
        }

        fprintf(relatorio_musicas, "==========================================Relatorio das Musicas==========================================\n\n");

        do
        {
            proxima_maior_aparicao = segunda_maior_aparicao;
            segunda_maior_aparicao = 0;

            for (i = 0; i < musicas_relatorio_qtd; i++)
            {
                if (primeira_maior_aparicao == musicas_aparicoes[i])
                {
                    fprintf(relatorio_musicas, "> Existem %d playlists contem a musica '%s'.\n", musicas_aparicoes[i], musica_retorna_nome(vet_musicas[musicas_indx[i]]));
                }
                else if (segunda_maior_aparicao < musicas_aparicoes[i] && musicas_aparicoes[i] < proxima_maior_aparicao)
                {
                    segunda_maior_aparicao = musicas_aparicoes[i];
                }
            }
            primeira_maior_aparicao = proxima_maior_aparicao;
        } while (proxima_maior_aparicao != 0);

        printf("Relatorio de musicas gerado com sucesso!\n");

        fclose(relatorio_musicas);
    }

    free(musicas_indx);
    free(musicas_aparicoes);
}

void playlist_gerar_relatorio_artistas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas_spotify)
{
    int i, j, k, l, artistas_relatorio_qtd = 0, flag_adicionada = 0, playlist_musica_artistas_qtd = 0, musica_atual_id = 0;

    char **artistas_id = calloc(0, sizeof(char *));
    char **artistas_nome = calloc(0, sizeof(char *));
    int *artistas_aparicoes = calloc(0, sizeof(int));

    char **vet_playlist_artistas_ids;
    char **vet_playlist_artistas_nomes;

    // para cada playlist
    for (i = 0; i < playlists_qtd; i++)
    {
        // para cada musica na playlist
        for (j = 0; j < vet_playlists[i]->musicas_qtd; j++)
        {
            musica_atual_id = vet_playlists[i]->vet_musicas[j];

            playlist_musica_artistas_qtd = musica_retorna_id_artistas(vet_musicas_spotify[musica_atual_id], &vet_playlist_artistas_ids);
            musica_retorna_nome_artistas(vet_musicas_spotify[musica_atual_id], &vet_playlist_artistas_nomes);

            // para cada artista nas musicas da playlist
            for (k = 0; k < playlist_musica_artistas_qtd; k++)
            {
                flag_adicionada = 0;

                for (l = 0; l < artistas_relatorio_qtd; l++)
                {
                    if (strcmp(vet_playlist_artistas_ids[k], artistas_id[l]) == 0)
                    {
                        artistas_aparicoes[l]++;
                        flag_adicionada = 1;
                        break;
                    }
                }

                if (!flag_adicionada)
                {
                    artistas_relatorio_qtd++;
                    artistas_id = realloc(artistas_id, artistas_relatorio_qtd * sizeof(char *));
                    artistas_nome = realloc(artistas_nome, artistas_relatorio_qtd * sizeof(char *));
                    artistas_aparicoes = realloc(artistas_aparicoes, artistas_relatorio_qtd * sizeof(int));

                    artistas_id[artistas_relatorio_qtd - 1] = vet_playlist_artistas_ids[k];
                    artistas_nome[artistas_relatorio_qtd - 1] = vet_playlist_artistas_nomes[k];
                    artistas_aparicoes[artistas_relatorio_qtd - 1] = 1;
                }
            }
        }
    }

    if (artistas_relatorio_qtd == 0)
    {
        printf("Nao ha musicas em nenhuma playlist...\nRelatorio de artistas cancelado!\n\n");
    }
    else
    {
        FILE *relatorio_artistas = fopen("Relatorio_Playlists_Artistas.txt", "w");

        int primeira_maior_aparicao = 0;
        int segunda_maior_aparicao = 0;
        int proxima_maior_aparicao = 0;

        for (i = 0; i < artistas_relatorio_qtd; i++)
        {
            if (primeira_maior_aparicao < artistas_aparicoes[i])
            {
                segunda_maior_aparicao = primeira_maior_aparicao;
                primeira_maior_aparicao = artistas_aparicoes[i];
            }
        }

        fprintf(relatorio_artistas, "==========================================Relatorio de Artistas==========================================\n\n");

        do
        {
            proxima_maior_aparicao = segunda_maior_aparicao;
            segunda_maior_aparicao = 0;

            for (i = 0; i < artistas_relatorio_qtd; i++)
            {
                if (primeira_maior_aparicao == artistas_aparicoes[i])
                {
                    fprintf(relatorio_artistas, "> Estão adicionadas em playlist %d musicas que mencionam '%s' [%s]\n", artistas_aparicoes[i], artistas_nome[i], artistas_id[i]);
                }
                if (segunda_maior_aparicao < artistas_aparicoes[i] && artistas_aparicoes[i] < proxima_maior_aparicao)
                {
                    segunda_maior_aparicao = artistas_aparicoes[i];
                }
            }
            primeira_maior_aparicao = proxima_maior_aparicao;
        } while (proxima_maior_aparicao != 0);

        fclose(relatorio_artistas);

        printf("Relatorio de artistas gerado com sucesso!\n");
    }

    free(artistas_id);
    free(artistas_nome);
    free(artistas_aparicoes);
}

int playlist_verifica_se_esta_incluso(p_Playlist playlist, int indice)
{
    int i;
    for (i = 0; i < playlist->musicas_qtd; i++)
    {
        if (playlist->vet_musicas[i] == indice)
            return 1;
    }
    return 0;
}

/*
O arquivo binario comecara com um inteiro N representando a quantidade de
playlists salvas seguido de N dados de playlists salvas no seguinte formato:

1 inteiro K que é o tamanho do nome (não contando \0);
K chars compondo o nome da playlist;
1 interio M que representa a quantidade de indexes no vetore de ids;
M inteiros que representam os indexes das musicas.
*/

void playlists_ler_bin(p_Playlist *playlist, FILE *arquivo_bin)
{
    *playlist = (p_Playlist)calloc(1, sizeof(struct Playlist));

    fread(&((*playlist)->nome_allc), sizeof(int), 1, arquivo_bin);

    (*playlist)->nome = (char *)calloc((*playlist)->nome_allc + 1, sizeof(char));
    fread((*playlist)->nome, sizeof(char), (*playlist)->nome_allc, arquivo_bin);
    (*playlist)->nome[(*playlist)->nome_allc + 1] = '\0';

    fread(&((*playlist)->musicas_qtd), sizeof(int), 1, arquivo_bin);

    (*playlist)->vet_musicas = (int *)calloc((*playlist)->musicas_qtd, sizeof(int));
    fread((*playlist)->vet_musicas, sizeof(int), (*playlist)->musicas_qtd, arquivo_bin);
}

void playlists_salva_bin(p_Playlist playlist, FILE *arquivo_bin)
{

    fwrite(&playlist->nome_allc, sizeof(int), 1, arquivo_bin);
    fwrite(playlist->nome, sizeof(char), playlist->nome_allc, arquivo_bin);
    fwrite(&playlist->musicas_qtd, sizeof(int), 1, arquivo_bin);
    fwrite(playlist->vet_musicas, sizeof(int), playlist->musicas_qtd, arquivo_bin);
}

p_Propriedades playlist_retorna_media_propriedades(p_Playlist playlist, p_Musica *vet_musica)
{
    p_Propriedades vet_propriedades[playlist->musicas_qtd];
    int i;
    for (i = 0; i < playlist->musicas_qtd; i++)
    {
        vet_propriedades[i] = musica_retorna_propriedade(vet_musica[playlist->vet_musicas[i]]);
    }

    p_Propriedades media = propriedade_media_playlist(vet_propriedades, playlist->musicas_qtd);

    return media;
}

void playlist_destroi(p_Playlist playlist)
{
    free(playlist->nome);
    free(playlist->vet_musicas);

    free(playlist);
}
