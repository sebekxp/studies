#ifndef FUN_H_
#define FUN_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 4

typedef struct k
{
    long typ;
    long nadawca;
    char tekst[4];
} komunikat;

static key_t utworzKlucz(const char *pathName, int projID, const char *name)
{
    key_t key;
    if (!(key = ftok(pathName, projID)))
    {
        printf("Blad tworzenia klucza %s\n", name);
        exit(-2);
    }
    return key;
}
static int utworzKolejkeKomunikatow(key_t key, int msgFlg, const char *name)
{
    int IDkolejki;
    if ((IDkolejki = msgget(key, msgFlg)) == -1)
    {
        printf("Blad tworzenia kolejki komunikatów.\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("%s %d uzyskal dostep do kolejki komunikatow \n", name, getpid());
    return IDkolejki;
};
static void utworzWatek(pthread_t *tid, const pthread_attr_t *attr, void *(*func)(void *), void *arg)
{
    if (pthread_create(tid, attr, func, arg))
    {
        printf("Blad tworzenia watku (wysylanie_komunikatu): %i (%s)\n", errno, strerror(errno));
        exit(1);
    }
}
static void przylaczWatek(pthread_t tid, void **status)
{
    if (pthread_join(tid, status))
    {
        printf("Blad przylaczenia watku (wysylanie_komunikatu):  %i (%s)\n", errno, strerror(errno));
        exit(2);
    }
}
static void zwolnijKoljeke(int id, int cmd, struct msqid_ds *buf)
{
    if ((msgctl(id, cmd, buf)) == -1)
    {
        printf("Blad usuwania kolejki komunikatow /serwer: %i (%s)\n", errno, strerror(errno));
        exit(-1);
    }
    else
        printf("Usunieta kolejke komunikatow o ID: %d\n", id);

    exit(0);
}
#endif