#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{
        int n,j,warunek=0,suma=1,i=0;
        double s;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            if((j>99)&&(j<=999))
            {
               suma=suma*j;
               warunek=warunek+j;
               i++;
            }
          }while(warunek<n);
          s=pow(suma,1./i);
          printf("Srednia geometryczna : %lf",s);
    return 0;
}
