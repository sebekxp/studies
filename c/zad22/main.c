#include <stdio.h>
#include <stdlib.h>
const int M = 100;
const int N = 100;

void changeComasForSpaces() {
    FILE *file;
    file=fopen("plik.txt", "r+");
    if(file==NULL)
    {
        printf("Brak pliku");
        return 0;
    }
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == ',')
        {
            fseek(file, -1, SEEK_CUR);
            fputc(' ',file);
            fseek(file, 0, SEEK_CUR);
        }
    }
    fclose(file);
}
void findSize(int tab[]){
    FILE *file;
    file=fopen("plik.txt", "r");
    if(file==NULL)
    {
        printf("Brak pliku");
        return 0;
    }

    char lastSign = ' ',ch;
    int numbercount= 0, linecount = 1;
    //Oblicznie rozmiaru macierzy
    while((ch=getc(file)) != EOF)
    {
        if(lastSign == ' ' || lastSign == '\n') { //funkcja dla 2-wu lub wiecej cyfrowych
            if (ch != ' ' && ch != '\n')
            ++numbercount;    //l. liczb
        }
        lastSign = ch;
        if (ch == '\n')
        { ++linecount; }  //liczba wirszy
    }//while
     tab[0]=linecount;//wiersze
     tab[1]=numbercount/linecount;//columny
     fclose(file);
}
void doArray(int arr[M][N],int tab[]){

    FILE *file;
    file=fopen("plik.txt", "r");
    if(file==NULL)
    {
        printf("Brak pliku");
        return 0;
    }
        for(int i=0; i<tab[0]; i++)
        {
            for(int j=0; j<tab[1]; j++)
            {
                fscanf( file, "%d", &arr[i][j]);
            }//for2
        }//for1
    fclose(file);
}
void drawArray(int arr[M][N],int tab[]){
for(int i=0; i<tab[0]; i++)
    {
        for(int j=0; j<tab[1]; j++)
        {
            printf("%d ",arr[i][j]);
        }//for2
        printf(" \n");
    }//for1
}
void doNewArray(int newArray[M][N],int tab[]){
    FILE *file;
    file=fopen("plik.txt", "r");
    if(file==NULL)
    {
        printf("Brak pliku");
        return 0;
    }
        for(int i=0; i<tab[0]; i++)
        {
            for(int j=0; j<tab[1]; j++)
            {
                fscanf( file, "%d", &newArray[i][j]);
            }//for2
        }//for1
    fclose(file);
}
void addtoNewArray(int newArray[M][N],int tab[]){
    FILE *file;
    file=fopen("plik.txt", "r");
    if(file==NULL)
    {
        printf("Brak pliku");
        return 0;
    }
        //DODAWANIE 2 WIERSZY
        for(int i=0; i<2*tab[0]-1; i++)
        {
            for(int j=0; j<tab[1]; j++)
            {
                fscanf( file, "%d", &newArray[(tab[0]+i)][j]);
            }//for2
        }//for1
    fclose(file);
}
void drawnewArray(int newArray[M][N],int tab[]){
for(int i=0; i<2*tab[0]-1; i++)
    {
        for(int j=0; j<tab[1]; j++)
        {
            printf("%d ",newArray[i][j]);
        }//for2
        printf(" \n");
    }//for1
}
void determinant(int newArray[M][N],int tab[]){
    int j=0,sum=1,SUM=0,sum1=1,SUM1=0,k=2;
    for(int i=0;i<2*tab[0]-1;i++)//lewo-prawo
    {

    sum*=newArray[i][j];
    j++;
    if(j==3)
        {
        j=0;
        i=i-2;
        SUM+=sum;
        sum=1;
        }
    }//for
    for(int i=0;i<2*tab[0]-1;i++)//lewo-prawo
    {

    sum1*=newArray[i][k];


    if(k==0)
        {
        k=3;
        i=i-2;
        SUM1+=sum1;
        sum1=1;
        }
        k--;
    }//for
int det=SUM-SUM1;
printf("Wyznacznik jest rowny : %d\n",det);


}
int main()
{   int tab[2],arr[M][N],newArray[M][N];
    changeComasForSpaces();
    findSize(tab);
    doArray(arr,tab);
    doNewArray(newArray,tab);
    addtoNewArray(newArray,tab);
    printf("Macierz\n\n");
    drawArray(arr,tab);
    printf("\n");
    drawnewArray(newArray,tab);
    printf("\n");
    determinant(newArray,tab);





    return 0;
}
