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
    int zero=0,jedynka=0, j=0,miejscejedynek=0;
    for(int i=0;i<tab[0];i++)//SPR LICZBY ELEMENTOW
    {
        for(int j=0;j<tab[1];j++)
        {
            if(arr[i][j]==1)
            jedynka++;
            else if(arr[i][j]==0)
            zero++;
        }
    }

    for(int i=0;i<tab[0];i++)//SPRAWDZANIE JEDYNEK NA POPRAWYNYCH MIEJSCACH
    {
            if(arr[i][j]==1)
            miejscejedynek++;
            j++;//jesli 1 na glownej przekatnej to ++
    }
    int iloscZer=tab[0]*tab[1]-tab[0];//ilosc zer to bok kwadrat-perzekatna
    if(iloscZer==zero&&jedynka==tab[0]&&miejscejedynek==tab[0])
        printf("Jest jednostkowa :)");
    else
        printf("Nie jest jednostkowa:)\n");
}
int main()
{   int tab[2],arr[M][N];
    changeComasForSpaces();
    findSize(tab);
    doArray(arr,tab);
    printf("Macierz\n\n");
    drawArray(arr,tab);
    check(arr,tab);




    return 0;
}
