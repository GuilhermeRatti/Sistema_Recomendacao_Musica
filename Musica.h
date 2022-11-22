#ifndef _MUSICA_H_
#define _MUSICA_H_
#include "Propriedades.h"

typedef struct Musica *p_Musica;

p_Musica musica_cria();

/*****************************************************
*    Funcao que le os dados de uma musica em uma linha
*
*    Os dados estao na ordem de:
*    ID > NOME > POPULARIDADE > DURACAO > EXPLICITO
*    > ARTISTAS > ID ARTISTAS > DATA > PROPRIEDADES
******************************************************/
void musica_le(p_Musica musica, char *linha);


/*?????????????????????????????????????????????????????
*??????? Pra que q isso serve matheus ?????????????????
*?????????????????????????????????????????????????????*/
void musica_le_artistas(p_Musica musica, char* holder_nome, char* holder_id);

/***************************************************************
*    Verifica se a string digitada str[] esta contida no titulo
*    
*    Caso esteja, chama a funcao musica_imprime_informacoes()
****************************************************************/
void musica_busca_titulo(p_Musica musica, char *str, int id_no_vet);

/*************************************************************************************
*    Imprime os atributos da musica de indice "id_no_vet"
*    com excessao das informacoes referente aos artistas, que sera feita separadamente
**************************************************************************************/
void musica_imprime_informacoes(p_Musica musica, int id_no_vet);


/*******************************************************************************************
*    Funcao que ira alterar a variavel artistas_id_out por referencia para que
*    seja possivel retornar varios resultados (vetor de ids - que sao strings - de artistas)
*
*    Retorna um inteiro sendo a quantidade de artistas
********************************************************************************************/
int musica_retorna_id_artistas(p_Musica musica, char ***artistas_id_out);

/*******************************************************************************************
*    Funcao que ira alterar a variavel artistas_nome_out por referencia para que
*    seja possivel retornar varios resultados (vetor de nomes - que sao strings - de artistas)
*
*    Retorna um inteiro sendo a quantidade de artistas
********************************************************************************************/
int musica_retorna_nome_artistas(p_Musica musica, char ***artistas_nome_out);


/************************************************************************************************
*    Funcao para cobrir casos em que o artista esta registrado na musica, mas nao esta registrado 
*    no arquivo de artistas.csv, ou seja, a unica informacao disponivel dele eh o nome e o id, 
*    que estao armazenadas na musica
*
*    EXEMṔLO: Musica de indice 468778 do arquivo tracks_full.csv
*************************************************************************************************/
void musica_imprime_artista_inexistente(p_Musica musica,int index);


/***************************************************
*   Funcao que retorna o nome da musica requisitada
*
*   A variavel retornada eh um ponteiro de char 
****************************************************/
char *musica_retorna_id(p_Musica musica);


/***************************************************
*    Funcao que retorna o nome da musica requisitada
*
*    A variavel retornada eh um ponteiro de char
****************************************************/
char *musica_retorna_nome(p_Musica musica);

/*********************************************************************
*    Funcao que retorna a quantidade de artistas da musica requisitada
*
*    A variavel retornada eh um inteiro
**********************************************************************/
int musica_retorna_qtd_artistas(p_Musica musica);

/*****************************************************
*    Recebe um ponteiro de musica como parametro
*    
*    Retorna o PONTEIRO de PROPRIEDADE daquela musica
******************************************************/
p_Propriedades musica_propriedade_get(p_Musica musica);


void musica_destroi(p_Musica musica);

#endif