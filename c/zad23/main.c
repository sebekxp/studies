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
void check(int arr[M][N],int tab[]){

    int wynik=arr[0][0];
    for(int i=1;i<tab[0];i++)
    {
       if(arr[i][i]>wynik)
       wynik=arr[i][i];
    }
    printf("Max : %d\n",wynik);
}
int main()
{   int tab[2],arr[M][N];
    changeComasForSpaces();
    findSize(tab);
    doArray(arr,tab);
    printf("Macierz\n\n");
    drawArray(arr,tab);
    printf("\n");
    check(arr,tab);




    return 0;
}
