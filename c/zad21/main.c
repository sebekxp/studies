#include <stdio.h>
#include <stdlib.h>
int max(int tab[],int n)
{
 int j=1;
 int wynik=tab[0];
 for(j;j<n;j++)
 {
     if(tab[j]>wynik)
        wynik=tab[j];

 }//for
 return wynik;
}
int min(int tab[],int n)
{
int j=1;
 int wynik=tab[0];
 for(j;j<n;j++)
 {
     if(tab[j]<wynik)
        wynik=tab[j];

 }//for
 return wynik;
}

int main()
{
    int n;
    printf("Podaj liczbe elementow :");
    scanf("%d",&n);
    int tab[n];
    int i,suma=0;
    double srednia;
    for(i=0;i<n;i++)
    {

        scanf("%d",&tab[i]);
        suma=suma+tab[i];

    }
    int a=max(tab,n);
    int b=min(tab,n);
    srednia=(double)suma/(double)i;
    printf("Suma :%d\n",suma);
    printf("Srednia :%0.2lf\n",srednia);
    printf("Max :%d\n",a);
    printf("Min :%d\n",b);


    return 0;
}
