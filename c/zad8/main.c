/* œrednia geometrycznaelementów dwu lub trzycyfrowych dodatnich
wczytywanych z klawiatury do napotkania wartoœci = koniec (bez koñca) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
       int n,i=0,j,suma=1,s;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            if(((j>=10)&&(j<=999))&&(j!=n))
            {
               i++;
               suma=(suma*j);
               s=pow(suma,1./i);
            }
          }while(j!=n);
          printf("Srednia geometryczna : %d",s);
    return 0;
}
