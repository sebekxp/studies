/* zliczy� elementy dodatnie i ujemne dwu lub trzycyfrowe,
kt�rych liczba dziesi�tek jest wi�ksza ni� liczba jedno�ci do
 uzyskania warto�ci >= koniec, ale nie wi�cej ni� n sk�adnik�w
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,j,x,y,i=0,suma=0,m;
        printf("Wartosc konczaca program : ");
        scanf("%d", &n);

         do{
              printf("Podaj liczbe: ");
              scanf("%d", &j);
              i++;
              if(((j>=-999)&&(j<=-10)) || ((j>=10)&&(j<=999)))
              {
                  if(j < 0)
                    m = j * (-1);
                  else
                    m = j;

                    x=m%10;                 //jednosci
                    y=((m-x)/10)%10;       //dziesiatki



                    if(y>x)
                    suma=suma+j;
              }

           }while(!(j>=n)&&(i<n));
            printf("Suma: %d",suma);


    return 0;
}
