#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
      int n,i=0,j,suma=1;
      double s;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            if(((j>=10)&&(j<=999))&&(j!=n))
            {
               suma=suma*j;
               i++;
            }
          }while(j!=n);
          s=pow(suma,1./i);
          printf("Srednia geometryczna : %lf",s);

    return 0;
}
