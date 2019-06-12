#include "Atom.h"

Atom readAtom() {
    std::string tempSymbol;
    int tempLiczbaAtomowa = 0;
    double tempGestosc = 0;
    int tempLiczbaElektronow = 0;

    std::cout << "Wprowadz dane dla obiektu\n";
    std::cout << "W formacie(symbol liczba atomowa gestosc liczba elektronow)\n";
    std::cin >> tempSymbol >> tempLiczbaAtomowa >> tempGestosc >> tempLiczbaElektronow;
    return Atom(tempSymbol, tempLiczbaAtomowa, tempGestosc, tempLiczbaElektronow);
}

int main() {
    // Przykład prezetujacy dzialanie prgramu z zadania
    Atom a1 = readAtom();
    Atom a2 = readAtom();

    // Przyklad porownania dwoch obiektow klasy Atom
    std::cout << "Porownanie dwoch obiektow klasy Atom\n";
    if (a1 < a2) std::cout << a2;
    else std::cout << a1;

    Atom atom1; // Przyklad uzycia konstruktora bezparametrowego
    Atom atom2("Cu", 1, 3.4, 4); // Przyklad uzycia konstruktora z parametrami

    return 0;
}