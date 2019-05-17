/* Suma elementów dwu lub trzycyfrowych dodatnich i ujemnych typu int wczytywanych z klawiatury
do napotkania wartoœci = koniec wraz z koñcem */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,suma=0;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{

           printf("Podaj liczbe: ");
           scanf("%d", &j);
           if((((j>=-999)&&(j<=-10)) || ((j>=10)&&(j<=999))) && (j!=n))
           suma=suma+j;

          }while(j!=n);
          suma=suma+n;

          printf("Suma : %d",suma);


    return 0;
}
