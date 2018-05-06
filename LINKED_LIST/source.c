#include "source.h"
typedef struct node{
    Aluno a;
    struct aluno *prox;
}Node;
Node *inicio = NULL;

void insere(Aluno a)
{
    Node *novo;
    novo = malloc(sizeof(Node));
    novo->a = a;
    novo->prox = NULL;
    if(inicio == NULL)
        {
            inicio = novo;
            novo->prox = NULL;
        }
    else
        {
            novo->prox = inicio;
            inicio = novo;
        }
    //return TRUE;
}
void imprime()
{
    Node *aux = inicio;
    if(aux == NULL)
        {
            printf("NULL\n");
        }
    else
        {
            do{
                printf("%d %f | ", aux->a.matricula, aux->a.cr);
                aux = aux->prox;
            }while(aux != NULL);
        }
}
