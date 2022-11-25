#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_
#include "Artista.h"
#include "Musica.h"
#include "Playlist.h"
#include "Propriedades.h"

typedef struct Spotify *p_Spotify;

//Inicializa as principais TADs do programa
p_Spotify spotify_cria();

//Inicia o programa carregando os arquivos musica e artista CSV e playlists BIN.
//Ativa a interface de terminal da TAD menu.
//Ao final do programa salva o arquivo de playlists em BIN.
void spotify_inicia(p_Spotify spotify, char path[]);

//Funcao responsavel por ler os arquivos csv de artistas
void arquivo_ler_artista_csv(p_Spotify spotify, char path[]);

//Funcao responsavel por ler os arquivos csv de musicas
void arquivo_ler_musica_csv(p_Spotify spotify, char path[]);

/*
O arquivo binario comecara com um inteiro N representando a quantidade de
playlists salvas seguido de N dados de playlists salvas no seguinte formato:

1 inteiro K que é o tamanho do nome (não contando \0);
K chars compondo o nome da playlist;
1 interio M que representa a quantidade de indexes no vetore de ids;
M inteiros que representam os indexes das musicas.
*/

/*
A função recebe o caminho da pasta de arquivos que contem o arquivo
binario de playlists

A funcao le a qtd N de playists e aloca espaço para elas
A leitura é feita repetindo uma função vinda de playlists N vezes
*/
void arquivo_ler_playlist_bin(p_Spotify spotify, char path[]);

/*
A função recebe o caminho da pasta de arquivos que contem o arquivo
binario de playlists

A funcao salva a qtd N de playists no arquivo binario
O resto da escrita é feita repetindo uma função vinda de playlists N vezes
*/
void arquivo_salvar_playlist_bin(p_Spotify spotify, char path[]);

/*
    Percorre o vetor de musicas da TAD spotify
    Chama a funcao musica_busca_titulo() para cada uma delas

    Nao retorna nem printa nada
*/
void spotify_busca_musica_titulo(p_Spotify spotify);

/*
    Recebe um id (STRING) para printar a musica equivalente a aquele id

    Chama funcoes para printar os atributos de musica e artista
*/
void spotify_lista_musica(p_Spotify spotify, int id);

//Cria uma nova playlist vazia no vetor de playlists 
void spotify_playlist_cria(p_Spotify spotify);

//Lista todas as playlists
void spotify_playlist_listar_todas(p_Spotify spotify);

//Lista uma unica playlist com mais detalhes
void spotify_playlist_listar_uma(p_Spotify spotify);

//Adiciona uma nova musica em uma playlist
void spotify_playlist_adicionar_musica(p_Spotify spotify);

//Gera relatorios de musicas e artistas em playlists
void spotify_gerar_relatorio(p_Spotify spotify);

//Ativa um algoritmo de reomendacao de musicas para um playlist
void spotify_recomendar_musicas(p_Spotify spotify);

//Libera todos as alocacoes de memoria feitas durante o programa
void spotify_destroi(p_Spotify spotify);

#endif