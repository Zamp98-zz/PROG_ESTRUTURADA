#include <stdio.h>
#include <stdlib.h>
void recebe(float *a,float *b,float *c,float *d,float *e,float *f)
{
    //printf("%f %f %f %f %f %f ",*a,*b,*c,*d,*e,*f);//
    void resolve(float a, float b, float c, float d, float e,float f)
    {
        double x;
        printf("Digite o x inicial:(O ultimo valor a ser calculado sera o oposto dele)");
        scanf("%lf",&x);
        int raizes = 0;
        double x_opo = -x;
        double eq;
        while(x<=x_opo)
            {
                x = x+0.00000001;
                eq = (a*(x*x*x*x*x))+(b*(x*x*x*x))+(c*(x*x*x))+(d*(x*x))+(e*x)+f;
                //printf("x = %f  eq = %f \n",x,eq);
                if((eq<0.0000001) && (eq>-0.0000001))
                    {
                        raizes = raizes+1;
                        printf("possivel raiz x = %f\n",x);
                    }
            }
    }
    resolve(*a,*b,*c,*d,*e,*f);
}
int main()
{
    float a,b,c,d,e,f;
    printf("Digite o valor de A:\n");
    scanf("%f",&a);
    printf("Digite o valor de B:\n");
    scanf("%f",&b);
    printf("Digite o valor de C:\n");
    scanf("%f",&c);
    printf("Digite o valor de D:\n");
    scanf("%f",&d);
    printf("Digite o valor de E:\n");
    scanf("%f",&e);
    printf("Digite o valor de F:\n");
    scanf("%f",&f);
    recebe(&a,&b,&c,&d,&e,&f);
}
