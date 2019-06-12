#include "Circle.h"

int main() {
    // Pryzkład tworzenia zmiennych na 3 sposoby
    Circle circle1;
    Circle circle2(4.0);
    auto *circle3 = new Circle(5.0);

    circle1.printInfo();
    circle2.printInfo();
    circle3->printInfo();

    std::cout << "========== AFTER SCALE ==========" << std::endl << std::endl;

    circle1.scaleCircle(3);
    circle2.scaleCircle(4);
    circle3->scaleCircle(5);

    circle1.printInfo();
    circle2.printInfo();
    circle3->printInfo();

    circle1.compareCircle(circle2);
    circle1.compareCircle(*circle3);
    circle2.compareCircle(*circle3);
    circle2.compareCircle(circle1);
    circle3->compareCircle(circle1);
    circle3->compareCircle(circle2);

    Circle circle4(5.0);
    circle4.compareCircle(*circle3);

    delete circle3;

    return 0;
}