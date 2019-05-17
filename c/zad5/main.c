/* zliczyæ elementy z przedzia³u <a;b>; a,b,n oraz n elementów
double do wczytania z klawiatury */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,x,n,i,e,s;
    printf("Podaj przedzial\n");

    printf("Wartosc poczatkowa : ");
    scanf("%d",&a);

    printf("Wartosc koncowa : ");
    scanf("%d",&b);

    printf("Ilosc elementow dopisywanych : ");
    scanf("%d",&n);

    printf("Twoj przedzial <%d,%d>\n",a,b);


    x=fabs(a-b)+1;
    printf("Przedzial zawiera %d elementow\n",x);
    printf("Dopisz pare elementow : \n");
    i=1;

    do{
        scanf("%d\n",&e);
        i++;
      }while(i<n);

    s=x+n;
    printf("Laczna ilsoc elementow z przedzialu i dopisanych wynosi : %d",s);


    return 0;
}
