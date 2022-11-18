#ifndef _ARTISTA_H_
#define _ARTISTA_H_

typedef struct Artista *p_Artista;

p_Artista artista_cria();

void artista_le(p_Artista artista, char *linha);

void artista_destroi(p_Artista artista);

#endif

