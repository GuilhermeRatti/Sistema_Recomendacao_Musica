#ifndef _PROPRIEDADES_H_
#define _PROPRIEDADES_H_

typedef struct Propriedades *p_Propriedades;

/*
*    Recebe como parametro dois ponteiros de propriedade
*    Um sendo o ponteiro com a media das propriedades da playlist
*    Outro sendo o ponteiro das propriedades da musica em questao
*
*    Retorna um DOUBLE sendo a DISTANCIA EUCLIDIANA
*/

//Inicialização do ponteiro da estrutura propriedade
p_Propriedades propriedades_cria();

//Leitura das propriedades atraves de uma string
void propriedades_le(p_Propriedades props, char *linha);

//Impressão das propriedades
void propriedades_imprime(p_Propriedades props);
    
//Liberacao do ponteiro de propriedades
void propriedades_destroi(p_Propriedades props);

/*Calculo da distancia euclidiana entre a media das propriedades de uma playlist e as propriedades de uma musica.
*
*    Recebe como parametro o vetor de musicas da playlist e a quantidade de musicas;
*    Para cada musica no vetor, vai usar a funcao musica_propriedade_get() para receber os valores de cada propriedade daquela musica;
*    Calcula a media de cada propriedade e salva em uma estrutura PROPRIEDADE.
*
*    Retorna um PONTEIRO p_Propriedades da estrutura PROPRIEDADE criada com as medias.
*/
double propriedade_likeliness(p_Propriedades media_playlist, p_Propriedades propriedades_musica);

/*
*    Recebe um vetor de propriedades das musicas vindo de uma playlist junto da quantidade de musicas nesse vetor.
*    Retorna um ponteiro de propriedades que contem a media de cada propriedade dentre as musicas.
*/
p_Propriedades propriedade_media_playlist(p_Propriedades *vet_propriedades, int qtd_musicas);


#endif