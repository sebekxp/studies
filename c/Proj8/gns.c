#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

static void blad(char opis[])
{
    printf("%s/n", opis);
    exit(EXIT_FAILURE);
}

int main()
{
    int id_gniazda;
    int id_gniazda_k;
    int klient_dlugosc;
    int nazwa_gniazda;
    char znak;

    struct sockaddr_un adres_serwera;
    struct sockaddr_un adres_klienta;
    adres_serwera.sun_family = AF_UNIX;
    strcpy(adres_serwera.sun_path, "gniazdo_serwera");

    id_gniazda = socket(AF_UNIX, SOCK_STREAM, 0);
    if (id_gniazda == -1)
        blad("Nie moglem utworzyc gniazda.\n");
    else
        printf("Gniazdo zostalo utworzone %d.\n", id_gniazda);

    if (bind(id_gniazda, (struct sockaddr *)&adres_serwera, sizeof(adres_serwera)) == -1)
        blad("Nie moge nadac nazwy gniazdu.\n");
    else
        printf("Gniazdo otrzymalo swoja nazwe.\n");

    if (listen(id_gniazda, 5) == -1)
        blad("Nie moge utworzy kolejki.\n");
    else
        printf("Kolejka zostala utworzona.\n");
    klient_dlugosc = sizeof(adres_klienta);

    printf("Oczekuje na klienta...\n");
    id_gniazda_k = accept(id_gniazda, (struct sockaddr *)&adres_klienta, &klient_dlugosc);
    read(id_gniazda_k, &znak, 1);
    printf("Otrzymalem znak od klienta : %c\n", znak);
    close(id_gniazda_k);
}