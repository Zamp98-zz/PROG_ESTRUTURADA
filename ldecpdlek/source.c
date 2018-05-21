#include "source.h"
typedef struct node{
    Mercadoria m;
    struct node *proximo;
    struct node *anterior;
}Node;
Node *corrente;
int init()
{
    corrente = NULL;
    carrega_persistencia();
    return TRUE;
}
int sai()
{
    Node *aux = corrente;
    if(corrente == NULL)
        {
            return FALSE;
        }
    if(corrente == corrente->proximo)///temos um elemento nesse caso!
        {
            corrente = NULL;
        }
    else
        {
            ///passos que ligarão o ultimo node ao proximo primeiro node
            corrente = corrente->proximo;
            corrente->anterior->anterior->proximo = corrente;
            corrente->anterior = corrente->anterior->anterior;
        }
    free(aux);
    imprime();
    return TRUE;
}
int proximo()
{
    if(corrente == NULL)
        {
            return FALSE;
        }
    else
        {
            corrente = corrente->proximo;
            imprime();
            return TRUE;
        }
}
int anterior()
{
    if(corrente == NULL)
        {
            return FALSE;
        }
    else
        {
            corrente = corrente->anterior;
            imprime();
            return TRUE;
        }
}
void imprime()
{
    Node *aux = corrente;
    if(aux == NULL)
        {
            printf("Lista vazia!\n");
        }
    else
        {
            do
                {
                    printf("%s %.2f ->", aux->m.nome, aux->m.preco);
                    aux = aux->proximo;
                }while(aux!=corrente);
                printf("\n");
        }
}
void carrega_persistencia()
{
    FILE *arquivo;
    arquivo = fopen("data.bin", "rb");
    Node n;
    while(1)
        {
            fread(&n,sizeof(Node), 1, arquivo);
            if(feof(arquivo))
                {
                    break;
                }
            insere_ordenado(n.m);
        }
    fclose(arquivo);
}
void grava_persistencia()
{
    FILE *arquivo;
    arquivo = fopen("data.bin", "wb");
    Node *aux = corrente;
    int counter = 0;
    if (corrente == NULL)
        {
        }
    else
        {
           do
                {
                    if(feof(arquivo)){break;}
                    fwrite(aux, sizeof(Node), 1, arquivo);
                    aux = aux->proximo;
                    counter++;
                }while(aux!=corrente);
                fclose(arquivo);
        }
}
int insere_ordenado(Mercadoria m)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->m = m;
    Node *aux = corrente;
    Node *temp = NULL;
    if(corrente == NULL)
        {
            corrente = novo;
            corrente->proximo = corrente->anterior = corrente;
        }
    else
        {
            do
                {
                    if(novo->m.preco<=aux->m.preco)
                        {
                            temp = aux;
                        }
                    aux = aux->proximo;
                }while(aux!=corrente);
            /// vai ser o ultimo endereço salvo
                    if(temp != NULL)
                        {
                            ///tenho que colocar o novo depois do temp
                            novo->anterior = temp;
                            novo->proximo = temp->proximo;
                            temp->proximo->anterior = novo;
                            temp->proximo = novo;
                }
            else
                {
                    novo->proximo = corrente; /// o node q vai entrar aponta para o atual
                    novo->anterior = corrente->anterior;///apontando para o ultimo
                    corrente->anterior->proximo = novo; /// o node ultimo aponta para o node novo
                    corrente->anterior = novo;///o atual aponta pro que vai entrar
                    corrente = novo;///substituindo pelo atual
                }
        }
    imprime();
    return TRUE;
}
int finish()
{
    grava_persistencia();
    corrente = NULL;
    return TRUE;
}
