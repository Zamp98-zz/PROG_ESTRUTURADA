#include "source.h"
#define antes 2
#define depois 3
int r = 0;
typedef struct node{
    Aluno a;
    struct node *proximo;
    struct node *anterior;
}Node;
Node *inicio, *corrente, *fim;
int inicializa(){
    fim = inicio = corrente = NULL;
    carregaPersistencia();
    return TRUE;
}

void insereInicio(Node *novo, Node *aux)
{
    printf("insereInicio");getch();
    novo->proximo = aux;
    aux->anterior = novo;
    inicio = novo; return;
}

void insereFim(Node *novo, Node *aux)
{
    printf("insereFim");getch();
    novo->anterior = aux;
    aux->proximo = novo;
    fim = novo; return;
}

void insereMeioAntes(Node *novo, Node *aux)
{
    printf("insereMeioAntes");getch();
    novo->anterior = aux->anterior;
    novo->proximo = aux;
    aux->anterior->proximo = novo;
    aux->anterior = novo; return;
}

void insereMeioPosterior(Node *novo, Node *aux)
{
    printf("insereMeioPosterior");getch();
    novo->proximo = aux->proximo;
    novo->anterior = aux;
    aux->proximo->anterior = novo;
    aux->proximo = novo; return;
}

void insere(Node *novo, Node *posicao, int ref)
{

    if((posicao->proximo == NULL) && (ref == antes))
    {
        if((posicao->anterior == NULL) && (ref == antes))
        {
            insereInicio(novo, posicao);
        }
        else
        {

            insereMeioAntes(novo, posicao);
        }
    }
    else if((posicao->proximo == NULL) && (ref == depois))
    {
        insereFim(novo,posicao);
    }
    else if((posicao->anterior == NULL) && (ref == antes))
    {
        printf("oi");getch();
        insereInicio(novo, posicao);
    }
    else if((posicao->anterior == NULL) && (ref == depois))
    {
        if((posicao->proximo == NULL) && (ref == depois))
        {
            insereFim(novo, posicao);
        }
        else
        {
            insereMeioPosterior(novo, posicao);
        }
    }
    else if((posicao->proximo != NULL) && (ref == antes))
    {
        if((posicao->anterior == NULL) && (ref == antes))
        {
            insereInicio(novo , posicao);
        }
        else
        {
            insereMeioAntes(novo, posicao);
        }

    }
    else if((posicao->proximo == NULL) && (ref == depois))
    {
        insereFim(novo, posicao);
    }
    else if((posicao->anterior != NULL) && (ref == depois))
    {
        if((posicao->proximo == NULL) && (ref == depois))
        {
            insereFim(novo, posicao);
        }
        else
        {
            insereMeioPosterior(novo, posicao);
        }
    }
    else if((posicao->anterior != NULL) && (ref == antes))
    {
        insereMeioAntes(novo, posicao);
    }
    return;
}

void ordena(Node *novo)
{
    Node *aux = inicio;
    Node *posicao = aux; int referencial = 0;//armazena a melhor posição para o node entrar
    Node *aux1 = NULL;
    while(aux!=NULL)//enquanto o ponteiro aux não chegar no final
    {
        ///se o novo for menor alfabeticamente
        if(strcmp(novo->a.nome,aux->a.nome)<0)
        {

            insere(novo, aux, antes);
            break;
        }
        else if(strcmp(novo->a.nome,aux->a.nome) == 0)
        {
            while(strcmp(novo->a.nome,aux->a.nome) == 0)
            {
                if(novo->a.idade<=aux->a.idade)
                {
                    printf("queisso");getch();
                    insere(novo, aux, antes); break;
                }
                else
                {
                    if(aux == fim)
                    {
                        insere(novo, aux, depois); break;
                    }
                }
                aux = aux->proximo;
            }
            return;
        }
        else if(strcmp(novo->a.nome,aux->a.nome)>0)
        {

            if(aux == fim)
                {
                    insere(novo, aux, depois);break;
                }
            aux = aux->proximo;
        }

    }
    return;
}

int insereAluno(Aluno a)
{
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->a = a;
    novo->proximo = novo->anterior = NULL;
    if(inicio == NULL)
    {
        inicio = fim = corrente = novo;
    }
    else
    {
        ordena(novo);
    }
    return TRUE;
}

void imprime()
{
    Node *aux = inicio;
    if(aux == NULL){
        printf("Lista vazia!\n");
    }
    else{
        do{
            if(aux == corrente){
                printf("[x]%s %d->",aux->a.nome, aux->a.idade);
            }
            else{
                printf("%s %d->",aux->a.nome, aux->a.idade);
            }
            aux = aux->proximo;
        }while(aux!=NULL);

        printf("\n");
    }
}
///função que retira o elemento corrente
int retira()
{
    ///casos
    ///se for unica
    ///se estiver no começo
    ///se estiver no final
    ///se estiver no meio
    Node *aux = corrente;
    if(aux == NULL)
    {
        return FALSE;
    }
    else if((aux->anterior == NULL) && (aux->proximo == NULL))
    {
        free(aux);
        fim = inicio = corrente = NULL;
    }
    else if((aux->anterior == NULL) &&(aux->proximo !=NULL))
    {
        corrente = corrente->proximo;
        corrente->anterior = NULL;
        inicio = corrente;
    }
    else if((aux->proximo == NULL) && (aux->anterior != NULL))
    {
        corrente = corrente->anterior;
        fim = corrente->anterior;
        corrente->proximo = NULL;
    }
    else
    {
        corrente->anterior->proximo = corrente->proximo;
        corrente->proximo->anterior = corrente->anterior;
        corrente = corrente->anterior;//quero andar pra trás!
    }
    free(aux);
    return TRUE;
}

int nodeAnterior()
{
    if (corrente->anterior == NULL)
    {
        return FALSE;
    }
    else
    {
        corrente = corrente->anterior;
        return TRUE;
    }
}

int nodeProximo(){
    if (corrente->proximo == NULL)
    {
        return FALSE;
    }
    else
    {
        corrente = corrente->proximo;
        return TRUE;
    }
}
int carregaAluno(Aluno a){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->a = a;
    novo->proximo = novo->anterior = NULL;
    //Node *aux = primeiro();
    if(corrente == NULL){
        fim = inicio = novo;
        corrente = novo;
    }
    ///quero botar no inicio da lista
    else{
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }
    return TRUE;
}
int carregaPersistencia()
{
    FILE *arquivo;
    arquivo = fopen("data.txt","r");
    if(arquivo == NULL)
    {
        return FALSE;
    }
    while(1)
        {
            Aluno a;
            fread(&a, sizeof(Aluno), 1, arquivo);

            if(feof(arquivo))
            {
                break;
            }
            carregaAluno(a);
        }
    return TRUE;
}

int gravaPersistencia()
{
    FILE *arquivo;
    arquivo = fopen("data.txt","w");
    if(arquivo == FALSE)
        return FALSE;
    if(inicio == NULL)
        return FALSE;
    Node *aux = fim;
    Aluno a;
    while(aux!=NULL)
        {
            a = aux->a;
            fwrite(&a, sizeof(Aluno), 1, arquivo);
            if(feof(arquivo))
            {
                break;
            }
            aux = aux->anterior;
        }
    fclose(arquivo);
    return TRUE;
}

int finaliza()
{
    gravaPersistencia();
    fim = inicio = corrente = NULL;
    return TRUE;
}
