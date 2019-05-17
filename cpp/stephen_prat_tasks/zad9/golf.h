#ifndef ZADANIA_PROGRAMISTYCZNE_9_GOLF_H
#define ZADANIA_PROGRAMISTYCZNE_9_GOLF_H
const int Len = 40;

struct golf {
    char fullname[Len];
    int handicap;
};

void setgolf(golf &g, const char *name, int hc);

void setgolf(golf &g);

void handicap(golf &g, int hc);

void showgolf(const golf &g);

#endif
