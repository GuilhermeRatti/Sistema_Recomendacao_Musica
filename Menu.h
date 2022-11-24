#ifndef _MENU_H_
#define _MENU_H_
#include "Spotify.h"

/*

    O Menu eh um arquivo separado sem TAD opaca que simplesmente recebe 
    as leituras do usuario e faz chamados de funcoes para o spotify.h 
    de acordo com a necessidade

    A funcao menu_show_options constantemente retorna um INTEIRO para
    saber se o programa continuara sendo executado ou nao
    Se o usuario deseja finalizar o programa, menu_show_options
    retornara 0, para qualquer outra opcao, um chamado de funcao
    sera feito e logo apos sera retornado o valor de 1

*/
int menu_show_options(p_Spotify spotify);

void menu_buscar_musica(p_Spotify spotify);

void menu_lista_musica(p_Spotify spotify);

void menu_playlist_cria(p_Spotify spotify);

void menu_playlist_listar_todas(p_Spotify spotify);

void menu_playlist_listar_uma(p_Spotify spotify);

void menu_playlist_adicionar_musica(p_Spotify spotify);

void menu_gerar_relatorio(p_Spotify spotify);

void menu_recomendar(p_Spotify spotify);
#endif