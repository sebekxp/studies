#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <limits>
#include <iostream>
class Player {
public:
    Player();
    ~Player(){
        free(shoot);
        free(min);
        free(max);
    }
    template<typename T>
    void feedback(int option) {
        switch (option) {
            case -1:
                *(T*)min = *(T*)shoot;
                break;
            case 1:
                *(T*)max = *(T*)shoot;
                break;
            case 2:
                shoot = malloc(sizeof(T));
                min = malloc(sizeof(T));
                max = malloc(sizeof(T));

                *(T*)min =std::numeric_limits<T>::lowest();
                *(T*)max =std::numeric_limits<T>::max();
                break;
        }
    }

    int GetID() { return numID; }

    template<typename T>
    T guess() {
        T temp1 = *(T*)min/2;
        T temp2 = *(T*)max/2;

        *(T*)shoot = (*(T*)min)/2 + (*(T*)max)/2;
        return *(T*)shoot;
    }

private:
    static int staticID;
    int numID;
    void *min;
    void *max;
    void *shoot;
};


#endif //UNTITLED_PLAYER_H
