#include "source.h"
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
///quero inserir no inicio da lista pq sim o programa eh meu
int insereAluno(Aluno a){
    printf("OI");
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
void imprime(){
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
int retira(){
    ///casos
    ///se for unica
    ///se estiver no começo
    ///se estiver no final
    ///se estiver no meio
    Node *aux = corrente;
    if(aux == NULL){
        return FALSE;
    }
    else if((aux->anterior == NULL) && (aux->proximo == NULL)){
        free(aux);
        fim = inicio = corrente = NULL;
    }
    else if((aux->anterior == NULL) &&(aux->proximo !=NULL)){
        corrente = corrente->proximo;
        corrente->anterior = NULL;
    }
    else if((aux->proximo == NULL) && (aux->anterior != NULL)){
        corrente = corrente->anterior;
        fim = corrente->anterior;
        corrente->proximo = NULL;
    }
    else{
        corrente->anterior->proximo = corrente->proximo;
        corrente->proximo->anterior = corrente->anterior;
        corrente = corrente->anterior;//quero andar pra trás!
    }
    free(aux);
    return TRUE;
}

int nodeAnterior(){
    if (corrente->anterior == NULL){
        return FALSE;
    }
    else{
        corrente = corrente->anterior;
        return TRUE;
    }
}

int nodeProximo(){
    if (corrente->proximo == NULL){
        return FALSE;
    }
    else{
        corrente = corrente->proximo;
        return TRUE;
    }
}

int carregaPersistencia(){
    FILE *arquivo;
    arquivo = fopen("data.bin","r");
    if(arquivo == NULL){
        return FALSE;
    }
    Node *aux = (Node *)malloc(sizeof(Node));

    while(1)
        {
            Aluno a;
            fread(&a, sizeof(Aluno), 1, arquivo);

            if(feof(arquivo)){
                break;
            }
            insereAluno(a);
        }
    return TRUE;
}

int gravaPersistencia(){
    FILE *arquivo;
    arquivo = fopen("data.bin","w");
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
            if(feof(arquivo)){
                break;
            }
            aux = aux->anterior;
        }
    fclose(arquivo);
    return TRUE;
}

int finaliza(){
    gravaPersistencia();
    fim = inicio = corrente = NULL;
    return TRUE;
}



/*Node *primeiro(){
    Node *aux = corrente;
    if (corrente == NULL){
        return NULL;
        }
    while(aux->anterior!=NULL){
        aux = aux->anterior;
    }
    return aux;
}*/
