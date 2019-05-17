#include "sem.h"

int main()
{
	int pamiec = upd(10, 1);
	char *adres = upa(pamiec);

	int id_semafora = utworz_semafor(ftok(".", 'A'), 3);
	ustaw_semafor(id_semafora, 0, 1, "0");
	ustaw_semafor(id_semafora, 1, 0, "1");
	ustaw_semafor(id_semafora, 2, 0, "2");

	FILE *wejscie = openFile(wejscie, "wejscie", "r");
	printf("\n\n");

	int znak = getc(wejscie);
	if (znak != EOF)
	{
		fseek(wejscie, 0, SEEK_SET);
		while (1)
		{
			//sleep(5);
			opusc_semafor(id_semafora, 0, "producent");
			znak = getc(wejscie);
			printf("Odczytany znak: %c/%d  -> producent\n", znak, znak);
			*adres = znak;

			podnies_semafor(id_semafora, 1, "konsument");
			printf("\n\n");

			if (znak == EOF)
				break;

		}
		opusc_semafor(id_semafora, 2, "Flaga");
	}
	else
		printf("Pusty plik!\n");

	closeFile(wejscie, "wejscie");
	usun_semafor(id_semafora);
	odlacz_pamiec(pamiec, adres);

	exit(EXIT_SUCCESS);
	return 0;
}
