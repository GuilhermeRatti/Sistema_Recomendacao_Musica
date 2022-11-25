#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Musica.h"
#include "Propriedades.h"

typedef struct Playlist *p_Playlist;

/*
 *    Recebe como parametro o ponteiro de uma playlist e de uma musica
 *
 *    A partir da media da playlist vai calcular a distancia euclidiana
 *
 *    retorna a distancia euclidiana
 */
double playlist_likeliness(p_Playlist playlist, p_Musica musica);

/*
Solicita o nome de uma playlist e a adiciona em um array.
*/
p_Playlist playlist_cria();

/*
Recebe um vetor de playlists e a quantidade de playlists no vetor

Exibe os dados de todas as playlists, uma por linha. Para cada playlist, deve ser exibido
o índice da playlist no array, o nome da playlist e o número de músicas que ela possui.
*/
void playlist_listar_todas(p_Playlist *vetor_playlists, int playlists_qtd);

/*
Recebe um vetor de playlists e a quantidade de playlists no vetor e o vetor de musicas

Solicita que o usuário digite o indice da playlist e apresenta na
tela o nome da playlist e os títulos das músicas que ela possui.
*/
void playlist_listar_uma(p_Playlist *vetor_playlists, int playlists_qtd, p_Musica *vetor_musicas);

/*
Solicita o índice de uma música e de uma playlist e adiciona a música na playlist.
*/
void playlist_adicionar_musica(p_Playlist *vet_playlists, int musicas_qtd, int playlists_qtd);

/*
Recebe como argumentos o vetor de playlists, a quantidade de playlists e o vetor de musicas

Organiza dois vetores que funcionam em paralelo:
Vetor de indices (contem os indices das musicas que aparecem em playlists)
Vetor de aparicoes (contem os respectivos numeros de vezes que as musicas de certo indice aparecem em playlists)

A partir desse vetores se percorre o vetor de aparicoes passando por todas as quantidades de apracições diferentes servindo como
parametro de escrita para a escrita dos nomes das musicas a partir do vetor de indices
*/
void playlist_gerar_relatorio_musicas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

/*
Recebe como argumentos o vetor de playlists, a quantidade de playlists e o vetor de musicas

Organiza tres vetores que funcionam em paralelo:
Vetor de nomes (contem os nomes dos artistas que aparecem em playlists)
Vetor de ids (contem os ids dos artistas que aparecem em playlists)
Vetor de aparicoes (contem os respectivos numeros de vezes que as musicas de certo indice aparecem em playlists)

A partir desses vetores se percorre o vetor de aparicoes passando por todas as quantidades de apracições diferentes servindo como
parametro de escrita para a escrita dos nomes e ids dos artistas a partir do vetor de nomes e ids;
*/
void playlist_gerar_relatorio_artistas(p_Playlist *vet_playlists, int playlists_qtd, p_Musica *vet_musicas);

/*
Verifica se a musica esta inclusa na playlist

Retorna 1 (True) se estiver, e 0 (False) se nao estiver
*/
int playlist_verifica_se_esta_incluso(p_Playlist playlist, int indice);

/*
Retorna media das propriedades das musicas contidas em uma playlist

Se retornar um ponteiro NULL eh porque a playlist nao possui musicas
*/
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

// libera alocacoes de memoria da playlist
void playlist_destroi(p_Playlist playlist);

#endif