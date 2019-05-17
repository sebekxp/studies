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
    int serwer_dlugosc;
    int nazwa_gniazda;
    const char *znak = "Czy dziala to jak powinno ?!";

    //nazywamy gniazdo serwera
    struct sockaddr_un adres_serwera;
    adres_serwera.sun_family = AF_UNIX;
    strcpy(adres_serwera.sun_path, "gniazdo_serwera");
    /* socket - Linux socket interface */
    id_gniazda = socket(AF_UNIX, SOCK_STREAM, 0);
    if (id_gniazda == -1)
        blad("Nie moglem utworzyc gniazda.\n");
    else
        printf("Gniazdo zostalo utworzone %d.\n", id_gniazda);
    /* connect - initiate a connection on a socket */
    if (connect(id_gniazda, (struct sockaddr *)&adres_serwera, sizeof(adres_serwera)) == -1)
        blad("Nie moge nadac nazwy gniazdu.\n");
    else
        printf("Gniazdo otrzymalo swoja nazwe.\n");


    write(id_gniazda, znak, sizeof(znak));
    close(id_gniazda);
    exit(0);
}