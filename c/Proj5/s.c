#include "fun.h"

void obsluga_sigint(int sig_n);

int main(){

    key_t klucz = utworzKlucz(".", 'A', "SERWER");
    int id_kolejki = utworzKolejkeKomunikatow(klucz, 0600 | IPC_CREAT, "SERWER");
    signal(SIGINT, obsluga_sigint);

    komunikat kom;

    while (1){
        printf("\nSerwer oczekuje na komunikaty...\n");
        kom.typ = 1;
        memset(kom.tekst, 0, MAX);

       
    if ((msgrcv(id_kolejki, (komunikat *)&kom, MAX + sizeof(long), kom.typ, 0)) == -1){
       
     printf("Blad pobrania komunikatu /serwer: %i (%s)\n", errno, strerror(errno));
            return -1;
        }

        printf("Serwer odebral komunikat od procesu: %ld, o tresci: %s\n", kom.nadawca, kom.tekst);

        int rozmiar = strlen(kom.tekst), i;
        for (i = 0; i < rozmiar; i++){
            kom.tekst[i] = toupper(kom.tekst[i]);
        }

        kom.typ = kom.nadawca;
        printf("Serwer wysyla komunikat do: %ld, o tresci: %s\n", kom.nadawca, kom.tekst);
        if ((msgsnd(id_kolejki, (komunikat *)&kom, strlen(kom.tekst) + sizeof(kom.nadawca), IPC_NOWAIT)) == -1){
            printf("Blad wysylania komunikatu /serwer: %i (%s)\n", errno, strerror(errno));
            return -1;
        }
    }

    return 0;
}

void obsluga_sigint(int sig_n){
    key_t klucz = utworzKlucz(".", 'A', "SERWER_SIGINT");
    int id_kolejki = utworzKolejkeKomunikatow(klucz, 0600 | IPC_CREAT, "SERWER_SIGINT");
    zwolnijKoljeke(id_kolejki, IPC_RMID,0);

}