/*liczba elementów parzystych z <a;b> - do wczytania a, b typu int*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,parzyste=0;
    printf("Stworz przedzial zamkniety\n");

    printf("Poczatek : ");
    scanf("%d",&a);

    printf("Koniec : ");
    scanf("%d",&b);

    printf("<%d,%d>\n",a,b);

    for(i=a;i<=b;i++)
    {
       if(i%2==0)
       parzyste++;
    }
     printf("Ilosc elementow parzstych wynosi : %d",parzyste);
    return 0;
}
