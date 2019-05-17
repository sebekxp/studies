#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,parzyste=0,n,k=0,s,e;
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
    printf("Ilosc elementow parzstych wynosi : %d\n",parzyste);

    printf("Ilosc elementow dopisywanych : ");
    scanf("%d",&n);


     printf("Dopisz pare elementow : \n");
    i=1;

    do{
        scanf("%d\n",&e);
        i++;
        if(i%2==0)
        k++;
      }while(i<n);

    s=parzyste+k;
    printf("Laczna ilsoc elementow parzystych z przedzialu i dopisanych wynosi : %d",s);
    return 0;
}
