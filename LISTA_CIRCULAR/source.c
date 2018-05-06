#include "source.h"
FILE *arq;///para se criar um arquivo de texto, eh necessario um ponteiro para o tipo FILE
 ///
 ///
typedef struct node{
    Hero h;
    struct node *prox;
}Node;
///
///
///
Node *corrente;
Node *inicio;
Node *fim;
///
///
int init()
{
    corrente = NULL;
    inicio = NULL;
    fim = NULL;
    arq = fopen("DATABASE.txt", "a");///abrindo arquivo no modo append
    return TRUE;
}
///
///
int inserir(Hero h)
{
    Node *novo;
    novo = malloc(sizeof(Node));
    novo->h = h;
    novo->prox = inicio;/// aponta para o inicio ja que eh circular
    fprintf(arq,"%s %i\n", novo->h.name, novo->h.power);///escrevendo o nome no arquivo de texto

    if (inicio == NULL)///se a lista estiver vazia
        {
            inicio = novo; /// inicializa a lista com um elemento
            corrente = novo; /// ponteiro corrente aponta para o novo elemento
        }
    else
        {
            corrente->prox = novo;///o "novo" anterior aponta para o novo "novo"
            corrente = novo; /// ponteiro corrente aponta para o ultimo adicionado
            novo->prox = inicio;
        }
    return TRUE;
}
///
///
int apaga()
{
    if(corrente==NULL)
        {
            return FALSE;
        }
    else
        {
            corrente->prox;
            return TRUE;
        }
}
///
///
int show()
{
    Node *primeiro;
    int counter = 0;
    primeiro = inicio;
    Node *aux;
    aux = inicio;
    if(aux == NULL)
        {
            return FALSE;
        }
    else
        {
            do
                {


                    printf("Nome: %s Poder: %d ->", aux->h.name, aux->h.power);
                    aux = aux->prox;
                    if(aux == primeiro)
                        {
                            printf("inicio\n");
                            return TRUE;
                        }
                }while(aux != aux->prox);
        }
}
///
///
int finish()
{
    corrente = NULL;
    inicio = NULL;
    fim = NULL;
    fclose(arq);
    return TRUE;
}
///---------------------------------------------fim-----------------------------------------------
