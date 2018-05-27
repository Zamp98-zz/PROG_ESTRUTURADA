#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#define MAX 50

#define TRUE 1
#define FALSE 0
typedef struct aluno{
    char nome[MAX];
    int idade;
}Aluno;
int inicializa();
int finaliza();
int insereAluno(Aluno a);
int retira();
int nodeProximo();
int nodeAnterior();
void imprime();

#endif // SOURCE_H_INCLUDED
