#ifndef _PROPRIEDADES_H_
#define _PROPRIEDADES_H_
#include "Musicas.h"

typedef struct Propriedades *p_Propriedades;

/*
    Recebe como parametro dois ponteiros de propriedade
    Um sendo o ponteiro com a media das propriedades da playlist
    Outro sendo o ponteiro das propriedades da musica em questao

    Retorna um DOUBLE sendo a DISTANCIA EUCLIDIANA
*/

double propriedade_likeliness(p_Propriedades media_playlist, p_Propriedades propriedades_musica);

/*
    Recebe como parametro o vetor de musicas da playlist e a quantidade de musicas
    Para cada musica no vetor, vai usar a funcao musica_propriedade_get() para receber os valores de cada propriedade daquela musica
    Calcula a media de cada propriedade e salva em uma estrutura PROPRIEDADE

    Retorna um PONTEIRO p_Propriedades da estrutura PROPRIEDADE criada com as medias
*/
//p_Propriedades propriedade_media_playlist(p_Musicas *vet_musicas, int qtd_musicas);

#endif