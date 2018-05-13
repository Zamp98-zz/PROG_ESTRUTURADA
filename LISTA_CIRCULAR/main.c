#include "source.h"
///

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
            printf("4 - Ler do arquivo:\n");
            printf("5 - Escrever no arquivo\n");
            printf("6 - Ajuda\n");
            printf("7 - Sair\n");
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
            else if (choice == 2)
                {
                    if(apaga()==FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                }
            else if (choice == 3)
                {
                    if(show()==FALSE)
                        {
                            printf("Lista vazia!\n");
                        }
                }
            else if (choice == 4)
                {
                    if(ler()==FALSE)
                        {
                            printf("Arquivo vazio!\n");
                        }
                    int continuar;
                    printf("Digite 0 para continuar\n");
                    scanf("%i", &continuar);
                    system("cls");
                }
            else if (choice == 5)
                {
                    if (escreve() == FALSE)
                        {
                            printf("Erro ao escrever no arquivo. Talvez a lista esteja vazia!\n");

                        }
                    int continuar;
                    printf("Digite 0 para continuar\n");
                    scanf("%i", &continuar);
                    system("cls");
                }
            else if (choice == 6)
                {
                    printf("Esse guia eh somente para escrever aquivos.\nEssa funcao escreve todos os elementos da lista num arquivo de texto.\n");
                    int continuar;
                    printf("Digite 0 para continuar\n");
                    scanf("%i", &continuar);
                    system("cls");
                }

            else if (choice == 7)
                {
                    finish();
                    return FALSE;
                }
        }
    return 0;
}
