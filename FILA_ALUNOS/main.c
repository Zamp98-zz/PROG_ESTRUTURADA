#include <stdio.h>
#include <stdlib.h>
#include "source.h"
int main()
{
    Aluno a;
    int x = 0;
    while(x<4)
        {
            scanf("%d", &a.matricula);
            scanf("%f", &a.cr);
            insere(a);
            x++;
        }
        printa();
    return 0;
}
