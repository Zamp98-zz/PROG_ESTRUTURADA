#include "source.h"
void tela(){
    printf("I - Inserir aluno:\n");
    printf("R - Retirar aluno:\n");
    printf("P - Pular pra proximo:\n");
    printf("A - Pular para anterior:\n");
    printf("OUTRA TECLA - Sair:\n");
    imprime();
}
int main(){
    inicializa();
    char opt;
    while(TRUE){
        //system("cls");
        tela();
        opt = toupper(getch());
        if(opt == 'I'){
            Aluno a;
            printf("Digite o nome:\n");
            scanf("%s", a.nome);
            system("cls");
            tela();
            printf("Digite a idade:\n");
            scanf("%d", &a.idade);
            system("cls");
            insereAluno(a);
        }
        else if(opt == 'R'){
            if(retira() == FALSE){
                printf("Lista vazia!\n");
                printf("Tecle algo:\n");
                getch(); system("cls");

            }
            }
        else if(opt == 'P'){
            if(nodeProximo()==FALSE){
                printf("Final da lista!\n");
                //printf("Tecle algo:\n");
                //getch(); system("cls");
            }
        }
        else if(opt == 'A'){
            if(nodeAnterior()==FALSE){
                printf("Inicio da lista!\n");
               //printf("Tecle algo:\n");
                //getch(); system("cls");
            }
        }
        else{
            finaliza();
            return FALSE;
        }
    }
    return 0;
}
