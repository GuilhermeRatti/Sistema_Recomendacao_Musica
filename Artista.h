#ifndef _ARTISTA_H_
#define _ARTISTA_H_

typedef struct Artista *p_Artista;

/*
    Cria um ponteiro p_Artistas e instancia todos os seus atributos
 
    Retorna um p_Artista
*/
p_Artista artista_cria();

/*
    Le informacoes de um artista de um csv
    As informacoes estao na ordem:

    ID > SEGUIDORES > GENEROS > NOME DO ARTISTA > POPULARIDADE
 */
void artista_le(p_Artista artista, char *linha);

/*
    Recebe como entrada uma TAD artista e uma string de id
    Compara a strind de id do artista com o id recebido

    Caso sejam iguais retorna 1, caso contrario retorna 0
*/
int artista_compara_id(p_Artista artista, char *id, int *achou);

/*************************************************
 *    Funcao que imprime os atributos dos artistas
 *
 *    Nao retorna nada
 **************************************************/
void artista_imprime(p_Artista artista);

void artista_destroi(p_Artista artista);

#endif
