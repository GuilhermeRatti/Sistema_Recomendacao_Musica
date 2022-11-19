#ifndef _MUSICA_H_
#define _MUSICA_H_
#include "Propriedades.h"

typedef struct Musica *p_Musica;

/*
    Recebe um ponteiro de musica como parametro
    
    Retorna o PONTEIRO de PROPRIEDADE daquela musica
*/
//p_Propriedades musica_propriedade_get(p_Musicas musica);

p_Musica musica_cria();

void musica_le(p_Musica musica, char *linha);

void musica_destroi(p_Musica musica);

//p_Propriedades musica_propriedade_get(p_Musica musica);

#endif