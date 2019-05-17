#include "sem.h"

int main()
{
    int pamiec = upd(10, 1);
    char *adres = upa(pamiec);

    int id_semafora = utworz_semafor(ftok(".", 'A'), 3);
    printf("\n\n");

    FILE *wyjscie = openFile(wyjscie, "wyjscie", "w");
    printf("\n\n");

    

    while (1)
    {
        opusc_semafor(id_semafora, 1, "konsument");

        printf("Odczytany znak: %c/%d -> konsument\n", *adres, (int)(*adres));
        if (*adres == EOF)
            break;
        fputc(*adres, wyjscie);

        podnies_semafor(id_semafora, 0, "producent");
        printf("\n\n");
    }
    
    printf("\n\n");
    podnies_semafor(id_semafora, 2, "Flaga");
    closeFile(wyjscie, "wyjscie");

    return 0;
}
