#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Musica.h"
#include "Propriedades.h"
#include <ctype.h>

/*
id: id spotify da track
nome: nome da música
popularity: Popularidade da música entre 0 e 100
duracao_ms: Duração da música em ms
explicit: Se contem conteudo explicito ou não
artists: Listas de artistas que criaram a musica
id_artists: id dos artistas que criaram a música
data de lançamento
*/

#define valor_alloc_nome 20
#define valor_alloc_id 23

struct Musica
{                              
    char id[23];               // O id sao 22 caracteres + \0
    char *nome;                // Alocacao dinamica
        int nome_allc;
    
    int popularidade;          // Um valor entre 0 e 100
    unsigned int duracao_ms;   // Duracao da musica em ms
    int explicito;             // 0 se nao tem conteudo explicito, 1 se tiver
    
    char **vet_art_nome;       // Vetor com os artistas da musica
    char **vet_art_id;         // Vetor com os ids dos artistas; cada id tem 22 caracteres + \0
        int artistas_qtd;

    
    char data_lancamento[11];    // AAAA-MM-DD + \0
    p_Propriedades propriedades; // Propriedades da musica
};

p_Musica musica_cria()
{
    p_Musica musica = (p_Musica)calloc(1, sizeof(struct Musica));

    musica->nome_allc = valor_alloc_nome;

    musica->nome = (char *)calloc(musica->nome_allc + 1, sizeof(char));

    //alocacao do primeiro artista
    musica->vet_art_id = (char**)calloc(1, sizeof(char*));
    musica->vet_art_nome = (char**)calloc(1, sizeof(char*));

    musica->vet_art_nome[0] = (char*)calloc((valor_alloc_nome+1), sizeof(char));
    musica->vet_art_id[0] = (char*)calloc(valor_alloc_id, sizeof(char));
    
    musica->propriedades = propriedades_cria();
   
    return musica;
}

void musica_le(p_Musica musica, char *linha)
{
    char *holder, *holder_2, *holder_artista_nome, *holder_artista_id;
    int i=0;

    //--> Parte de atribuicao do id da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
    
    while(holder[i])
    {
        musica->id[i] = holder[i];
        i++; 
    }
    musica->id[i]='\0';

    //--> Parte de atribuicao do nome da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
   
    int contador_chars=0;
    while (holder[contador_chars])
    {

        if((contador_chars+1)>musica->nome_allc)
        {
            musica->nome_allc += valor_alloc_nome;
            musica->nome = (char*)realloc(musica->nome, (1+musica->nome_allc)*sizeof(char));
        }

        musica->nome[contador_chars] = holder[contador_chars];
        contador_chars++;
    }

    musica->nome[contador_chars] = '\0';

    //--> Parte de atribuicao da popularidade da musica <=
    musica->popularidade = atoi(strtok_r(linha,";",&linha));
    
    //--> Parte de atribuicao da duracao da musica <=
    musica->duracao_ms = atoi(strtok_r(linha,";",&linha));
    
    //--> Parte de atribuicao do indicador de conteudo explicito da musica <=
    musica->explicito = atoi(strtok_r(linha,";",&linha));
    
    //--> Parte de atribuicao dos nomes e ids de artistas nos seus respectivos vets da musica <=
    i=0;
    holder = strtok_r(linha,";",&linha);
    holder_2 = strtok_r(linha,";",&linha);

    //OSB: O numero de nomes de artistas e de ids de artistas é SEMPRE o mesmo, isso possibilita o mesmo while para as duas atribuicoes 
    while ((holder_artista_nome = strtok_r(holder,"|",&holder)) && (holder_artista_id=strtok_r(holder_2,"|",&holder_2)))
    {
        contador_chars = valor_alloc_nome;
        //-> Sub-parte de alocacao de um novo artista
        musica->artistas_qtd++;

        if(musica->artistas_qtd > 1){
            musica->vet_art_nome = (char**)realloc(musica->vet_art_nome, musica->artistas_qtd*sizeof(char*));
            musica->vet_art_id = (char**)realloc(musica->vet_art_id, musica->artistas_qtd*sizeof(char*));

            musica->vet_art_nome[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*(valor_alloc_nome+1));
            musica->vet_art_id[musica->artistas_qtd-1] = (char*)calloc(1, sizeof(char)*valor_alloc_id);
        }        
        
        //-> Sub-parte de atribuição dos caracteres para a string atual do vetor de nomes de artistas
        i=0;
        while (holder_artista_nome[i])
        {
            if (i+1>contador_chars)
            {
                contador_chars += valor_alloc_nome;
                
                musica->vet_art_nome[musica->artistas_qtd-1] = (char*)realloc(musica->vet_art_nome[musica->artistas_qtd-1], sizeof(char)*(contador_chars+1));
            }
            
            musica->vet_art_nome[musica->artistas_qtd-1][i] = holder_artista_nome[i];
            i++;
        }
        musica->vet_art_nome[musica->artistas_qtd-1][i] = '\0';
        
        //-> Sub-parte de atribuicao dos ids de artistas no vet de ids
        i=0;
        while (holder_artista_id[i])
        {
            musica->vet_art_id[musica->artistas_qtd-1][i] = holder_artista_id[i];
            i++;
        }
        musica->vet_art_id[musica->artistas_qtd-1][i] = '\0';

    }

    //--> Atribuicao da data de lancamento <=
    i=0;
    holder = strtok_r(linha,";",&linha);

    while(holder[i])
    {
        musica->data_lancamento[i] = holder[i];
        i++; 
    }
    
    musica->data_lancamento[i]='\0';

    //--> Atribuicao das propriedades <=
    propriedades_le(musica->propriedades, linha);

}

