/*�rednia arytmetyczna spo�r�d element�w 3-cyfrowych dodatnich i ujemnych wczytywanych
z klawiatury do napotkania warto�ci = koniec w��cznie */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,suma=0,srednia,i=0;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            i++;
            if((((j>=-999)&&(j<=-100)) || ((j>=100)&&(j<=999))) && (j!=n))
            suma=suma+j;

        }while(j!=n);

        suma=suma+n;
        printf("Suma: %d\n",suma);
        srednia=suma/i;
        printf("Srednia: %d",srednia);



    return 0;
}
