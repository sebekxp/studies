#ifndef SEM_H
#define SEM_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>

static int upd(int key, int size)
{
    int pamiec = shmget(key, size, 0777 | IPC_CREAT);
    if (pamiec == -1)
    {
        printf("Problemy z utworzeniem pamieci dzielonej.\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Pamiec dzielona zostala utworzona: %d\n", pamiec);

    return pamiec;
}
static char *upa(int id)
{

    char *adres = shmat(id, 0, 0);
    if (*adres == -1)
    {
        printf("Problem z przydzieleniem adresu.\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Przestrzen adresowa zostala przyznana: %s\n", adres);

    return adres;
}
static int utworz_semafor(int key, int numSem)
{
    int semafor = semget(key, numSem, 0600 | IPC_CREAT);
    if (semafor == -1)
    {
        printf("Nie moglem utworzyc nowego zbioru semaforow.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Zbior semaforow zostal utworzony: %d\n", semafor);
    }
    return semafor;
}

static void ustaw_semafor(int semafor, int numSem, int value, const char *strName)
{
    int ustaw_sem;
    ustaw_sem = semctl(semafor, numSem, SETVAL, value);
    if (ustaw_sem == -1)
    {
        printf("Nie mozna ustawic %s semafora.\n",strName);
        exit(EXIT_FAILURE);
    }
    else
        printf("Semafor %s zostal ustawiony.\n",strName);

}

static void opusc_semafor(int id_semafora, short nr_sem, const char *msg)
{
    int zmien_sem;
    struct sembuf bufor_sem;
    bufor_sem.sem_num = nr_sem;
    bufor_sem.sem_op = -1;
    bufor_sem.sem_flg = 0;

    while (1)
    {
        zmien_sem = semop(id_semafora, &bufor_sem, 1);
        if (zmien_sem == 0 || errno != 4) //eerno == 4 -> Interrupted system call
            break;
    }

    if (zmien_sem == -1)
    {
        if (errno != 4)
        {
            perror("Blad opuszczania semafora");
            printf(" -> %s.\n", msg);
            exit(EXIT_FAILURE);
        }
    }
    else
        printf("Semafor %d opuszczony -> %s.\n", nr_sem, msg);
}

static void podnies_semafor(int id_semafora, short nr_sem, const char *msg)
{
    int zmien_sem;
    struct sembuf bufor_sem;
    bufor_sem.sem_num = nr_sem;
    bufor_sem.sem_op = 1;
    bufor_sem.sem_flg = 0;

    while (1)
    {
        zmien_sem = semop(id_semafora, &bufor_sem, 1);
        if (zmien_sem == 0 || errno != 4) //eerno == 4 -> Interrupted system call
            break;
    }

    if (zmien_sem == -1)
    {
        if (errno != 4)
        {
            perror("Blad opuszczania semafora");
            printf(" -> %s.\n", msg);
            exit(EXIT_FAILURE);
        }
    }
    else
        printf("Semafor %d podniesiony -> %s.\n", nr_sem, msg);
}

static void usun_semafor(int semafor)
{
    int sem;
    sem = semctl(semafor, 0, IPC_RMID);
    if (sem == -1)
    {
        printf("Nie mozna usunac zbioru semafora.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Zbior semafor zostal usuniety: %d\n", semafor);
    }
}

static void odlacz_pamiec(int pamiec, char *adres)
{
    int odlaczenie1 = shmctl(pamiec, IPC_RMID, 0);
    int odlaczenie2 = shmdt(adres);
    if (odlaczenie1 == -1 || odlaczenie2 == -1)
    {
        printf("Problemy z odlaczeniem pamieci dzielonej.\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Pamiec dzielona zostala odlaczona.\n");
}

FILE *openFile(FILE *wejscie, const char *fileName, const char *modes)
{
    if ((wejscie = fopen(fileName, modes)) == NULL)
    {
        printf("Nie moge otworzyc pliku wejscie do odczytu! -> producent\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Otwarto plik %s.\n", fileName);
    return wejscie;
}
void closeFile(FILE *wejscie, const char *fileName)
{
    if (fclose(wejscie) == EOF)
    {
        printf("Blad zamykania wejscia /producent\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Zamknieto plik %s.\n", fileName);
}
#endif