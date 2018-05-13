#include "source.h"

#define SIZE 256
#define SIZE_N 1
///FILE *arq;///para se criar um arquivo de texto, eh necessario um ponteiro para o tipo FILE
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
typedef struct node{
    Hero h;
    struct node *prox;
}Node;
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
Node *corrente;
Node *inicio;
Node *fim;
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int init()
{
    corrente = NULL;
    inicio = NULL;
    fim = NULL;
    ///arq = fopen("DATABASE.txt", "a");///abrindo arquivo no modo append
    return TRUE;
}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int inserir(Hero h)
{
    Node *novo;
    novo = malloc(sizeof(Node));
    novo->h = h;
    novo->prox = inicio;/// aponta para o inicio ja que eh circular
    ///fprintf(arq,"%s %i\n", novo->h.name, novo->h.power);///escrevendo o nome no arquivo de texto
    ///fprintf(arq,"\0");

    if (inicio == NULL)///se a lista estiver vazia
        {
            inicio = novo; /// inicializa a lista com um elemento
            corrente = novo;
            corrente->prox = novo; /// ponteiro corrente aponta para o novo elemento
        }
    else
        {
            corrente->prox = novo;///o "novo" anterior aponta para o novo "novo"
            corrente = novo; /// ponteiro corrente aponta para o ultimo adicionado
            novo->prox = inicio;
        }
    ///ordena(&h);
    return TRUE;
}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
/*void liberaMemoria(Node *corrente)
{
    Node *p1;
    Node *p2; = corrente->prox;
    while (p2 != corrente)
        {
            //p1 = p2;
            Node *aux = p2->prox;
            printf("libera %s\n", p2->h.name);
            free(p2);
            p2 = p1->prox;
        }
        printf("Libera corrente %s", p2->h.name);
        free(p2);
}*/
int apaga()
{
    Node *aux = corrente;
    if(corrente==NULL)
        {
            return FALSE;
        }
    else
        {
            if(corrente == inicio)
                {
                    inicio = NULL;
                    corrente = inicio;
                }
            else
                {
                    corrente->h.name[0] = '\0';
                    corrente->h.power = 0;
                    corrente = aux->prox;
                }

        }
    free(aux);
    return TRUE;
}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int show()
{
    system("cls");
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
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int ordena(Hero *h)///Essa função tem que percorrer toda a lista
{
    Node *aux = inicio;
    char c[2];
    c[0] = aux->h.name[0];/// intervalo de valor eh de 97 até 122 ASCII letra minúsculas
    char temp[2];
    Hero a, b, aux1;
    if (aux == NULL)/// Isso diz que a lista está vazia
        {
            return FALSE;
        }
    else
        {
            do{
                a = aux->h;
                aux = aux->prox;
                b = aux->h;
                temp[0] = aux->h.name[0];
                if(c[0]<temp[0])
                    {
                    }
                else
                    {
                        aux1 = b;
                        b = a;
                        a = aux1;
                    }
            }while(aux !=NULL);
        }
}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int ler()
{
    system("cls");
    char buffer[100];
    FILE *arq;
    if(arq==NULL)
        {
            return FALSE;
        }
    arq = fopen("DATABASE.txt","r");
    fread(buffer, SIZE, SIZE_N, arq);
    printf("%s\n", buffer);
    //fclose(arq);

    return TRUE;

}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int escreve()
{
    ///Foi necessária a crição de dois ponteiros para dizer onde o loop do print tem que parar
    Node *primeiro;
    primeiro = inicio;
    Node *aux;
    aux = inicio;
    FILE *arq;
    arq = fopen("DATABASE.txt", "a");///abrindo arquivo no modo append
    if (arq == NULL)
        {
            return FALSE;
        }
    if(aux == NULL)
        {
            return FALSE;
        }
    else
        {
            do
                {


                    fprintf(arq,"%s %i\n", aux->h.name, aux->h.power);///escrevendo o nome no arquivo de texto
                    fprintf(arq,"\0");
                    aux = aux->prox;///essa variavel percorre a lista
                    if(aux == primeiro)
                        {

                            printf("Gravado com sucesso!\n");
                            fclose(arq);
                            return TRUE;
                        }
                }while(aux != aux->prox);

        }

}
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
///----------------------------------------------------------------------------------------------///
int finish()
{
    corrente = NULL;
    inicio = NULL;
    fim = NULL;
    ///fclose(arq);
    return TRUE;
}
///---------------------------------------------fim-----------------------------------------------
