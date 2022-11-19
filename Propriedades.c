#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propriedades.h"

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
    return (p_Propriedades)calloc(1, sizeof(struct Propriedades));
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
/*
danceability: [0, 1]
energy: [0, 1]
key: nota maior [0: C, 1: C#/Db, 2: D, …]
loudness: em db
mode: 0 se minor e 1 se major
speechiness: [0,1]
acousticness: [0,1]
instrumentalness: [0,1]
liveness:[0,1]
valence: [0,1]
tempo: BPM
time_signature
*/