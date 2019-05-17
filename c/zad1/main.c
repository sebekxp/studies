 /* Œrednia arytmetyczna elementów podzielnych przez 3; elementy typu int wczytywane z klawiatury
 do napotkania wartoœci = koniec (bez koñca) */
#include <stdio.h>
#include <stdlib.h>


int main()
{
       int n,j,x=0,i=0,z;
       printf("Wartosc konczaca program : ");
       scanf("%d",&n);

    do{

       printf("Podaj liczbe : ");
       scanf("%d", &j);

       if((j%3==0)&&(j!=n))
       {
        x=x+j;
        i++;
       }

      }while(j!=n);

       z=x/i;
       printf("Srednia arytmetyczna wynosi : %d",z);

    return 0;
}
