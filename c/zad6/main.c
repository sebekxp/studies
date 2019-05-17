/* zliczyæ elementy dodatnie dwu lub trzycyfrowe, których suma cyfr jest parzysta ; elementy int do wczytania z klawiatury
 do napotkania elementu = koniec wraz z nim, nie wiêcej ni¿ n elementów */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,z,y,x,i=0,suma=0,suma_dodatnie=0;

        printf("Wartosc konczaca program : ");
        do{
            scanf("%d", &n);
            if(n<10)
            printf("Element musi byc 2-u lub 3-y cyfrowy\n");

          }while(n<10);

         do{
              printf("Podaj liczbe: ");
              scanf("%d", &j);
              i++;
              if((j>=10)&&(j<=999))
              {
                    x=j%10;                 //jednosci
                    y=((j-x)/10)%10;       //dziesiatki
                    z=(j-x)/100;          //setek
                    suma=x+y+z;          //suma cyfr

                    if(suma%2==0)
                    suma_dodatnie = suma_dodatnie+j;
              }
           }while((j!=n)&&(i<n));

           printf("Suma :%d",suma_dodatnie);


    return 0;
}
