
#include "source.h"
int main()
{
    Aluno a;
    int x = 0;
    while(x<3)
        {
            scanf("%d", &a.matricula);
            scanf("%f", &a.cr);
            insere(a);
            x++;
        }
    imprime();
    return FALSE;
}
