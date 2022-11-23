#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musica.h"
#include "Propriedades.h"

typedef struct Playlist *p_Playlist;

/***************************************************************************************
 *    Recebe como parametro o ponteiro de uma PLAYLIST e de uma MUSICA
 *
 *    A partir da media da playlist vai calcular a DISTANCIA EUCLIDIANA
 *
 *    RETORNA A DISTANCIA EUCLIDIANA
 ****************************************************************************************/
double playlist_likeliness(p_Playlist playlist, p_Musica musica);

p_Playlist playlist_cria();

void playlist_listar_todas(p_Playlist *vetor_playlists, int playlists_qtd);

void playlist_listar_uma(p_Playlist *vetor_playlists, int playlists_qtd, p_Musica *vetor_musicas);

/*
Solicita o índice de uma música e de uma
playlist e adiciona a música a playlist.
*/
void playlist_adicionar_musica(p_Playlist *vet_playlists, int musicas_qtd, int playlists_qtd);

void playlist_gerar_relatorio_musicas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

void playlist_gerar_relatorio_artistas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

/*
    Verifica se a musica esta inclusa na playlist

    Retorna 1 (True) se estiver, e 0 (False) se nao estiver
*/
int playlist_verifica_se_esta_incluso(p_Playlist playlist, int indice);

p_Propriedades playlist_retorna_media_propriedades(p_Playlist playlist, p_Musica *vet_musicas);

/*
A função recebe um ponteiro de playlsit e um arquivo binario

A funcao segue a ordem de leitura:
1 inteiro K que é o tamanho do nome (não contando \0);
K chars compondo o nome da playlist;
1 interio M que representa a quantidade de indexes no vetore de ids;
M inteiros que representam os indexes das musicas.

A playlist passada por referencia armazena os dados
*/
void playlists_ler_bin(p_Playlist *playlist, FILE *arquivo_bin);

/*
A função recebe uma playlsit e um arquivo binario

A funcao alimenta o arquivo com os dados da playlist passsada
seguindo a ordem de escrita:
1 inteiro K que é o tamanho do nome (não contando \0);
K chars compondo o nome da playlist;
1 interio M que representa a quantidade de indexes no vetore de ids;
M inteiros que representam os indexes das musicas.
*/
void playlists_salva_bin(p_Playlist playlist, FILE *arquivo_bin);

void playlist_destroi(p_Playlist playlist);

#endif