void musica_busca_titulo(p_Musica musica, char *str, int id_no_vet)
{
    int i=0,k=0;
    int matched=0; //variavel booleana (0 ou 1) para verificar se o titulo esta contido

    //Loop que vai passar por todos os caracteres do titulo da musica ate identificar se a string esta contida no titulo (ou nao)
    
    while(musica->nome[i])
    {
        if(toupper(str[0])==toupper(musica->nome[i])) // Transforma ambos os caracteres em upper pra nao ter diferenca entre minusculo e maiusculo
        {
            k=0;
            matched=1;
            while(str[k]) // Quando eh verificado que algum char do titulo eh igual com o primeiro char da string digitada
                          // Verifica com esse while se todas os caracteres seguintes sao iguais, ate o fim da string digitada
            {
                if(!(musica->nome[i+k]) ||
                   toupper(musica->nome[i+k]) != toupper(str[k]))
                {
                    matched=0;
                    break;
                }
                k++;
            }
        }

        if(matched==1)
        {
            break;
        }
        i++;
    }

    if(matched == 1)
    {
        printf("%d | %s | %s", id_no_vet,musica->id,musica->nome);

        int i;
        for(i=0;i<musica->artistas_qtd;i++)
        {
            printf(" | %s", musica->vet_art_nome[i]);
        }

        printf("\n");
    }
}

void musica_imprime_informacoes(p_Musica musica, int id)
{
    printf("\n\n|##########################################\n");
    printf("|######### BUSCA DE MUSICA POR ID #########\n");
    printf("|##########################################\n");
    printf("|#\n|# Informacoes da musica na posicao %d no vetor: \n", id);
    printf("|#   --> Id: %s\n|#   -->Nome: %s\n|#   -->Popularidade: %d\n", musica->id, musica->nome, musica->popularidade);

    // Transforma a duracao em ms para minutos:segundos
    int minutos = (int)(musica->duracao_ms/60000);
    int segundos = (int)(musica->duracao_ms/1000)/*Isso da no TOTAL de segundos*/ - minutos*60 /*conversao de minutos para segundos*/;
    printf("|#   --> Duracao: %d Minutos e %d segundos\n", minutos,segundos);

    // Verifica se eh explicito ou nao e imprime uma string (sim/nao)
    if(musica->explicito==0)
    {
        printf("|#   --> Explicito: Nao\n");
    }
    else
    {
        printf("|#   --> Explicito: Sim\n");
    }

    // Imprimindo data
    printf("|#   --> Data de lancamento: %s\n", musica->data_lancamento);

    // Artistas vao ser imprimidos separadamente
}

void musica_imprime_artista_inexistente(p_Musica musica,int index)
{
    printf("|#   %s\n",musica->vet_art_nome[index]);
    printf("|#      --> Nenhuma informacao foi encontrada sobre esse artista :(\n");
}

int musica_retorna_id_artistas(p_Musica musica, char ***artistas_id_out)
{
    (*artistas_id_out) = musica->vet_art_id;
    return musica->artistas_qtd;
}

int musica_retorna_nome_artistas(p_Musica musica, char ***artistas_nome_out)
{
    (*artistas_nome_out) = musica->vet_art_nome;
    return musica->artistas_qtd;
}

char *musica_retorna_id(p_Musica musica){
    return musica->id;
}

char *musica_retorna_nome(p_Musica musica){
    return musica->nome;
}

int musica_retorna_qtd_artistas(p_Musica musica){
    return musica->artistas_qtd;
}

void musica_destroi(p_Musica musica)
{
    int i;

    for (i = 0; i < musica->artistas_qtd; i++)
    {
        free(musica->vet_art_id[i]);
        free(musica->vet_art_nome[i]);
    }

    free(musica->vet_art_id);
    free(musica->vet_art_nome);

    free(musica->nome);

    propriedades_destroi(musica->propriedades);

    free(musica);
}



p_Propriedades musica_retorna_propriedade(p_Musica musica){
    return musica->propriedades;
}
