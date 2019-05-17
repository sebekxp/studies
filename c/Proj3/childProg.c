#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int semID;
void sem_p(void) // oPuszczanie
{
    int changeSem;
    struct sembuf buffSem;
    buffSem.sem_num = 0;
    buffSem.sem_op = -1;
    buffSem.sem_flg = SEM_UNDO;

    /*
        Operacje na semaforach
        semop(int semid, struct sembuf *sops, size_t nsops)

        semid – identyfikator zbioru semaforów
        sops – wskaźnik do tablicy struktur określający operacje na zbiorze semaforów
        nsops – liczba semaforów (elementów tablicy), na których ma być wykonana operacja

        Return value:
		    - Sukces -> 0, - Porazka -> -1, - errno TAK
    */

    while (1)
    {
        changeSem = semop(semID, &buffSem, 1);
        if (changeSem == 0 || errno != 4) //eerno == 4 -> Interrupted system call
            break;
    }

    if (changeSem == -1)
    {
        if (errno != 4)
        {
            printf("Error in leaving the semaphore\n");
            exit(-5);
        }
    }
    else
        printf("\nSemaphore has been closed\n");
}

void sem_v(void) // Podnoszenie
{
    int changeSem;
    struct sembuf buffSem;
    buffSem.sem_num = 0;
    buffSem.sem_op = 1;
    buffSem.sem_flg = SEM_UNDO;

    while (1)
    {
        changeSem = semop(semID, &buffSem, 1);
        if (changeSem == 0 || errno != 4) //eerno == 4 -> Interrupted system call
            break;
    }

    if (changeSem == -1)
    {
        if (errno != 4)
        {
            printf("Blad podnoszenia  semafora\n");
            exit(-5);
        }
    }
    else
        printf("Semafor zostal otwarty.\n\n");
}

void numWaitProcess()
{
    int i;
    i = semctl(semID, 0, GETNCNT);
    if (i == -1)
    {
        printf("Error in reading the number of processes waiting for the semaphore to be raised");
        exit(-5);
    }
    else
        printf("Number of processes waiting for the semaphore to be raised: %d\n", i);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Too few arguments\nCall mainProgram critSection\n");
        exit(-1);
    }

    int critSection = atoi(argv[1]);

    //kontrola przekazanych argumentow do programu
    if (!critSection)
    {
        printf("Argument must be a number\n");
        exit(-1);
    }

    //tworzenie keya
    key_t key;
    if (!(key = ftok(".", 'F')))
    {
		printf("Key creation error");
        exit(-2);
    }

    //uzyskanie dostepu do semafora
    if ((semID = semget(key, 1, 0600 | IPC_CREAT)) == -1)
    {
        printf("Error in accessing the semaphore/childProgram\n");
        exit(-3);
    }
    else
        printf("Process %d gained access to the semaphore\n", getpid());

    //dzialanie na semaforze
    int i;
    for (i = 1; i <= critSection; i++)
    {
        sem_p(); //zmiana stanu semafora na 0
        printf("Critical section of the process: %d\n", getpid());
        
        numWaitProcess(); //wypisanie liczby procesow czekajacych na podniesienie semafora
        sem_v();             //zmiana stanu semafora na 1
    }

    return 0;
}
