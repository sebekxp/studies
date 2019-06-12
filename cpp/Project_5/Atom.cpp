#include "Atom.h"

Atom::Atom(const std::string &symbol, int liczbaAtomowa,
           double gestosc, int liczbaElektronow) : symbol(symbol),
                                                   liczbaAtomowa(
                                                           liczbaAtomowa),
                                                   gestosc(gestosc),
                                                   liczbaElektronow(
                                                           liczbaElektronow) {}

Atom::Atom() : symbol("Cu"),
               liczbaAtomowa(1),
               gestosc(2.3),
               liczbaElektronow(3) {}

std::ostream &operator<<(std::ostream &out, const Atom &a) {
    return out << a.getSymbol() << "(" << a.getLiczbaAtomowa() - a.getLiczbaElektronow() << ")" << std::endl;
}

const std::string &Atom::getSymbol() const {
    return symbol;
}

int Atom::getLiczbaAtomowa() const {
    return liczbaAtomowa;
}

double Atom::getGestosc() const {
    return gestosc;
}

int Atom::getLiczbaElektronow() const {
    return liczbaElektronow;
}

bool operator<(const Atom &a1, const Atom &a2) {
    return a1.getLiczbaAtomowa() < a2.getLiczbaAtomowa();
}

void Atom::setSymbol(const std::string &symbol) {
    Atom::symbol = symbol;
}

void Atom::setLiczbaAtomowa(int liczbaAtomowa) {
    Atom::liczbaAtomowa = liczbaAtomowa;
}

void Atom::setGestosc(double gestosc) {
    Atom::gestosc = gestosc;
}

void Atom::setLiczbaElektronow(int liczbaElektronow) {
    Atom::liczbaElektronow = liczbaElektronow;
}
