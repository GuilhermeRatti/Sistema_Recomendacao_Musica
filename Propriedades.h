#ifndef _PROPRIEDADES_H_
#define _PROPRIEDADES_H_

typedef struct Propriedades *p_Propriedades;



/*
    Nao recebe nada

    Da callocs em todos os atributos

    Retorna um PONTEIRO de propriedades inicializados
*/
p_Propriedades propriedades_cria();


/*
    Recebe como parametro um ponteiro de propriedades vazio 
    e um ponteiro de char sendo a linha a ser lida

    Fragmenta a linha da e vai convertendo as informacoes nela
    e as salvando na struct propriedade que estava vazia

    Retorna o PONTEIRO da struct preenchida
*/
void propriedades_le(p_Propriedades props, char *linha);


/*
    Recebe como parametro ponteiro de propriedades

    Imprime informacoes da struct
*/
void propriedades_imprime(p_Propriedades props);


/*
    Recebe como parametro ponteiro de propriedades

    Da free no ponteiro recebido
*/
void propriedades_destroi(p_Propriedades props);


/*
    Recebe como parametro dois ponteiros de propriedade

    Essa funcao tem somente um return sendo o return da distancia euclidiana entre as duas propriedades

    Retorna um DOUBLE sendo a DISTANCIA EUCLIDIANA
*/
double propriedade_likeliness(p_Propriedades media_playlist, p_Propriedades propriedades_musica);


/*
    Recebe como parametro um vetor de propriedades
    das musicas da playlist e um inteiro de quantidade de musicas

    Essa funcao executa um for loop para passar pelo vetor de propriedades
    e soma cada atributo, acumulando-os em uma nova struct propriedades
    Apos o for loop, divide todos os atributos dessa nova struct propriedades pela qtd de musicas

    Retorna o PONTEIRO da nova struct propriedades armazenando a media das propriedades das musicas na playlist
*/
p_Propriedades propriedade_media_playlist(p_Propriedades *vet_propriedades, int qtd_musicas);

#endif