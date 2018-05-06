#include "source.h"

int main()
{
    init();
    Hero a;
    while(TRUE)
        {
            printf("Escolha a opcao:\n");
            printf("1 - Criar heroi:\n");
            printf("2 - Apagar heroi:\n");
            printf("3 - Mostrar herois:\n");
            printf("4 - Sair\n");
            int choice;
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
                {

                    printf("Digite o nome do heroi:\n");
                    scanf("%s", a.name);
                    system("cls");
                    printf("Digite o poder do heroi:\n");
                    scanf("%d", &a.power);
                    if (inserir(a)==FALSE)
                        {
                            printf("Mas que porra foi essa!?!?\n");
                            printf("Tao te hasckeando broder toma cuidado!!!\n");
                        }
                    else
                        {
                            system("cls");
                        }

                }
            if (choice == 2)
                {
                    if(apaga()==FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                    else
                        {
                            apaga();
                        }
                }
            if (choice == 3)
                {
                    if(show()==FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                }
            if (choice == 4)
                {
                    finish();
                    return FALSE;
                }
        }
    return 0;
}
