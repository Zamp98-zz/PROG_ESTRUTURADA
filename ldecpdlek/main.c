#include "source.h"
int main()
{
    Mercadoria m;
    init();
    while(TRUE)
        {
            int choice;
            printf("1 - Inserir na lista:\n");
            printf("2 - Retirar da lista:\n");
            printf("3 - Proximo:\n");
            printf("4 - Anterior:\n");
            printf("5 - Sair:\n");
            scanf("%d", &choice);
            if(choice == 1)
                {
                    system("cls");
                    printf("Digite o nome do produto:\n");
                    scanf("%s", m.nome);
                    system("cls");
                    printf("Digite o preco:\n");
                    scanf("%f", &m.preco);
                    system("cls");
                    insere_ordenado(m);
                }
            if(choice == 2)
                {
                    sai();
                }
            if(choice == 3)
                {
                    if(proximo() == FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                }
            if(choice == 4)
                {
                    if(anterior() == FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                }
            if(choice == 5)
                {
                    finish();
                    return FALSE;
                }
        }
    return 0;
}
