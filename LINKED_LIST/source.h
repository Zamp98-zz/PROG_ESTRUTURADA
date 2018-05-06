#include <stdio.h>
#include <stdlib.h>
#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
#define TRUE 1
#define FALSE 0
typedef struct aluno{
    int matricula;
    float cr;
}Aluno;
void insere(Aluno a);
#endif // SOURCE_H_INCLUDED
