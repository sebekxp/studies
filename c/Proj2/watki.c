#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define R 2
#define C 10

int arr[R][C];
int sum1, sum2;

void *countRow_1();
void *countRow_2();
void fillAndPrintTab();

int main()
{
    srand(time(NULL));
    pthread_t id1, id2;
    int *status1;
    int *status2;

    fillAndPrintTab();

    if (pthread_create(&id1, NULL, countRow_1, NULL))
    {
        printf("Error in creating a thread");
        exit(1);
    }
    if (pthread_create(&id2, NULL, countRow_2, NULL))
    {
        printf("Error in creating a thread");
        exit(1);
    }
    
    if (pthread_join(id1,(void*)&status1))
    {
        printf("Error in join the thread");
        exit(2);
    }
    if (pthread_join(id2, (void*)&status2))
    {
        printf("Error in join the thread");
        exit(2);
    }

    printf("Suma pierwszego oraz drugiego wiersza: %d\n", sum1 + sum2);

    printf("Exit code: %d\n", status1);
    printf("Exit code: %d\n", status2);

    return 0;
}

void *countRow_1()
{
    int i;
    sum1 = 0;
    for (i = 0; i < C; i++)
        sum1 += arr[0][i];
    printf("Suma pierwszego wiersza: %d\n", sum1);
    pthread_exit((void*) 10);
}
void *countRow_2()
{
    int i;
    sum2 = 0;
    for (i = 0; i < C; i++)
        sum2 += arr[1][i];

    printf("Suma drugiego wiersza: %d\n", sum2);
    pthread_exit((void*) 20);
}
void fillAndPrintTab(){
        int i, j;
        for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            arr[i][j] = rand() % 100;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
