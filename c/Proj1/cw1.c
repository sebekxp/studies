#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
printf("Identyfikator uzytkownika UID: %d\n", getuid());
printf("Identyfikator grupy uzytkownika GID: %d\n", getgid());
printf("Identyfikator procesu PID: %d\n", getpid());
printf("Identyfikator procesu macierzystego PPID: %d\n", getppid());

exit(0);
}