#include <stdio.h>
#include <stdlib.h>

#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
typedef struct aluno{
    int matricula;
    float cr;
}Aluno;
void insere(Aluno a);
void printa();

#endif // SOURCE_H_INCLUDED
