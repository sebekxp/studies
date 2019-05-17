#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void main(int argc, char *argv[]){
	if (argc < 4){
		printf("Wrong number of arguments\n");
		printf("Call mainProgram childProgram numProces critSection\n");
		exit(-1);
	}


	int numProces = atoi(argv[2]),

		critSection = atoi(argv[3]);

	// kontrola przekazanych argumentow do programu
	if (!numProces){
		printf("The third argument must be a number\n");
		exit(-2);
	}

	if (!critSection){
		printf("The fourth argument must be a number\n");
		exit(-2);
	}

	if (numProces < 0 || critSection < 0){
		printf("The third and fourth arguments must be positive\n");
		exit(-3);
	}

	//wypisanie argumentow
	printf("Child program: %s, numProces: %d, critSection: %d\n", argv[1], numProces, critSection);

	//tworzenie keya i semafora
	key_t key;
	int semID;
	/*
		Do tworzenia, czy do odwoływania się do zbioru semaforów potrzebny jest
		tzw. klucz – liczba całkowita.
		key_t ftok(const char *path, int id)
		
		path - ścieŜkowa nazwa istniejącego pliku - dostępnego procesowi
		id – zwykle pojedynczy znak, który jednoznacznie identyfikuje projekt 
		Return value:
		- Sukces -> wartosc klucza, - Porazka -> -1, - errno NIE
	*/
	if (!(key = ftok(".", 'F'))){
		printf("Key creation error");
		exit(-4);
	}
	/*
		Tworzenie i uzyskiwanie dostępu do semaforów
		int semget (key_t key, int nsems, int semflg)

		key - klucz do zbioru semaforów (róŜne procesy, które chcą korzystać z tego samego zbioru,
			  muszą uŜyć tego samego klucza)
		nsems – liczba semaforów w zbiorze
		semflag – flaga określająca sposób wykonania funkcji i prawa dostępu do semaforów
		Return value:
			- Sukces -> ID semafora, - Porazka -> -1, - errno TAK
		
			PC_CREAT – utworzenie zbioru semaforów lub uzyskanie dostępu do
 			istniejącego juŜ zbioru

 			IPC_EXCL – uŜyta w połączeniu z IPC_CREAT zwraca błąd, jeŜeli dla
 			danego klucza istnieje juŜ zbiór semaforów
 			
			 PRAWA DOSTĘPU – podobnie jak dla pliku np. 0666 

	*/
	semID = semget(key, 1, 0600 | IPC_CREAT );
	if (semID == -1){
		printf("Semaphore creation error");
		exit(-5);
	}
	else
		printf("Semaphore has been created, id: %d with key: %d\n", semID, key);

	//ustwanie semafora
	/*
		Sterowanie semaforami
		semctl(int semid, int semnum, int cmd,  union semun arg ,…)		
		Return value:
			- Sukces -> 0 lub wartosc zadana przez cmd, - Porazka -> -1, - errno TAK

	*/

	if (semctl(semID, 0, SETVAL, 1) == -1){
		printf("I can not set the semaphore\n");
		exit(-7);
	}
	else
		printf("Semaphore has been set\n");
	int returnCode, childPid;
	//utworzenie numProces procesow
	int i;
	for (i = 1; i <= numProces; i++){
		switch (fork()){
		case -1:
			printf("Error of creating a child process\n");
			childPid = wait(&returnCode);
			exit(-4);
		case 0:
			if (execl(argv[1], argv[1], argv[3], NULL) == -1){
				printf("Exec error for the child main program\n");
				exit(-4);
			}
		}
	}

	//czekanie na zakonczenie procesow potomnych
	for (i = 1; i <= numProces; i++){
		childPid = wait(&returnCode);
		if (childPid == -1){
			printf("Error in the wait function\n");
			exit(-6);
		}
		printf("Child process %d ended with the return code %d\n", childPid, returnCode);
	}

	//usuwanie semafora
	if (semctl(semID, 0, IPC_RMID) == -1){
		printf("Semaphore can not be removed\n");
		exit(-6);
	}
	else
		printf("Semaphore has been removed, id: %d\n", semID);

	return;
}





































	/*
		 Maksymalna liczbe procesow wyswietla poloecenie "ulimit -a" w wierszu "max user procceses"
  	 	 wyluskanie: ulimit -a | grep "max user processes" | tr -s ' ' | cut -d' ' -f5
	*/