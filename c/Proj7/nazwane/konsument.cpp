#include "includes.h"

unsigned int limit_procesow() {
    rlimit struktura_rlimit{};
    getrlimit(RLIMIT_NPROC, &struktura_rlimit);

    return (unsigned int) struktura_rlimit.rlim_cur;
}

unsigned int ilosc_procesow() {

    unsigned int ulimit;
    FILE *file_ptr = popen("ps -aux | wc -l", "r");
    fscanf(file_ptr, "%u", &ulimit);
    pclose(file_ptr);

    return ulimit;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Argumenty!!!" << std::endl;
        exit(1);
    }

    if (access("POTOK", F_OK) == -1) {
        std::cout << "Brak dostepu do potoku! Nie ma?" << std::endl;
        exit(2);
    }

    int ilosc_konsumentow = std::stoi(argv[1]);

    if (ilosc_konsumentow <= 0) {
        std::cout << "Konsumenci są ujemni!" << std::endl;
        exit(3);
    }

    if (ilosc_konsumentow > (limit_procesow() - ilosc_procesow())) {
        std::cout << "Brak miejsca na procesy: " << (limit_procesow() - ilosc_procesow())
                  << "!" << std::endl;
        exit(3);
    }
    for (int i = 0; i < ilosc_konsumentow; i++) {
        std::string numery_konsumentow = std::to_string(i);
        switch (fork()) {
            case -1:
                perror("Fork error");
                exit(4);
                break;
            case 0: {

                FILE *file_ptr = fopen(("konsument/" + numery_konsumentow + ".txt").c_str(), "w");
                if (file_ptr == nullptr) {
                    perror("File open error!");
                    exit(5);
                }

                int potok_ptr = open("POTOK", O_RDONLY | O_NONBLOCK);

                if (potok_ptr == -1) {
                    perror("Open Error");
                    exit(6);
                }

                char literka = 0;
                while (true) {
                    ssize_t retval = read(potok_ptr, &literka, sizeof(char));

                    if (retval <= 0) {
                        if (retval != -1) 
                        {
                            fclose(file_ptr);
                            close(potok_ptr);
                            exit(0);
                        }
                    } else {
                        fputc(literka, file_ptr);
                        fflush(file_ptr);
                    }
                }
            }
            default:
                break;
        }
    }

    for (int i = 0; i < ilosc_konsumentow; i++)
        wait(nullptr);

    if (remove("POTOK") != 0) {
        perror("Blad usuwania kolejki");
        exit(7);
    }
    std::cout << "ZLICZANIE..." << std::endl;
    system("../zliczanieZnakow.sh");
    return 0;
}
