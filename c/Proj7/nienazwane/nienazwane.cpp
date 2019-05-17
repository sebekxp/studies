#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <csignal>
#include <poll.h>

#include <poll.h>

int potok[2];
int producent_ilosc = 0;
int konsument_ilosc = 0;
int producentCounter = 0;
int konsumentCounter = 0;

unsigned int limit_procesow(){
	//maxymalna liczba procesow z ulimit
	rlimit struktura_rlimit{};
	getrlimit(RLIMIT_NPROC, &struktura_rlimit);

	return struktura_rlimit.rlim_cur;
}
unsigned int ilosc_procesow(){
	unsigned int ulimit;
	FILE *fp = popen("ps -aux | wc -l", "r");

	fscanf(fp, "%u", &ulimit); 
	pclose(fp);

	return ulimit;
}

FILE *file_ptr = nullptr;

void PRODUCENCI(){
	//Producenci
	for (int i = 0; i < producent_ilosc; i++){
		std::string numery_producentow = std::to_string(i);

		switch (fork()){
			case -1:
				perror("Fork error");
				exit(3);

			case 0:{
				close(potok[0]);
				//Kontolnie do pliku
				file_ptr = fopen(("producent/" + numery_producentow + ".txt").c_str(), "w");

				if (file_ptr == nullptr){
					perror("File open error!");
					exit(5);
				}

				srand(time(NULL) - i * 2); //generowanie losowo literek (co sekunde)

				for (int k = 0; k < 100; k++){
					char ch = 'A' + (rand() % 26); //losowanie jednej liteki A-Z

					ssize_t val = write(potok[1], &ch, sizeof(char));;
					//Zapisz
					if (val == -1){
						perror("Write error");
						exit(7);
					}

					fputc(ch, file_ptr);
				}
				//Koniec
				exit(0);

			}

				break;
			default:
				break;
		}
		producentCounter++;
	}
}

void KONSUMENCI(){
	// .fd - file descriptor, .events - data to read
	// pol(array, num items in array, )
	pollfd pl = {potok[0], POLLIN};
	while (poll(&pl, 1, 0) != 1);
	//Konsumenci
	for (int i = 0; i < konsument_ilosc; i++){
		std::string numery_konsumentow = std::to_string(i);

		switch (fork()){
			case -1:
				perror("Fork error");
				exit(3);
			case 0:{
				close(potok[1]);  //Zamknij zapis
				//Otworz plik do zapisu
				file_ptr = fopen(("konsument/" + numery_konsumentow + ".txt").c_str(), "w");
				if (file_ptr == nullptr){
					perror("File open error!");
					exit(5);
				}
				ssize_t val = 0;
				char literka = 0;

				while (true){
					//próbuje odczytać liczbę bajtów z deskryptora pliku(potok[0])do bufora(literka)
					val = read(potok[0], &literka, sizeof(char));
					if (val <= 0){
						//W przypadku błędu zwracane jest -1 i odpowiednio ustawiane errno. 
						//Jesli errno -> EAGAIN to potok zamkniety. Wyjdz z programu
						if (val == -1 && errno == EAGAIN){
							//Czeka na jakieś wydarzenie na deskryptorze pliku
							if (poll(&pl, 1, 500) == 1) 
								continue; 
							close(potok[0]);
							fclose(file_ptr);
							exit(0);
						}
						else{
							perror("Read error");
							exit(6);
						}
					}
					else{
						fputc(literka, file_ptr);
						fflush(file_ptr);
					}
				}
			}
				break;
			default:
				break;
		}
		konsumentCounter++;
	}

}

int main(int argc, char *argv[]){
	std::cout << "PID " << getpid() << " WYSTARTOWAL" << std::endl;
	system("../czyszczenieKatalogow.sh");

	if (argc != 3){
		std::cout << "Argumenty!!! ./program liczba_producentow liczba_konsumentow" << std::endl;
		exit(1);
	}

	producent_ilosc = std::stoi(argv[1]); 
	konsument_ilosc = std::stoi(argv[2]); 

	if (producent_ilosc <= 0 || konsument_ilosc <= 0){
		std::cout << "Liczba/y musza byc dodatnie" << std::endl;
		exit(2);
	}

	if (konsument_ilosc + producent_ilosc >= (limit_procesow() - ilosc_procesow())){
		std::cout << "Brak miejsca na procesy: "
				  << (limit_procesow() - ilosc_procesow()) << "!" << std::endl;
		exit(2);
	}

	int potok_ptr = pipe(potok);

	if (potok_ptr != 0){
		perror("Potok error");
		exit(3);
	}

	//Flaga NONBLOCK dla read że nie blokuje tylko przerywa
	int flags = fcntl(potok[0], F_GETFL);
	//Zwraca tryb dostepu do pliku i flagi statusu pliku.

	flags |= O_NONBLOCK;
	if (fcntl(potok[0], F_SETFL, flags) != 0){
		perror("FCNTL Error");
		exit(4);
	}

	PRODUCENCI();
	KONSUMENCI();

	std::cout << "WYSTARTOWALO: " << producentCounter << " PRODUCENTOW" << std::endl;
	std::cout << "WYSTARTOWALO: " << konsumentCounter << " KONSUMENTOW" << std::endl;

	for (int i = 0; i < producentCounter + konsumentCounter; i++)
		wait(nullptr);
	close(potok[0]);

	std::cout << "PID " << getpid() << " ZAKONCZYL DZIALANIE" << std::endl;
	std::cout << "ZLICZANIE..." << std::endl;
	system("../zliczanieZnakow.sh");
	return 0;

}
