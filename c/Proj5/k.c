#include "fun.h"
#include <stdio.h>
void obsluga_sigint(int sig_n);

int id_kolejki;
komunikat kom;
komunikat kom_1;

int globalCounter = 0;
void *wysylanie_komunikatu(){
	printf("Klient %d wysyla komunikat o tresci: \"%s\" do serwera\n", getpid(), kom.tekst);
	if ((msgsnd(id_kolejki, (komunikat *)&kom, strlen(kom.tekst) + sizeof(long), IPC_NOWAIT)) == -1){
		printf("Blad wysylania komunikatu /klient: %i (%s)\n", errno, strerror(errno));
		if(errno == EAGAIN){
			printf("Kolejka jest pelna.\n");
		}
		else
			printf("Blad wysylania komunikatu /klient: %i (%s)\n", errno, strerror(errno));
	}
	globalCounter++;
	pthread_exit((void *)0);
}

void *odbieranie_komunikatu(){
	while(1){
	kom_1.typ = getpid();
	memset(kom_1.tekst, 0, MAX);
	if ((msgrcv(id_kolejki, (komunikat *)&kom_1, MAX + sizeof(kom_1.nadawca), kom_1.typ, 0)) == -1){

		if (errno == ENOMSG){
			continue;
		}
		else{
			printf("Blad pobrania komunikatu /klient: %i (%s)\n", errno, strerror(errno));
			exit(2);
		}
	}
	globalCounter--;
	printf("Klient %d odebral komunikat od serwera o tresci: %s\n", getpid(), kom_1.tekst);
	}
}

int main(){
	key_t klucz = utworzKlucz(".", 'A', "KLIENT");
	id_kolejki = utworzKolejkeKomunikatow(klucz, 0600 | IPC_CREAT, "KLIENT");

	int i = 0;
	char wiadomosc[MAX];
	pthread_t tid2;
	signal(SIGINT, obsluga_sigint);
	utworzWatek(&tid2, NULL, odbieranie_komunikatu, NULL);
	while (1){
		pthread_t tid1;
		kom.typ = 1;
		kom.nadawca = getpid();

		printf("\nKlient %d: Podaj tekst do wyslania: ", getpid());
		i = 0;
		while (1){
			wiadomosc[i] = getchar();
			if((wiadomosc[i] == '\n')||(i>=MAX)){
				wiadomosc[i] = '\0';
				break;
			}
			i++;
		}
		//getline(&wiadomosc,MAX,stdin);
		strcpy(kom.tekst, wiadomosc);
		
		utworzWatek(&tid1, NULL, wysylanie_komunikatu, NULL);
		przylaczWatek(tid1, NULL);

	}

	return 0;
}
void obsluga_sigint(int sig_n)
{
	while(globalCounter);
	exit(0);
}