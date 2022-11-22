#ifndef _MENU_H_
#define _MENU_H_
#include "Spotify.h"

/************************************************************
*    Funcao que lista as opcoes e executa cada uma delas
*
*    Retorna 0 (FINALIZAR) se foi escolido a opcao finalizar
*    Retorna 1 (CONTINUAR) para qualquer outra opcao
*************************************************************/
int menu_show_options(p_Spotify spotify);


/***************************************************************************************
*    Funcao que envia o chamado de buscar musicas por titulo para a biblioteca spotify.h
*
*    Nao retorna nada
****************************************************************************************/
void menu_buscar_musica(p_Spotify spotify);


/************************************************************************
*    Funcao que envia o chamado de buscar uma musica por indice de vetor
*
*    Nao retorna nada
*************************************************************************/
void menu_lista_musica(p_Spotify spotify);


/*****************************************************************
*    Funcao que envia o chamado de criar uma playlist pro spotify
*
*    Nao retorna nada
******************************************************************/
void menu_playlist_cria(p_Spotify spotify);


/*

*/
void menu_playlist_listar_todas(p_Spotify spotify);

void menu_playlist_listar_uma(p_Spotify spotify);

void menu_playlist_adicionar_musica(p_Spotify spotify);


void menu_gerar_relatorio();
#endif