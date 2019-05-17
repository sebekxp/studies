#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("Proces macierzysty! PID: %d, PPID: %d\n", getpid(), getppid());
	int i;
	int pidM = getpid();
	char str[25];

	for (i = 1; i < 3; i++)
	{
		switch (fork())
		{
		case -1:
			perror("fork error");
			exit(1);
		case 0:
			fork();
			printf("POTOMEK %d\n", i);
			printf("Identyfikator uzytkownika UID: %d\n", getuid());
			printf("Identyfikator grupy uzytkownika GID: %d\n", getgid());
			printf("Identyfikator procesu PID: %d\n", getpid());
			printf("Identyfikator procesu macierzystego PPID: %d\n", getppid());
			break;
		default:
			fork();
			break;
		}
	}
	printf("\n\n");
	sprintf(str, "pstree -p %d", pidM);
	system(str);


	return 0;
}