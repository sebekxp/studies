/* zliczy� elementy dodatnie dwu lub trzycyfrowe, kt�rych
 suma cyfr jest nieparzysta ; elementy int do wczytania z klawiatury
do napotkania elementu = koniec bez ko�ca, nie wi�cej ni� n element�w */
#include <stdio.h>
#include <stdlib.h>

int main()
{

        int n,j,z,y,x,suma=0,sumaNieparzyste=0,i=0;

        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

         do{
              printf("Podaj liczbe: ");
              scanf("%d", &j);
              i++;
              if(((j>=10)&&(j<=999))&&(j!=n))
              {
                    x=j%10;                 //jednosci
                    y=((j-x)/10)%10;       //dziesiatki
                    z=(j-x)/100;          //setek
                    suma=x+y+z;          //suma cyfr

                    if(suma%2)
                    sumaNieparzyste= sumaNieparzyste+j;
              }

           }while((j!=n)&&(i<n));

           printf("Suma :%d",sumaNieparzyste);
    return 0;
}
