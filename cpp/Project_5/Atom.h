#ifndef PROJECT_5_ATOM_H
#define PROJECT_5_ATOM_H

#include <string>
#include <iostream>

class Atom {
    std::string symbol;
    int liczbaAtomowa;
    double gestosc;
    int liczbaElektronow;

public:
    Atom(const std::string &symbol, int liczbaAtomowa, double gestosc, int liczbaElektronow);

    Atom();

    friend std::ostream &operator<<(std::ostream &out, const Atom &a);

    friend bool operator<(const Atom &a1, const Atom &a2);

    const std::string &getSymbol() const;

    int getLiczbaAtomowa() const;

    double getGestosc() const;

    int getLiczbaElektronow() const;

    void setSymbol(const std::string &symbol);

    void setLiczbaAtomowa(int liczbaAtomowa);

    void setGestosc(double gestosc);

    void setLiczbaElektronow(int liczbaElektronow);

};


#endif //PROJECT_5_ATOM_H
