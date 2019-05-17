/*Suma elementów dwu lub trzycyfrowych dodatnich i ujemnych typu int wczytywanych z
klawiatury do uzyskania wartoœci >= koniec; wyniki – suma i liczba elementów */
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n,j,suma=0,i=0;
     printf("Wartosc konczaca program : ");
     scanf("%d", &n);

     do{

           printf("Podaj liczbe: ");
           scanf("%d", &j);
           if(((j>=-999)&&(j<=-10)) || ((j>=10)&&(j<=999)))
           {
            suma=suma+j;
            i++;
           }

          }while(!(j>=n));


           printf("Suma : %d\n",suma);
           printf("Liczba elementow : %d",i);
    return 0;
}
