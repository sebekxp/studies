#ifndef PROJECT_4_OKRAG_H
#define PROJECT_4_OKRAG_H

#include<cmath>
#include <ostream>
#include <iostream>
#include <typeinfo>

class Circle {
private:
    double R;

public:

    Circle();

    // Użycie explicit aby nie
    // została przeprowadzana automatyczna
    // konwersja przy pomocy tego konstruktora
    explicit Circle(double R);

    double getR() const;

    void setR(double R);

    // Metoda pomocnicza aby nie powtarzać
    // kodu dla wypisywania informacji o danym obiekcie obiekcie
    void printInfo();

    double circumferenceCircle();

    void scaleCircle(double scale);

    void compareCircle(const Circle &c);

    friend Circle &operator*(Circle &c1, double scale);

    friend std::ostream &operator<<(std::ostream &out, const Circle &o);

    friend bool operator==(const Circle &c1, const Circle &c2);

    friend bool operator<(const Circle &c1, const Circle &c2);

    friend bool operator>(const Circle &c1, const Circle &c2);
};

#endif //PROJECT_4_OKRAG_H
