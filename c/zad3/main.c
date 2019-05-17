/* Suma elementów dwucyfrowych ujemnych ; elementy typu int wczytywane z klawiatury
 do napotkania wartoœci = koniec wraz z koñcem, ale nie wiêcej ni¿ n elementów */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,x=0,i=0,z;
        printf("Wartosc konczaca program : ");

       do{
            scanf("%d",&n);
            if(n<0)
            printf("Liczba musi byc dodania\n");
         }while(!(n>0));

        do
        {

         printf("Podaj liczbe : ");
         scanf("%d", &j);
         i++;
         if((j<=-10)&&(j>=-99))
         {
             x=x+j;
         }
        }while((j!=n)&&(i<n));

        x=x+n;
        printf("Suma wynosi : %d",x);
    return 0;
}
