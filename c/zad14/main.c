/*Œrednia geometryczna elementów parzystych; elementy typu int wczytywane z
klawiatury do napotkania wartoœci = koniec w³¹cznie

 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,i=0,j,suma=1,s;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            if(j%2==0)
            {
               i++;
               suma=(suma*j);
            }
          }while(j!=n);
          suma=suma*n;
          i++;
          s=pow(suma,1./i);
          printf("Srednia geometryczna : %d",s);
    return 0;
}
