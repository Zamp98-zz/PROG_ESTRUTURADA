#include "source.h"
typedef struct node{
    Aluno a;
    struct node *prox;
    struct node *anterior;
}Node;

Node *inicio = NULL;
Node *fim = NULL;

void insere(Aluno a)
{
    Node *novo;
    novo = malloc(sizeof(Node));//alocando espaço na memoria para o novo elemento
    novo->a = a;//recebendo o tipo aluno
    novo->prox = NULL;
    //novo->anterior = NULL;
    Node *aux = fim;
    if (inicio == NULL)
        {
            inicio = novo;//aponta para o novo elemento
            fim = novo;
        }
    else if (inicio == fim)//temos 1 elemento
        {
            inicio->prox = novo;
            fim = novo;
        }
    else if (inicio != fim)//temos mais de 1 elemento
        {
            fim->prox = novo;
            fim = novo;
        }
}
void printa()
{
    Node *aux = inicio;
    if(aux == NULL)
        {
            printf("NULL\n");
        }
    else
        {
            do
                {
                    printf("%d %f |", aux->a.matricula, aux->a.cr);
                    aux = aux->prox;
                }while(aux != NULL);
        }
}
