#include <stdio.h>
#include <stdlib.h>
#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
#define TRUE 1
#define FALSE 0
typedef struct hero{
    char name[40];
    int power;
}Hero;

int init();
int inserir(Hero h);
int show();
int finish();
int apaga();
int show();
int ler();
int escreve();



#endif // SOURCE_H_INCLUDED
