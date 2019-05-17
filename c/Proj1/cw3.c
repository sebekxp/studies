#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int i;
    int pidM = getpid();
    char str[25];
    for (i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execl("/usr/bin/xterm", "xterm", "-fg", "red", "-bg", "blue", NULL);
            break;
        default:
            printf("\nProces macierzysty\n");
        }
    }
	sprintf(str, "pstree -p %d", pidM);
	system(str);

    int j;
    for(j=0;j<3;j++){
    int w, x = 0;
    w = wait(&x);
    if(w == -1){
        printf("Blad wait\n");
        exit(3);
    }
    printf("Kod powrotu potomka %d = %d\n", w, x );
    }

    return 0;
}