/*�rednia arytmetyczna element�w podzielnych przez 3; elementy typu
int wczytywane z klawiatury
do napotkania warto�ci = koniec (z ko�cem), ale nie wi�cej ni� n element�w*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,suma=0,i=0,srednia,m=0;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

        do{
            printf("Podaj liczbe: ");
            scanf("%d", &j);
            m++;
            if(j%3==0)
            {
                suma=suma+j;
                i++;
            }
        }while((j!=n)&&(m<n));
        suma=suma+n;
        i++;
        srednia=suma/i;
        printf("Srednia arytmetyczna : %d",srednia);



    return 0;
}
