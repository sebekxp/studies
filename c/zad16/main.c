/* Suma elementów dwu lub trzycyfrowych cyfrowych ujemnych ;
elementy typu int wczytywane z klawiatury
do napotkania wartoœci = koniec wraz z koñcem, ale nie wiêcej ni¿ n elementów */
#include <stdio.h>
#include <stdlib.h>

int main()
{


        int n,j,suma=0,i=0;
        printf("Wartosc konczaca program : ");
        do{
            scanf("%d",&n);
            if(n<0)
            printf("Liczba musi byc dodania\n");
          }while(!(n>0));

        do{

           printf("Podaj liczbe: ");
           scanf("%d", &j);
           i++;
           if(((j>=-999)&&(j<=-10))&&(j!=n))
            {
            suma=suma+j;
            }

           }while((j!=n)&&(i<n));
           suma=suma+n;
           i++;
           printf("Suma : %d ",suma);

    return 0;
}
