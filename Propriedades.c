#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propriedades.h"
#include "Musica.h"
#include <math.h>

struct Propriedades
{
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int time_signature;
};

p_Propriedades propriedades_cria(){
    p_Propriedades p = (p_Propriedades)calloc(1, sizeof(struct Propriedades));
    return p;
}

void propriedades_le(p_Propriedades props, char *linha){
    //atribuicao da propriedades em ordem
    props->danceability = atof(strtok_r(linha,";",&linha));

    props->energy = atof(strtok_r(linha,";",&linha));
    
    props->key = atoi(strtok_r(linha,";",&linha));

    props->loudness = atof(strtok_r(linha,";",&linha));

    props->mode = atoi(strtok_r(linha,";",&linha));
    
    props->speechiness = atof(strtok_r(linha,";",&linha));
    
    props->acousticness = atof(strtok_r(linha,";",&linha));
    
    props->instrumentalness = atof(strtok_r(linha,";",&linha));
    
    props->liveness = atof(strtok_r(linha,";",&linha));
    
    props->valence = atof(strtok_r(linha,";",&linha));
    
    props->tempo = atof(strtok_r(linha,";",&linha));
    
    props->time_signature = atoi(strtok_r(linha,";",&linha));
        
}

void propriedades_imprime(p_Propriedades props){
    //
    printf("Danceability: %f\nEnergy: %f\nKey: %d\nLoudness: %f\nMode: %d\nSpeechiness: %f\nAcousticness: %f\nInstrumentalness: %f\nLiveness: %f\nValence: %f\nTempo: %f\nTime Signature: %d\n",
    props->danceability,    
    props->energy,          
    props->key,             
    props->loudness,        
    props->mode,            
    props->speechiness,
    props->acousticness,     
    props->instrumentalness,
    props->liveness,       
    props->valence,         
    props->tempo,           
    props->time_signature); 
}

void propriedades_destroi(p_Propriedades props){
    free(props);
}

double propriedade_likeliness(p_Propriedades media_playlist, p_Propriedades propriedades_musica)
{
    return sqrt(pow(propriedades_musica->acousticness - media_playlist->acousticness,2)+
                pow(propriedades_musica->danceability - media_playlist->danceability,2)+
                pow(propriedades_musica->energy - media_playlist->energy,2)+
                pow(propriedades_musica->instrumentalness - media_playlist->instrumentalness,2)+
                pow(propriedades_musica->liveness - media_playlist->liveness,2)+
                pow(propriedades_musica->valence - media_playlist->valence,2)+
                pow(propriedades_musica->mode - media_playlist->mode,2)+
                pow(propriedades_musica->speechiness - media_playlist->speechiness,2));
}

p_Propriedades propriedade_media_playlist(p_Propriedades *vet_propriedades, int qtd_musicas)
{
    int i;
    p_Propriedades media = propriedades_cria();

    for(i=0;i<qtd_musicas;i++)
    {
        media->acousticness += vet_propriedades[i]->acousticness;
        media->danceability += vet_propriedades[i]->danceability;
        media->energy += vet_propriedades[i]->energy;
        media->instrumentalness += vet_propriedades[i]->instrumentalness;
        media->key += vet_propriedades[i]->key;
        media->liveness += vet_propriedades[i]->liveness;
        media->loudness += vet_propriedades[i]->loudness;
        media->mode += vet_propriedades[i]->mode;
        media->speechiness += vet_propriedades[i]->speechiness;
        media->tempo += vet_propriedades[i]->tempo;
        media->time_signature += vet_propriedades[i]->time_signature;
        media->valence += vet_propriedades[i]->valence;
    }

    media->acousticness /= qtd_musicas;
    media->danceability /= qtd_musicas;
    media->energy /= qtd_musicas;
    media->instrumentalness /= qtd_musicas;
    media->key /= qtd_musicas;
    media->liveness /= qtd_musicas;
    media->loudness /= qtd_musicas;
    media->mode /= qtd_musicas;
    media->speechiness /= qtd_musicas;
    media->tempo /= qtd_musicas;
    media->time_signature /= qtd_musicas;
    media->valence /= qtd_musicas;

    return media;
}