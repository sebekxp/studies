#include <sys/stat.h>
#include "includes.h"

unsigned int limit_procesow() {
    rlimit struktura_rlimit;
    getrlimit(RLIMIT_NPROC, &struktura_rlimit);
    return struktura_rlimit.rlim_cur;
}

unsigned int ilosc_procesow() {

    unsigned int ulimit;
    FILE *file_ptr = popen("ps -aux | wc -l", "r");

    fscanf(file_ptr, "%u", &ulimit);
    pclose(file_ptr);

    return ulimit;
}

int main(int argc, char *argv[]) {
    system("../czyszczenieKatalogow.sh");
    if (argc != 2) {
        std::cout << "Argumenty!!! " << std::endl;
        exit(1);
    }

    int ilosc_producentow = std::stoi(argv[1]);

    if (ilosc_producentow <= 0) {
        std::cout << "Liczba producentow musi byc dodatnia!" << std::endl;
        exit(2);
    }

    if (ilosc_producentow > (limit_procesow() - ilosc_procesow())) {
        std::cout << "Liczba producentow musi byc < liczby proc dostepnych!" << std::endl;
        exit(2);
    }

    const char *potok = "POTOK";

    if (mkfifo(potok, S_IWUSR | S_IRUSR) == -1)
    {
        perror("Mkfifo error");
        exit(3);
    }
	std::cout<<"WYSTARTOWALO: "<<ilosc_producentow<<" PRODUCENTOW"<<std::endl;
    for (int i = 0; i < ilosc_producentow; i++) {
        std::string numery_producentow = std::to_string(i);

        switch (fork()) {
            case -1:
                perror("Fork error");
                exit(4);
                break;
            case 0: {
                srand((time(nullptr) - i * 2));

                FILE *file_ptr = fopen(("producent/" + numery_producentow + ".txt").c_str(), "w");
                if (file_ptr == nullptr) {
                    perror("File open error!");
                    exit(5);
                }

                int potok_ptr = open(potok, O_WRONLY);
                if (potok_ptr == -1) {
                    perror("Pipe Open Error");
                    exit(6);
                }

                char literka = 0;
                for (int j = 0; j < 1000000; j++) {
                    literka = 'A' + (rand() % 26);

                    if (write(potok_ptr, &literka, sizeof(char)) == -1) {
                        perror("Write error");
                        exit(7);
                    }

                    fputc(literka, file_ptr);
                }
                fclose(file_ptr);
                close(potok_ptr);
                exit(0);
            }
                break;
            default:
                break;
        }

    }
    std::cout << "Czekam..." << std::endl;
    for (int i = 0; i < ilosc_producentow; i++)
        wait(nullptr);


    return 0;
}
