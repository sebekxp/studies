/*zliczyæ elementy dodatnie dwu lub trzycyfrowe, których suma cyfr jest nieparzysta ;
elementy int do wczytania z klawiatury do uzyskania wartoœci >= koniec*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,z,y,x,suma=0,sumaNieparzyste=0;

        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

         do{
              printf("Podaj liczbe: ");
              scanf("%d", &j);
              if((j>=10)&&(j<=999))
              {
                    x=j%10;                 //jednosci
                    y=((j-x)/10)%10;       //dziesiatki
                    z=(j-x)/100;          //setek
                    suma=x+y+z;          //suma cyfr

                    if(suma%2)
                    sumaNieparzyste= sumaNieparzyste+j;
              }

           }while(!(j>=n));

           printf("Suma :%d",sumaNieparzyste);
    return 0;
}
