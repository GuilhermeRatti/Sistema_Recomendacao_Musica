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