#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define MAX 50
typedef struct mercadoria{
    char nome[MAX];
    float preco;
}Mercadoria;
int init();
int finish();
int insere_ordenado(Mercadoria m);
int sai();
int proximo();
int anterior();
#endif // SOURCE_H_INCLUDED
