#include "Circle.h"

Circle::Circle() : R(3.0) {}

Circle::Circle(double R) : R(R) {}

double Circle::circumferenceCircle() {
    return 2 * M_PI * this->getR();
}

std::ostream &operator<<(std::ostream &out, const Circle &o) {
    return out << "Object of the circle class, R = " << o.getR() << std::endl;
}

Circle &operator*(Circle &c, double scale) {
    c.setR(c.R * scale);    // c.R = c.R * scale;
    return c;
}

void Circle::scaleCircle(double scale) {

    // Przykład metody skalującej okrąg
    // Przemnożenie obiektu, dla którego została
    // wywołana metoda przez czynnik skali

    *this * scale;
}

void Circle::printInfo() {
    // Przykład przeładowania operatora '<<'
    // Równoznaczne z np. std::cout << circle1, std::cout << circle2
    std::cout << *this;
    std::cout << "circle R = " << this->getR() << std::endl;
    // Przykład metody obliczającej obwód koła
    std::cout << "Circumference of the circle: " << this->circumferenceCircle() << std::endl << std::endl;
}

double Circle::getR() const {
    return R;
}

void Circle::setR(double R) {
    Circle::R = R;
}

bool operator==(const Circle &c1, const Circle &c2) {
    return c1.getR() == c2.getR();
}

bool operator<(const Circle &c1, const Circle &c2) {
    return c1.getR() < c2.getR();
}

bool operator>(const Circle &c1, const Circle &c2) {
    return c1.getR() > c2.getR();
}

void Circle::compareCircle(const Circle &c) {
    if (*this == c)
        std::cout << "Circles are tangent" << std::endl;
    else if (*this > c)
        std::cout << "Circles are disjoint" << std::endl;
    else if (*this < c)
        std::cout << "Circles intersect" << std::endl;

}



