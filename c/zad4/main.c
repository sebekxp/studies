#include <stdio.h>
#include <stdlib.h>
int main()
{
    int tab[]={1,7,5,2,3,3,1,1,1,1,1,2,2};
    int i,a,ile,flag;
    printf("ELEMENT\t\tILOSC\n");
    int w=sizeof(tab)/sizeof(tab[0]);
    for(i=0; i<w;i++)
     {    ile=0;
          flag=0;
         for(int j=0;j<w;j++)
        {
            if(tab[j]==tab[i])
            {
            ile++;
            if(i<j)
            flag=1;
            }
        }
        if(flag==0)
        printf("  %d\t  -\t  %d\n",tab[i], ile);
     }//for
    return 0;
}
